/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_override.h

//     Abstract:   C++ Metrics Discovery internal override header

#pragma once

#include "md_types.h"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricsDevice;

    ///////////////////////////////////////////////////////////////////////////////
    // Internal override parameters:                                             //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SOverrideInternalParams
    {
        uint32_t          QueryOverrideId;
        TByteArrayLatest* PlatformMask;
    } TOverrideInternalParams;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Description:
    //     Common class representing a device override.
    //
    //////////////////////////////////////////////////////////////////////////////
    class COverrideCommon : public IOverrideLatest
    {
    public:
        // Non-API:
        const TOverrideInternalParams* GetParamsInternal( void );
        const TByteArrayLatest*        GetPlatformMask( void );

    protected:
        // Constructor:
        COverrideCommon( void );
        virtual ~COverrideCommon();

    protected:
        // Variables:
        TOverrideInternalParams m_internalParams;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Description:
    //     Class representing a single device override.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    class COverride : public COverrideCommon
    {
    public:
        // API 1.2:
        virtual TOverrideParams_1_2* GetParams( void );
        virtual TCompletionCode      SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize );

    public:
        // Constructor & Destructor:
        COverride( CMetricsDevice* device );
        virtual ~COverride();

    private:
        // Variables:
        TOverrideParams_1_2 m_params;
        CMetricsDevice*     m_device;
    };

} // namespace MetricsDiscoveryInternal
