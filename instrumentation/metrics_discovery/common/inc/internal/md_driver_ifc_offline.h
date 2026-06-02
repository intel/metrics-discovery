/*========================== begin_copyright_notice ============================

Copyright (C) 2025-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_offline.h

//     Abstract:   C++ driver interface header for offline metrics device

#pragma once

#include <string>

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
        CAdapterHandleOffline() {};
        virtual ~CAdapterHandleOffline() {};

        virtual TCompletionCode Close( [[maybe_unused]] const uint32_t adapterId ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsValid() const final
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
        CDriverInterfaceOffline() {};
        virtual ~CDriverInterfaceOffline() {};

        CDriverInterfaceOffline( const CDriverInterfaceOffline& )            = delete; // Delete copy-constructor
        CDriverInterfaceOffline& operator=( const CDriverInterfaceOffline& ) = delete; // Delete assignment operator

        // General:
        virtual TCompletionCode ForceSupportDisable() final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendSupportEnableEscape( [[maybe_unused]] bool enable ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendDeviceInfoParamEscape( [[maybe_unused]] GTDI_DEVICE_PARAM param, [[maybe_unused]] GTDIDeviceInfoParamExtOut& out, [[maybe_unused]] CMetricsDevice& metricsDevice ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetMaxMinOaBufferSize( [[maybe_unused]] const GTDI_OA_BUFFER_TYPE oaBufferType, [[maybe_unused]] const GTDI_DEVICE_PARAM param, [[maybe_unused]] GTDIDeviceInfoParamExtOut& out, [[maybe_unused]] CMetricsDevice& metricsDevice ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendPmRegsConfig( [[maybe_unused]] std::vector<TRegister*>& pmRegs, [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const GTDI_OA_BUFFER_TYPE oaBufferType, [[maybe_unused]] const TReportType reportType ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode SendReadRegsConfig( [[maybe_unused]] TRegister** regVector, [[maybe_unused]] uint32_t regCount ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetPmRegsConfigHandles( [[maybe_unused]] uint32_t* oaConfigHandle, [[maybe_unused]] uint32_t* rrConfigHandle ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode ValidatePmRegsConfig( [[maybe_unused]] TRegister* regVector, [[maybe_unused]] uint32_t regCount, [[maybe_unused]] uint32_t platformId ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode GetGpuCpuTimestamps( [[maybe_unused]] CMetricsDevice& device, [[maybe_unused]] uint64_t& gpuTimestamp, [[maybe_unused]] uint64_t& cpuTimestamp, [[maybe_unused]] uint32_t& cpuId, [[maybe_unused]] uint64_t& correlationIndicator ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };

        // Stream:
        virtual TCompletionCode OpenIoStream( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup, [[maybe_unused]] const uint32_t processId, [[maybe_unused]] uint32_t& nsTimerPeriod, [[maybe_unused]] uint32_t& bufferSize ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode ReadIoStream( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup, [[maybe_unused]] char* reportData, [[maybe_unused]] uint32_t& reportsCount, [[maybe_unused]] uint32_t& frequency, [[maybe_unused]] GTDIReadCounterStreamExceptions& exceptions ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode CloseIoStream( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode ChangeIoStreamState( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup, [[maybe_unused]] TIoStreamState state, [[maybe_unused]] uint32_t& nsTimerPeriod ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode HandleIoStreamExceptions( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup, [[maybe_unused]] const uint32_t processId, [[maybe_unused]] uint32_t& reportCount, [[maybe_unused]] const GTDIReadCounterStreamExceptions exceptions ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual TCompletionCode WaitForIoStreamReports( [[maybe_unused]] COAConcurrentGroup& oaConcurrentGroup, [[maybe_unused]] const uint32_t milliseconds ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsIoMeasurementInfoAvailable( [[maybe_unused]] const TIoMeasurementInfoType ioMeasurementInfoType ) final
        {
            return false;
        };
        virtual bool IsStreamTypeSupported( [[maybe_unused]] const TStreamType streamType ) final
        {
            return false;
        };

        // Overrides:
        virtual TCompletionCode SetFrequencyOverride( [[maybe_unused]] CMetricsDevice& device, [[maybe_unused]] const TSetFrequencyOverrideParams_1_2& params ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
        virtual bool IsOverrideAvailable( [[maybe_unused]] TOverrideType overrideType ) final
        {
            return false;
        };
        virtual bool IsSubDeviceSupported() final
        {
            return false;
        };
        virtual TQueryMode GetQueryModeOverride() final
        {
            return QUERY_MODE_NONE;
        };

        // Adapter enumeration static:
        static bool IsSupportedIntelAdapter( [[maybe_unused]] CDriverInterfaceOffline& adapterHandle, [[maybe_unused]] uint32_t& platformId )
        {
            return false;
        };
        static TCompletionCode FillAdapterData( [[maybe_unused]] CDriverInterfaceOffline& adapterHandle, [[maybe_unused]] TAdapterData& adapterData )
        {
            return CC_ERROR_NOT_SUPPORTED;
        };

    protected:
        virtual bool CreateContext() final
        {
            return false;
        };
        virtual void            DeleteContext() final {};
        virtual TCompletionCode ReopenIoStream( [[maybe_unused]] const std::wstring& streamEventNameW, [[maybe_unused]] const GTDI_OA_BUFFER_TYPE oaBufferType, [[maybe_unused]] const uint32_t processId ) final
        {
            return CC_ERROR_NOT_SUPPORTED;
        };
    };

} // namespace MetricsDiscoveryInternal
