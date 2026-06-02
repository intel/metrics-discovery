/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_xe.h
//
//     Abstract:   C++ implementation for Linux with XE KMD

#pragma once

#include "md_driver_ifc_linux_common.h"

#include <mutex>
#include <chrono>
#include <vector> // for Query
#include <condition_variable>

#include "xe_drm.h"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     SXeObservationCapabilities
    //
    // Description:
    //     A structure holding information about Xe observation features support in kernel.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SXeObservationCapabilities
    {
        bool IsConfigurableOaBufferSize;
        bool IsOaNotifyNumReportsSupported;
        bool IsOamScmiSupported;
        bool IsOamSagSupported;
        bool IsOaMertSupported;
        bool IsGtIdSupported;

    } TXeObservationCapabilities;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Description:
    //     Driver interface class implementation for Linux based systems with XE KMD.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterfaceLinuxXe : public CDriverInterfaceLinuxCommon
    {
    public: // Constructor & Destructor
        CDriverInterfaceLinuxXe( CAdapterHandle& adapterHandle );
        virtual ~CDriverInterfaceLinuxXe();

        CDriverInterfaceLinuxXe( const CDriverInterfaceLinuxXe& )            = delete; // Delete copy-constructor
        CDriverInterfaceLinuxXe& operator=( const CDriverInterfaceLinuxXe& ) = delete; // Delete assignment operator

        // Methods
        // Drm queries.
        TCompletionCode QueryDrm( const uint32_t queryId, std::vector<uint8_t>& data );
        TCompletionCode QueryDrm( drm_xe_device_query& query );

        // Read global symbols per tile.
        virtual TCompletionCode GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice ) final;
        virtual TCompletionCode GetEuCoresPerSubsliceCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice ) final;
        virtual TCompletionCode GetSliceMask( int32_t& sliceMask, CMetricsDevice& metricsDevice ) final;
        virtual TCompletionCode GetSubsliceMask( int64_t& subsliceMask, CMetricsDevice& metricsDevice ) final;

        // General
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestamp, uint64_t& cpuTimestamp, uint32_t& cpuId, uint64_t& correlationIndicator ) final;
        virtual bool            IsTbsEngineValid( const TEngineParamsLatest& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false ) const final;

        // Overrides
        virtual bool            IsSubDeviceSupported() final;
        virtual TCompletionCode EnumerateSubDevices( CSubDevices& subDevices ) final;

    protected:
        using OaUnitEngineClassInstancePair = std::pair<uint32_t, drm_xe_engine_class_instance>;

        TCompletionCode GetEngines( std::vector<OaUnitEngineClassInstancePair>& engines );
        TCompletionCode GetSubDeviceEngines( CSubDevices& subDevices, const std::vector<OaUnitEngineClassInstancePair>& engines );
        virtual bool    CreateContext() final;

        // SysFs
        virtual void GetSysFsPath( CMetricsDevice& device, const TSysFsType fileType, char* filePath, const uint32_t filePathLength ) final;

    private:
        // OA Stream
        virtual TCompletionCode OpenOaStream( CMetricsDevice& metricsDevice, uint32_t oaMetricSetId, uint32_t oaReportType, uint32_t oaReportSize, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType ) final;
        virtual TCompletionCode ReadOaStream( CMetricsDevice& metricsDevice, uint32_t reportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions ) final;
        virtual TCompletionCode ChangeIoStreamState( const int32_t streamId, const TIoStreamState state ) final;
        virtual TCompletionCode AddOaConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId ) final;
        virtual TCompletionCode RemoveOaConfig( int32_t oaConfigId ) final;
        virtual uint32_t        GetOaReportType( const TReportType reportType ) final;
        virtual TCompletionCode GetOaTimestampFrequency( uint64_t& frequency ) final;
        virtual TCompletionCode GetCsTimestampFrequency( uint64_t& frequency ) final;
        bool                    IsOamRequested( const uint32_t reportType, const GTDI_OA_BUFFER_TYPE oaBufferType );

        // Xe observation capabilities
        TCompletionCode ReadXeObservationCapabilities();

        // Read global symbols per tile.
        TCompletionCode GetGeometryTopology( std::vector<uint8_t>& buffer, CMetricsDevice& metricsDevice );

        // Drm queries.
        uint32_t GetQueryDrmDataLength( const uint32_t queryId );

        // Device info params
        virtual TCompletionCode GetDeviceId( int32_t& deviceId ) final;
        virtual TCompletionCode GetRevisionId( int32_t& revisionId ) final;
        virtual TCompletionCode GetOaBufferSize( const int32_t streamId, uint32_t& oaBufferSize ) final;
        virtual TCompletionCode GetOaBufferSupportedSizes( const uint32_t platformId, uint32_t& minSize, uint32_t& maxSize ) final;
        virtual uint32_t        GetOaBufferCount( CMetricsDevice& metricsDevice ) final;
        virtual uint32_t        GetOaBufferMask( CMetricsDevice& metricsDevice ) final;
        virtual TCompletionCode GetL3NodeTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3NodeCount ) final;
        virtual TCompletionCode GetL3BankTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3BankCount ) final;
        virtual TCompletionCode GetCopyEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& copyEngineCount ) final;
        virtual TCompletionCode GetComputeEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& computeEngineCount ) final;
        virtual TCompletionCode GetSqidiTotalCount( CMetricsDevice& metricsDevice, uint32_t& sqidiCount ) final;
        virtual TCompletionCode GetL3BankMask( CMetricsDevice& metricsDevice, uint64_t& l3BankMask ) final;
        virtual TCompletionCode GetL3NodeMask( CMetricsDevice& metricsDevice, uint64_t& l3NodeMask ) final;
        virtual TCompletionCode GetCopyEngineMask( CMetricsDevice& metricsDevice, uint64_t& copyEngineMask ) final;

        TXeObservationCapabilities m_xeObservationCapabilities; // Information about Xe observation features supported in current kernel
    };

} // namespace MetricsDiscoveryInternal
