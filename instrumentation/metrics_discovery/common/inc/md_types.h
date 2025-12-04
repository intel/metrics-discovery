/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_types.h

//     Abstract:   C++ Metrics Discovery types header

#pragma once

#include "metrics_discovery_internal_api.h"

// Defines
#define MD_MAX_CONTEXT_TAGS              128 // Should match max count used by Intel driver
#define MD_PLATFORM_MASK_BYTE_ARRAY_SIZE 8

#define MD_BYTE            8
#define MD_KBYTE           1024
#define MD_MBYTE           1048576
#define MD_MHERTZ          1000000
#define MD_NSEC_PER_SEC    1000000000ULL
#define MD_INTEL_VENDOR_ID 0x8086

#define MD_ROOT_DEVICE_INDEX 0

using namespace MetricsDiscovery;

constexpr uint32_t MD_QUERY_API_MASK = ( API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_DX12 | API_TYPE_VULKAN );

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CEquation;

    ///////////////////////////////////////////////////////////////////////////////
    // OA report types:                                                          //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EReportType
    {
        OA_REPORT_TYPE_256B_A45_NOA16     = GTDI_REPORT_TYPE_256B_A45_NOA16,
        OA_REPORT_TYPE_320B_PEC64         = GTDI_REPORT_TYPE_320B_PEC64,
        OA_REPORT_TYPE_576B_PEC64LL       = GTDI_REPORT_TYPE_576B_PEC64LL,
        OA_REPORT_TYPE_640B_PEC64LL_NOA16 = GTDI_REPORT_TYPE_640B_PEC64LL_NOA16,
        OA_REPORT_TYPE_192B_MPEC8LL_NOA16 = GTDI_REPORT_TYPE_192B_MPEC8LL_NOA16,
        OA_REPORT_TYPE_128B_MPEC8_NOA16   = GTDI_REPORT_TYPE_128B_MPEC8_NOA16,
        // ...
        OA_REPORT_TYPE_LAST,
    } TReportType;

    ///////////////////////////////////////////////////////////////////////////////
    // Stream types:                                                             //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EStreamType
    {
        STREAM_TYPE_OA = 0,
        STREAM_TYPE_SYS,
        STREAM_TYPE_BB,
        STREAM_TYPE_OAM,
        // ...
    } TStreamType;

    ///////////////////////////////////////////////////////////////////////////////
    // Override types:                                                           //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EOverrideType
    {
        OVERRIDE_TYPE_FREQUENCY = 0,
        OVERRIDE_TYPE_NULL_HARDWARE,
        OVERRIDE_TYPE_EXTENDED_QUERY,
        OVERRIDE_TYPE_MULTISAMPLED_QUERY,
        OVERRIDE_TYPE_FLUSH_GPU_CACHES,
        OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS,
        // ...
        OVERRIDE_TYPE_LAST,
    } TOverrideType;

    ///////////////////////////////////////////////////////////////////////////////
    // Io Measurement Info types:                                                //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EIoMeasurementInfoType
    {
        IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ = 0,
        IO_MEASUREMENT_INFO_FREQUENCY_CHANGED,
        IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID,
        IO_MEASUREMENT_INFO_SLICE_SHUTDOWN,
        IO_MEASUREMENT_INFO_DATA_OUTSTANDING,
        IO_MEASUREMENT_INFO_REPORT_LOST,
        IO_MEASUREMENT_INFO_BUFFER_OVERFLOW,
        IO_MEASUREMENT_INFO_BUFFER_OVERRUN,
        IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW,
        // ...
        IO_MEASUREMENT_INFO_LAST,
    } TIoMeasurementInfoType;

    ///////////////////////////////////////////////////////////////////////////////
    // Context Tag types:                                                        //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EContextTagType
    {
        CONTEXT_TAG_TYPE_RENDER, // Should be in sync with instrumentation INSTR_RENDER_CONTEXT_TAG, same for other entries
        CONTEXT_TAG_TYPE_PRESENT,
        CONTEXT_TAG_TYPE_INTERNAL,
        // ...
        CONTEXT_TAG_TYPE_LAST,
    } TContextTagType;

    ///////////////////////////////////////////////////////////////////////////////
    // Context Tag                                                               //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SContextTag
    {
        uint32_t        PID;
        uint32_t        ContextTag;
        TContextTagType ContextTagType;
        uint32_t        Node;
    } TContextTag;

    ///////////////////////////////////////////////////////////////////////////////
    // Get context id tags params:                                               //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SGetCtxIdTagsParams
    {
        // IN
        uint32_t PID;    // Process ID, 0 is global
        uint32_t Offset; // Skip first offset tags
        // OUT
        uint32_t    StateChangeCount;          // Increases during context creation / removal
        uint32_t    AvailableTags;             // All available tag count
        uint32_t    TagCount;                  // Returned tag count
        TContextTag Tags[MD_MAX_CONTEXT_TAGS]; // Returned tags
    } TGetCtxTagsIdParams;

    ///////////////////////////////////////////////////////////////////////////////
    // Same as LARGE_INTEGER, used in metric calculation:                        //
    ///////////////////////////////////////////////////////////////////////////////
    typedef union ULargeInteger
    {
        struct
        {
            uint32_t LowPart;
            int32_t  HighPart;
        } u;
        int64_t QuadPart;
    } TLargeInteger;

    ///////////////////////////////////////////////////////////////////////////////
    // API versions:                                                             //
    ///////////////////////////////////////////////////////////////////////////////
    enum EApiVersion
    {
        API_VERSION_1_0 = 0,
    };

    ///////////////////////////////////////////////////////////////////////////////
    // Symbol types:                                                             //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum ESymbolType
    {
        SYMBOL_TYPE_IMMEDIATE, // static value
        SYMBOL_TYPE_DETECT,    // static value detected during initialization
        SYMBOL_TYPE_DYNAMIC    // dynamic value that can change during runtime
    } TSymbolType;

    ///////////////////////////////////////////////////////////////////////////////
    // Global symbol:                                                            //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SGlobalSymbol
    {
        EApiVersion version;
        union
        {
            TGlobalSymbolLatest symbol;
        };
        TSymbolType symbolType;
    } TGlobalSymbol;

    ///////////////////////////////////////////////////////////////////////////////
    // Register set params:                                                      //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SRegisterSetParams
    {
        uint32_t    ConfigId;
        uint32_t    ConfigPriority;
        TConfigType ConfigType;
    } TRegisterSetParams;

}; // namespace MetricsDiscoveryInternal
