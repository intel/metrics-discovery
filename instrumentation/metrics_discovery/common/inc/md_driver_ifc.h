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

    File Name:  md_driver_ifc.h

    Abstract:   C++ driver interface header

\*****************************************************************************/
#pragma once

#include "md_types.h"
#include "md_internal.h"

#include "instr_gt_driver_ifc.h"

#define MD_SEMAPHORE_NAME_MAX_LENGTH 250

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
/* Forward declarations */
class CMetricSet;

/******************************************************************************/
/* Semaphore wait result:                                                     */
/******************************************************************************/
typedef enum ESemaphoreWaitResult
{
    WAIT_RESULT_SUCCESSFUL,
    WAIT_RESULT_TIMEOUT,
    WAIT_RESULT_ERROR_GENERAL,

} TSemaphoreWaitResult;

/******************************************************************************/
/* Override ID map to not include instr files in (md)_internal.cpp            */
/******************************************************************************/
typedef enum EOverrideId
{
    OVERRIDE_ID_NOT_AVAILABLE,
    OVERRIDE_ID_NULL_HARDWARE,
    OVERRIDE_ID_FLUSH_GPU_CACHES,
} TOverrideId;

/*****************************************************************************\

Class:
    CDriverInterface

Description:
    Abstract driver interface class.
    Each implementation should derive from this class and implement static method GetInstance()
    to return object of this implementation.

\*****************************************************************************/
class CDriverInterface
{
public: // Destructor
    virtual ~CDriverInterface() { };

public:
    static CDriverInterface* GetInstance();

public: // Methods
    // General
    virtual const char*            GetDeviceName() = 0;
    virtual bool                   GetNeedSupportEnable() = 0;
    virtual TCompletionCode        SendSupportEnableEscape( bool enable ) = 0;
    virtual TCompletionCode        SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamOut* out ) = 0;
    virtual TCompletionCode        SendPmRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask ) = 0;
    virtual TCompletionCode        SendReadRegsConfig(TRegister** regVector, uint32_t regCount, uint32_t apiMask ) = 0;
    virtual TCompletionCode        GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle ) = 0;
    virtual TCompletionCode        ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, TPlatformType platform ) = 0;
    virtual TCompletionCode        GetGpuCpuTimestamps( uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId ) = 0;
    virtual TCompletionCode        SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params ) = 0;

    // Synchronization
    virtual TCompletionCode        SemaphoreCreate( const char* name, void** semaphore ) = 0;
    virtual TSemaphoreWaitResult   SemaphoreWait( uint32_t milliseconds, void* semaphore ) = 0;
    virtual TCompletionCode        SemaphoreRelease( void** semaphore ) = 0;
    virtual TCompletionCode        LockConcurrentGroup( const char* name, void**semaphore ) = 0;
    virtual TCompletionCode        UnlockConcurrentGroup( const char* name, void**semaphore ) = 0;

    // Stream
    virtual TCompletionCode        OpenIoStream( TStreamType streamType, CMetricSet* metricSet, const char* concurrentGroupName, uint32_t processId,
        uint32_t* nsTimerPeriod, uint32_t* bufferSize, void** streamEventHandle ) = 0;
    virtual TCompletionCode        ReadIoStream( TStreamType streamType, IMetricSet_1_0* metricSet, char* reportData, uint32_t* reportsCount, uint32_t readFlags,
        uint32_t* frequency, GTDIReadCounterStreamExceptions* exceptions ) = 0;
    virtual TCompletionCode        CloseIoStream( TStreamType streamType, void** streamEventHandle, const char* concurrentGroupName, CMetricSet* metricSet ) = 0;
    virtual TCompletionCode        WaitForIoStreamReports( TStreamType streamType, uint32_t milliseconds, void* streamEventHandle ) = 0;
    virtual bool                   IsIoMeasurementInfoAvailable( TIoMeasurementInfoType ioMeasurementInfoType ) = 0;

    // Overrides
    virtual TCompletionCode        SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params ) = 0;
    virtual TCompletionCode        SetQueryOverride( TOverrideType overrideType, TPlatformType platform, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params ) = 0;
    virtual TCompletionCode        SetFreqChangeReportsOverride( bool enable ) = 0;
    virtual bool                   IsOverrideAvailable( TOverrideType overrideType ) = 0;

protected:
    virtual bool CreateContext() = 0;
    virtual void DeleteContext() = 0;
};

}
