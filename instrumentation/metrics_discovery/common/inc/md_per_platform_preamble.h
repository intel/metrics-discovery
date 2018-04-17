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

    File Name:  md_per_platform_preamble.h

    Abstract:   C++ Metrics Discovery internal header

\*****************************************************************************/
#pragma once

#include "metrics_discovery_api.h"
#include "md_exports.h"
#include "md_internal.h"

#if defined(_DEBUG) || defined(_RELEASE_INTERNAL)
#define MD_IS_INTERNAL_BUILD 1
#else
#define MD_IS_INTERNAL_BUILD 0
#endif // defined(_DEBUG) || defined(_RELEASE_INTERNAL)

// NOTE:
//  MD_INCLUDE_{platform}_METRICS preprocessor macros may be added to compilation parameters
//   to control the scope of metrics.
//  If none of the macros is defined all platforms with source support will be included
//  By defining any of the macros one will automatically exclude all other platforms
#define MD_INCLUDE_ALL_METRICS ( !(MD_INCLUDE_SKL_GT2_METRICS || \
                                   MD_INCLUDE_SKL_GT3_METRICS || \
                                   MD_INCLUDE_SKL_GT4_METRICS || \
                                   MD_INCLUDE_BXT_METRICS || \
                                   MD_INCLUDE_KBL_GT2_METRICS || \
                                   MD_INCLUDE_KBL_GT3_METRICS) )

using namespace MetricsDiscovery;
using namespace MetricsDiscoveryInternal;

// Global handle to MetricsDevice
extern CMetricsDevice* g_MetricsDevice;
