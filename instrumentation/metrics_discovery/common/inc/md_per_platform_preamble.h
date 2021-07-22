/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_per_platform_preamble.h

//     Abstract:   C++ Metrics Discovery internal header

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
