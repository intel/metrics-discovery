/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_concurrent_group.h

//     Abstract:   C++ Metrics Discovery internal concurrent group implementation

#include "md_concurrent_group.h"
#include "md_information.h"
#include "md_metric_set.h"

#include "md_calculation.h"
#include "md_driver_ifc.h"

#include <cstring>

//////////////////////////////////////////////////////////////////////////////
// Helper macro to get CustomMetricSetParams
//////////////////////////////////////////////////////////////////////////////
#define MD_CUSTOM_METRIC_SET_PARAMS( params, version ) ( params )->CustomMetricSetParams_##version

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     CConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device     - parent metrics device
    //     const char * name           - concurrent group name
    //     const char * description    - concurrent group description
    //     uint32_t measurementTypeMask - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup::CConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : m_isAvailabile( true )
        , m_semaphore( nullptr )
        , m_setsVector()
        , m_otherSetsList()
        , m_informationVector()
        , m_otherInformationVector()
        , m_informationCount( 0 )
        , m_device( device )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.SymbolName                    = GetCopiedCString( name, adapterId );
        m_params_1_0.Description                   = GetCopiedCString( description, adapterId );
        m_params_1_0.MeasurementTypeMask           = measurementTypeMask;
        m_params_1_0.MetricSetsCount               = 0;
        m_params_1_0.IoMeasurementInformationCount = 0;
        m_params_1_0.IoGpuContextInformationCount  = 0;

        m_setsVector.reserve( SETS_VECTOR_INCREASE );
        m_informationVector.reserve( INFORMATION_VECTOR_INCREASE );
        m_otherInformationVector.reserve( INFORMATION_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     CConcurrentGroup destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup::~CConcurrentGroup()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.Description );
        ClearVector( m_informationVector );
        ClearVector( m_otherInformationVector );
        ClearVector( m_setsVector );
        ClearList( m_otherSetsList );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns concurrent group params.
    //
    // Output:
    //     TConcurrentGroupParams_1_0*  - concurrent group params
    //
    //////////////////////////////////////////////////////////////////////////////
    TConcurrentGroupParams_1_0* CConcurrentGroup::GetParams( void )
    {
        return &m_params_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Wrapper function for adding custom metric sets with the given parameters.
    //
    // Input:
    //     TAddCustomMetricSetParams*  params               - params
    //     IMetricSetLatest*           referenceMetricSet   - (optional) metric set from which copy metrics and information
    //                                                         *IGNORED IN CConcurrentGroup*
    //     bool                        copyInformationOnly  - Copy information without metrics from reference set
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly /*= false*/ )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_device, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, params, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, referenceMetricSet, nullptr );

        IMetricSetLatest* set        = nullptr;
        TReportType       reportType = DEFAULT_METRIC_SET_REPORT_TYPE;

        if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSetsCount,
                nullptr,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_1 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_2 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType );
            }

            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_3 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ReportType );
            }

            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     FindSameMetricSetForPlatform
    //
    // Description:
    //     Finds MetricSet with the same symbol name matching the given platform mask.
    //     Used in adding custom metric sets with reference metric sets.
    //
    // Input:
    //     CMetricSet*         metricSet    - metrics set to look for
    //     TByteArrayLatest*   platformMask - platform mask
    //     uint32_t            gtMask       - gt mask
    //
    // Output:
    //     CMetricSet*                      - found metric set or input metric set
    //                                        if not found one with matching platform mask
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::FindSameMetricSetForPlatform( CMetricSet* metricSet, const TByteArrayLatest* platformMask, const uint32_t gtMask )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, metricSet, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, platformMask, nullptr );

        if( ComparePlatforms( metricSet->GetPlatformMask(), metricSet->GetParams()->GtMask, platformMask, gtMask, adapterId ) )
        {
            return metricSet;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "Cannot find metric set for specified platform. Metric set symbol name: %s", metricSet->GetParams()->SymbolName );

        for( auto& otherSet : m_otherSetsList )
        {
            const auto otherSetPlatformMask = otherSet->GetParams()->PlatformMask;
            const auto otherSetGtMask       = otherSet->GetParams()->GtMask;

            if( otherSet && ( strcmp( otherSet->GetParams()->SymbolName, metricSet->GetParams()->SymbolName ) == 0 ) && ComparePlatforms( otherSet->GetPlatformMask(), otherSet->GetParams()->GtMask, platformMask, gtMask, adapterId ) )
            {
                return otherSet;
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Adds custom metric set with the given parameters.
    //
    // Input:
    //     CMetricSet*        referenceMetricSet     - (optional) metric set from which inherit metrics and information
    //     const char*        signalName             - (optional) signal name with which metrics should be inherited
    //     const char*        symbolName             -
    //     const char*        shortName              -
    //     uint32_t           apiMask                -
    //     uint32_t           categoryMask           -
    //     TByteArrayLatest*  platformMask           -
    //     uint32_t           gtMask                 -
    //     uint32_t           rawReportSize          -
    //     uint32_t           queryReportSize        -
    //     uint32_t           complementarySetsCount -
    //     const char*        complementarySetsList  - comma separated copmlementary sets list
    //     TApiSpecificId_1_0 apiSpecificId          -
    //     TRegisterSet*      startRegSets           -
    //     uint32_t           startRegSetsCount      -
    //     const char*        availabilityEquation   -
    //     TReportType        reportType             -
    //     bool               copyInformationOnly    -
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName, const char* symbolName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, TByteArrayLatest* platformMask, uint32_t gtMask, uint32_t rawReportSize, uint32_t queryReportSize, const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets, uint32_t startRegSetsCount, const char* availabilityEquation, TReportType reportType, bool copyInformationOnly /*= false*/ )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );

        if( !AreMetricSetParamsValid( symbolName, shortName, platformMask, gtMask, startRegSets, startRegSetsCount ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "invalid custom metric set parameters" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        if( MatchingSetExists( symbolName, platformMask, gtMask ) )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "metric set already added: %s", symbolName );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        CMetricSet* refMetricSetMatchingPlatform = nullptr;
        CMetricSet* set                          = new( std::nothrow ) CMetricSet( m_device, this, symbolName, shortName, apiMask, categoryMask, rawReportSize, queryReportSize, reportType, platformMask, gtMask, true );
        MD_CHECK_PTR_RET_A( adapterId, set, nullptr );

        if( complementarySetsList != nullptr && ( set->AddComplementaryMetricSets( complementarySetsList ) != CC_OK ) )
        {
            goto customMetricSetCleanup;
        }

        if( set->SetApiSpecificId( apiSpecificId ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "error setting apiSpecificId" );
            goto customMetricSetCleanup;
        }

        refMetricSetMatchingPlatform = FindSameMetricSetForPlatform( referenceMetricSet, platformMask, gtMask );
        if( refMetricSetMatchingPlatform != nullptr && set->InheritFromMetricSet( refMetricSetMatchingPlatform, signalName, copyInformationOnly ) != CC_OK )
        {
            goto customMetricSetCleanup;
        }

        if( startRegSets && startRegSetsCount )
        {
            for( uint32_t i = 0; i < startRegSetsCount; i++ )
            {
                if( startRegSets[i].StartConfigRegs && startRegSets[i].StartConfigRegsCount )
                {
                    set->AddStartRegisterSet(
                        startRegSets[i].ConfigId,
                        startRegSets[i].ConfigPriority,
                        startRegSets[i].AvailabilityEquation,
                        startRegSets[i].ConfigType );

                    for( uint32_t j = 0; j < startRegSets[i].StartConfigRegsCount; j++ )
                    {
                        set->AddStartConfigRegister(
                            startRegSets[i].StartConfigRegs[j].offset,
                            startRegSets[i].StartConfigRegs[j].value,
                            startRegSets[i].StartConfigRegs[j].type );
                    }
                }
            }
        }
        set->RefreshConfigRegisters();

        if( set->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Error setting metric set equations" );
            goto customMetricSetCleanup;
        }

        if( m_device->IsPlatformTypeOf( platformMask, gtMask ) && set->IsAvailabilityEquationTrue() )
        {
            m_setsVector.push_back( set );
            m_params_1_0.MetricSetsCount = m_setsVector.size();
        }
        else
        {
            m_otherSetsList.push_back( set );
        }

        return set;

    customMetricSetCleanup:
        MD_SAFE_DELETE( set );
        MD_LOG_EXIT_A( adapterId );
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddMetricSet
    //
    // Description:
    //     Adds a new metric set to  the concurrent group.
    //
    // Input:
    //     const char *      symbolicName          -
    //     const char *      shortName             -
    //     uint32_t          apiMask               -
    //     TMetricCategory   category              - metric set category
    //     uint32_t          snapshotReportSize    -
    //     uint32_t          deltaReportSize       -
    //     TReportType       reportType            -
    //     const char *      availabilityEquation  -
    //     TByteArrayLatest* platformMask          -
    //     uint32_t          gtMask                -
    //     bool              isCustom              -
    //
    // Output:
    //     CMetricSet*  - pointer to the newly added metrics set
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, const char* availabilityEquation /*= nullptr*/, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
    {
        const uint32_t adapterId       = OBTAIN_ADAPTER_ID( m_device );
        CMetricSet*    alreadyAddedSet = nullptr;
        CMetricSet*    set             = new( std::nothrow ) CMetricSet( m_device, this, symbolicName, shortName, apiMask, categoryMask, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom );
        MD_CHECK_PTR_RET_A( adapterId, set, nullptr );

        if( set->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Error setting metric set equations" );
            MD_SAFE_DELETE( set );
            return nullptr;
        }

        bool isSuitablePlatform = m_device->IsPlatformTypeOf( platformMask, gtMask ) && set->IsAvailabilityEquationTrue();
        if( isSuitablePlatform )
        {
            // Check if metric set is already present in m_setsVector or m_otherSetsList.
            alreadyAddedSet = GetMatchingMetricSet( symbolicName, platformMask, gtMask, true );
            if( alreadyAddedSet != nullptr )
            {
                // If metric set present in m_setsVector it should be move to m_otherSetsList.
                // Metric set compared to alreadyAddedSet will be added in else section as unavailable on this platform.
                auto iterator = std::find( m_setsVector.begin(), m_setsVector.end(), alreadyAddedSet );
                if( iterator != m_setsVector.end() )
                {
                    MD_LOG_A( adapterId, LOG_WARNING, "Attempt to add metric set [%s] with the same name and true availability equation.", alreadyAddedSet->GetParams()->SymbolName );

                    m_setsVector.erase( iterator );
                    m_params_1_0.MetricSetsCount = m_setsVector.size();

                    m_otherSetsList.push_back( alreadyAddedSet );
                }
            }
        }

        if( isSuitablePlatform && alreadyAddedSet == nullptr )
        {
            m_setsVector.push_back( set );
            m_params_1_0.MetricSetsCount = m_setsVector.size();
            MD_LOG_A( adapterId, LOG_INFO, "%s - added", set->GetParams()->SymbolName );
        }
        else
        {
            MD_LOG_A( adapterId, LOG_INFO, "%s - not available", set->GetParams()->SymbolName );
            m_otherSetsList.push_back( set );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMetricSet
    //
    // Description:
    //     Returns the chosen metrics set or null if index doesn't exist.
    //
    // Input:
    //     uint32_t index    - index of a chosen metrics set
    //
    // Output:
    //     IMetricSetLatest* - chosen metrics set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::GetMetricSet( uint32_t index )
    {
        if( index < m_setsVector.size() )
        {
            return m_setsVector[index];
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     Lock
    //
    // Description:
    //     Creates a semaphore on the concurrent group. Waits 1s if needed.
    //     Adapter BDF numbers are added to the semaphore name so different
    //     adapters won't block each other.
    //
    // Output:
    //     TCompletionCode - *CC_OK* if succeeded,
    //                       *CC_CONCURRENT_GROUP_LOCKED* if timeout occurred
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::Lock()
    {
        // 1. Create semaphore name
        char semaphoreName[MD_SEMAPHORE_NAME_MAX_LENGTH] = {};

        TCompletionCode ret = FillLockSemaphoreName( semaphoreName, sizeof( semaphoreName ) );
        if( ret == CC_OK )
        {
            // 2. Get driver interface
            CDriverInterface& driverInterface = m_device->GetDriverInterface();

            // 3. Lock concurrent group
            ret = driverInterface.LockConcurrentGroup( semaphoreName, &m_semaphore );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     Unlock
    //
    // Description:
    //     Releases the semaphore created on concurrent group.
    //     Adapter BDF numbers are added to the semaphore name so different
    //     adapters won't block each other.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::Unlock()
    {
        // 1. Create semaphore name
        char semaphoreName[MD_SEMAPHORE_NAME_MAX_LENGTH] = {};

        TCompletionCode ret = FillLockSemaphoreName( semaphoreName, sizeof( semaphoreName ) );
        if( ret == CC_OK )
        {
            // 2. Get driver interface
            CDriverInterface& driverInterface = m_device->GetDriverInterface();

            // 3. Unlock concurrent group
            ret = driverInterface.UnlockConcurrentGroup( semaphoreName, &m_semaphore );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     WriteCConcurrentGroupToFile
    //
    // Description:
    //     Writes concurrent group to file.
    //
    // Input:
    //     FILE* metricFile    - handle to metric file file
    //
    // Output:
    //     TCompletionCode - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::WriteCConcurrentGroupToFile( FILE* metricFile )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.Description, metricFile, adapterId );
        fwrite( &m_params_1_0.MeasurementTypeMask, sizeof( m_params_1_0.MeasurementTypeMask ), 1, metricFile );

        // m_setsVector & m_otherSetsList
        uint32_t count = GetCustomSetCount();
        fwrite( &count, sizeof( count ), 1, metricFile );

        for( auto& metricSet : m_setsVector )
        {
            if( metricSet->IsCustom() )
            {
                metricSet->WriteCMetricSetToFile( metricFile );
            }
        }

        for( auto& otherMetricSet : m_otherSetsList )
        {
            if( otherMetricSet->IsCustom() )
            {
                otherMetricSet->WriteCMetricSetToFile( metricFile );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     MatchingSetExists
    //
    // Description:
    //     Checks if metric set of the given name, platform and gt is already added to the concurrent group.
    //
    // Input:
    //     const char*           symbolicName   - symbolic name of a metric set to check
    //     TByteArrayLatest*     platformMask   - platform Id bit mask indicates platforms compatible with set.
    //     uint32_t              gtMask         - gt type bit mask indicates platform versions compatible with set.
    //
    // Output:
    //     bool                                 - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CConcurrentGroup::MatchingSetExists( const char* symbolName, TByteArrayLatest* platformMask, uint32_t gtMask )
    {
        return GetMatchingMetricSet( symbolName, platformMask, gtMask ) != nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AreMetricSetParamsValid
    //
    // Description:
    //     Checks the correctness of the given metricSet parameters.
    //
    // Input:
    //     const char*         symbolName        -
    //     const char*         shortName         -
    //     TByteArrayLatest*   platformMask      -
    //     uint32_t            gtMask            -
    //     TRegisterSet*       startRegSets      -
    //     uint32_t            startRegSetsCount -
    //
    // Output:
    //     bool                - true if valid
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CConcurrentGroup::AreMetricSetParamsValid( const char* symbolName, const char* shortName, TByteArrayLatest* platformMask, uint32_t gtMask, TRegisterSet* startRegSets, uint32_t startRegSetsCount )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();
        const uint32_t    platformIndex   = m_device->GetPlatformIndex();
        const uint32_t    adapterId       = OBTAIN_ADAPTER_ID( m_device );

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
        if( ( platformMask == nullptr ) || ( platformMask->Size == 0 ) || ( platformMask->Data == nullptr ) )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, platformMask );
            return false;
        }
        if( gtMask == 0 )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, gtMask );
            return false;
        }
        if( startRegSetsCount > 0 && startRegSets == nullptr )
        {
            MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, startRegSets );
            return false;
        }

        for( uint32_t i = 0; i < startRegSetsCount; i++ )
        {
            if( startRegSets[i].StartConfigRegsCount > 0 )
            {
                if( startRegSets[i].StartConfigRegs == nullptr )
                {
                    MD_LOG_INVALID_PARAMETER_A( adapterId, LOG_ERROR, startRegSets[i].StartConfigRegs );
                    return false;
                }

                // Validate registers for every platform in the mask
                for( uint32_t platform = 0; i < platformMask->Size * MD_BYTE; ++i )
                {
                    if( platformIndex == platform )
                    {
                        MD_LOG_A( adapterId, LOG_DEBUG, "validating register offsets for platform index: %u", platform );
                        if( driverInterface.ValidatePmRegsConfig( startRegSets[i].StartConfigRegs, startRegSets[i].StartConfigRegsCount, platform ) != CC_OK )
                        {
                            MD_LOG_A( adapterId, LOG_ERROR, "invalid start register offsets for platform: %u", platform );
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetCustomSetCount
    //
    // Description:
    //     Returns number of custom sets + default sets with custom metrics.
    //
    // Output:
    //     uint32_t - custom set count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CConcurrentGroup::GetCustomSetCount()
    {
        uint32_t customSetCount = 0;

        for( auto& metricSet : m_setsVector )
        {
            if( metricSet->IsCustom() )
            {
                customSetCount++;
            }
        }

        for( auto& metricSet : m_otherSetsList )
        {
            if( metricSet->IsCustom() )
            {
                customSetCount++;
            }
        }

        return customSetCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     FillLockSemaphoreName
    //
    // Description:
    //     Creates semaphore name for the need of lock / unlock concurrent group
    //     calls. Adapter BDF numbers are added to the name so different adapters
    //     won't block each other.
    //
    // Input:
    //     char*  name - buffer for the name
    //     size_t size - size of the name buffer
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::FillLockSemaphoreName( char* name, size_t size )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_ASSERT_A( adapterId, name != nullptr );

        // Create a semaphore name: "<CcgSymbolName>_<BusNumber>_<DeviceNumber>_<FunctionNumber>"
        const TAdapterParams_1_9* adapterParams = m_device->GetAdapter().GetParams();
        MD_CHECK_PTR_RET_A( adapterId, adapterParams, CC_ERROR_GENERAL );

        int32_t neededSize = snprintf( name, size, "%s_%u_%u_%u", m_params_1_0.SymbolName, adapterParams->BusNumber, adapterParams->DeviceNumber, adapterParams->FunctionNumber );

        // If snprintf failed or buffer size was too small
        if( neededSize < 0 || neededSize >= (int32_t) size )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMatchingMetricSet
    //
    // Description:
    //     Looks through concurrent group for an already added metric set with
    //     a given name, platform and gt. Returns pointer to a found metric set or
    //     null if it doesn't exist.
    //
    // Input:
    //     const char*       symbolName                       - name of a metric set to look for
    //     TByteArrayLatest* platformMask                     - platform Id bit mask indicates platforms compatible with set.
    //     uint32_t          gtMask                           - gt type bit mask indicates platform versions compatible with set.
    //     bool              findWithTrueAvailabilityEquation - check if availability equation of set contained in m_otherSetsList is true.
    // Output:
    //     CMetricSet*                                        - found metric set or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::GetMatchingMetricSet( const char* symbolName, TByteArrayLatest* platformMask, uint32_t gtMask, bool findWithTrueAvailabilityEquation /* = false */ )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, symbolName, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, platformMask, nullptr );

        // List of available sets
        for( auto& metricSet : m_setsVector )
        {
            auto setParams = metricSet ? metricSet->GetParams() : nullptr;

            if( setParams && ( strcmp( symbolName, setParams->SymbolName ) == 0 ) )
            {
                if( m_device->IsPlatformTypeOf( platformMask, gtMask ) )
                {
                    return metricSet;
                }
            }
        }

        // List of unavailable sets for current platform
        for( auto& otherMetricSet : m_otherSetsList )
        {
            auto setParams = otherMetricSet ? otherMetricSet->GetParams() : nullptr;

            if( setParams && strcmp( symbolName, setParams->SymbolName ) == 0 )
            {
                if( ComparePlatforms( platformMask, gtMask, otherMetricSet->GetPlatformMask(), setParams->GtMask, adapterId ) )
                {
                    if( findWithTrueAvailabilityEquation && !otherMetricSet->IsAvailabilityEquationTrue() )
                    {
                        continue;
                    }

                    return otherMetricSet;
                }
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
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
    IInformation_1_0* CConcurrentGroup::GetInformation( uint32_t index )
    {
        if( index < m_informationVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_informationVector[index] );
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetInformationCount
    //
    // Description:
    //     Returns number of Information objects in concurrent group
    //
    // Output:
    //     uint32_t - number of information objects
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CConcurrentGroup::GetInformationCount()
    {
        return m_informationCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMetricsDevice
    //
    // Description:
    //     Returns metrics device.
    //
    // Output:
    //     CMetricsDevice* - a pointer to a metrics device object.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CConcurrentGroup::GetMetricsDevice()
    {
        return m_device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device             - parent metrics device
    //     const char * name                   - concurrent group name
    //     const char * description            - concurrent group description
    //     uint32_t     measurementTypeMask    -
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::COAConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : CConcurrentGroup( device, name, description, measurementTypeMask )
        , m_streamType( STREAM_TYPE_OA )
        , m_ioMetricSet( nullptr )
        , m_contextTagsEnabled( false )
        , m_processId( 0 )
        , m_streamEventHandle( nullptr )
        , m_ioMeasurementInfoVector()
        , m_ioGpuContextInfoVector()
    {
        AddIoMeasurementInfoPredefined();

        m_ioMeasurementInfoVector.reserve( EXCEPTIONS_VECTOR_INCREASE );
        m_ioGpuContextInfoVector.reserve( GPU_CONTEXTS_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::~COAConcurrentGroup()
    {
        if( m_ioMetricSet )
        {
            CloseIoStream();
        }

        ClearVector( m_ioMeasurementInfoVector );
        ClearVector( m_ioGpuContextInfoVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Wrapper function for adding custom metric sets with the given parameters.
    //
    // Input:
    //     TAddCustomMetricSetParams*  params               - params
    //     IMetricSetLatest*           referenceMetricSet   - (optional) metric set from which copy metrics and information
    //     bool                        copyInformationOnly  - Copy information without metrics from reference set
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* COAConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly /*= false*/ )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_device, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, params, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, referenceMetricSet, nullptr );

        IMetricSetLatest* set        = nullptr;
        TReportType       reportType = DEFAULT_METRIC_SET_REPORT_TYPE;

        if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSetsCount,
                nullptr,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_1 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_2 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType );
            }

            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_3 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType );
            }

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoStreamSamplingType
    //
    // Description:
    //     Sets stream sampling type. OA and BB (batch buffer) supported.
    //
    // Input:
    //     TSamplingType type - requested IO Stream Sampling Type
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::SetIoStreamSamplingType( TSamplingType type )
    {
        const uint32_t  adapterId     = OBTAIN_ADAPTER_ID( m_device );
        TStreamType     newStreamType = STREAM_TYPE_OA;
        TCompletionCode ret           = CC_OK;
        MD_LOG_ENTER_A( adapterId );
        switch( type )
        {
            case SAMPLING_TYPE_OA_TIMER:
                newStreamType = STREAM_TYPE_OA;
                break;
            case SAMPLING_TYPE_DMA_BUFFER:
                newStreamType = STREAM_TYPE_BB;
                break;
            default:
                ret = CC_ERROR_NOT_SUPPORTED;
        }
        if( ret == CC_OK && newStreamType != m_streamType )
        {
            // change is disallowed if stream is already opened
            if( m_ioMetricSet != nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Failed to set IoStream sampling type" );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                m_streamType = newStreamType;
                MD_LOG_A( adapterId, LOG_DEBUG, "Stream type changed to: %u", m_streamType );
            }
        }
        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Opens IO Stream for given metric set.
    //     (Enables Timer Mode and opens Counter Stream)
    //
    // Input:
    //     IMetricSet_1_0*      metricSet           - metric set
    //     uint32_t             processId           - PID of the measured app (0 is global context)
    //     uint32_t*            nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t*            oaBufferSize        - (in/out) requested/set OA Buffer size in bytes
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, oaBufferSize, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.OpenIoStream( m_streamType, *m_device, static_cast<CMetricSet*>( metricSet ), m_params_1_0.SymbolName, processId, nsTimerPeriod, oaBufferSize, &m_streamEventHandle );
        if( ret != CC_OK )
        {
            MD_LOG_EXIT_A( adapterId );
            return ret;
        }
        MD_LOG_A( adapterId, LOG_DEBUG, "Stream opened using type: %u", m_streamType );

        m_ioMetricSet          = static_cast<CMetricSet*>( metricSet );
        m_processId            = processId;
        m_contextTagsEnabled   = m_ioMetricSet->HasInformation( "ContextId" );
        CMetricsCalculator* mc = m_ioMetricSet->GetMetricsCalculator();
        // In case of stream reopen
        ClearVector( m_ioGpuContextInfoVector );
        m_params_1_0.IoGpuContextInformationCount = 0;
        if( mc != nullptr )
        {
            mc->DiscardSavedReport();
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    //     data was read. Additionally, at the end of ReadIoStream GpuContextIds are read and updated.
    //
    // Input:
    //     uint32_t        reportCount - (in/out) requested number of reports to read / reports read from the stream
    //     char*           reportData  - (out) pointer to the read data
    //     uint32_t        readFlags   - read flags (see TIoReadFlag enum), 0 is ok
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_CHECK_PTR_RET_A( adapterId, reportData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, reportCount, CC_ERROR_INVALID_PARAMETER );
        if( m_ioMetricSet == nullptr )
        {
            *reportCount = 0;
            MD_LOG_A( adapterId, LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }
        if( *reportCount == 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "0 reports to read" );
            return CC_OK;
        }

        TCompletionCode                 ret             = CC_OK;
        CDriverInterface&               driverInterface = m_device->GetDriverInterface();
        uint32_t                        frequency       = 0;
        GTDIReadCounterStreamExceptions exceptions      = {};

        ret = driverInterface.ReadIoStream( m_streamType, *m_device, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
        if( ret == CC_OK || ret == CC_READ_PENDING )
        {
            driverInterface.HandleIoStreamExceptions( m_params_1_0.SymbolName, m_ioMetricSet, m_processId, reportCount, &exceptions );

            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW, exceptions.BufferOverflow, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERRUN, exceptions.BufferOverrun, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW, exceptions.CountersOverflow, &index );

            m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector.size();
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes IO Stream.
    //     (Closes Counter Stream and disables Timer Mode)
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::CloseIoStream( void )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );
        if( m_ioMetricSet == nullptr )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "stream not opened" );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.CloseIoStream( m_streamType, *m_device, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
        if( ret != CC_OK )
        {
            MD_LOG_EXIT_A( adapterId );
            return ret;
        }

        // m_processId is not cleared after close to define if context filtering was used.
        // Stream reopen will override m_processId
        m_ioMetricSet = nullptr;
        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     WaitForReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     uint32_t     milliseconds   - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::WaitForReports( uint32_t milliseconds )
    {
        TCompletionCode   retVal          = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        retVal = driverInterface.WaitForIoStreamReports( m_streamType, *m_device, milliseconds, m_streamEventHandle );

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoMeasurementInformation
    //
    // Description:
    //     Returns measurement information of given index. Measurement information values
    //     are set after successful ReadIoStream.
    //
    // Input:
    //     uint32_t     index  - index of the measurement information
    //
    // Output:
    //     IInformation_1_0*   - measurement information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoMeasurementInformation( uint32_t index )
    {
        if( m_params_1_0.IoMeasurementInformationCount != 0 && index < m_ioMeasurementInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioMeasurementInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoGpuContextInformation
    //
    // Description:
    //     Returns GPU context id information of given index. GPU context id information values
    //     are set after successful ReadIoStream if IO_READ_FLAG_GET_CONTEXT_ID_TAGS was set.
    //
    // Input:
    //     uint32_t     index  - index of the GPU context information
    //
    // Output:
    //     IInformation_1_0*   - GPU context information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoGpuContextInformation( uint32_t index )
    {
        if( m_params_1_0.IoGpuContextInformationCount != 0 && index < m_ioGpuContextInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioGpuContextInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddAllIoMeasurementInformation
    //
    // Description:
    //     Adds exceptions from GTDIReadCounterStreamExceptions struct and Frequency from
    //     GTDIReadCounterStreamExtOut struct.
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::AddIoMeasurementInfoPredefined( void )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ ) )
        {
            AddIoMeasurementInformation( "CoreFrequencyMHz", "Core Frequency in MHz", "The last core frequency in the measurement.", "Report Meta Data", INFORMATION_TYPE_VALUE, "megahertz" );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED ) )
        {
            AddIoMeasurementInformation( "FrequencyChanged", "Core Frequency Changed", "The flag indicating that core frequency has changed.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID ) )
        {
            AddIoMeasurementInformation( "FrequencyChangedInvalid", "Core Frequency Changed Invalid", "The flag indicating inability to report freq change due to delayed read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN ) )
        {
            AddIoMeasurementInformation( "SliceShutdown", "Slice Shutdown Occurred", "The flag indicating that the Slice Shutdown has occurred.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_REPORT_LOST ) )
        {
            AddIoMeasurementInformation( "ReportLost", "Report Lost reported by HW", "The flag indicating that some samples were lost since last Read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_DATA_OUTSTANDING ) )
        {
            AddIoMeasurementInformation( "DataOutstanding", "Data Outstanding", "The flag indicating that there are still some outstanding data.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "BufferOverflow", "Buffer Overflow", "The flag indicating that some reports have been overwritten.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERRUN ) )
        {
            AddIoMeasurementInformation( "BufferOverrun", "Buffer Overrun", "The flag indicating that the buffer is full (n-1 reports).", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "CountersOverflow", "Counters Overflow", "The flag indicating that counters overflows occurred between two consecutive readings.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoMeasurementInformation
    //
    // Description:
    //     Adds new measurement information to the *m_ioMeasurementInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation. To set use SetInformationValue() from CInformation class.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added measurement information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        const uint32_t adapterId       = OBTAIN_ADAPTER_ID( m_device );
        CInformation*  measurementInfo = new( std::nothrow ) CInformation( m_device, m_ioMeasurementInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | API_TYPE_BBSTREAM, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, measurementInfo, nullptr );

        measurementInfo->SetSnapshotReportReadEquation( "" );
        measurementInfo->SetDeltaReportReadEquation( "" );

        m_ioMeasurementInfoVector.push_back( measurementInfo );
        return measurementInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoGpuContextInformation
    //
    // Description:
    //     Adds new GPU context information to the *m_ioGpuContextInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added GPU context information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        const uint32_t adapterId      = OBTAIN_ADAPTER_ID( m_device );
        CInformation*  gpuContextInfo = new( std::nothrow ) CInformation( m_device, m_ioGpuContextInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | 0x0, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, gpuContextInfo, nullptr );

        gpuContextInfo->SetSnapshotReportReadEquation( "" );
        gpuContextInfo->SetDeltaReportReadEquation( "" );

        m_ioGpuContextInfoVector.push_back( gpuContextInfo );
        return gpuContextInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoMeasurementInfoPredefined
    //
    // Description:
    //     Sets value of the previously defined IoMeasurementInformation identified by
    //     the given type.
    //     Used indices should be in sync with AddIoMeasurementInfoPredefined() (right order).
    //
    // Input:
    //     TIoMeasurementInfoType ioMeasurementInfoType - IO measurement information type
    //     uint32_t               value                 - value to set
    //     uint32_t*              index                 - IO measurement information index (should be in sync with AddIoMeasurementInfoPredefined())
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::SetIoMeasurementInfoPredefined( TIoMeasurementInfoType ioMeasurementInfoType, uint32_t value, uint32_t* index )
    {
        if( !index || *index >= m_ioMeasurementInfoVector.size() )
        {
            return;
        }

        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        // Set information if available
        if( driverInterface.IsIoMeasurementInfoAvailable( ioMeasurementInfoType ) )
        {
            m_ioMeasurementInfoVector[( *index )++]->SetInformationValue( value, EQUATION_IO_READ );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     CPerfMonConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device             - parent metrics device
    //     const char * name                   - concurrent group name
    //     const char * description            - concurrent group description
    //     uint32_t     measurementTypeMask    -
    //
    //////////////////////////////////////////////////////////////////////////////
    CPerfMonConcurrentGroup::CPerfMonConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Opens IO Stream for given metric set.
    //     (Enables Timer Mode and opens Counter Stream)
    //
    // Input:
    //     IMetricSet_1_0*      metricSet           - metric set
    //     uint32_t             processId           - PID of the measured app (0 is global context)
    //     uint32_t*            nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t*            sysBufferSize       - (in/out) requested/set Sys Buffer size in bytes
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* sysBufferSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, sysBufferSize, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.OpenIoStream( STREAM_TYPE_SYS, *m_device, static_cast<CMetricSet*>( metricSet ), m_params_1_0.SymbolName, processId, nsTimerPeriod, sysBufferSize, &m_streamEventHandle );
        if( ret != CC_OK )
        {
            return ret;
        }

        m_ioMetricSet = static_cast<CMetricSet*>( metricSet );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    //     data was read.
    //
    // Input:
    //     uint32_t            reportCount - (in/out) requested number of reports to read / reports read from the stream
    //     char*               reportData  - (out) pointer to the read data
    //     uint32_t            readFlags   - read flags (see TIoReadFlag enum), 0 is ok
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, reportData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, reportCount, CC_ERROR_INVALID_PARAMETER );
        if( m_ioMetricSet == nullptr )
        {
            *reportCount = 0;
            MD_LOG_A( m_device->GetAdapter().GetAdapterId(), LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode                 ret             = CC_OK;
        uint32_t                        frequency       = 0;
        GTDIReadCounterStreamExceptions exceptions      = {};
        CDriverInterface&               driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.ReadIoStream( STREAM_TYPE_SYS, *m_device, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
        if( ret == CC_OK || ret == CC_READ_PENDING )
        {
            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW, exceptions.BufferOverflow, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERRUN, exceptions.BufferOverrun, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW, exceptions.CountersOverflow, &index );

            m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector.size();
        }
        else
        {
            m_params_1_0.IoMeasurementInformationCount = 0;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes IO Stream.
    //     (Closes Counter Stream and disables Timer Mode)
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::CloseIoStream()
    {
        if( m_ioMetricSet == nullptr )
        {
            MD_LOG_A( m_device->GetAdapter().GetAdapterId(), LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.CloseIoStream( STREAM_TYPE_SYS, *m_device, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
        if( ret != CC_OK )
        {
            return ret;
        }

        m_ioMetricSet = nullptr;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     WaitForReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     uint32_t     milliseconds   - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::WaitForReports( uint32_t milliseconds )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        return driverInterface.WaitForIoStreamReports( STREAM_TYPE_SYS, *m_device, milliseconds, m_streamEventHandle );
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
    CInformation* CConcurrentGroup::AddInformation( CInformation* information )
    {
        m_informationVector.push_back( information );
        m_informationCount = m_informationVector.size();

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
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
    CInformation* CConcurrentGroup::AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId )
    {
        CInformation* information = new( std::nothrow ) CInformation( m_device, informationXmlId, symbolName, shortName, longName, groupName, apiMask, informationType, informationUnits );
        MD_CHECK_PTR_RET_A( OBTAIN_ADAPTER_ID( m_device ), information, nullptr );

        if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( information );
            return nullptr;
        }

        if( information->IsAvailabilityEquationTrue() )
        {
            uint32_t count = m_informationVector.size();
            information->SetIdInSetParam( count );
            m_informationVector.push_back( information );
            m_informationCount = count + 1;
        }
        else
        {
            m_otherInformationVector.push_back( information );
        }

        return information;
    }
} // namespace MetricsDiscoveryInternal
