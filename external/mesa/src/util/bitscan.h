/**************************************************************************
 *
 * Copyright 2008 VMware, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

// !!
// FILE MODIFIED FOR THE NEED OF METRICS DISCOVERY API TO CONTAIN ONLY REQUIRED THINGS.
// !!

#ifndef BITSCAN_H
#define BITSCAN_H

// ! For the need of Metrics Discovery API: !
// ! Only 'HAVE___BUILTIN_CLZ' define is needed from c99_compat.h. Copied to not include the whole file. !
//#include "c99_compat.h"
/* Fallback definitions, for build systems other than autoconfig which don't
 * auto-detect these things. */
#ifdef HAVE_NO_AUTOCONF
#  ifdef __GNUC__
#    if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
       /* https://gcc.gnu.org/onlinedocs/gcc-4.2.4/gcc/Other-Builtins.html */
#    define HAVE___BUILTIN_CLZ 1
#    endif
#  endif /* __GNUC__ */
#endif /* !HAVE_AUTOCONF */

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Find last bit set in a word.  The least significant bit is 1.
 * Return 0 if no bits are set.
 * Essentially ffs() in the reverse direction.
 */
static inline unsigned
util_last_bit(unsigned u)
{
#if defined(HAVE___BUILTIN_CLZ)
   return u == 0 ? 0 : 32 - __builtin_clz(u);
#elif defined(_MSC_VER) && (_M_IX86 || _M_ARM || _M_AMD64 || _M_IA64)
   unsigned long index;
   if (_BitScanReverse(&index, u))
      return index + 1;
   else
      return 0;
#else
   unsigned r = 0;
   while (u) {
      r++;
      u >>= 1;
   }
   return r;
#endif
}


#ifdef __cplusplus
}
#endif

#endif /* BITSCAN_H */
