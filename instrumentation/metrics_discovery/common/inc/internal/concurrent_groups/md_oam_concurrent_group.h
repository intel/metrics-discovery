/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_oam_concurrent_group.h

//     Abstract:   C++ Metrics Discovery oam concurrent group header

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
    //     COAMConcurrentGroup
    //
    // Description:
    //     The OAM metrics groups that can be collected concurrently to another group.
    //     Stores metric sets. It has OAM IO Stream implemented.
    //
    //////////////////////////////////////////////////////////////////////////////
    class COAMConcurrentGroup : public COAConcurrentGroup
    {
    public:
        // API 1.13:
        virtual IMetricEnumerator_1_13* GetMetricEnumerator( void ) override;
        virtual IMetricSet_1_13*        AddMetricSet( const char* symbolName, const char* shortName ) override;

    public:
        // Constructor:
        COAMConcurrentGroup( CMetricsDevice& device, const char* name, const char* description, const uint32_t measurementTypeMask );

        COAMConcurrentGroup( const COAMConcurrentGroup& )            = delete; // Delete copy-constructor
        COAMConcurrentGroup& operator=( const COAMConcurrentGroup& ) = delete; // Delete assignment operator

    protected:
        virtual TCompletionCode GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const override;

    public:
        // Static methods:
        static bool IsSupported( const char* symbolName, CMetricsDevice& device );
        static bool IsValidSymbolName( const char* symbolName );

    protected:
        static GTDI_OA_BUFFER_TYPE GetOaBufferTypeFromName( const char* symbolName, CMetricsDevice& device );
    };

} // namespace MetricsDiscoveryInternal
