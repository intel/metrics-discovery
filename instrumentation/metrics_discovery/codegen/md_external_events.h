/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_external_events.h
//
//     Abstract:   C++ automated generated file defined architectural events

#pragma once

#include "md_per_platform_preamble.h"

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS

struct ExternalEvents
{
    static const char archEvents[35113];
    static const char hwEvents[48966];
};

#endif

#if MD_INCLUDE_MTL_GT2_METRICS || MD_INCLUDE_MTL_GT3_METRICS || MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS || MD_INCLUDE_ARL_GT1_METRICS || MD_INCLUDE_ARL_GT2_METRICS

struct ExternalEventsMedia
{
    static const char archEvents[1941];
    static const char hwEvents[2517];
};

#endif

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_PTL_METRICS

struct ExternalEventsWorkarounds
{
    static const char workarounds[409];
};

#endif
