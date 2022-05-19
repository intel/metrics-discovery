/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc.h

//     Abstract:   C++ driver interface header

#pragma once

#include "md_types.h"
#include "md_debug.h"

#include "instr_gt_driver_ifc.h"

#include <vector>

#define MD_SEMAPHORE_NAME_MAX_LENGTH 250

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    class CAdapterHandle;
    class CMetricsDevice;
    class CMetricSet;

    ///////////////////////////////////////////////////////////////////////////////
    // Semaphore wait result:                                                    //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum ESemaphoreWaitResult
    {
        WAIT_RESULT_SUCCESSFUL,
        WAIT_RESULT_TIMEOUT,
        WAIT_RESULT_ERROR_GENERAL,

    } TSemaphoreWaitResult;

    ///////////////////////////////////////////////////////////////////////////////
    // Override ID map to not include instr files in (md)_internal.cpp           //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EOverrideId
    {
        OVERRIDE_ID_NOT_AVAILABLE,
        OVERRIDE_ID_NULL_HARDWARE,
        OVERRIDE_ID_FLUSH_GPU_CACHES,
    } TOverrideId;

    ///////////////////////////////////////////////////////////////////////////////
    // Adapter data:                                                             //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SAdapterData
    {
        CAdapterHandle*    Handle;
        TAdapterParams_1_9 Params;
    } TAdapterData;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandle
    //
    // Description:
    //     Abstract adapter handle wrapper class.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapterHandle
    {
    public:
        virtual ~CAdapterHandle() = default;

        virtual TCompletionCode Close( const uint32_t adapterId ) = 0;
        virtual bool            IsValid() const                   = 0;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Description:
    //     Abstract driver interface class.
    //     Each implementation should derive from this class and implement static method GetInstance()
    //     to return object of this implementation.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CDriverInterface
    {
    public: // Destructor:
        virtual ~CDriverInterface(){};

    public:
        // Creation and debug settings static:
        static CDriverInterface* CreateInstance( CAdapterHandle& adapterHandle );
        static void              ReadDebugLogSettings();
        static bool              IsSupportEnableRequired();

        // Adapter enumeration static:
        static TCompletionCode GetAvailableAdapters( std::vector<TAdapterData>& adapters, const uint32_t adapterId );

        // Synchronization static:
        static TCompletionCode      SemaphoreCreate( const char* name, void** semaphore, const uint32_t adapterId );
        static TSemaphoreWaitResult SemaphoreWait( uint32_t milliseconds, void* semaphore, const uint32_t adapterId );
        static TCompletionCode      SemaphoreRelease( void** semaphore, const uint32_t adapterId );

        // General:
        virtual TCompletionCode ForceSupportDisable()                                                                                                                          = 0;
        virtual TCompletionCode SendSupportEnableEscape( bool enable )                                                                                                         = 0;
        virtual TCompletionCode SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice = nullptr )                  = 0;
        virtual TCompletionCode SendPmRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask )                                                                 = 0;
        virtual TCompletionCode SendReadRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask )                                                               = 0;
        virtual TCompletionCode GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle )                      = 0;
        virtual TCompletionCode ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, TPlatformType platform )                                                        = 0;
        virtual TCompletionCode GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId, uint64_t* correlationIndicator ) = 0;
        virtual TCompletionCode SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params )                                                                                          = 0;
        virtual uint32_t        GetAdapterId()                                                                                                                                 = 0;

        // Synchronization:
        virtual TCompletionCode LockConcurrentGroup( const char* name, void** semaphore )   = 0;
        virtual TCompletionCode UnlockConcurrentGroup( const char* name, void** semaphore ) = 0;

        // Stream:
        virtual TCompletionCode OpenIoStream( TStreamType streamType, CMetricsDevice& metricDevice, CMetricSet* metricSet, const char* concurrentGroupName, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* bufferSize, void** streamEventHandle )   = 0;
        virtual TCompletionCode ReadIoStream( TStreamType streamType, CMetricsDevice& metricDevice, CMetricSet* metricSet, char* reportData, uint32_t* reportsCount, uint32_t readFlags, uint32_t* frequency, GTDIReadCounterStreamExceptions* exceptions ) = 0;
        virtual TCompletionCode CloseIoStream( TStreamType streamType, CMetricsDevice& metricDevice, void** streamEventHandle, const char* concurrentGroupName, CMetricSet* metricSet )                                                                     = 0;
        virtual TCompletionCode HandleIoStreamExceptions( const char* concurrentGroupName, CMetricSet* metricSet, uint32_t processId, uint32_t* reportCount, GTDIReadCounterStreamExceptions* exceptions )                                                  = 0;
        virtual TCompletionCode WaitForIoStreamReports( TStreamType streamType, CMetricsDevice& metricDevice, uint32_t milliseconds, void* streamEventHandle )                                                                                              = 0;
        virtual bool            IsIoMeasurementInfoAvailable( TIoMeasurementInfoType ioMeasurementInfoType )                                                                                                                                                = 0;

        // Overrides:
        virtual TCompletionCode SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params )                                                                    = 0;
        virtual TCompletionCode SetQueryOverride( TOverrideType overrideType, TPlatformType platform, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params ) = 0;
        virtual TCompletionCode SetFreqChangeReportsOverride( bool enable )                                                                                              = 0;
        virtual bool            IsOverrideAvailable( TOverrideType overrideType )                                                                                        = 0;
        virtual bool            IsSubDeviceSupported()                                                                                                                   = 0;

    protected:
        virtual bool CreateContext() = 0;
        virtual void DeleteContext() = 0;
        uint32_t     m_adapterId     = IU_ADAPTER_ID_UNKNOWN;
    };

} // namespace MetricsDiscoveryInternal
