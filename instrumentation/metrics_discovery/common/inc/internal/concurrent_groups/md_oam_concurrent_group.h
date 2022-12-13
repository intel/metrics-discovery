/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

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
        // Constructor:
        COAMConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, const uint32_t measurementTypeMask );

    protected:
        virtual TCompletionCode GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const override;

        // Static methods:
    public:
        static bool IsSupported( const char* symbolicName, CMetricsDevice& metricsDevice );

    protected:
        static GTDI_OA_BUFFER_TYPE GetOaBufferTypeFromName( const char* symbolicName, const uint32_t adapterId );
    };

} // namespace MetricsDiscoveryInternal
