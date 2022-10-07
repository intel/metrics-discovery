/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_override.h

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
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FREQUENCY>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "FrequencyOverride";
        m_params.Description      = "Overrides device GPU frequency with a static value.";
        m_params.ApiMask          = (uint32_t) API_TYPE_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

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
    //     COverride<OVERRIDE_TYPE_NULL_HARDWARE>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Null Hardware override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_NULL_HARDWARE>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "Null Hardware";
        m_params.Description      = "Do not send primitives to the hardware rasterizer.";
        m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NULL_HARDWARE;

        auto ret = SetAllBitsPlatformMask( adapterId, m_internalParams.PlatformMask, &m_params.PlatformMask );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot set platform mask!" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Flush GPU caches override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "Flush GPU caches";
        m_params.Description      = "Flushes all GPU caches.";
        m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_FLUSH_GPU_CACHES;

        auto ret = SetAllBitsPlatformMask( adapterId, m_internalParams.PlatformMask, &m_params.PlatformMask );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot set platform mask!" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_EXTENDED_QUERY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Extended query override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "Extended query";
        m_params.Description      = "Enables extended query mode.";
        m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

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
    //     COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Multisampled query override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "Multisampled query";
        m_params.Description      = "Enables multisampled query mode.";
        m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

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
    //     COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Frequency change reports override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics device
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::COverride( CMetricsDevice* device )
    {
        MD_CHECK_PTR_RET( device, MD_EMPTY );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_device = device;

        m_params.SymbolName       = "FrequencyChangeReports";
        m_params.Description      = "Allows to toggle frequency change reports.";
        m_params.ApiMask          = (uint32_t) API_TYPE_IOSTREAM;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET_A( adapterId, paramsSize, TSetFrequencyOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        auto& driverInterface         = m_device->GetDriverInterface();
        auto  frequencyOverrideParams = static_cast<TSetFrequencyOverrideParams_1_2*>( params );

        auto ret = driverInterface.SetFrequencyOverride( frequencyOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Setting frequency override failed, res: %u", ret );
        }
        else
        {
            // Update Frequency global symbol
            CSymbolSet* symbolSet = m_device->GetSymbolSet();
            symbolSet->RedetectSymbol( "GpuCurrentFrequencyMHz" );
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_EXTENDED_QUERY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables or disables extended query mode. Requires override specific
    //     params to be passed in place of *params*: TSetQueryOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, m_device, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET_A( adapterId, paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        auto& driverInterface = m_device->GetDriverInterface();
        auto  oaBufferSize    = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
        if( oaBufferSize == nullptr )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unable to obtain maximum OA buffer size" );
            return CC_ERROR_GENERAL;
        }

        auto queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>( params );
        auto ret                 = driverInterface.SetQueryOverride( OVERRIDE_TYPE_EXTENDED_QUERY, oaBufferSize->ValueUInt32, queryOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Setting extended query override failed, res: %u", ret );
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables or disables multisampled query mode. Requires override specific
    //     params to be passed in place of *params*: TSetQueryOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, m_device, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET_A( adapterId, paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        auto& driverInterface = m_device->GetDriverInterface();

        auto oaBufferSize = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
        if( oaBufferSize == nullptr )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unable to obtain maximum OA buffer size" );
            return CC_ERROR_GENERAL;
        }

        auto queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>( params );
        auto ret                 = driverInterface.SetQueryOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY, oaBufferSize->ValueUInt32, queryOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Setting multisampled query override failed, res: %u", ret );
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enabled or disables frequency change reports override. Requires override
    //     specific params to be passed in place of *params*: TSetOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, m_device, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET_A( adapterId, paramsSize, TSetOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        auto& driverInterface = m_device->GetDriverInterface();
        auto  ret             = driverInterface.SetFreqChangeReportsOverride( params->Enable );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Setting frequency change reports override failed, res: %u", ret );
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
        MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_ERROR, "Override %u not supported in global mode", overrideType );
        return CC_ERROR_NOT_SUPPORTED;
    }
} // namespace MetricsDiscoveryInternal
