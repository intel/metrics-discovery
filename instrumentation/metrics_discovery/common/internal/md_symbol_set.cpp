/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_symbol_set.cpp

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
        , m_maxL3Node( 0 )
        , m_maxL3BankPerL3Node( 0 )
        , m_maxCopyEngine( 0 )
    {
        m_symbolMap.reserve( SYMBOLS_MAP_RESERVE );
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
            MD_SAFE_DELETE_ARRAY( symbol.second->symbol.SymbolName );
            if( symbol.second->symbol.SymbolTypedValue.ValueType == VALUE_TYPE_CSTRING )
            {
                MD_SAFE_DELETE_ARRAY( symbol.second->symbol.SymbolTypedValue.ValueCString );
            }
            else if( symbol.second->symbol.SymbolTypedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                MD_SAFE_DELETE_ARRAY( symbol.second->symbol.SymbolTypedValue.ValueByteArray->Data );
                MD_SAFE_DELETE( symbol.second->symbol.SymbolTypedValue.ValueByteArray );
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
        return static_cast<uint32_t>( m_symbolMap.size() );
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
    //     uint32_t index - index of symbol
    //
    // Output:
    //     TGlobalSymbol* - pointer to the symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbol* CSymbolSet::GetSymbol( uint32_t index )
    {
        if( index < m_symbolMap.size() )
        {
            auto iterator = m_symbolMap.begin();
            std::advance( iterator, index );
            return iterator->second;
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbolByName
    //
    // Description:
    //     Returns chosen symbol by name or nullptr if not exists.
    //
    // Input:
    //     std::string_view name - name of symbol
    //
    // Output:
    //     TGlobalSymbol*        - pointer to symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbol* CSymbolSet::GetSymbolByName( std::string_view name )
    {
        auto symbol = m_symbolMap.find( name );

        return ( symbol != m_symbolMap.end() )
            ? symbol->second
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

        if( symbolType == SYMBOL_TYPE_DETECT || symbolType == SYMBOL_TYPE_DYNAMIC )
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

        symbol->version           = API_VERSION_1_0;
        symbol->symbolType        = symbolType;
        symbol->symbol.SymbolName = GetCopiedCString( name, adapterId );
        if( typedValue.ValueType == VALUE_TYPE_CSTRING )
        {
            symbol->symbol.SymbolTypedValue.ValueType    = typedValue.ValueType;
            symbol->symbol.SymbolTypedValue.ValueCString = ( symbolType == SYMBOL_TYPE_DETECT || symbolType == SYMBOL_TYPE_DYNAMIC )
                ? typedValue.ValueCString // CString is already copied
                : GetCopiedCString( typedValue.ValueCString, adapterId );
        }
        else if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
        {
            symbol->symbol.SymbolTypedValue.ValueType      = typedValue.ValueType;
            symbol->symbol.SymbolTypedValue.ValueByteArray = ( symbolType == SYMBOL_TYPE_DETECT || symbolType == SYMBOL_TYPE_DYNAMIC )
                ? typedValue.ValueByteArray // ByteArray is already copied
                : GetCopiedByteArray( typedValue.ValueByteArray, adapterId );
        }
        else
        {
            symbol->symbol.SymbolTypedValue = typedValue;
        }
        m_symbolMap.emplace( symbol->symbol.SymbolName, symbol );

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
            // Only on ACM, MTL and ARL dual subslices are used to calculate XeCore global symbols.
            GENERATION_MTL,
            GENERATION_ARL,
            GENERATION_ACM );

        if( name == "EuCoresTotalCount" || name == "VectorEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuCoresPerSubsliceCount" || name == "VectorEnginePerXeCoreCount" )
        {
            // ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT, out, m_metricsDevice );
            // TODO: windows driver interface refactoring is needed.

            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, out, m_metricsDevice );
            if( ret == CC_OK )
            {
                uint32_t euCoresTotalCount = out.ValueUint32;

                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT, out, m_metricsDevice );
                if( ret != CC_OK || out.ValueUint32 == 0 )
                {
                    ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, out, m_metricsDevice );
                }
                else
                {
                    const bool isSubsliceAvailable = IsPlatformMatch( platformIndex, GENERATION_TGL, GENERATION_DG1, GENERATION_ADLP, GENERATION_ADLS, GENERATION_ADLN );
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
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuDualSubslicesTotalCount" || ( useDualSubslice && ( name == "XeCoreTotalCount" ) ) )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuSlicesTotalCount" || name == "SliceTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "EuThreadsCount" || name == "VectorEngineThreadsCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_THREADS_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "GtSliceMask" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_MASK, out, m_metricsDevice );
            if( ret == CC_OK )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }

                const uint32_t byteArraySize = RoundUp( m_maxSlice / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
                TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
                typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
            }
        }
        else if( name == "GtSubsliceMask" || ( !useDualSubslice && ( name == "GtXeCoreMask" ) ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_MASK, out, m_metricsDevice );
            if( ret == CC_OK )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }

                const uint32_t byteArraySize = RoundUp( m_maxSubslicePerSlice * m_maxSlice / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
                TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
                typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
            }
        }
        else if( name == "GtDualSubsliceMask" || ( useDualSubslice && ( name == "GtXeCoreMask" ) ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK, out, m_metricsDevice );
            if( ret == CC_OK )
            {
                if( typedValue.ValueByteArray != nullptr )
                {
                    DeleteByteArray( typedValue.ValueByteArray, adapterId );
                }

                const uint32_t byteArraySize = RoundUp( m_maxDualSubslicePerSlice * m_maxSlice / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
                TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
                typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
            }
        }
        else if( name == "SamplersTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SAMPLERS_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "MemoryPeakThroghputMB" )
        {
            if( m_metricsDevice.GetAdapter().GetParams()->Type == ADAPTER_TYPE_INTEGRATED )
            {
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT, out, m_metricsDevice );
                typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 / static_cast<uint64_t>( MD_MBYTE ) );
            }
            else
            {
                return CC_ERROR_NOT_SUPPORTED;
            }
        }
        else if( name == "GpuMinFrequencyMHz" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY, out, m_metricsDevice );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG_A( adapterId, LOG_WARNING, "%.*s not available, GpuCurrentFrequencyMHz used instead", static_cast<uint32_t>( name.length() ), name.data() );
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, out, m_metricsDevice );
                typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
            }
            else
            {
                typedValue.ValueUInt32 = out.ValueUint32;
            }
        }
        else if( name == "GpuMaxFrequencyMHz" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY, out, m_metricsDevice );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG_A( adapterId, LOG_WARNING, "%.*s not available, GpuCurrentFrequencyMHz used instead", static_cast<uint32_t>( name.length() ), name.data() );
                ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, out, m_metricsDevice );
                typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
            }
            else
            {
                typedValue.ValueUInt32 = out.ValueUint32;
            }
        }
        else if( name == "GpuCurrentFrequencyMHz" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
        }
        else if( name == "GpuFrequencyOverrideEnabled" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_STATIC_FREQUENCY_OVERRIDE, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "PciDeviceId" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PCI_DEVICE_ID, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SkuRevisionId" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_REVISION_ID, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "SkuRevisionId is %u", typedValue.ValueUInt32 );
        }
        else if( name == "PlatformIndex" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "PlatformIndex is %u", typedValue.ValueUInt32 );
        }
        else if( name == "ApertureSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_APERTURE_SIZE, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "Capabilities" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "PavpDisabled" )
        {
            ret                  = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, out, m_metricsDevice );
            typedValue.ValueBool = IsPavpDisabled( out.ValueUint32 );
        }
        else if( name == "NumberOfRenderOutputUnits" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "NumberOfShadingUnits" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "OABufferMinSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_DEFAULT, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "OABufferMaxSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_DEFAULT, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "MediaOABufferMinSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_OAM_SLICE_0, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "MediaOABufferMaxSize" )
        {
            ret                    = m_driverInterface.GetMaxMinOaBufferSize( GTDI_OA_BUFFER_TYPE_OAM_SLICE_0, GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "GpuTimestampFrequency" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, out, m_metricsDevice );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "EdramSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EDRAM_SIZE, out, m_metricsDevice );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "LLCSize" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_LLC_SIZE, out, m_metricsDevice );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "L3Size" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_SIZE, out, m_metricsDevice );
            typedValue.ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 );
        }
        else if( name == "MaxTimestamp" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, out, m_metricsDevice );

            typedValue.ValueUInt64 = m_metricsDevice.ConvertGpuTimestampToNs( ( std::numeric_limits<uint64_t>::max )(), out.ValueUint64 );
            if( typedValue.ValueUInt64 == 0 )
            {
                ret = CC_ERROR_GENERAL;
            }
        }
        else if( name == "L3BankTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_BANK_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "L3NodeTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_NODE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "SqidiTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SQIDI_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "PlatformVersion" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_VERSION, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
            MD_LOG_A( adapterId, LOG_INFO, "PlatformVersion is %u", typedValue.ValueUInt32 );
        }
        else if( name == "ComputeEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COMPUTE_ENGINE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "CopyEngineTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COPY_ENGINE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "GtL3BankMask" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_BANK_MASK, out, m_metricsDevice );

            if( typedValue.ValueByteArray != nullptr )
            {
                DeleteByteArray( typedValue.ValueByteArray, adapterId );
            }

            const uint32_t byteArraySize = RoundUp( m_maxL3Node * m_maxL3BankPerL3Node / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
            TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
            typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
        }
        else if( name == "GtL3NodeMask" || name == "GtSqidiMask" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_NODE_MASK, out, m_metricsDevice );

            if( typedValue.ValueByteArray != nullptr )
            {
                DeleteByteArray( typedValue.ValueByteArray, adapterId );
            }

            const uint32_t byteArraySize = RoundUp( m_maxL3Node / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
            TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
            typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
        }
        else if( name == "GtCopyEngineMask" )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COPY_ENGINE_MASK, out, m_metricsDevice );

            if( typedValue.ValueByteArray != nullptr )
            {
                DeleteByteArray( typedValue.ValueByteArray, adapterId );
            }

            const uint32_t byteArraySize = RoundUp( m_maxCopyEngine / MD_BITS_PER_BYTE, MD_BYTE_ARRAY_MIN_SIZE );
            TByteArray_1_0 byteArray     = { byteArraySize, out.ValueByteArray };
            typedValue.ValueByteArray    = GetCopiedByteArray( &byteArray, adapterId );
        }
        else if( name == "ColorPipeTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_COLOR_PIPE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "DepthPipeTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DEPTH_PIPE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "GeometryPipeTotalCount" )
        {
            ret                    = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GEOMETRY_PIPE_TOTAL_COUNT, out, m_metricsDevice );
            typedValue.ValueUInt32 = out.ValueUint32;
        }
        else if( name == "QueryMode" )
        {
            typedValue.ValueUInt32 = static_cast<uint32_t>( m_metricsDevice.GetQueryMode() );
        }
        else
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unknown global symbol name: %.*s", static_cast<uint32_t>( name.length() ), name.data() );
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
        const uint32_t adapterId     = m_metricsDevice.GetAdapter().GetAdapterId();
        const uint32_t platformIndex = m_metricsDevice.GetPlatformIndex();

        bool isPlatformVersionSupported = false;
        bool isNewTermUsed              = false;
        bool isDualSubsliceUsed         = false;
        bool isOamSupported             = false;
        bool isL3BankSupported          = false;
        bool isXe2Plus                  = false;

        switch( platformIndex )
        {
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_RKL:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
                isDualSubsliceUsed = true;
                break;

            case GENERATION_ACM:
                isNewTermUsed      = true;
                isDualSubsliceUsed = true;
                break;

            case GENERATION_PVC:
                isNewTermUsed     = true;
                isL3BankSupported = true;
                break;

            case GENERATION_MTL:
            case GENERATION_ARL:
                isNewTermUsed      = true;
                isDualSubsliceUsed = true;
                isOamSupported     = true;
                break;

            case GENERATION_BMG:
            case GENERATION_PTL:
                isPlatformVersionSupported = true;
                isNewTermUsed              = true;
                isOamSupported             = true;
                isL3BankSupported          = true;
                isXe2Plus                  = true;
                break;

            case GENERATION_LNL:
                isNewTermUsed     = true;
                isOamSupported    = true;
                isL3BankSupported = true;
                isXe2Plus         = true;
                break;

            default:
                break;
        }

        if( name == "PlatformVersion" )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name is%s supported: %.*s", isPlatformVersionSupported ? "" : " not", static_cast<uint32_t>( name.length() ), name.data() );
            return isPlatformVersionSupported;
        }

        // Media related global symbols
        if( name == "MediaOABufferMinSize" || name == "MediaOABufferMaxSize" )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Media symbol name is%s supported: %.*s", isOamSupported ? "" : " not", static_cast<uint32_t>( name.length() ), name.data() );
            return isOamSupported;
        }

        if( name == "L3BankTotalCount" )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name is%s supported: %.*s", isL3BankSupported ? "" : " not", static_cast<uint32_t>( name.length() ), name.data() );
            return isL3BankSupported;
        }

        // Xe2+ related global symbols
        if( name == "L3NodeTotalCount" ||
            name == "SqidiTotalCount" ||
            name == "ComputeEngineTotalCount" ||
            name == "CopyEngineTotalCount" ||
            name == "QueryMode" ||
            name == "GtL3BankMask" ||
            name == "GtL3NodeMask" ||
            name == "GtSqidiMask" ||
            name == "GtCopyEngineMask" ||
            name == "ColorPipeTotalCount" ||
            name == "DepthPipeTotalCount" ||
            name == "GeometryPipeTotalCount" )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name is%s supported: %.*s", isXe2Plus ? "" : " not", static_cast<uint32_t>( name.length() ), name.data() );
            return isXe2Plus;
        }

        if( name == "L3Size" ||
            name == "MemoryPeakThroghputMB" ||
            name == "ApertureSize" ||
            name == "LLCSize" ||
            name == "EdramSize" ||
            name == "NumberOfShadingUnits" ||
            name == "NumberOfRenderOutputUnits" )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name is%s supported: %.*s", isXe2Plus ? " not" : "", static_cast<uint32_t>( name.length() ), name.data() );
            return !isXe2Plus;
        }

        std::map<std::string_view, std::string_view> globalSymbolMap{
            { "EuCoresTotalCount", "VectorEngineTotalCount" },
            { "EuCoresPerSubsliceCount", "VectorEnginePerXeCoreCount" },
            { "EuSlicesTotalCount", "SliceTotalCount" },
            { "EuThreadsCount", "VectorEngineThreadsCount" },
        };

        if( isDualSubsliceUsed )
        {
            globalSymbolMap.emplace( "EuSubslicesTotalCount", "" );
            globalSymbolMap.emplace( "EuDualSubslicesTotalCount", "XeCoreTotalCount" );

            globalSymbolMap.emplace( "GtSubsliceMask", "" );
            globalSymbolMap.emplace( "GtDualSubsliceMask", "GtXeCoreMask" );
        }
        else
        {
            globalSymbolMap.emplace( "EuSubslicesTotalCount", "XeCoreTotalCount" );
            globalSymbolMap.emplace( "EuDualSubslicesTotalCount", "" );

            globalSymbolMap.emplace( "GtSubsliceMask", "GtXeCoreMask" );
            globalSymbolMap.emplace( "GtDualSubsliceMask", "" );
        }

        // Not supported symbol names or old ones
        if( isNewTermUsed )
        {
            if( globalSymbolMap.find( name ) != globalSymbolMap.end() )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Not supported symbol names or old ones: %.*s", static_cast<uint32_t>( name.length() ), name.data() );
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
                    MD_LOG_A( adapterId, LOG_DEBUG, "Xe symbol but platform is not Xe: %.*s", static_cast<uint32_t>( name.length() ), name.data() );
                    return false;
                }

                // Dual subslice/subslice support
                if( ( iterator->first == name ) && ( iterator->second == "" ) )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "%.*s symbol is not supported because platform %s dual subslices", static_cast<uint32_t>( name.length() ), name.data(), isDualSubsliceUsed ? "supports" : "does not support" );
                    return false;
                }
            }
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "Symbol name supported: %.*s", static_cast<uint32_t>( name.length() ), name.data() ); // but it doesn't mean that global symbol will be added, for example some symbols are not supported on Linux.
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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_UINT32;
        typedValue.ValueUInt32     = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_UINT64;
        typedValue.ValueUInt64     = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_BOOL;
        typedValue.ValueBool       = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_FLOAT;
        typedValue.ValueFloat      = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_CSTRING;
        typedValue.ValueCString    = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

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
        const uint32_t adapterId = m_metricsDevice.GetAdapter().GetAdapterId();

        TTypedValue_1_0 typedValue = {};
        typedValue.ValueType       = VALUE_TYPE_BYTEARRAY;
        typedValue.ValueByteArray  = value;

        const auto ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG_A( adapterId, ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     WriteSymbolSetToBuffer
    //
    // Description:
    //     Writes symbol set to a buffer.
    //
    // Input:
    //     uint8_t*  buffer       - pointer to a buffer
    //     uint32_t& bufferSize   - size of the buffer
    //     uint32_t& bufferOffset - the current offset of the buffer
    //
    // Output:
    //     TCompletionCode        - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::WriteSymbolSetToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset )
    {
        const uint32_t  adapterId = m_metricsDevice.GetAdapter().GetAdapterId();
        TCompletionCode result    = CC_OK;

        const uint32_t symbolCount = static_cast<uint32_t>( m_symbolMap.size() );

        result = WriteDataToBuffer( (void*) &symbolCount, sizeof( symbolCount ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        for( auto& symbol : m_symbolMap )
        {
            result = WriteCStringToBuffer( symbol.second->symbol.SymbolName, buffer, bufferSize, bufferOffset, adapterId );
            MD_CHECK_CC_RET_A( adapterId, result );

            result = WriteTTypedValueToBuffer( &symbol.second->symbol.SymbolTypedValue, buffer, bufferSize, bufferOffset, adapterId );
            MD_CHECK_CC_RET_A( adapterId, result );

            result = WriteDataToBuffer( &symbol.second->symbolType, sizeof( symbol.second->symbolType ), buffer, bufferSize, bufferOffset, adapterId );
            MD_CHECK_CC_RET_A( adapterId, result );
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
    //     std::string_view name - name of a symbol to redetect
    //
    // Output:
    //     TCompletionCode       - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::RedetectSymbol( std::string_view symbolName )
    {
        TGlobalSymbol* symbol = GetSymbolByName( symbolName );

        if( !symbol )
        {
            MD_LOG_A( m_metricsDevice.GetAdapter().GetAdapterId(), LOG_DEBUG, "Symbol doesn't exist, name: %.*s", static_cast<uint32_t>( symbolName.length() ), symbolName.data() );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return ( symbol->symbolType == SYMBOL_TYPE_DYNAMIC )
            ? DetectSymbolValue( symbolName, symbol->symbol.SymbolTypedValue )
            : CC_OK;
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
        TCompletionCode           ret           = CC_OK;
        GTDIDeviceInfoParamExtOut out           = {};
        const uint32_t            adapterId     = m_metricsDevice.GetAdapter().GetAdapterId();
        const uint32_t            platformIndex = m_metricsDevice.GetPlatformIndex();

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SLICE, out, m_metricsDevice );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE, out, m_metricsDevice );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxSubslicePerSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE, out, m_metricsDevice );
        MD_CHECK_CC_RET_A( adapterId, ret )
        m_maxDualSubslicePerSlice = out.ValueUint32;

        switch( platformIndex )
        {
            case GENERATION_BMG:
            case GENERATION_LNL:
            case GENERATION_PTL:
            {
                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_L3_NODE, out, m_metricsDevice );
                MD_CHECK_CC_RET_A( adapterId, ret )
                m_maxL3Node = out.ValueUint32;

                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_L3_BANK_PER_L3_NODE, out, m_metricsDevice );
                MD_CHECK_CC_RET_A( adapterId, ret )
                m_maxL3BankPerL3Node = out.ValueUint32;

                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_COPY_ENGINE, out, m_metricsDevice );
                MD_CHECK_CC_RET_A( adapterId, ret )
                m_maxCopyEngine = out.ValueUint32;

                break;
            }

            default:
                break;
        }

        return CC_OK;
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
        const uint32_t   platformIndex = m_metricsDevice.GetPlatformIndex();
        std::string_view name          = symbol->symbol.SymbolName;
        const uint32_t   maskSize      = symbol->symbol.SymbolTypedValue.ValueByteArray->Size;
        uint8_t*         mask          = symbol->symbol.SymbolTypedValue.ValueByteArray->Data;
        TTypedValue_1_0  boolValue     = {};
        boolValue.ValueType            = VALUE_TYPE_BOOL;
        boolValue.ValueBool            = true;

        bool useDualSubslice = false;
        bool isXe2Plus       = false;

        switch( platformIndex )
        {
            case GENERATION_MTL:
            case GENERATION_ARL:
            case GENERATION_ACM:
                useDualSubslice = true;
                break;

            case GENERATION_BMG:
            case GENERATION_LNL:
            case GENERATION_PTL:
                isXe2Plus = true;
                break;

            default:
                break;
        }

        // Unpack mask
        if( name == "GtSliceMask" )
        {
            const uint32_t maxSlice = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxSlice );

            for( uint32_t i = 0; i < maxSlice; ++i )
            {
                const uint32_t currentByte = i / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtSlice" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else if( const bool isXeCoreSymbol = name == "GtXeCoreMask";
                 name == "GtSubsliceMask" || ( !useDualSubslice && isXeCoreSymbol ) )
        {
            const char* subSliceString = ( isXeCoreSymbol ) ? "XeCore" : "Subslice";

            const uint32_t maxSlice = ( m_maxSubslicePerSlice != 0 )
                ? ( std::min )( maskSize * MD_BITS_PER_BYTE / m_maxSubslicePerSlice, m_maxSlice )
                : 0;

            for( uint32_t i = 0; i < maxSlice; ++i )
            {
                for( uint32_t j = 0; j < m_maxSubslicePerSlice; ++j )
                {
                    const uint32_t subsliceIndex = i * m_maxSubslicePerSlice + j;
                    const uint32_t currentByte   = subsliceIndex / MD_BITS_PER_BYTE;
                    const uint32_t currentBit    = subsliceIndex % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = ( isXe2Plus )
                            ? "GtXeCore" + std::to_string( i * m_maxSubslicePerSlice + j ) // For Xe2 actual max number must be used.
                            : "GtSlice" + std::to_string( i ) + subSliceString + std::to_string( j );

                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                    }
                }
            }
        }
        else if( name == "GtDualSubsliceMask" || ( useDualSubslice && isXeCoreSymbol ) )
        {
            const char* dualSubSliceString = ( isXeCoreSymbol ) ? "XeCore" : "DualSubslice";

            const uint32_t maxSlice = ( m_maxDualSubslicePerSlice != 0 )
                ? ( std::min )( maskSize * MD_BITS_PER_BYTE / m_maxDualSubslicePerSlice, m_maxSlice )
                : 0;

            for( uint32_t i = 0; i < maxSlice; ++i )
            {
                for( uint32_t j = 0; j < m_maxDualSubslicePerSlice; ++j )
                {
                    const uint32_t dualSubsliceIndex = i * m_maxDualSubslicePerSlice + j;
                    const uint32_t currentByte       = dualSubsliceIndex / MD_BITS_PER_BYTE;
                    const uint32_t currentBit        = dualSubsliceIndex % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtSlice" + std::to_string( i ) + dualSubSliceString + std::to_string( j );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                    }
                }
            }
        }
        else if( name == "GtL3BankMask" )
        {
            const uint32_t maxL3Node = ( m_maxL3BankPerL3Node != 0 )
                ? ( std::min )( maskSize * MD_BITS_PER_BYTE / m_maxL3BankPerL3Node, m_maxL3Node )
                : m_maxL3BankPerL3Node;

            for( uint32_t i = 0; i < maxL3Node; ++i )
            {
                for( uint32_t j = 0; j < m_maxL3BankPerL3Node; ++j )
                {
                    const uint32_t l3BankIndex = i * m_maxL3BankPerL3Node + j;
                    const uint32_t currentByte = ( l3BankIndex ) / MD_BITS_PER_BYTE;
                    const uint32_t currentBit  = ( l3BankIndex ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtL3Bank" + std::to_string( l3BankIndex );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                    }
                }
            }
        }
        else if( name == "GtL3NodeMask" )
        {
            const uint32_t maxL3Node = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxL3Node );

            for( uint32_t i = 0; i < maxL3Node; ++i )
            {
                const uint32_t currentByte = ( i ) / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = ( i ) % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtL3Node" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else if( name == "GtSqidiMask" )
        {
            const uint32_t maxL3Node = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxL3Node );

            for( uint32_t i = 0; i < maxL3Node; ++i )
            {
                const uint32_t currentByte = ( i ) / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = ( i ) % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtSqidi" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else if( name == "GtCopyEngineMask" )
        {
            const uint32_t maxCopyEngine = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxCopyEngine );

            for( uint32_t i = 0; i < maxCopyEngine; ++i )
            {
                const uint32_t currentByte = ( i ) / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = ( i ) % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtCopyEngine" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else
        {
            MD_LOG_A( m_metricsDevice.GetAdapter().GetAdapterId(), LOG_WARNING, "%s - unknown mask, cannot unpack", symbol->symbol.SymbolName );
        }

        return CC_OK;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     UnpackMaskToValidValues
    //
    // Description:
    //     Unpack mask of the global symbol and assign validValues based on it
    //
    // Input:
    //     std::string_view    name            - global symbol name.
    //     TByteArrayLatest*   byteArray       - global symbol mask and its size.
    //     uint32_t&           validValueCount - valid values count.
    //     TValidValueLatest*& validValues     - validValues array.
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::UnpackMaskToValidValues( std::string_view name, TByteArrayLatest* byteArray, uint32_t& validValueCount, TValidValueLatest*& validValues )
    {
        const uint32_t    adapterId = m_metricsDevice.GetAdapter().GetAdapterId();
        const uint32_t    maskSize  = byteArray->Size;
        uint8_t*          mask      = byteArray->Data;
        uint32_t          index     = 0;
        TValidValueLatest localValidValues[64];

        // Unpack mask
        if( name == "GtSliceMask" )
        {
            const uint32_t maxSlice = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxSlice );

            for( uint32_t i = 0; i < maxSlice; ++i )
            {
                const uint32_t currentByte = i / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    localValidValues[index].ValueType   = VALUE_TYPE_UINT32;
                    localValidValues[index].ValueUInt32 = i;
                    ++index;
                }
            }
        }
        else if( name == "GtXeCoreMask" )
        {
            const uint32_t maxSlice = ( m_maxSubslicePerSlice != 0 )
                ? ( std::min )( maskSize * MD_BITS_PER_BYTE / m_maxSubslicePerSlice, m_maxSlice )
                : 0;

            for( uint32_t i = 0; i < maxSlice; ++i )
            {
                for( uint32_t j = 0; j < m_maxSubslicePerSlice; ++j )
                {
                    const uint32_t currentByte = ( i * m_maxSubslicePerSlice + j ) / MD_BITS_PER_BYTE;
                    const uint32_t currentBit  = ( i * m_maxSubslicePerSlice + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        localValidValues[index].ValueType   = VALUE_TYPE_UINT32;
                        localValidValues[index].ValueUInt32 = i * m_maxSubslicePerSlice + j;
                        ++index;
                    }
                }
            }
        }
        else if( name == "GtL3BankMask" )
        {
            const uint32_t maxL3Node = ( m_maxL3BankPerL3Node != 0 )
                ? ( std::min )( maskSize * MD_BITS_PER_BYTE / m_maxL3BankPerL3Node, m_maxL3Node )
                : 0;

            for( uint32_t i = 0; i < maxL3Node; ++i )
            {
                for( uint32_t j = 0; j < m_maxL3BankPerL3Node; ++j )
                {
                    const uint32_t currentByte = ( i * m_maxL3BankPerL3Node + j ) / MD_BITS_PER_BYTE;
                    const uint32_t currentBit  = ( i * m_maxL3BankPerL3Node + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        localValidValues[index].ValueType   = VALUE_TYPE_UINT32;
                        localValidValues[index].ValueUInt32 = i * m_maxL3BankPerL3Node + j;
                        ++index;
                    }
                }
            }
        }
        else if( name == "GtSqidiMask" || name == "GtL3NodeMask" )
        {
            const uint32_t maxL3Node = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxL3Node );

            for( uint32_t i = 0; i < maxL3Node; ++i )
            {
                const uint32_t currentByte = i / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    localValidValues[index].ValueType   = VALUE_TYPE_UINT32;
                    localValidValues[index].ValueUInt32 = i;
                    ++index;
                }
            }
        }
        else if( name == "GtCopyEngineMask" )
        {
            const uint32_t maxCopyEngine = ( std::min )( maskSize * MD_BITS_PER_BYTE, m_maxCopyEngine );

            for( uint32_t i = 0; i < maxCopyEngine; ++i )
            {
                const uint32_t currentByte = i / MD_BITS_PER_BYTE;
                const uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    localValidValues[index].ValueType   = VALUE_TYPE_UINT32;
                    localValidValues[index].ValueUInt32 = i;
                    ++index;
                }
            }
        }
        else
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: not supported symbol" );
        }

        validValueCount = index;
        validValues     = new( std::nothrow ) TValidValueLatest[validValueCount]();

        if( validValues == nullptr )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: validValues" );
            return CC_ERROR_NO_MEMORY;
        }

        return ( iu_memcpy_s( validValues, validValueCount * sizeof( TValidValueLatest ), localValidValues, validValueCount * sizeof( TValidValueLatest ) ) )
            ? CC_OK
            : CC_ERROR_GENERAL;
    }
} // namespace MetricsDiscoveryInternal
