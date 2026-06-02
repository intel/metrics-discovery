/*========================== begin_copyright_notice ============================

Copyright (C) 2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_register_manager.cpp

//     Abstract:   C++ Metrics Discovery internal register manager implementation

#include <algorithm>
#include <vector>

#include "md_register_manager.h"

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     CRegisterManager constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CRegisterManager::CRegisterManager()
        : m_registers{}
        , m_squashedRegisters{}
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     AddRegister
    //
    // Description:
    //     Adds a register to the vector. If the vector contains a register with
    //     conflicting value and mask, returns error and does not add the passed register.
    //
    // Input:
    //     const uint32_t address - register address
    //     const uint32_t mask    - register mask
    //     const uint32_t value   - register value
    //
    // Output:
    //    TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterManager::AddRegister( const uint32_t address, const uint32_t mask, const uint32_t value )
    {
        auto isRegisterAdded = [address, mask]( const TRegisterMaskValue& reg )
        {
            return reg.Address == address && reg.Mask == mask;
        };

        auto registerIterator = std::find_if( m_registers.begin(), m_registers.end(), isRegisterAdded );
        if( registerIterator != m_registers.end() )
        {
            const uint32_t foundMask  = registerIterator->Mask;
            const uint32_t foundValue = registerIterator->Value;
            if( ( foundValue & ( foundMask & mask ) ) != ( value & ( foundMask & mask ) ) )
            {
                return CC_ERROR_GENERAL;
            }
        }

        m_registers.emplace_back( address, mask, value );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     RemoveRegister
    //
    // Description:
    //     Removes a register from the vector.
    //
    // Input:
    //     const uint32_t address - register address
    //     const uint32_t mask    - register mask
    //     const uint32_t value   - register value
    //
    // Output:
    //    TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterManager::RemoveRegister( const uint32_t address, const uint32_t mask, const uint32_t value )
    {
        auto isRegisterAdded = [address, mask, value]( const TRegisterMaskValue& reg )
        {
            return reg.Address == address && reg.Mask == mask && reg.Value == value;
        };

        auto registerIterator = std::find_if( m_registers.begin(), m_registers.end(), isRegisterAdded );

        if( registerIterator != m_registers.end() )
        {
            m_registers.erase( registerIterator );
            return CC_OK;
        }

        return CC_ERROR_INVALID_PARAMETER;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     SquashRegisters
    //
    // Description:
    //     Squashes not conflicting registers in the vector.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CRegisterManager::SquashRegisters()
    {
        m_squashedRegisters.clear();

        for( auto& reg : m_registers )
        {
            auto isRegisterAdded = [&reg]( const TRegisterMaskValue& registerToSquash )
            {
                return registerToSquash.Address == reg.Address;
            };

            auto registerIterator = std::find_if( m_squashedRegisters.begin(), m_squashedRegisters.end(), isRegisterAdded );
            if( registerIterator != m_squashedRegisters.end() )
            {
                registerIterator->Mask |= reg.Mask;
                registerIterator->Value |= ( reg.Value & reg.Mask );
                continue;
            }

            m_squashedRegisters.emplace_back( reg.Address, reg.Mask, reg.Value & reg.Mask );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     GetRegistersVector
    //
    // Description:
    //     Returns a reference to the vector with squashed registers.
    //
    // Output:
    //    std::vector<TRegisterMaskValue>& - reference to the vector
    //
    //////////////////////////////////////////////////////////////////////////////
    std::vector<TRegisterMaskValue>& CRegisterManager::GetRegistersVector()
    {
        return m_squashedRegisters;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterManager
    //
    // Method:
    //     ClearRegistersVector
    //
    // Description:
    //     Clears the vector with registers.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CRegisterManager::ClearRegistersVector()
    {
        m_registers.clear();
        m_squashedRegisters.clear();
    }
} // namespace MetricsDiscoveryInternal
