/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_symbol_set.h

//     Abstract:   C++ Metrics Discovery internal symbol set implementation

#include "md_symbol_set.h"
#include "md_adapter.h"
#include "md_metrics_device.h"

#include "md_driver_ifc.h"
#include "md_utils.h"

#include <cstring>
#include <limits>
#include <map>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     CSymbolSet constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet::CSymbolSet( CMetricsDevice& metricsDevice, CDriverInterface& driverInterface )
        : m_symbolMap()
        , m_metricsDevice( metricsDevice )
        , m_driverInterface( driverInterface )
        , m_maxSlice( 0 )
        , m_maxSubslicePerSlice( 0 )
        , m_maxDualSubslicePerSlice( 0 )
    {
        m_symbolMap.reserve( SYMBOLS_MAP_INCREASE );

        if( DetectMaxSlicesInfo() != CC_OK )
        {
            MD_LOG_A( metricsDevice.GetAdapter().GetAdapterId(), LOG_ERROR, "Cannot detect max slices, subslices per slice or dual subslices per slice" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     CSymbolSet destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet::~CSymbolSet()
    {
        for( auto& symbol : m_symbolMap )
        {
            MD_SAFE_DELETE_ARRAY( symbol.second->symbol_1_0.SymbolName );
            if( symbol.second->symbol_1_0.SymbolTypedValue.ValueType == VALUE_TYPE_CSTRING )
            {
                MD_SAFE_DELETE_ARRAY( symbol.second->symbol_1_0.SymbolTypedValue.ValueCString );
            }
            else if( symbol.second->symbol_1_0.SymbolTypedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                MD_SAFE_DELETE_ARRAY( symbol.second->symbol_1_0.SymbolTypedValue.ValueByteArray->Data );
                MD_SAFE_DELETE( symbol.second->symbol_1_0.SymbolTypedValue.ValueByteArray );
            }
        }

        ClearUnorderedMap( m_symbolMap );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbolCount
    //
    // Description:
    //     Returns symbol count.
    //
    // Output:
    //     uint32_t -  symbol count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSymbolSet::GetSymbolCount()
    {
        return m_symbolMap.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbol
    //
    // Description:
    //     Returns chosen symbol or null if not exists.
    //
    // Input:
    //     uint32_t index      - index of symbol
    //
    // Output:
    //     TGlobalSymbol_1_0*  - pointer to the symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbol_1_0* CSymbolSet::GetSymbol( uint32_t index )
    {
        if( index < m_symbolMap.size() )
        {
            auto iterator = m_symbolMap.begin();
            std::advance( iterator, index );
            return &( iterator->second->symbol_1_0 );
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbolValueByName
    //
    // Description:
    //     Returns chosen symbol by name or nullptr if not exists.
    //
    // Input:
    //     const char* name   - name of symbol
    //
    // Output:
    //     TTypedValue_1_0*   - pointer to symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0* CSymbolSet::GetSymbolValueByName( const char* name )
    {
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, name, nullptr );

        auto symbol = m_symbolMap.find( name );

        return ( symbol != m_symbolMap.end() )
            ? ( &( symbol->second->symbol_1_0.SymbolTypedValue ) )
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbol
    //
    // Description:
    //     Adds symbol to symbol set.
    //
    // Input:
    //     const char*       name       - symbol name
    //     TTypedValueLatest typedValue - symbol value
    //     TSymbolType       symbolType - symbol type
    //
    // Output:
    //     TCompletionCode              - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbol( const char* name, TTypedValueLatest typedValue, TSymbolType symbolType )
    {
        TCompletionCode ret       = CC_OK;
        const uint32_t  adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, name, CC_ERROR_GENERAL );
        MD_LOG_A( adapterId, LOG_DEBUG, "%s - adding...", name );

        if( IsSymbolAlreadyAdded( name ) )
        {
            MD_LOG_A( adapterId, LOG_INFO, "The symbol has already been added." );
            return CC_OK;
        }

        if( symbolType == SYMBOL_TYPE_DETECT )
        {
            // if it is a CString or a ByteArray, a memory is allocated here
            ret = DetectSymbolValue( name, typedValue );

            if( ret == CC_ERROR_NOT_SUPPORTED )
            {
                MD_LOG_A( adapterId, LOG_INFO, "Symbol is not supported." );

                if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY && typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }

                return CC_OK;
            }

            MD_CHECK_CC_RET_A( adapterId, ret );
        }

        TGlobalSymbol* symbol = new( std::nothrow ) TGlobalSymbol;
        MD_CHECK_PTR_RET_A( adapterId, symbol, CC_ERROR_NO_MEMORY );

        symbol->version               = API_VERSION_1_0;
        symbol->symbolType            = symbolType;
        symbol->symbol_1_0.SymbolName = GetCopiedCString( name, adapterId );
        if( typedValue.ValueType == VALUE_TYPE_CSTRING )
        {
            symbol->symbol_1_0.SymbolTypedValue.ValueType    = typedValue.ValueType;
            symbol->symbol_1_0.SymbolTypedValue.ValueCString = ( symbolType == SYMBOL_TYPE_DETECT )
                ? typedValue.ValueCString // CString is already copied
                : GetCopiedCString( typedValue.ValueCString, adapterId );
        }
        else if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
        {
            symbol->symbol_1_0.SymbolTypedValue.ValueType      = typedValue.ValueType;
            symbol->symbol_1_0.SymbolTypedValue.ValueByteArray = ( symbolType == SYMBOL_TYPE_DETECT )
                ? typedValue.ValueByteArray // ByteArray is already copied
                : GetCopiedByteArray( typedValue.ValueByteArray, adapterId );
        }
        else
        {
            symbol->symbol_1_0.SymbolTypedValue = typedValue;
        }
        m_symbolMap.emplace( symbol->symbol_1_0.SymbolName, symbol );

        if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
        {
            // check if this ByteArray is a mask
            return UnpackMask( symbol );
        }

        MD_LOG_A( adapterId, LOG_INFO, "Symbol added successfully." );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     DetectSymbolValue
    //
    // Description:
    //     Gets certain symbol's values sending escapes to KMD.
    //
    // Input:
    //     std::string_view        name          - symbol name
    //     TTypedValueLatest&      typedValue    - output value
    //
    // Output:
    //     TCompletionCode                       - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::DetectSymbolValue( std::string_view name, TTypedValueLatest& typedValue )
    {
        const uint32_t            adapterId     = m_metricsDevice.GetAdapter().GetAdapterId();
        const uint32_t            platformIndex = m_metricsDevice.GetPlatformIndex();
        TCompletionCode           ret           = CC_OK;
        GTDIDeviceInfoParamExtOut out           = {};

        if( !IsSymbolNameSupported( name ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        const bool useDualSubslice = IsPlatformMatch(
            platformIndex,
            // Only on ACM and MTL dual subslices are used to calculate XeCore global symbols.
            GENERATION_MTL,
            GENERATION_ACM );

        if( name == "EuCoresTotalCount" || name == "VectorEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuCoresPerSubsliceCount" || name == "VectorEnginePerXeCoreCount" )
        {
            // ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT, &out, &m_metricsDevice );
            // TODO: windows driver interface refactoring is needed.

            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, &out, &m_metricsDevice );
            if( ret == CC_OK )
            {
                uint32_t euCoresTotalCount = out.ValueUint32;

                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT, &out, &m_metricsDevice );
                if( ret != CC_OK )
                {
                    ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, &out, &m_metricsDevice );
                }
                else
                {
                    const bool isSubsliceAvailable = IsPlatformMatch( platformIndex, GENERATION_TGL, GENERATION_DG1, GENERATION_ADLP, GENERATION_ADLS, GENERATION_ADLN, GENERATION_XEHP_SDV );
                    if( isSubsliceAvailable )
                    {
                        out.ValueUint32 *= 2;
                    }
                }

                uint32_t subslicesTotalCount = out.ValueUint32;

                typedValue.ValueUInt32 = ( subslicesTotalCount > 0 ) ? euCoresTotalCount / subslicesTotalCount : 0;
            }
        }
        else if( name == "EuSubslicesTotalCount" || ( !useDualSubslice && ( name == "XeCoreTotalCount" ) ) )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        // not supported for XeHP_SDV, removed all platforms for consistency
        else if( name == "EuSubslicesPerSliceCount" )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }
        else if( name == "EuDualSubslicesTotalCount" || ( useDualSubslice && ( name == "XeCoreTotalCount" ) ) )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuSlicesTotalCount" || name == "SliceTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_COUNT, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuThreadsCount" || name == "VectorEngineThreadsCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_THREADS_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SliceMask" || name == "GtSliceMask" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_MASK, &out, &m_metricsDevice );
            if( ret == CC_OK && typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }
                TByteArray_1_0 byteArray  = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue.ValueByteArray = GetCopiedByteArray( &byteArray, adapterId );
            }
            else
            {
                typedValue.ValueUInt32 = out.ValueUint32;
            }
        }
        else if( ( name == "SubsliceMask" ) || ( name == "GtSubsliceMask" ) || ( !useDualSubslice && ( ( name == "XeCoreMask" ) || ( name == "GtXeCoreMask" ) ) ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_MASK, &out, &m_metricsDevice );
            if( ret == CC_OK && typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }
                TByteArray_1_0 byteArray  = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue.ValueByteArray = GetCopiedByteArray( &byteArray, adapterId );
            }
            else
            {
                typedValue.ValueUInt64 = out.ValueUint64;
            }
        }
        else if( ( name == "DualSubsliceMask" ) || ( name == "GtDualSubsliceMask" ) || ( useDualSubslice && ( ( name == "XeCoreMask" ) || ( name == "GtXeCoreMask" ) ) ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK, &out, &m_metricsDevice );
            if( ret == CC_OK && typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }
                TByteArray_1_0 byteArray  = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue.ValueByteArray = GetCopiedByteArray( &byteArray, adapterId );
            }
            else
            {
                typedValue.ValueUInt64 = out.ValueUint64;
            }
        }
        else if( name == "SamplersTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SAMPLERS_COUNT, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SamplersPerSubliceCount" )
        {
            // obsolete
            return CC_ERROR_NOT_SUPPORTED;
        }
        else if( name == "MemoryPeakThroghputMB" )
        {
            if( m_metricsDevice.GetAdapter().GetParams()->Type == ADAPTER_TYPE_INTEGRATED )
            {
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT, &out );
                typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 / static_cast<uint64_t>( MD_MBYTE ) );
            }
            else
            {
                return CC_ERROR_NOT_SUPPORTED;
            }
        }
        else if( name == "GpuMinFrequencyMHz" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY, &out );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG_A( adapterId, LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", GetCStringFromStringView( name ) );
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, &out );
                typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
            }
            else
            {
                typedValue.ValueUInt32 = out.ValueUint32;
            }
        }
        else if( name == "GpuMaxFrequencyMHz" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY, &out );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG_A( adapterId, LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", GetCStringFromStringView( name ) );
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, &out );
                typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
            }
            else
            {
                typedValue.ValueUInt32 = out.ValueUint32;
            }
        }
        else if( name == "GpuCurrentFrequencyMHz" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, &out );
            typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
        }

        else if( name == "PciDeviceId" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PCI_DEVICE_ID, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SkuRevisionId" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_REVISION_ID, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "SkuRevisionId is %u", typedValue.ValueUInt32 );
        }
        else if( name == "PlatformIndex" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "PlatformIndex is %u", typedValue.ValueUInt32 );
        }
        else if( name == "ApertureSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_APERTURE_SIZE, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "Capabilities" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "PavpDisabled" )
        {
            ret                  = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
            typedValue.ValueBool = IsPavpDisabled( out.ValueUint32 );
        }
        else if( name == "NumberOfRenderOutputUnits" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS, &out, &m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "NumberOfShadingUnits" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "OABufferMinSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_DEFAULT, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "OABufferMaxSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_DEFAULT, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "MediaOABufferMinSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_OAM_SLICE_0, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "MediaOABufferMaxSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_OAM_SLICE_0, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "GpuTimestampFrequency" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "EdramSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EDRAM_SIZE, &out );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "LLCSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_LLC_SIZE, &out );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "L3Size" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_SIZE, &out );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "MaxTimestamp" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
            typedValue.ValueUInt64 = m_metricsDevice.ConvertGpuTimestampToNs( ( std::numeric_limits<uint64_t>::max )(), out.ValueUint64 );
        }
        else if( name == "L3BankTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_BANK_TOTAL_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "L3NodeTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_NODE_TOTAL_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SqidiTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SQIDI_TOTAL_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "PlatformVersion" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_VERSION, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "PlatformVersion is %u", typedValue.ValueUInt32 );
        }
        else if( name == "ComputeEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COMPUTE_ENGINE_TOTAL_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "CopyEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COPY_ENGINE_TOTAL_COUNT, &out );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unknown global symbol name: %s", GetCStringFromStringView( name ) );
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( ret == CC_ERROR_NOT_SUPPORTED )
        {
            return ret;
        }
        MD_CHECK_CC_RET_A( adapterId, ret );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     IsSymbolNameSupported
    //
    // Description:
    //     Check if symbol name is valid for current platform.
    //
    // Input:
    //     std::string_view name - base symbol name
    //
    // Output:
    //     bool                  - true if supported on this platform.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSymbolSet::IsSymbolNameSupported( std::string_view name )
    {
        const uint32_t adapterId        = m_metricsDevice.GetAdapter().GetAdapterId();
        const uint32_t platformIndex    = m_metricsDevice.GetPlatformIndex();
        const char*    globalSymbolName = GetCStringFromStringView( name );

        if( name == "PlatformVersion" )
        {
            return platformIndex == GENERATION_ACM;
        }

        const bool isXeHpgPlus = IsPlatformMatch(
            platformIndex,
            GENERATION_MTL,
            GENERATION_ACM,
            GENERATION_PVC );

        const bool useDualSubslice = IsPlatformMatch(
            platformIndex,
            GENERATION_MTL,
            GENERATION_TGL,
            GENERATION_DG1,
            GENERATION_XEHP_SDV,
            GENERATION_ACM,
            GENERATION_RKL,
            GENERATION_ADLP,
            GENERATION_ADLS,
            GENERATION_ADLN );

        // Media related global symbols
        if( name == "MediaOABufferMinSize" || name == "MediaOABufferMaxSize" )
        {
            const bool oamSupported = IsPlatformMatch(
                platformIndex,
                GENERATION_MTL,
                GENERATION_ACM );

            MD_LOG_A( adapterId, LOG_DEBUG, "Media symbol name is%s supported: %s", oamSupported ? "" : " not", globalSymbolName );

            return oamSupported;
        }

        std::map<std::string_view, std::string_view> globalSymbolMap{
            { "EuCoresTotalCount", "VectorEngineTotalCount" },
            { "EuCoresPerSubsliceCount", "VectorEnginePerXeCoreCount" },
            { "EuSlicesTotalCount", "SliceTotalCount" },
            { "EuThreadsCount", "VectorEngineThreadsCount" },
        };

        if( useDualSubslice )
        {
            globalSymbolMap.emplace( "EuSubslicesTotalCount", "" );
            globalSymbolMap.emplace( "EuDualSubslicesTotalCount", "XeCoreTotalCount" );

            globalSymbolMap.emplace( "SubsliceMask", "" );
            globalSymbolMap.emplace( "DualSubsliceMask", "XeCoreMask" );

            globalSymbolMap.emplace( "GtSubsliceMask", "" );
            globalSymbolMap.emplace( "GtDualSubsliceMask", "GtXeCoreMask" );
        }
        else
        {
            globalSymbolMap.emplace( "EuSubslicesTotalCount", "XeCoreTotalCount" );
            globalSymbolMap.emplace( "EuDualSubslicesTotalCount", "" );

            globalSymbolMap.emplace( "SubsliceMask", "XeCoreMask" );
            globalSymbolMap.emplace( "DualSubsliceMask", "" );

            globalSymbolMap.emplace( "GtSubsliceMask", "GtXeCoreMask" );
            globalSymbolMap.emplace( "GtDualSubsliceMask", "" );
        }

        // Not supported symbol names or old ones
        if( isXeHpgPlus )
        {
            if( globalSymbolMap.find( name ) != globalSymbolMap.end() )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Not supported symbol names or old ones: %s", globalSymbolName );
                return false;
            }
        }
        else
        {
            for( auto iterator = globalSymbolMap.begin(); iterator != globalSymbolMap.end(); ++iterator )
            {
                // Xe symbol but platform is not Xe
                if( iterator->second == name )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "Xe symbol but platform is not Xe: %s", globalSymbolName );
                    return false;
                }

                // Dual subslice/subslice support
                if( ( iterator->first == name ) && ( iterator->second == "" ) )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "%s symbol is not supported because platform %s dual subslices", globalSymbolName, useDualSubslice ? "supports" : "does not support" );
                    return false;
                }
            }
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name supported: %s", globalSymbolName ); // but it doesn't mean that global symbol will be added, for example some symbols are not supported on Linux.
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolUINT32
    //
    // Description:
    //     Adds 32-bit uint32_t symbol to the symbol set.
    //
    // Input:
    //     const char*  name       - symbol name
    //     uint32_t     value      - symbol value
    //     TSymbolType  symbolType - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolUINT32( const char* name, uint32_t value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType     = VALUE_TYPE_UINT32;
        typedValue.ValueUInt32   = value;
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolUINT64
    //
    // Description:
    //     Adds 64-bit uint64_t symbol to the symbol set.
    //
    // Input:
    //     const char*  name       - symbol name
    //     uint64_t     value      - symbol value
    //     TSymbolType  symbolType - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType     = VALUE_TYPE_UINT64;
        typedValue.ValueUInt64   = value;
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolBOOL
    //
    // Description:
    //     Adds boolean symbol to the symbol set.
    //
    // Input:
    //     const char*  name       - symbol name
    //     bool         value      - symbol value
    //     TSymbolType  symbolType - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolBOOL( const char* name, bool value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType     = VALUE_TYPE_BOOL;
        typedValue.ValueBool     = value;
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolFLOAT
    //
    // Description:
    //     Adds float symbol to the symbol set.
    //
    // Input:
    //     const char* name       - symbol name
    //     float       value      - symbol value
    //     TSymbolType symbolType - symbol type
    //
    // Output:
    //     TCompletionCode        - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType     = VALUE_TYPE_FLOAT;
        typedValue.ValueFloat    = value;
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolCSTRING
    //
    // Description:
    //     Adds cstring symbol to the symbol set.
    //
    // Input:
    //     const char* name       - symbol name
    //     const char* value      - symbol value
    //     TSymbolType symbolType - symbol type
    //
    // Output:
    //     TCompletionCode        - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolCSTRING( const char* name, char* value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType     = VALUE_TYPE_CSTRING;
        typedValue.ValueCString  = value;
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolBYTEARRAY
    //
    // Description:
    //     Adds byte array symbol to the symbol set.
    //
    // Input:
    //     const char*       name       - symbol name
    //     TByteArrayLatest* value      - symbol value
    //     TSymbolType       symbolType - symbol type
    //
    // Output:
    //     TCompletionCode              - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolBYTEARRAY( const char* name, TByteArrayLatest* value, TSymbolType symbolType )
    {
        TCompletionCode ret        = CC_OK;
        TTypedValue_1_0 typedValue = {};

        typedValue.ValueType      = VALUE_TYPE_BYTEARRAY;
        typedValue.ValueByteArray = value;
        const uint32_t adapterId  = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     WriteSymbolSetToFile
    //
    // Description:
    //     Writes symbol set to a file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::WriteSymbolSetToFile( FILE* metricFile )
    {
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();
        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        uint32_t symbolCount = m_symbolMap.size();
        fwrite( &symbolCount, sizeof( symbolCount ), 1, metricFile );
        for( auto& symbol : m_symbolMap )
        {
            // symbol_1_0
            WriteCStringToFile( symbol.second->symbol_1_0.SymbolName, metricFile, adapterId );
            WriteTTypedValueToFile( &symbol.second->symbol_1_0.SymbolTypedValue, metricFile, adapterId );
            fwrite( &symbol.second->symbolType, sizeof( symbol.second->symbolType ), 1, metricFile );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     IsSymbolAlreadyAdded
    //
    // Description:
    //     Checks if the symbol of the given name is already added to the symbol set.
    //
    // Input:
    //     std::string_view symbolName  - symbolic name of a symbol to check
    //
    // Output:
    //     bool                         - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSymbolSet::IsSymbolAlreadyAdded( std::string_view symbolName )
    {
        return m_symbolMap.find( symbolName ) != m_symbolMap.end();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     RedetectSymbol
    //
    // Description:
    //     Redetects (updates) the symbol value.
    //
    // Input:
    //     const char* name - name of a symbol to redetect
    //
    // Output:
    //     TCompletionCode  - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::RedetectSymbol( const char* symbolName )
    {
        TTypedValue_1_0* symbolValue = GetSymbolValueByName( symbolName );
        if( !symbolValue )
        {
            MD_LOG_A( m_metricsDevice.GetAdapter().GetAdapterId(), LOG_DEBUG, "Symbol doesn't exist, name: %s", symbolName );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return DetectSymbolValue( symbolName, *symbolValue );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     IsPavpDisabled
    //
    // Description:
    //     Checks if the PAVP_DISABLED bit in capabilities symbol is set.
    //
    // Output:
    //     bool - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSymbolSet::IsPavpDisabled( uint32_t capabilities )
    {
        return ( capabilities & GTDI_CAPABILITY_PAVP_DISABLED ) > 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     UnpackMask
    //
    // Description:
    //     Generate a separate global symbol for each instance from the mask
    //
    // Input:
    //     const TGlobalSymbol* symbol  - global symbol handle
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::UnpackMask( const TGlobalSymbol* symbol )
    {
        const uint32_t  platformIndex = m_metricsDevice.GetPlatformIndex();
        const char*     name          = symbol->symbol_1_0.SymbolName;
        uint8_t*        mask          = symbol->symbol_1_0.SymbolTypedValue.ValueByteArray->Data;
        TTypedValue_1_0 boolValue     = {};
        boolValue.ValueType           = VALUE_TYPE_BOOL;
        boolValue.ValueBool           = true;

        const bool useDualSubslice = IsPlatformMatch(
            platformIndex,
            GENERATION_MTL,
            GENERATION_ACM );

        // Unpack mask
        if( strcmp( name, "GtSliceMask" ) == 0 )
        {
            for( uint32_t i = 0; i < m_maxSlice; ++i )
            {
                uint32_t currentByte = i / MD_BITS_PER_BYTE;
                uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtSlice" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else if( const bool isXeCoreSymbol = strcmp( name, "GtXeCoreMask" ) == 0;
                 ( strcmp( name, "GtSubsliceMask" ) == 0 ) || ( !useDualSubslice && isXeCoreSymbol ) )
        {
            for( uint32_t i = 0; i < m_maxSlice; i++ )
            {
                for( uint32_t j = 0; j < m_maxSubslicePerSlice; j++ )
                {
                    uint32_t currentByte = ( i * m_maxSubslicePerSlice + j ) / MD_BITS_PER_BYTE;
                    uint32_t currentBit  = ( i * m_maxSubslicePerSlice + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtSlice" + std::to_string( i ) + ( ( isXeCoreSymbol ) ? "XeCore" : "Subslice" ) + std::to_string( j );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                    }
                }
            }
        }
        else if( const bool isXeCoreSymbol = strcmp( name, "GtXeCoreMask" ) == 0;
                 ( strcmp( name, "GtDualSubsliceMask" ) == 0 ) || ( useDualSubslice && isXeCoreSymbol ) )
        {
            constexpr uint32_t first4Slices                      = 4;
            TTypedValue_1_0    activeDualSubsliceForFirst4Slices = {};
            activeDualSubsliceForFirst4Slices.ValueType          = VALUE_TYPE_UINT32;
            activeDualSubsliceForFirst4Slices.ValueUInt32        = 0;

            for( uint32_t i = 0; i < m_maxSlice; i++ )
            {
                for( uint32_t j = 0; j < m_maxDualSubslicePerSlice; j++ )
                {
                    uint32_t currentByte = ( i * m_maxDualSubslicePerSlice + j ) / MD_BITS_PER_BYTE;
                    uint32_t currentBit  = ( i * m_maxDualSubslicePerSlice + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtSlice" + std::to_string( i ) + ( ( isXeCoreSymbol ) ? "XeCore" : "DualSubslice" ) + std::to_string( j );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );

                        // Count active dual subslices for first four slices
                        if( i < first4Slices )
                        {
                            ++activeDualSubsliceForFirst4Slices.ValueUInt32;
                        }
                    }
                }
            }

            if( IsPlatformMatch( platformIndex, GENERATION_XEHP_SDV ) )
            {
                AddSymbol( "EuDualSubslicesSlice0123Count", activeDualSubsliceForFirst4Slices, SYMBOL_TYPE_IMMEDIATE );
            }
        }
        else
        {
            MD_LOG_A( m_metricsDevice.GetAdapter().GetAdapterId(), LOG_WARNING, "%s - unknown mask, cannot unpack", name );
        }

        return CC_OK;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     DetectMaxSlicesInfo
    //
    // Description:
    //     Gets information about max slices, max subslices per slice and
    //     max dual subslices per slice sending escapes to KMD.
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::DetectMaxSlicesInfo()
    {
        TCompletionCode           ret       = CC_OK;
        GTDIDeviceInfoParamExtOut out       = {};
        const uint32_t            adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SLICE, &out );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE, &out );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxSubslicePerSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE, &out );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxDualSubslicePerSlice = out.ValueUint32;

        return CC_OK;
    }
} // namespace MetricsDiscoveryInternal
