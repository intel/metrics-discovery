/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2024 Intel Corporation

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
    TEquationElement_1_0* IEquation_1_0::GetEquationElement( [[maybe_unused]] uint32_t index )
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
    IConcurrentGroup_1_0* IMetricsDevice_1_0::GetConcurrentGroup( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TGlobalSymbol_1_0* IMetricsDevice_1_0::GetGlobalSymbol( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TTypedValue_1_0* IMetricsDevice_1_0::GetGlobalSymbolValueByName( [[maybe_unused]] const char* name )
    {
        return nullptr;
    }
    TCompletionCode IMetricsDevice_1_0::GetLastError( void )
    {
        return CC_LAST_1_0;
    }
    TCompletionCode IMetricsDevice_1_0::GetGpuCpuTimestamps( [[maybe_unused]] uint64_t* gpuTimestampNs, [[maybe_unused]] uint64_t* cpuTimestampNs, [[maybe_unused]] uint32_t* cpuId )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IConcurrentGroup_1_1* IMetricsDevice_1_1::GetConcurrentGroup( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TMetricsDeviceParams_1_2* IMetricsDevice_1_2::GetParams( void )
    {
        return nullptr;
    }
    IOverride_1_2* IMetricsDevice_1_2::GetOverride( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IOverride_1_2* IMetricsDevice_1_2::GetOverrideByName( [[maybe_unused]] const char* name )
    {
        return nullptr;
    }
    IConcurrentGroup_1_5* IMetricsDevice_1_5::GetConcurrentGroup( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricsDevice_1_10::GetGpuCpuTimestamps( [[maybe_unused]] uint64_t* gpuTimestampNs, [[maybe_unused]] uint64_t* cpuTimestampNs, [[maybe_unused]] uint32_t* cpuId, [[maybe_unused]] uint64_t* correlationIndicatorNs )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IConcurrentGroup_1_11* IMetricsDevice_1_11::GetConcurrentGroup( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IConcurrentGroup_1_13* IMetricsDevice_1_13::GetConcurrentGroup( [[maybe_unused]] uint32_t index )
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
    TCompletionCode IOverride_1_2::SetOverride( [[maybe_unused]] TSetOverrideParams_1_2* params, [[maybe_unused]] uint32_t paramsSize )
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
    IMetricSet_1_0* IConcurrentGroup_1_0::GetMetricSet( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IConcurrentGroup_1_0::OpenIoStream( [[maybe_unused]] IMetricSet_1_0* metricSet, [[maybe_unused]] uint32_t processId, [[maybe_unused]] uint32_t* nsTimerPeriod, [[maybe_unused]] uint32_t* oaBufferSize )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::ReadIoStream( [[maybe_unused]] uint32_t* reportsCount, [[maybe_unused]] char* reportData, [[maybe_unused]] uint32_t readFlags )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::CloseIoStream( void )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IConcurrentGroup_1_0::WaitForReports( [[maybe_unused]] uint32_t milliseconds )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IInformation_1_0* IConcurrentGroup_1_0::GetIoMeasurementInformation( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IInformation_1_0* IConcurrentGroup_1_0::GetIoGpuContextInformation( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_1* IConcurrentGroup_1_1::GetMetricSet( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }

    TCompletionCode IConcurrentGroup_1_3::SetIoStreamSamplingType( [[maybe_unused]] TSamplingType type )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    IMetricSet_1_5* IConcurrentGroup_1_5::GetMetricSet( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_11* IConcurrentGroup_1_11::GetMetricSet( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TConcurrentGroupParams_1_13* IConcurrentGroup_1_13::GetParams( void )
    {
        return nullptr;
    }
    IMetricEnumerator_1_13* IConcurrentGroup_1_13::GetMetricEnumerator( void )
    {
        return nullptr;
    }
    IMetricEnumerator_1_13* IConcurrentGroup_1_13::GetMetricEnumeratorFromFile( [[maybe_unused]] const char* fileName )
    {
        return nullptr;
    }
    IMetricSet_1_13* IConcurrentGroup_1_13::AddMetricSet( [[maybe_unused]] const char* symbolName, [[maybe_unused]] const char* shortName )
    {
        return nullptr;
    }
    TCompletionCode IConcurrentGroup_1_13::RemoveMetricSet( [[maybe_unused]] IMetricSet_1_13* metricSet )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    IMetricSet_1_13* IConcurrentGroup_1_13::GetMetricSet( [[maybe_unused]] uint32_t index )
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
    IMetric_1_0* IMetricSet_1_0::GetMetric( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IInformation_1_0* IMetricSet_1_0::GetInformation( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IMetricSet_1_0* IMetricSet_1_0::GetComplementaryMetricSet( [[maybe_unused]] uint32_t index )
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
    IMetric_1_0* IMetricSet_1_0::AddCustomMetric( [[maybe_unused]] const char* symbolName, [[maybe_unused]] const char* shortName, [[maybe_unused]] const char* groupName, [[maybe_unused]] const char* longName, [[maybe_unused]] const char* dxToOglAlias, [[maybe_unused]] uint32_t usageFlagsMask, [[maybe_unused]] uint32_t apiMask, [[maybe_unused]] TMetricResultType resultType, [[maybe_unused]] const char* resultUnits, [[maybe_unused]] TMetricType metricType, [[maybe_unused]] int64_t loWatermark, [[maybe_unused]] int64_t hiWatermark, [[maybe_unused]] THwUnitType hwType, [[maybe_unused]] const char* ioReadEquation, [[maybe_unused]] const char* deltaFunction, [[maybe_unused]] const char* queryReadEquation, [[maybe_unused]] const char* normalizationEquation, [[maybe_unused]] const char* maxValueEquation, [[maybe_unused]] const char* signalName )
    {
        return nullptr;
    }

    IMetricSet_1_1::~IMetricSet_1_1()
    {
    }
    TCompletionCode IMetricSet_1_1::SetApiFiltering( [[maybe_unused]] uint32_t apiMask )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_1::CalculateMetrics( [[maybe_unused]] const uint8_t* rawData, [[maybe_unused]] uint32_t rawDataSize, [[maybe_unused]] TTypedValue_1_0* out, [[maybe_unused]] uint32_t outSize, [[maybe_unused]] uint32_t* outReportCount, [[maybe_unused]] bool enableContextFiltering )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_1::CalculateIoMeasurementInformation( [[maybe_unused]] TTypedValue_1_0* out, [[maybe_unused]] uint32_t outSize )
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
    IMetricSet_1_5* IMetricSet_1_5::GetComplementaryMetricSet( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricSet_1_5::CalculateMetrics( [[maybe_unused]] const uint8_t* rawData, [[maybe_unused]] uint32_t rawDataSize, [[maybe_unused]] TTypedValue_1_0* out, [[maybe_unused]] uint32_t outSize, [[maybe_unused]] uint32_t* outReportCount, [[maybe_unused]] TTypedValue_1_0* outMaxValues, [[maybe_unused]] uint32_t outMaxValuesSize )
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
    IMetricSet_1_13::~IMetricSet_1_13()
    {
    }
    IMetric_1_13* IMetricSet_1_13::GetMetric( uint32_t )
    {
        return nullptr;
    }
    IMetric_1_13* IMetricSet_1_13::AddCustomMetric( [[maybe_unused]] const char* symbolName, [[maybe_unused]] const char* shortName, [[maybe_unused]] const char* groupName, [[maybe_unused]] const char* longName, [[maybe_unused]] const char* dxToOglAlias, [[maybe_unused]] uint32_t usageFlagsMask, [[maybe_unused]] uint32_t apiMask, [[maybe_unused]] TMetricResultType resultType, [[maybe_unused]] const char* resultUnits, [[maybe_unused]] TMetricType metricType, [[maybe_unused]] int64_t loWatermark, [[maybe_unused]] int64_t hiWatermark, [[maybe_unused]] THwUnitType hwType, [[maybe_unused]] const char* ioReadEquation, [[maybe_unused]] const char* deltaFunction, [[maybe_unused]] const char* queryReadEquation, [[maybe_unused]] const char* normalizationEquation, [[maybe_unused]] const char* maxValueEquation, [[maybe_unused]] const char* signalName, [[maybe_unused]] uint32_t queryModeMask )
    {
        return nullptr;
    }
    TCompletionCode IMetricSet_1_13::Open()
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_13::AddMetric( [[maybe_unused]] IMetricPrototype_1_13* metricPrototype )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_13::RemoveMetric( [[maybe_unused]] IMetricPrototype_1_13* metricPrototype )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricSet_1_13::Finalize()
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    IMetric_1_0::~IMetric_1_0()
    {
    }
    TMetricParams_1_0* IMetric_1_0 ::GetParams()
    {
        return nullptr;
    }
    IMetric_1_13::~IMetric_1_13()
    {
    }

    TMetricParams_1_13* IMetric_1_13::GetParams()
    {
        return nullptr;
    }

    IMetricPrototype_1_13::~IMetricPrototype_1_13()
    {
    }
    const TMetricPrototypeParams_1_13* IMetricPrototype_1_13::GetParams( void ) const
    {
        return nullptr;
    }
    IMetricPrototype_1_13* IMetricPrototype_1_13::Clone( void )
    {
        return nullptr;
    }
    const TMetricPrototypeOptionDescriptor_1_13* IMetricPrototype_1_13::GetOptionDescriptor( [[maybe_unused]] uint32_t index ) const
    {
        return nullptr;
    }
    TCompletionCode IMetricPrototype_1_13::SetOption( [[maybe_unused]] const TOptionDescriptorType optionType, [[maybe_unused]] const TTypedValue_1_0* typedValue )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricPrototype_1_13::ChangeNames( [[maybe_unused]] const char* symbolName, [[maybe_unused]] const char* shortName, [[maybe_unused]] const char* longName, [[maybe_unused]] const char* resultUnits )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    IMetricEnumerator_1_13 ::~IMetricEnumerator_1_13()
    {
    }
    uint32_t IMetricEnumerator_1_13::GetMetricPrototypeCount( void )
    {
        return 0;
    }
    IMetricPrototype_1_13* IMetricEnumerator_1_13::GetMetricPrototype( [[maybe_unused]] const uint32_t index )
    {
        return nullptr;
    }
    TCompletionCode IMetricEnumerator_1_13::GetMetricPrototypes( [[maybe_unused]] const uint32_t index, [[maybe_unused]] uint32_t* count, [[maybe_unused]] IMetricPrototype_1_13** metrics )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IMetricEnumerator_1_13::RemoveClonedMetricPrototype( [[maybe_unused]] IMetricPrototype_1_13* clonedPrototype )
    {
        return CC_ERROR_NOT_SUPPORTED;
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
    IMetricSetLatest* IInternalConcurrentGroup::AddCustomMetricSet( [[maybe_unused]] TAddCustomMetricSetParams* params, [[maybe_unused]] IMetricSetLatest* referenceMetricSet, [[maybe_unused]] bool copyInformationOnly )
    {
        return nullptr;
    }
    IInternalMetricSet::~IInternalMetricSet()
    {
    }
    IMetricLatest* IInternalMetricSet::AddCustomMetric( [[maybe_unused]] TAddCustomMetricParams* params )
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
    IAdapter_1_6* IAdapterGroup_1_6::GetAdapter( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_8* IAdapterGroup_1_8::GetAdapter( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_9* IAdapterGroup_1_9::GetAdapter( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_10* IAdapterGroup_1_10::GetAdapter( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_11* IAdapterGroup_1_11::GetAdapter( [[maybe_unused]] uint32_t index )
    {
        return nullptr;
    }
    IAdapter_1_13* IAdapterGroup_1_13::GetAdapter( [[maybe_unused]] uint32_t index )
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
    TCompletionCode IAdapter_1_6::OpenMetricsDevice( [[maybe_unused]] IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::OpenMetricsDeviceFromFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::CloseMetricsDevice( [[maybe_unused]] IMetricsDevice_1_5* metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_6::SaveMetricsDeviceToFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* saveParams, [[maybe_unused]] IMetricsDevice_1_5* metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    const TAdapterParams_1_8* IAdapter_1_8::GetParams( void ) const
    {
        return nullptr;
    }
    TCompletionCode IAdapter_1_9::OpenMetricsSubDevice( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_9::OpenMetricsSubDeviceFromFile( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_5** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    const TAdapterParams_1_9* IAdapter_1_9::GetParams( void ) const
    {
        return nullptr;
    }
    const TSubDeviceParams_1_9* IAdapter_1_9::GetSubDeviceParams( [[maybe_unused]] const uint32_t subDeviceIndex )
    {
        return nullptr;
    }
    const TEngineParams_1_9* IAdapter_1_9::GetEngineParams( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const uint32_t engineIndex )
    {
        return nullptr;
    }
    const TEngineParams_1_13* IAdapter_1_13::GetEngineParams( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const uint32_t engineIndex )
    {
        return nullptr;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsDevice( [[maybe_unused]] IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsDeviceFromFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsSubDevice( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_10::OpenMetricsSubDeviceFromFile( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_10** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsDevice( [[maybe_unused]] IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsDeviceFromFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsSubDevice( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::OpenMetricsSubDeviceFromFile( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_11** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_11::SaveMetricsDeviceToFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* saveParams, [[maybe_unused]] IMetricsDevice_1_11* metricsDevice, [[maybe_unused]] const uint32_t minMajorApiVersion, [[maybe_unused]] const uint32_t minMinorApiVersion )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_13::OpenMetricsDevice( [[maybe_unused]] IMetricsDevice_1_13** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_13::OpenMetricsDeviceFromFile( [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_13** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_13::OpenMetricsSubDevice( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] IMetricsDevice_1_13** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    TCompletionCode IAdapter_1_13::OpenMetricsSubDeviceFromFile( [[maybe_unused]] const uint32_t subDeviceIndex, [[maybe_unused]] const char* fileName, [[maybe_unused]] void* openParams, [[maybe_unused]] IMetricsDevice_1_13** metricsDevice )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
} // namespace MetricsDiscovery
