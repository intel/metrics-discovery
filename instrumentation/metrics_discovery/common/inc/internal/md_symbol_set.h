/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

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

        CSymbolSet( const CSymbolSet& )            = delete; // Delete copy-constructor
        CSymbolSet& operator=( const CSymbolSet& ) = delete; // Delete assignment operator

        // Non-API:
        uint32_t        GetSymbolCount();
        TGlobalSymbol*  GetSymbol( uint32_t index );
        TGlobalSymbol*  GetSymbolByName( std::string_view name );
        TCompletionCode AddSymbol( const char* name, TTypedValueLatest typedValue, TSymbolType symbolType );
        TCompletionCode DetectSymbolValue( std::string_view name, TTypedValueLatest& typedValue );
        TCompletionCode AddSymbolUINT32( const char* name, uint32_t value, TSymbolType symbolType );
        TCompletionCode AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType );
        TCompletionCode AddSymbolBOOL( const char* name, bool value, TSymbolType symbolType );
        TCompletionCode AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType );
        TCompletionCode AddSymbolCSTRING( const char* name, char* value, TSymbolType symbolType );
        TCompletionCode AddSymbolBYTEARRAY( const char* name, TByteArrayLatest* value, TSymbolType symbolType );
        TCompletionCode WriteSymbolSetToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset );
        bool            IsSymbolAlreadyAdded( std::string_view symbolName );
        TCompletionCode RedetectSymbol( std::string_view name );
        TCompletionCode DetectMaxSlicesInfo();
        TCompletionCode UnpackMaskToValidValues( std::string_view name, TByteArrayLatest* byteArray, uint32_t& validValueCount, TValidValueLatest*& validValues );

    private:
        bool            IsPavpDisabled( uint32_t capabilities );
        TCompletionCode UnpackMask( const TGlobalSymbol* symbol );
        bool            IsSymbolNameSupported( std::string_view name );

    private:
        // Variables:
        std::unordered_map<std::string_view, TGlobalSymbol*> m_symbolMap;
        CMetricsDevice&                                      m_metricsDevice;
        CDriverInterface&                                    m_driverInterface;
        uint32_t                                             m_maxSlice;
        uint32_t                                             m_maxSubslicePerSlice;
        uint32_t                                             m_maxDualSubslicePerSlice;
        uint32_t                                             m_maxL3Node;
        uint32_t                                             m_maxL3BankPerL3Node;
        uint32_t                                             m_maxCopyEngine;

    private:
        // Static variables:
        static constexpr uint32_t SYMBOLS_MAP_RESERVE = 32;
    };
} // namespace MetricsDiscoveryInternal
