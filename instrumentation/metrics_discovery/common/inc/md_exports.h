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
//////////////////////////////////////////////////////////////////////////////

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

    DllExport TCompletionCode OpenAdapterGroup( IAdapterGroup_1_9** adapterGroup );

    // Note: when changing IMetricsDevice version in params remember about OGL PerfQuery - it needs to be changed too
    DllExport TCompletionCode OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice );

    DllExport TCompletionCode CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice );

    DllExport TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice );

#if defined( _DEBUG ) || defined( _RELEASE_INTERNAL )

    DllExport TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_5* metricsDevice );

#endif // defined(_DEBUG) || defined(_RELEASE_INTERNAL)

#ifdef __cplusplus
}
#endif
