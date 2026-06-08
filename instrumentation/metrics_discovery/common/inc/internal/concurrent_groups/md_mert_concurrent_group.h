/*========================== begin_copyright_notice ============================

Copyright (C) 2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_mert_concurrent_group.h

//     Abstract:   C++ Metrics Discovery mert concurrent group header

#pragma once

#include "md_oa_concurrent_group.h"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CInformation;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMERTConcurrentGroup
    //
    // Description:
    //     The MERT metrics groups that can be collected concurrently to another group.
    //     Stores metric sets. It has MERT IO Stream implemented.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CMERTConcurrentGroup : public COAConcurrentGroup
    {
    public:
        // API 1.16:
        virtual IMetricSet_1_16* AddMetricSet( const char* symbolName, const char* shortName, TCountersMode mode ) final;

        // API 1.13:
        virtual IMetricEnumerator_1_13* GetMetricEnumerator( void ) final;

        virtual IMetricSet_1_13* AddMetricSet( const char* symbolName, const char* shortName ) final;

    public:
        // Constructor & Destructor:
        CMERTConcurrentGroup( CMetricsDevice& device, const char* name, const char* description, const uint32_t measurementTypeMask );
        virtual ~CMERTConcurrentGroup() {};

        CMERTConcurrentGroup( const CMERTConcurrentGroup& )            = delete; // Delete copy-constructor
        CMERTConcurrentGroup& operator=( const CMERTConcurrentGroup& ) = delete; // Delete assignment operator

    public:
        // Static methods:
        static bool IsSupported( CMetricsDevice& device );
    };

} // namespace MetricsDiscoveryInternal
