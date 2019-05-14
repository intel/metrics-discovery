/*****************************************************************************\

    Copyright © 2019, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  iu_os.h

    Abstract:   Instrumentation Utils header with OS specific non-standard
                functions for Linux / Android.

\*****************************************************************************/
#pragma once

#include <stdint.h>
#include <wchar.h>

/*****************************************************************************\

Description:
    Defines related to unit conversion.

\*****************************************************************************/
#define IU_SECOND_IN_NS             1000000000ULL
#define IU_SECOND_IN_US             1000000ULL

/*****************************************************************************\

Description:
    Defines related to reading module and process names functionality.

\*****************************************************************************/
#define IU_MODULE_NAME_SIZE_MAX     128

/*****************************************************************************\

Description:
    OS dependent non-standard functions.

\*****************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

void     IuGetModuleInfo(
    char**    dlName,
    char**    processName );

void     IuLogGetSystemSettings(
    bool*     assertEnable,
    uint32_t* logLayerEnable,
    uint32_t* logLevel );

void     IuLogGetLocalSettings(
    bool*     assertEnable,
    uint32_t* logLayerEnable,
    uint32_t* logLevel );

#if defined(__cplusplus)
} // extern "C"
#endif
