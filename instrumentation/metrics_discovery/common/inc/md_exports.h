/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_exports.h

//     Abstract:   Header with exports of the MetricsDiscovery library. Exports on Windows
//                 are defined in the project file.

#pragma once

#include "metrics_discovery_api.h"

using namespace MetricsDiscovery;

#if defined( __linux__ )
    #define DllExport __attribute__( ( visibility( "default" ) ) )
#else
    // On Windows exports through project settings (linker commands)
    // ! WARNING: Windows exports a different set of functions than Linux !
    #define DllExport
#endif // __linux__

#ifdef __cplusplus
extern "C"
{
#endif

    DllExport TCompletionCode OpenAdapterGroup( IAdapterGroupLatest** adapterGroup );

    // Note: when changing IMetricsDevice version in params remember about OGL PerfQuery - it needs to be changed too
    DllExport TCompletionCode OpenMetricsDevice( IMetricsDeviceLatest** metricsDevice );

    DllExport TCompletionCode CloseMetricsDevice( IMetricsDeviceLatest* metricsDevice );

    DllExport TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDeviceLatest** metricsDevice );

#if defined( _DEBUG ) || defined( _RELEASE_INTERNAL )

    DllExport TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDeviceLatest* metricsDevice );

#endif // defined(_DEBUG) || defined(_RELEASE_INTERNAL)

#ifdef __cplusplus
}
#endif
