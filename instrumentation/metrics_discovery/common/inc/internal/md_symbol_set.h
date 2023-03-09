/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_symbol_set.h

//     Abstract:   C++ Metrics Discovery internal symbol set header

#pragma once

#include "md_types.h"

#include <cstdio>
#include <unordered_map>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CDriverInterface;
    class CMetricsDevice;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CGlobalSymbolSet
    //
    // Description:
    //     Collection of global symbols with methods to add them.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CSymbolSet
    {
    public:
        // Constructor & Destructor:
        CSymbolSet( CMetricsDevice& metricsDevice, CDriverInterface& driverInterface );
        ~CSymbolSet();

        // Non-API:
        uint32_t             GetSymbolCount();
        TGlobalSymbolLatest* GetSymbol( uint32_t index );
        TTypedValueLatest*   GetSymbolValueByName( const char* name );
        TCompletionCode      AddSymbol( const char* name, TTypedValueLatest typedValue, TSymbolType symbolType );
        TCompletionCode      DetectSymbolValue( std::string_view name, TTypedValueLatest& typedValue );
        TCompletionCode      AddSymbolUINT32( const char* name, uint32_t value, TSymbolType symbolType );
        TCompletionCode      AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType );
        TCompletionCode      AddSymbolBOOL( const char* name, bool value, TSymbolType symbolType );
        TCompletionCode      AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType );
        TCompletionCode      AddSymbolCSTRING( const char* name, char* value, TSymbolType symbolType );
        TCompletionCode      AddSymbolBYTEARRAY( const char* name, TByteArrayLatest* value, TSymbolType symbolType );
        TCompletionCode      WriteSymbolSetToFile( FILE* metricFile );
        bool                 IsSymbolAlreadyAdded( std::string_view symbolName );
        TCompletionCode      RedetectSymbol( const char* name );

    private:
        bool            IsPavpDisabled( uint32_t capabilities );
        TCompletionCode UnpackMask( const TGlobalSymbol* symbol );
        TCompletionCode DetectMaxSlicesInfo();
        bool            IsSymbolNameSupported( std::string_view name );

    private:
        // Variables:
        std::unordered_map<std::string_view, TGlobalSymbol*> m_symbolMap;
        CMetricsDevice&                                      m_metricsDevice;
        CDriverInterface&                                    m_driverInterface;
        uint32_t                                             m_maxSlice;
        uint32_t                                             m_maxSubslicePerSlice;
        uint32_t                                             m_maxDualSubslicePerSlice;

    private:
        // Static variables:
        static constexpr uint32_t SYMBOLS_MAP_INCREASE = 32;
    };
} // namespace MetricsDiscoveryInternal
