/*****************************************************************************\

    Copyright © 2018, Intel Corporation

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

    File Name:  md_debug.h

    Abstract:   C++ header with Metrics Discovery debug functions and macros

\*****************************************************************************/
#pragma once

#include "iu_debug.h"

/////////////////////////////////////////////////////////////
// METRICS DISCOVERY LAYER LOGS
/////////////////////////////////////////////////////////////
// Tag to prefix log messages with
#if !defined(MDAPI_LOG_TAG)
#define MDAPI_LOG_TAG "[MDAPI]"
#endif

#define MD_ASSERT(expr)        IU_ASSERT_TAGGED             (expr,       IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG)
#define MD_LOG(level, ...)     IU_DBG_PRINT_TAGGED          (_##level,   IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG, __VA_ARGS__)
#define MD_LOG_ENTER()         IU_DBG_FUNCTION_ENTER_TAGGED (_LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG);
#define MD_LOG_EXIT()          IU_DBG_FUNCTION_EXIT_TAGGED  (_LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG)

#define MD_LOG_INVALID_PARAMETER(level, variable) MD_LOG(level, "invalid parameter: %s", #variable);
