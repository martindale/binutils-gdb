/* BFD support for the asm.js target
   Copyright (C) 1994-2015 Free Software Foundation, Inc.
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
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "libiberty.h"

#define N(number, print, default, next)  \
{  64, 64, 8, bfd_arch_wasm64, number, "wasm64", "wasm64", 4, default, bfd_default_compatible, \
   bfd_default_scan, bfd_arch_default_fill, next }

static const bfd_arch_info_type arch_info_struct[] =
{
  N (bfd_mach_wasm64,      "wasm64",   TRUE, NULL)
};

const bfd_arch_info_type bfd_wasm64_arch =
  N (bfd_mach_wasm64, "wasm64", TRUE, & arch_info_struct[0]);
