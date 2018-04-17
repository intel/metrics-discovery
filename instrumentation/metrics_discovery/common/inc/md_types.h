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

    File Name:  md_types.h

    Abstract:   C++ Metrics Discovery types header

\*****************************************************************************/
#pragma once

#include "metrics_discovery_api.h"

// Defines
#define MD_MAX_CONTEXT_TAGS 128  // Should match max count used by Intel driver

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{

    /******************************************************************************/
    /* Stream types:                                                              */
    /******************************************************************************/
    typedef enum EStreamType
    {
        STREAM_TYPE_OA = 0,
        STREAM_TYPE_SYS,
        STREAM_TYPE_BB,
        // ...
    } TStreamType;

    /******************************************************************************/
    /* Override types:                                                            */
    /******************************************************************************/
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

    /******************************************************************************/
    /* Io Measurement Info types:                                                 */
    /******************************************************************************/
    typedef enum EIoMeasurementInfoType
    {
        IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ = 0,
        IO_MEASUREMENT_INFO_FREQUENCY_CHANGED,
        IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID,
        IO_MEASUREMENT_INFO_SLICE_SHUTDOWN,
        IO_MEASUREMENT_INFO_DATA_OUTSTANDING,
        IO_MEASUREMENT_INFO_REPORT_LOST,
        // ...
        IO_MEASUREMENT_INFO_LAST,
    } TIoMeasurementInfoType;

    /******************************************************************************/
    /* Context Tag types:                                                         */
    /******************************************************************************/
    typedef enum EContextTagType
    {
        CONTEXT_TAG_TYPE_RENDER,  // Should be in sync with instrumentation INSTR_RENDER_CONTEXT_TAG, same for other entries
        CONTEXT_TAG_TYPE_PRESENT,
        // ...
        CONTEXT_TAG_TYPE_LAST,
    } TContextTagType;

    /******************************************************************************/
    /* Context Tag                                                                */
    /******************************************************************************/
    typedef struct SContextTag
    {
        uint32_t        PID;
        uint32_t        ContextTag;
        TContextTagType ContextTagType;
    } TContextTag;

    /******************************************************************************/
    /* Get context id tags params:                                                */
    /******************************************************************************/
    typedef struct SGetCtxIdTagsParams
    {
        // IN
        uint32_t PID;                           // Process ID, 0 is global
        uint32_t Offset;                        // Skip first offset tags
        // OUT
        uint32_t StateChangeCount;              // Increases during context creation / removal
        uint32_t AvailableTags;                 // All available tag count
        uint32_t TagCount;                      // Returned tag count
        TContextTag  Tags[MD_MAX_CONTEXT_TAGS]; // Returned tags
    } TGetCtxTagsIdParams;

    /******************************************************************************/
    /* Same as LARGE_INTEGER, used in metric calculation:                         */
    /******************************************************************************/
    typedef union ULargeInteger
    {
        struct
        {
            uint32_t LowPart;
            int32_t  HighPart;
        };
        struct
        {
            uint32_t LowPart;
            int32_t  HighPart;
        } u;
        int64_t QuadPart;
    } TLargeInteger;
};

