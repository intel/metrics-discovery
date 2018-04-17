/*****************************************************************************\

    Copyright © 2018, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  md_driver_ifc_linux_perf.h

    Abstract:   C++ implementation for Linux/Android with Perf

\*****************************************************************************/
#pragma once

#include <mutex>
#include <chrono>
#include <vector>   // for Query
#include <condition_variable>

#include "md_driver_ifc.h"

#if defined(__cplusplus)
extern "C" {
#endif
  #include "gen_device_info.h"    // MESA
#if defined(__cplusplus)
}
#endif

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{

/*****************************************************************************\

Enum:
    TGfxGtType

Description:
    Based on 'GTTYPE' struct from Intel driver files, it should be in sync
    with that struct.
    ! DO NOT CHANGE THE ORDER OR INDICES !

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CSemaphore

Description:
    Used in driver interface to provide semaphore functionality on different
    OSes.

\*****************************************************************************/
class CSemaphore
{
public:
    CSemaphore();
    void Notify();
    void Wait();
    bool WaitFor( uint64_t timeoutNs );
    bool TryWait();
    uint32_t GetValue();

private:
    typedef std::mutex TFenceMutex;
    typedef std::condition_variable TFenceConditionVariable;

    TFenceMutex             semMutex;
    TFenceConditionVariable semCv;
    uint32_t                semCount;
};

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Description:
    Driver interface class implementation for Linux based systems with i915 Perf.

\*****************************************************************************/
class CDriverInterfaceLinuxPerf: public CDriverInterface
{
public: // Constructor & Destructor
    CDriverInterfaceLinuxPerf();
    virtual ~CDriverInterfaceLinuxPerf();

public: // Methods
    // General
    virtual const char*             GetDeviceName();
    virtual bool                    GetNeedSupportEnable();
    virtual TCompletionCode         SendSupportEnableEscape( bool enable );
    virtual TCompletionCode         SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamOut* out );
    virtual TCompletionCode         SendPmRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask );
    virtual TCompletionCode         SendReadRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask );
    virtual TCompletionCode         GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle );
    virtual TCompletionCode         ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, TPlatformType platform );
    virtual TCompletionCode         GetGpuCpuTimestamps( uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId );
    virtual TCompletionCode         SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params );

    // Synchronization
    virtual TCompletionCode         SemaphoreCreate( const char* name, void** semaphore );
    virtual TSemaphoreWaitResult    SemaphoreWait( uint32_t milliseconds, void* semaphore );
    virtual TCompletionCode         SemaphoreRelease( void** semaphore );
    virtual TCompletionCode         LockConcurrentGroup( const char* name, void** semaphore );
    virtual TCompletionCode         UnlockConcurrentGroup( const char* name, void** semaphore );

    // Stream
    virtual TCompletionCode         OpenIoStream( TStreamType streamType, CMetricSet* metricSet, const char* concurrentGroupName, uint32_t processId,
        uint32_t* nsTimerPeriod, uint32_t* bufferSize, void** streamEventHandle );
    virtual TCompletionCode         ReadIoStream( TStreamType streamType, IMetricSet_1_0* metricSet, char* reportData, uint32_t* reportsCount, uint32_t readFlags,
        uint32_t* frequency, GTDIReadCounterStreamExceptions* exceptions );
    virtual TCompletionCode         CloseIoStream( TStreamType streamType, void** openStreamEventHandle, const char* concurrentGroupName, CMetricSet* metricSet );
    virtual TCompletionCode         WaitForIoStreamReports( TStreamType streamType, uint32_t milliseconds, void* streamEventHandle );
    virtual bool                    IsIoMeasurementInfoAvailable( TIoMeasurementInfoType ioMeasurementInfoType );

    // Overrides
    virtual TCompletionCode         SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params );
    virtual TCompletionCode         SetQueryOverride( TOverrideType overrideType, TPlatformType platorm, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params );
    virtual TCompletionCode         SetFreqChangeReportsOverride( bool enable );
    virtual bool                    IsOverrideAvailable( TOverrideType overrideType );

