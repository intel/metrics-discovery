/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_sub_devices_linux.cpp

//     Abstract:   C++ sub devices implementation for Linux

#include "md_sub_devices_linux.h"
#include "md_driver_ifc_linux_common.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_utils.h"

#include <cmath>
#include <algorithm>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     CSubDeviceEngines constructor
    //
    // Input:
    //     CSubDevices& subDevices - sub devices class
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDeviceEngines::CSubDeviceEngines( CSubDevices& subDevices )
        : m_subDevices( subDevices )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     AddEngine
    //
    // Input:
    //     const uint32_t engineClass    - engine class
    //     const uint32_t engineInstance - engine instance
    //     const uint32_t gtId           - gt id linked to the engine
    //     const uint32_t oaUnit         - oa unit linked to the engine
    //
    // Description:
    //     Adds engine to sub device.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDeviceEngines::AddEngine(
        const uint32_t                  engineClass,
        const uint32_t                  engineInstance,
        [[maybe_unused]] const uint32_t gtId,
        [[maybe_unused]] const uint32_t oaUnit )
    {
        TEngineParamsLatest engine             = {};
        engine.EngineId.Type                   = ENGINE_ID_TYPE_CLASS_INSTANCE;
        engine.EngineId.ClassInstance.Class    = engineClass;
        engine.EngineId.ClassInstance.Instance = engineInstance;

        m_engines.push_back( std::move( engine ) );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     GetEngineParams
    //
    // Input:
    //     uint32_t engineIndex - engine index.
    //
    // Output:
    //     TEngineParamsLatest  - engine parameters
    //
    // Description:
    //     Returns engine parameters.
    //
    //////////////////////////////////////////////////////////////////////////////
    TEngineParamsLatest CSubDeviceEngines::GetEngineParams( const uint32_t engineIndex )
    {
        MD_ASSERT( engineIndex < m_engines.size() );

        return m_engines[engineIndex];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     GetTbsEngineParams
    //
    // Input:
    //     const uint32_t requestedInstance - requested engine instance
    //     const bool     isOam             - indicates if requested engine is related to oam
    //
    // Output:
    //     TEngineParamsLatest              - tbs engine parameters
    //     TCompletionCode                  - operation status
    //
    // Description:
    //     Returns engine parameters that can be used with tbs.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDeviceEngines::GetTbsEngineParams(
        TEngineParamsLatest& engineParams,
        const uint32_t       requestedInstance /*= -1*/,
        const bool           isOam /*= false*/ )
    {
        for( auto& engine : m_engines )
        {
            if( m_subDevices.IsTbsEngineValid( engine, requestedInstance, isOam ) )
            {
                engineParams = engine;
                return CC_OK;
            }
        }

        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevice
    //
    // Method:
    //     GetEnginesCount
    //
    // Output:
    //     uint32_t - engines count
    //
    // Description:
    //     Returns engines count.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDeviceEngines::GetEnginesCount()
    {
        return m_engines.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     CSubDevices constructor
    //
    // Description:
    //     CSubDevice constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDevices::CSubDevices( CAdapter& adapter )
        : m_adapter( adapter )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Check sub device support.
    //
    // Output:
    //     bool - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::IsSupported()
    {
        auto driver = m_adapter.GetDriverInterface();

        if( driver != nullptr )
        {
            return driver->IsSubDeviceSupported();
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Enumerate
    //
    // Description:
    //     Detects available sub devices.
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::Enumerate()
    {
        auto driver = static_cast<CDriverInterfaceLinuxCommon*>( m_adapter.GetDriverInterface() );

        if( driver != nullptr )
        {
            return driver->EnumerateSubDevices( *this );
        }

        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetAdapterParams
    //
    // Description:
    //     Returns sub device parameters related to adapter.
    //
    // Output:
    //     TAdapterParams_1_9& params   - adapter parameters
    //     TCompletionCode              - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetAdapterParams( TAdapterParams_1_9& params )
    {
        params.SubDevicesCount = m_subDeviceEngines.size();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetSubDeviceParams
    //
    // Description:
    //     Returns sub device parameters.
    //
    // Input:
    //     const uint32_t index          - sub device index
    //
    // Output:
    //     TSubDeviceParams_1_9& params  - sub device parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetSubDeviceParams(
        const uint32_t        index,
        TSubDeviceParams_1_9& params )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();
        const size_t   size      = m_subDeviceEngines.size();
        MD_CHECK_CC_RET_A( adapterId, ( index < size ) ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        params.EnginesCount = m_subDeviceEngines[index].GetEnginesCount();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetEngineParams
    //
    // Description:
    //     Returns engine parameters.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //     const uint32_t engineIndex    - engine index
    //
    // Output:
    //     TEngineParamsLatest& params   - engine parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetEngineParams(
        const uint32_t       subDeviceIndex,
        const uint32_t       engineIndex,
        TEngineParamsLatest& params )
    {
        const uint32_t adapterId    = m_adapter.GetAdapterId();
        const uint32_t enginesCount = m_subDeviceEngines[subDeviceIndex].GetEnginesCount();
        const size_t   size         = m_subDeviceEngines.size();

        MD_CHECK_CC_RET_A( adapterId, ( subDeviceIndex < size ) ? CC_OK : CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_CC_RET_A( adapterId, ( engineIndex < enginesCount ) ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        params = m_subDeviceEngines[subDeviceIndex].GetEngineParams( engineIndex );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetTbsEngineParams
    //
    // Description:
    //     Returns engine parameters compatible with tbs.
    //
    // Input:
    //     const uint32_t subDeviceIndex          - sub device index
    //     const uint32_t requestedEngineInstance - requested engine instance
    //     const bool     isOam                   - is oam related engine required to find
    //
    // Output:
    //     TEngineParamsLatest& params            - tbs engine parameters
    //     TCompletionCode                        - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetTbsEngineParams(
        const uint32_t       subDeviceIndex,
        TEngineParamsLatest& params,
        const uint32_t       requestedEngineInstance /*= -1*/,
        const bool           isOam /*= false*/ )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();
        const size_t   size      = m_subDeviceEngines.size();
        MD_CHECK_CC_RET_A( adapterId, ( subDeviceIndex < size ) ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        return m_subDeviceEngines[subDeviceIndex].GetTbsEngineParams( params, requestedEngineInstance, isOam );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetClassInstancesCount
    //
    // Description:
    //     Returns instances count for requested class of sub device
    //
    // Input:
    //     const uint32_t subDeviceIndex       - sub device index
    //     const uint32_t requestedEngineClass - requested engine class
    //
    // Output:
    //     uint32_t                            - count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDevices::GetClassInstancesCount(
        const uint32_t subDeviceIndex,
        const uint32_t requestedEngineClass )
    {
        if( subDeviceIndex >= m_subDeviceEngines.size() )
        {
            MD_LOG_A( m_adapter.GetAdapterId(), LOG_ERROR, "ERROR: subDeviceIndex is out of range. Max sub device index: %d, given: %d", m_subDeviceEngines.size(), subDeviceIndex );
            return -1;
        }

        uint32_t count = 0;
        for( uint32_t i = 0; i < m_subDeviceEngines[subDeviceIndex].GetEnginesCount(); ++i )
        {
            auto params = m_subDeviceEngines[subDeviceIndex].GetEngineParams( i );

            count += ( params.EngineId.ClassInstance.Class == requestedEngineClass )
                ? 1
                : 0;
        }

        return count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     IsTbsEngineValid
    //
    // Input:
    //     TEngineParamsLatest& engineParams      - engine params
    //     const uint32_t       requestedInstance - requested engine instance
    //     const bool           isOam             - indicates if validated engine is related to oam
    //
    // Output:
    //     bool                                   - result
    //
    // Description:
    //     Checks if engine with given params can be used to open tbs.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::IsTbsEngineValid(
        const TEngineParamsLatest& engineParams,
        const uint32_t             requestedInstance /*= -1*/,
        const bool                 isOam /*= false*/ ) const
    {
        auto driver = static_cast<CDriverInterfaceLinuxCommon*>( m_adapter.GetDriverInterface() );

        if( driver != nullptr )
        {
            return driver->IsTbsEngineValid( engineParams, requestedInstance, isOam );
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetCount
    //
    // Description:
    //     Returns number of opened sub devices.
    //
    // Output:
    //     uint32_t  - sub device count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDevices::GetDeviceCount()
    {
        uint32_t count = 0;

        for( uint32_t i = 0; i < m_subDevices.size(); ++i )
        {
            count += ( m_subDevices[i] != nullptr )
                ? 1
                : 0;
        }

        return count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     FindDevice
    //
    // Description:
    //     Checks if given sub device exists.
    //
    // Input:
    //     const CMetricsDevice* metricsDevice  - sub device
    //
    // Output:
    //     bool                                 - true if sub device found
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::FindDevice( const CMetricsDevice* metricsDevice )
    {
        return std::find( m_subDevices.begin(), m_subDevices.end(), metricsDevice ) != m_subDevices.end();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetDevice
    //
    // Description:
    //     Returns metrics sub device.
    //
    // Input:
    //     const uint32_t index - sub device index
    //
    // Output:
    //     CMetricsDevice*      - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::GetDevice( const uint32_t index )
    {
        MD_ASSERT_A( m_adapter.GetAdapterId(), index < m_subDevices.size() );

        return index < m_subDevices.size()
            ? m_subDevices[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens metrics sub device.
    //
    // Input:
    //     const uint32_t index - sub device index
    //
    // Output:
    //     CMetricsDevice*      - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::OpenDevice( const uint32_t index )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_ASSERT_A( adapterId, index < m_subDevices.size() );
        MD_ASSERT_A( adapterId, m_subDevices[index] == nullptr );

        CMetricsDevice* metricsDevice = nullptr;

        // Open metrics device and set sub device index
        m_adapter.OpenMetricsDeviceByIndex( &metricsDevice, index );

        if( metricsDevice && m_subDevices[index] == nullptr )
        {
            m_subDevices[index] = metricsDevice;
        }

        return m_subDevices[index];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens metrics sub device from file.
    //
    // Input:
    //     const uint32_t index      - sub device index
    //     const char*    filename   - custom metric file name
    //     void*          parameters - open parameters
    //
    // Output:
    //     CMetricsDevice*           - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::OpenDeviceFromFile(
        const uint32_t index,
        const char*    filename,
        void*          parameters )
    {
        const uint32_t adapterId = m_adapter.GetAdapterId();

        MD_ASSERT_A( adapterId, index < m_subDevices.size() );
        MD_ASSERT_A( adapterId, m_subDevices[index] == nullptr );

        CMetricsDevice* metricsDevice = nullptr;

        // Open metrics device from file and set sub device index
        m_adapter.OpenMetricsDeviceFromFileByIndex( filename, parameters, &metricsDevice, index );

        if( metricsDevice && m_subDevices[index] == nullptr )
        {
            m_subDevices[index] = metricsDevice;
        }

        return m_subDevices[index];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     SetRootDevice
    //
    // Description:
    //     Sets metrics root device.
    //
    // Input:
    //     CMetricsDevice* metricsDevice - metrics root device
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::SetRootDevice( CMetricsDevice* metricsDevice )
    {
        if( IsSupported() && m_subDevices[MD_ROOT_DEVICE_INDEX] == nullptr )
        {
            m_subDevices[MD_ROOT_DEVICE_INDEX] = metricsDevice;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     RemoveDevice
    //
    // Description:
    //     Removes sub device.
    //
    // Input:
    //     const CMetricsDevice* metricsDevice - sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::RemoveDevice( const CMetricsDevice* metricsDevice )
    {
        // Removes device from cache, metricsDevice instance
        // will be removed by original CloseMetricsDevice.
        for( uint32_t i = 0; i < m_subDevices.size(); ++i )
        {
            if( m_subDevices[i] == metricsDevice )
            {
                m_subDevices[i] = nullptr;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     MakeSpaceForMetricsDevices
    //
    // Description:
    //     Makes space for a sub device in sub devices vector.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::MakeSpaceForMetricsDevices()
    {
        m_subDevices.resize( m_subDeviceEngines.size(), nullptr );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     AppendSubDeviceEngine
    //
    // Description:
    //     Makes space for an engine in sub device engines vector.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::AppendSubDeviceEngine()
    {
        m_subDeviceEngines.emplace_back( *this );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetAllEnginesCount
    //
    // Output:
    //      uint32_t - all engines count across sub devices
    //
    // Description:
    //     Returns number of all sub device engines.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDevices::GetAllEnginesCount()
    {
        return m_subDeviceEngines.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     AddEngine
    //
    // Input:
    //     const uint32_t engineClass    - engine class
    //     const uint32_t engineInstance - engine instance
    //     const uint32_t gtId           - gt id linked to the engine
    //     const uint32_t oaUnit         - oa unit linked to the engine
    //
    // Description:
    //     Adds engine to sub device.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::AddEngine(
        const uint32_t engineClass,
        const uint32_t engineInstance,
        const uint32_t gtId,
        const uint32_t oaUnit )
    {
        if( m_subDeviceEngines.size() > 0 )
        {
            return m_subDeviceEngines.back().AddEngine( engineClass, engineInstance, gtId, oaUnit );
        }

        return CC_ERROR_GENERAL;
    }

} // namespace MetricsDiscoveryInternal
