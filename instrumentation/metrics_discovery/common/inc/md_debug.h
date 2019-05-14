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

    File Name:  md_debug.h

    Abstract:   Header with Metrics Discovery debug functions and macros

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
#define MD_LOG(level, ...)     IU_DBG_PRINT_TAGGED          (_##level,   IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG, __FUNCTION__, __VA_ARGS__)
#define MD_LOG_ENTER()         IU_DBG_FUNCTION_ENTER_TAGGED (_LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG);
#define MD_LOG_EXIT()          IU_DBG_FUNCTION_EXIT_TAGGED  (_LOG_DEBUG, IU_DBG_LAYER_MDAPI, MDAPI_LOG_TAG)

#define MD_LOG_INVALID_PARAMETER(level, variable) MD_LOG(level, "invalid parameter: %s", #variable);


/*****************************************************************************\
MACRO: Following macros are required for compatibility between IU debug framework
       and current MDAPI logs.
\*****************************************************************************/
#define _LOG_ERROR                          IU_DBG_SEV_ERROR
#define _LOG_WARNING                        IU_DBG_SEV_WARNING
#define _LOG_INFO                           IU_DBG_SEV_INFO
#define _LOG_DEBUG                          IU_DBG_SEV_DEBUG

#define __LOG_ERROR                         IU_DBG_SEV_ERROR
#define __LOG_WARNING                       IU_DBG_SEV_WARNING
#define __LOG_INFO                          IU_DBG_SEV_INFO
#define __LOG_DEBUG                         IU_DBG_SEV_DEBUG

#define F__LOG_ERROR(level, layer, ...)     F_IU_DBG_SEV_ERROR(level, layer, __VA_ARGS__)
#define F__LOG_WARNING(level, layer, ...)   F_IU_DBG_SEV_WARNING(level, layer, __VA_ARGS__)
#define F__LOG_INFO(level, layer, ...)      F_IU_DBG_SEV_INFO(level, layer, __VA_ARGS__)
#define F__LOG_DEBUG(level, layer, ...)     F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)

#define F___LOG_ERROR(level, layer, ...)    F_IU_DBG_SEV_ERROR(level, layer, __VA_ARGS__)
#define F___LOG_WARNING(level, layer, ...)  F_IU_DBG_SEV_WARNING(level, layer, __VA_ARGS__)
#define F___LOG_INFO(level, layer, ...)     F_IU_DBG_SEV_INFO(level, layer, __VA_ARGS__)
#define F___LOG_DEBUG(level, layer, ...)    F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)
