//////////////////////////////////////////////////////////////////////////////
//
//  Copyright © 2019-2021, Intel Corporation
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//
//  File Name:  md_per_platform_preamble.h
//
//  Abstract:   C++ Metrics Discovery internal header
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "metrics_discovery_api.h"

#if defined( _DEBUG ) || defined( _RELEASE_INTERNAL )
    #define MD_IS_INTERNAL_BUILD 1
#else
    #define MD_IS_INTERNAL_BUILD 0
#endif // defined(_DEBUG) || defined(_RELEASE_INTERNAL)

// official
#define MD_INCLUDE_Common_METRICS  1
#define MD_INCLUDE_HSW_METRICS     1
#define MD_INCLUDE_BDW_METRICS     1
#define MD_INCLUDE_SKL_GT2_METRICS 1
#define MD_INCLUDE_SKL_GT3_METRICS 1
#define MD_INCLUDE_SKL_GT4_METRICS 1
#define MD_INCLUDE_CHV_METRICS     1
#define MD_INCLUDE_BXT_METRICS     1
#define MD_INCLUDE_GLK_METRICS     1
#define MD_INCLUDE_KBL_GT2_METRICS 1
#define MD_INCLUDE_KBL_GT3_METRICS 1
#define MD_INCLUDE_CNL_METRICS     1
#define MD_INCLUDE_CFL_GT2_METRICS 1
#define MD_INCLUDE_CFL_GT3_METRICS 1
#define MD_INCLUDE_ICL_METRICS     1
#define MD_INCLUDE_EHL_METRICS     1
#define MD_INCLUDE_TGL_GT1_METRICS 1
#define MD_INCLUDE_TGL_GT2_METRICS 1
#define MD_INCLUDE_DG1_METRICS     1
#define MD_INCLUDE_RKL_METRICS     1