protected:
    virtual bool    CreateContext();
    virtual void    DeleteContext();

private:
    // Perf
    TCompletionCode OpenPerfStream( uint32_t perfMetricSetId, uint32_t perfReportType, uint32_t timerPeriodExponent );
    TCompletionCode ReadPerfStream( uint32_t oaReportSize, uint32_t reportsToRead, char* reportData, uint32_t* readBytes, bool* reportLostOccured );
    TCompletionCode ClosePerfStream();
    TCompletionCode WaitForPerfStreamReports( uint32_t timeoutMs );
    TCompletionCode AddPerfConfig( TRegister** regVector, uint32_t regCount, const char* requestedGuid, int32_t* addedConfigId );
    TCompletionCode RemovePerfConfig( int32_t perfConfigId );
    TCompletionCode RemovePerfConfigQuery();
    TCompletionCode GetPerfMetricSetId( const char* guid, uint32_t* perfMetricSetId );
    bool            PerfMetricSetExists( const char* guid );

    // DRM
    bool            InitializeIntelDrm();
    void            DeinitializeIntelDrm();
    int32_t         OpenIntelDrm();
    void            CloseIntelDrm( int32_t drmFd );
    int32_t         GetDrmCardNumber( int32_t drmFd );

    // SysFs
    TCompletionCode ReadSysFsFile( const char* fileName, uint64_t* readValue );
    TCompletionCode WriteSysFsFile( const char* fileName, uint64_t value );
    TCompletionCode ReadUInt64FromFile( const char* filePath, uint64_t* readValue );
    TCompletionCode WriteUInt64ToFile( const char* filePath, uint64_t value );

    // IOCTLs
    int32_t         SendIoctl( int32_t drmFd, uint32_t request, void* argument );
    TCompletionCode SendGetParamIoctl( int32_t drmFd, uint32_t paramId, GTDIDeviceInfoParamOut* outValue );
    TCompletionCode SendGetParamIoctl( int32_t drmFd, uint32_t paramId, int32_t* outValue );

    // Device info params
    TCompletionCode GetMesaDeviceInfo( const gen_device_info** mesaDeviceInfo );
    TCompletionCode GetDeviceId( int32_t* deviceId );
    TCompletionCode GetInstrPlatformId( GTDI_PLATFORM_INDEX* instrPlatformId );
    TCompletionCode GetGpuFrequencyInfo( uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency, uint64_t* boostFrequency );
    TCompletionCode GetGpuTimestampFrequency( uint64_t* gpuTimestampFrequency );
    TCompletionCode GetGpuTimestampPeriodNs( uint64_t* gpuTimestampPeriodNs );
    TCompletionCode GetGpuTimestampNs( uint64_t* gpuTimestampNs );
    TCompletionCode GetGpuTimestampTicks( uint64_t* gpuTimestampTicks );
    TCompletionCode GetCpuTimestampNs( uint64_t* cpuTimestampNs );

    // Device info utils
    uint32_t        GetGtMaxSubslicePerSlice();
    TCompletionCode MapMesaToInstrPlatform( const gen_device_info* mesaDeviceInfo, GTDI_PLATFORM_INDEX* outInstrPlatformId );
    TGfxGtType      MapMesaToInstrGtType( int32_t mesaGtType );

    // General utils
    uint32_t        CalculateEnabledBits( uint32_t value, uint32_t mask );
    uint32_t        GetTimerPeriodExponent( uint32_t nsTimerPeriod );
    uint32_t        GetNsTimerPeriod( uint32_t timerPeriodExponent );

private: // Variables
    int32_t                      m_DrmFd;                       // DRM file descriptor, used mostly for sending IOCTLs
    int32_t                      m_DrmCardNumber;               // Used for SysFs reads / writes
    int32_t                      m_PerfStreamFd;                // Opened Perf stream file descriptor
    int32_t                      m_PerfStreamConfigId;          // Perf configuration ID used for opening Perf stream, needed for config removal

    // Query
    std::vector<int32_t>         m_AddedPerfConfigs;            // IDs of configurations added to Perf for the need of query, needed for later config removal
};

}
