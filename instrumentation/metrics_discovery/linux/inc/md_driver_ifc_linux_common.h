/*========================== begin_copyright_notice ============================

Copyright (C) 2023-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_common.h
//
//     Abstract:   C++ common implementation for Linux

#pragma once

#include "md_driver_ifc.h"

#include <mutex>
#include <chrono>
#include <vector> // for Query
#include <condition_variable>

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     General defines used by Perf driver interface.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_PATH_LENGTH     128
#define MD_PERF_GUID_LENGTH    37                                     // GUID is a string formatted like "%08x-%04x-%04x-%04x-%012x"
#define MD_PERF_GUID_FOR_QUERY "2f01b241-7014-42a7-9eb6-a925cad3daba" // static GUID for storing Query configuration

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Register used for reading GPU Timestamp.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_TIMESTAMP_LOW_OFFSET 0x2358

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Default GpuTimestampFrequency, used if value obtained from drm is invalid.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_DEFAULT_GPU_TIMESTAMP_FREQUENCY 12000000; // Default, one tick per 83.333ns.

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Hardware info used in number of shading units and number of render output
//     units calculation. Based on Intel driver instrumentation files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_NUM_PIXELS_OUT_PER_CLOCK         ( 4 )
#define MD_EU_SIMD_SIZE_PER_CLOCK           ( 4 )
#define MD_L3_BANK_COUNT_PER_L3_NODE        ( 4 )
#define MD_L3_NODE_COUNT_PER_COPY_ENGINE    ( 2 )
#define MD_L3_NODE_COUNT_PER_PAIR_OF_SLICES ( 2 )
#define MD_OLD_EU_COUNT_PER_NEW_EU_COUNT    ( 2 )

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     For platforms <= SKL mask of size '3' is used to preserve backward compatibility
//     with MDAPI metric equation definitions. Based on Intel driver instrumentation
//     files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_SUBSLICE_PER_SLICE_OLD 3

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Maximums which bound all supported GT. Must update as needed with new GT.
//     Based on Intel driver files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_SUBSLICE_PER_SLICE      8  // Currently max value
#define MD_MAX_SLICE                   8  // Currently max value
#define MD_MAX_DUALSUBSLICE_PER_SLICE  6  // Currently max value
#define MD_MAX_SUBSLICE_PER_DSS        2  // Currently max value
#define MD_MAX_L3_NODE                 16 // Currently max value
#define MD_MAX_L3_BANK_PER_L3_NODE     4  // Currently max value
#define MD_MAX_L3_NODE_PER_COPY_ENGINE 2  // Currently max value
#define MD_DUALSUBSLICE_PER_SLICE      4  // Current value
#define MD_SUBSLICE_PER_SLICE_BMG      4  // Current Xe2 value

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Masks helping to define OA Adder workaround need
//
//////////////////////////////////////////////////////////////////////////////
#define SLICES0TO3  0x0F
#define SLICES4TO7  0xF0
#define SLICES4AND5 0x30
#define SLICES6AND7 0xC0

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Oa buffer min/max size value
//
//////////////////////////////////////////////////////////////////////////////
// Oa buffer min/max size is equal to 16 MB
#define MD_OA_BUFFER_SIZE_MAX ( 16 * MD_MBYTE )

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
    // Enum:
    //     TDrmVersion
    //
    // Description:
    //     DRM driver version.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef enum EDrmVersion
    {
        DRM_VERSION_I915 = 0,
        DRM_VERSION_XE   = 1,
        // ...
        DRM_VERSION_UNDEFINED,
    } TDrmVersion;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Enum:
    //     TSysFsType
    //
    // Description:
    //     SysFs types.
    //     Min/Max frequency files return the min/max frequency that can be set on the HW.
    //     Min/Max/Boost frequency override files return currently set frequency. Setting
    //     static frequency requires writing to all of these 3 files.
    //
    //////////////////////////////////////////////////////////////////////////////
    typedef enum ESysFsType
    {
        SYS_FS_ACT_FREQ      = 0,
        SYS_FS_MAX_FREQ      = 1,
        SYS_FS_MIN_FREQ      = 2,
        SYS_FS_MAX_FREQ_OV   = 3,
        SYS_FS_MIN_FREQ_OV   = 4,
        SYS_FS_BOOST_FREQ_OV = 5,
        // ...
        SYS_FS_UNDEFINED,
    } TSysFsType;

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
        std::mutex              m_mutex;
        std::condition_variable m_conditionVariable;
        uint32_t                m_count;
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
    //     CDriverInterfaceLinuxCommon
    //
    // Description:
    //     Common driver interface class implementation for Linux based systems.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterfaceLinuxCommon : public CDriverInterface
    {
    public: // Constructor & Destructor
        CDriverInterfaceLinuxCommon( CAdapterHandle& adapterHandle, const TDrmVersion drmVersion );
        virtual ~CDriverInterfaceLinuxCommon();

        CDriverInterfaceLinuxCommon( const CDriverInterfaceLinuxCommon& )            = delete; // Delete copy-constructor
        CDriverInterfaceLinuxCommon& operator=( const CDriverInterfaceLinuxCommon& ) = delete; // Delete assignment operator

    public: // Methods
        // Static
        static TCompletionCode GetGfxDeviceInfo( int32_t deviceId, TGfxDeviceInfo& gfxDeviceInfo );
        static TAdapterType    GetAdapterType( const TGfxDeviceInfo& gfxDeviceInfo );
        static TDrmVersion     GetDrmVersion( int32_t drmFd );

        // Read global symbols per tile.
        virtual TCompletionCode GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )       = 0;
        virtual TCompletionCode GetEuCoresPerSubsliceCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice ) = 0;
        virtual TCompletionCode GetSliceMask( int32_t& sliceMask, CMetricsDevice& metricsDevice )                           = 0;
        virtual TCompletionCode GetSubsliceMask( int64_t& subsliceMask, CMetricsDevice& metricsDevice )                     = 0;

        // General
        virtual TCompletionCode ForceSupportDisable();
        virtual TCompletionCode SendSupportEnableEscape( bool enable );
        virtual TCompletionCode SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice );
        virtual TCompletionCode GetMaxMinOaBufferSize( const GTDI_OA_BUFFER_TYPE oaBufferType, const GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice );
        virtual TCompletionCode SendPmRegsConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const GTDI_OA_BUFFER_TYPE oaBufferType );
        virtual TCompletionCode SendReadRegsConfig( TRegister** regVector, uint32_t regCount );
        virtual TCompletionCode GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle );
        virtual TCompletionCode ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, uint32_t platformId );
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestamp, uint64_t& cpuTimestamp, uint32_t& cpuId, uint64_t& correlationIndicator ) = 0;
        virtual bool            IsTbsEngineValid( const TEngineParamsLatest& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false ) const             = 0;
        virtual TCompletionCode SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params );
        virtual uint32_t        GetAdapterId();
        virtual bool            IsOaBufferSupported( const GTDI_OA_BUFFER_TYPE oaBufferType, CMetricsDevice& metricsDevice );
        TCompletionCode         GetOaTimestamp( const uint64_t csTimestamp, uint64_t& oaTimestamp );

        // Synchronization
        virtual TCompletionCode LockConcurrentGroup( const char* name, void** semaphore );
        virtual TCompletionCode UnlockConcurrentGroup( const char* name, void** semaphore );

        // Stream
        virtual TCompletionCode OpenIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& nsTimerPeriod, uint32_t& bufferSize );
        virtual TCompletionCode ReadIoStream( COAConcurrentGroup& oaConcurrentGroup, char* reportData, uint32_t& reportsCount, uint32_t& frequency, GTDIReadCounterStreamExceptions& exceptions );
        virtual TCompletionCode CloseIoStream( COAConcurrentGroup& oaConcurrentGroup );
        virtual TCompletionCode HandleIoStreamExceptions( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& reportCount, const GTDIReadCounterStreamExceptions exceptions );
        virtual TCompletionCode WaitForIoStreamReports( COAConcurrentGroup& oaConcurrentGroup, const uint32_t milliseconds );
        virtual bool            IsIoMeasurementInfoAvailable( const TIoMeasurementInfoType ioMeasurementInfoType );
        virtual bool            IsStreamTypeSupported( const TStreamType streamType );

        // Overrides
        virtual TCompletionCode SetFrequencyOverride( CMetricsDevice& device, const TSetFrequencyOverrideParams_1_2& params );
        virtual TCompletionCode SetQueryOverride( TOverrideType overrideType, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2& params );
        virtual TCompletionCode SetFreqChangeReportsOverride( bool enable );
        virtual bool            IsOverrideAvailable( TOverrideType overrideType );
        virtual bool            IsSubDeviceSupported()                         = 0;
        virtual TCompletionCode EnumerateSubDevices( CSubDevices& subDevices ) = 0;
        virtual TQueryMode      GetQueryModeOverride();

    protected:
        virtual bool CreateContext() = 0;
        virtual void DeleteContext();

    protected:
        // OA
        virtual TCompletionCode OpenOaStream( CMetricsDevice& metricsDevice, uint32_t oaMetricSetId, uint32_t oaReportType, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType ) = 0;
        virtual TCompletionCode ReadOaStream( CMetricsDevice& metricsDevice, uint32_t reportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions )          = 0;
        TCompletionCode         CloseOaStream( CMetricsDevice& metricsDevice );
        TCompletionCode         WaitForOaStreamReports( CMetricsDevice& metricsDevice, uint32_t timeoutMs );
        std::string             GenerateQueryGuid( const uint32_t subDeviceIndex );
        virtual TCompletionCode AddOaConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId ) = 0;
        virtual TCompletionCode RemoveOaConfig( int32_t oaConfigId )                                                                                                            = 0;
        TCompletionCode         RemoveOaConfigQuery( const char* guid );
        TCompletionCode         GetOaMetricSetId( const char* guid, int32_t& oaMetricSetId );
        bool                    OaMetricSetExists( const char* guid );
        virtual uint32_t        GetOaReportType( const TReportType reportType ) = 0;
        virtual TCompletionCode GetOaTimestampFrequency( uint64_t& frequency )  = 0;
        virtual TCompletionCode GetCsTimestampFrequency( uint64_t& frequency )  = 0;

        // DRM
        bool            InitializeIntelDrm();
        void            DeinitializeIntelDrm();
        int32_t         GetDrmCardNumber( int32_t drmFd );
        TCompletionCode AcquireAdapterId();

        // SysFs
        virtual void    GetSysFsPath( CMetricsDevice& device, const TSysFsType fileType, char* filePath, const uint32_t filePathLength ) = 0;
        TCompletionCode ReadSysFsFile( CMetricsDevice& device, const TSysFsType fileType, uint64_t* readValue );
        TCompletionCode WriteSysFsFile( CMetricsDevice& device, const TSysFsType fileType, uint64_t value );
        TCompletionCode ReadUInt64FromFile( const char* filePath, uint64_t* readValue );
        TCompletionCode WriteUInt64ToFile( const char* filePath, uint64_t value );

        // IOCTL
        static int32_t SendIoctl( int32_t drmFd, uint32_t request, void* argument );

        // Device info params
        TCompletionCode         GetGfxDeviceInfo( const TGfxDeviceInfo*& gfxDeviceInfo );
        virtual TCompletionCode GetDeviceId( int32_t& deviceId )    = 0;
        virtual TCompletionCode GetRevisionId( int32_t& evisionId ) = 0;
        TCompletionCode         GetGpuFrequencyInfo( CMetricsDevice& device, uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency, uint64_t* boostFrequency );
        TCompletionCode         GetGpuTimestampFrequency( uint64_t& gpuTimestampFrequency );
        TCompletionCode         GetGpuTimestampPeriodNs( uint64_t& gpuTimestampPeriodNs );

        virtual TCompletionCode GetOaBufferSize( const int32_t streamId, uint32_t& oaBufferSize )                            = 0;
        virtual TCompletionCode GetOaBufferSupportedSizes( const uint32_t platformId, uint32_t& minSize, uint32_t& maxSize ) = 0;
        virtual TCompletionCode GetOaBufferCount( CMetricsDevice& metricsDevice, uint32_t& oaBufferCount )                   = 0;
        virtual TCompletionCode GetL3NodeTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3NodeCount )                  = 0;
        virtual TCompletionCode GetL3BankTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3BankCount )                  = 0;
        virtual TCompletionCode GetComputeEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& computeEngineCount )    = 0;
        virtual TCompletionCode GetL3BankMask( CMetricsDevice& metricsDevice, uint64_t& l3BankMask )                         = 0;
        virtual TCompletionCode GetL3NodeMask( CMetricsDevice& metricsDevice, uint64_t& l3NodeMask )                         = 0;
        virtual TCompletionCode GetCopyEngineMask( CMetricsDevice& metricsDevice, uint64_t& copyEngineMask )                 = 0;

        // Device info utils
        uint32_t   GetGtMaxSubslicePerSlice();
        uint32_t   GetGtMaxDualSubslicePerSlice();
        bool       IsDualSubsliceSupported();
        TGfxGtType MapDeviceInfoToInstrGtTypeGfxVer12( const TGfxDeviceInfo& gfxDeviceInfo, CMetricsDevice& metricsDevice );

        // General utils
        uint32_t GetTimerPeriodExponent( uint32_t nsTimerPeriod );
        uint32_t GetNsTimerPeriod( uint32_t timerPeriodExponent );
        uint32_t CalculateOaBufferSize( const uint32_t requestedBufferSize, CMetricsDevice& metricsDevice );

    protected:
        // Variables
        CAdapterHandleLinux& m_DrmDeviceHandle; // Adapter handle with which this driver interface communicates.
                                                // Important: handle owned by CAdapter object.
        int32_t     m_DrmCardNumber;            // Used for SysFs reads / writes
        TDrmVersion m_DrmVersion;

        // Query
        std::vector<int32_t> m_AddedOaConfigs; // IDs of configurations added to i915 Perf or XE OA for the need of query, needed for later config removal

        // Cached values
        uint64_t       m_CachedBoostFrequency;
        uint64_t       m_CachedMinFrequency;
        uint64_t       m_CachedMaxFrequency;
        TGfxDeviceInfo m_CachedGfxDeviceInfo;
        int32_t        m_CachedDeviceId;
        int32_t        m_CachedRevisionId;
    };

} // namespace MetricsDiscoveryInternal
