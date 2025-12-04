/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_set.cpp

//     Abstract:   C++ Metrics Discovery internal metric set implementation

#include "md_metric_set.h"
#include "md_adapter.h"
#include "md_concurrent_group.h"
#include "md_oam_concurrent_group.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metrics_device.h"
#include "md_register_set.h"
#include "md_metric_prototype.h"
#include "md_metric_enumerator.h"
#include "md_metric_prototype_manager.h"
#include "md_metrics_calculator.h"

#include "md_calculation.h"
#include "md_driver_ifc.h"
#include "md_utils.h"

#include <cstring>
#include <unordered_map>

//////////////////////////////////////////////////////////////////////////////
// Helper macro to get CustomMetricParams
//////////////////////////////////////////////////////////////////////////////
#define MD_CUSTOM_METRIC_PARAMS( params, version ) ( params )->CustomMetricParams_##version

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CMetricSet constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice&     device             -
    //     CConcurrentGroup*   concurrentGroup    -
    //     const char*         symbolicName       -
    //     const char*         shortName          -
    //     uint32_t            apiMask            -
    //     uint32_t            categoryMask       -
    //     uint32_t            snapshotReportSize -
    //     uint32_t            deltaReportSize    -
    //     TReportType         reportType         -
    //     TByteArrayLatest*   platformMask       -
    //     uint32_t            gtMask             -
    //     bool                isCustom           -
    //     bool                aggregationEnabled -
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet::CMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/, bool aggregationEnabled /*= false*/ )
        : m_concurrentGroup( concurrentGroup )
        , m_params{}
        , m_device( device )
        , m_reportType( reportType )
        , m_metricsVector()
        , m_informationVector()
        , m_complementarySetsVector()
        , m_startRegsVector()
        , m_startRegsQueryVector()
        , m_startRegisterSetList()
        , m_otherMetricsVector()
        , m_otherInformationVector()
        , m_platformMask( GetCopiedByteArray( platformMask, m_device.GetAdapter().GetAdapterId() ) )
        , m_availabilityEquation( nullptr )
        , m_filteredParams{}
        , m_filteredMetricsVector()
        , m_filteredInformationVector()
        , m_isCustom( isCustom )
        , m_aggregationEnabled( aggregationEnabled )
        , m_isReadRegsCfgSet( false )
        , m_pmRegsConfigInfo{}
        , m_metricsCalculator( nullptr )
        , m_isOam( COAMConcurrentGroup::IsValidSymbolName( concurrentGroup->GetParams()->SymbolName ) )
        , m_isFlexible( false )
        , m_isOpened( false )
        , m_prototypeManager( nullptr )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        m_params.SymbolName       = GetCopiedCString( symbolicName, adapterId );
        m_params.ShortName        = GetCopiedCString( shortName, adapterId );
        m_params.ApiMask          = apiMask;
        m_params.CategoryMask     = categoryMask;
        m_params.RawReportSize    = snapshotReportSize; // as in HW
        m_params.QueryReportSize  = deltaReportSize;    // as in Query API
        m_params.InformationCount = concurrentGroup->GetInformationCount();
        m_params.PlatformMask     = GetPlatformTypeFromByteArray( platformMask, adapterId );
        m_params.GtMask           = gtMask;

        // Set 'current' variables and mark 'filtered' params as uninitialized
        UseApiFilteredVariables( false );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet destructor
    //
    // Method:
    //     ~CMetricSet
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet::~CMetricSet()
    {
        MD_SAFE_DELETE_ARRAY( m_params.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params.ApiSpecificId.D3D1XDevDependentName );
        MD_SAFE_DELETE_ARRAY( m_params.ApiSpecificId.OGLQueryIntelName );
        MD_SAFE_DELETE_ARRAY( m_params.AvailabilityEquation );

        ClearCachedMetricsAndInformation();

        ClearVector( m_metricsVector );
        ClearVector( m_informationVector );
        ClearVector( m_complementarySetsVector );

        // Clearing m_startRegsVector and m_startRegsQueryVector is
        // not necessary as they share pointers with m_startRegisterSetList

        ClearList( m_startRegisterSetList );

        ClearVector( m_otherMetricsVector );
        ClearVector( m_otherInformationVector );
        MD_SAFE_DELETE( m_metricsCalculator );

        MD_SAFE_DELETE( m_availabilityEquation );
        MD_SAFE_DELETE( m_prototypeManager );

        DeleteByteArray( m_platformMask, m_device.GetAdapter().GetAdapterId() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Initialize
    //
    // Description:
    //     Virtual method that initialize metric set.
    //     Used in derived metric set classes.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Initialize()
    {
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns metric set params
    //
    // Output:
    //     TMetricSetParamsLatest* - metric set params
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricSetParamsLatest* CMetricSet::GetParams( void )
    {
        return m_currentParams;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetMetric
    //
    // Description:
    //     Returns the chosen metric or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t index  - index of a metric
    //
    // Output:
    //     IMetricLatest*  - chosen metric or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CMetricSet::GetMetric( uint32_t index )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, m_currentMetricsVector, nullptr );

        if( index < m_currentMetricsVector->size() )
        {
            return static_cast<IMetricLatest*>( ( *m_currentMetricsVector )[index] );
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetInformation
    //
    // Description:
    //     Returns the chosen information or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of an information
    //
    // Output:
    //     IInformation_1_0*   - chosen information or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* CMetricSet::GetInformation( uint32_t index )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, m_currentInformationVector, nullptr );

        if( m_isFiltered )
        {
            return ( index < m_currentInformationVector->size() )
                ? static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index] )
                : nullptr;
        }

        // if index is in Concurrent Group indexes bounds ( 0..N, N = amount of infs in concurrent group )
        const uint32_t cgInformationCount = m_concurrentGroup->GetInformationCount();

        if( index < cgInformationCount )
        {
            // return information from Concurrent Group
            return m_concurrentGroup->GetInformation( index );
        }
        else if( index < m_currentInformationVector->size() + cgInformationCount )
        {
            return static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index - cgInformationCount] );
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetComplementaryMetricSet
    //
    // Description:
    //     Returns the chosen complementary metric set or null if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of a complementary set
    //
    // Output:
    //     IMetricSetLatest*   - chosen complementary metric set or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CMetricSet::GetComplementaryMetricSet( uint32_t index )
    {
        if( index < m_complementarySetsVector.size() )
        {
            IMetricSetLatest* metricSet       = nullptr;
            size_t            stringLength    = strlen( m_complementarySetsVector[index] );
            uint32_t          metricSetsCount = m_concurrentGroup->GetParams()->MetricSetsCount;
            for( uint32_t i = 0; i < metricSetsCount; i++ )
            {
                metricSet = m_concurrentGroup->GetMetricSet( i );
                if( strncmp( metricSet->GetParams()->SymbolName, m_complementarySetsVector[index], stringLength ) == 0 )
                {
                    return metricSet;
                }
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Activate
    //
    // Description:
    //     To enable this configuration before query instance is created or IO stream is opened.
    //     Locks the concurrent group and sends the configuration if lock was successful.
    //
    // Output:
    //     TCompletionCode  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Activate( void )
    {
        if( m_isOpened )
        {
            MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_ERROR, "Finalize method has not been called before Activate" );
            return CC_ERROR_GENERAL;
        }

        // Cannot change metric sets after their activation.
        m_isFlexible = false;

        return ActivateInternal( true, true );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Deactivate
    //
    // Description:
    //     Unlocks the concurrent group after query instance is created or IO stream is opened.
    //     Sends 'empty' read regs config if it was previously set.
    //
    // Output:
    //     TCompletionCode  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Deactivate( void )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );
        TCompletionCode ret = CC_OK;

        if( m_isOpened )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Finalize method has not been called before Deactivate" );
            return CC_ERROR_GENERAL;
        }

        if( m_isReadRegsCfgSet )
        {
            auto& driverInterface = m_device.GetDriverInterface();

            TRegister  emptyRrConfig    = { 0, 0, REGISTER_TYPE_MMIO };
            TRegister* emptyRrConfigPtr = &emptyRrConfig; // Because we will need 'array of pointers'

            ret = driverInterface.SendReadRegsConfig( &emptyRrConfigPtr, 1 );
            if( ret == CC_OK )
            {
                // Update PmRegsHandles and reset rrSet flag
                driverInterface.GetPmRegsConfigHandles( &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
                m_isReadRegsCfgSet = false;
            }
        }

        if( ret == CC_OK )
        {
            ret = m_concurrentGroup->Unlock();
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     MetricGroupNameToId
    //
    // Description:
    //     To get order of group names
    //
    // Output:
    //     uint32_t - group id, METRIC_GROUP_NAME_ID_INVALID if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricSet::MetricGroupNameToId( const char* groupName )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, groupName, METRIC_GROUP_NAME_ID_INVALID );

        uint32_t groupId = 0, tokenNo = 0;
        char *   token = nullptr, *tokenNext = nullptr, *groupNameCopy = nullptr;

        groupNameCopy = GetCopiedCString( groupName, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, groupNameCopy, METRIC_GROUP_NAME_ID_INVALID );

        token = iu_strtok_s( groupNameCopy, "/", &tokenNext );
        while( token != nullptr )
        {
            uint32_t partialGroupId = GetPartialGroupId( token, tokenNo++ );

            groupId += partialGroupId;
            token = iu_strtok_s( nullptr, "/", &tokenNext );
        }

        MD_SAFE_DELETE_ARRAY( groupNameCopy );
        return groupId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetPartialGroupId
    //
    // Description:
    //     Returns group id based on a given depth and group name.
    //
    // Input:
    //     char*        groupName - group name at depth
    //     uint32_t     level     - group name level, e.g. A\B\C - A has level 0, B has level 1
    //
    // Output:
    //     uint32_t    - group id, METRIC_GROUP_NAME_ID_INVALID if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricSet::GetPartialGroupId( char* groupName, uint32_t level )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_ASSERT_A( adapterId, groupName != nullptr );

        if( level > MD_METRIC_GROUP_NAME_LEVEL_MAX )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "maximum group name level allowed is %u", MD_METRIC_GROUP_NAME_LEVEL_MAX );
            return METRIC_GROUP_NAME_ID_INVALID;
        }

        uint32_t groupId      = METRIC_GROUP_NAME_ID_INVALID;
        uint32_t currentLevel = 1 << level;
        uint32_t shift        = ( MD_METRIC_GROUP_NAME_LEVEL_MAX - level ) * MD_BYTE;
        uint32_t pairCount    = sizeof( GroupNamePairs ) / sizeof( TMetricGroupNameIdPair );

        for( uint32_t i = 0; i < pairCount; i++ )
        {
            if( ( GroupNamePairs[i].LevelMask & currentLevel ) && ( strcmp( groupName, GroupNamePairs[i].Name ) == 0 ) )
            {
                groupId = GroupNamePairs[i].Id << shift;
                break;
            }
        }

        if( groupId == METRIC_GROUP_NAME_ID_INVALID )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "invalid group name: %s at level: %u", groupName, level );

            groupId = METRIC_GROUP_NAME_ID_GPU; // Use default group name ID
        }

        return groupId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddCustomMetric
    //
    // Description:
    //     Adds the custom metric with the given parameters.
    //
    // Input:
    //     TAddCustomMetricParams * params - params
    //
    // Output:
    //     IMetricLatest* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CMetricSet::AddCustomMetric( TAddCustomMetricParams* params )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( params == nullptr )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, params );
            return nullptr;
        }

        const char*       symbolName            = nullptr;
        const char*       shortName             = nullptr;
        const char*       groupName             = nullptr;
        const char*       longName              = nullptr;
        const char*       dxToOglAlias          = nullptr;
        uint32_t          usageFlagsMask        = 0;
        uint32_t          apiMask               = 0;
        TMetricResultType resultType            = RESULT_UINT32;
        const char*       resultUnits           = nullptr;
        TMetricType       metricType            = METRIC_TYPE_DURATION;
        int64_t           loWatermark           = 0;
        int64_t           hiWatermark           = 0;
        THwUnitType       hwType                = HW_UNIT_GPU;
        const char*       ioReadEquation        = nullptr;
        const char*       deltaFunction         = nullptr;
        const char*       queryReadEquation     = nullptr;
        const char*       normalizationEquation = nullptr;
        const char*       maxValueEquation      = nullptr;
        const char*       signalName            = nullptr;
        const char*       availabilityEquation  = nullptr;
        uint32_t          queryModeMask         = 0;

        switch( params->Type )
        {
            case METRIC_CUSTOM_PARAMS_1_0:
            {
                symbolName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SymbolName;
                shortName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ShortName;
                groupName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).GroupName;
                longName              = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LongName;
                dxToOglAlias          = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DxToOglAlias;
                usageFlagsMask        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).UsageFlagsMask;
                apiMask               = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ApiMask;
                resultType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ResultType;
                resultUnits           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricResultUnits;
                metricType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricType;
                loWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LowWatermark;
                hiWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HighWatermark;
                hwType                = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HwUnitType;
                ioReadEquation        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).IoReadEquation;
                deltaFunction         = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DeltaFunction;
                queryReadEquation     = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).QueryReadEquation;
                normalizationEquation = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).NormEquation;
                maxValueEquation      = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MaxValueEquation;
                signalName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SignalName;
                availabilityEquation  = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).AvailabilityEquation;
                queryModeMask         = ( apiMask & MD_QUERY_API_MASK )
                            ? static_cast<uint32_t>( QUERY_MODE_MASK_ALL )   // By default, a query metric supports all query modes
                            : static_cast<uint32_t>( QUERY_MODE_MASK_NONE ); // By default, a tbs metric does not support any query
                break;
            }

            case METRIC_CUSTOM_PARAMS_1_1:
            {
                symbolName            = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).SymbolName;
                shortName             = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).ShortName;
                groupName             = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).GroupName;
                longName              = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).LongName;
                dxToOglAlias          = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).DxToOglAlias;
                usageFlagsMask        = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).UsageFlagsMask;
                apiMask               = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).ApiMask;
                resultType            = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).ResultType;
                resultUnits           = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).MetricResultUnits;
                metricType            = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).MetricType;
                loWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).LowWatermark;
                hiWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).HighWatermark;
                hwType                = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).HwUnitType;
                ioReadEquation        = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).IoReadEquation;
                deltaFunction         = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).DeltaFunction;
                queryReadEquation     = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).QueryReadEquation;
                normalizationEquation = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).NormEquation;
                maxValueEquation      = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).MaxValueEquation;
                signalName            = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).SignalName;
                availabilityEquation  = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).AvailabilityEquation;
                queryModeMask         = MD_CUSTOM_METRIC_PARAMS( params, 1_1 ).QueryModeMask;

                break;
            }

            default:
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Unsupported TAddCustomMetricParams Type: %u", params->Type );
                return nullptr;
            }
        }

        MD_LOG_ENTER_A( adapterId );

        if( !AreMetricParamsValid(
                symbolName, shortName, longName, groupName, metricType, resultType, resultUnits, hwType, dxToOglAlias ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "invalid custom metric parameters" );
            return nullptr;
        }
        if( !IsCustomApiMaskValid( apiMask ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "wrong apiMask: %x", apiMask );
            return nullptr;
        }
        if( IsMetricAlreadyAdded( symbolName ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "metric already added: %s", symbolName );
            return nullptr;
        }
        if( usageFlagsMask == 0 || usageFlagsMask > USAGE_FLAG_ALL )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "wrong usageFlagsMask: %x", usageFlagsMask );
            return nullptr;
        }

        uint32_t groupId = MetricGroupNameToId( groupName );

        CMetric* metric = new( std::nothrow ) CMetric( m_device, static_cast<uint32_t>( m_metricsVector.size() ), symbolName, shortName, longName, groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, resultUnits, loWatermark, hiWatermark, hwType, dxToOglAlias, signalName, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, nullptr );

        metric->SetQueryModeMask( queryModeMask );

        if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK || metric->SetSnapshotReportReadEquation( ioReadEquation ) != CC_OK || metric->SetDeltaReportReadEquation( queryReadEquation ) != CC_OK || metric->SetNormalizationEquation( normalizationEquation ) != CC_OK || metric->SetSnapshotReportDeltaFunction( deltaFunction ) != CC_OK || metric->SetMaxValueEquation( maxValueEquation ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error setting custom metric equations" );
            MD_SAFE_DELETE( metric );
            return nullptr;
        }

        m_metricsVector.push_back( metric );
        m_params.MetricsCount = static_cast<uint32_t>( m_metricsVector.size() );
        m_isCustom            = true;

        // Refresh cached filtered metrics
        RefreshCachedMetricsAndInformation();

        MD_LOG_A( adapterId, LOG_DEBUG, "Custom metric %s is added", symbolName );
        MD_LOG_EXIT_A( adapterId );
        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddCustomMetric
    //
    // Description:
    //     Adds custom metric with given parameters.
    //
    // Input:
    //     const char * symbolName                  -
    //     const char * shortName                   -
    //     const char * groupName                   -
    //     const char * longName                    -
    //     const char * dxToOglAlias                -
    //     uint32_t     usageFlagsMask              -
    //     uint32_t     apiMask                     -
    //     TMetricResultType resultType             -
    //     const char * resultUnits                 -
    //     TMetricType metricType                   -
    //     int64_t *   loWatermark                  -
    //     int64_t *   hiWatermark                  -
    //     THwUnitType hwType                       -
    //     const char * ioReadEquation              -
    //     const char * deltaFunction               -
    //     const char * queryReadEquation           -
    //     const char * normalizationEquation       -
    //     const char * maxValueEquation            -
    //     const char * signalName                  -
    //
    // Output:
    //     IMetricLatest* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CMetricSet::AddCustomMetric( const char* symbolName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName )
    {
        TAddCustomMetricParams params                      = {};
        params.Type                                        = METRIC_CUSTOM_PARAMS_1_0;
        params.CustomMetricParams_1_0.SymbolName           = symbolName;
        params.CustomMetricParams_1_0.ShortName            = shortName;
        params.CustomMetricParams_1_0.GroupName            = groupName;
        params.CustomMetricParams_1_0.LongName             = longName;
        params.CustomMetricParams_1_0.DxToOglAlias         = dxToOglAlias;
        params.CustomMetricParams_1_0.UsageFlagsMask       = usageFlagsMask;
        params.CustomMetricParams_1_0.ApiMask              = apiMask;
        params.CustomMetricParams_1_0.ResultType           = resultType;
        params.CustomMetricParams_1_0.MetricResultUnits    = resultUnits;
        params.CustomMetricParams_1_0.MetricType           = metricType;
        params.CustomMetricParams_1_0.LowWatermark         = loWatermark;
        params.CustomMetricParams_1_0.HighWatermark        = hiWatermark;
        params.CustomMetricParams_1_0.HwUnitType           = hwType;
        params.CustomMetricParams_1_0.IoReadEquation       = ioReadEquation;
        params.CustomMetricParams_1_0.QueryReadEquation    = queryReadEquation;
        params.CustomMetricParams_1_0.DeltaFunction        = deltaFunction;
        params.CustomMetricParams_1_0.NormEquation         = normalizationEquation;
        params.CustomMetricParams_1_0.MaxValueEquation     = maxValueEquation;
        params.CustomMetricParams_1_0.SignalName           = signalName;
        params.CustomMetricParams_1_0.AvailabilityEquation = nullptr;

        return AddCustomMetric( &params );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiSpecificId
    //
    // Description:
    //     Sets the API specific ids in the metric set params.
    //
    // Input:
    //     const char * dx9        -
    //     uint32_t     dx10       -
    //     uint32_t     ogl        -
    //     uint32_t     ocl        -
    //     uint32_t     hwConfig   -
    //
    // Output:
    //     TCompletionCode         - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiSpecificId( const char* dx9Fourcc, uint32_t dx9QueryId, uint32_t dx10Counter, uint32_t oglQuery, uint32_t ocl, uint32_t hwConfig, const char* dx10CounterName, uint32_t dx10QueryId, const char* oglQueryName, uint32_t oglQueryARB )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        m_params.ApiSpecificId.D3D9QueryId           = dx9QueryId;
        m_params.ApiSpecificId.D3D9Fourcc            = dx9Fourcc ? ( dx9Fourcc[0] ) + ( dx9Fourcc[1] << 8 ) + ( dx9Fourcc[2] << 16 ) + ( dx9Fourcc[3] << 24 ) : 0;
        m_params.ApiSpecificId.D3D1XQueryId          = dx10QueryId;
        m_params.ApiSpecificId.D3D1XDevDependentId   = dx10Counter;
        m_params.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( dx10CounterName, adapterId );
        m_params.ApiSpecificId.OGLQueryIntelId       = oglQuery;
        m_params.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( oglQueryName, adapterId );
        m_params.ApiSpecificId.OGLQueryARBTargetId   = oglQueryARB;
        m_params.ApiSpecificId.OCL                   = ocl;
        m_params.ApiSpecificId.HwConfigId            = hwConfig;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiSpecificId
    //
    // Description:
    //     Sets the API specific ids in the metric set params.
    //
    // Input:
    //     TApiSpecificId_1_0 apiSepcificId    - API specific id struct to set
    //
    // Output:
    //     TCompletionCode                     - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiSpecificId( TApiSpecificId_1_0 apiSpecificId )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        m_params.ApiSpecificId                       = apiSpecificId;
        m_params.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( apiSpecificId.D3D1XDevDependentName, adapterId );
        m_params.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( apiSpecificId.OGLQueryIntelName, adapterId );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens metric set for adding metric prototypes.
    //
    // Output:
    //     TCompletionCode - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Open()
    {
        if( !m_isFlexible )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        if( m_isOpened )
        {
            MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_WARNING, "Metric set is already opened" );
            return CC_OK;
        }

        // Clear vectors.
        ClearVector( m_metricsVector );
        ClearVector( m_informationVector );
        ClearVector( m_complementarySetsVector );
        ClearList( m_startRegisterSetList );
        ClearVector( m_otherMetricsVector );
        ClearVector( m_otherInformationVector );

        // Disable api filtering.
        EnableApiFiltering( 0, false );

        // Clear references in vectors.
        m_startRegsVector.clear();
        m_startRegsQueryVector.clear();

        m_params.MetricsCount    = 0;
        m_filteredParams.ApiMask = static_cast<uint32_t>( API_TYPE_ALL );

        m_isOpened = true;

        // Open should not clear previously added metric prototypes.

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddMetric
    //
    // Description:
    //     Adds a metric to the metric set using a metric prototype.
    //
    // Input:
    //     IMetricPrototype_1_13* metricPrototype - metric prototype to be added to the metric set.
    //
    // Output:
    //     TCompletionCode - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddMetric( IMetricPrototype_1_13* metricPrototype )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, m_prototypeManager, CC_ERROR_NOT_SUPPORTED );
        MD_CHECK_PTR_RET_A( adapterId, metricPrototype, CC_ERROR_INVALID_PARAMETER );

        if( !m_isOpened || m_params.MetricsCount > 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Cannot add metrics after finalizing metric set" );
            return CC_ERROR_GENERAL;
        }

        auto& metricPrototypeInternal = static_cast<CMetricPrototype&>( *metricPrototype );

        // Check if metric prototype is from the same concurrent group.
        if( auto& prototypeConcurrentGroup = metricPrototypeInternal.GetMetricEnumerator().GetConcurrentGroup();
            m_concurrentGroup != &prototypeConcurrentGroup )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "Metric prototype is not from the same concurrent group! MetricSet CG is: %s and MetricPrototype CG is: %s ", m_concurrentGroup->GetParams()->SymbolName, prototypeConcurrentGroup.GetParams()->SymbolName );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return m_prototypeManager->AddPrototype( metricPrototypeInternal );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     RemoveMetric
    //
    // Description:
    //     Removes a given metric from the metric set.
    //
    // Input:
    //     IMetricPrototype_1_13* metricPrototype - metric prototype to be removed
    //                                              from the metric set.
    //
    // Output:
    //     TCompletionCode - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::RemoveMetric( IMetricPrototype_1_13* metricPrototype )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, m_prototypeManager, CC_ERROR_NOT_SUPPORTED );
        MD_CHECK_PTR_RET_A( adapterId, metricPrototype, CC_ERROR_INVALID_PARAMETER );

        if( !m_isOpened || m_params.MetricsCount > 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Cannot remove metrics after finalizing metric set" );
            return CC_ERROR_GENERAL;
        }

        auto& metricPrototypeInternal = static_cast<CMetricPrototype&>( *metricPrototype );

        return m_prototypeManager->RemovePrototype( metricPrototypeInternal );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Finalize
    //
    // Description:
    //     Finalizes metric set to make it usable for metrics enumeration, activation etc.
    //
    // Output:
    //     TCompletionCode - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Finalize()
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( !m_prototypeManager || !m_prototypeManager->IsSupported() )
        {
            m_isOpened = false;
            return CC_ERROR_NOT_SUPPORTED;
        }

        if( m_prototypeManager->IsEmpty() )
        {
            m_isOpened = false;
            return CC_ERROR_GENERAL;
        }

        MD_CHECK_CC( AddDefaultMetrics() );

        // Begin configuration.
        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );

        // Process prototypes and create metrics with equations.
        MD_CHECK_CC( m_prototypeManager->CreateMetricsFromPrototypes() );

        // End configuration.
        MD_CHECK_CC( RefreshConfigRegisters() );

        m_isOpened = false;

        return CC_OK;

    exception:
        // Clear vectors.
        ClearVector( m_metricsVector );
        ClearVector( m_informationVector );
        ClearVector( m_complementarySetsVector );
        ClearList( m_startRegisterSetList );
        ClearVector( m_otherMetricsVector );
        ClearVector( m_otherInformationVector );

        // Disable api filtering.
        EnableApiFiltering( 0, false );

        // Clear references in vectors.
        m_startRegsVector.clear();
        m_startRegsQueryVector.clear();

        m_params.MetricsCount    = 0;
        m_filteredParams.ApiMask = static_cast<uint32_t>( API_TYPE_ALL );

        m_isOpened = false;

        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddCustomMetric
    //
    // Description:
    //     Adds custom metric with given parameters.
    //
    // Input:
    //     const char * symbolName                  -
    //     const char * shortName                   -
    //     const char * groupName                   -
    //     const char * longName                    -
    //     const char * dxToOglAlias                -
    //     uint32_t     usageFlagsMask              -
    //     uint32_t     apiMask                     -
    //     TMetricResultType resultType             -
    //     const char * resultUnits                 -
    //     TMetricType metricType                   -
    //     int64_t *   loWatermark                  -
    //     int64_t *   hiWatermark                  -
    //     THwUnitType hwType                       -
    //     const char * ioReadEquation              -
    //     const char * deltaFunction               -
    //     const char * queryReadEquation           -
    //     const char * normalizationEquation       -
    //     const char * maxValueEquation            -
    //     const char * signalName                  -
    //     uint32_t     queryModeMask               -
    //
    // Output:
    //     IMetricLatest* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CMetricSet::AddCustomMetric( const char* symbolName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName, uint32_t queryModeMask )
    {
        TAddCustomMetricParams params                      = {};
        params.Type                                        = METRIC_CUSTOM_PARAMS_1_1;
        params.CustomMetricParams_1_1.SymbolName           = symbolName;
        params.CustomMetricParams_1_1.ShortName            = shortName;
        params.CustomMetricParams_1_1.GroupName            = groupName;
        params.CustomMetricParams_1_1.LongName             = longName;
        params.CustomMetricParams_1_1.DxToOglAlias         = dxToOglAlias;
        params.CustomMetricParams_1_1.UsageFlagsMask       = usageFlagsMask;
        params.CustomMetricParams_1_1.ApiMask              = apiMask;
        params.CustomMetricParams_1_1.ResultType           = resultType;
        params.CustomMetricParams_1_1.MetricResultUnits    = resultUnits;
        params.CustomMetricParams_1_1.MetricType           = metricType;
        params.CustomMetricParams_1_1.LowWatermark         = loWatermark;
        params.CustomMetricParams_1_1.HighWatermark        = hiWatermark;
        params.CustomMetricParams_1_1.HwUnitType           = hwType;
        params.CustomMetricParams_1_1.IoReadEquation       = ioReadEquation;
        params.CustomMetricParams_1_1.QueryReadEquation    = queryReadEquation;
        params.CustomMetricParams_1_1.DeltaFunction        = deltaFunction;
        params.CustomMetricParams_1_1.NormEquation         = normalizationEquation;
        params.CustomMetricParams_1_1.MaxValueEquation     = maxValueEquation;
        params.CustomMetricParams_1_1.SignalName           = signalName;
        params.CustomMetricParams_1_1.AvailabilityEquation = nullptr;
        params.CustomMetricParams_1_1.QueryModeMask        = queryModeMask;

        return AddCustomMetric( &params );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddMetric
    //
    // Description:
    //     Adds a new metric to the metric set. Null if failed.
    //
    // Input:
    //     const char * symbolName             -
    //     const char * shortName              -
    //     const char * longName               -
    //     const char * groupName              -
    //     uint32_t     groupId                -
    //     uint32_t     usageFlagsMask         -
    //     uint32_t     apiMask                -
    //     TMetricType  metricType             -
    //     TMetricResultType resultType        -
    //     const char * units                  -
    //     const char * maxValue               -
    //     int64_t loWatermark                 -
    //     int64_t hiWatermark                 -
    //     THwUnitType hwType                  -
    //     const char * availabilityEquation   -
    //     const char* alias                   -
    //     const char* signalName              -
    //     uint32_t metricXmlId                -
    //     bool isCustom                       -
    //
    // Output:
    //     CMetric*  - pointer to the newly created metric.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric* CMetricSet::AddMetric( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* availabilityEquation, const char* alias, const char* signalName, uint32_t metricXmlId, bool isCustom /*= false*/ )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( groupName == nullptr )
        {
            groupName = "";
        }

        CMetric* metric = new( std::nothrow ) CMetric( m_device, metricXmlId, symbolName, shortName, longName, groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, units, loWatermark, hiWatermark, hwType, alias, signalName, isCustom );
        MD_CHECK_PTR_RET_A( adapterId, metric, nullptr );

        if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( metric );
            return nullptr;
        }

        if( metric->IsAvailabilityEquationTrue() )
        {
            if( IsMetricAlreadyAdded( symbolName ) )
            {
                m_otherMetricsVector.push_back( metric );
            }
            else
            {
                uint32_t count = static_cast<uint32_t>( m_metricsVector.size() );
                metric->SetIdInSetParam( count );
                m_metricsVector.push_back( metric );
                m_params.MetricsCount = count + 1;
            }
        }
        else
        {
            m_otherMetricsVector.push_back( metric );
        }

        if( isCustom )
        {
            m_isCustom = true;
        }

        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddMetric
    //
    // Description:
    //     Adds a new metric to the metric set. nullptr if failed.
    //
    // Input:
    //     CMetric* metric - metric to add
    //
    // Output:
    //     CMetric*        - added metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric* CMetricSet::AddMetric( CMetric* metric )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, metric, nullptr );

        if( IsMetricAlreadyAdded( metric->GetParams()->SymbolName ) )
        {
            m_otherMetricsVector.push_back( metric );
        }
        else
        {
            m_metricsVector.push_back( metric );
            m_params.MetricsCount = static_cast<uint32_t>( m_metricsVector.size() );
        }

        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. Null if failed.
    //
    // Input:
    //     const char * symbolicName           -
    //     const char * shortName              -
    //     const char * longName               -
    //     const char * groupName              -
    //     uint32_t     apiMask                -
    //     TInformationType informationType    -
    //     const char*  availabilityEquation   -
    //     uint32_t informationXmlId           -
    //
    // Output:
    //     CInformation*   - pointer to the newly created information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CMetricSet::AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        CInformation* information = new( std::nothrow ) CInformation( m_device, informationXmlId, symbolName, shortName, longName, groupName, apiMask, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, information, nullptr );

        if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( information );
            return nullptr;
        }

        if( information->IsAvailabilityEquationTrue() )
        {
            information->SetIdInSetParam( static_cast<uint32_t>( m_informationVector.size() ) );
            m_informationVector.push_back( information );
            m_params.InformationCount = static_cast<uint32_t>( m_informationVector.size() ) + m_concurrentGroup->GetInformationCount();
        }
        else
        {
            m_otherInformationVector.push_back( information );
        }

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. nullptr if failed.
    //
    // Input:
    //     CInformation* information  - information to add
    //
    // Output:
    //     CInformation*              - pointer to the added information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CMetricSet::AddInformation( CInformation* information )
    {
        MD_CHECK_PTR_RET_A( m_device.GetAdapter().GetAdapterId(), information, nullptr );

        m_informationVector.push_back( information );
        m_params.InformationCount = static_cast<uint32_t>( m_informationVector.size() ) + m_concurrentGroup->GetInformationCount();

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddComplementaryMetricSet
    //
    // Description:
    //     Adds a complementary metric set by name.
    //
    // Input:
    //     const char * complementaryMetricSetSymbolicName - complementary metric set name to add
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddComplementaryMetricSet( const char* complementaryMetricSetSymbolicName )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, complementaryMetricSetSymbolicName, CC_ERROR_INVALID_PARAMETER );

        if( strcmp( complementaryMetricSetSymbolicName, "" ) == 0 )
        {
            return CC_OK; // 0 is fine condition for "" name
        }

        char* metricSetName = GetCopiedCString( complementaryMetricSetSymbolicName, adapterId );

        m_complementarySetsVector.push_back( metricSetName );
        m_params.ComplementarySetsCount = static_cast<uint32_t>( m_complementarySetsVector.size() );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddComplementaryMetricSet
    //
    // Description:
    //     Adds multiple complementary metric sets by name.
    //
    // Input:
    //     const char* complementaryMetricSetsList - comma separated list of complementary sets (symbol names)
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddComplementaryMetricSets( const char* complementarySetsList )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, complementarySetsList, CC_ERROR_INVALID_PARAMETER );

        char *token = nullptr, *tokenNext = nullptr, *complementarySets = nullptr;

        complementarySets = GetCopiedCString( complementarySetsList, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, complementarySets, CC_ERROR_NO_MEMORY );

        token = iu_strtok_s( complementarySets, ",", &tokenNext );
        while( token != nullptr )
        {
            if( AddComplementaryMetricSet( token ) != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "error adding complementary metric sets" );
                MD_SAFE_DELETE_ARRAY( complementarySets );
                return CC_ERROR_GENERAL;
            }
            token = iu_strtok_s( nullptr, ",", &tokenNext );
        }
        MD_SAFE_DELETE_ARRAY( complementarySets );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ActivateInternal
    //
    // Description:
    //     To enable this configuration before query instance is created or IO stream is opened.
    //     Locks the concurrent group and sends the configuration if flag was set and the lock was successful.
    //
    // Input:
    //     bool sendConfigFlag      - if true, StartConfigRegs are sent
    //     bool sendQueryConfigFlag - if true, query specific regs are sent too
    //
    // Output:
    //     TCompletionCode           - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::ActivateInternal( bool sendConfigFlag, bool sendQueryConfigFlag )
    {
        TCompletionCode retVal    = CC_OK;
        const uint32_t  adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );

        retVal = m_concurrentGroup->Lock();
        if( retVal == CC_OK && sendConfigFlag )
        {
            if( SendStartConfiguration( sendQueryConfigFlag ) != CC_OK )
            {
                m_concurrentGroup->Unlock();
                MD_LOG_A( adapterId, LOG_DEBUG, "sending start configuration failed" );
                retVal = CC_ERROR_GENERAL;
            }
        }

        MD_LOG_EXIT_A( adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddStartConfigRegisterSet
    //
    // Description:
    //     Adds a new empty start config register set to the metric set.
    //
    // Input:
    //     uint32_t     configId             - config id
    //     uint32_t     configPriority       - priority, lower is more important
    //     const char*  availabilityEquation - availability equation (default nullptr - available)
    //     TConfigType  configType           - e.g. COMMON, SNAPSHOT (default COMMON)
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddStartRegisterSet( uint32_t configId, uint32_t configPriority, const char* availabilityEquation /*= nullptr */, TConfigType configType /*= CONFIG_TYPE_COMMON*/ )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        CRegisterSet* registerSet = new( std::nothrow ) CRegisterSet( m_device, configId, configPriority, configType );
        MD_CHECK_PTR_RET_A( adapterId, registerSet, CC_ERROR_NO_MEMORY );

        if( registerSet->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_INFO, "Failed to add start config register set to the metric set" );
            MD_SAFE_DELETE( registerSet );
            return CC_ERROR_GENERAL;
        }
        m_startRegisterSetList.push_back( registerSet );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddStartConfigRegister
    //
    // Description:
    //     Adds configuration register to the metric set to send it during Activate method.
    //     It only adds registers to a register set. RefreshConfigRegisters() adds them to
    //     a real configuration which will be sent.
    //
    // Input:
    //     uint32_t      offset - register offset
    //     uint32_t      value  - register value
    //     TRegisterType type   - register type
    //
    // Output:
    //     TCompletionCode      - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddStartConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        CRegisterSet* registerSet = m_startRegisterSetList.size() > 0 ? m_startRegisterSetList.back() : nullptr;
        MD_CHECK_PTR_RET_A( adapterId, registerSet, CC_ERROR_GENERAL );

        TRegister* reg = registerSet->AddConfigRegister( offset, value, type );
        MD_CHECK_PTR_RET_A( adapterId, reg, CC_ERROR_GENERAL );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     RefreshConfigRegisters
    //
    // Description:
    //     Chooses start registers with the highest priorities and adds them to a configuration.
    //     Only one set with a given ID can be used in the configuration.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::RefreshConfigRegisters()
    {
        uint32_t      id          = 0;
        CRegisterSet* registerSet = nullptr;

        while( GetStartRegSetHiPriority( id++, &registerSet ) )
        {
            if( registerSet )
            {
                // Add registers
                TRegisterSetParams* params = registerSet->GetParams();

                switch( params->ConfigType )
                {
                    case CONFIG_TYPE_COMMON:
                        registerSet->RegsToVector( m_startRegsVector );
                        break;

                    case CONFIG_TYPE_QUERY:
                        registerSet->RegsToVector( m_startRegsQueryVector );
                        break;

                    default:
                        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_ERROR, "Unknown register method" );
                        return CC_ERROR_GENERAL;
                }
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetRegSetLoIdHiPriority
    //
    // Description:
    //     Iterates through all the start register sets looking for a set with the highest
    //     priority and a given ID. If there's no such registerSet is nullptr. If there's no
    //     sets with the given ID or higher it returns false.
    //
    // Input:
    //     uint32_t       id          - config id to look for
    //     CRegisterSet** registerSet - (out) found register set, nullptr if not found
    //
    // Output:
    //     bool - false if there is no register sets with given id or higher (end of search)
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::GetStartRegSetHiPriority( uint32_t id, CRegisterSet** registerSet )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, registerSet, false );

        bool          ret             = false;
        CRegisterSet* set             = nullptr;
        uint32_t      highestPriority = 0xFFFFFFFF; // Lower is more important

        for( auto& startRegisterSet : m_startRegisterSetList )
        {
            TRegisterSetParams* params = startRegisterSet->GetParams();
            if( params->ConfigId >= id )
            {
                ret = true;
                if( params->ConfigId == id && startRegisterSet->IsAvailable() && params->ConfigPriority < highestPriority )
                {
                    highestPriority = params->ConfigPriority;
                    set             = startRegisterSet;
                }
            }
        }
        *registerSet = set;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetStartConfiguration
    //
    // Description:
    //     Returns common start config registers (without query specific).
    //
    // Input:
    //     uint32_t&     count - (out) registers count
    //
    // Output:
    //     TRegister**         - pointers to the common start config registers
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegister** CMetricSet::GetStartConfiguration( uint32_t& count )
    {
        count = static_cast<uint32_t>( m_startRegsVector.size() );
        return m_startRegsVector.data();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SendStartConfiguration
    //
    // Description:
    //     Sends a start configuration to the driver.
    //
    // Input:
    //     bool sendQueryConfigFlag - if true, send also query specific configuration
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SendStartConfiguration( bool sendQueryConfigFlag )
    {
        auto&           driverInterface   = m_device.GetDriverInterface();
        auto&           oaConcurrentGroup = static_cast<COAConcurrentGroup&>( *m_concurrentGroup );
        const uint32_t  adapterId         = m_device.GetAdapter().GetAdapterId();
        TCompletionCode ret               = CC_OK;

        if( CheckSendConfigRequired( sendQueryConfigFlag ) )
        {
            // Prepare register reference lists to sent
            std::vector<TRegister*> pmRegs;
            std::vector<TRegister*> readRegs;
            pmRegs.reserve( m_startRegsVector.size() );

            AppendToConfiguration( m_startRegsVector, pmRegs, readRegs );
            if( sendQueryConfigFlag )
            {
                AppendToConfiguration( m_startRegsQueryVector, pmRegs, readRegs );
            }

            // Verify if programming is present
            // "m_startRegisterSetList may be empty for e.g. PipelineStatistics"
            if( ( pmRegs.size() > 0 || readRegs.size() > 0 ) || m_startRegisterSetList.size() == 0 )
            {
                if( sendQueryConfigFlag && ( m_currentParams->ApiMask & API_TYPE_IOSTREAM ) )
                {
                    // Api mask cannot include iostream if query config is being sent
                    MD_LOG_A( adapterId, LOG_DEBUG, "SetApiFiltering wasn't used" );
                }

                // Send configurations
                ret = driverInterface.SendPmRegsConfig( pmRegs.data(), static_cast<uint32_t>( pmRegs.size() ), m_device.GetSubDeviceIndex(), oaConcurrentGroup.GetOaBufferType() );
                if( ret == CC_OK && readRegs.size() )
                {
                    ret = driverInterface.SendReadRegsConfig( readRegs.data(), static_cast<uint32_t>( readRegs.size() ) );
                }

                if( ret == CC_OK )
                {
                    m_isReadRegsCfgSet = readRegs.size() > 0;

                    m_pmRegsConfigInfo.IsQueryConfig = sendQueryConfigFlag;
                    driverInterface.GetPmRegsConfigHandles( &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
                }
            }
            else
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Programming missing" );
                ret = CC_ERROR_NOT_SUPPORTED;
            }

            // Do not clear local register vectors to preserve original references
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AppendToConfiguration
    //
    // Description:
    //     Appends register from the source vector to the two destination (PmRegs and ReadRegs)
    //     vectors. It's because read and pm regs are sent using different way.
    //
    // Input:
    //     Vector<TRegister*>& sourceRegs  - source vector for all regs
    //     Vector<TRegister*>& outPmRegs   - dest vector for PmRegs
    //     Vector<TRegister*>& outReadRegs - dest vector for ReadRegs
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::AppendToConfiguration( std::vector<TRegister*>& sourceRegs, std::vector<TRegister*>& outPmRegs, std::vector<TRegister*>& outReadRegs )
    {
        for( auto& sourceRegister : sourceRegs )
        {
            if( sourceRegister->type == REGISTER_TYPE_MMIO )
            {
                outReadRegs.push_back( sourceRegister );
            }
            else
            {
                outPmRegs.push_back( sourceRegister );
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CheckSendConfigRequired
    //
    // Description:
    //     Checks whether the configuration in KMD needs to be updated to be used with
    //     the current metric set.
    //
    // Output:
    //     bool - false if sending is unnecessary
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::CheckSendConfigRequired( bool sendQueryConfigFlag )
    {
        const uint32_t adapterId       = m_device.GetAdapter().GetAdapterId();
        auto&          driverInterface = m_device.GetDriverInterface();
        bool           ret             = true;

        // If measurement type didn't change and config handles were checked before
        if( m_pmRegsConfigInfo.IsQueryConfig == sendQueryConfigFlag && ( m_pmRegsConfigInfo.OaConfigHandle != 0 || m_pmRegsConfigInfo.RrConfigHandle != 0 ) )
        {
            uint32_t        oaCfgHandle = 0;
            uint32_t        rrCfgHandle = 0;
            TCompletionCode retCode     = CC_OK;

            retCode = driverInterface.GetPmRegsConfigHandles( &oaCfgHandle, &rrCfgHandle );

            if( retCode == CC_OK && oaCfgHandle == m_pmRegsConfigInfo.OaConfigHandle && rrCfgHandle == m_pmRegsConfigInfo.RrConfigHandle )
            {
                ret = false;
                MD_LOG_A( adapterId, LOG_DEBUG, "No need to send PmRegs configuration" );
            }
        }

        if( ret )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Sending PmRegs configuration required" );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetReportType
    //
    // Description:
    //     Returns metric's report type for IO Stream.
    //
    // Output:
    //     TReportType - metric's report type
    //
    //////////////////////////////////////////////////////////////////////////////
    TReportType CMetricSet::GetReportType()
    {
        return m_reportType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     WriteCMetricSetToBuffer
    //
    // Description:
    //     Writes metric set to buffer.
    //
    // Input:
    //     uint8_t*  buffer                   - pointer to a buffer
    //     uint32_t& bufferSize               - size of the buffer
    //     uint32_t& bufferOffset             - the current offset of the buffer
    //     bool      copyInformationFromGroup - true if information should be copied from the group
    //
    // Output:
    //     TCompletionCode                    - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::WriteCMetricSetToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, bool copyInformationFromGroup )
    {
        const uint32_t  adapterId = m_device.GetAdapter().GetAdapterId();
        TCompletionCode result    = CC_OK;

        // m_params
        result = WriteCStringToBuffer( m_params.SymbolName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.ShortName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiMask, sizeof( m_params.ApiMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.CategoryMask, sizeof( m_params.CategoryMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.RawReportSize, sizeof( m_params.RawReportSize ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.QueryReportSize, sizeof( m_params.QueryReportSize ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.PlatformMask, sizeof( m_params.PlatformMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.GtMask, sizeof( m_params.GtMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteEquationToBuffer( m_availabilityEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_reportType, sizeof( m_reportType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteByteArrayToBuffer( m_platformMask, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_params.ApiSpecificId (placeholder is not saved!)
        result = WriteDataToBuffer( &m_params.ApiSpecificId.D3D9QueryId, sizeof( m_params.ApiSpecificId.D3D9QueryId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.D3D9Fourcc, sizeof( m_params.ApiSpecificId.D3D9Fourcc ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.D3D1XQueryId, sizeof( m_params.ApiSpecificId.D3D1XQueryId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.D3D1XDevDependentId, sizeof( m_params.ApiSpecificId.D3D1XDevDependentId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.ApiSpecificId.D3D1XDevDependentName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.OGLQueryIntelId, sizeof( m_params.ApiSpecificId.OGLQueryIntelId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.ApiSpecificId.OGLQueryIntelName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.OGLQueryARBTargetId, sizeof( m_params.ApiSpecificId.OGLQueryARBTargetId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.OCL, sizeof( m_params.ApiSpecificId.OCL ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiSpecificId.HwConfigId, sizeof( m_params.ApiSpecificId.HwConfigId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_metricsVector & m_otherMetricsVector
        uint32_t count = static_cast<uint32_t>( m_metricsVector.size() + m_otherMetricsVector.size() );

        result = WriteDataToBuffer( (void*) &count, sizeof( count ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        uint32_t i = 0;
        uint32_t j = 0;
        while( i < m_metricsVector.size() || j < m_otherMetricsVector.size() )
        {
            // Define which vector is not finished and write remaining available metrics
            if( i == m_metricsVector.size() )
            {
                for( uint32_t k = j; k < m_otherMetricsVector.size(); ++k )
                {
                    result = m_otherMetricsVector[k]->WriteCMetricToBuffer( buffer, bufferSize, bufferOffset );
                    MD_CHECK_CC_RET_A( adapterId, result );
                }
                break;
            }
            if( j == m_otherMetricsVector.size() )
            {
                for( uint32_t k = i; k < m_metricsVector.size(); ++k )
                {
                    result = m_metricsVector[k]->WriteCMetricToBuffer( buffer, bufferSize, bufferOffset );
                    MD_CHECK_CC_RET_A( adapterId, result );
                }
                break;
            }

            // Write in the correct order
            if( m_metricsVector[i]->GetId() < m_otherMetricsVector[j]->GetId() )
            {
                result = m_metricsVector[i++]->WriteCMetricToBuffer( buffer, bufferSize, bufferOffset );
                MD_CHECK_CC_RET_A( adapterId, result );
            }
            else
            {
                result = m_otherMetricsVector[j++]->WriteCMetricToBuffer( buffer, bufferSize, bufferOffset );
                MD_CHECK_CC_RET_A( adapterId, result );
            }
        }

        // m_informationVector & m_otherInformationVector
        if( m_concurrentGroup && copyInformationFromGroup )
        {
            count = static_cast<uint32_t>( m_concurrentGroup->GetInformationCount() + m_informationVector.size() + m_otherInformationVector.size() );
        }
        else
        {
            count = static_cast<uint32_t>( m_informationVector.size() + m_otherInformationVector.size() );
        }

        result = WriteDataToBuffer( &count, sizeof( count ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // Write informations from concurrent group
        if( m_concurrentGroup && copyInformationFromGroup )
        {
            for( i = 0; i < m_concurrentGroup->GetInformationCount(); ++i )
            {
                CInformation* information = static_cast<CInformation*>( m_concurrentGroup->GetInformation( i ) );

                result = information
                    ? information->WriteCInformationToBuffer( buffer, bufferSize, bufferOffset )
                    : CC_ERROR_GENERAL;
                MD_CHECK_CC_RET_A( adapterId, result );
            }
        }

        i = 0;
        j = 0;
        while( i < m_informationVector.size() || j < m_otherInformationVector.size() )
        {
            // Define which vector is not finished and write remaining available informations
            if( i == m_informationVector.size() )
            {
                for( uint32_t k = j; k < m_otherInformationVector.size(); ++k )
                {
                    result = m_otherInformationVector[k]->WriteCInformationToBuffer( buffer, bufferSize, bufferOffset );
                    MD_CHECK_CC_RET_A( adapterId, result );
                }
                break;
            }
            if( j == m_otherInformationVector.size() )
            {
                for( uint32_t k = i; k < m_informationVector.size(); ++k )
                {
                    result = m_informationVector[k]->WriteCInformationToBuffer( buffer, bufferSize, bufferOffset );
                    MD_CHECK_CC_RET_A( adapterId, result );
                }
                break;
            }

            // Write in the correct order
            if( m_informationVector[i]->GetId() < m_otherInformationVector[j]->GetId() )
            {
                result = m_informationVector[i++]->WriteCInformationToBuffer( buffer, bufferSize, bufferOffset );
                MD_CHECK_CC_RET_A( adapterId, result );
            }
            else
            {
                result = m_otherInformationVector[j++]->WriteCInformationToBuffer( buffer, bufferSize, bufferOffset );
                MD_CHECK_CC_RET_A( adapterId, result );
            }
        }

        // m_startRegisterSetList
        count = static_cast<uint32_t>( m_startRegisterSetList.size() );

        result = WriteDataToBuffer( &count, sizeof( count ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        for( auto& registerSet : m_startRegisterSetList )
        {
            result = registerSet->WriteCRegisterSetToBuffer( buffer, bufferSize, bufferOffset );
            MD_CHECK_CC_RET_A( adapterId, result );
        }

        // m_stopRegisterSetList - remains to be backward compatible, count is always 0
        count = 0;

        result = WriteDataToBuffer( &count, sizeof( count ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_complementarySetsVector
        count = static_cast<uint32_t>( m_complementarySetsVector.size() );

        result = WriteDataToBuffer( &count, sizeof( count ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        for( i = 0; i < count; ++i )
        {
            result = WriteCStringToBuffer( m_complementarySetsVector[i], buffer, bufferSize, bufferOffset, adapterId );
            MD_CHECK_CC_RET_A( adapterId, result );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InheritFromMetricSet
    //
    // Description:
    //     Inherits metrics with signal name containing specified string and all the information from
    //     the reference metric set. When signalName is nullptr copy all the metrics.
    //
    // Input:
    //     CMetricSet* referenceMetricSet   - metric set to be copied
    //     const char* signalName           - signal name
    //     bool        copyInformationOnly  - Inherit only informations
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::InheritFromMetricSet( CMetricSet* referenceMetricSet, const char* signalName, bool copyInformationOnly )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, referenceMetricSet, CC_ERROR_INVALID_PARAMETER );

        CMetric*      metric               = nullptr;
        CMetric*      referenceMetric      = nullptr;
        CInformation* information          = nullptr;
        CInformation* referenceInformation = nullptr;
        const char*   metricSignalName     = nullptr;
        uint32_t      count                = 0;

        // Copy metrics with signal name containing signalName
        if( !copyInformationOnly )
        {
            count = referenceMetricSet->GetParams()->MetricsCount;
            for( uint32_t i = 0; i < count; i++ )
            {
                referenceMetric = referenceMetricSet->GetMetricExplicit( i );
                if( referenceMetric == nullptr )
                {
                    MD_ASSERT_A( m_device.GetAdapter().GetAdapterId(), false );
                    return CC_ERROR_GENERAL;
                }
                metricSignalName = referenceMetric->GetSignalName();
                if( signalName == nullptr || ( metricSignalName != nullptr && strstr( metricSignalName, signalName ) != nullptr ) )
                {
                    metric = new( std::nothrow ) CMetric( *referenceMetric );
                    if( !metric )
                    {
                        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_DEBUG, "error copying metrics" );
                        return CC_ERROR_GENERAL;
                    }
                    AddMetric( metric );
                }
            }
        }

        // Copy information from metric set. Not from concurrent group
        count = referenceMetricSet->GetParams()->InformationCount;
        for( uint32_t i = m_concurrentGroup->GetInformationCount(); i < count; i++ )
        {
            referenceInformation = static_cast<CInformation*>( referenceMetricSet->GetInformation( i ) );
            if( referenceInformation == nullptr )
            {
                MD_ASSERT_A( m_device.GetAdapter().GetAdapterId(), false );
                return CC_ERROR_GENERAL;
            }
            information = new( std::nothrow ) CInformation( *referenceInformation );
            if( !information )
            {
                MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_DEBUG, "error copying information" );
                return CC_ERROR_GENERAL;
            }
            AddInformation( information );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsMetricAlreadyAdded
    //
    // Description:
    //     Checks if metric of the given name is already added to the metrics set.
    //
    // Input:
    //     const char * symbolicName   - symbolic name of a metric to check
    //
    // Output:
    //     bool                        - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsMetricAlreadyAdded( const char* symbolName )
    {
        MD_CHECK_PTR_RET_A( m_device.GetAdapter().GetAdapterId(), symbolName, false );

        for( auto& metric : m_metricsVector )
        {
            if( metric && ( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 ) )
            {
                return true;
            }
        }

        for( auto& metric : m_otherMetricsVector )
        {
            if( metric && ( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 ) )
            {
                return true;
            }
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsCustom
    //
    // Description:
    //     True if this is a custom Metric Set or default with custom metrics added.
    //
    // Output:
    //     bool - true if custom
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsCustom()
    {
        return m_isCustom;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsFiltered
    //
    // Description:
    //     True if filtered variables are used.
    //
    // Output:
    //     bool - true if filtered
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsFiltered()
    {
        return m_isFiltered;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetConcurrentGroup
    //
    // Description:
    //     Returns concurrent group related to the metric set.
    //
    // Output:
    //     CConcurrentGroup* - concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup* CMetricSet::GetConcurrentGroup()
    {
        return m_concurrentGroup;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiFiltering
    //
    // Description:
    //     Sets filtering by the given API mask. After enabling the set will contain only
    //     metrics and information available for the given API.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Output:
    //     TCompletionCode - *CC_OK* mease succcess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiFiltering( uint32_t apiMask )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );

        if( m_isOpened )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Cannot do filtering if metric set is opened" );
            return CC_ERROR_GENERAL;
        }

        if( !IsApiFilteringMaskValid( apiMask ) )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "error: invalid filtering API mask" );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( apiMask == 0 || apiMask == API_TYPE_ALL )
        {
            // Disable API filtering
            MD_LOG_A( adapterId, LOG_INFO, "disabling API filtering, apiMask: %u", apiMask );
            EnableApiFiltering( apiMask, false );
        }
        else
        {
            // Enable API filtering
            MD_LOG_A( adapterId, LOG_INFO, "enabling API filtering, apiMask: %u", apiMask );
            EnableApiFiltering( apiMask, true );
        }

        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsApiFilteringMaskValid
    //
    // Description:
    //     Validates API mask used in SetApiFiltering method.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Input:
    //    const uint32_t apiMask - api mask
    //
    // Output:
    //     bool                  - true if valid, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsApiFilteringMaskValid( const uint32_t apiMask )
    {
        if( apiMask != 0 && apiMask != API_TYPE_ALL )
        {
            const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
            const bool     isStream  = ( apiMask & API_TYPE_IOSTREAM );
            const bool     isQuery   = ( apiMask & MD_QUERY_API_MASK );

            if( !isStream && !isQuery )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Wrong apiMask!, apiMask: %x", apiMask );
                return false;
            }

            // Do not allow mixing stream and query metrics
            if( isStream && isQuery )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: IoStream and Query api mask mixed, apiMask: %x", apiMask );
                return false;
            }
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricSet
    //
    // Method:
    //     EnableApiFiltering
    //
    // Description:
    //     Enables or disables API filtering for the current metric set.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Input:
    //     const uint32_t apiMask - API mask for filtering
    //     const bool     enable  - if true enable, if false disable
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::EnableApiFiltering( const uint32_t apiMask, const bool enable )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );

        if( !enable )
        {
            UseApiFilteredVariables( false );
        }
        else
        {
            // Used cached metrics if possible
            if( apiMask == m_filteredParams.ApiMask )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Using cached metrics for API filtering, apiMask: %x", apiMask );
            }
            else
            {
                // Copy (shallow) params, then modify apiMask
                iu_memcpy_s( &m_filteredParams, sizeof( m_filteredParams ), &m_params, sizeof( m_params ) );
                m_filteredParams.ApiMask = apiMask;

                // Cache and modify counts in params
                RefreshCachedMetricsAndInformation();
            }

            UseApiFilteredVariables( true );
        }

        UpdateMetricIndicesInEquations();

        MD_LOG_A( adapterId, LOG_DEBUG, "API filtering %s", m_isFiltered ? "enabled" : "disabled" );
        MD_LOG_EXIT_A( adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricSet
    //
    // Method:
    //     UpdateMetricIndicesInEquations
    //
    // Description:
    //     Sets internal indices values depending on whether the symbol name was found
    //     in a metric set.
    //     These are later used in calculating the normalization equation.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::UpdateMetricIndicesInEquations()
    {
        std::unordered_map<std::string, uint32_t> metricsIndexMap( m_params.MetricsCount );

        // Initialize metric indices map
        for( uint32_t i = 0; i < m_params.MetricsCount; ++i )
        {
            CMetric* metric = GetMetricExplicit( i );

            if( metric != nullptr )
            {
                const auto metricParams = metric->GetParams();

                metricsIndexMap[metricParams->SymbolName] = i;
            }
        }

        // Update metric indices
        for( uint32_t i = 0; i < m_params.MetricsCount; ++i )
        {
            CMetric* metric = GetMetricExplicit( i );

            if( metric != nullptr )
            {
                const auto metricParams = metric->GetParams();

                if( metricParams->NormEquation != nullptr )
                {
                    // Get an equation
                    IEquation_1_0* equation              = metricParams->NormEquation;
                    const uint32_t equationElementsCount = equation->GetEquationElementsCount();

                    // Metrics equation can use only preceding metrics' values
                    for( uint32_t j = 0; j < equationElementsCount; ++j )
                    {
                        const auto internalElement = static_cast<CEquationElementInternal*>( equation->GetEquationElement( j ) );

                        if( internalElement->Type == EQUATION_ELEM_LOCAL_COUNTER_SYMBOL || internalElement->Type == EQUATION_ELEM_LOCAL_METRIC_SYMBOL || internalElement->Type == EQUATION_ELEM_PREV_METRIC_SYMBOL )
                        {
                            // Find if symbol name is in the index map
                            const auto foundMetric = metricsIndexMap.find( internalElement->SymbolName );

                            // Check for the results
                            if( foundMetric != metricsIndexMap.end() )
                            {
                                internalElement->MetricIndexInternal = foundMetric->second;
                            }
                            else
                            {
                                internalElement->MetricIndexInternal = -1;
                            }
                        }
                    }
                }
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     UseApiFilteredVariables
    //
    // Description:
    //     Swaps currently used variables in such methods as GetParams, GetMetric etc. to
    //     filtered or non-filtered ones.
    //
    // Input:
    //     bool enable - if true change to filtered
    //                   if false change to non-filtered
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::UseApiFilteredVariables( bool enable )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( enable )
        {
            m_currentParams            = &m_filteredParams;
            m_currentMetricsVector     = &m_filteredMetricsVector;
            m_currentInformationVector = &m_filteredInformationVector;
            m_isFiltered               = true;

            MD_LOG_A( adapterId, LOG_DEBUG, "Before API filtering, MetricsCount: %u, InformationCount: %u", m_params.MetricsCount, m_params.InformationCount );
            MD_LOG_A( adapterId, LOG_DEBUG, "After API filtering, MetricsCount: %u, InformationCount: %u", m_filteredParams.MetricsCount, m_filteredParams.InformationCount );
        }
        else
        {
            m_currentParams            = &m_params;
            m_currentMetricsVector     = &m_metricsVector;
            m_currentInformationVector = &m_informationVector;
            m_isFiltered               = false;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "Use API filtered variables: %s", enable ? "TRUE" : "FALSE" );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CacheMetricsAndInformation
    //
    // Description:
    //     Clears cached metrics and information, then updates them using the whole
    //     MetricSet and API mask stored in filtered params.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::RefreshCachedMetricsAndInformation()
    {
        if( m_filteredParams.ApiMask == 0 )
        {
            // Filtering uninitialized, nothing to do
            return;
        }

        // Do not use API filtered variables - need to look through all metrics/information
        bool filteringEnabled = m_isFiltered;
        if( filteringEnabled )
        {
            UseApiFilteredVariables( false );
        }

        ClearCachedMetricsAndInformation();

        const auto queryMode = m_device.GetQueryMode();
        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_DEBUG, "queryMode: %u", queryMode );

        // Cache metrics
        for( uint32_t i = 0, j = 0; i < m_params.MetricsCount; ++i )
        {
            if( auto metric = GetMetricExplicit( i );
                metric != nullptr )
            {
                if( const auto params = metric->GetParams();
                    params != nullptr && ( params->ApiMask & m_filteredParams.ApiMask ) )
                {
                    if( ( m_filteredParams.ApiMask & MD_QUERY_API_MASK ) && !IsQueryModeMatch( queryMode, params->QueryModeMask ) )
                    {
                        continue;
                    }

                    metric->SetIdInSetParam( j++ );

                    m_filteredMetricsVector.push_back( metric );
                }
            }
        }

        // Cache information
        for( uint32_t i = 0, j = 0; i < m_params.InformationCount; ++i )
        {
            if( auto information = static_cast<CInformation*>( GetInformation( i ) ); information != nullptr )
            {
                if( const auto params = information->GetParams();
                    params != nullptr && ( ( params->ApiMask & m_filteredParams.ApiMask ) != 0 ) &&
                    ( !m_aggregationEnabled || information->IsAggregatable() ) )
                {
                    information->SetIdInSetParam( j++ );

                    m_filteredInformationVector.push_back( information );
                }
            }
        }

        // Modify counts
        m_filteredParams.MetricsCount     = static_cast<uint32_t>( m_filteredMetricsVector.size() );
        m_filteredParams.InformationCount = static_cast<uint32_t>( m_filteredInformationVector.size() );

        if( filteringEnabled )
        {
            UseApiFilteredVariables( true );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ClearCachedMetricsAndInformation
    //
    // Description:
    //     Clear cached metrics and information. Instances are set to nullptr because
    //     Clear() method deletes objects stored in the List. This's not desired.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::ClearCachedMetricsAndInformation()
    {
        // To prevent double memory freeing, original instances are in m_metrics/informationVector
        std::fill( m_filteredMetricsVector.begin(), m_filteredMetricsVector.end(), nullptr );
        std::fill( m_filteredInformationVector.begin(), m_filteredInformationVector.end(), nullptr );

        m_filteredMetricsVector.clear();
        m_filteredInformationVector.clear();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateMetrics
    //
    // Description:
    //     Conducts the whole process of metrics and information calculation for multiple reports.
    //     It's API agnostic - user doesn't have to worry about API he has used.
    //     User has to provide input buffer and its size, output buffer and its size with enough space for
    //     all calculated metrics and information.
    //     The amount of input reports is calculated based on rawData size and the size of single raw report.
    //
    // Input:
    //     const uint8_t*   rawData                - raw report data
    //     uint32_t         rawDataSize            - size of raw report data
    //     TTypedValue_1_0* out                    - (OUT) buffer for calculated reports
    //     uint32_t         outSize                - size of the provided output buffer
    //     uint32_t*        outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    //     bool             enableContextFiltering - if true enable context filtering during calculation
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering )
    {
        if( enableContextFiltering )
        {
            MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_ERROR, "error: context filtering not supported" );
            return CC_ERROR_NOT_SUPPORTED;
        }

        return CalculateMetrics( rawData, rawDataSize, out, outSize, outReportCount, nullptr, 0 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateMetrics
    //
    // Description:
    //     Conducts the whole process of metrics and information calculation for multiple reports.
    //     It's API agnostic - user doesn't have to worry about API he has used.
    //     User has to provide input buffer and its size, output buffer and its size with enough space for
    //     all calculated metrics and information.
    //     The amount of input reports is calculated based on rawData size and the size of single raw report.
    //
    //     Optional MaxValues calculation added, if MaxValueEquation isn't defined for the metric its current
    //     normalized value is used.
    //
    // Input:
    //     const uint8_t*   rawData                - raw report data
    //     uint32_t         rawDataSize            - size of raw report data in bytes
    //     TTypedValue_1_0* out                    - (OUT) buffer for calculated reports
    //     uint32_t         outSize                - size of the provided output buffer in bytes
    //     uint32_t*        outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    //     TTypedValue_1_0* outMaxValues           - (OUT - optional) should have a memory for at least 'MetricCount * RawReportCount' values, can be nullptr. Calculated maxValues for each metric.
    //                                               If MaxValueEquation isn't defined for the metric, MaxValue will be equal to the current, normalized metric value.
    //     uint32_t         outMaxValuesSize       - size of the provided buffer for max values in bytes
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        return CalculateMetrics<false>( rawData, rawDataSize, out, outSize, outReportCount, outMaxValues, outMaxValuesSize );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateMetrics
    //
    // Template Parameter:
    //     async - Determines if the calculation is performed for async reports or not.
    //
    // Description:
    //     Conducts the whole process of metrics and information calculation for multiple reports.
    //     It's API agnostic - user doesn't have to worry about API he has used.
    //     User has to provide input buffer and its size, output buffer and its size with enough space for
    //     all calculated metrics and information.
    //     If async, method supports only IoStream. Query is not supported. Timer reports are not calculated in this method.
    //     The amount of input reports is calculated based on rawData size and the size of single raw report.
    //
    //     Optional MaxValues calculation added, if MaxValueEquation isn't defined for the metric its current
    //     normalized value is used.
    //
    // Input:
    //     const uint8_t*   rawData                - raw report data
    //     uint32_t         rawDataSize            - size of raw report data in bytes
    //     TTypedValue_1_0* out                    - (OUT) buffer for calculated reports
    //     uint32_t         outSize                - size of the provided output buffer in bytes
    //     uint32_t*        outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    //     TTypedValue_1_0* outMaxValues           - (OUT - optional) should have a memory for at least 'MetricCount * RawReportCount' values, can be nullptr. Calculated maxValues for each metric.
    //                                               If MaxValueEquation isn't defined for the metric, MaxValue will be equal to the current, normalized metric value.
    //     uint32_t         outMaxValuesSize       - size of the provided buffer for max values in bytes
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <bool async>
    TCompletionCode CMetricSet::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );

        constexpr uint32_t streamMask = API_TYPE_IOSTREAM;

        const auto measurementType = ( m_currentParams->ApiMask & streamMask )
            ? MEASUREMENT_TYPE_SNAPSHOT_IO
            : MEASUREMENT_TYPE_DELTA_QUERY;

        if constexpr( async )
        {
            if( measurementType != MEASUREMENT_TYPE_SNAPSHOT_IO )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Async metrics calculation is only supported for IoStream measurements" );
                MD_LOG_EXIT_A( adapterId );
                return CC_ERROR_NOT_SUPPORTED;
            }
        }

        MD_CHECK_PTR_RET_A( adapterId, rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, out, CC_ERROR_INVALID_PARAMETER );

        if( !rawDataSize )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "nothing to calculate, rawDataSize: 0" );
            MD_LOG_EXIT_A( adapterId );
            return CC_OK;
        }
        if( !outMaxValues || !outMaxValuesSize )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "max values won't be calculated, outMaxValues: %p, outMaxValuesSize: %u", outMaxValues, outMaxValuesSize );
            outMaxValues     = nullptr;
            outMaxValuesSize = 0;
        }

        if( !m_isFiltered )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_GENERAL;
        }
        if( ( m_currentParams->MetricsCount + m_currentParams->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG_A( adapterId, LOG_WARNING, "nothing to calculate, empty MetricSet" );
            MD_LOG_EXIT_A( adapterId );
            return CC_OK;
        }

        const uint32_t rawReportSize = ( measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO )
            ? m_currentParams->RawReportSize
            : m_currentParams->QueryReportSize;

        const uint32_t rawReportCount = rawDataSize / rawReportSize;

        // Validation
        auto ret = ValidateCalculateMetricsParams( rawDataSize, rawReportSize, outSize, rawReportCount, outMaxValuesSize );
        MD_CHECK_CC_RET_A( adapterId, ret );

        // Initialize manager and context
        TCalculationContext  calculationContext = {};
        CCalculationManager* calculationManager = nullptr;

        InitializeCalculationManager( measurementType, &calculationManager, true );
        MD_CHECK_PTR_RET_A( adapterId, calculationManager, CC_ERROR_NO_MEMORY );

        ret = InitializeCalculationContext( calculationContext, calculationManager, measurementType, out, outMaxValues, rawData, rawReportCount, true );
        if( ret != CC_OK )
        {
            goto deinitialize_manager;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "about to calculate %u raw reports", rawReportCount );

        // CALCULATE METRICS
        if constexpr( async )
        {
            while( calculationManager->CalculateNextAsyncReport( calculationContext ) )
            { // void
            }
        }
        else
        {
            while( calculationManager->CalculateNextReport( calculationContext ) )
            { // void
            }
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "calculated %u out reports", calculationContext.CommonCalculationContext.OutReportCount );
        MD_LOG_A( adapterId, LOG_DEBUG, "max values%s calculated", outMaxValues ? "" : " not" );

        if( outReportCount )
        {
            *outReportCount = calculationContext.CommonCalculationContext.OutReportCount;
        }

        InitializeCalculationContext( calculationContext, nullptr, measurementType, nullptr, nullptr, nullptr, 0, false );
    deinitialize_manager:
        InitializeCalculationManager( measurementType, &calculationManager, false );

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateIoMeasurementInformation
    //
    // Description:
    //     Calculates IoMeasurementInformation obtained on every ReadIoStream.
    //
    // Input:
    //     TTypedValue_1_0* out     - (OUT) buffer for calculated IoMeasurementInformation
    //     uint32_t         outSize - output buffer size, should be at least
    //                                IoMeasurementInformation count * sizeof(TTypedValue_1_0)
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );

        MD_CHECK_PTR_RET_A( adapterId, m_concurrentGroup, CC_ERROR_GENERAL );
        MD_CHECK_PTR_RET_A( adapterId, out, CC_ERROR_INVALID_PARAMETER );

        if( outSize < m_concurrentGroup->GetParams()->IoMeasurementInformationCount * sizeof( TTypedValue_1_0 ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG_A( adapterId, LOG_DEBUG, "outSize: %u", outSize );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        auto metricsCalculator = GetMetricsCalculator();
        MD_CHECK_PTR_RET_A( adapterId, metricsCalculator, CC_ERROR_GENERAL );

        metricsCalculator->ReadIoMeasurementInformation( *m_concurrentGroup, out );
        MD_LOG_A( adapterId, LOG_DEBUG, "calculated %u out io information", m_concurrentGroup->GetParams()->IoMeasurementInformationCount );

        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ValidateCalculateMetricsParams
    //
    // Description:
    //     Validates parameters passed to CalculateMetrics.
    //     Subjects of validation: i.a. input and output buffer alignments, output buffer size.
    //
    // Input:
    //     uint32_t rawDataSize      - raw report data size
    //     uint32_t rawReportSize    - size of one individual raw report
    //     uint32_t outSize          - size of out buffer in bytes
    //     uint32_t rawReportCount   - raw report count
    //     uint32_t outMaxValuesSize - size of max values buffer in bytes
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::ValidateCalculateMetricsParams( uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize, uint32_t rawReportCount, uint32_t outMaxValuesSize )
    {
        // Size of one individual calculated report in bytes
        uint32_t outReportSize = ( m_currentParams->MetricsCount + m_currentParams->InformationCount ) * sizeof( TTypedValue_1_0 );
        // Size of one individual calculated max values report in bytes
        uint32_t maxValuesReportSize = m_currentParams->MetricsCount * sizeof( TTypedValue_1_0 );

        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_ASSERT_A( adapterId, rawReportSize != 0 );

        if( rawDataSize % rawReportSize != 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: input buffer has incorrect size" );
            MD_LOG_A( adapterId, LOG_DEBUG, "rawDataSize: %u, rawReportSize: %u", rawDataSize, rawReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outReportSize == 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "outReportSize: 0. Nothing to calculate." );
            return CC_OK;
        }
        if( outSize % outReportSize != 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG_A( adapterId, LOG_DEBUG, "outSize: %u, outReportSize: %u", outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( rawReportCount > ( outSize / outReportSize ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: output buffer to small" );
            MD_LOG_A( adapterId, LOG_DEBUG, "rawReportCount: %u, outSize: %u, outReportSize: %u", rawReportCount, outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outMaxValuesSize && maxValuesReportSize && rawReportCount > ( outMaxValuesSize / maxValuesReportSize ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: maxValues buffer to small" );
            MD_LOG_A( adapterId, LOG_DEBUG, "rawReportCount: %u, outMaxValuesSize: %u, maxValueReportSize: %u", rawReportCount, outMaxValuesSize, maxValuesReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InitializeCalculationManager
    //
    // Description:
    //     Creates or destroys CalculationManager adequate to the given measurement type.
    //
    // Input:
    //     TMeasurementType      measurementType     - type of measurement for which manager will be created
    //     CCalculationManager** calculationManager  - (OUT) pointer to the newly created CalculationManager, null if error
    //     bool                  init                - if true initialization,
    //                                                 if false deinitialization
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::InitializeCalculationManager( TMeasurementType measurementType, CCalculationManager** calculationManager, bool init )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( !init )
        {
            MD_SAFE_DELETE( *calculationManager );
            MD_LOG_A( adapterId, LOG_DEBUG, "calculation manager deinitialization" );
            return;
        }

        MD_ASSERT_A( adapterId, *calculationManager == nullptr );
        switch( measurementType )
        {
            case MEASUREMENT_TYPE_DELTA_QUERY:
                *calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>();
                MD_LOG_A( adapterId, LOG_DEBUG, "query calculation manager created" );
                return;

            case MEASUREMENT_TYPE_SNAPSHOT_IO:
                *calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>();
                MD_LOG_A( adapterId, LOG_DEBUG, "ioStream calculation manager created" );
                return;

            default:
                *calculationManager = nullptr;
                MD_LOG_A( adapterId, LOG_ERROR, "not supported measurement type" );
                return;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InitializeCalculationContext
    //
    // Description:
    //     Resets calculation context and initializes it with user provided data.
    //     After execution the context is ready for metrics calculations.
    //
    // Input:
    //     TCalculationContext& context            - (OUT) calculation context
    //     CalcManager*         calculationManager - already initialized calculation manager
    //     TMeasurementType     measurementType    - type of measurements
    //     TTypedValue_1_0*     out                - output buffer
    //     TTypedValue_1_0*     outMaxValues       - output buffer for MaxValues, can be nullptr
    //     const uint8_t*       rawData            - input buffer with raw report data
    //     uint32_t             rawReportCount     - raw report count
    //     bool                 init               - if true initialization,
    //                                               if false deinitialization
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::InitializeCalculationContext( TCalculationContext& context, CCalculationManager* calculationManager, TMeasurementType measurementType, TTypedValue_1_0* out, TTypedValue_1_0* outMaxValues, const uint8_t* rawData, uint32_t rawReportCount, bool init )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );
        if( !init )
        {
            MD_SAFE_DELETE_ARRAY( context.CommonCalculationContext.DeltaValues );
            MD_LOG_A( adapterId, LOG_DEBUG, "calculation context deinitialization" );
            MD_LOG_EXIT_A( adapterId );
            return CC_OK;
        }

        // Initialize context
        calculationManager->ResetContext( context );
        context.CommonCalculationContext.DeltaValues = new( std::nothrow ) TTypedValue_1_0[m_currentParams->MetricsCount];
        MD_CHECK_PTR_RET_A( adapterId, context.CommonCalculationContext.DeltaValues, CC_ERROR_NO_MEMORY );
        context.CommonCalculationContext.Calculator     = GetMetricsCalculator();
        context.CommonCalculationContext.MetricSet      = this;
        context.CommonCalculationContext.Out            = out;
        context.CommonCalculationContext.OutMaxValues   = outMaxValues;
        context.CommonCalculationContext.RawData        = rawData;
        context.CommonCalculationContext.RawReportCount = rawReportCount;
        if( measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO )
        {
            // Not supported
            context.StreamCalculationContext.DoContextFiltering = false;
        }
        if( calculationManager->PrepareContext( context ) != CC_OK )
        {
            // Deinitialize and return error
            InitializeCalculationContext( context, nullptr, measurementType, nullptr, nullptr, nullptr, 0, false );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_GENERAL;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "calculation context initialized" );
        MD_LOG_A( adapterId, LOG_DEBUG, "metricSet: %s", context.CommonCalculationContext.MetricSet->GetParams()->ShortName );
        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AreMetricParamsValid
    //
    // Description:
    //     Checks the correctness of the given metric parameters.
    //
    // Input:
    //     const char* symbolicName     -
    //     const char* shortName        -
    //     const char* longName         -
    //     const char* groupName        -
    //     TMetricType metricType       -
    //     TMetricResultType resultType -
    //     const char* units            -
    //     THwUnitType hwType           -
    //     const char* alias            -
    //
    // Output:
    //     bool -
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::AreMetricParamsValid( const char* symbolName, const char* shortName, const char* longName, const char* groupName, TMetricType metricType, TMetricResultType resultType, const char* units, THwUnitType hwType, const char* alias )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( ( symbolName == nullptr ) || ( strcmp( symbolName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, symbolName );
            return false;
        }
        if( ( shortName == nullptr ) || ( strcmp( shortName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, shortName );
            return false;
        }
        if( ( longName == nullptr ) || ( strcmp( longName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, longName );
            return false;
        }
        if( ( groupName == nullptr ) || ( strcmp( groupName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, groupName );
            return false;
        }
        if( (uint32_t) metricType >= METRIC_TYPE_LAST )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, metricType );
            return false;
        }
        if( (uint32_t) resultType >= RESULT_LAST )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, resultType );
            return false;
        }
        if( ( units == nullptr ) || ( strcmp( units, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, units );
            return false;
        }
        if( (uint32_t) hwType >= HW_UNIT_LAST )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, hwType );
            return false;
        }
        if( alias == nullptr )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, alias );
            return false;
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsCustomApiMaskValid
    //
    // Description:
    //     Validates API mask used in IsCustomApiMaskValid method.
    //     IoStream and Query measurements can be mixed.
    //
    // Input:
    //    const uint32_t apiMask - api mask
    //
    // Output:
    //     bool                  - true if valid, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsCustomApiMaskValid( const uint32_t apiMask )
    {
        if( apiMask != 0 && apiMask != API_TYPE_ALL )
        {
            const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
            const bool     isStream  = ( apiMask & API_TYPE_IOSTREAM );
            const bool     isQuery   = ( apiMask & MD_QUERY_API_MASK );

            if( !isStream && !isQuery )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Wrong apiMask!, apiMask: %x", apiMask );
                return false;
            }
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     HasInformation
    //
    // Description:
    //     Returns true if in the m_informationVector there is an information with the given
    //     symbol name.
    //
    // Input:
    //     const char * symbolName - information name to look for
    //
    // Output:
    //     bool - true if found
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::HasInformation( const char* symbolName )
    {
        MD_CHECK_PTR_RET_A( m_device.GetAdapter().GetAdapterId(), symbolName, false );

        for( uint32_t i = 0; i < m_params.InformationCount; ++i )
        {
            auto information = GetInformation( i );
            if( information && information->GetParams()->SymbolName != nullptr && strcmp( information->GetParams()->SymbolName, symbolName ) == 0 )
            {
                return true;
            }
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetMetricsCalculator
    //
    // Description:
    //     Returns metrics calculator.
    //
    // Output:
    //     CMetricsCalculator* - metrics calculator or *nullptr* if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsCalculator* CMetricSet::GetMetricsCalculator()
    {
        if( m_metricsCalculator == nullptr )
        {
            std::vector<std::reference_wrapper<CMetricsDevice>> devices = { m_device };

            InitializeMetricsCalculator( devices );
        }

        return m_metricsCalculator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetMetricsDevice
    //
    // Description:
    //     Returns metrics device.
    //
    // Output:
    //     CMetricsDevice& - reference to metrics device associated with metrics set
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice& CMetricSet::GetMetricsDevice()
    {
        return m_device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetPlatformMask
    //
    // Description:
    //     Returns platform mask byte array member.
    //
    // Output:
    //     TByteArrayLatest* -
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest* CMetricSet::GetPlatformMask()
    {
        return m_platformMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InitializeMetricsCalculator
    //
    // Description:
    //     Initializes metrics calculator if not already initialized.
    //
    // Input:
    //    std::vector<std::reference_wrapper<CMetricsDevice>>& devices - vector of metrics devices, used to get symbols
    //
    // Output:
    //     TCompletionCode - *CC_OK* if metrics calculator has been initialized successfully, *CC_ERROR_NO_MEMORY* if memory allocation failed.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::InitializeMetricsCalculator( std::vector<std::reference_wrapper<CMetricsDevice>>& devices )
    {
        if( m_metricsCalculator == nullptr )
        {
            const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

            m_metricsCalculator = ( devices.size() == 1 )
                ? new( std::nothrow ) CMetricsCalculator( devices[0].get() )
                : new( std::nothrow ) CMetricsCalculator( devices );

            if( m_metricsCalculator == nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot allocate memory for CMetricsCalculator" );
                return CC_ERROR_NO_MEMORY;
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the metric set. It's used to determine if the metric
    //     set is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret       = SetEquation( m_device, m_availabilityEquation, equationString );
        const uint32_t  adapterId = m_device.GetAdapter().GetAdapterId();

        if( ret == CC_OK )
        {
            m_params.AvailabilityEquation = GetCopiedCString( equationString, adapterId );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsAvailabilityEquationTrue
    //
    // Description:
    //     Solves the given metric set availability equation.
    //
    // Output:
    //     bool - result of solving availability equation.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsAvailabilityEquationTrue()
    {
        return !m_availabilityEquation || m_availabilityEquation->SolveBooleanEquation();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsFlexible
    //
    // Description:
    //     Returns true if a given metric set is flexible. False otherwise.
    //
    // Output:
    //     bool - true if flexible.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsFlexible() const
    {
        return m_isFlexible;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetToFlexible
    //
    // Description:
    //     Makes metric set flexible what means that the metric set is able to
    //     create metrics from metric prototypes. Allocates a prototype manager.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::SetToFlexible()
    {
        if( !m_prototypeManager )
        {
            if( m_isOam )
            {
                m_prototypeManager = new( std::nothrow ) CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>( m_device, *this );
            }
            else
            {
                m_prototypeManager = new( std::nothrow ) CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>( m_device, *this );
            }

            m_isFlexible = m_prototypeManager != nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetPrototypeManager
    //
    // Description:
    //     Deletes the current prototype manager and sets the new one.
    //
    // Input:
    //     CPrototypeManager* prototypeManager - prototype manager
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::SetPrototypeManager( CPrototypeManager* prototypeManager )
    {
        MD_SAFE_DELETE( m_prototypeManager );

        m_prototypeManager = prototypeManager;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     DecreasePrototypesReferenceCounters
    //
    // Description:
    //     Decreases reference counters for all metric prototypes added to the
    //     metric set.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::DecreasePrototypesReferenceCounters()
    {
        if( m_prototypeManager )
        {
            m_prototypeManager->DecreasePrototypesReferenceCounters();
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsOpened
    //
    // Description:
    //     Returns true if a given metric set is opened. False otherwise.
    //
    // Output:
    //     bool - true if open.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsOpened()
    {
        return m_isOpened;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddDefaultMetrics
    //
    // Description:
    //     Add default metrics to metric set like GpuCoreClock, GpuTime etc.
    //
    // Output:
    //     TCompletionCode - CC_OK if metrics have been added successfully.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddDefaultMetrics()
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        const bool isXe2PlusPlatform =
            IsPlatformPresentInMask( m_platformMask, GENERATION_BMG, adapterId ) ||
            IsPlatformPresentInMask( m_platformMask, GENERATION_LNL, adapterId ) ||
            IsPlatformPresentInMask( m_platformMask, GENERATION_PTL, adapterId ) ||
            IsPlatformPresentInMask( m_platformMask, GENERATION_NVL, adapterId ) ||
            IsPlatformPresentInMask( m_platformMask, GENERATION_CRI, adapterId );

        const uint32_t apiMask = m_isOam
            ? API_TYPE_IOSTREAM
            : ( MD_QUERY_API_MASK | API_TYPE_IOSTREAM );

        CMetric* metric      = nullptr;
        uint32_t metricIndex = 0;

        metric = AddMetric( "GpuTime", "GPU Time Elapsed", "Time elapsed on the GPU during the measurement.", "GPU", 0, USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, apiMask, METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, "oa.fixed", metricIndex++, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );

        if( isXe2PlusPlatform )
        {
            MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        }
        else
        {
            MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "dw@0x08 1000000000 UMUL $GpuTimestampFrequency UDIV" ) );
        }
        if( !m_isOam )
        {
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x00" ) );
        }

        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks", "The total number of GPU core clocks elapsed during the measurement.", "GPU", 0, USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, apiMask, METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, "oa.fixed", metricIndex++, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );

        if( !m_isOam )
        {
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x08" ) );
        }

        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency", "Average GPU Core Frequency in the measurement.", "GPU", 0, USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, apiMask, METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, "oa.fixed", metricIndex++, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty", "Result uncertainty indicator", "GPU", 0, USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, apiMask, METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, metricIndex++, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        return CC_OK;

    exception:
        MD_LOG_A( adapterId, LOG_INFO, "Failed to add default metrics" );
        return CC_ERROR_GENERAL;
    }
} // namespace MetricsDiscoveryInternal
