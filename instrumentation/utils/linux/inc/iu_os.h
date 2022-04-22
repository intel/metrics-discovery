/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  iu_os.h

//     Abstract:   Instrumentation Utils header with OS specific non-standard
//                 functions for Linux / Android.

#pragma once

#include <stdint.h>
#include <wchar.h>

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Defines related to unit conversion.
//
//////////////////////////////////////////////////////////////////////////////
#define IU_SECOND_IN_NS 1000000000ULL
#define IU_SECOND_IN_US 1000000ULL

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Defines related to reading module and process names functionality.
//
//////////////////////////////////////////////////////////////////////////////
#define IU_MODULE_NAME_SIZE_MAX 128

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     OS dependent non-standard functions.
//
//////////////////////////////////////////////////////////////////////////////
#if defined( __cplusplus )
extern "C"
{
#endif

    uint64_t IuOsQueryPerformanceCounter(
        uint64_t* outFrequency );

    const char* IuOsGetModuleInfo(
        char** processName );

    void IuOsLogGetSystemSettings(
        void*     deviceContext,
        bool*     assertEnable,
        uint32_t* logLayerEnable,
        uint32_t* logLevel );

    void IuOsLogGetLocalSettings(
        bool*     assertEnable,
        uint32_t* logLayerEnable,
        uint32_t* logLevel );

#if defined( __cplusplus )
} // extern "C"
#endif
