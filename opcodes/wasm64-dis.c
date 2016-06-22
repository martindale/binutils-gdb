/* "Instruction" printing code for the asm.js target
   Copyright (C) 1994-2015 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>

   This file is NOT part of libopcodes.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"

#include "dis-asm.h"
#include "opintl.h"
#include "safe-ctype.h"
#include "floatformat.h"

/* FIXME: This shouldn't be done here.  */
#include "coff/internal.h"
#include "libcoff.h"
#include "elf-bfd.h"
#include "elf/internal.h"
#include "elf/wasm64.h"

/* FIXME: Belongs in global header.  */
#ifndef strneq
#define strneq(a,b,n)	(strncmp ((a), (b), (n)) == 0)
#endif

#ifndef NUM_ELEM
#define NUM_ELEM(a)     (sizeof (a) / sizeof (a)[0])
#endif



enum wasm_clas { wasm_special, wasm_special1, wasm_break, wasm_break_if, wasm_break_table,
wasm_return, wasm_call, wasm_call_indirect, wasm_get_local, wasm_set_local,
wasm_constant, wasm_constant_f32, wasm_constant_f64, wasm_unary, wasm_binary,
wasm_conv, wasm_load, wasm_store, wasm_select, wasm_relational, wasm_eqz };

enum wasm_signedness { wasm_signed, wasm_unsigned, wasm_agnostic, wasm_floating };

enum wasm_type { wasm_void, wasm_any, wasm_i32, wasm_i64, wasm_f32, wasm_f64 };

