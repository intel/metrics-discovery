/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_override.cpp

//     Abstract:   C++ Metrics Discovery internal override implementation

#include "md_override.h"
#include "md_adapter.h"
#include "md_metrics_device.h"

#include "md_driver_ifc.h"
#include "md_utils.h"

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Method:
    //     COverrideCommon
    //
    // Description:
    //     Common override class constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    COverrideCommon::COverrideCommon( void )
        : m_internalParams{
            OVERRIDE_ID_NOT_AVAILABLE,
            new( std::nothrow ) TByteArrayLatest{ MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, new( std::nothrow ) uint8_t[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE]() }
        }
    {
        MD_CHECK_PTR_RET( m_internalParams.PlatformMask, MD_EMPTY );
        MD_CHECK_PTR_RET( m_internalParams.PlatformMask->Data, MD_EMPTY );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Method:
    //     ~COverrideCommon
    //
    // Description:
    //     Common override class destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    COverrideCommon::~COverrideCommon()
    {
        DeleteByteArray( m_internalParams.PlatformMask, IU_ADAPTER_ID_UNKNOWN );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Method:
    //     GetParamsInternal
    //
    // Description:
    //     Returns internal parameters for a given override.
    //
    // Output:
    //     const TOverrideInternalParams* - internal override parameters.
    //
    //////////////////////////////////////////////////////////////////////////////
    const TOverrideInternalParams* COverrideCommon::GetParamsInternal( void )
    {
        return &m_internalParams;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     GetPlatformMask
    //
    // Description:
    //     Returns platform mask.
    //
    //////////////////////////////////////////////////////////////////////////////
    const TByteArrayLatest* COverrideCommon::GetPlatformMask( void )
    {
        return m_internalParams.PlatformMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Frequency override constructor.
    //
    // Input:
    //     CMetricsDevice& device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FREQUENCY>::COverride( CMetricsDevice& device )
        : m_device( device )
    {
        const uint32_t adapterId = device.GetAdapter().GetAdapterId();

        m_params.SymbolName       = "FrequencyOverride";
        m_params.Description      = "Overrides device GPU frequency with a static value.";
        m_params.ApiMask          = static_cast<uint32_t>( API_TYPE_ALL );
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;
        m_params.PlatformMask     = PLATFORM_UNKNOWN;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;

        auto ret = SetAllBitsPlatformMask( adapterId, m_internalParams.PlatformMask, &m_params.PlatformMask );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot set platform mask!" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     ~COverride
    //
    // Description:
    //     Generic COverride destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    COverride<overrideType>::~COverride()
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns override params.
    //
    // Output:
    //     TOverrideParams_1_2* - override params
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    TOverrideParams_1_2* COverride<overrideType>::GetParams( void )
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enabled or disables frequency override. Requires override specific
    //     params to be passed in place of *params*: TSetFrequencyOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetFrequencyOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET_A( adapterId, paramsSize, TSetFrequencyOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        auto& driverInterface = m_device.GetDriverInterface();

        auto& frequencyOverrideParams = static_cast<TSetFrequencyOverrideParams_1_2&>( *params );

        auto ret = driverInterface.SetFrequencyOverride( m_device, frequencyOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Setting frequency override failed, res: %u", ret );
        }
        else
        {
            // Update Frequency global symbol
            ret = m_device.GetSymbolSet().RedetectSymbol( "GpuCurrentFrequencyMHz" );
            ret = m_device.GetSymbolSet().RedetectSymbol( "GpuFrequencyOverrideEnabled" );
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables override.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    TCompletionCode COverride<overrideType>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        // In template methods [[maybe_unused]] is ignored by older GCC versions.
        (void) params;
        (void) paramsSize;

        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
        MD_LOG_A( adapterId, LOG_ERROR, "Override %u not supported in global mode", overrideType );
        return CC_ERROR_NOT_SUPPORTED;
    }
} // namespace MetricsDiscoveryInternal
