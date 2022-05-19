/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_common.cpp

//     Abstract:   C++ Metrics Discovery internal common implementation

#include "metrics_discovery_internal_api.h"

namespace MetricsDiscovery
{
    IEquation_1_0::~IEquation_1_0()
    {
    }
    uint32_t IEquation_1_0::GetEquationElementsCount( void )
    {
        return 0;
    }
    TEquationElement_1_0* IEquation_1_0::GetEquationElement( uint32_t index )
    {
        return nullptr;
    }

    IMetricsDevice_1_0::~IMetricsDevice_1_0()
    {
    }
    TMetricsDeviceParams_1_0* IMetricsDevice_1_0::GetParams( void )
    {
        return nullptr;
    }
    IConcurrentGroup_1_0* IMetricsDevice_1_0::GetConcurrentGroup( uint32_t index )
    {
        return nullptr;
    }
    TGlobalSymbol_1_0* IMetricsDevice_1_0::GetGlobalSymbol( uint32_t index )
    {
        return nullptr;
    }
    TTypedValue_1_0* IMetricsDevice_1_0::GetGlobalSymbolValueByName( const char* name )
    {
        return nullptr;
    }
    TCompletionCode IMetricsDevice_1_0::GetLastError( void )
    {
        return CC_LAST_1_0;
    }
    TCompletionCode IMetricsDevice_1_0::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IConcurrentGroup_1_1* IMetricsDevice_1_1::GetConcurrentGroup( uint32_t index )
    {
        return nullptr;
    }
    TMetricsDeviceParams_1_2* IMetricsDevice_1_2::GetParams( void )
    {
        return nullptr;
    }
    IOverride_1_2* IMetricsDevice_1_2::GetOverride( uint32_t index )
    {
        return nullptr;
    }
    IOverride_1_2* IMetricsDevice_1_2::GetOverrideByName( const char* name )
    {
        return nullptr;
    }
    IConcurrentGroup_1_5* IMetricsDevice_1_5::GetConcurrentGroup( uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricsDevice_1_10::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId, uint64_t* correlationIndicatorNs )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IConcurrentGroup_1_11* IMetricsDevice_1_11::GetConcurrentGroup( uint32_t index )
    {
        return nullptr;
    }

    IOverride_1_2::~IOverride_1_2()
    {
    }
    TOverrideParams_1_2* IOverride_1_2::GetParams( void )
    {
        return nullptr;
    }
    TCompletionCode IOverride_1_2::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    IConcurrentGroup_1_0::~IConcurrentGroup_1_0()
    {
    }
    TConcurrentGroupParams_1_0* IConcurrentGroup_1_0::GetParams( void )
    {
        return nullptr;
    }
    IMetricSet_1_0* IConcurrentGroup_1_0::GetMetricSet( uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IConcurrentGroup_1_0::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::ReadIoStream( uint32_t* reportsCount, char* reportData, uint32_t readFlags )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::CloseIoStream( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::WaitForReports( uint32_t milliseconds )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IInformation_1_0* IConcurrentGroup_1_0::GetIoMeasurementInformation( uint32_t index )
    {
        return nullptr;
    }
    IInformation_1_0* IConcurrentGroup_1_0::GetIoGpuContextInformation( uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_1* IConcurrentGroup_1_1::GetMetricSet( uint32_t index )
    {
        return nullptr;
    }

    TCompletionCode IConcurrentGroup_1_3::SetIoStreamSamplingType( TSamplingType type )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    IMetricSet_1_5* IConcurrentGroup_1_5::GetMetricSet( uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_11* IConcurrentGroup_1_11::GetMetricSet( uint32_t index )
    {
        return nullptr;
    }

    IMetricSet_1_0::~IMetricSet_1_0()
    {
    }
    TMetricSetParams_1_0* IMetricSet_1_0::GetParams( void )
    {
        return nullptr;
    }
    IMetric_1_0* IMetricSet_1_0::GetMetric( uint32_t index )
    {
        return nullptr;
    }
    IInformation_1_0* IMetricSet_1_0::GetInformation( uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_0* IMetricSet_1_0::GetComplementaryMetricSet( uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricSet_1_0::Activate( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_0::Deactivate( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IMetric_1_0* IMetricSet_1_0::AddCustomMetric( const char* symbolicName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName )
    {
        return nullptr;
    }

    IMetricSet_1_1::~IMetricSet_1_1()
    {
    }
    TCompletionCode IMetricSet_1_1::SetApiFiltering( uint32_t apiMask )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_1::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_1::CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IMetricSet_1_4::~IMetricSet_1_4()
    {
    }
    TMetricSetParams_1_4* IMetricSet_1_4::GetParams( void )
    {
        return nullptr;
    }
    IMetricSet_1_5* IMetricSet_1_5::GetComplementaryMetricSet( uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricSet_1_5::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IMetricSet_1_11::~IMetricSet_1_11()
    {
    }
    TMetricSetParams_1_11* IMetricSet_1_11::GetParams( void )
    {
        return nullptr;
    }
    IMetric_1_0::~IMetric_1_0()
    {
    }
    TMetricParams_1_0* IMetric_1_0 ::GetParams()
    {
        return nullptr;
    }

    IInformation_1_0::~IInformation_1_0()
    {
    }
    TInformationParams_1_0* IInformation_1_0::GetParams()
    {
        return nullptr;
    }

    // Internal API
    IInternalConcurrentGroup::~IInternalConcurrentGroup()
    {
    }
    IMetricSetLatest* IInternalConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly )
    {
        return nullptr;
    }
    IInternalMetricSet::~IInternalMetricSet()
    {
    }
    IMetricLatest* IInternalMetricSet::AddCustomMetric( TAddCustomMetricParams* params )
    {
        return nullptr;
    }
    IAdapterGroup_1_6::~IAdapterGroup_1_6()
    {
    }
    TCompletionCode IAdapterGroup_1_6::Close( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    const TAdapterGroupParams_1_6* IAdapterGroup_1_6::GetParams( void ) const
    {
        return nullptr;
    }
    IAdapter_1_6* IAdapterGroup_1_6::GetAdapter( uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_8* IAdapterGroup_1_8::GetAdapter( uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_9* IAdapterGroup_1_9::GetAdapter( uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_10* IAdapterGroup_1_10::GetAdapter( uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_11* IAdapterGroup_1_11::GetAdapter( uint32_t index )
    {
        return nullptr;
    }

    IAdapter_1_6::~IAdapter_1_6()
    {
    }
    const TAdapterParams_1_6* IAdapter_1_6::GetParams( void ) const
    {
        return nullptr;
    }
    TCompletionCode IAdapter_1_6::Reset( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_5* metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    const TAdapterParams_1_8* IAdapter_1_8::GetParams( void ) const
    {
        return nullptr;
    }
    TCompletionCode IAdapter_1_9::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_9::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    const TAdapterParams_1_9* IAdapter_1_9::GetParams( void ) const
    {
        return nullptr;
    }
    const TSubDeviceParams_1_9* IAdapter_1_9::GetSubDeviceParams( const uint32_t subDeviceIndex )
    {
        return nullptr;
    }
    const TEngineParams_1_9* IAdapter_1_9::GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex )
    {
        return nullptr;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsDevice( IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsDevice( IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_11* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
} // namespace MetricsDiscovery
