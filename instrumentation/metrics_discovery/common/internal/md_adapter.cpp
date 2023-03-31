/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_adapter.h

//     Abstract:   C++ Metrics Discovery internal adapter implementation

#include "md_adapter.h"
#include "md_metrics_device.h"

#include "md_driver_ifc.h"
#include "md_metrics.h"
#include "md_types.h"
#include "md_utils.h"

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CAdapter constructor
    //
    // Description:
    //     Constructor.
    //     Adapter object becomes owner of the adapter handle (CAdapterHandle object) and
    //     params memory (strings).
    //
    // Input:
    //     CAdapterGroup&            adapterGroup  - parent adapter group object
    //     const TAdapterParams_1_9& params        - filled adapter params
    //     CAdapterHandle&           adapterHandle - adapter handle connected with this adapter
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter::CAdapter( CAdapterGroup& adapterGroup, const TAdapterParams_1_9& params, CAdapterHandle& adapterHandle )
        : m_adapterId( IU_ADAPTER_ID_UNKNOWN )
        , m_params( params )
        , m_adapterHandle( &adapterHandle )
        , m_driverInterface( nullptr )
        , m_metricsDevice( nullptr )
        , m_openCloseSemaphore( nullptr )
        , m_subDevices( *this )
        , m_subDeviceParams{}
        , m_engineParams{}
        , m_adapterGroup( adapterGroup )
    {
        // Initialize sub device information.
        m_subDevices.Enumerate();
        m_subDevices.GetAdapterParams( m_params );

        if( CreateDriverInterface() != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Failed to create driver interface for an adapter" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     ~CAdapter
    //
    // Description:
    //     Deallocates memory and closes underlying adapter handle.
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter::~CAdapter()
    {
        MD_SAFE_DELETE_ARRAY( m_params.ShortName );

        MD_SAFE_DELETE( m_metricsDevice );
        MD_SAFE_DELETE( m_driverInterface );

        if( m_adapterHandle )
        {
            m_adapterHandle->Close( m_adapterId );
            MD_SAFE_DELETE( m_adapterHandle );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns adapter params.
    //
    // Output:
    //     const TAdapterParams_1_9* - adapter params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TAdapterParams_1_9* CAdapter::GetParams() const
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetSubDeviceParams
    //
    // Description:
    //     Returns sub device params.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //
    // Output:
    //     const TSubDeviceParams_1_9*   - sub device params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TSubDeviceParams_1_9* CAdapter::GetSubDeviceParams( const uint32_t subDeviceIndex )
    {
        return ( m_subDevices.GetSubDeviceParams( subDeviceIndex, m_subDeviceParams ) == CC_OK )
            ? &m_subDeviceParams
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetEngineParams
    //
    // Description:
    //     Returns engine params.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //     const uint32_t engineIndex    - engine index
    //
    // Output:
    //     const TEngineParams_1_9*      - adapter params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TEngineParams_1_9* CAdapter::GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex )
    {
        return ( m_subDevices.GetEngineParams( subDeviceIndex, engineIndex, m_engineParams ) == CC_OK )
            ? &m_engineParams
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetSubDevices
    //
    // Description:
    //     Returns a reference to sub devices implementation.
    //
    // Output:
    //     CSubDevices& -reference to sub device implementation.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDevices& CAdapter::GetSubDevices()
    {
        return m_subDevices;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetAdapterId
    //
    // Description:
    //     Returns the id of the adapter.
    //
    // Output:
    //     uint32_t - id of the adapter.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CAdapter::GetAdapterId() const
    {
        return m_adapterId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     Reset
    //
    // Description:
    //     Tries to disable performance monitoring support. Useful when previous
    //     application crashed and left it in the unspecified / initialized state.
    //
    //     Allowed only if no metrics device objects are open.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::Reset()
    {
        MD_LOG_ENTER_A( m_adapterId );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT_A( m_adapterId );
            return retVal;
        }

        // 2. Allow resetting only if no metrics device objects are created
        if( !m_metricsDevice )
        {
            if( CDriverInterface::IsSupportEnableRequired() )
            {
                // 3. Create driver interface
                retVal = CreateDriverInterface();
                if( retVal == CC_OK )
                {
                    MD_ASSERT_A( m_adapterId, m_driverInterface != nullptr );

                    // 4. Force disable performance monitoring support
                    retVal = m_driverInterface->ForceSupportDisable();
                    if( retVal != CC_OK )
                    {
                        MD_LOG_A( m_adapterId, LOG_ERROR, "Resetting adapter state failed" );
                    }

                    DestroyDriverInterface();
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "Failed to get driver interface" );
                }
            }
        }
        else
        {
            retVal = CC_ERROR_GENERAL;
        }

        // 5. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT_A( m_adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceByIndex
    //
    // Description:
    //     Opens metrics device and sets sub device index or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //     const uint32_t        subDeviceIndex  - index of sub device to create
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceByIndex( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode retVal = CC_OK;

        // if MD_METRIC_EXTENSION environment var is set, OpenMetricsDeviceFromFileByIndex  instead
        const char* metricFilename = iu_dupenv_s( MD_METRIC_EXTENSION );
        if( metricFilename != nullptr )
        {
            MD_LOG_A( m_adapterId, LOG_INFO, "Opening metrics device from extension file %s ...", metricFilename );

            retVal = OpenMetricsDeviceFromFileByIndex( metricFilename, (void*) "", metricsDevice, subDeviceIndex );

            free( (void*) metricFilename );

            // Return if succeded or failed for reasons other than a lack of the metric file
            if( retVal != CC_ERROR_FILE_NOT_FOUND )
            {
                MD_LOG_EXIT_A( m_adapterId );
                return retVal;
            }
        }

        // 1. Obtain semaphore
        retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT_A( m_adapterId );
            return retVal;
        }

        // 2. Create or return existing metrics device object
        if( m_metricsDevice )
        {
            *metricsDevice = m_metricsDevice;
            retVal         = CC_ALREADY_INITIALIZED;
            ++m_metricsDevice->GetReferenceCounter();
        }
        else
        {
            retVal = CreateMetricsDevice( metricsDevice, subDeviceIndex );
            if( retVal == CC_OK )
            {
                ++m_metricsDevice->GetReferenceCounter();

                if( subDeviceIndex == MD_ROOT_DEVICE_INDEX )
                {
                    m_subDevices.SetRootDevice( *metricsDevice );
                }
            }
        }

        // 3. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT_A( m_adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_5** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_10** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_11** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFileByIndex
    //
    // Description:
    //     Opens metrics device and sets sub device index or uses an instance opened before (just like OpenMetricsDeviceByIndex),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName        - custom metric file
    //     void*                 openParams      - open params
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //     const uint32_t        subDeviceIndex  - index of sub device to create
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFileByIndex( const char* fileName, void* openParams, CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT_A( m_adapterId );
            return retVal;
        }

        // 2. Create 'standard' metrics device object if needed
        if( !m_metricsDevice )
        {
            retVal = CreateMetricsDevice( nullptr, subDeviceIndex );
        }
        MD_ASSERT_A( m_adapterId, m_driverInterface != nullptr );

        // 3. Load from file or return existing metrics device object
        if( retVal == CC_OK )
        {
            if( m_metricsDevice->IsOpenedFromFile() )
            {
                *metricsDevice = m_metricsDevice;
                retVal         = CC_ALREADY_INITIALIZED;
                ++m_metricsDevice->GetReferenceCounter();
            }
            else
            {
                retVal = m_metricsDevice->OpenFromFile( fileName, MD_IS_INTERNAL_BUILD );
                if( retVal == CC_OK )
                {
                    *metricsDevice = m_metricsDevice;
                    ++m_metricsDevice->GetReferenceCounter();
                }
                else if( !m_metricsDevice->GetReferenceCounter() )
                {
                    // If this was a first call to OpenMetricsDevice
                    DestroyMetricsDevice();
                }
            }
        }

        // 4. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT_A( m_adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_5**  metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_10** metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_11** metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t     subDeviceIndex - sub device index to create
    //     CMetricsDevice**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                   - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, CMetricsDevice** metricsDevice )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        const bool      isFirstDevice        = subDeviceIndex == 0;
        const bool      isValidIndex         = isFirstDevice || ( subDeviceIndex < m_params.SubDevicesCount );
        const bool      isSubDeviceSupported = m_subDevices.IsSupported();
        TCompletionCode result               = CC_OK;

        // Check sub device support (first device is always supported).
        if( !isFirstDevice && !isSubDeviceSupported )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Sub devices are not supported" );
            MD_LOG_EXIT_A( m_adapterId );
            return CC_ERROR_NOT_SUPPORTED;
        }

        // Check sub device index.
        if( !isValidIndex )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Invalid sub device index" );
            MD_LOG_EXIT_A( m_adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // Check if device is already created.
        m_metricsDevice = m_subDevices.GetDevice( subDeviceIndex );

        // Create new one if needed or increment reference counter.
        if( m_metricsDevice == nullptr )
        {
            m_metricsDevice = m_subDevices.OpenDevice( subDeviceIndex );
            result          = m_metricsDevice ? CC_OK : CC_ERROR_GENERAL;
        }
        else
        {
            ++m_metricsDevice->GetReferenceCounter();
            result = CC_ALREADY_INITIALIZED;
        }

        MD_LOG_EXIT_A( m_adapterId )
        *metricsDevice = m_metricsDevice;
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t         subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_5**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t          subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_10**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                        - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t          subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_11**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                        - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t        subDeviceIndex  - sub device index to create
    //     const char*           fileName        - custom metric file
    //     void*                 openParams      - open params
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, CMetricsDevice** metricsDevice )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        const bool      isFirstDevice        = subDeviceIndex == 0;
        const bool      isValidIndex         = isFirstDevice || ( subDeviceIndex < m_params.SubDevicesCount );
        const bool      isSubDeviceSupported = m_subDevices.IsSupported();
        TCompletionCode result               = CC_OK;

        // Check sub device support (first device is always supported).
        if( !isFirstDevice && !isSubDeviceSupported )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Sub devices are not supported" );
            MD_LOG_EXIT_A( m_adapterId );
            return CC_ERROR_NOT_SUPPORTED;
        }

        // Check sub device index.
        if( !isValidIndex )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Invalid sub device index" );
            MD_LOG_EXIT_A( m_adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // Check if device is already created.
        m_metricsDevice = m_subDevices.GetDevice( subDeviceIndex );

        // Create new one if needed or increment reference counter.
        if( m_metricsDevice == nullptr )
        {
            m_metricsDevice = m_subDevices.OpenDeviceFromFile( subDeviceIndex, fileName, openParams );
            result          = m_metricsDevice ? CC_OK : CC_ERROR_GENERAL;
        }
        else
        {
            ++m_metricsDevice->GetReferenceCounter();
            result = CC_ALREADY_INITIALIZED;
        }

        MD_LOG_EXIT_A( m_adapterId )
        *metricsDevice = m_metricsDevice;
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t            subDeviceIndex  - sub device index to create
    //     const char*               fileName        - custom metric file
    //     void*                     openParams      - open params
    //     IMetricsDevice_1_5**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                           - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t             subDeviceIndex  - sub device index to create
    //     const char*                fileName        - custom metric file
    //     void*                      openParams      - open params
    //     IMetricsDevice_1_10**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                            - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t             subDeviceIndex  - sub device index to create
    //     const char*                fileName        - custom metric file
    //     void*                      openParams      - open params
    //     IMetricsDevice_1_11**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                            - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CloseMetricsDevice
    //
    // Description:
    //     Decreases metrics device reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    // Input:
    //     CMetricsDevice*     metricsDevice - metrics device to close
    //
    // Output:
    //     TCompletionCode                   - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CloseMetricsDevice( CMetricsDevice* metricsDevice )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT_A( m_adapterId );
            return retVal;
        }

        // 2. Check driver interface - it should be created during OpenMetricsDevice
        if( !m_driverInterface )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Driver interface not found" );
            retVal = CC_ERROR_GENERAL;
        }

        // 3. Check whether correct metrics device was passed
        if( retVal == CC_OK )
        {
            const bool validDevice    = metricsDevice == m_metricsDevice;
            const bool validSubDevice = m_subDevices.FindDevice( metricsDevice );

            if( !validDevice && !validSubDevice )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Pointers mismatch" );
                retVal = CC_ERROR_GENERAL;
            }
        }

        // 4. Destroy or decrease reference counter for existing metrics device object
        if( retVal == CC_OK )
        {
            // Set as default device to remove.
            m_metricsDevice = metricsDevice;

            if( m_metricsDevice->GetReferenceCounter() > 1 )
            {
                --m_metricsDevice->GetReferenceCounter();
                retVal = CC_STILL_INITIALIZED;
            }
            else if( m_metricsDevice->GetReferenceCounter() == 1 )
            {
                m_metricsDevice->GetReferenceCounter() = 0;
                DestroyMetricsDevice();
                retVal = CC_OK;
            }
            else
            {
                retVal = CC_ERROR_GENERAL;
            }
        }

        // 5. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT_A( m_adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CloseMetricsDevice
    //
    // Description:
    //     Decreases metrics device reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    // Input:
    //     IMetricsDevice_1_5*     metricsDevice - metrics device to close
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice )
    {
        return CloseMetricsDevice( static_cast<CMetricsDevice*>( metricsDevice ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*          fileName           - target file name
    //     void*                saveParams         - save params
    //     CMetricsDevice*      metricsDevice      - target metrics device
    //     const uint32_t       minMajorApiVersion - required MDAPI major version to open the file
    //     const uint32_t       minMinorApiVersion - required MDAPI minor version to open the file
    //
    // Output:
    //     TCompletionCode                         - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, CMetricsDevice* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT_A( m_adapterId );
            return retVal;
        }

        // 2. Check whether correct metrics device was passed
        if( metricsDevice != m_metricsDevice )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Pointers mismatch" );
            retVal = CC_ERROR_GENERAL;
        }

        // 3. Save metrics device object to a file
        retVal = m_metricsDevice->SaveToFile( fileName, minMajorApiVersion, minMinorApiVersion );
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Saving to file failed" );
        }

        // 4. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT_A( m_adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*          fileName      - target file name
    //     void*                saveParams    - save params
    //     IMetricsDevice_1_5*  metricsDevice - target metrics device
    //
    // Output:
    //     TCompletionCode                    - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_5* metricsDevice )
    {
        return SaveMetricsDeviceToFile( fileName, saveParams, static_cast<CMetricsDevice*>( metricsDevice ), 0, 0 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*           fileName           - target file name
    //     void*                 saveParams         - save params
    //     IMetricsDevice_1_11*  metricsDevice      - target metrics device
    //     const uint32_t        minMajorApiVersion - required MDAPI major version to open the file
    //     const uint32_t        minMinorApiVersion - required MDAPI minor version to open the file
    //
    // Output:
    //     TCompletionCode                          - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_11* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        return SaveMetricsDeviceToFile( fileName, saveParams, static_cast<CMetricsDevice*>( metricsDevice ), minMajorApiVersion, minMinorApiVersion );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetDriverInterface
    //
    // Description:
    //     Returns driver interface.
    //
    // Output:
    //     CDriverInterface - pointer to driver interface
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterface* CAdapter::GetDriverInterface()
    {
        if( m_driverInterface == nullptr )
        {
            CreateDriverInterface();
        }

        return m_driverInterface;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CreateDriverInterface
    //
    // Description:
    //     Creates an instance of driver interface. Only one driver interface per adapter
    //     should be created.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CreateDriverInterface()
    {
        MD_CHECK_PTR_RET_A( m_adapterId, m_adapterHandle, CC_ERROR_GENERAL );

        if( !m_driverInterface )
        {
            m_driverInterface = CDriverInterface::CreateInstance( *m_adapterHandle );
        }

        if( m_driverInterface )
        {
            m_adapterId = m_driverInterface->GetAdapterId();
            return CC_OK;
        }

        m_adapterId = IU_ADAPTER_ID_UNKNOWN;
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     DestroyDriverInterface
    //
    // Description:
    //     Destroys driver interface.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CAdapter::DestroyDriverInterface()
    {
        if( m_subDevices.GetDeviceCount() == 0 )
        {
            MD_SAFE_DELETE( m_driverInterface );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetOpenCloseSemaphore
    //
    // Description:
    //     Acquires semaphore used during Open/CloseMetricsDevice() calls. Use to control
    //     parallel access to these functions.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::GetOpenCloseSemaphore()
    {
        const char     openClosePrefix[] = "MdOpenClose";
        const uint32_t spaceFor3Uints    = 33; // 3 * "max uint string" + 3 * "_"

        // Create a semaphore name: "OpenClose_<BusNumber>_<DeviceNumber>_<FunctionNumber>"
        char semaphoreName[sizeof( openClosePrefix ) + spaceFor3Uints];
        snprintf( semaphoreName, sizeof( semaphoreName ), "%s_%u_%u_%u", openClosePrefix, m_params.BusNumber, m_params.DeviceNumber, m_params.FunctionNumber );

        return GetNamedSemaphore( semaphoreName, &m_openCloseSemaphore, m_adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     ReleaseOpenCloseSemaphore
    //
    // Description:
    //     Releases semaphore used during Open/CloseMetricsDevice() calls. Use to control
    //     parallel access to these functions.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::ReleaseOpenCloseSemaphore()
    {
        return ReleaseNamedSemaphore( &m_openCloseSemaphore, m_adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CreateMetricsDevice
    //
    // Description:
    //     Creates metrics device along with the whole metric tree and driver interface.
    //     May enable instrumentation support if needed.
    //
    // Input:
    //     CMetricsDevice**      metricsDevice  - [out][optional] created metrics device
    //     const uint32_t        subDeviceIndex - index of sub device to create
    //
    // Output:
    //     TCompletionCode                      - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CreateMetricsDevice( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex /* = 0 */ )
    {
        MD_ASSERT_A( m_adapterId, m_metricsDevice == nullptr );

        // 1. Create driver interface
        TCompletionCode retVal = CreateDriverInterface();
        if( retVal != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Failed to get driver interface" );
            return retVal;
        }
        MD_ASSERT_A( m_adapterId, m_driverInterface != nullptr );

        // 2. Enable instrumentation support if needed
        retVal = EnableDriverSupport( true );
        if( retVal != CC_OK )
        {
            DestroyDriverInterface();
            return retVal;
        }

        // 3. Create metrics device object
        m_metricsDevice = new( std::nothrow ) CMetricsDevice( *this, *m_driverInterface, subDeviceIndex );
        if( !m_metricsDevice )
        {
            EnableDriverSupport( false );
            DestroyDriverInterface();
            return CC_ERROR_NO_MEMORY;
        }

        // 4. Populate metric tree
        retVal = CreateMetricTree( m_metricsDevice );
        if( retVal != CC_OK )
        {
            MD_SAFE_DELETE( m_metricsDevice );
            EnableDriverSupport( false );
            DestroyDriverInterface();
            return retVal;
        }

        if( metricsDevice )
        {
            *metricsDevice = m_metricsDevice;
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     DestroyMetricsDevice
    //
    // Description:
    //     Destroys metrics device for this adapter.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CAdapter::DestroyMetricsDevice()
    {
        // 1. Remove device from sub devices.
        m_subDevices.RemoveDevice( m_metricsDevice );

        // 2. Delete metrics device object
        MD_SAFE_DELETE( m_metricsDevice );

        // 3. Disable instrumentation support if needed
        EnableDriverSupport( false );

        // 4. Destroy driver interface
        DestroyDriverInterface();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     EnableDriverSupport
    //
    // Description:
    //     Enables driver support if driver requires that.
    //
    // Input:
    //     bool enable     - true to enable
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::EnableDriverSupport( bool enable )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, m_driverInterface, CC_ERROR_NOT_SUPPORTED );

        TCompletionCode retVal      = CC_OK;
        auto            enablePrint = []( bool enable )
        {
            return enable ? "enabling" : "disabling";
        };

        if( m_driverInterface->IsSupportEnableRequired() )
        {
            MD_LOG_A( m_adapterId, LOG_INFO, "Driver support %s...", enablePrint( enable ) );
            retVal = m_driverInterface->SendSupportEnableEscape( enable );
            if( retVal != CC_OK )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Driver support %s failed", enablePrint( enable ) );
            }
        }

        return retVal;
    }
} // namespace MetricsDiscoveryInternal
