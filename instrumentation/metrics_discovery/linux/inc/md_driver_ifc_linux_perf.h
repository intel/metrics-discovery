/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_perf.h
//
//     Abstract:   C++ implementation for Linux with Perf

#pragma once

#include "md_driver_ifc.h"
#include "i915_drm.h"

#include <mutex>
#include <chrono>
#include <vector> // for Query
#include <condition_variable>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Enum:
    //     TGfxGtType
    //
    // Description:
    //     Based on 'GTTYPE' struct from Intel driver files, it should be in sync
    //     with that struct.
    //     ! DO NOT CHANGE THE ORDER OR INDICES !
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef enum EGfxGtType
    {
        GFX_GTTYPE_GT1 = 0,
        GFX_GTTYPE_GT2 = 1,
        // 2-8 reserved
        GFX_GTTYPE_GT3 = 9,
        GFX_GTTYPE_GT4 = 10,
        GFX_GTTYPE_GT0 = 11,
        // 12-16 reserved
        GFX_GTTYPE_RESERVED_16 = 16,
        // ...
        GFX_GTTYPE_UNDEFINED, // Always at the end.
    } TGfxGtType;

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
    // Struct:
    //     TPlatformIndexGt
    //
    // Description:
    //     Platform index and GT pair to create a map with device id as a key.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SPlatformIndexGt
    {
        SPlatformIndexGt()
            : PlatformIndex( GTDI_PLATFORM_MAX )
            , GtType( GFX_GTTYPE_UNDEFINED )
        {
        }
        SPlatformIndexGt( const GTDI_PLATFORM_INDEX platformIndex, const TGfxGtType gtType )
            : PlatformIndex( platformIndex )
            , GtType( gtType )
        {
        }

        GTDI_PLATFORM_INDEX PlatformIndex;
        TGfxGtType          GtType;
    } TPlatformIndexGt;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     TGfxDeviceInfo
    //
    // Description:
    //     A structure with basic device information.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SGfxDeviceInfo
    {
        GTDI_PLATFORM_INDEX PlatformIndex;
        TGfxGtType          GtType;
        uint32_t            ThreadsPerEu;
    } TGfxDeviceInfo;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Description:
    //     Used in driver interface to provide semaphore functionality on different
    //     OSes.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CSemaphore
    {
    public:
        CSemaphore();
        void     Notify();
        void     Wait();
        bool     WaitFor( uint64_t timeoutNs );
        bool     TryWait();
        uint32_t GetValue();

    private:
        typedef std::mutex              TFenceMutex;
        typedef std::condition_variable TFenceConditionVariable;

        TFenceMutex             semMutex;
        TFenceConditionVariable semCv;
        uint32_t                semCount;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Description:
    //     Adapter handle wrapper class for Linux. Keeps DRM file descriptor.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapterHandleLinux : public CAdapterHandle
    {
    public:
        CAdapterHandleLinux( int32_t adapterHandle );
        virtual ~CAdapterHandleLinux();

        virtual TCompletionCode Close( const uint32_t adapterId );
        virtual bool            IsValid() const;

        operator int() const;

    private:
        static constexpr int32_t InvalidValue = -1;

        int32_t m_handle;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Description:
    //     Driver interface class implementation for Linux based systems with i915 Perf.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterfaceLinuxPerf : public CDriverInterface
    {
    public: // Constructor & Destructor
        CDriverInterfaceLinuxPerf( CAdapterHandle& adapterHandle );
        virtual ~CDriverInterfaceLinuxPerf();

    public: // Methods
        // Static
        static TCompletionCode GetGfxDeviceInfo( int32_t deviceId, TGfxDeviceInfo* gfxDeviceInfo, const uint32_t adapterId );
        static TAdapterType    GetAdapterType( const TGfxDeviceInfo* gfxDeviceInfo );

        // Drm queries.
        uint32_t        GetQueryDrmDataLength( const uint32_t queryId, const uint32_t flags = 0 );
        TCompletionCode QueryDrm( const uint32_t queryId, std::vector<uint8_t>& data, const uint32_t flags = 0 );
        TCompletionCode QueryDrm( drm_i915_query& query );

        // Read global symbols per tile.
        TCompletionCode GetQueryGeometrySlices( std::vector<uint8_t>& buffer, CMetricsDevice* metricsDevice );
        TCompletionCode GetQueryTopologyInfo( std::vector<uint8_t>& buffer );
        TCompletionCode GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice );
        TCompletionCode GetSliceMask( int32_t* sliceMask, CMetricsDevice* metricsDevice );
        TCompletionCode GetSubsliceMask( int64_t* subsliceMask, CMetricsDevice* metricsDevice );

        // General
        virtual TCompletionCode ForceSupportDisable();
        virtual TCompletionCode SendSupportEnableEscape( bool enable );
        virtual TCompletionCode SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice = nullptr );
        virtual TCompletionCode GetMaxMinOaBufferSize( const GTDI_OA_BUFFER_TYPE oaBufferType, const GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out );
        virtual TCompletionCode SendPmRegsConfig( TRegister** regVector, const uint32_t regCount, const uint32_t apiMask, const uint32_t subDeviceIndex, const GTDI_OA_BUFFER_TYPE oaBufferType );
        virtual TCompletionCode SendReadRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask );
        virtual TCompletionCode GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle );
        virtual TCompletionCode ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, uint32_t platformId );
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId, uint64_t* correlationIndicator );
        virtual TCompletionCode SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params );
        virtual uint32_t        GetAdapterId();
        virtual bool            IsOaBufferSupported( const GTDI_OA_BUFFER_TYPE oaBufferType, CMetricsDevice* metricsDevice = nullptr );
        TCompletionCode         GetOaTimestamp( const uint64_t csTimestamp, uint64_t& oaTimestamp );

        // Synchronization
        virtual TCompletionCode LockConcurrentGroup( const char* name, void** semaphore );
        virtual TCompletionCode UnlockConcurrentGroup( const char* name, void** semaphore );

        // Stream
        virtual TCompletionCode OpenIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& nsTimerPeriod, uint32_t& bufferSize );
        virtual TCompletionCode ReadIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t readFlags, char* reportData, uint32_t& reportsCount, uint32_t& frequency, GTDIReadCounterStreamExceptions& exceptions );
        virtual TCompletionCode CloseIoStream( COAConcurrentGroup& oaConcurrentGroup );
        virtual TCompletionCode HandleIoStreamExceptions( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& reportCount, const GTDIReadCounterStreamExceptions exceptions );
        virtual TCompletionCode WaitForIoStreamReports( COAConcurrentGroup& oaConcurrentGroup, const uint32_t milliseconds );
        virtual bool            IsIoMeasurementInfoAvailable( const TIoMeasurementInfoType ioMeasurementInfoType );
        virtual bool            IsStreamTypeSupported( const TStreamType streamType );

        // Overrides
        virtual TCompletionCode SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params );
        virtual TCompletionCode SetQueryOverride( TOverrideType overrideType, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params );
        virtual TCompletionCode SetFreqChangeReportsOverride( bool enable );
        virtual bool            IsOverrideAvailable( TOverrideType overrideType );
        virtual bool            IsSubDeviceSupported();

    protected:
        virtual bool CreateContext();
        virtual void DeleteContext();

    private:
        // Perf
        void            ReadPerfCapabilities();
        void            ResetPerfCapabilities();
        void            PrintPerfCapabilities();
        TCompletionCode OpenPerfStream( CMetricsDevice& metricsDevice, uint32_t perfMetricSetId, uint32_t perfReportType, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType );
        TCompletionCode ReadPerfStream( CMetricsDevice& metricsDevice, uint32_t oaReportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions );
        TCompletionCode ClosePerfStream( CMetricsDevice& metricsDevice );
        TCompletionCode FlushPerfStream( CMetricsDevice& metricsDevice );
        TCompletionCode WaitForPerfStreamReports( CMetricsDevice& metricsDevice, uint32_t timeoutMs );
        std::string     GenerateQueryGuid( const uint32_t subDeviceIndex );
        TCompletionCode AddPerfConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId );
        TCompletionCode RemovePerfConfig( int32_t perfConfigId );
        TCompletionCode RemovePerfConfigQuery( const char* guid );
        TCompletionCode GetPerfMetricSetId( const char* guid, int32_t& perfMetricSetId );
        bool            PerfMetricSetExists( const char* guid );
        uint32_t        GetPerfReportType( const TReportType reportType );
        TCompletionCode GetOaTimestampFrequency( uint64_t& frequency );
        TCompletionCode GetCsTimestampFrequency( uint64_t& frequency );
        bool            IsOamSupported();
        bool            IsOamRequested( const uint32_t reportType );

        // DRM
        bool            InitializeIntelDrm();
        void            DeinitializeIntelDrm();
        int32_t         OpenIntelDrm();
        void            CloseIntelDrm( int32_t drmFd );
        int32_t         GetDrmCardNumber( int32_t drmFd );
        TCompletionCode AcquireAdapterId();

        // SysFs
        TCompletionCode ReadSysFsFile( const char* fileName, uint64_t* readValue );
        TCompletionCode WriteSysFsFile( const char* fileName, uint64_t value );
        TCompletionCode ReadUInt64FromFile( const char* filePath, uint64_t* readValue );
        TCompletionCode WriteUInt64ToFile( const char* filePath, uint64_t value );

        // IOCTLs
        int32_t         SendIoctl( int32_t drmFd, uint32_t request, void* argument );
        TCompletionCode SendGetParamIoctl( int32_t drmFd, uint32_t paramId, GTDIDeviceInfoParamExtOut* outValue );
        TCompletionCode SendGetParamIoctl( int32_t drmFd, uint32_t paramId, int32_t* outValue );

        // Device info params
        TCompletionCode GetGfxDeviceInfo( const TGfxDeviceInfo** gfxDeviceInfo );
        TCompletionCode GetDeviceId( int32_t* deviceId );
        TCompletionCode GetPerfRevision( int32_t* perfRevision );
        TCompletionCode GetGpuFrequencyInfo( uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency, uint64_t* boostFrequency );
        TCompletionCode GetGpuTimestampFrequency( uint64_t* gpuTimestampFrequency );
        TCompletionCode GetGpuTimestampPeriodNs( uint64_t* gpuTimestampPeriodNs );
        TCompletionCode GetGpuTimestampNs( CMetricsDevice& metricsDevice, uint64_t* gpuTimestampNs );
        TCompletionCode GetGpuTimestampTicks( uint64_t* gpuTimestampTicks );
        TCompletionCode GetCpuTimestampNs( uint64_t* cpuTimestampNs );
        TCompletionCode GetOaBufferCount( CMetricsDevice& metricsDevice, uint32_t& oaBufferCount );

        // Device info utils
        uint32_t   GetGtMaxSubslicePerSlice();
        uint32_t   GetGtMaxDualSubslicePerSlice();
        bool       IsXePlus();
        bool       IsDualSubsliceSupported();
        TGfxGtType MapDeviceInfoToInstrGtTypeGfxVer12( const TGfxDeviceInfo* gfxDeviceInfo, CMetricsDevice* metricsDevice );

        // General utils
        uint32_t CalculateEnabledBits( uint64_t value, uint64_t mask = UINT64_MAX );
        uint32_t GetTimerPeriodExponent( uint32_t nsTimerPeriod );
        uint32_t GetNsTimerPeriod( uint32_t timerPeriodExponent );
        uint32_t CalculateOaBufferSize( const uint32_t requestedBufferSize );

    private:                                    // Variables
        CAdapterHandleLinux& m_DrmDeviceHandle; // Adapter handle with which this driver interface communicates.
                                                // Important: handle owned by CAdapter object.
        int32_t           m_DrmCardNumber;      // Used for SysFs reads / writes
        TPerfCapabilities m_PerfCapabilities;   // Information about i915 Perf features supported in current kernel

        // Query
        std::vector<int32_t> m_AddedPerfConfigs; // IDs of configurations added to Perf for the need of query, needed for later config removal

        // Cached values
        uint64_t       m_CachedBoostFrequency;
        uint64_t       m_CachedMinFrequency;
        uint64_t       m_CachedMaxFrequency;
        TGfxDeviceInfo m_CachedGfxDeviceInfo;
        int32_t        m_CachedDeviceId;
        int32_t        m_CachedPerfRevision;
    };

} // namespace MetricsDiscoveryInternal