#define WASM_OPCODE(name, intype, outtype, clas, signedness, opcode) \
  { name, wasm_ ## intype, wasm_ ## outtype, wasm_ ## clas, wasm_ ## signedness, opcode },

struct wasm64_opcode_s {
  const char *name;
  enum wasm_type intype;
  enum wasm_type outtype;
  enum wasm_clas clas;
  enum wasm_signedness signedness;
  unsigned char opcode;
} wasm64_opcodes[] = {
#include "opcode/wasm.h"
  { NULL, 0, 0, 0, 0, 0 }
};

bfd_boolean
wasm64_symbol_is_valid (asymbol * sym,
                       struct disassemble_info * info ATTRIBUTE_UNUSED);
bfd_boolean
wasm64_symbol_is_valid (asymbol * sym,
		     struct disassemble_info * info ATTRIBUTE_UNUSED)
{
  if (sym == NULL)
    return FALSE;

  return TRUE;
}

/* Parse an individual disassembler option.  */

void
parse_wasm64_disassembler_option (char *option);
void
parse_wasm64_disassembler_option (char *option)
{
  if (option == NULL)
    return;

  /* XXX - should break 'option' at following delimiter.  */
  fprintf (stderr, _("Unrecognised disassembler option: %s\n"), option);

  return;
}

/* Parse the string of disassembler options, spliting it at whitespaces
   or commas.  (Whitespace separators supported for backwards compatibility).  */

extern
int read_uleb128(long *value, bfd_vma pc, struct disassemble_info *info);

int read_uleb128(long *value, bfd_vma pc, struct disassemble_info *info)
{
  bfd_byte buffer[16];
  int len = 1;

  if (info->read_memory_func (pc, buffer, 1, info))
    return -1;

  if (buffer[0] & 0x80)
    {
      len = read_uleb128(value, pc + 1, info) + 1;
    }
  *value <<= 7;
  *value |= buffer[0]&0x7f;

  return len;
}

int read_u32(long *value, bfd_vma pc, struct disassemble_info *info);
int read_u32(long *value, bfd_vma pc, struct disassemble_info *info)
{
  int ret;

  if (info->read_memory_func (pc, (bfd_byte*)&ret, 4, info))
    return -1;

  *value = ret;

  return 4;
}

int read_f32(double *value, bfd_vma pc, struct disassemble_info *info);
int read_f32(double *value, bfd_vma pc, struct disassemble_info *info)
{
  float ret;

  if (info->read_memory_func (pc, (bfd_byte*)&ret, 4, info))
    return -1;

  *value = ret;

  return 4;
}

int read_f64(double *value, bfd_vma pc, struct disassemble_info *info);
int read_f64(double *value, bfd_vma pc, struct disassemble_info *info)
{
  double ret;

  if (info->read_memory_func (pc, (bfd_byte*)&ret, 8, info))
    return -1;

  *value = ret;

  return 8;
}

const char *print_type(enum wasm_type);
const char *print_type(enum wasm_type type)
{
  switch (type) {
  case wasm_i32:
    return "i32";
  case wasm_f32:
    return "f32";
  case wasm_i64:
    return "i64";
  case wasm_f64:
    return "f64";
  default:
    return NULL;
  }
}

int
print_insn_little_wasm64 (bfd_vma pc, struct disassemble_info *info);
int
print_insn_little_wasm64 (bfd_vma pc, struct disassemble_info *info)
{
  unsigned char opcode;
  struct wasm64_opcode_s *op;
  bfd_byte buffer[16];
  void *stream = info->stream;
  fprintf_ftype prin = info->fprintf_func;
  long argument_count = 0;
  long constant = 0;
  double fconstant = 0.0;
  long flags = 0;
  long offset = 0;
  long depth = 0;
  long index = 0;
  long target_count = 0;
  int len = 1;
  int i;

  if (info->read_memory_func (pc, buffer, 1, info))
    return -1;

  opcode = buffer[0];

  for (op = wasm64_opcodes; op->name; op++)
    if (op->opcode == opcode)
      break;

  if (!op->name)
    {
      prin (stream, "\t.byte %02x\n", buffer[0]);
      return 1;
    }
  else
    {
      len = 1;

      prin (stream, "\t");
      if (op->clas == wasm_relational || op->clas == wasm_eqz) {
        prin (stream, "%s", print_type (op->intype));
        prin (stream, ".");
      } else if (op->outtype != wasm_void && op->outtype != wasm_any) {
        prin (stream, "%s", print_type (op->outtype));
        prin (stream, ".");
      }
      prin (stream, "%s", op->name);
      if (op->signedness == wasm_signed)
        prin (stream, "_s");
      else if (op->signedness == wasm_unsigned)
        prin (stream, "_u");
      if (op->clas == wasm_conv)
        {
          prin (stream, "_%s", print_type (op->intype));
        }

      switch (op->clas)
        {
        case wasm_special:
          prin (stream, "[0:0]");
          break;
        case wasm_special1:
          prin (stream, "[1:0]");
          break;
        case wasm_binary:
        case wasm_relational:
        case wasm_store:
          prin (stream, "[2:1]");
          break;
        case wasm_select:
          prin (stream, "[3:1]");
          break;
        case wasm_eqz:
        case wasm_unary:
        case wasm_conv:
        case wasm_load:
        case wasm_set_local:
          prin (stream, "[1:1]");
          break;
        case wasm_break_table:
        case wasm_break:
        case wasm_return:
          read_uleb128(&argument_count, pc + len, info);
          prin (stream, "[%ld:0]", argument_count);
          argument_count = 0;
          break;
        case wasm_call:
        case wasm_call_indirect:
          read_uleb128(&argument_count, pc + len, info);
          /* the :1 is subject to change, maybe */
          prin (stream, "[%ld:1]", argument_count);
          argument_count = 0;
          break;
        case wasm_break_if:
          read_uleb128(&argument_count, pc + len, info);
          prin (stream, "[%ld:0]", argument_count+1);
          argument_count = 0;
          break;
        case wasm_constant:
        case wasm_constant_f32:
        case wasm_constant_f64:
        case wasm_get_local:
          prin (stream, "[0:1]");
          break;
        }

      switch (op->clas)
        {
        case wasm_special:
        case wasm_special1:
        case wasm_eqz:
        case wasm_binary:
        case wasm_unary:
        case wasm_conv:
        case wasm_relational:
          break;
        case wasm_select:
          break;
        case wasm_break_table:
          len += read_uleb128(&argument_count, pc + len, info);
          len += read_uleb128(&target_count, pc + len, info);
          //prin (stream, " %ld %ld", argument_count, target_count);
          for (i = 0; i < target_count + 1; i++)
            {
              long target = 0;
              len += read_u32(&target, pc + len, info);
              prin (stream, " %ld", target);
            }
          break;
        case wasm_break:
        case wasm_break_if:
          len += read_uleb128(&argument_count, pc + len, info);
          len += read_uleb128(&depth, pc + len, info);
          //prin (stream, " %ld %ld", argument_count, depth);
          prin (stream, " %ld", depth);
          break;
        case wasm_return:
          len += read_uleb128(&argument_count, pc + len, info);
          //prin (stream, " %ld", argument_count);
          break;
        case wasm_constant:
          len += read_uleb128(&constant, pc + len, info);
          prin (stream, " %lx", constant);
          break;
        case wasm_constant_f32:
          len += read_f32(&fconstant, pc + len, info);
          prin (stream, " %f", fconstant);
          break;
        case wasm_constant_f64:
          len += read_f64(&fconstant, pc + len, info);
          prin (stream, " %f", fconstant);
          break;
        case wasm_call:
        case wasm_call_indirect:
          len += read_uleb128(&argument_count, pc + len, info);
          len += read_uleb128(&index, pc + len, info);
          //prin (stream, " %ld %ld", argument_count, index);
          prin (stream, " %ld", index);
          break;
        case wasm_get_local:
        case wasm_set_local:
          len += read_uleb128(&constant, pc + len, info);
          prin (stream, " %ld", constant);
          break;
        case wasm_load:
        case wasm_store:
          len += read_uleb128(&flags, pc + len, info);
          len += read_uleb128(&offset, pc + len, info);
          prin (stream, " a=%ld %ld", flags, offset);
          break;
        }
    }
  return len;
}

void print_wasm64_disassembler_options(FILE *);
void
print_wasm64_disassembler_options (FILE *stream)
{
  fprintf (stream, _("\
The following WASM64 specific disassembler options are supported for use with\n\
the -M switch:\nnone\n"));
}
