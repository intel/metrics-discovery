/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics.h

//     Abstract:   C++ Metrics Discovery header for metric meta data.

#pragma once

#define MD_CLEAR_UNSOPPORTED_HW_MASK_VECTOR( vector ) \
    for( auto& element : vector )                     \
    {                                                 \
        element.Clear();                              \
    }                                                 \
    vector.clear();

#include "metrics_discovery_api.h"

using namespace MetricsDiscovery;

///////////////////////////////////////////////////////////////////////////////
// Forward declarations:                                                     //
///////////////////////////////////////////////////////////////////////////////
namespace MetricsDiscoveryInternal
{
    class CMetricsDevice;
}

TCompletionCode CreateMetricTree( MetricsDiscoveryInternal::CMetricsDevice* metricsDevice );
