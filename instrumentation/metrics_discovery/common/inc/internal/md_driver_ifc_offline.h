/*========================== begin_copyright_notice ============================

Copyright (C) 2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_offline.h

//     Abstract:   C++ driver interface header for offline metrics device

#pragma once

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleOffline
    //
    // Description:
    //     Adapter handle wrapper class for offline metrics device.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapterHandleOffline : public CAdapterHandle
    {
    public:
        CAdapterHandleOffline(){};
        virtual ~CAdapterHandleOffline(){};

        virtual TCompletionCode Close( const uint32_t adapterId )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsValid() const
        {
            return true;
        };
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceOffline
    //
    // Description:
    //     Driver interface class implementation for offline metrics device.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterfaceOffline : public CDriverInterface
    {
    public:
        // Constructor & Destructor:
        CDriverInterfaceOffline(){};
        virtual ~CDriverInterfaceOffline(){};

        CDriverInterfaceOffline( const CDriverInterfaceOffline& )            = delete; // Delete copy-constructor
        CDriverInterfaceOffline& operator=( const CDriverInterfaceOffline& ) = delete; // Delete assignment operator

        // General:
        virtual TCompletionCode ForceSupportDisable()
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendSupportEnableEscape( bool enable )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetMaxMinOaBufferSize( const GTDI_OA_BUFFER_TYPE oaBufferType, const GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendPmRegsConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const GTDI_OA_BUFFER_TYPE oaBufferType )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendReadRegsConfig( TRegister** regVector, uint32_t regCount )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetPmRegsConfigHandles( uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, uint32_t platformId )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestamp, uint64_t& cpuTimestamp, uint32_t& cpuId, uint64_t& correlationIndicator )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsOaBufferSupported( const GTDI_OA_BUFFER_TYPE oaBufferType, CMetricsDevice& metricsDevice )
        {
            return false;
        };
        virtual uint32_t GetAdapterId()
        {
            return m_adapterId;
        };

        // Synchronization:
        virtual TCompletionCode LockConcurrentGroup( const char* name, void** semaphore )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode UnlockConcurrentGroup( const char* name, void** semaphore )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };

        // Stream:
        virtual TCompletionCode OpenIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& nsTimerPeriod, uint32_t& bufferSize )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode ReadIoStream( COAConcurrentGroup& oaConcurrentGroup, char* reportData, uint32_t& reportsCount, uint32_t& frequency, GTDIReadCounterStreamExceptions& exceptions )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode CloseIoStream( COAConcurrentGroup& oaConcurrentGroup )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode HandleIoStreamExceptions( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& reportCount, const GTDIReadCounterStreamExceptions exceptions )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode WaitForIoStreamReports( COAConcurrentGroup& oaConcurrentGroup, const uint32_t milliseconds )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsIoMeasurementInfoAvailable( const TIoMeasurementInfoType ioMeasurementInfoType )
        {
            return false;
        };
        virtual bool IsStreamTypeSupported( const TStreamType streamType )
        {
            return false;
        };

        // Overrides:
        virtual TCompletionCode SetFrequencyOverride( CMetricsDevice& device, const TSetFrequencyOverrideParams_1_2& params )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SetQueryOverride( TOverrideType overrideType, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2& params )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SetFreqChangeReportsOverride( bool enable )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsOverrideAvailable( TOverrideType overrideType )
        {
            return false;
        };
        virtual bool IsSubDeviceSupported()
        {
            return false;
        };
        virtual TCompletionCode SetQueryModeOverride( const TQueryMode queryMode )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TQueryMode GetQueryModeOverride()
        {
            return QUERY_MODE_NONE;
        };

        // Adapter enumeration static:
        static bool IsSupportedIntelAdapter( CDriverInterfaceOffline& adapterHandle, uint32_t& platformId )
        {
            return false;
        };
        static TCompletionCode FillAdapterData( CDriverInterfaceOffline& adapterHandle, TAdapterData& adapterData )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };

    protected:
        virtual bool CreateContext()
        {
            return false;
        };
        virtual void            DeleteContext(){};
        virtual TCompletionCode ReopenIoStream( const std::wstring& streamEventNameW, const GTDI_OA_BUFFER_TYPE oaBufferType, const uint32_t processId )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
    };

} // namespace MetricsDiscoveryInternal
