/* ELF support for BFD for the asm.js target.
   Copyright (C) 1998-2015 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>

   This file is NOT part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _ELF_ASMJS_H
#define _ELF_ASMJS_H

#include "elf/reloc-macros.h"

/* Relocation types.  */

START_RELOC_NUMBERS (elf_wasm32_reloc_type)
  RELOC_NUMBER (R_ASMJS_NONE,            	  0)
  RELOC_NUMBER (R_ASMJS_HEX16,            	  1)
  RELOC_NUMBER (R_ASMJS_HEX16R4,            	  2)
  RELOC_NUMBER (R_ASMJS_ABS32,           	  3)
  RELOC_NUMBER (R_ASMJS_REL32,           	  4)
  RELOC_NUMBER (R_ASMJS_HEX16R12,            	  5)
  RELOC_NUMBER (R_ASMJS_REL16,           	  6)
  RELOC_NUMBER (R_ASMJS_ABS16,           	  7)
  RELOC_NUMBER (R_ASMJS_ABS64,           	  8)
  RELOC_NUMBER (R_ASMJS_REL64,           	  9)
  RELOC_NUMBER (R_ASMJS_LEB128,                  10)
  RELOC_NUMBER (R_ASMJS_LEB128R32,               11)
  RELOC_NUMBER (R_ASMJS_LEB128_GOT,              12)
  RELOC_NUMBER (R_ASMJS_LEB128_PLT,              13)
  RELOC_NUMBER (R_ASMJS_PLT_INDEX,               14)
  RELOC_NUMBER (R_ASMJS_ABS32_CODE,              15)
  RELOC_NUMBER (R_ASMJS_ABS64_CODE,              16)
  RELOC_NUMBER (R_ASMJS_COPY,                    17)
  RELOC_NUMBER (R_ASMJS_LEB128_GOT_CODE,         18)
  RELOC_NUMBER (R_ASMJS_PLT_LAZY,                19)
END_RELOC_NUMBERS (R_ASMJS_max = 19)

#endif /* _ELF_ASMJS_H */
