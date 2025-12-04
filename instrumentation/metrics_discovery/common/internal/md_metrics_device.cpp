/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_device.cpp

//     Abstract:   C++ Metrics Discovery internal metrics device implementation

#include "md_metrics_device.h"
#include "md_adapter.h"
#include "md_concurrent_group.h"
#include "md_oa_concurrent_group.h"
#include "md_oam_concurrent_group.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"
#include "md_override.h"
#include "md_utils.h"

#include "md_driver_ifc.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     CMetricsDevice constructor
    //
    // Description:
    //     Constructor. Sends DeviceInfoParam escape.
    //
    // Input:
    //     CAdapter&         adapter         - parent adapter object
    //     CDriverInterface& driverInterface - driver interface tied to the device
    //     const uint32_t    subDeviceIndex  - sub device index (0 by default)
    //     const bool        isOffline       - offline mode flag (false by default)
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice::CMetricsDevice( CAdapter& adapter, CDriverInterface& driverInterface, const uint32_t subDeviceIndex /* = 0 */, const bool isOffline /* = false */ )
        : m_params{}
        , m_groupsVector()
        , m_overridesVector()
        , m_adapter( adapter )
        , m_driverInterface( driverInterface )
        , m_symbolSet( *this, driverInterface )
        , m_streamId( -1 )
        , m_streamConfigId( -1 )
        , m_streamBuffer()
        , m_subDeviceIndex( subDeviceIndex )
        , m_platformIndex( 0 )
        , m_gtType( GT_TYPE_UNKNOWN )
        , m_isOpenedFromFile( false )
        , m_isOffline( isOffline )
        , m_referenceCounter( 0 )
        , m_oaBufferMask( m_isOffline ? GTDI_OA_BUFFER_MASK_ALL : GTDI_OA_BUFFER_MASK_NONE )
        , m_queryModeRequested( QUERY_MODE_NONE )
        , m_queryModeDefault( m_driverInterface.GetQueryModeOverride() )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        if( !m_isOffline )
        {
            GTDIDeviceInfoParamExtOut out = {};

            if( m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, out, *this ) == CC_OK )
            {
                m_platformIndex = out.ValueUint32;
                MD_LOG_A( adapterId, LOG_INFO, "Metrics device platform index: %u", m_platformIndex );
            }
            if( m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GT_TYPE, out, *this ) == CC_OK )
            {
                m_gtType = static_cast<TGTType>( 1 << out.ValueUint32 );
                MD_LOG_A( adapterId, LOG_INFO, "GT_TYPE is %u", m_gtType );
            }

            if( m_symbolSet.DetectMaxSlicesInfo() != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Cannot detect max slices, subslices per slice or dual subslices per slice" );
            }

            m_params.DeviceName = GetCopiedCString( m_adapter.GetParams()->ShortName, adapterId );
        }
        else
        {
            m_gtType            = GT_TYPE_ALL;
            m_params.DeviceName = GetCopiedCString( "Offline Metrics Device", adapterId );
        }

        m_params.DeltaFunctionsCount       = DELTA_FUNCTION_LAST_1_0;
        m_params.EquationOperationsCount   = EQUATION_OPER_LAST_1_0;
        m_params.EquationElementTypesCount = EQUATION_ELEM_LAST_1_0;

        m_params.Version.MajorNumber = MD_API_MAJOR_NUMBER_CURRENT;
        m_params.Version.MinorNumber = MD_API_MINOR_NUMBER_CURRENT;
        m_params.Version.BuildNumber = MD_API_BUILD_NUMBER_CURRENT;

        m_params.GlobalSymbolsCount = m_symbolSet.GetSymbolCount();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     CMetricsDevice destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice::~CMetricsDevice()
    {
        MD_SAFE_DELETE_ARRAY( m_params.DeviceName );

        ClearVector( m_groupsVector );
        ClearVector( m_overridesVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns metrics device params.
    //
    // Output:
    //     TMetricsDeviceParams_1_0*  - pointer to metrics device params
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricsDeviceParams_1_2* CMetricsDevice::GetParams( void )
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetConcurrentGroup
    //
    // Description:
    //     Returns chosen concurrent group or null if not exists.
    //
    // Input:
    //     uint32_t index          - index of concurrent group
    //
    // Output:
    //     IConcurrentGroupLatest* - pointer to concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    IConcurrentGroupLatest* CMetricsDevice::GetConcurrentGroup( uint32_t index )
    {
        return ( index < m_groupsVector.size() )
            ? m_groupsVector[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetGlobalSymbol
    //
    // Description:
    //     Returns chosen global symbol or null if not exists.
    //
    // Input:
    //     uint32_t index       - index of global symbol
    //
    // Output:
    //     TGlobalSymbolLatest* - pointer to global symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbolLatest* CMetricsDevice::GetGlobalSymbol( uint32_t index )
    {
        TGlobalSymbol* symbol = m_symbolSet.GetSymbol( index );

        if( symbol )
        {
            // Redetect global symbol if dynamic.
            const TCompletionCode result = m_symbolSet.RedetectSymbol( symbol->symbol.SymbolName );

            if( result == CC_OK )
            {
                return &( symbol->symbol );
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetGlobalSymbolValueByName
    //
    // Description:
    //     Returns chosen global symbol by name or null if not exists.
    //
    // Input:
    //     const char * name   - name of global symbol
    //
    // Output:
    //     TTypedValue_1_0*    - pointer to global symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0* CMetricsDevice::GetGlobalSymbolValueByName( const char* name )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, name, nullptr );

        TGlobalSymbol* symbol = m_symbolSet.GetSymbolByName( name );

        if( symbol )
        {
            // Redetect global symbol if dynamic.
            const TCompletionCode result = m_symbolSet.RedetectSymbol( symbol->symbol.SymbolName );

            if( result == CC_OK )
            {
                return &( symbol->symbol.SymbolTypedValue );
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetLastError
    //
    // Description:
    //     Returns last error from enum TCompletionCode.
    //
    // Output:
    //     TCompletionCode - last error from enum
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetLastError()
    {
        return CC_LAST_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetCpuGpuTimestamps
    //
    // Description:
    //     Retrieves both GPU and CPU timestamp at the same time.
    //
    // Input:
    //     uint64_t* gpuTimestampNs         - (out) GPU timestamp in ns
    //     uint64_t* cpuTimestampNs         - (out) CPU timestamp in ns
    //     uint32_t* cpuId                  - (out) CPU id
    //     uint64_t* correlationIndicatorNs - (out) correlation indicator in ns
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId, uint64_t* correlationIndicatorNs )
    {
        if( !gpuTimestampNs && !cpuTimestampNs )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        uint64_t        gpuTS = 0, cpuTS = 0, correlationIndicator = 0;
        uint32_t        cpuID = 0;
        TCompletionCode ret   = m_driverInterface.GetGpuCpuTimestamps( *this, gpuTS, cpuTS, cpuID, correlationIndicator );

        if( ret == CC_OK )
        {
            if( gpuTimestampNs )
            {
                *gpuTimestampNs = gpuTS;
            }
            if( cpuTimestampNs )
            {
                *cpuTimestampNs = cpuTS;
            }
            if( cpuId )
            {
                *cpuId = cpuID;
            }
            if( correlationIndicatorNs )
            {
                *correlationIndicatorNs = correlationIndicator;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetCpuGpuTimestamps
    //
    // Description:
    //     Retrieves both GPU and CPU timestamp at the same time.
    //
    // Input:
    //     uint64_t* gpuTimestampNs - (out) GPU timestamp in ns
    //     uint64_t* cpuTimestampNs - (out) CPU timestamp in ns
    //     uint32_t* cpuId          - (out) CPU id
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId )
    {
        return GetGpuCpuTimestamps( gpuTimestampNs, cpuTimestampNs, cpuId, nullptr );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetOverride
    //
    // Description:
    //     Returns the chosen override object or null if index doesn't exist.
    //
    // Input:
    //     uint32_t index - index of an override
    //
    // Output:
    //     IOverride_1_2* - chosen override object or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::GetOverride( uint32_t index )
    {
        return ( index < m_overridesVector.size() )
            ? m_overridesVector[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetOverrideByName
    //
    // Description:
    //     Returns the chosen override object or nullptr if index doesn't exist.
    //
    // Input:
    //     const char* symbolName - name of an override
    //
    // Output:
    //     IOverride_1_2* - chosen override object or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::GetOverrideByName( const char* symbolName )
    {
        MD_CHECK_PTR_RET_A( m_adapter.GetAdapterId(), symbolName, nullptr );

        for( auto& override : m_overridesVector )
        {
            if( override && ( strcmp( symbolName, override->GetParams()->SymbolName ) == 0 ) )
            {
                return override;
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddConcurrentGroup
    //
    // Description:
    //     Adds concurrent group to the metrics device.
    //
    // Input:
    //     const char*       symbolicName        - concurrent group name
    //     const char*       shortName           - concurrent group short name
    //     TByteArrayLatest* platformMask        - platform mask
    //     const uint32_t    measurementTypeMask - measurement type mask
    //
    // Output:
    //     bool&             isSupported         - true if concurrent group is supported on given platform
    //     CConcurrentGroup*                     - pointer to newly created concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup* CMetricsDevice::AddConcurrentGroup( const char* symbolicName, const char* shortName, const uint32_t measurementTypeMask, TByteArrayLatest* platformMask, bool& isSupported )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        CConcurrentGroup* group = nullptr;
        isSupported             = true;

        if( !IsPlatformPresentInMask( platformMask, m_platformIndex, adapterId ) )
        {
            isSupported = false;
            return nullptr;
        };

        if( strstr( symbolicName, "OAM" ) != nullptr )
        {
            if( !COAMConcurrentGroup::IsSupported( symbolicName, *this ) )
            {
                isSupported = false;
                return nullptr;
            }

            group = new( std::nothrow ) COAMConcurrentGroup( *this, symbolicName, shortName, measurementTypeMask );
        }
        else if( strstr( symbolicName, "OA" ) != nullptr )
        {
            group = new( std::nothrow ) COAConcurrentGroup( *this, symbolicName, shortName, measurementTypeMask );
        }
        else
        {
            group = new( std::nothrow ) CConcurrentGroup( *this, symbolicName, shortName, measurementTypeMask );
        }

        MD_CHECK_PTR_RET_A( adapterId, group, nullptr );

        m_groupsVector.push_back( group );
        m_params.ConcurrentGroupsCount = static_cast<uint32_t>( m_groupsVector.size() );

        return group;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddOverride
    //
    // Description:
    //     Adds the given override to MetricsDevice if available on current driver interface and
    //     platform.
    //     All the params are set in specialized constructors.
    //
    // Output:
    //     IOverride_1_2* - added override or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::AddOverride( TOverrideType overrideType )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();
        // 1. CHECK AVAILABILITY ON CURRENT DRIVER INTERFACE
        if( !m_driverInterface.IsOverrideAvailable( overrideType ) )
        {
            MD_LOG_A( adapterId, LOG_INFO, "Override %u not available on the current driver interface", overrideType );
            return nullptr;
        }

        // 2. CREATE OVERRIDE OBJECT
        IOverride_1_2* override = nullptr;
        switch( overrideType )
        {
            case OVERRIDE_TYPE_FREQUENCY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FREQUENCY>( *this );
                break;
            case OVERRIDE_TYPE_NULL_HARDWARE:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_NULL_HARDWARE>( *this );
                break;
            case OVERRIDE_TYPE_MULTISAMPLED_QUERY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>( *this );
                break;
            case OVERRIDE_TYPE_EXTENDED_QUERY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_EXTENDED_QUERY>( *this );
                break;
            case OVERRIDE_TYPE_FLUSH_GPU_CACHES:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>( *this );
                break;
#if defined( _RELEASE_INTERNAL )
            case OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>( *this );
                break;
#endif
            default:
                break;
        }

        // 3. CHECK AVAILABILITY ON CURRENT PLATFORM
        MD_CHECK_PTR_RET_A( adapterId, override, nullptr );
        if( IsPlatformTypeOf( static_cast<COverrideCommon*>( override )->GetParamsInternal()->PlatformMask ) )
        {
            // Add override and update count
            m_overridesVector.push_back( override );
            m_params.OverrideCount = static_cast<uint32_t>( m_overridesVector.size() );
            MD_LOG_A( adapterId, LOG_INFO, "%s - added", override->GetParams()->SymbolName );
        }
        else
        {
            // Override isn't available on the current platform
            MD_LOG_A( adapterId, LOG_INFO, "%s - not available", override->GetParams()->SymbolName );
            MD_SAFE_DELETE( override );
        }

        return override;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddOverrides
    //
    // Description:
    //     Fills override vector in MetricsDevice with previously defined overrides.
    //     All the params are set in specialized constructors.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::AddOverrides()
    {
        TCompletionCode ret = CC_OK;

        AddOverride( OVERRIDE_TYPE_FREQUENCY );
        AddOverride( OVERRIDE_TYPE_NULL_HARDWARE );
        AddOverride( OVERRIDE_TYPE_EXTENDED_QUERY );
        AddOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY );
        AddOverride( OVERRIDE_TYPE_FLUSH_GPU_CACHES );
#if defined( _RELEASE_INTERNAL )
        AddOverride( OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS );
#endif
        // ...

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsPlatformTypeOf
    //
    // Description:
    //     Checks if current platform is given type.
    //
    // Input:
    //     const TByteArrayLatest* platformMask - platform mask byte array
    //     uint32_t                gtMask - gt type mask in TGTType notation
    //
    // Output:
    //     bool                           - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsPlatformTypeOf( TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/ )
    {
        return ( m_gtType & gtMask ) && IsPlatformPresentInMask( platformMask, m_platformIndex, m_adapter.GetAdapterId() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SaveToFile
    //
    // Description:
    //     Saves a custom part of MetricsDevice to file.
    //
    // Input:
    //     const char*     fileName           - file name
    //     const uint32_t  minMajorApiVersion - required major MDAPI version to save to file
    //     const uint32_t  minMinorApiVersion - required minor MDAPI version to save to file
    //
    // Output:
    //     TCompletionCode                    - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::SaveToFile( const char* fileName, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        TCompletionCode retVal     = CC_OK;
        FILE*           metricFile = nullptr;
        uint8_t*        buffer     = nullptr;
        const uint32_t  adapterId  = m_adapter.GetAdapterId();

        iu_fopen_s( &metricFile, fileName, "wb" );
        MD_CHECK_PTR_RET_A( adapterId, metricFile, CC_ERROR_FILE_NOT_FOUND );

        uint32_t bufferSize = 0;
        retVal              = WriteToBuffer( nullptr, bufferSize, nullptr, 0, minMajorApiVersion, minMinorApiVersion );
        MD_CHECK_CC( retVal );

        buffer = new( std::nothrow ) uint8_t[bufferSize];
        MD_CHECK_PTR( buffer );

        retVal = WriteToBuffer( buffer, bufferSize, nullptr, 0, minMajorApiVersion, minMinorApiVersion );
        MD_CHECK_CC( retVal );

        fwrite( buffer, sizeof( uint8_t ), bufferSize, metricFile );

    exception:
        MD_SAFE_DELETE_ARRAY( buffer );

        fclose( metricFile );

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     WriteToBuffer
    //
    // Description:
    //     Saves a custom part of MetricsDevice to buffer.
    //
    // Input:
    //     uint8_t*       buffer             - pointer to a buffer
    //     uint32_t&      bufferSize         - size of the buffer
    //     CMetricSet**   metricSets         - metric sets to write to the buffer
    //     uint32_t       metricSetCount     - number of metric sets
    //     const uint32_t minMajorApiVersion - required major MDAPI version to save to buffer
    //     const uint32_t minMinorApiVersion - required minor MDAPI version to save to buffer
    //
    // Output:
    //     TCompletionCode                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::WriteToBuffer( uint8_t* buffer, uint32_t& bufferSize, CMetricSet** metricSets, uint32_t metricSetCount, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        const uint32_t  adapterId = m_adapter.GetAdapterId();
        TCompletionCode result    = CC_OK;

        if( buffer == nullptr )
        {
            bufferSize = 0;
        }

        uint32_t bufferOffset = 0;

        // Specific key indicating plain text MDAPI file
        result = WriteCStringToBuffer( MD_METRICS_FILE_KEY_3_0, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // Minimal api version
        result = WriteDataToBuffer( (void*) &minMajorApiVersion, sizeof( minMajorApiVersion ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( (void*) &minMinorApiVersion, sizeof( minMinorApiVersion ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_platformIndex
        result = WriteDataToBuffer( (void*) &m_platformIndex, sizeof( m_platformIndex ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_params
        result = WriteDataToBuffer( (void*) &m_params.Version, sizeof( m_params.Version ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_symbolsVector
        result = m_symbolSet.WriteSymbolSetToBuffer( buffer, bufferSize, bufferOffset );
        MD_CHECK_CC_RET_A( adapterId, result );

        // m_groupsVector
        const uint32_t groupsCount = static_cast<uint32_t>( m_groupsVector.size() );

        result = WriteDataToBuffer( (void*) &groupsCount, sizeof( groupsCount ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        for( auto& group : m_groupsVector )
        {
            result = group->WriteCConcurrentGroupToBuffer( buffer, bufferSize, bufferOffset, metricSets, metricSetCount );
            MD_CHECK_CC_RET_A( adapterId, result );
        }

        if( buffer != nullptr )
        {
            const bool validWrite = ( bufferOffset == bufferSize );
            MD_ASSERT_A( adapterId, validWrite );
            return validWrite ? CC_OK : CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadGlobalSymbolsFromBuffer
    //
    // Description:
    //     Reads global symbols from buffer and advances the pointer.
    //
    // Input:
    //     uint8_t*&       bufferPtr         - buffer
    //     const uint8_t*  bufferBeginOffset - buffer begin offset
    //     const uint32_t  bufferSize        - buffer size
    //     const uint32_t  bufferVersion     - buffer or file version
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadGlobalSymbolsFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, const uint32_t bufferVersion )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        auto isValidByteArray = []( const TGlobalSymbolLatest& globalSymbol )
        {
            return globalSymbol.SymbolTypedValue.ValueType == VALUE_TYPE_BYTEARRAY && globalSymbol.SymbolTypedValue.ValueByteArray != nullptr;
        };

        TGlobalSymbol   globalSymbol = {};
        TCompletionCode ret          = CC_OK;
        uint32_t        symbolsCount = 0;

        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, symbolsCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );

        for( uint32_t i = 0; i < symbolsCount; ++i )
        {
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, globalSymbol.symbol.SymbolName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadTTypedValueFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, bufferVersion, globalSymbol.symbol.SymbolTypedValue, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            uint32_t valueSymbolType = 0;
            ret                      = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueSymbolType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            globalSymbol.symbolType = m_isOffline ? SYMBOL_TYPE_IMMEDIATE // Only immediate symbols are supported in offline mode
                                                  : static_cast<TSymbolType>( valueSymbolType );

            if( m_symbolSet.IsSymbolAlreadyAdded( globalSymbol.symbol.SymbolName ) )
            {
                if( isValidByteArray( globalSymbol.symbol ) )
                {
                    DeleteByteArray( globalSymbol.symbol.SymbolTypedValue.ValueByteArray, adapterId );
                }
                continue;
            }

            ret = m_symbolSet.AddSymbol(
                globalSymbol.symbol.SymbolName,
                globalSymbol.symbol.SymbolTypedValue,
                globalSymbol.symbolType );

            if( ret != CC_OK && isValidByteArray( globalSymbol.symbol ) )
            {
                DeleteByteArray( globalSymbol.symbol.SymbolTypedValue.ValueByteArray, adapterId );
            }
        }

        m_params.GlobalSymbolsCount = m_symbolSet.GetSymbolCount();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadConcurrentGroupsFromBuffer
    //
    // Description:
    //     Reads concurrent groups from buffer and advances the pointer.
    //
    // Input:
    //     uint8_t*&        bufferPtr         - buffer
    //     const uint8_t*   bufferBeginOffset - buffer begin offset
    //     const uint32_t   bufferSize        - buffer size
    //     TApiVersion_1_0* apiVersion        - API version
    //     const uint32_t   bufferVersion     - buffer or file version
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadConcurrentGroupsFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, TApiVersion_1_0* apiVersion, const uint32_t bufferVersion )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode ret                 = CC_OK;
        const char*     symbolicName        = nullptr;
        const char*     shortName           = nullptr;
        uint32_t        measurementTypeMask = 0;
        bool            isSupported         = false;
        uint32_t        groupsCount         = 0;

        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, groupsCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );

        for( uint32_t i = 0; i < groupsCount; ++i )
        {
            // ConcurrentGroupParams
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, symbolicName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, shortName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, measurementTypeMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            auto concurrentGroup = GetConcurrentGroupByName( symbolicName );
            if( concurrentGroup == nullptr )
            {
                uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
                TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

                ret = SetAllBitsPlatformMask( adapterId, &platformMask );
                MD_CHECK_CC_RET_A( adapterId, ret );

                concurrentGroup = AddConcurrentGroup( symbolicName, shortName, measurementTypeMask, &platformMask, isSupported );
                if( !isSupported )
                {
                    MD_LOG_A( adapterId, LOG_WARNING, "%s concurrent group is not supported!", symbolicName );
                    return CC_ERROR_NOT_SUPPORTED;
                }

                MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_NO_MEMORY );
            }

            // MetricSets
            ret = ReadMetricSetsFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, concurrentGroup, apiVersion, bufferVersion );
            MD_CHECK_CC_RET_A( adapterId, ret );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadMetricSetsFromBuffer
    //
    // Description:
    //     Reads metric sets from buffer, adds them to the group and advances the pointer.
    //
    // Input:
    //     uint8_t*&         bufferPtr         - buffer
    //     const uint8_t*    bufferBeginOffset - buffer begin offset
    //     const uint32_t    bufferSize        - buffer size
    //     CConcurrentGroup* group             - parent concurrent group
    //     TApiVersion_1_0*  apiVersion        - API version
    //     const uint32_t    bufferVersion     - buffer or file version
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadMetricSetsFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, CConcurrentGroup* group, TApiVersion_1_0* apiVersion, const uint32_t bufferVersion )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, group, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode ret                  = CC_OK;
        CMetricSet*     set                  = nullptr;
        CMetricSet*     existingSet          = nullptr;
        const char*     symbolicName         = nullptr;
        const char*     availabilityEquation = nullptr;
        uint32_t        count                = 0;
        uint32_t        metricSetsCount      = 0;

        TMetricSetParams_1_11 metricSetParams;
        TApiSpecificId_1_0    apiSpecificId;
        TReportType           reportType;

        // MetricSets
        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetsCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );

        for( uint32_t j = 0; j < metricSetsCount; ++j )
        {
            set         = nullptr;
            existingSet = nullptr;

            // MetricSetParams
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.SymbolName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.ShortName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.ApiMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.CategoryMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.RawReportSize, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.QueryReportSize, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.PlatformMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            if( ( apiVersion->MajorNumber == MD_API_MAJOR_NUMBER_1 && apiVersion->MinorNumber >= MD_API_MINOR_NUMBER_4 ) || ( apiVersion->MajorNumber > MD_API_MAJOR_NUMBER_1 ) )
            {
                ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricSetParams.GtMask, adapterId );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }
            else
            {
                metricSetParams.GtMask = (uint32_t) GT_TYPE_ALL;
            }

            if( ( apiVersion->MajorNumber == MD_API_MAJOR_NUMBER_1 && apiVersion->MinorNumber >= MD_API_MINOR_NUMBER_11 ) || ( apiVersion->MajorNumber > MD_API_MAJOR_NUMBER_1 ) )
            {
                ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, availabilityEquation, adapterId );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            uint32_t valueReportType = 0;
            ret                      = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueReportType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            reportType = static_cast<TReportType>( valueReportType );

            TByteArrayLatest* platformMask = nullptr;
            if( bufferVersion >= CUSTOM_METRICS_FILE_VERSION_3 )
            {
                ret = ReadByteArrayFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, platformMask, adapterId );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }
            else
            {
                platformMask = GetByteArrayFromPlatformType( metricSetParams.PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );
            }
            MD_CHECK_PTR_RET_A( adapterId, platformMask, CC_ERROR_GENERAL );

            existingSet = group->GetMatchingMetricSet( metricSetParams.SymbolName, platformMask, metricSetParams.GtMask );
            if( !existingSet )
            {
                set = group->AddMetricSet(
                    metricSetParams.SymbolName,
                    metricSetParams.ShortName,
                    metricSetParams.ApiMask,
                    metricSetParams.CategoryMask,
                    metricSetParams.RawReportSize,
                    metricSetParams.QueryReportSize,
                    reportType,
                    platformMask,
                    availabilityEquation,
                    metricSetParams.GtMask,
                    true );

                if( !set )
                {
                    DeleteByteArray( platformMask, adapterId );
                    MD_CHECK_PTR_RET_A( adapterId, set, CC_ERROR_NO_MEMORY );
                }
                MD_LOG_A( adapterId, LOG_DEBUG, "adding set: %s", metricSetParams.ShortName );
            }
            else
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "set not added, using existing one: %s", metricSetParams.ShortName );
            }
            // platformMask is stored in metric set. iu_memcpy_s used.
            DeleteByteArray( platformMask, adapterId );

            // ApiSpecificId
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.D3D9QueryId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.D3D9Fourcc, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.D3D1XQueryId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.D3D1XDevDependentId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.D3D1XDevDependentName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.OGLQueryIntelId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.OGLQueryIntelName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret )
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.OGLQueryARBTargetId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.OCL, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, apiSpecificId.HwConfigId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( set )
            {
                set->SetApiSpecificId( apiSpecificId );
            }

            // Metrics - if set's been existing, add only missing metrics
            ret = ReadMetricsFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, existingSet ? existingSet : set, existingSet == nullptr );
            MD_CHECK_CC_RET_A( adapterId, ret );

            // Information
            ret = ReadInformationFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, set );
            MD_CHECK_CC_RET_A( adapterId, ret );

            // Start and stop registers
            ret = ReadRegistersFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, set );
            MD_CHECK_CC_RET_A( adapterId, ret );

            // ComplementaryMetricSets
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, count, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            for( uint32_t k = 0; k < count; ++k )
            {
                ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, symbolicName, adapterId );
                MD_CHECK_CC_RET_A( adapterId, ret );
                if( set )
                {
                    set->AddComplementaryMetricSet( symbolicName );
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
    //     ReadMetricsFromBuffer
    //
    // Description:
    //     Reads metrics from buffer, adds them to the set and advances the pointer.
    //
    // Input:
    //     uint8_t*&      bufferPtr         - buffer
    //     const uint8_t* bufferBeginOffset - buffer begin offset
    //     const uint32_t bufferSize        - buffer size
    //     CMetricSet*    set               - parent metric set
    //     const bool     isSetNew          - if true, add all metrics, otherwise add only metrics that
    //                                        don't exist in the set. It's to prevent adding duplicated
    //                                        metrics when reading existing set (e.g. default RenderBasic)
    //                                        with added custom metrics.
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadMetricsFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, CMetricSet* set, const bool isSetNew )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        CMetric*           metric         = nullptr;
        const char*        equationString = nullptr;
        const char*        signalName     = nullptr;
        TMetricParams_1_0  metricParams;
        TDeltaFunction_1_0 deltaFunction;
        bool               skip               = ( set == nullptr );
        TCompletionCode    ret                = CC_OK;
        uint32_t           metricsCount       = 0;
        int64_t            valueLowWatermark  = 0;
        int64_t            valueHighWatermark = 0;

        // Metrics
        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricsCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );
        for( uint32_t i = 0; i < metricsCount; ++i )
        {
            metric                   = nullptr;
            uint32_t valueResultType = 0;
            uint32_t valueMetricType = 0;
            uint32_t valueHwUnitType = 0;

            // MetricParams
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.GroupId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.SymbolName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.ShortName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.GroupName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.LongName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.DxToOglAlias, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.UsageFlagsMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.ApiMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueResultType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            metricParams.ResultType = static_cast<TMetricResultType>( valueResultType );

            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, metricParams.MetricResultUnits, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueMetricType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            metricParams.MetricType = static_cast<TMetricType>( valueMetricType );

            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueHwUnitType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            metricParams.HwUnitType = static_cast<THwUnitType>( valueHwUnitType );

            ret = ReadInt64FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueLowWatermark, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            metricParams.LowWatermark = static_cast<uint64_t>( valueLowWatermark );

            ret = ReadInt64FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueHighWatermark, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            metricParams.HighWatermark = static_cast<uint64_t>( valueHighWatermark );

            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, signalName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            if( !skip )
            {
                // Add only unique metrics to an existing metric set
                if( isSetNew || !set->IsMetricAlreadyAdded( metricParams.SymbolName ) )
                {
                    metric = set->AddMetric(
                        metricParams.SymbolName,
                        metricParams.ShortName,
                        metricParams.LongName,
                        metricParams.GroupName,
                        metricParams.GroupId,
                        metricParams.UsageFlagsMask,
                        metricParams.ApiMask,
                        metricParams.MetricType,
                        metricParams.ResultType,
                        metricParams.MetricResultUnits,
                        metricParams.LowWatermark,
                        metricParams.HighWatermark,
                        metricParams.HwUnitType,
                        equationString,
                        metricParams.DxToOglAlias,
                        signalName,
                        i,
                        true );
                    MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );
                }
            }

            uint32_t valueFunctionType = 0;

            // Delta function
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueFunctionType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            deltaFunction.FunctionType = static_cast<TDeltaFunctionType>( valueFunctionType );

            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, deltaFunction.BitsCount, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( metric )
            {
                ret = metric->SetSnapshotReportDeltaFunction( deltaFunction );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Snapshot report read equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( metric )
            {
                ret = metric->SetSnapshotReportReadEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Delta report read equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( metric )
            {
                ret = metric->SetDeltaReportReadEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Normalization equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( metric )
            {
                ret = metric->SetNormalizationEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Max value equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( metric )
            {
                ret = metric->SetMaxValueEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadInformationFromBuffer
    //
    // Description:
    //     Reads information from buffer, adds them to the set and advances the pointer.
    //
    // Input:
    //     uint8_t*&      bufferPtr         - buffer
    //     const uint8_t* bufferBeginOffset - buffer begin offset
    //     const uint32_t bufferSize        - buffer size
    //     CMetricSet*    set               - parent metric set
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadInformationFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, CMetricSet* set )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        CInformation*          aInformation   = nullptr;
        const char*            equationString = nullptr;
        TInformationParams_1_0 informationParams;
        TDeltaFunction_1_0     deltaFunction;
        bool                   skip              = ( set == nullptr );
        TCompletionCode        ret               = CC_OK;
        uint32_t               informationCount  = 0;
        uint32_t               valueInfoType     = 0;
        uint32_t               valueFunctionType = 0;

        // Information
        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );
        for( uint32_t k = 0; k < informationCount; ++k )
        {
            aInformation = nullptr;

            // InformationParams
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.SymbolName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.ShortName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.GroupName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.LongName, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.ApiMask, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret                        = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueInfoType, adapterId );
            informationParams.InfoType = static_cast<TInformationType>( valueInfoType );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadCStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, informationParams.InfoUnits, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            if( !skip )
            {
                aInformation = set->AddInformation(
                    informationParams.SymbolName,
                    informationParams.ShortName,
                    informationParams.LongName,
                    informationParams.GroupName,
                    informationParams.ApiMask,
                    informationParams.InfoType,
                    informationParams.InfoUnits,
                    equationString,
                    k );
                MD_CHECK_PTR_RET_A( adapterId, aInformation, CC_ERROR_NO_MEMORY );
            }

            // Delta function
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueFunctionType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            deltaFunction.FunctionType = static_cast<TDeltaFunctionType>( valueFunctionType );

            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, deltaFunction.BitsCount, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( aInformation )
            {
                ret = aInformation->SetOverflowFunction( deltaFunction );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Snapshot report read equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( aInformation )
            {
                ret = aInformation->SetSnapshotReportReadEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            // Delta report read equation
            ret = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            if( aInformation )
            {
                ret = aInformation->SetDeltaReportReadEquation( equationString );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadRegistersFromBuffer
    //
    // Description:
    //     Reads start and stop registers from buffer, adds them to the set and
    //     advances the pointer.
    //
    // Input:
    //     uint8_t*&      bufferPtr         - buffer
    //     const uint8_t* bufferBeginOffset - buffer begin offset
    //     const uint32_t bufferSize        - buffer size
    //     CMetricSet*    set               - parent metric set
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadRegistersFromBuffer( uint8_t*& bufferPtr, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, CMetricSet* set )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        TRegister          reg;
        const char*        equationString = nullptr;
        TRegisterSetParams registerSetParams;
        uint32_t           regCount        = 0;
        bool               skip            = ( set == nullptr );
        TCompletionCode    ret             = CC_OK;
        uint32_t           regSetCount     = 0;
        uint32_t           valueConfigType = 0;

        // Start register sets
        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, regSetCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );
        for( uint32_t i = 0; i < regSetCount; ++i )
        {
            // RegisterSetParams
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, registerSetParams.ConfigId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, registerSetParams.ConfigPriority, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueConfigType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            registerSetParams.ConfigType = static_cast<TConfigType>( valueConfigType );
            ret                          = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            if( !skip )
            {
                ret = set->AddStartRegisterSet(
                    registerSetParams.ConfigId,
                    registerSetParams.ConfigPriority,
                    equationString,
                    registerSetParams.ConfigType );
                MD_CHECK_CC_RET_A( adapterId, ret );
            }

            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, regCount, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            for( uint32_t j = 0; j < regCount; j++ )
            {
                if( !skip )
                {
                    reg = *( (TRegister*) ( bufferPtr ) );
                    ret = set->AddStartConfigRegister( reg.offset, reg.value, reg.type );
                    MD_CHECK_CC_RET_A( adapterId, ret );
                }
                MD_CHECK_BUFFER_A( adapterId, bufferPtr, bufferBeginOffset, sizeof( TRegister ), bufferSize );
                bufferPtr += sizeof( TRegister );
            }
        }

        // Stop register sets - !StopRegisters are obsolete, remains to be backward compatible (in new versions count is always 0)!
        ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, regSetCount, adapterId );
        MD_CHECK_CC_RET_A( adapterId, ret );
        for( uint32_t i = 0; i < regSetCount; ++i )
        {
            // RegisterSetParams
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, registerSetParams.ConfigId, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, registerSetParams.ConfigPriority, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, valueConfigType, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
            registerSetParams.ConfigType = static_cast<TConfigType>( valueConfigType );
            ret                          = ReadEquationStringFromBuffer( bufferPtr, bufferBeginOffset, bufferSize, equationString, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            ret = ReadUInt32FromBuffer( bufferPtr, bufferBeginOffset, bufferSize, regCount, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );

            const uint32_t regTotalSize = sizeof( TRegister ) * regCount;
            MD_CHECK_BUFFER_A( adapterId, bufferPtr, bufferBeginOffset, regTotalSize, bufferSize );
            bufferPtr += regTotalSize;
        }

        if( !skip )
        {
            if( set->RefreshConfigRegisters() != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_INFO, "Failed to refresh config registers" );
                return CC_ERROR_GENERAL;
            }
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     OpenFromFile
    //
    // Description:
    //     Opens, checks for MDAPI plain text format and loads file with saved
    //     metrics device if the format is valid.

    //
    // Input:
    //     const char* fileName - file name
    //
    // Output:
    //     TCompletionCode      - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::OpenFromFile( const char* fileName )
    {
        TCompletionCode retVal           = CC_OK;
        FILE*           metricFile       = nullptr;
        uint8_t*        metricFileBuffer = nullptr;
        uint8_t*        bufferPtr        = nullptr;
        uint32_t        fileVersion      = CUSTOM_METRICS_FILE_VERSION_0;
        const uint32_t  adapterId        = m_adapter.GetAdapterId();

        iu_fopen_s( &metricFile, fileName, "rb" );
        MD_CHECK_PTR_RET_A( adapterId, metricFile, CC_ERROR_FILE_NOT_FOUND );

        const uint32_t fileSize = static_cast<uint32_t>( GetFileSize( metricFile, adapterId ) );
        if( fileSize == static_cast<uint32_t>( -1 ) || fileSize < sizeof( MD_METRICS_FILE_KEY ) )
        {
            fclose( metricFile );
            return CC_ERROR_INVALID_PARAMETER;
        }

        metricFileBuffer = new( std::nothrow ) uint8_t[fileSize]();
        if( metricFileBuffer == nullptr )
        {
            fclose( metricFile );
            return CC_ERROR_NO_MEMORY;
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "Check if file is in MDAPI plain text format" );
        if( IsMetricsFileInPlainTextFormat( metricFile, fileVersion ) )
        {
            // Load plain text format file
            if( iu_fread_s( metricFileBuffer, fileSize, 1, fileSize, metricFile ) == 0 )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Cannot load file" );
                MD_SAFE_DELETE_ARRAY( metricFileBuffer );
                fclose( metricFile );
                return CC_ERROR_INVALID_PARAMETER;
            }
            bufferPtr = metricFileBuffer;

            if( fileVersion == CUSTOM_METRICS_FILE_VERSION_1 )
            {
                bufferPtr += sizeof( MD_METRICS_FILE_KEY );
            }
            else if( fileVersion == CUSTOM_METRICS_FILE_VERSION_2 )
            {
                bufferPtr += sizeof( MD_METRICS_FILE_KEY_2_0 );
            }
            else if( fileVersion == CUSTOM_METRICS_FILE_VERSION_3 )
            {
                bufferPtr += sizeof( MD_METRICS_FILE_KEY_3_0 );
            }
        }
        else
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Metrics device file is not valid" );
            retVal = CC_ERROR_INVALID_PARAMETER;
        }
        fclose( metricFile );

        if( retVal == CC_OK )
        {
            if( fileVersion > CUSTOM_METRICS_FILE_VERSION_1 )
            {
                uint32_t majorApiVersion = 0;
                uint32_t minorApiVersion = 0;

                retVal = ReadUInt32FromBuffer( bufferPtr, metricFileBuffer, fileSize, majorApiVersion, adapterId );
                MD_CHECK_CC( retVal );

                retVal = ReadUInt32FromBuffer( bufferPtr, metricFileBuffer, fileSize, minorApiVersion, adapterId );
                MD_CHECK_CC( retVal );

                if( ( majorApiVersion == MD_API_MAJOR_NUMBER_CURRENT && minorApiVersion > MD_API_MINOR_NUMBER_CURRENT ) || majorApiVersion > MD_API_MAJOR_NUMBER_CURRENT )
                {
                    MD_LOG_A( adapterId, LOG_ERROR, "Required MDAPI version %d.%d, current version %d.%d", majorApiVersion, minorApiVersion, MD_API_MAJOR_NUMBER_CURRENT, MD_API_MINOR_NUMBER_CURRENT );
                    m_isOpenedFromFile = false;
                    MD_SAFE_DELETE_ARRAY( metricFileBuffer );
                    return CC_ERROR_NOT_SUPPORTED;
                }
            }

            if( fileVersion >= CUSTOM_METRICS_FILE_VERSION_3 )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Metrics device file saved on platform index: %u, current: %u", *( (uint32_t*) bufferPtr ), m_platformIndex );
                bufferPtr += sizeof( uint32_t );
            }
            else
            {
                uint32_t       platFormIndex = UINT32_MAX;
                const uint32_t platformMask  = *( (TPlatformType*) bufferPtr );
                for( uint32_t i = 0; i < sizeof( platformMask ) * MD_BYTE; ++i )
                {
                    if( platformMask & ( 1 << i ) )
                    {
                        platFormIndex = i;
                        break;
                    }
                }

                if( platFormIndex == UINT32_MAX )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "WARNING: read platform mask of metrics device is empty." );
                }
                else
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "Metrics device file saved on platform: %u, current: %u", platFormIndex, m_platformIndex );
                }

                bufferPtr += sizeof( TPlatformType );
            }

            // MetricsDeviceParams
            TApiVersion_1_0 apiVersion = {};

            retVal = ReadUInt32FromBuffer( bufferPtr, metricFileBuffer, fileSize, apiVersion.MajorNumber, adapterId );
            MD_CHECK_CC( retVal );
            retVal = ReadUInt32FromBuffer( bufferPtr, metricFileBuffer, fileSize, apiVersion.MinorNumber, adapterId );
            MD_CHECK_CC( retVal );
            retVal = ReadUInt32FromBuffer( bufferPtr, metricFileBuffer, fileSize, apiVersion.BuildNumber, adapterId );
            MD_CHECK_CC( retVal );

            MD_LOG_A( adapterId, LOG_DEBUG, "Metrics device file saved with MDAPI v. %d.%d.%d, current v: %d.%d.%d", apiVersion.MajorNumber, apiVersion.MinorNumber, apiVersion.BuildNumber, MD_API_MAJOR_NUMBER_CURRENT, MD_API_MINOR_NUMBER_CURRENT, MD_API_BUILD_NUMBER_CURRENT );

            // GlobalSymbols
            retVal = ReadGlobalSymbolsFromBuffer( bufferPtr, metricFileBuffer, fileSize, fileVersion );
            MD_CHECK_CC( retVal );

            // ConcurrentGroup tree
            if( retVal == CC_OK )
            {
                retVal = ReadConcurrentGroupsFromBuffer( bufferPtr, metricFileBuffer, fileSize, &apiVersion, fileVersion );
                MD_CHECK_CC( retVal );
            }
        }
        m_isOpenedFromFile = ( retVal == CC_OK );

    exception:
        MD_SAFE_DELETE_ARRAY( metricFileBuffer );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     OpenOfflineFromBuffer
    //
    // Description:
    //     Opens an offline metrics device from a buffer
    //
    // Input:
    //     uint8_t* buffer     - a buffer containing device data and metrics
    //     uint32_t bufferSize - the size of a buffer
    //
    // Output:
    //     TCompletionCode     - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::OpenOfflineFromBuffer( uint8_t* buffer, uint32_t bufferSize )
    {
        const uint32_t            adapterId                 = m_adapter.GetAdapterId();
        TCompletionCode           retVal                    = CC_OK;
        uint8_t*                  bufferPtr                 = buffer;
        const char*               metricBufferVersionString = nullptr;
        TCustomMetricsFileVersion metricBufferVersion       = CUSTOM_METRICS_FILE_VERSION_0;
        uint32_t                  majorApiVersion           = 0;
        uint32_t                  minorApiVersion           = 0;
        uint32_t                  platformIndex             = 0;
        TApiVersion_1_0           apiVersion                = {};

        retVal = ReadCStringFromBuffer( bufferPtr, buffer, bufferSize, metricBufferVersionString, adapterId );
        MD_CHECK_CC_RET( retVal );

        size_t metricBufferVersionStringLength = strlen( metricBufferVersionString );

        if( iu_strncmp( MD_METRICS_FILE_KEY, metricBufferVersionString, metricBufferVersionStringLength ) == 0 )
        {
            metricBufferVersion = CUSTOM_METRICS_FILE_VERSION_1;
        }
        else if( iu_strncmp( MD_METRICS_FILE_KEY_2_0, metricBufferVersionString, metricBufferVersionStringLength ) == 0 )
        {
            metricBufferVersion = CUSTOM_METRICS_FILE_VERSION_2;
        }
        else if( iu_strncmp( MD_METRICS_FILE_KEY_3_0, metricBufferVersionString, metricBufferVersionStringLength ) == 0 )
        {
            metricBufferVersion = CUSTOM_METRICS_FILE_VERSION_3;
        }

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, majorApiVersion, adapterId );
        MD_CHECK_CC_RET( retVal );

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, minorApiVersion, adapterId );
        MD_CHECK_CC_RET( retVal );

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, platformIndex, adapterId );
        MD_CHECK_CC_RET( retVal );
        m_platformIndex = platformIndex;

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, apiVersion.MajorNumber, adapterId );
        MD_CHECK_CC_RET( retVal );

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, apiVersion.MinorNumber, adapterId );
        MD_CHECK_CC_RET( retVal );

        retVal = ReadUInt32FromBuffer( bufferPtr, buffer, bufferSize, apiVersion.BuildNumber, adapterId );
        MD_CHECK_CC_RET( retVal );

        // GlobalSymbols
        retVal = ReadGlobalSymbolsFromBuffer( bufferPtr, buffer, bufferSize, metricBufferVersion );
        MD_CHECK_CC_RET( retVal );

        // ConcurrentGroup tree
        if( retVal == CC_OK )
        {
            retVal = ReadConcurrentGroupsFromBuffer( bufferPtr, buffer, bufferSize, &apiVersion, metricBufferVersion );
            MD_CHECK_CC_RET( retVal );
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetQueryMode
    //
    // Description:
    //     Get status of query mode override.
    //
    // Output:
    //     TQueryMode - enabled query mode override.
    //
    //////////////////////////////////////////////////////////////////////////////
    TQueryMode CMetricsDevice::GetQueryMode() const
    {
        return ( m_queryModeRequested == QUERY_MODE_NONE )
            ? m_queryModeDefault
            : m_queryModeRequested;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsMetricsFileInPlainTextFormat
    //
    // Description:
    //     Check if metrics file has a proper header with MD_METRICS_FILE_KEY.
    //
    // Input:
    //     FILE*     metricFile  - opened file with custom metrics.
    //     uint32_t& fileVersion - custom file version [out]
    //
    // Output:
    //     bool                  - true if file in MDAPI plain text format, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsMetricsFileInPlainTextFormat( FILE* metricFile, uint32_t& fileVersion )
    {
        const uint32_t metricFileKeySize              = sizeof( MD_METRICS_FILE_KEY_3_0 );
        uint8_t        readFileKey[metricFileKeySize] = { 0 };

        // Load fragment of the file as plain text
        if( iu_fread_s( readFileKey, metricFileKeySize, 1, metricFileKeySize, metricFile ) == 0 )
        {
            return false;
        }

        // Move file pointer to the start
        rewind( metricFile );

        if( iu_strncmp( MD_METRICS_FILE_KEY, (const char*) &readFileKey, metricFileKeySize ) == 0 )
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_1;
        }
        else if( iu_strncmp( MD_METRICS_FILE_KEY_2_0, (const char*) &readFileKey, metricFileKeySize ) == 0 )
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_2;
        }
        else if( iu_strncmp( MD_METRICS_FILE_KEY_3_0, (const char*) &readFileKey, metricFileKeySize ) == 0 )
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_3;
        }
        else
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_0;
        }

        // Check if the file has MDAPI plain text header
        return fileVersion > CUSTOM_METRICS_FILE_VERSION_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetDriverInterface
    //
    // Description:
    //     Returns driver interface.
    //
    // Output:
    //     CDriverInterface& - driver interface reference
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterface& CMetricsDevice::GetDriverInterface()
    {
        return m_driverInterface;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetAdapter
    //
    // Description:
    //     Returns underlying adapter reference.
    //
    // Output:
    //     CAdapter& - adapter reference
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter& CMetricsDevice::GetAdapter()
    {
        return m_adapter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetSymbolSet
    //
    // Description:
    //     Returns reference to the symbol set.
    //
    // Output:
    //     CSymbolSet& - reference to the symbol set
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet& CMetricsDevice::GetSymbolSet()
    {
        return m_symbolSet;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetPlatformByteArray
    //
    // Description:
    //     Returns platform index.
    //
    // Output:
    //     uint32_t - platform index.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricsDevice::GetPlatformIndex()
    {
        return m_platformIndex;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsOpenedFromFile
    //
    // Description:
    //     Returns true if device was opened from a file
    //
    // Output:
    //     bool - true if opened from file
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsOpenedFromFile()
    {
        return m_isOpenedFromFile;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ConvertGpuTimestampToNs
    //
    // Description:
    //     Converts gpu timestamp to ns and provides a sync with report timestamps.
    //
    // Input:
    //     const uint64_t gpuTimestampTicks     - gpu timestamp in ticks.
    //     const uint64_t gpuTimestampFrequency - gpu timestamp frequency.
    //
    // Output:
    //     uint64_t                             - gpu timestamp in ns.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint64_t CMetricsDevice::ConvertGpuTimestampToNs( const uint64_t gpuTimestampTicks, const uint64_t gpuTimestampFrequency )
    {
        if( gpuTimestampFrequency == 0 )
        {
            return 0;
        }

        switch( m_platformIndex )
        {
            case GENERATION_BMG:
            case GENERATION_LNL:
            case GENERATION_PTL:
            case GENERATION_NVL:
            case GENERATION_CRI:
            {
                // Ticks masked to 56bit to get sync with report timestamps.
                const double oneTickNs                        = static_cast<double>( MD_SECOND_IN_NS ) / gpuTimestampFrequency;
                const double gpuTimestampNsHigh               = ( ( gpuTimestampTicks & MD_GPU_TIMESTAMP_MASK_56 ) >> 32 ) * oneTickNs;
                const double gpuTimestampNsHighFractionalPart = ( gpuTimestampNsHigh - static_cast<uint64_t>( gpuTimestampNsHigh ) ) * ( MD_GPU_TIMESTAMP_MASK_32 + 1 );
                const double gpuTimestampNsLow                = ( gpuTimestampTicks & MD_GPU_TIMESTAMP_MASK_32 ) * oneTickNs;

                return ( static_cast<uint64_t>( gpuTimestampNsHigh ) << 32 ) + static_cast<uint64_t>( gpuTimestampNsLow + gpuTimestampNsHighFractionalPart );
            }
            default:
                // Ticks masked to 32bit to get sync with report timestamps.
                return ( gpuTimestampTicks & MD_GPU_TIMESTAMP_MASK_32 ) * MD_SECOND_IN_NS / gpuTimestampFrequency;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetReferenceCounter
    //
    // Description:
    //     Returns metrics device reference counters.
    //
    // Output:
    //     uint32_t - metrics device reference counter
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t& CMetricsDevice::GetReferenceCounter()
    {
        return m_referenceCounter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetSubDeviceIndex
    //
    // Description:
    //     Returns sub device index.
    //
    // Output:
    //     uint32_t - sub device index
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricsDevice::GetSubDeviceIndex()
    {
        return m_subDeviceIndex;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetOaBufferMask
    //
    // Description:
    //     Returns oa buffer mask.
    //
    // Output:
    //     uint32_t - oa buffer mask
    //
    //////////////////////////////////////////////////////////////////////////////
    GTDI_OA_BUFFER_MASK CMetricsDevice::GetOaBufferMask()
    {
        if( m_oaBufferMask == GTDI_OA_BUFFER_MASK_NONE )
        {
            const uint32_t adapterId = m_adapter.GetAdapterId();

            GTDIDeviceInfoParamExtOut out = {};
            const auto                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFERS_MASK, out, *this );
            if( ret == CC_OK )
            {
                m_oaBufferMask = static_cast<GTDI_OA_BUFFER_MASK>( out.ValueUint32 );
                MD_LOG_A( adapterId, LOG_DEBUG, "Oa buffer mask: %x", m_oaBufferMask );
            }
            else
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Unable to get oa buffer mask. Return code: %u", ret );
            }
        }

        return m_oaBufferMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamConfigId
    //
    // Description:
    //     Returns stream configuration id.
    //
    // Output:
    //     int32_t - configuration id.
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CMetricsDevice::GetStreamConfigId()
    {
        return m_streamConfigId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamId
    //
    // Description:
    //     Returns stream id.
    //
    // Output:
    //     int32_t - stream id.
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CMetricsDevice::GetStreamId()
    {
        return m_streamId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SetStreamId
    //
    // Description:
    //     Sets stream id.
    //
    // Input:
    //     const int32_t id - stream id.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsDevice::SetStreamId( const int32_t id )
    {
        m_streamId = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SetStreamConfigId
    //
    // Description:
    //     Sets stream configuration id.
    //
    // Input:
    //     const int32_t id - configuration id.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsDevice::SetStreamConfigId( const int32_t id )
    {
        m_streamConfigId = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamBuffer
    //
    // Description:
    //     Returns preallocated buffer for reading data from tbs stream to avoid new allocations on every read.
    //
    // Output:
    //     std::vector<uint8_t> - tbs stream buffer.
    //
    //////////////////////////////////////////////////////////////////////////////
    std::vector<uint8_t>& CMetricsDevice::GetStreamBuffer()
    {
        return m_streamBuffer;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetConcurrentGroupByName
    //
    // Description:
    //     Returns chosen concurrent group by name or nullptr if not exists.
    //
    // Input:
    //     const char* symbolName - name of a concurrent group to look for
    //
    // Output:
    //     CConcurrentGroup*      - found concurrent group or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup* CMetricsDevice::GetConcurrentGroupByName( const char* symbolName )
    {
        MD_CHECK_PTR_RET_A( m_adapter.GetAdapterId(), symbolName, nullptr );

        for( auto& group : m_groupsVector )
        {
            if( group && ( strcmp( symbolName, group->GetParams()->SymbolName ) == 0 ) )
            {
                return group;
            }
        }

        return nullptr;
    }
} // namespace MetricsDiscoveryInternal
