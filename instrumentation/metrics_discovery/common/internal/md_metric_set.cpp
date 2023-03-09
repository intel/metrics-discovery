/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_set.h

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
    //     CMetricsDevice*     device               -
    //     CConcurrentGroup*   concurrentGroup      -
    //     const char*         symbolicName         -
    //     const char*         shortName            -
    //     uint32_t            apiMask              -
    //     uint32_t            categoryMask         -
    //     uint32_t            snapshotReportSize   -
    //     uint32_t            deltaReportSize      -
    //     TReportType         reportType           -
    //     TByteArrayLatest*   platformMask         -
    //     uint32_t            gtMask               -
    //     bool                isCustom             -
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet::CMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : m_concurrentGroup( concurrentGroup )
        , m_params_1_0{}
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
        , m_platformMask( GetCopiedByteArray( platformMask, OBTAIN_ADAPTER_ID( m_device ) ) )
        , m_availabilityEquation( nullptr )
        , m_filteredMetricsVector()
        , m_filteredInformationVector()
        , m_isCustom( isCustom )
        , m_isReadRegsCfgSet( false )
        , m_metricsCalculator( new( std::nothrow ) CMetricsCalculator( m_device ) )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.SymbolName             = GetCopiedCString( symbolicName, adapterId );
        m_params_1_0.ShortName              = GetCopiedCString( shortName, adapterId );
        m_params_1_0.ApiMask                = apiMask;
        m_params_1_0.CategoryMask           = categoryMask;
        m_params_1_0.RawReportSize          = snapshotReportSize; // as in HW
        m_params_1_0.QueryReportSize        = deltaReportSize;    // as in Query API
        m_params_1_0.MetricsCount           = 0;
        m_params_1_0.InformationCount       = concurrentGroup->GetInformationCount();
        m_params_1_0.ComplementarySetsCount = 0;
        m_params_1_0.ApiSpecificId          = {};
        m_params_1_0.PlatformMask           = GetPlatformTypeFromByteArray( platformMask, adapterId );
        m_params_1_0.GtMask                 = gtMask;
        m_params_1_0.AvailabilityEquation   = "";

        m_pmRegsConfigInfo.IsQueryConfig  = false;
        m_pmRegsConfigInfo.OaConfigHandle = 0;
        m_pmRegsConfigInfo.GpConfigHandle = 0;
        m_pmRegsConfigInfo.RrConfigHandle = 0;

        m_metricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_informationVector.reserve( INFORMATION_VECTOR_INCREASE );
        m_complementarySetsVector.reserve( COMPLEMENTARY_SETS_VECTOR_INCREASE );
        m_startRegsVector.reserve( START_REGS_VECTOR_INCREASE );
        m_startRegsQueryVector.reserve( START_REGS_QUERY_VECTOR_INCREASE );

        m_otherMetricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_otherInformationVector.reserve( INFORMATION_VECTOR_INCREASE );

        m_filteredMetricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_filteredInformationVector.reserve( INFORMATION_VECTOR_INCREASE );

        // Set 'current' variables and mark 'filtered' params as uninitialized
        UseApiFilteredVariables( false );
        m_filteredParams.ApiMask              = 0;
        m_filteredParams.GtMask               = 0;
        m_filteredParams.AvailabilityEquation = nullptr;

        if( m_metricsCalculator == nullptr )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot allocate memory for CMetricsCalculator" );
        }
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
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.D3D1XDevDependentName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.OGLQueryIntelName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.AvailabilityEquation );

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

        DeleteByteArray( m_platformMask, OBTAIN_ADAPTER_ID( m_device ) );
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
    //     TMetricSetParams_1_11*  - metric set params
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricSetParams_1_11* CMetricSet::GetParams( void )
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
    //     uint32_t     index  - index of a metric
    //
    // Output:
    //     IMetric_1_0*        - chosen metric or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetric_1_0* CMetricSet::GetMetric( uint32_t index )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_currentMetricsVector, nullptr );

        if( index < m_currentMetricsVector->size() )
        {
            return static_cast<IMetric_1_0*>( ( *m_currentMetricsVector )[index] );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_currentInformationVector, nullptr );

        if( m_isFiltered )
        {
            if( index < m_currentInformationVector->size() )
            {
                return static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index] );
            }
            return nullptr;
        }

        // if index is in Concurrent Group indexes bounds ( 0..N, N = amount of infs in concurrent group )
        if( index < m_concurrentGroup->GetInformationCount() )
        {
            // return information from Concurrent Group
            return m_concurrentGroup->GetInformation( index );
        }
        else
        {
            if( index < m_currentInformationVector->size() + m_concurrentGroup->GetInformationCount() )
            {
                return static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index - m_concurrentGroup->GetInformationCount()] );
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
    //     GetComplementaryMetricSet
    //
    // Description:
    //     Returns the chosen complementary metric set or null if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of a complementary set
    //
    // Output:
    //     IMetricSet_1_11*     - chosen complementary metric set or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSet_1_11* CMetricSet::GetComplementaryMetricSet( uint32_t index )
    {
        if( index < m_complementarySetsVector.size() )
        {
            IMetricSet_1_11* metricSet       = nullptr;
            size_t           stringLength    = strlen( m_complementarySetsVector[index] );
            uint32_t         metricSetsCount = m_concurrentGroup->GetParams()->MetricSetsCount;
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );
        TCompletionCode ret = CC_OK;
        if( m_isReadRegsCfgSet )
        {
            CDriverInterface& driverInterface  = m_device->GetDriverInterface();
            TRegister         emptyRrConfig    = { 0, 0, REGISTER_TYPE_MMIO };
            TRegister*        emptyRrConfigPtr = &emptyRrConfig; // Because we will need 'array of pointers'

            ret = driverInterface.SendReadRegsConfig( &emptyRrConfigPtr, 1, m_currentParams->ApiMask );
            if( ret == CC_OK )
            {
                // Update PmRegsHandles and reset rrSet flag
                driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, groupName, METRIC_GROUP_NAME_ID_INVALID );

        uint32_t groupId = 0, tokenNo = 0;
        char *   token = nullptr, *tokenNext = nullptr, *groupNameCopy = nullptr;

        groupNameCopy = GetCopiedCString( groupName, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, groupNameCopy, METRIC_GROUP_NAME_ID_INVALID );

        token = iu_strtok_s( groupNameCopy, "/", &tokenNext );
        while( token != nullptr )
        {
            uint32_t partialGroupId = GetPartialGroupId( token, tokenNo++ );
            if( partialGroupId == METRIC_GROUP_NAME_ID_INVALID )
            {
                partialGroupId = METRIC_GROUP_NAME_ID_GPU; // Use default group name ID
            }

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( params == nullptr )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, params );
            return nullptr;
        }

        if( params->Type != METRIC_CUSTOM_PARAMS_1_0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unsupported TAddCustomMetricParams Type: %u", params->Type );
            return nullptr;
        }

        const char*       symbolName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SymbolName;
        const char*       shortName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ShortName;
        const char*       groupName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).GroupName;
        const char*       longName              = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LongName;
        const char*       dxToOglAlias          = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DxToOglAlias;
        uint32_t          usageFlagsMask        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).UsageFlagsMask;
        uint32_t          apiMask               = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ApiMask;
        TMetricResultType resultType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ResultType;
        const char*       resultUnits           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricResultUnits;
        TMetricType       metricType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricType;
        int64_t           loWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LowWatermark;
        int64_t           hiWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HighWatermark;
        THwUnitType       hwType                = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HwUnitType;
        const char*       ioReadEquation        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).IoReadEquation;
        const char*       deltaFunction         = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DeltaFunction;
        const char*       queryReadEquation     = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).QueryReadEquation;
        const char*       normalizationEquation = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).NormEquation;
        const char*       maxValueEquation      = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MaxValueEquation;
        const char*       signalName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SignalName;
        const char*       availabilityEquation  = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).AvailabilityEquation;

        MD_LOG_ENTER_A( adapterId );

        if( !AreMetricParamsValid(
                symbolName, shortName, longName, groupName, metricType, resultType, resultUnits, hwType, dxToOglAlias ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "invalid custom metric parameters" );
            return nullptr;
        }
        if( IsMetricAlreadyAdded( symbolName ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "metric already added: %s", symbolName );
            return nullptr;
        }

        uint32_t groupId = MetricGroupNameToId( groupName );

        CMetric* metric = new( std::nothrow ) CMetric( m_device, m_metricsVector.size(), symbolName, shortName, longName, groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, resultUnits, loWatermark, hiWatermark, hwType, dxToOglAlias, signalName, true );
        MD_CHECK_PTR_RET_A( adapterId, metric, nullptr );

        if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK || metric->SetSnapshotReportReadEquation( ioReadEquation ) != CC_OK || metric->SetDeltaReportReadEquation( queryReadEquation ) != CC_OK || metric->SetNormalizationEquation( normalizationEquation ) != CC_OK || metric->SetSnapshotReportDeltaFunction( deltaFunction ) != CC_OK || metric->SetMaxValueEquation( maxValueEquation ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error setting custom metric equations" );
            MD_SAFE_DELETE( metric );
            return nullptr;
        }

        m_metricsVector.push_back( metric );
        m_params_1_0.MetricsCount = m_metricsVector.size();
        m_isCustom                = true;

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
    //     IMetric_1_0* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetric_1_0* CMetricSet::AddCustomMetric( const char* symbolName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName )
    {
        TAddCustomMetricParams params = {
            METRIC_CUSTOM_PARAMS_1_0,
        };
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
        params.CustomMetricParams_1_0.AvailabilityEquation = "1";

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.ApiSpecificId.D3D9QueryId           = dx9QueryId;
        m_params_1_0.ApiSpecificId.D3D9Fourcc            = dx9Fourcc ? ( dx9Fourcc[0] ) + ( dx9Fourcc[1] << 8 ) + ( dx9Fourcc[2] << 16 ) + ( dx9Fourcc[3] << 24 ) : 0;
        m_params_1_0.ApiSpecificId.D3D1XQueryId          = dx10QueryId;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentId   = dx10Counter;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( dx10CounterName, adapterId );
        m_params_1_0.ApiSpecificId.OGLQueryIntelId       = oglQuery;
        m_params_1_0.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( oglQueryName, adapterId );
        m_params_1_0.ApiSpecificId.OGLQueryARBTargetId   = oglQueryARB;
        m_params_1_0.ApiSpecificId.OCL                   = ocl;
        m_params_1_0.ApiSpecificId.HwConfigId            = hwConfig;

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.ApiSpecificId                       = apiSpecificId;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( apiSpecificId.D3D1XDevDependentName, adapterId );
        m_params_1_0.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( apiSpecificId.OGLQueryIntelName, adapterId );

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
                uint32_t count = m_metricsVector.size();
                metric->SetIdInSetParam( count );
                m_metricsVector.push_back( metric );
                m_params_1_0.MetricsCount = count + 1;
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, metric, nullptr );

        if( IsMetricAlreadyAdded( metric->GetParams()->SymbolName ) )
        {
            m_otherMetricsVector.push_back( metric );
        }
        else
        {
            m_metricsVector.push_back( metric );
            m_params_1_0.MetricsCount = m_metricsVector.size();
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        CInformation* information = new( std::nothrow ) CInformation( m_device, informationXmlId, symbolName, shortName, longName, groupName, apiMask, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, information, nullptr );

        if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( information );
            return nullptr;
        }

        if( information->IsAvailabilityEquationTrue() )
        {
            information->SetIdInSetParam( m_informationVector.size() );
            m_informationVector.push_back( information );
            m_params_1_0.InformationCount = m_informationVector.size() + m_concurrentGroup->GetInformationCount();
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
        MD_CHECK_PTR_RET_A( OBTAIN_ADAPTER_ID( m_device ), information, nullptr );

        m_informationVector.push_back( information );
        m_params_1_0.InformationCount = m_informationVector.size() + m_concurrentGroup->GetInformationCount();

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, complementaryMetricSetSymbolicName, CC_ERROR_INVALID_PARAMETER );

        if( strcmp( complementaryMetricSetSymbolicName, "" ) == 0 )
        {
            return CC_OK; // 0 is fine condition for "" name
        }

        char* metricSetName = GetCopiedCString( complementaryMetricSetSymbolicName, adapterId );

        m_complementarySetsVector.push_back( metricSetName );
        m_params_1_0.ComplementarySetsCount = m_complementarySetsVector.size();

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, complementarySetsList, CC_ERROR_INVALID_PARAMETER );

        char *token = nullptr, *tokenNext = nullptr, *complementarySets = nullptr;

        complementarySets = GetCopiedCString( complementarySetsList, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, complementarySets, CC_ERROR_NO_MEMORY );

        token = iu_strtok_s( complementarySets, ",", &tokenNext );
        while( token != nullptr )
        {
            if( AddComplementaryMetricSet( token ) != CC_OK )
            {
                MD_LOG_A( m_device->GetAdapter().GetAdapterId(), LOG_DEBUG, "error adding complementary metric sets" );
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
        const uint32_t  adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        CRegisterSet* registerSet = new( std::nothrow ) CRegisterSet( m_device, configId, configPriority, configType );
        MD_CHECK_PTR_RET_A( adapterId, registerSet, CC_ERROR_NO_MEMORY );

        if( registerSet->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
                if( params->ConfigType == CONFIG_TYPE_COMMON )
                {
                    registerSet->RegsToVector( m_startRegsVector );
                }
                else if( params->ConfigType == CONFIG_TYPE_QUERY )
                {
                    registerSet->RegsToVector( m_startRegsQueryVector );
                }
                else
                {
                    MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_ERROR, "Unknown register method" );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, registerSet, false );

        bool          ret             = false;
        CRegisterSet* set             = nullptr;
        uint32_t      highestPriority = 0xFFFFFFFF; // Lower is more important

        for( auto& registerSet : m_startRegisterSetList )
        {
            TRegisterSetParams* params = registerSet->GetParams();
            if( params->ConfigId >= id )
            {
                ret = true;
                if( params->ConfigId == id && registerSet->IsAvailable() && params->ConfigPriority < highestPriority )
                {
                    highestPriority = params->ConfigPriority;
                    set             = registerSet;
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
    //     uint32_t*     count - (out) registers count
    //
    // Output:
    //     TRegister**         - pointers to the common start config registers
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegister** CMetricSet::GetStartConfiguration( uint32_t* count )
    {
        if( count != nullptr )
        {
            *count = m_startRegsVector.size();
        }
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
        TCompletionCode     ret               = CC_OK;
        CDriverInterface&   driverInterface   = m_device->GetDriverInterface();
        COAConcurrentGroup& oaConcurrentGroup = static_cast<COAConcurrentGroup&>( *m_concurrentGroup );

        if( CheckSendConfigRequired( sendQueryConfigFlag ) )
        {
            // Prepare register reference lists to sent
            std::vector<TRegister*> pmRegs;
            std::vector<TRegister*> readRegs;
            pmRegs.reserve( START_REGS_VECTOR_INCREASE );
            readRegs.reserve( START_REGS_VECTOR_INCREASE );

            AppendToConfiguration( m_startRegsVector, pmRegs, readRegs );
            if( sendQueryConfigFlag )
            {
                AppendToConfiguration( m_startRegsQueryVector, pmRegs, readRegs );
            }

            // Verify if programming is present
            // "m_startRegisterSetList may be empty for e.g. PipelineStatistics"
            if( ( pmRegs.size() > 0 || readRegs.size() > 0 ) || m_startRegisterSetList.size() == 0 )
            {
                // Send configurations
                ret = driverInterface.SendPmRegsConfig( pmRegs.data(), pmRegs.size(), m_currentParams->ApiMask, m_device->GetSubDeviceIndex(), oaConcurrentGroup.GetOaBufferType() );
                if( ret == CC_OK && readRegs.size() )
                {
                    ret = driverInterface.SendReadRegsConfig( readRegs.data(), readRegs.size(), m_currentParams->ApiMask );
                }

                if( ret == CC_OK )
                {
                    m_isReadRegsCfgSet = readRegs.size() > 0;

                    m_pmRegsConfigInfo.IsQueryConfig = sendQueryConfigFlag;
                    driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
                }
            }
            else
            {
                MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_ERROR, "Programming missing" );
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
        bool              ret             = true;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();
        const uint32_t    adapterId       = OBTAIN_ADAPTER_ID( m_device );

        // If measurement type didn't change and config handles were checked before
        if( m_pmRegsConfigInfo.IsQueryConfig == sendQueryConfigFlag && ( m_pmRegsConfigInfo.OaConfigHandle != 0 || m_pmRegsConfigInfo.GpConfigHandle != 0 || m_pmRegsConfigInfo.RrConfigHandle != 0 ) )
        {
            uint32_t        oaCfgHandle = 0;
            uint32_t        gpCfgHandle = 0;
            uint32_t        rrCfgHandle = 0;
            TCompletionCode retCode     = CC_OK;

            retCode = driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &oaCfgHandle, &gpCfgHandle, &rrCfgHandle );

            if( retCode == CC_OK && oaCfgHandle == m_pmRegsConfigInfo.OaConfigHandle && gpCfgHandle == m_pmRegsConfigInfo.GpConfigHandle && rrCfgHandle == m_pmRegsConfigInfo.RrConfigHandle )
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
    //     WriteCMetricSetToFile
    //
    // Description:
    //     Writes metric set to file.
    //
    // Input:
    //     FILE* metricFile - handle to metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::WriteCMetricSetToFile( FILE* metricFile )
    {
        uint32_t       count     = 0;
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile, adapterId );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.CategoryMask, sizeof( m_params_1_0.CategoryMask ), 1, metricFile );
        fwrite( &m_params_1_0.RawReportSize, sizeof( m_params_1_0.RawReportSize ), 1, metricFile );
        fwrite( &m_params_1_0.QueryReportSize, sizeof( m_params_1_0.QueryReportSize ), 1, metricFile );
        fwrite( &m_params_1_0.PlatformMask, sizeof( m_params_1_0.PlatformMask ), 1, metricFile );
        fwrite( &m_params_1_0.GtMask, sizeof( m_params_1_0.GtMask ), 1, metricFile );
        WriteEquationToFile( m_availabilityEquation, metricFile, adapterId );
        fwrite( &m_reportType, sizeof( m_reportType ), 1, metricFile );
        WriteByteArrayToFile( m_platformMask, metricFile, adapterId );
        // m_params_1_0.ApiSpecificId (placeholder is not saved!)
        fwrite( &m_params_1_0.ApiSpecificId.D3D9QueryId, sizeof( m_params_1_0.ApiSpecificId.D3D9QueryId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D9Fourcc, sizeof( m_params_1_0.ApiSpecificId.D3D9Fourcc ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D1XQueryId, sizeof( m_params_1_0.ApiSpecificId.D3D1XQueryId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D1XDevDependentId, sizeof( m_params_1_0.ApiSpecificId.D3D1XDevDependentId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.ApiSpecificId.D3D1XDevDependentName, metricFile, adapterId );
        fwrite( &m_params_1_0.ApiSpecificId.OGLQueryIntelId, sizeof( m_params_1_0.ApiSpecificId.OGLQueryIntelId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.ApiSpecificId.OGLQueryIntelName, metricFile, adapterId );
        fwrite( &m_params_1_0.ApiSpecificId.OGLQueryARBTargetId, sizeof( m_params_1_0.ApiSpecificId.OGLQueryARBTargetId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.OCL, sizeof( m_params_1_0.ApiSpecificId.OCL ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.HwConfigId, sizeof( m_params_1_0.ApiSpecificId.HwConfigId ), 1, metricFile );

        // m_metricsVector & m_otherMetricsVector
        count = m_metricsVector.size() + m_otherMetricsVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        uint32_t i = 0;
        uint32_t j = 0;
        while( i < m_metricsVector.size() || j < m_otherMetricsVector.size() )
        {
            // Define which vector is not finished and write remaining available metrics
            if( i == m_metricsVector.size() )
            {
                for( uint32_t k = j; k < m_otherMetricsVector.size(); k++ )
                {
                    m_otherMetricsVector[k]->WriteCMetricToFile( metricFile );
                }
                break;
            }
            if( j == m_otherMetricsVector.size() )
            {
                for( uint32_t k = i; k < m_metricsVector.size(); k++ )
                {
                    m_metricsVector[k]->WriteCMetricToFile( metricFile );
                }
                break;
            }

            // Write in the correct order
            if( m_metricsVector[i]->m_id < m_otherMetricsVector[j]->m_id )
            {
                m_metricsVector[i]->WriteCMetricToFile( metricFile );
                i++;
            }
            else
            {
                m_otherMetricsVector[j]->WriteCMetricToFile( metricFile );
                j++;
            }
        }

        // m_informationVector & m_otherInformationVector
        count = m_informationVector.size() + m_otherInformationVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        i = 0;
        j = 0;
        while( i < m_informationVector.size() || j < m_otherInformationVector.size() )
        {
            // Define which vector is not finished and write remaining available informations
            if( i == m_informationVector.size() )
            {
                for( uint32_t k = j; k < m_otherInformationVector.size(); k++ )
                {
                    m_otherInformationVector[k]->WriteCInformationToFile( metricFile );
                }
                break;
            }
            if( j == m_otherInformationVector.size() )
            {
                for( uint32_t k = i; k < m_informationVector.size(); k++ )
                {
                    m_informationVector[k]->WriteCInformationToFile( metricFile );
                }
                break;
            }

            // Write in the correct order
            if( m_informationVector[i]->m_id < m_otherInformationVector[j]->m_id )
            {
                m_informationVector[i++]->WriteCInformationToFile( metricFile );
            }
            else
            {
                m_otherInformationVector[j++]->WriteCInformationToFile( metricFile );
            }
        }

        // m_startRegisterSetList
        count = m_startRegisterSetList.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        for( auto& registerSet : m_startRegisterSetList )
        {
            registerSet->WriteCRegisterSetToFile( metricFile );
        }

        // m_stopRegisterSetList - remains to be backward compatible, count is always 0
        count = 0;
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );

        // m_complementarySetsVector
        count = m_complementarySetsVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        for( i = 0; i < count; i++ )
        {
            WriteCStringToFile( m_complementarySetsVector[i], metricFile, adapterId );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
                    MD_ASSERT_A( m_device->GetAdapter().GetAdapterId(), false );
                    return CC_ERROR_GENERAL;
                }
                metricSignalName = referenceMetric->GetSignalName();
                if( signalName == nullptr || ( metricSignalName != nullptr && strstr( metricSignalName, signalName ) != nullptr ) )
                {
                    metric = new( std::nothrow ) CMetric( *referenceMetric );
                    if( !metric )
                    {
                        MD_LOG_A( m_device->GetAdapter().GetAdapterId(), LOG_DEBUG, "error copying metrics" );
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
                MD_ASSERT_A( m_device->GetAdapter().GetAdapterId(), false );
                return CC_ERROR_GENERAL;
            }
            information = new( std::nothrow ) CInformation( *referenceInformation );
            if( !information )
            {
                MD_LOG_A( m_device->GetAdapter().GetAdapterId(), LOG_DEBUG, "error copying information" );
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
        MD_CHECK_PTR_RET_A( OBTAIN_ADAPTER_ID( m_device ), symbolName, false );

        for( auto& metric : m_metricsVector )
        {
            if( metric && ( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 ) )
            {
                return true;
            }
        }

        for( auto& metric : m_otherMetricsVector )
        {
            if( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 )
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );

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
    // Output:
    //     bool - true if valid, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsApiFilteringMaskValid( uint32_t apiMask )
    {
        bool     ret        = true;
        uint32_t streamMask = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;

        if( apiMask == 0 || apiMask == API_TYPE_ALL )
        {
            ret = true;
        }
        // Do not allow mixing stream and query metrics
        else if( ( apiMask & streamMask ) && ( apiMask & ~streamMask ) )
        {
            MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_DEBUG, "error: IoStream and Query api mask mixed, apiMask: %u", apiMask );
            ret = false;
        }

        return ret;
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
    //     uint32_t     apiMask - API mask for filtering
    //     bool         enable  - if true enable, if false disable
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::EnableApiFiltering( uint32_t apiMask, bool enable )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
                MD_LOG_A( adapterId, LOG_DEBUG, "using cached metrics for API filtering, apiMask: %u", apiMask );
            }
            else
            {
                // Copy (shallow) params, then modify apiMask
                iu_memcpy_s( &m_filteredParams, sizeof( m_filteredParams ), &m_params_1_0, sizeof( m_params_1_0 ) );
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
        std::unordered_map<std::string, uint32_t> metricsIndexMap( GetParams()->MetricsCount );

        // Update metric indices
        for( uint32_t i = 0; i < GetParams()->MetricsCount; i++ )
        {
            CMetric* metric = GetMetricExplicit( i );

            if( metric )
            {
                metricsIndexMap[metric->GetParams()->SymbolName] = i;

                if( metric->GetParams()->NormEquation )
                {
                    // Get an equation
                    IEquation_1_0* equation = metric->GetParams()->NormEquation;

                    // Metrics equation can use only preceding metrics' values
                    for( uint32_t j = 0; j < equation->GetEquationElementsCount(); j++ )
                    {
                        CEquationElementInternal* internalElement = (CEquationElementInternal*) equation->GetEquationElement( j );

                        if( internalElement->Element_1_0.Type == EQUATION_ELEM_LOCAL_COUNTER_SYMBOL || internalElement->Element_1_0.Type == EQUATION_ELEM_LOCAL_METRIC_SYMBOL )
                        {
                            // Find if symbol name is in the index map
                            const auto foundMetric = metricsIndexMap.find( internalElement->Element_1_0.SymbolName );

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
        if( enable )
        {
            m_currentParams            = &m_filteredParams;
            m_currentMetricsVector     = &m_filteredMetricsVector;
            m_currentInformationVector = &m_filteredInformationVector;
            m_isFiltered               = true;
        }
        else
        {
            m_currentParams            = &m_params_1_0;
            m_currentMetricsVector     = &m_metricsVector;
            m_currentInformationVector = &m_informationVector;
            m_isFiltered               = false;
        }

        MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_DEBUG, "use API filtered variables: %s", enable ? "TRUE" : "FALSE" );
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

        // Cache metrics
        for( uint32_t i = 0, j = 0; i < m_params_1_0.MetricsCount; i++ )
        {
            CMetric* metric = GetMetricExplicit( i );
            if( metric && ( metric->GetParams()->ApiMask & m_filteredParams.ApiMask ) > 0 )
            {
                CMetric* filteredMetric = metric;
                filteredMetric->SetIdInSetParam( j++ );

                m_filteredMetricsVector.push_back( filteredMetric );
            }
        }

        // Cache information
        for( uint32_t i = 0, j = 0; i < m_params_1_0.InformationCount; i++ )
        {
            IInformation_1_0* information = GetInformation( i );
            if( information && ( information->GetParams()->ApiMask & m_filteredParams.ApiMask ) > 0 )
            {
                CInformation* filteredInformation = static_cast<CInformation*>( information );
                filteredInformation->SetIdInSetParam( j++ );

                m_filteredInformationVector.push_back( filteredInformation );
            }
        }

        // Modify counts
        m_filteredParams.MetricsCount     = m_filteredMetricsVector.size();
        m_filteredParams.InformationCount = m_filteredInformationVector.size();

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
        uint32_t count = m_filteredMetricsVector.size();
        for( uint32_t i = 0; i < count; i++ )
        {
            m_filteredMetricsVector[i] = nullptr;
        }
        count = m_filteredInformationVector.size();
        for( uint32_t i = 0; i < count; i++ )
        {
            m_filteredInformationVector[i] = nullptr;
        }

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
            MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_ERROR, "error: context filtering not supported" );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );

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

        TCompletionCode  ret             = CC_OK;
        uint32_t         streamMask      = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;
        TMeasurementType measurementType = ( m_currentParams->ApiMask & streamMask ) ? MEASUREMENT_TYPE_SNAPSHOT_IO : MEASUREMENT_TYPE_DELTA_QUERY;
        uint32_t         rawReportSize   = ( measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO ) ? m_currentParams->RawReportSize : m_currentParams->QueryReportSize;
        uint32_t         rawReportCount  = rawDataSize / rawReportSize;

        // Validation
        ret = ValidateCalculateMetricsParams( rawDataSize, rawReportSize, outSize, rawReportCount, outMaxValuesSize );
        MD_CHECK_CC_RET_A( adapterId, ret );

        // Initialize manager and context
        CCalculationManager* calculationManager = nullptr;
        TCalculationContext  calculationContext;

        InitializeCalculationManager( measurementType, &calculationManager, true );
        MD_CHECK_PTR_RET_A( adapterId, calculationManager, CC_ERROR_NO_MEMORY );

        ret = InitializeCalculationContext( calculationContext, calculationManager, measurementType, out, outMaxValues, rawData, rawReportCount, true );
        if( ret != CC_OK )
        {
            goto deinitialize_manager;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "about to calculate %u raw reports", rawReportCount );

        // CALCULATE METRICS
        while( calculationManager->CalculateNextReport( calculationContext ) )
        { // void
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );

        MD_CHECK_PTR_RET_A( adapterId, m_concurrentGroup, CC_ERROR_GENERAL );
        MD_CHECK_PTR_RET_A( adapterId, out, CC_ERROR_INVALID_PARAMETER );

        if( outSize < m_concurrentGroup->GetParams()->IoMeasurementInformationCount )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG_A( adapterId, LOG_DEBUG, "outSize: %u", outSize );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        MD_CHECK_PTR_RET_A( adapterId, m_metricsCalculator, CC_ERROR_GENERAL );

        m_metricsCalculator->ReadIoMeasurementInformation( *m_concurrentGroup, out );
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

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        context.CommonCalculationContext.DeltaValues    = new( std::nothrow ) TTypedValue_1_0[m_currentParams->MetricsCount];
        context.CommonCalculationContext.Calculator     = m_metricsCalculator;
        context.CommonCalculationContext.MetricSet      = this;
        context.CommonCalculationContext.Out            = out;
        context.CommonCalculationContext.OutMaxValues   = outMaxValues;
        context.CommonCalculationContext.RawData        = rawData;
        context.CommonCalculationContext.RawReportCount = rawReportCount;
        MD_CHECK_PTR_RET_A( adapterId, context.CommonCalculationContext.DeltaValues, CC_ERROR_NO_MEMORY );
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

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
        MD_CHECK_PTR_RET_A( OBTAIN_ADAPTER_ID( m_device ), symbolName, false );

        for( uint32_t i = 0; i < m_params_1_0.InformationCount; i++ )
        {
            IInformation_1_0* information = GetInformation( i );
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
    //     CMetricsDevice* - metrics calculator or *nullptr* if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CMetricSet::GetMetricsDevice()
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
        const uint32_t  adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( ret == CC_OK )
        {
            m_params_1_0.AvailabilityEquation = GetCopiedCString( equationString, adapterId );
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

} // namespace MetricsDiscoveryInternal
