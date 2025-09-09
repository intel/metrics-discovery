/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_events.cpp

//     Abstract:   C++ Metrics Discovery internal events implementation

#include "md_events.h"
#include "md_utils.h"

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SWorkaroundHeader
    //
    // Method:
    //     SWorkaroundHeader constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     const char* name   -
    //     const bool  ignore -
    //
    //////////////////////////////////////////////////////////////////////////////
    SWorkaroundHeader::SWorkaroundHeader( const char* name, const bool ignore )
        : m_name( name )
        , m_ignore( ignore )
    {
        if( m_name == "Type" )
        {
            m_type = VALUE_TYPE_UINT32;
        }
        else if( m_name == "Project" ||
            m_name == "Event" ||
            m_name == "Equation" )
        {
            m_type = VALUE_TYPE_CSTRING;
        }
        else
        {
            m_ignore = true;
            m_type   = VALUE_TYPE_CSTRING;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SEventWorkaround
    //
    // Method:
    //     SEventWorkaround constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    SEventWorkaround::SEventWorkaround()
        : m_type( EVENT_WORKAROUND_TYPE_NONE )
        , m_equation( "" )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SArchEventHeader
    //
    // Method:
    //     SArchEventHeader constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     const char* name   - arch event header name.
    //     const bool  ignore - true if the property needs to be ignored.
    //
    //////////////////////////////////////////////////////////////////////////////
    SArchEventHeader::SArchEventHeader( const char* name, const bool ignore )
        : m_name( name )
        , m_ignore( ignore )
    {
        if( m_name == "Group Mask" ||
            m_name == "Event Encoding" ||
            m_name == "Disaggregation Mode" ||
            m_name == "Metric Type" ||
            m_name == "Hw Unit Type" ||
            m_name == "Normalization" )
        {
            m_type = VALUE_TYPE_UINT32;
        }
        else if( m_name == "Architectural Event Name" ||
            m_name == "Event Definition" ||
            m_name == "OA Reporting" ||
            m_name == "OAM Unit" ||
            m_name == "Project" ||
            m_name == "Group Name" ||
            m_name == "Instance" ||
            m_name == "Filter" ||
            m_name == "Metric Result Units" )
        {
            m_type = VALUE_TYPE_CSTRING;
        }
        else
        {
            m_ignore = true;
            m_type   = VALUE_TYPE_CSTRING;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SArchEvent
    //
    // Method:
    //     SArchEvent constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    SArchEvent::SArchEvent()
        : m_groupMask( ARCH_EVENT_GROUP_NONE )
        , m_eventEncoding( 0 )
        , m_platformMask( nullptr )
        , m_oaReportingType( OA_REPORTING_NONE )
        , m_metricType( METRIC_TYPE_EVENT )
        , m_hwUnitType( HW_UNIT_GPU )
        , m_name( "" )
        , m_description( "" )
        , m_oamUnit( "" )
        , m_groupName( "" )
        , m_instance( "" )
        , m_filter( "" )
        , m_resultUnits( "" )
        , m_normalization( NORMALIZATION_TYPE_NONE )
        , m_projectName( "" )
        , m_disaggregationMode( DISAGGREGATION_MODE_NONE )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SArchEvent
    //
    // Method:
    //     SArchEvent destructor
    //
    // Description:
    //     Destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    SArchEvent::~SArchEvent()
    {
        DeleteByteArray( m_platformMask, IU_ADAPTER_ID_UNKNOWN );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SHwEventHeader
    //
    // Method:
    //     SHwEventHeader constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     const char* name   - hw event header name.
    //     const bool  ignore - true if the property needs to be ignored.
    //
    //////////////////////////////////////////////////////////////////////////////
    SHwEventHeader::SHwEventHeader( const char* name, const bool ignore )
        : m_name( name )
        , m_ignore( ignore )
    {
        if( m_name == "Filter Value" )
        {
            m_type = VALUE_TYPE_UINT32;
        }
        else if( m_name == "Architectural Event Name" ||
            m_name == "Hw Event Name" ||
            m_name == "Hw Event Short Name" ||
            m_name == "Hw Event Description" )
        {
            m_type = VALUE_TYPE_CSTRING;
        }
        else
        {
            m_ignore = true;
            m_type   = VALUE_TYPE_CSTRING;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     SHwEvent
    //
    // Method:
    //     SHwEvent constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     TArchEvent& archEvent - arch event reference
    //
    //////////////////////////////////////////////////////////////////////////////
    SHwEvent::SHwEvent( TArchEvent& archEvent )
        : m_archEvent( archEvent )
        , m_filterValue( 0 )
        , m_name( "" )
        , m_shortName( "" )
        , m_description( "" )
        , m_disaggregationMask( 0 )
    {
    }
} // namespace MetricsDiscoveryInternal
