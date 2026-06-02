/*========================== begin_copyright_notice ============================

Copyright (C) 2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_register_manager.h

//     Abstract:   C++ Metrics Discovery internal register manager header

#pragma once

#include "metrics_discovery_internal_api.h"

#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Structure:
    //     SRegisterMaskValue
    //
    // Description:
    //     Register, mask and value.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SRegisterMaskValue
    {
        uint32_t Address;
        uint32_t Mask;
        uint32_t Value;

        SRegisterMaskValue()
            : Address( 0u )
            , Mask( 0u )
            , Value( 0u )
        {
        }

        SRegisterMaskValue( const uint32_t address, const uint32_t mask, const uint32_t value )
            : Address( address )
            , Mask( mask )
            , Value( value )
        {
        }
    } TRegisterMaskValue;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Description:
    //     The class provides to perform register address, its mask and value
    //     manipulations.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CRegisterManager
    {
    private:
        std::vector<TRegisterMaskValue> m_registers;
        std::vector<TRegisterMaskValue> m_squashedRegisters;

    public:
        CRegisterManager();
        TCompletionCode                  AddRegister( const uint32_t address, const uint32_t mask, const uint32_t value );
        TCompletionCode                  RemoveRegister( const uint32_t address, const uint32_t mask, const uint32_t value );
        void                             SquashRegisters();
        std::vector<TRegisterMaskValue>& GetRegistersVector();
        void                             ClearRegistersVector();
    };
} // namespace MetricsDiscoveryInternal
