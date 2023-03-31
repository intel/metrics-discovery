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

#define MD_INCLUDE_Common_METRICS 1

// NOTE:
//    MD_INCLUDE_{platform}_METRICS preprocessor macros may be added to compilation parameters
//    to control the scope of metrics.
//    If none of the macros is defined all platforms with source support will be included
//    By defining any of the macros one will automatically exclude all other platforms

// clang-format off
    #if !( MD_INCLUDE_HSW_METRICS              || \
           MD_INCLUDE_BDW_METRICS              || \
           MD_INCLUDE_SKL_GT2_METRICS          || \
           MD_INCLUDE_SKL_GT3_METRICS          || \
           MD_INCLUDE_SKL_GT4_METRICS          || \
           MD_INCLUDE_BXT_METRICS              || \
           MD_INCLUDE_GLK_METRICS              || \
           MD_INCLUDE_KBL_GT2_METRICS          || \
           MD_INCLUDE_KBL_GT3_METRICS          || \
           MD_INCLUDE_CFL_GT2_METRICS          || \
           MD_INCLUDE_CFL_GT3_METRICS          || \
           MD_INCLUDE_ICL_METRICS              || \
           MD_INCLUDE_EHL_METRICS              || \
           MD_INCLUDE_TGL_GT1_METRICS          || \
           MD_INCLUDE_TGL_GT2_METRICS          || \
           MD_INCLUDE_DG1_METRICS              || \
           MD_INCLUDE_RKL_METRICS              || \
           MD_INCLUDE_ADLP_METRICS             || \
           MD_INCLUDE_ADLS_METRICS             || \
           MD_INCLUDE_ADLN_METRICS             || \
           MD_INCLUDE_XEHP_SDV_GT1_GT2_METRICS || \
           MD_INCLUDE_XEHP_SDV_GT1_METRICS     || \
           MD_INCLUDE_XEHP_SDV_GT2_METRICS     || \
           MD_INCLUDE_ACM_GT1_METRICS          || \
           MD_INCLUDE_ACM_GT2_METRICS          || \
           MD_INCLUDE_ACM_GT3_METRICS          || \
           MD_INCLUDE_PVC_GT1_METRICS          || \
           MD_INCLUDE_PVC_GT2_METRICS          || \
           MD_INCLUDE_MTL_GT2_METRICS          || \
           MD_INCLUDE_MTL_GT3_METRICS )
// clang-format on

    #define MD_INCLUDE_HSW_METRICS              1
    #define MD_INCLUDE_BDW_METRICS              1
    #define MD_INCLUDE_SKL_GT2_METRICS          1
    #define MD_INCLUDE_SKL_GT3_METRICS          1
    #define MD_INCLUDE_SKL_GT4_METRICS          1
    #define MD_INCLUDE_BXT_METRICS              1
    #define MD_INCLUDE_GLK_METRICS              1
    #define MD_INCLUDE_KBL_GT2_METRICS          1
    #define MD_INCLUDE_KBL_GT3_METRICS          1
    #define MD_INCLUDE_CFL_GT2_METRICS          1
    #define MD_INCLUDE_CFL_GT3_METRICS          1
    #define MD_INCLUDE_ICL_METRICS              1
    #define MD_INCLUDE_EHL_METRICS              1
    #define MD_INCLUDE_TGL_GT1_METRICS          1
    #define MD_INCLUDE_TGL_GT2_METRICS          1
    #define MD_INCLUDE_DG1_METRICS              1
    #define MD_INCLUDE_RKL_METRICS              1
    #define MD_INCLUDE_ADLP_METRICS             1
    #define MD_INCLUDE_ADLS_METRICS             1
    #define MD_INCLUDE_ADLN_METRICS             1
    #define MD_INCLUDE_XEHP_SDV_GT1_GT2_METRICS 1
    #define MD_INCLUDE_XEHP_SDV_GT1_METRICS     1
    #define MD_INCLUDE_XEHP_SDV_GT2_METRICS     1
    #define MD_INCLUDE_ACM_GT1_METRICS          1
    #define MD_INCLUDE_ACM_GT2_METRICS          1
    #define MD_INCLUDE_ACM_GT3_METRICS          1
    #define MD_INCLUDE_PVC_GT1_METRICS          1
    #define MD_INCLUDE_PVC_GT2_METRICS          1
    #define MD_INCLUDE_MTL_GT2_METRICS          1
    #define MD_INCLUDE_MTL_GT3_METRICS          1
#endif
