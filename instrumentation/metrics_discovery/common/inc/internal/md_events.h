/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_events.h

//     Abstract:   C++ Metrics Discovery internal events header

#pragma once

#include "metrics_discovery_api.h"

#include <string>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Oa reporting types:                                                       //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EOaReportingType
    {
        OA_REPORTING_NONE            = QUERY_MODE_MASK_NONE,
        OA_REPORTING_RENDER          = QUERY_MODE_MASK_RENDER,
        OA_REPORTING_COMPUTE         = QUERY_MODE_MASK_COMPUTE,
        OA_REPORTING_GLOBAL          = QUERY_MODE_MASK_GLOBAL,
        OA_REPORTING_GLOBAL_EXTENDED = QUERY_MODE_MASK_GLOBAL_EXTENDED,
        OA_REPORTING_MEDIA           = 0x10,
    } TOaReportingType;

    ///////////////////////////////////////////////////////////////////////////////
    // Normalization types:                                                      //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum ENormalizationType
    {
        NORMALIZATION_TYPE_NONE        = 0,
        NORMALIZATION_TYPE_UTILIZATION = 1 << ( OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION - OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ),
        NORMALIZATION_TYPE_AVERAGE     = 1 << ( OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE - OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ),
        NORMALIZATION_TYPE_RATE        = 1 << ( OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE - OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ),
        NORMALIZATION_TYPE_BYTE        = 1 << ( OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE - OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ),
    } TNormalizationType;

    ///////////////////////////////////////////////////////////////////////////////
    // Arch event group types:                                                   //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EArchEventGroup
    {
        ARCH_EVENT_GROUP_NONE   = 0x0,
        ARCH_EVENT_GROUP_FIRST  = 0x1,
        ARCH_EVENT_GROUP_SECOND = 0x2,
        ARCH_EVENT_GROUP_FLEX   = 0x4,
    } TArchEventGroup;

    ///////////////////////////////////////////////////////////////////////////////
    // Hw event group types:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EHwEventGroup
    {
        HW_EVENT_GROUP_FIRST  = 0,
        HW_EVENT_GROUP_SECOND = 1,
        HW_EVENT_GROUP_FLEX   = 2,
    } THwEventGroup;

    ///////////////////////////////////////////////////////////////////////////////
    // Event workaround types:                                                   //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EEventWorkaroundType
    {
        EVENT_WORKAROUND_TYPE_NONE               = 0,
        EVENT_WORKAROUND_TYPE_ALL_COUNTERS       = 1,
        EVENT_WORKAROUND_TYPE_FLEX_COUNTERS      = 2,
        EVENT_WORKAROUND_TYPE_DISAGGREGATED_ONLY = 3,
    } TEventWorkaroundType;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SWorkaroundHeader
    //
    // Description:
    //     The workaround header.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SWorkaroundHeader
    {
        std::string m_name;
        bool        m_ignore;
        TValueType  m_type;

        SWorkaroundHeader( const char* name, const bool ignore );
    } TWorkaroundHeader;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SEventWorkaround
    //
    // Description:
    //     The event workaround.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SEventWorkaround
    {
        TEventWorkaroundType m_type;
        std::string          m_equation;

        SEventWorkaround();
    } TEventWorkaround;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SArchEventHeader
    //
    // Description:
    //     The architecture event header.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SArchEventHeader
    {
        std::string m_name;
        bool        m_ignore;
        TValueType  m_type;

        SArchEventHeader( const char* name, const bool ignore );
    } TArchEventHeader;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SArchEvent
    //
    // Description:
    //     The architecture event.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SArchEvent
    {
        TArchEventGroup     m_groupMask;
        uint32_t            m_eventEncoding;
        TByteArrayLatest*   m_platformMask;
        TOaReportingType    m_oaReportingType;
        TMetricType         m_metricType;
        THwUnitType         m_hwUnitType;
        std::string         m_name;
        std::string         m_description;
        std::string         m_oamUnit;
        std::string         m_groupName;
        std::string         m_instance;
        std::string         m_filter;
        std::string         m_resultUnits;
        TNormalizationType  m_normalization;
        TEventWorkaround    m_workaround;
        std::string         m_projectName;
        TDisaggregationMode m_disaggregationMode;

        SArchEvent();
    } TArchEvent;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SHwEventHeader
    //
    // Description:
    //     The hw event header.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SHwEventHeader
    {
        std::string m_name;
        bool        m_ignore;
        TValueType  m_type;

        SHwEventHeader( const char* name, const bool ignore );
    } THwEventHeader;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SHwEvent
    //
    // Description:
    //     The hardware event.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SHwEvent
    {
        const TArchEvent& m_archEvent;
        uint32_t          m_filterValue;
        std::string       m_name;
        std::string       m_shortName;
        std::string       m_description;
        uint32_t          m_disaggregationMask;
        TEventWorkaround  m_workaround;

        SHwEvent( TArchEvent& archEvent );
    } THwEvent;
} // namespace MetricsDiscoveryInternal
