/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_external_events.h
//
//     Abstract:   C++ automated generated file defined architectural events

#pragma once

#include "md_per_platform_preamble.h"

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS || MD_INCLUDE_NVL_METRICS || MD_INCLUDE_NVLP_METRICS || MD_INCLUDE_CRI_METRICS

struct ExternalEvents
{
    static const char archEvents[43831];
    static const char hwEvents[59601];
};

#endif

#if MD_INCLUDE_MTL_GT2_METRICS || MD_INCLUDE_MTL_GT3_METRICS || MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS || MD_INCLUDE_ARL_GT1_METRICS || MD_INCLUDE_ARL_GT2_METRICS || MD_INCLUDE_NVL_METRICS || MD_INCLUDE_NVLP_METRICS || MD_INCLUDE_CRI_METRICS

struct ExternalEventsMedia
{
    static const char archEvents[2196];
    static const char hwEvents[2772];
};

#endif

#if MD_INCLUDE_CRI_METRICS

struct ExternalEventsMert
{
    static const char archEvents[1118];
    static const char hwEvents[1128];
};

#endif

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS || MD_INCLUDE_NVL_METRICS || MD_INCLUDE_NVLP_METRICS || MD_INCLUDE_CRI_METRICS

struct ExternalEventsWorkarounds
{
    static const char workarounds[563];
};

#endif
