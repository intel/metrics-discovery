/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_concurrent_group.cpp

//     Abstract:   C++ Metrics Discovery internal concurrent group implementation

#include "md_concurrent_group.h"
#include "md_information.h"
#include "md_driver_ifc.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{
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
    //     TConcurrentGroupParamsLatest*  - concurrent group params
    //
    //////////////////////////////////////////////////////////////////////////////
    TConcurrentGroupParamsLatest* CConcurrentGroup::GetParams( void )
    {
        return &m_params;
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
    //     CConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice* device              - parent metrics device
    //     const char*     name                - concurrent group name
    //     const char*     description         - concurrent group description
    //     const uint32_t  measurementTypeMask - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup::CConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, const uint32_t measurementTypeMask )
        : m_params{}
        , m_semaphore( nullptr )
        , m_setsVector()
        , m_otherSetsList()
        , m_informationVector()
        , m_otherInformationVector()
        , m_informationCount( 0 )
        , m_device( device )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_params.SymbolName                    = GetCopiedCString( name, adapterId );
        m_params.Description                   = GetCopiedCString( description, adapterId );
        m_params.MeasurementTypeMask           = measurementTypeMask;
        m_params.MetricSetsCount               = 0;
        m_params.IoMeasurementInformationCount = 0;
        m_params.IoGpuContextInformationCount  = 0;
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
        MD_SAFE_DELETE_ARRAY( m_params.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params.Description );
        ClearVector( m_setsVector );
        ClearList( m_otherSetsList );

        ClearVector( m_informationVector );
        ClearVector( m_otherInformationVector );
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
    //     uint32_t          categoryMask          -
    //     uint32_t          snapshotReportSize    -
    //     uint32_t          deltaReportSize       -
    //     TReportType       reportType            -
    //     TByteArrayLatest* platformMask          -
    //     const char*       availabilityEquation  -
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
                    m_params.MetricSetsCount = m_setsVector.size();

                    m_otherSetsList.push_back( alreadyAddedSet );
                }
            }
        }

        if( isSuitablePlatform && alreadyAddedSet == nullptr )
        {
            m_setsVector.push_back( set );
            m_params.MetricSetsCount = m_setsVector.size();
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
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. Null if failed.
    //
    // Input:
    //     const char*      symbolicName           -
    //     const char*      shortName              -
    //     const char*      longName               -
    //     const char*      groupName              -
    //     uint32_t         apiMask                -
    //     TInformationType informationType        -
    //     const char*      informationUnits       -
    //     const char*      availabilityEquation   -
    //     uint32_t         informationXmlId       -
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

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the concurrent group. nullptr if failed.
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
    //     GetInformation
    //
    // Description:
    //     Returns the chosen information or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t index      - index of an information
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
    //     FILE* metricFile - handle to metric file file
    //
    // Output:
    //     TCompletionCode  - result of operation
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

        // m_params
        WriteCStringToFile( m_params.SymbolName, metricFile, adapterId );
        WriteCStringToFile( m_params.Description, metricFile, adapterId );
        fwrite( &m_params.MeasurementTypeMask, sizeof( m_params.MeasurementTypeMask ), 1, metricFile );

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
    //     const char*        complementarySetsList  - comma separated copmlementary sets list
    //     TApiSpecificId_1_0 apiSpecificId          -
    //     TRegisterSet*      startRegSets           -
    //     uint32_t           startRegSetsCount      -
    //     const char*        availabilityEquation   -
    //     TReportType        reportType             -
    //     bool               copyInformationOnly    -
    //
    // Output:
    //     IMetricSetLatest*                         - added metric set
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
            m_params.MetricSetsCount = m_setsVector.size();
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
    //     bool - true if valid
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
    //     char*  name     - buffer for the name
    //     size_t size     - size of the name buffer
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

        int32_t neededSize = snprintf( name, size, "%s_%u_%u_%u", m_params.SymbolName, adapterParams->BusNumber, adapterParams->DeviceNumber, adapterParams->FunctionNumber );

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
            if( otherSet && ( strcmp( otherSet->GetParams()->SymbolName, metricSet->GetParams()->SymbolName ) == 0 ) && ComparePlatforms( otherSet->GetPlatformMask(), otherSet->GetParams()->GtMask, platformMask, gtMask, adapterId ) )
            {
                return otherSet;
            }
        }

        return nullptr;
    }
} // namespace MetricsDiscoveryInternal
