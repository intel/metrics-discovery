/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_perf.h
//
//     Abstract:   C++ implementation for Linux with Perf

#pragma once

#include "md_driver_ifc_linux_common.h"

#include <mutex>
#include <chrono>
#include <vector> // for Query
#include <condition_variable>

#include "i915_drm.h"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     TPerfCapabilities
    //
    // Description:
    //     A structure holding information about i915 Perf features support in kernel.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SPerfCapabilities
    {
        bool IsOaInterruptSupported;     // Available since i915 Perf revision '2'
        bool IsSubDeviceSupported;       // Available since i915 Perf revision '10'
        bool IsGpuCpuTimestampSupported; // Available since i915 Perf revision '11'
    } TPerfCapabilities;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Description:
    //     Driver interface class implementation for Linux based systems with i915 Perf.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterfaceLinuxPerf : public CDriverInterfaceLinuxCommon
    {
    public: // Constructor & Destructor
        CDriverInterfaceLinuxPerf( CAdapterHandle& adapterHandle );
        virtual ~CDriverInterfaceLinuxPerf();

        CDriverInterfaceLinuxPerf( const CDriverInterfaceLinuxPerf& )            = delete; // Delete copy-constructor
        CDriverInterfaceLinuxPerf& operator=( const CDriverInterfaceLinuxPerf& ) = delete; // Delete assignment operator

    public: // Methods
        // Drm queries.
        TCompletionCode QueryDrm( const uint32_t queryId, std::vector<uint8_t>& data, const uint32_t flags = 0 );
        TCompletionCode QueryDrm( drm_i915_query& query );

        // Read global symbols per tile.
        virtual TCompletionCode GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice );
        virtual TCompletionCode GetEuCoresPerSubsliceCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice );
        virtual TCompletionCode GetSliceMask( int32_t& sliceMask, CMetricsDevice& metricsDevice );
        virtual TCompletionCode GetSubsliceMask( int64_t& subsliceMask, CMetricsDevice& metricsDevice );

        // General
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestamp, uint64_t& cpuTimestamp, uint32_t& cpuId, uint64_t& correlationIndicator );
        virtual bool            IsTbsEngineValid( const TEngineParams_1_9& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false ) const;

        // Overrides
        virtual bool            IsSubDeviceSupported();
        virtual TCompletionCode EnumerateSubDevices( CSubDevices& subDevices );

    protected:
        TCompletionCode GetEngines( std::vector<drm_i915_engine_info>& engines );
        TCompletionCode GetMemoryRegions( std::vector<drm_i915_memory_region_info>& regions );
        TCompletionCode GetEngineDistances( const std::vector<drm_i915_engine_info>& engines, const std::vector<drm_i915_memory_region_info>& regions, std::vector<prelim_drm_i915_query_distance_info>& distances );
        TCompletionCode GetSubDeviceEngines( CSubDevices& subDevices, const std::vector<prelim_drm_i915_query_distance_info>& distances );
        virtual bool    CreateContext();

        // SysFs
        virtual void GetSysFsPath( CMetricsDevice& device, const TSysFsType fileType, char* filePath, const uint32_t filePathLength );

    private:
        // Perf
        void ReadPerfCapabilities();
        void ResetPerfCapabilities();
        void PrintPerfCapabilities();

        // OA Stream
        virtual TCompletionCode OpenOaStream( CMetricsDevice& metricsDevice, uint32_t oaMetricSetId, uint32_t oaReportType, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType );
        virtual TCompletionCode ReadOaStream( CMetricsDevice& metricsDevice, uint32_t reportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions );
        virtual TCompletionCode AddOaConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId );
        virtual TCompletionCode RemoveOaConfig( int32_t oaConfigId );
        virtual uint32_t        GetOaReportType( const TReportType reportType );
        virtual TCompletionCode GetOaTimestampFrequency( uint64_t& frequency );
        virtual TCompletionCode GetCsTimestampFrequency( uint64_t& frequency );
        TCompletionCode         UpdateTbsEngineParams( CMetricsDevice& metricsDevice, std::vector<uint64_t>& properties );
        bool                    IsOamSupported();
        bool                    IsOamRequested( const uint32_t reportType );

        // Read global symbols per tile.
        TCompletionCode GetQueryGeometrySlices( std::vector<uint8_t>& buffer, CMetricsDevice& metricsDevice );
        TCompletionCode GetQueryTopologyInfo( std::vector<uint8_t>& buffer );

        // Drm queries.
        uint32_t GetQueryDrmDataLength( const uint32_t queryId, const uint32_t flags = 0 );

        // Device info params
        virtual TCompletionCode GetDeviceId( int32_t& deviceId );
        virtual TCompletionCode GetRevisionId( int32_t& revisionId );
        TCompletionCode         GetPerfRevision( int32_t& revision );
        TCompletionCode         GetCpuTimestampNs( uint64_t& cpuTimestampNs );
        TCompletionCode         GetGpuTimestampNs( CMetricsDevice& metricsDevice, uint64_t& gpuTimestampNs );
        TCompletionCode         GetGpuTimestampTicks( uint64_t& gpuTimestampTicks );
        TCompletionCode         GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestampNs, uint64_t& cpuTimestampNs );

        // IOCTLs
        TCompletionCode         SendGetParamIoctl( int32_t drmFd, uint32_t paramId, GTDIDeviceInfoParamExtOut& outValue );
        TCompletionCode         SendGetParamIoctl( int32_t drmFd, uint32_t paramId, int32_t& outValue );
        virtual TCompletionCode GetOaBufferSupportedSizes( const uint32_t platformId, uint32_t& minSize, uint32_t& maxSize );
        virtual TCompletionCode GetOaBufferCount( CMetricsDevice& metricsDevice, uint32_t& oaBufferCount );
        virtual TCompletionCode GetL3NodeTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3NodeCount );
        virtual TCompletionCode GetL3BankTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3BankCount );
        virtual TCompletionCode GetComputeEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& computeEngineCount );
        virtual TCompletionCode GetL3BankMask( CMetricsDevice& metricsDevice, uint64_t& l3BankMask );
        virtual TCompletionCode GetL3NodeMask( CMetricsDevice& metricsDevice, uint64_t& l3NodeMask );
        virtual TCompletionCode GetCopyEngineMask( CMetricsDevice& metricsDevice, uint64_t& copyEngineMask );

        // Device info utils
        bool IsXePlus();

    private:
        // Variables
        TPerfCapabilities m_perfCapabilities; // Information about i915 Perf features supported in current kernel
        bool              m_subDevicesSupported;

        // Cached values
        int32_t m_cachedPerfRevision;
    };

} // namespace MetricsDiscoveryInternal
