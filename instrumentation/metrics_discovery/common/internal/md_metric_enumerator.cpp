/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_enumerator.cpp
//
//     Abstract:   C++ Metrics Discovery internal metric enumerator implementation

#include "md_metric_enumerator.h"
#include "md_oam_concurrent_group.h"
#include "md_metric_prototype.h"
#include "md_metrics_device.h"

#include "md_external_events.h"

#include "md_utils.h"

#include <cstring>
#include <sstream>
#include <regex>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     CMetricEnumerator constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     COAConcurrentGroup& oaConcurrentGroup - concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricEnumerator::CMetricEnumerator( COAConcurrentGroup& oaConcurrentGroup )
        : m_metricPrototypes()
        , m_oaConcurrentGroup( oaConcurrentGroup )
        , m_device( oaConcurrentGroup.GetMetricsDevice() )
        , m_isInitialized( false )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ~CMetricEnumerator destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricEnumerator::~CMetricEnumerator()
    {
        ClearVector( m_metricPrototypes );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     IsInitialized
    //
    // Description:
    //     Returns initialization state.
    //
    // Output:
    //     bool - true if metric enumerator is initialized, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricEnumerator::IsInitialized() const
    {
        return m_isInitialized;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     Initialize
    //
    // Description:
    //     Initializes metric enumerator.
    //
    // Input:
    //     const uint32_t oaReportingTypeMask - oa reporting type mask
    //
    // Output:
    //     TCompletionCode - CC_OK if metric enumerator has been initialized
    //                       correctly.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::Initialize( const uint32_t oaReportingTypeMask )
    {
        const uint32_t adapterId      = m_device.GetAdapter().GetAdapterId();
        const uint32_t platformIndex  = m_device.GetPlatformIndex();
        const bool     isOaReporting  = ( oaReportingTypeMask & ( OA_REPORTING_GLOBAL | OA_REPORTING_GLOBAL_EXTENDED | OA_REPORTING_RENDER | OA_REPORTING_COMPUTE ) ) != 0;
        const bool     isOamReporting = ( oaReportingTypeMask & OA_REPORTING_MEDIA ) != 0;
        bool           isXe2Plus      = false;

        TCompletionCode status = CC_ERROR_NOT_SUPPORTED;

        if( isOaReporting && isOamReporting )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Error: Cannot initialize common metric enumerator for OAM and OAG/OAR/OAC. oaReportingTypeMask: %u", oaReportingTypeMask );
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( isOaReporting )
        {
            switch( platformIndex )
            {
                case GENERATION_BMG:
                case GENERATION_LNL:
                    isXe2Plus = true;
                    break;

                default:
                    break;
            }

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS
            if( isXe2Plus )
            {
                // External events.
                status = ReadEvents(
                    ExternalEvents::archEvents,
                    sizeof( ExternalEvents::archEvents ),
                    ExternalEvents::hwEvents,
                    sizeof( ExternalEvents::hwEvents ) );

                if( status != CC_OK )
                {
                    return status;
                }
            }
#endif
        }

        if( isOamReporting )
        {
#if MD_INCLUDE_MTL_GT2_METRICS || MD_INCLUDE_MTL_GT3_METRICS || MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS || MD_INCLUDE_ARL_GT1_METRICS || MD_INCLUDE_ARL_GT2_METRICS
            if( IsPlatformMatch( platformIndex, GENERATION_MTL, GENERATION_BMG, GENERATION_LNL, GENERATION_ARL ) )
            {
                // External media events.
                status = ReadEvents(
                    ExternalEventsMedia::archEvents,
                    sizeof( ExternalEventsMedia::archEvents ),
                    ExternalEventsMedia::hwEvents,
                    sizeof( ExternalEventsMedia::hwEvents ) );

                if( status != CC_OK )
                {
                    return status;
                }
            }
#endif
        }

#if MD_INCLUDE_BMG_METRICS || MD_INCLUDE_LNL_METRICS
        // Read workarounds for external events.
        uint32_t workaroundsSize = sizeof( ExternalEventsWorkarounds::workarounds );
        uint8_t* workarounds     = new( std::nothrow ) uint8_t[workaroundsSize]();

        if( workarounds == nullptr )
        {
            return CC_ERROR_NO_MEMORY;
        }

        iu_memcpy_s( workarounds, workaroundsSize, ExternalEventsWorkarounds::workarounds, workaroundsSize );

        status = ReadWorkarounds( workarounds, sizeof( ExternalEventsWorkarounds::workarounds ) );

        MD_SAFE_DELETE_ARRAY( workarounds );
#endif
        if( m_metricPrototypes.size() == 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Cannot find any supported prototypes" );
            return CC_ERROR_NOT_SUPPORTED;
        }

        m_isInitialized = true;

        return status;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetMetricPrototypes
    //
    // Description:
    //     Returns metric prototypes vector.
    //
    // Output:
    //     std::vector<CMetricPrototype*>& - a reference to metric prototype vector.
    //
    //////////////////////////////////////////////////////////////////////////////
    std::vector<CMetricPrototype*>& CMetricEnumerator::GetMetricPrototypes()
    {
        return m_metricPrototypes;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetConcurrentGroup
    //
    // Description:
    //     Returns concurrent group.
    //
    // Output:
    //     COAConcurrentGroup& - a reference to concurrent group.
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup& CMetricEnumerator::GetConcurrentGroup()
    {
        return m_oaConcurrentGroup;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetMetricsDevice
    //
    // Description:
    //     Returns metrics device.
    //
    // Output:
    //     CMetricsDevice& - reference to metrics device associated with metric enumerator
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice& CMetricEnumerator::GetMetricsDevice()
    {
        return m_device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadEvents
    //
    // Description:
    //     Reads events from csv file.
    //
    // Input:
    //     const char*    archEvents     - architectural events buffer.
    //     const uint32_t archEventsSize - size of architectural events buffer.
    //     const char*    hwEvents       - hardware events buffer.
    //     const uint32_t hwEventsSize   - size of hardware events buffer.
    //
    // Output:
    //     TCompletionCode - CC_OK if all arch events have been read correctly.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::ReadEvents( const char* archEvents, const uint32_t archEventsSize, const char* hwEvents, const uint32_t hwEventsSize )
    {
        TCompletionCode status     = CC_OK;
        const uint32_t  eventsSize = ( archEventsSize > hwEventsSize ) ? archEventsSize : hwEventsSize;

        uint8_t* events = new( std::nothrow ) uint8_t[eventsSize]();
        if( events == nullptr )
        {
            return CC_ERROR_NO_MEMORY;
        }

        // Read architectural events.
        iu_memcpy_s( events, eventsSize, archEvents, archEventsSize );

        status = ReadArchEvents( events, archEventsSize );

        if( status != CC_OK )
        {
            MD_SAFE_DELETE_ARRAY( events );
            return status;
        }

        // Read hardware events.
        iu_zeromem( events, eventsSize );
        iu_memcpy_s( events, eventsSize, hwEvents, hwEventsSize );

        status = ReadHwEvents( events, hwEventsSize );

        MD_SAFE_DELETE_ARRAY( events );
        return status;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadArchEvents
    //
    // Description:
    //     Reads architecture events from csv file.
    //
    // Input:
    //     uint8_t*       fileBuffer - file buffer
    //     const uint32_t fileSize   - size of the file buffer
    //
    // Output:
    //     TCompletionCode - CC_OK if all arch events have been read correctly.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::ReadArchEvents( uint8_t* fileBuffer, const uint32_t fileSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        auto  archEventHeader = std::vector<TArchEventHeader>();
        auto& archEvents      = m_oaConcurrentGroup.GetArchEvents();

        // File buffer iterator, points to csv row.
        uint8_t*                 fileBufferIterator = fileBuffer;
        std::vector<const char*> csvRowValues;

        // Allocate memory for architectural events.
        uint32_t columnCount = 0;
        uint32_t rowCount    = 0;

        GetColumnAndRowCount( fileBuffer, fileSize, columnCount, rowCount );

        archEventHeader.reserve( columnCount );
        archEvents.reserve( archEvents.size() + rowCount );

        csvRowValues.resize( columnCount, nullptr );

        // Read header.
        auto ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
            return ret;
        }

        for( auto name : csvRowValues )
        {
            archEventHeader.emplace_back( name, false );
        }

        // Read arch event values.
        for( uint32_t i = 0; i < rowCount; ++i )
        {
            auto archEvent = new( std::nothrow ) TArchEvent();

            if( archEvent == nullptr )
            {
                ClearVector( archEvents );

                MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: archEvent" );
                return CC_ERROR_NO_MEMORY;
            }

            ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
            if( ret != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
                MD_SAFE_DELETE( archEvent );
                return ret;
            }

            for( uint32_t j = 0; j < archEventHeader.size(); ++j )
            {
                const auto archEventValueString = csvRowValues[j];
                if( archEventValueString == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_ERROR, "ERROR: null pointer: archEventValueString" );
                    MD_SAFE_DELETE( archEvent );
                    return CC_ERROR_GENERAL;
                }

                if( archEventHeader[j].m_ignore )
                {
                    continue;
                }

                if( archEventHeader[j].m_type == TValueType::VALUE_TYPE_UINT32 )
                {
                    if( archEventHeader[j].m_name == "Group Mask" )
                    {
                        archEvent->m_groupMask = static_cast<TArchEventGroup>( atoi( archEventValueString ) );
                    }
                    else if( archEventHeader[j].m_name == "Event Encoding" )
                    {
                        archEvent->m_eventEncoding = static_cast<uint32_t>( atoi( archEventValueString ) );
                    }
                    else if( archEventHeader[j].m_name == "Disaggregation Mode" )
                    {
                        archEvent->m_disaggregationMode = static_cast<TDisaggregationMode>( atoi( archEventValueString ) );
                    }
                    else if( archEventHeader[j].m_name == "Metric Type" )
                    {
                        archEvent->m_metricType = static_cast<TMetricType>( atoi( archEventValueString ) );
                    }
                    else if( archEventHeader[j].m_name == "Hw Unit Type" )
                    {
                        archEvent->m_hwUnitType = static_cast<THwUnitType>( atoi( archEventValueString ) );
                    }
                    else if( archEventHeader[j].m_name == "Normalization" )
                    {
                        archEvent->m_normalization = static_cast<TNormalizationType>( atoi( archEventValueString ) );
                    }
                }
                else if( archEventHeader[j].m_type == TValueType::VALUE_TYPE_CSTRING )
                {
                    if( archEventHeader[j].m_name == "Architectural Event Name" )
                    {
                        archEvent->m_name = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "Event Definition" )
                    {
                        archEvent->m_description = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "OA Reporting" )
                    {
                        const uint32_t valueLength = static_cast<uint32_t>( strlen( archEventValueString ) );

                        for( uint32_t k = 0; k < valueLength; ++k )
                        {
                            if( *( archEventValueString + k ) == 'R' )
                            {
                                archEvent->m_oaReportingType = static_cast<TOaReportingType>( archEvent->m_oaReportingType | OA_REPORTING_RENDER );
                            }
                            else if( *( archEventValueString + k ) == 'C' )
                            {
                                archEvent->m_oaReportingType = static_cast<TOaReportingType>( archEvent->m_oaReportingType | OA_REPORTING_COMPUTE );
                            }
                            else if( *( archEventValueString + k ) == 'G' )
                            {
                                archEvent->m_oaReportingType = static_cast<TOaReportingType>( archEvent->m_oaReportingType | OA_REPORTING_GLOBAL | OA_REPORTING_GLOBAL_EXTENDED );
                            }
                            else if( *( archEventValueString + k ) == 'M' )
                            {
                                archEvent->m_oaReportingType = static_cast<TOaReportingType>( archEvent->m_oaReportingType | OA_REPORTING_MEDIA );
                            }
                        }
                    }
                    else if( archEventHeader[j].m_name == "OAM Unit" )
                    {
                        archEvent->m_oamUnit = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "Project" )
                    {
                        archEvent->m_projectName  = archEventValueString;
                        archEvent->m_platformMask = CStrToPlatformMask( archEventValueString );
                    }
                    else if( archEventHeader[j].m_name == "Group Name" )
                    {
                        archEvent->m_groupName = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "Instance" )
                    {
                        archEvent->m_instance = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "Filter" )
                    {
                        archEvent->m_filter = archEventValueString;
                    }
                    else if( archEventHeader[j].m_name == "Metric Result Units" )
                    {
                        archEvent->m_resultUnits = archEventValueString;
                    }
                }
            }

            archEvents.emplace_back( archEvent );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadHwEvents
    //
    // Description:
    //     Reads hw events from csv file.
    //
    // Input:
    //     uint8_t*       fileBuffer - file buffer
    //     const uint32_t fileSize   - size of the file buffer
    //
    // Output:
    //     TCompletionCode - CC_OK if all hw events have been read correctly.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::ReadHwEvents( uint8_t* fileBuffer, const uint32_t fileSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        // File buffer iterator, points to csv row.
        uint8_t*                 fileBufferIterator = fileBuffer;
        std::vector<const char*> csvRowValues;

        // Allocate memory for hardware events.
        uint32_t columnCount = 0;
        uint32_t rowCount    = 0;

        std::vector<THwEventHeader> hwEventsHeader = {};

        GetColumnAndRowCount( fileBuffer, fileSize, columnCount, rowCount );

        hwEventsHeader.reserve( columnCount );
        m_metricPrototypes.reserve( m_metricPrototypes.size() + rowCount );

        csvRowValues.resize( columnCount, nullptr );

        // Read header.
        auto ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
            return ret;
        }

        for( auto name : csvRowValues )
        {
            hwEventsHeader.emplace_back( name, false );
        }

        // Read hw event values.
        for( uint32_t i = 0; i < rowCount; ++i )
        {
            ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
            if( ret != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
                return ret;
            }

            // The first column must be architectural event name!
            if( hwEventsHeader.size() > 0 &&
                hwEventsHeader[0].m_type == TValueType::VALUE_TYPE_CSTRING &&
                hwEventsHeader[0].m_name == "Architectural Event Name" )
            {
                const auto archEventName = csvRowValues[0];
                if( archEventName == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_ERROR, "ERROR: null pointer: hwEventValueString" );
                    return CC_ERROR_GENERAL;
                }

                const auto& archEvents         = m_oaConcurrentGroup.GetArchEvents();
                const auto  hwEventProjectName = csvRowValues[hwEventsHeader.size() - 1];

                auto archEventIterator = std::find_if(
                    archEvents.begin(),
                    archEvents.end(),
                    [&]( const TArchEvent* archEvent )
                    {
                        return ( archEvent->m_name == archEventName ) &&
                            ( archEvent->m_projectName == hwEventProjectName );
                    } );

                if( archEventIterator == archEvents.end() )
                {
                    ClearVector( m_metricPrototypes );

                    MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot find arch event" );
                    return CC_ERROR_INVALID_PARAMETER;
                }

                if( !IsPlatformPresentInMask( ( *archEventIterator )->m_platformMask, m_device.GetPlatformIndex(), adapterId ) )
                {
                    MD_LOG_A( adapterId, LOG_INFO, "The arch event %s is not supported on this platform", ( *archEventIterator )->m_name.c_str() );
                    continue;
                }

                if( ( ( *archEventIterator )->m_oaReportingType & OA_REPORTING_MEDIA ) != 0 &&
                    !IsPlatformMatch( m_device.GetPlatformIndex(), GENERATION_ARL, GENERATION_MTL ) )
                {
                    const auto concurrentGroupSymbolName = m_oaConcurrentGroup.GetParams()->SymbolName;

                    if( !COAMConcurrentGroup::IsValidSymbolName( concurrentGroupSymbolName ) )
                    {
                        MD_LOG_A( adapterId, LOG_INFO, "Not valid OAM concurrent group with symbol name: %s", concurrentGroupSymbolName );
                        continue;
                    }

                    const auto& archEventOamUnit = ( *archEventIterator )->m_oamUnit;
                    bool        isOamUnitValid   = false;

                    switch( concurrentGroupSymbolName[3] )
                    {
                        case 'G': // OAMG
                            isOamUnitValid = archEventOamUnit == "SAG";
                            break;
                        default: // OAMx
                            isOamUnitValid = archEventOamUnit == "SCMI";
                            break;
                    }

                    if( !isOamUnitValid )
                    {
                        MD_LOG_A( adapterId, LOG_INFO, "The arch event %s is not supported for %s OAM unit", ( *archEventIterator )->m_name.c_str(), archEventOamUnit.c_str() );
                        continue;
                    }
                }

                auto hwEvent = THwEvent( **archEventIterator );

                for( uint32_t j = 1; j < hwEventsHeader.size(); ++j )
                {
                    const auto hwEventValueString = csvRowValues[j];
                    if( hwEventValueString == nullptr )
                    {
                        MD_LOG_A( adapterId, LOG_ERROR, "ERROR: null pointer: hwEventValueString" );
                        return CC_ERROR_GENERAL;
                    }

                    if( hwEventsHeader[j].m_ignore )
                    {
                        continue;
                    }

                    if( hwEventsHeader[j].m_type == TValueType::VALUE_TYPE_UINT32 )
                    {
                        if( hwEventsHeader[j].m_name == "Filter Value" )
                        {
                            hwEvent.m_filterValue = atoi( hwEventValueString ) & 0b1111;
                        }
                    }
                    else if( hwEventsHeader[j].m_type == TValueType::VALUE_TYPE_CSTRING )
                    {
                        if( hwEventsHeader[j].m_name == "Hw Event Name" )
                        {
                            hwEvent.m_name = hwEventValueString;
                        }
                        else if( hwEventsHeader[j].m_name == "Hw Event Short Name" )
                        {
                            hwEvent.m_shortName = hwEventValueString;
                        }
                        else if( hwEventsHeader[j].m_name == "Hw Event Description" )
                        {
                            hwEvent.m_description = hwEventValueString;
                        }
                    }
                }

                auto metricPrototype = new( std::nothrow ) CMetricPrototype( *this, std::move( hwEvent ) );

                if( metricPrototype == nullptr )
                {
                    ClearVector( m_metricPrototypes );

                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: metricPrototype" );
                    return CC_ERROR_NO_MEMORY;
                }
                else if( metricPrototype->Initialize() != CC_OK )
                {
                    MD_SAFE_DELETE( metricPrototype );
                    ClearVector( m_metricPrototypes );
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: cannot initialize metric prototype" );
                    return CC_ERROR_GENERAL;
                }

                m_metricPrototypes.emplace_back( metricPrototype );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadWorkarounds
    //
    // Description:
    //     Reads workarounds from csv file.
    //
    // Input:
    //     uint8_t*       fileBuffer - file buffer
    //     const uint32_t fileSize   - size of the file buffer
    //
    // Output:
    //     TCompletionCode - CC_OK if all hw events have been read correctly.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::ReadWorkarounds( uint8_t* fileBuffer, const uint32_t fileSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        // File buffer iterator, points to csv row.
        uint8_t*                 fileBufferIterator = fileBuffer;
        std::vector<const char*> csvRowValues;

        // Allocate memory for workarounds.
        uint32_t columnCount = 0;
        uint32_t rowCount    = 0;

        std::vector<TWorkaroundHeader> workaroundsHeader = {};

        GetColumnAndRowCount( fileBuffer, fileSize, columnCount, rowCount );

        workaroundsHeader.reserve( columnCount );

        csvRowValues.resize( columnCount, nullptr );

        // Read header.
        auto ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
            return ret;
        }

        for( auto name : csvRowValues )
        {
            workaroundsHeader.emplace_back( name, false );
        }

        // Read workaround values.
        for( uint32_t i = 0; i < rowCount; ++i )
        {
            TEventWorkaround workaround = {};
            TArchEvent*      archEvent  = nullptr;
            THwEvent*        hwEvent    = nullptr;
            bool             skipRow    = false;

            ret = ReadCsvRow( fileBufferIterator, fileSize, csvRowValues );
            if( ret != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot read csv row" );
                return ret;
            }

            for( uint32_t j = 0; j < workaroundsHeader.size(); ++j )
            {
                const auto workaroundValueString = csvRowValues[j];
                if( workaroundValueString == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_ERROR, "ERROR: null pointer: workaroundValueString" );
                    return CC_ERROR_GENERAL;
                }

                if( workaroundsHeader[j].m_ignore )
                {
                    continue;
                }

                if( workaroundsHeader[j].m_type == TValueType::VALUE_TYPE_UINT32 )
                {
                    if( workaroundsHeader[j].m_name == "Type" )
                    {
                        workaround.m_type = static_cast<TEventWorkaroundType>( atoi( workaroundValueString ) );
                    }
                }
                else if( workaroundsHeader[j].m_type == TValueType::VALUE_TYPE_CSTRING )
                {
                    if( workaroundsHeader[j].m_name == "Project" )
                    {
                        skipRow = true;

                        std::istringstream stream( workaroundValueString );
                        for( std::string project; std::getline( stream, project, ' ' ); )
                        {
                            if( std::smatch projectMatch;
                                std::regex_search( project, projectMatch, std::regex( "([A-Z0-9]+):?(([0-9]+)-([0-9]+))?" ) ) ) // Format: Platform:VersionMin-VersionMax
                            {
                                MD_ASSERT_A( adapterId, projectMatch.size() == 5 );

                                const std::string platform   = projectMatch[1].str();
                                const std::string versionMin = projectMatch[3].str();
                                const std::string versionMax = projectMatch[4].str();

                                uint32_t platformIndex = CStrToPlatformIndex( platform.c_str() );

                                if( platformIndex == m_device.GetPlatformIndex() )
                                {
                                    if( versionMin != "" && versionMax != "" )
                                    {
                                        const uint32_t versionMinIndex = std::stoi( versionMin );
                                        const uint32_t versionMaxIndex = std::stoi( versionMax );

                                        if( auto platformVersion = m_device.GetGlobalSymbolValueByName( "PlatformVersion" );
                                            platformVersion == nullptr ||
                                            ( platformVersion->ValueType == VALUE_TYPE_UINT32 &&
                                                platformVersion->ValueUInt32 >= versionMinIndex &&
                                                platformVersion->ValueUInt32 <= versionMaxIndex ) )
                                        {
                                            // PlatformVersion is null or is between min and max, so the workaround is supported.
                                            skipRow = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        // Not specified platform version range, assume the workaround is for all versions of a given platform.
                                        skipRow = false;
                                        break;
                                    }
                                }
                            }
                        }

                        if( skipRow )
                        {
                            break;
                        }
                    }
                    else if( workaroundsHeader[j].m_name == "Event" )
                    {
                        std::string event = workaroundValueString;

                        if( std::smatch eventMatch;
                            std::regex_search( event, eventMatch, std::regex( "(Arch|Hw):" ) ) )
                        {
                            MD_ASSERT_A( adapterId, eventMatch.size() == 2 );

                            if( eventMatch[1].str() == "Arch" ) // Workaround for architectural event
                            {
                                const auto& archEvents = m_oaConcurrentGroup.GetArchEvents();

                                auto archEventIterator = std::find_if(
                                    archEvents.begin(),
                                    archEvents.end(),
                                    [&]( const TArchEvent* archEvent )
                                    {
                                        return ( archEvent->m_name == eventMatch.suffix() ) &&
                                            IsPlatformPresentInMask( archEvent->m_platformMask, m_device.GetPlatformIndex(), adapterId );
                                    } );

                                if( archEventIterator != archEvents.end() )
                                {
                                    archEvent = *archEventIterator;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            else // Workaround for hardware event
                            {
                                auto prototypeIterator = std::find_if(
                                    m_metricPrototypes.begin(),
                                    m_metricPrototypes.end(),
                                    [&]( CMetricPrototype* prototype )
                                    {
                                        auto& event = prototype->GetHwEvent();

                                        return ( event.m_name == eventMatch.suffix() ) &&
                                            IsPlatformPresentInMask( event.m_archEvent.m_platformMask, m_device.GetPlatformIndex(), adapterId );
                                    } );

                                if( prototypeIterator != m_metricPrototypes.end() )
                                {
                                    hwEvent = &( *prototypeIterator )->GetHwEvent();
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                    }
                    else if( workaroundsHeader[j].m_name == "Equation" )
                    {
                        workaround.m_equation = workaroundValueString;
                    }
                }
            }

            if( skipRow )
            {
                // Do not process the workaround.
                continue;
            }

            if( workaround.m_equation == "1 UMUL" || workaround.m_equation == "1 UDIV" )
            {
                workaround.m_equation = "";
            }

            // Add workaround to arch.
            if( archEvent != nullptr )
            {
                if( workaround.m_type == EVENT_WORKAROUND_TYPE_FLEX_COUNTERS )
                {
                    // Override group mask to only flex group.
                    archEvent->m_groupMask = ARCH_EVENT_GROUP_FLEX;

                    if( workaround.m_equation.empty() )
                    {
                        // Not needed workaround.
                        workaround.m_type = EVENT_WORKAROUND_TYPE_NONE;
                    }
                    else
                    {
                        // Group mask is overridden to flex-only, so workaround can have "all counters" type.
                        workaround.m_type = EVENT_WORKAROUND_TYPE_ALL_COUNTERS;
                    }
                }

                archEvent->m_workaround = std::move( workaround );
            }

            // Add workaround to hw event.
            if( hwEvent != nullptr )
            {
                hwEvent->m_workaround = std::move( workaround );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadCsvRow
    //
    // Description:
    //     Reads one row from csv file.
    //
    // Input:
    //     uint8_t*&                 fileBuffer - file buffer
    //     const uint32_t            fileSize   - size of the file buffer
    //
    // Output:
    //     std::vector<const char*>& rowValues  - read row values
    //     TCompletionCode                      - CC_OK if row read successfully
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::ReadCsvRow( uint8_t*& fileBuffer, const uint32_t fileSize, std::vector<const char*>& rowValues )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        bool     endOfRow   = false;
        uint32_t startIndex = 0;
        uint32_t endIndex   = 0;
        uint32_t valueIndex = 0;

        while( !endOfRow )
        {
            if( valueIndex > rowValues.size() - 1 )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: index is out of range. Index: %d, vector size: %d", valueIndex, rowValues.size() );
                return CC_ERROR_INVALID_PARAMETER;
            }

            const auto value = ReadCsvValue( fileBuffer, fileSize, startIndex, endIndex, endOfRow );
            if( value == nullptr )
            {
                return CC_ERROR_GENERAL;
            }

            rowValues[valueIndex++] = value;
            startIndex              = endIndex + 1;
        }

        if( valueIndex != rowValues.size() )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: rowValues vector is not fully filled. Filled: %d, expected: %d", valueIndex, rowValues.size() );
            return CC_ERROR_GENERAL;
        }

        fileBuffer += endIndex + 1;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     ReadCsvValue
    //
    // Description:
    //     Reads a single value from csv file.
    //
    // Input:
    //     uint8_t*       fileBuffer - file buffer
    //     const uint32_t fileSize   - size of the file buffer
    //     const uint32_t startIndex - start buffer index
    //
    // Output:
    //     uint32_t&      endIndex   - end buffer index
    //     bool&          endOfRow   - indicates if it is the end of a row
    //     char*                     - read value as array of chars
    //
    //////////////////////////////////////////////////////////////////////////////
    char* CMetricEnumerator::ReadCsvValue( uint8_t* fileBuffer, const uint32_t fileSize, const uint32_t startIndex, uint32_t& endIndex, bool& endOfRow )
    {
        bool isInsideQuote = false;

        // Read string from csv.
        while( isInsideQuote || ( ( *( fileBuffer + endIndex ) != ',' ) && ( *( fileBuffer + endIndex ) != '\n' ) ) )
        {
            if( *( fileBuffer + endIndex ) == '\"' )
            {
                isInsideQuote = !isInsideQuote;
            }

            ++endIndex;

            if( endIndex >= fileSize )
            {
                return nullptr;
            }
        }

        if( *( fileBuffer + endIndex ) == ',' ) // Only comma.
        {
            *( fileBuffer + endIndex ) = '\0';
        }
        else if( *( fileBuffer + endIndex ) == '\n' ) // End line.
        {
            *( fileBuffer + endIndex ) = '\0';

            if( *( fileBuffer + endIndex - 1 ) == '\r' ) // Optional carriage return.
            {
                *( fileBuffer + endIndex - 1 ) = '\0';
            }

            endOfRow = true;
        }

        char*          valueString = reinterpret_cast<char*>( fileBuffer + startIndex );
        const uint32_t valueLength = static_cast<uint32_t>( strlen( valueString ) );

        if( *valueString == '\"' ) // Remove quotation marks if needed.
        {
            *( valueString + valueLength - 1 ) = '\0';
            ++valueString;
        }

        return valueString;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetColumnAndRowCount
    //
    // Description:
    //     Return row and column count from file buffer.
    //
    // Input:
    //     uint8_t*       fileBuffer - file buffer
    //     const uint32_t fileSize   - size of the file buffer
    //
    // Output:
    //     uint32_t& columnCount     - column count
    //     uint32_t& rowCount        - row count
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricEnumerator::GetColumnAndRowCount( uint8_t* fileBuffer, const uint32_t fileSize, uint32_t& columnCount, uint32_t& rowCount )
    {
        constexpr uint32_t maxColumns = 100;
        constexpr uint32_t maxRows    = 10000;

        for( uint32_t i = 0; i < fileSize; ++i )
        {
            if( fileBuffer[i] == ',' )
            {
                columnCount++;
            }
            else if( fileBuffer[i] == '\n' )
            {
                if( ++columnCount > maxColumns )
                {
                    columnCount = maxColumns;
                }
                break;
            }
        }

        for( uint32_t i = 0; i < fileSize; ++i )
        {
            if( fileBuffer[i] == '\n' )
            {
                if( ++rowCount > maxRows )
                {
                    rowCount = maxRows;
                    break;
                }
            }
        }
        if( fileBuffer[fileSize - 2] == '\n' )
        {
            if( rowCount > 0 )
            {
                rowCount--;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     CStrToPlatformMask
    //
    // Description:
    //     Converts a c-string of space-separated platform names into a platform mask byte array
    //
    // Input:
    //     const char* const platformString - c-string of platform names
    //
    // Output:
    //     TByteArrayLatest* - pointer to dynamically allocated platform mask
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest* CMetricEnumerator::CStrToPlatformMask( const char* const platformString )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        auto platformMask = new( std::nothrow ) TByteArrayLatest{ MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, new( std::nothrow ) uint8_t[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE]() };

        if( platformString == nullptr )
        {
            return platformMask;
        }

        std::istringstream stream( platformString );
        for( std::string platform; std::getline( stream, platform, ' ' ); )
        {
            uint32_t platformIndex = CStrToPlatformIndex( platform.c_str() );

            if( platformIndex == GTDI_PLATFORM_MAX )
            {
                MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Incorrect platform - %s", platform.c_str() );
                continue;
            }

            auto result = SetPlatformMask( adapterId, platformMask, nullptr, true, platformIndex );
            if( result != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Cannot set platform mask!" );
            }
        }

        return platformMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     CStrToPlatformIndex
    //
    // Description:
    //     Converts a platform name into a platform index
    //
    // Input:
    //     const char* const platformString - c-string of platform name
    //
    // Output:
    //     GTDI_PLATFORM_INDEX              - platform index
    //
    //////////////////////////////////////////////////////////////////////////////
    GTDI_PLATFORM_INDEX CMetricEnumerator::CStrToPlatformIndex( const char* const platformString )
    {
        std::string_view platform = platformString;

        if( platform == "MTL" )
        {
            return GENERATION_MTL;
        }
#if MD_INCLUDE_BMG_METRICS
        if( platform == "BMG" )
        {
            return GENERATION_BMG;
        }
#endif // MD_INCLUDE_BMG_METRICS
#if MD_INCLUDE_LNL_METRICS
        if( platform == "LNL" )
        {
            return GENERATION_LNL;
        }
#endif // MD_INCLUDE_LNL_METRICS
        if( platform == "ARL" )
        {
            return GENERATION_ARL;
        }

        return GTDI_PLATFORM_MAX;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetMetricPrototypeCount
    //
    // Description:
    //     Returns metric prototype count.
    //
    // Output:
    //     uint32_t         - metric prototype count.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricEnumerator::GetMetricPrototypeCount( void )
    {
        return static_cast<uint32_t>( m_metricPrototypes.size() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetMetricPrototype
    //
    // Description:
    //     Returns metric prototype.
    //
    // Output:
    //     IMetricPrototype_1_13*   - pointer to metric prototype.
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricPrototype_1_13* CMetricEnumerator::GetMetricPrototype( const uint32_t index )
    {
        return ( index < m_metricPrototypes.size() )
            ? m_metricPrototypes[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     GetMetricPrototypes
    //
    // Description:
    //     Returns multiple metric prototypes.
    //
    // Output:
    //     TCompletionCode          - result of the operation.
    //     IMetricPrototype_1_13**  - pointer to array of metric prototypes.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::GetMetricPrototypes( const uint32_t index, uint32_t* count, IMetricPrototype_1_13** metrics )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_ASSERT_A( adapterId, count != nullptr );
        MD_ASSERT_A( adapterId, metrics != nullptr );

        if( count == nullptr || metrics == nullptr )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        const uint32_t size = static_cast<uint32_t>( m_metricPrototypes.size() );

        if( index >= size )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( index + *count > size )
        {
            // Update count.
            *count = size - index;
        }

        for( uint32_t i = 0; i < *count; ++i )
        {
            metrics[i] = static_cast<CMetricPrototype*>( m_metricPrototypes[i + index] );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Method:
    //     RemoveClonedMetricPrototype
    //
    // Description:
    //     Removes cloned metric prototype.
    //
    // Input:
    //     IMetricPrototype_1_13* - a pointer to metric prototype to be removed.
    //
    // Output:
    //     TCompletionCode        - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricEnumerator::RemoveClonedMetricPrototype( IMetricPrototype_1_13* clonedPrototype )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, clonedPrototype, CC_ERROR_INVALID_PARAMETER );

        CMetricPrototype*       prototype = static_cast<CMetricPrototype*>( clonedPrototype );
        const CMetricPrototype* parent    = prototype->GetParent();

        if( parent == nullptr )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Cannot delete predefined or parent prototype!" );
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( prototype->GetReferenceCounter() > 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Cannot delete prototype added to a metric set!" );
            return CC_ERROR_INVALID_PARAMETER;
        }

        auto prototypeIterator = std::find( m_metricPrototypes.begin(), m_metricPrototypes.end(), prototype );

        if( prototypeIterator == m_metricPrototypes.end() )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Cannot find the cloned prototype!" );
            return CC_ERROR_INVALID_PARAMETER;
        }

        for( auto& metricPrototype : m_metricPrototypes )
        {
            if( metricPrototype->GetParent() == prototype )
            {
                // Update parents for all cloned prototypes that have been cloned from the prototype that is being deleted.
                if( metricPrototype->UpdateParent( parent ) != CC_OK )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Could not update parent for a prototype!" );
                }
            }
        }

        m_metricPrototypes.erase( prototypeIterator );

        MD_SAFE_DELETE( prototype );

        return CC_OK;
    }
} // namespace MetricsDiscoveryInternal
