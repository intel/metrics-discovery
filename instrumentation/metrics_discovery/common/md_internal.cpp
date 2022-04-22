/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_internal.cpp

//     Abstract:   C++ Metrics Discovery internal implementation

#include "md_internal.h"
#include "md_metrics.h"
#include "md_utils.h"

#include <string>
#include <string.h>
#include <stdlib.h>
#include <new>
#include <unordered_map>
#include <algorithm>

using namespace MetricsDiscovery;

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

namespace MetricsDiscoveryInternal
{
    static const TMetricGroupNameIdPair GroupNamePairs[] = {
        { "GPU", METRIC_GROUP_NAME_ID_GPU, METRIC_GROUP_LEVEL_0 },
        { "GTI", METRIC_GROUP_NAME_ID_GTI, METRIC_GROUP_LEVEL_0 },
        { "LLC", METRIC_GROUP_NAME_ID_LLC, METRIC_GROUP_LEVEL_0 },
        { "EDRAM", METRIC_GROUP_NAME_ID_EDRAM, METRIC_GROUP_LEVEL_0 },
        { "DRAM", METRIC_GROUP_NAME_ID_DRAM, METRIC_GROUP_LEVEL_0 },
        { "EU Array", METRIC_GROUP_NAME_ID_EU_ARRAY, METRIC_GROUP_LEVEL_0 },
        { "Sampler", METRIC_GROUP_NAME_ID_SAMPLER, METRIC_GROUP_LEVEL_0 },
        { "Uncore", METRIC_GROUP_NAME_UNCORE, METRIC_GROUP_LEVEL_0 },
        { "Memory Controller", METRIC_GROUP_NAME_UNCORE_MC, METRIC_GROUP_LEVEL_0 },
        { "3D Pipe", METRIC_GROUP_NAME_ID_3D_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VE Pipe", METRIC_GROUP_NAME_ID_VE_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VD Pipe", METRIC_GROUP_NAME_ID_VD_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "WD Pipe", METRIC_GROUP_NAME_ID_WD_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VME Pipe", METRIC_GROUP_NAME_ID_VME_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "L3", METRIC_GROUP_NAME_ID_L3, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "Thread Dispatcher", METRIC_GROUP_NAME_ID_TD, METRIC_GROUP_LEVEL_1 },
        { "Rasterizer", METRIC_GROUP_NAME_ID_WM, METRIC_GROUP_LEVEL_1 },
        { "Data Port", METRIC_GROUP_NAME_ID_DATA_PORT, METRIC_GROUP_LEVEL_1 },
        { "IME Pipe", METRIC_GROUP_NAME_ID_IME_PIPE, METRIC_GROUP_LEVEL_1 },
        { "CRE Pipe", METRIC_GROUP_NAME_ID_CRE_PIPE, METRIC_GROUP_LEVEL_1 },
        { "Instruction Cache", METRIC_GROUP_NAME_ID_IC, METRIC_GROUP_LEVEL_1 },
        { "IC", METRIC_GROUP_NAME_ID_IC, METRIC_GROUP_LEVEL_1 },
        { "Sampler", METRIC_GROUP_NAME_ID_SAMPLER, METRIC_GROUP_LEVEL_1 },
        { "Pipes", METRIC_GROUP_NAME_ID_EU_PIPES, METRIC_GROUP_LEVEL_1 },
        { "Color Cache", METRIC_GROUP_NAME_ID_RCC, METRIC_GROUP_LEVEL_1 },
        { "Sampler Input", METRIC_GROUP_NAME_ID_SAMPLER_IN, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Cache", METRIC_GROUP_NAME_ID_SAMPLER_CACHE, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Filter", METRIC_GROUP_NAME_ID_SAMPLER_FL, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Output", METRIC_GROUP_NAME_ID_SAMPLER_OUT, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "TAG", METRIC_GROUP_NAME_ID_L3_TAG, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Instructions", METRIC_GROUP_NAME_ID_EU_INSTR, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Barrier", METRIC_GROUP_NAME_ID_EU_BARRIER, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Input Assembler", METRIC_GROUP_NAME_ID_IA, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Vertex Shader", METRIC_GROUP_NAME_ID_VS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Hull Shader", METRIC_GROUP_NAME_ID_HS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Control Shader", METRIC_GROUP_NAME_ID_HS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Tesselator", METRIC_GROUP_NAME_ID_TE, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Domain Shader", METRIC_GROUP_NAME_ID_DS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Evaluation Shader", METRIC_GROUP_NAME_ID_DS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Geometry Shader", METRIC_GROUP_NAME_ID_GS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Stream Output", METRIC_GROUP_NAME_ID_SO, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Clipper", METRIC_GROUP_NAME_ID_CL, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Pixel Shader", METRIC_GROUP_NAME_ID_PS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Fragment Shader", METRIC_GROUP_NAME_ID_PS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Output Merger", METRIC_GROUP_NAME_ID_OM, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Compute Shader", METRIC_GROUP_NAME_ID_CS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "SLM", METRIC_GROUP_NAME_ID_SLM, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "URB", METRIC_GROUP_NAME_ID_URB, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Depth Cache", METRIC_GROUP_NAME_ID_RCZ, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Stencil Cache", METRIC_GROUP_NAME_ID_STC, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Atomics", METRIC_GROUP_NAME_ID_ATOMICS, METRIC_GROUP_LEVEL_2 },
        { "Strip-Fans", METRIC_GROUP_NAME_ID_SF, METRIC_GROUP_LEVEL_2 },
        { "Early Depth Test", METRIC_GROUP_NAME_ID_IZ, METRIC_GROUP_LEVEL_2 },
        { "Hi-Depth Test", METRIC_GROUP_NAME_ID_HZ, METRIC_GROUP_LEVEL_2 },
        { "Barycentric Calc", METRIC_GROUP_NAME_ID_BC, METRIC_GROUP_LEVEL_2 },
        { "Command Streamer", METRIC_GROUP_NAME_ID_RCS, METRIC_GROUP_LEVEL_2 },
        { "Resource Streamer", METRIC_GROUP_NAME_ID_RS, METRIC_GROUP_LEVEL_2 },
        { "Vertex Fetch", METRIC_GROUP_NAME_ID_VF, METRIC_GROUP_LEVEL_2 }
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     WriteEquationToFile
    //
    // Description:
    //     Writes CEquation class to file. If it's equal to null 0xFF will be written.
    //
    // Input:
    //     CEquation* equation    - CEquation to be written
    //     FILE*      metricFile  - handle to metric file
    //
    // Output:
    //     TCompletionCode        - result
    //
    //////////////////////////////////////////////////////////////////////////////
    static TCompletionCode WriteEquationToFile( CEquation* equation, FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        TCompletionCode ret = CC_OK;

        if( equation )
        {
            ret = equation->WriteCEquationToFile( metricFile );
        }
        else
        {
            fputc( 0xFF, metricFile );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     SetDeltaFunction
    //
    // Description:
    //     Sets the delta function from parsed string.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //     TDeltaFunction_1_0*        - (out) delta function
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    static TCompletionCode SetDeltaFunction( const char* equationString, TDeltaFunction_1_0* deltaFunction )
    {
        if( equationString == nullptr || strcmp( equationString, "" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_FUNCTION_NULL;
            return CC_OK;
        }
        if( strncmp( equationString, "DELTA", sizeof( "DELTA" ) - 1 ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_N_BITS;
            if( equationString[5] == ' ' )
            {
                deltaFunction->BitsCount = strtoul( (char*) &equationString[6], nullptr, 10 );
            }
            else
            {
                deltaFunction->BitsCount = strtoul( (char*) &equationString[5], nullptr, 10 );
            }
            return CC_OK;
        }
        if( strcmp( equationString, "OR" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_BOOL_OR;
            return CC_OK;
        }
        if( strcmp( equationString, "XOR" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_BOOL_XOR;
            return CC_OK;
        }
        if( strcmp( equationString, "PREV" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_GET_PREVIOUS;
            return CC_OK;
        }
        if( strcmp( equationString, "LAST" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_GET_LAST;
            return CC_OK;
        }
        if( strcmp( equationString, "NS_TIME" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_NS_TIME;
            return CC_OK;
        }

        MD_LOG( LOG_ERROR, "Unknown delta function: %s", equationString );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     SetEquation
    //
    // Description:
    //     Sets the given equation.
    //
    // Input:
    //     CMetricsDevice* device         - metric device
    //     CEquation**     equation       - pointer to the equation to be set
    //     const char*     equationString - euqation string, could be empty or null
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    static TCompletionCode SetEquation( CMetricsDevice* device, CEquation** equation, const char* equationString )
    {
        MD_CHECK_PTR_RET( device, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( equation, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode ret = CC_OK;

        // Delete previous equation if any
        MD_SAFE_DELETE( *equation );

        // nullptr is fine condition for "" equations
        if( equationString != nullptr && strcmp( equationString, "" ) != 0 )
        {
            *equation = new( std::nothrow ) CEquation( device );
            if( *equation == nullptr || !( *equation )->ParseEquationString( equationString ) )
            {
                MD_SAFE_DELETE( *equation );
                ret = CC_ERROR_GENERAL;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Global variable:
    //     m_openCloseSemaphore
    //
    // Description:
    //     Semaphore used for controlling parallel Open/CloseAdapterGroup calls.
    //
    //////////////////////////////////////////////////////////////////////////////
    void* CAdapterGroup::m_openCloseSemaphore = nullptr;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Global variable:
    //     m_agRefCounter
    //
    // Description:
    //     Adapter group reference counter.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CAdapterGroup::m_agRefCounter = 0;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Global variable:
    //     m_adapterGroup
    //
    // Description:
    //     Adapter group global instance.
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterGroup* CAdapterGroup::m_adapterGroup = nullptr;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     CAdapterGroup
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterGroup::CAdapterGroup()
        : m_params{}
        , m_defaultAdapter( nullptr )
        , m_adapterVector()
    {
        m_params.Version.MajorNumber = MD_API_MAJOR_NUMBER_CURRENT;
        m_params.Version.MinorNumber = MD_API_MINOR_NUMBER_CURRENT;
        m_params.Version.BuildNumber = MD_API_BUILD_NUMBER_CURRENT;

        m_adapterVector.reserve( ADAPTER_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     ~CAdapterGroup
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterGroup::~CAdapterGroup()
    {
        ClearVector( m_adapterVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns adapter group params.
    //
    // Output:
    //     const TAdapterGroupParams_1_6* - adapter group params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TAdapterGroupParams_1_6* CAdapterGroup::GetParams() const
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     GetAdapter
    //
    // Description:
    //    Returns chosen adapter or null if index doesn't exist.
    //
    // Input:
    //     uint32_t index - index of a chosen adapter
    //
    // Output:
    //     IAdapterLatest* - chosen adapter or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IAdapterLatest* CAdapterGroup::GetAdapter( uint32_t index )
    {
        if( index < m_adapterVector.size() )
        {
            return m_adapterVector[index];
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     Close
    //
    // Description:
    //     Decreases adapter group reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    // Output:
    //     TCompletionCode - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::Close()
    {
        MD_LOG_ENTER();
        MD_ASSERT( this == m_adapterGroup );

        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        if( retVal == CC_OK )
        {
            if( m_agRefCounter > 1 )
            {
                m_agRefCounter--;
                retVal = CC_STILL_INITIALIZED;
            }
            else if( m_agRefCounter == 1 )
            {
                // Important: 'this' (current object) is deleted here
                MD_SAFE_DELETE( m_adapterGroup );
                m_agRefCounter = 0;
                retVal         = CC_OK;
            }
            else
            {
                retVal = CC_ERROR_GENERAL;
            }
        }

        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens main MDAPI root object - adapter group or retrieves an instance
    //     opened before. Only one instance of adapter group may be created, all
    //     Open() calls are reference counted.
    //
    // Input:
    //     CAdapterGroup** adapterGroup - [out] created / retrieved adapter group
    //
    // Output:
    //     TCompletionCode              - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::Open( CAdapterGroup** adapterGroup )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( adapterGroup, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        if( m_adapterGroup )
        {
            *adapterGroup = m_adapterGroup;
            retVal        = CC_ALREADY_INITIALIZED;
            m_agRefCounter++;
        }
        else
        {
            // Read global debug log settings
            CDriverInterface::ReadDebugLogSettings();

            retVal = CreateAdapterGroup( adapterGroup );
            if( retVal == CC_OK )
            {
                m_agRefCounter++;
            }
        }

        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     IsOpened
    //
    // Description:
    //     Checks whether adapter group was opened (created) before.
    //
    // Output:
    //     bool - true if adapter group instance exists (was created before)
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CAdapterGroup::IsOpened()
    {
        return m_adapterGroup != nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     Get
    //
    // Description:
    //     Returns static adapter group instance.
    //
    // Output:
    //     CAdapterGroup* - adapter group instance, may be null if it doesn't exists
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterGroup* CAdapterGroup::Get()
    {
        return m_adapterGroup;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     GetOpenCloseSemaphore
    //
    // Description:
    //     Acquires semaphore used during adapter group open / close operations.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::GetOpenCloseSemaphore()
    {
        return GetNamedSemaphore( "AdOpenClose", &m_openCloseSemaphore );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     ReleaseOpenCloseSemaphore
    //
    // Description:
    //     Releases semaphore used during adapter group open / close operations.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::ReleaseOpenCloseSemaphore()
    {
        return ReleaseNamedSemaphore( &m_openCloseSemaphore );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     CreateAdapterGroup
    //
    // Description:
    //     Creates adapter group along with the whole adapter tree, including
    //     adapter enumeration.
    //
    // Input:
    //     CAdapterGroup** adapterGroup - [optional] created adapter group
    //
    // Output:
    //     TCompletionCode              - CC_OK if success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::CreateAdapterGroup( CAdapterGroup** adapterGroup )
    {
        MD_ASSERT( m_adapterGroup == nullptr );

        m_adapterGroup = new( std::nothrow ) CAdapterGroup();
        MD_CHECK_PTR_RET( m_adapterGroup, CC_ERROR_NO_MEMORY );

        TCompletionCode ret = m_adapterGroup->CreateAdapterTree();
        if( ret != CC_OK )
        {
            MD_SAFE_DELETE( m_adapterGroup );
            return ret;
        }

        if( adapterGroup )
        {
            *adapterGroup = m_adapterGroup;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     GetDefaultAdapter
    //
    // Description:
    //     Returns default adapter chosen during initialization.
    //
    // Output:
    //     CAdapter* - default adapter, may be null if no adapters are available
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter* CAdapterGroup::GetDefaultAdapter()
    {
        MD_LOG( LOG_DEBUG, "Returned default adapter: %p", m_defaultAdapter );
        return m_defaultAdapter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     CreateAdapterTree
    //
    // Description:
    //     Creates the whole adapter tree. Includes available adapter discovery,
    //     creating adapter objects and filling their data.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::CreateAdapterTree()
    {
        MD_LOG_ENTER();

        std::vector<TAdapterData> availableAdapters;

        // 1. Get adapter information from OS
        auto ret = CDriverInterface::GetAvailableAdapters( availableAdapters );
        MD_CHECK_CC_RET( ret );

        // 2. Create adapter objects
        for( const auto& adapterData : availableAdapters )
        {
            ret = AddAdapter( adapterData );
            if( ret != CC_OK )
            {
                MD_LOG( LOG_ERROR, "Error: failed to add adapter %s", adapterData.Params.ShortName );
                CleanupAdapters();
                break;
            }
        }
        MD_ASSERT( m_params.AdapterCount == m_adapterVector.size() );

        // 3. Choose default adapter
        if( ret == CC_OK )
        {
            m_defaultAdapter = ChooseDefaultAdapter();
            MD_LOG( LOG_INFO, "Default adapter: %s", m_defaultAdapter ? m_defaultAdapter->GetParams()->ShortName : "None" );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     AddAdapter
    //
    // Description:
    //     Creates a single adapter and adds it to the adapter vector. Updates
    //     adapter count in params respectively.
    //     Adapter object becomes owner of the adapter handle (CAdapterHandle object) and
    //     params memory (strings).
    //
    // Input:
    //     const TAdapterData& adapterData - input adapter information
    //
    // Output:
    //     TCompletionCode                 - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterGroup::AddAdapter( const TAdapterData& adapterData )
    {
        MD_CHECK_PTR_RET( adapterData.Handle, CC_ERROR_INVALID_PARAMETER );

        auto adapter = new( std::nothrow ) CAdapter( *this, adapterData.Params, *adapterData.Handle );
        MD_CHECK_PTR_RET( adapter, CC_ERROR_NO_MEMORY );

        m_adapterVector.push_back( adapter );
        m_params.AdapterCount = m_adapterVector.size();

        const TAdapterParams_1_6* adapterParams = adapter->GetParams();

        MD_LOG( LOG_INFO, "Adapter %s - added", adapterParams->ShortName );
        MD_LOG( LOG_INFO, "Platform ID: %u", adapterParams->Platform );
        MD_LOG( LOG_INFO, "Device ID: %u", adapterParams->DeviceId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     CleanupAdapters
    //
    // Description:
    //     Cleans all stored adapter. Their handles are closed in their destructors.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CAdapterGroup::CleanupAdapters()
    {
        m_defaultAdapter      = nullptr;
        m_params.AdapterCount = 0;

        ClearVector( m_adapterVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterGroup
    //
    // Method:
    //     ChooseDefaultAdapter
    //
    // Description:
    //     Chooses default adapter for usage with legacy OpenMetricsDevice API.
    //     Currently default is first external GPU.
    //
    // Output:
    //     CAdapter* - default adapter or nullptr if adapter count if 0
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter* CAdapterGroup::ChooseDefaultAdapter()
    {
        if( !m_adapterVector.size() )
        {
            return nullptr;
        }

        // 1. Initialize to first adapter
        CAdapter* defaultAdapter = m_adapterVector.front();

        // 2. Change to discrete GPU if exists
        for( auto& adapter : m_adapterVector )
        {
            if( adapter && adapter->GetParams()->Type == ADAPTER_TYPE_DISCRETE )
            {
                defaultAdapter = adapter;
                break;
            }
        }

        return defaultAdapter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CAdapter constructor
    //
    // Description:
    //     Constructor.
    //     Adapter object becomes owner of the adapter handle (CAdapterHandle object) and
    //     params memory (strings).
    //
    // Input:
    //     CAdapterGroup&            adapterGroup  - parent adapter group object
    //     const TAdapterParams_1_9& params        - filled adapter params
    //     CAdapterHandle&           adapterHandle - adapter handle connected with this adapter
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter::CAdapter( CAdapterGroup& adapterGroup, const TAdapterParams_1_9& params, CAdapterHandle& adapterHandle )
        : m_params( params )
        , m_adapterHandle( &adapterHandle )
        , m_adapterGroup( adapterGroup )
        , m_openCloseSemaphore( nullptr )
        , m_driverInterface( nullptr )
        , m_metricsDevice( nullptr )
        , m_subDevices( *this )
        , m_subDeviceParams{}
        , m_engineParams{}
    {
        // Initialize sub device information.
        m_subDevices.Enumerate();
        m_subDevices.GetAdapterParams( m_params );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     ~CAdapter
    //
    // Description:
    //     Deallocates memory and closes underlying adapter handle.
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter::~CAdapter()
    {
        MD_SAFE_DELETE_ARRAY( m_params.ShortName );

        MD_SAFE_DELETE( m_metricsDevice );
        MD_SAFE_DELETE( m_driverInterface );

        if( m_adapterHandle )
        {
            m_adapterHandle->Close();
            MD_SAFE_DELETE( m_adapterHandle );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns adapter params.
    //
    // Output:
    //     const TAdapterParams_1_9* - adapter params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TAdapterParams_1_9* CAdapter::GetParams() const
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetSubDeviceParams
    //
    // Description:
    //     Returns sub device params.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //
    // Output:
    //     const TSubDeviceParams_1_9*   - sub device params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TSubDeviceParams_1_9* CAdapter::GetSubDeviceParams( const uint32_t subDeviceIndex )
    {
        return ( m_subDevices.GetSubDeviceParams( subDeviceIndex, m_subDeviceParams ) == CC_OK )
            ? &m_subDeviceParams
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetEngineParams
    //
    // Description:
    //     Returns engine params.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //     const uint32_t engineIndex    - engine index
    //
    // Output:
    //     const TEngineParams_1_9*      - adapter params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TEngineParams_1_9* CAdapter::GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex )
    {
        return ( m_subDevices.GetEngineParams( subDeviceIndex, engineIndex, m_engineParams ) == CC_OK )
            ? &m_engineParams
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetSubDevices
    //
    // Description:
    //     Returns a reference to sub devices implementation.
    //
    // Output:
    //     CSubDevices& -reference to sub device implementation.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDevices& CAdapter::GetSubDevices()
    {
        return m_subDevices;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     Reset
    //
    // Description:
    //     Tries to disable performance monitoring support. Useful when previous
    //     application crashed and left it in the unspecified / initialized state.
    //
    //     Allowed only if no metrics device objects are open.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::Reset()
    {
        MD_LOG_ENTER();

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        // 2. Allow resetting only if no metrics device objects are created
        if( !m_metricsDevice )
        {
            if( CDriverInterface::IsSupportEnableRequired() )
            {
                // 3. Create driver interface
                retVal = CreateDriverInterface();
                if( retVal == CC_OK )
                {
                    MD_ASSERT( m_driverInterface != nullptr );

                    // 4. Force disable performance monitoring support
                    retVal = m_driverInterface->ForceSupportDisable();
                    if( retVal != CC_OK )
                    {
                        MD_LOG( LOG_ERROR, "Resetting adapter state failed" );
                    }

                    DestroyDriverInterface();
                }
                else
                {
                    MD_LOG( LOG_ERROR, "Failed to get driver interface" );
                }
            }
        }
        else
        {
            retVal = CC_ERROR_GENERAL;
        }

        // 5. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceByIndex
    //
    // Description:
    //     Opens metrics device and sets sub device index or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //     const uint32_t        subDeviceIndex  - index of sub device to create
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceByIndex( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        // 2. Create or return existing metrics device object
        if( m_metricsDevice )
        {
            *metricsDevice = m_metricsDevice;
            retVal         = CC_ALREADY_INITIALIZED;
            ++m_metricsDevice->GetReferenceCounter();
        }
        else
        {
            retVal = CreateMetricsDevice( metricsDevice, subDeviceIndex );
            if( retVal == CC_OK )
            {
                ++m_metricsDevice->GetReferenceCounter();
            }
        }

        // 5. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_5** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_10** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    // Input:
    //     IMetricsDevice_1_11** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDevice( IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsDeviceByIndex( (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFileByIndex
    //
    // Description:
    //     Opens metrics device and sets sub device index or uses an instance opened before (just like OpenMetricsDeviceByIndex),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName        - custom metric file
    //     void*                 openParams      - open params
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //     const uint32_t        subDeviceIndex  - index of sub device to create
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFileByIndex( const char* fileName, void* openParams, CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        // 2. Create 'standard' metrics device object if needed
        if( !m_metricsDevice )
        {
            retVal = CreateMetricsDevice( nullptr, subDeviceIndex );
        }
        MD_ASSERT( m_driverInterface != nullptr );

        // 3. Load from file or return existing metrics device object
        if( retVal == CC_OK )
        {
            if( m_metricsDevice->IsOpenedFromFile() )
            {
                *metricsDevice = m_metricsDevice;
                retVal         = CC_ALREADY_INITIALIZED;
                ++m_metricsDevice->GetReferenceCounter();
            }
            else
            {
                retVal = m_metricsDevice->OpenFromFile( fileName, MD_IS_INTERNAL_BUILD );
                if( retVal == CC_OK )
                {
                    *metricsDevice = m_metricsDevice;
                    ++m_metricsDevice->GetReferenceCounter();
                }
                else if( !m_metricsDevice->GetReferenceCounter() )
                {
                    // If this was a first call to OpenMetricsDevice
                    DestroyMetricsDevice();
                }
            }
        }

        // 4. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_5**  metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_10** metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const char*           fileName       - custom metric file
    //     void*                 openParams     - open params
    //     IMetricsDevice_1_11** metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsDeviceFromFileByIndex( fileName, openParams, (CMetricsDevice**) metricsDevice, MD_ROOT_DEVICE_INDEX );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t     subDeviceIndex - sub device index to create
    //     CMetricsDevice**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                   - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, CMetricsDevice** metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        const bool      isFirstDevice        = subDeviceIndex == 0;
        const bool      isValidIndex         = isFirstDevice || ( subDeviceIndex < m_params.SubDevicesCount );
        const bool      isSubDeviceSupported = m_subDevices.IsSupported();
        TCompletionCode result               = CC_OK;

        // Check sub device support (first device is always supported).
        if( !isFirstDevice && !isSubDeviceSupported )
        {
            MD_LOG( LOG_ERROR, "Sub devices are not supported" );
            MD_LOG_EXIT();
            return TCompletionCode::CC_ERROR_NOT_SUPPORTED;
        }

        // Check sub device index.
        if( !isValidIndex )
        {
            MD_LOG( LOG_ERROR, "Invalid sub device index" );
            MD_LOG_EXIT();
            return TCompletionCode::CC_ERROR_INVALID_PARAMETER;
        }

        // Check if device is already created.
        m_metricsDevice = m_subDevices.GetDevice( subDeviceIndex );

        // Create new one if needed or increment reference counter.
        if( m_metricsDevice == nullptr )
        {
            m_metricsDevice = m_subDevices.OpenDevice( subDeviceIndex );
            result          = m_metricsDevice ? CC_OK : CC_ERROR_GENERAL;
        }
        else
        {
            ++m_metricsDevice->GetReferenceCounter();
            result = CC_ALREADY_INITIALIZED;
        }

        MD_LOG_EXIT()
        *metricsDevice = m_metricsDevice;
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t         subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_5**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t          subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_10**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                        - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDevice
    //
    // Description:
    //     Opens metrics sub device or retrieves an instance opened before.
    //
    // Input:
    //     const uint32_t          subDeviceIndex - sub device index to create
    //     IMetricsDevice_1_11**   metricsDevice  - [out] created / retrieved metrics sub device
    //
    // Output:
    //     TCompletionCode                        - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsSubDevice( subDeviceIndex, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t        subDeviceIndex  - sub device index to create
    //     const char*           fileName        - custom metric file
    //     void*                 openParams      - open params
    //     CMetricsDevice**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, CMetricsDevice** metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        const bool      isFirstDevice        = subDeviceIndex == 0;
        const bool      isValidIndex         = isFirstDevice || ( subDeviceIndex < m_params.SubDevicesCount );
        const bool      isSubDeviceSupported = m_subDevices.IsSupported();
        TCompletionCode result               = CC_OK;

        // Check sub device support (first device is always supported).
        if( !isFirstDevice && !isSubDeviceSupported )
        {
            MD_LOG( LOG_ERROR, "Sub devices are not supported" );
            MD_LOG_EXIT();
            return TCompletionCode::CC_ERROR_NOT_SUPPORTED;
        }

        // Check sub device index.
        if( !isValidIndex )
        {
            MD_LOG( LOG_ERROR, "Invalid sub device index" );
            MD_LOG_EXIT();
            return TCompletionCode::CC_ERROR_INVALID_PARAMETER;
        }

        // Check if device is already created.
        m_metricsDevice = m_subDevices.GetDevice( subDeviceIndex );

        // Create new one if needed or increment reference counter.
        if( m_metricsDevice == nullptr )
        {
            m_metricsDevice = m_subDevices.OpenDeviceFromFile( subDeviceIndex, fileName, openParams );
            result          = m_metricsDevice ? CC_OK : CC_ERROR_GENERAL;
        }
        else
        {
            ++m_metricsDevice->GetReferenceCounter();
            result = CC_ALREADY_INITIALIZED;
        }

        MD_LOG_EXIT()
        *metricsDevice = m_metricsDevice;
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t            subDeviceIndex  - sub device index to create
    //     const char*               fileName        - custom metric file
    //     void*                     openParams      - open params
    //     IMetricsDevice_1_5**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                           - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t             subDeviceIndex  - sub device index to create
    //     const char*                fileName        - custom metric file
    //     void*                      openParams      - open params
    //     IMetricsDevice_1_10**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                            - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     OpenMetricsSubDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    // Input:
    //     const uint32_t             subDeviceIndex  - sub device index to create
    //     const char*                fileName        - custom metric file
    //     void*                      openParams      - open params
    //     IMetricsDevice_1_11**      metricsDevice   - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                            - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice )
    {
        return OpenMetricsSubDeviceFromFile( subDeviceIndex, fileName, openParams, (CMetricsDevice**) metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CloseMetricsDevice
    //
    // Description:
    //     Decreases metrics device reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    // Input:
    //     CMetricsDevice*     metricsDevice - metrics device to close
    //
    // Output:
    //     TCompletionCode                   - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CloseMetricsDevice( CMetricsDevice* metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        // 2. Check driver interface - it should be created during OpenMetricsDevice
        if( !m_driverInterface )
        {
            MD_LOG( LOG_ERROR, "Driver interface not found" );
            retVal = CC_ERROR_GENERAL;
        }

        // 3. Check whether correct metrics device was passed
        if( retVal == CC_OK )
        {
            const bool validDevice    = metricsDevice == m_metricsDevice;
            const bool validSubDevice = m_subDevices.FindDevice( metricsDevice );

            if( !validDevice && !validSubDevice )
            {
                MD_LOG( LOG_ERROR, "Pointers mismatch" );
                retVal = CC_ERROR_GENERAL;
            }
        }

        // 4. Destroy or decrease reference counter for existing metrics device object
        if( retVal == CC_OK )
        {
            // Set as default device to remove.
            m_metricsDevice = metricsDevice;

            if( m_metricsDevice->GetReferenceCounter() > 1 )
            {
                --m_metricsDevice->GetReferenceCounter();
                retVal = CC_STILL_INITIALIZED;
            }
            else if( m_metricsDevice->GetReferenceCounter() == 1 )
            {
                m_metricsDevice->GetReferenceCounter() = 0;
                DestroyMetricsDevice();
                retVal = CC_OK;
            }
            else
            {
                retVal = CC_ERROR_GENERAL;
            }
        }

        // 5. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CloseMetricsDevice
    //
    // Description:
    //     Decreases metrics device reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    // Input:
    //     IMetricsDevice_1_5*     metricsDevice - metrics device to close
    //
    // Output:
    //     TCompletionCode                       - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice )
    {
        return CloseMetricsDevice( static_cast<CMetricsDevice*>( metricsDevice ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*          fileName           - target file name
    //     void*                saveParams         - save params
    //     CMetricsDevice*      metricsDevice      - target metrics device
    //     const uint32_t       minMajorApiVersion - required MDAPI major version to open the file
    //     const uint32_t       minMinorApiVersion - required MDAPI minor version to open the file
    //
    // Output:
    //     TCompletionCode                         - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, CMetricsDevice* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. Obtain semaphore
        TCompletionCode retVal = GetOpenCloseSemaphore();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Get semaphore failed" );
            MD_LOG_EXIT();
            return retVal;
        }

        // 2. Check whether correct metrics device was passed
        if( metricsDevice != m_metricsDevice )
        {
            MD_LOG( LOG_ERROR, "Pointers mismatch" );
            retVal = CC_ERROR_GENERAL;
        }

        // 3. Save metrics device object to a file
        retVal = m_metricsDevice->SaveToFile( fileName, minMajorApiVersion, minMinorApiVersion );
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Saving to file failed" );
        }

        // 4. Release semaphore
        ReleaseOpenCloseSemaphore();

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*          fileName      - target file name
    //     void*                saveParams    - save params
    //     IMetricsDevice_1_5*  metricsDevice - target metrics device
    //
    // Output:
    //     TCompletionCode                    - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_5* metricsDevice )
    {
        return SaveMetricsDeviceToFile( fileName, saveParams, static_cast<CMetricsDevice*>( metricsDevice ), 0, 0 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    // Input:
    //     const char*           fileName           - target file name
    //     void*                 saveParams         - save params
    //     IMetricsDevice_1_11*  metricsDevice      - target metrics device
    //     const uint32_t        minMajorApiVersion - required MDAPI major version to open the file
    //     const uint32_t        minMinorApiVersion - required MDAPI minor version to open the file
    //
    // Output:
    //     TCompletionCode                          - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_11* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion )
    {
        return SaveMetricsDeviceToFile( fileName, saveParams, static_cast<CMetricsDevice*>( metricsDevice ), minMajorApiVersion, minMinorApiVersion );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetDriverInterface
    //
    // Description:
    //     Returns driver interface.
    //
    // Output:
    //     CDriverInterface - pointer to driver interface
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterface* CAdapter::GetDriverInterface()
    {
        if( m_driverInterface == nullptr )
        {
            CreateDriverInterface();
        }

        return m_driverInterface;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CreateDriverInterface
    //
    // Description:
    //     Creates an instance of driver interface. Only one driver interface per adapter
    //     should be created.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CreateDriverInterface()
    {
        MD_CHECK_PTR_RET( m_adapterHandle, CC_ERROR_GENERAL );

        if( !m_driverInterface )
        {
            m_driverInterface = CDriverInterface::CreateInstance( *m_adapterHandle );
        }

        return m_driverInterface ? CC_OK
                                 : CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     DestroyDriverInterface
    //
    // Description:
    //     Destroys driver interface.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CAdapter::DestroyDriverInterface()
    {
        if( m_subDevices.GetDeviceCount() == 0 )
        {
            MD_SAFE_DELETE( m_driverInterface );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     GetOpenCloseSemaphore
    //
    // Description:
    //     Acquires semaphore used during Open/CloseMetricsDevice() calls. Use to control
    //     parallel access to these functions.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::GetOpenCloseSemaphore()
    {
        const char     openClosePrefix[] = "MdOpenClose";
        const uint32_t spaceFor3Uints    = 33; // 3 * "max uint string" + 3 * "_"

        // Create a semaphore name: "OpenClose_<BusNumber>_<DeviceNumber>_<FunctionNumber>"
        char semaphoreName[sizeof( openClosePrefix ) + spaceFor3Uints];
        snprintf( semaphoreName, sizeof( semaphoreName ), "%s_%u_%u_%u", openClosePrefix, m_params.BusNumber, m_params.DeviceNumber, m_params.FunctionNumber );

        return GetNamedSemaphore( semaphoreName, &m_openCloseSemaphore );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     ReleaseOpenCloseSemaphore
    //
    // Description:
    //     Releases semaphore used during Open/CloseMetricsDevice() calls. Use to control
    //     parallel access to these functions.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::ReleaseOpenCloseSemaphore()
    {
        return ReleaseNamedSemaphore( &m_openCloseSemaphore );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     CreateMetricsDevice
    //
    // Description:
    //     Creates metrics device along with the whole metric tree and driver interface.
    //     May enable instrumentation support if needed.
    //
    // Input:
    //     CMetricsDevice**      metricsDevice  - [out][optional] created metrics device
    //     const uint32_t        subDeviceIndex - index of sub device to create
    //
    // Output:
    //     TCompletionCode                      - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::CreateMetricsDevice( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex /* = 0 */ )
    {
        MD_ASSERT( m_metricsDevice == nullptr );

        // 1. Create driver interface
        TCompletionCode retVal = CreateDriverInterface();
        if( retVal != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Failed to get driver interface" );
            return retVal;
        }
        MD_ASSERT( m_driverInterface != nullptr );

        // 2. Enable instrumentation support if needed
        retVal = EnableDriverSupport( true );
        if( retVal != CC_OK )
        {
            DestroyDriverInterface();
            return retVal;
        }

        // 3. Create metrics device object
        m_metricsDevice = new( std::nothrow ) CMetricsDevice( *this, *m_driverInterface, subDeviceIndex );
        if( !m_metricsDevice )
        {
            EnableDriverSupport( false );
            DestroyDriverInterface();
            return CC_ERROR_NO_MEMORY;
        }

        // 4. Populate metric tree
        retVal = CreateMetricTree( m_metricsDevice );
        if( retVal != CC_OK )
        {
            MD_SAFE_DELETE( m_metricsDevice );
            EnableDriverSupport( false );
            DestroyDriverInterface();
            return retVal;
        }

        if( metricsDevice )
        {
            *metricsDevice = m_metricsDevice;
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     DestroyMetricsDevice
    //
    // Description:
    //     Destroys metrics device for this adapter.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CAdapter::DestroyMetricsDevice()
    {
        // 1. Remove device from sub devices.
        m_subDevices.RemoveDevice( m_metricsDevice );

        // 2. Delete metrics device object
        MD_SAFE_DELETE( m_metricsDevice );

        // 3. Disable instrumentation support if needed
        EnableDriverSupport( false );

        // 4. Destroy driver interface
        DestroyDriverInterface();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Method:
    //     EnableDriverSupport
    //
    // Description:
    //     Enables driver support if driver requires that.
    //
    // Input:
    //     bool enable     - true to enable
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapter::EnableDriverSupport( bool enable )
    {
        MD_CHECK_PTR_RET( m_driverInterface, CC_ERROR_NOT_SUPPORTED );

        TCompletionCode retVal      = CC_OK;
        auto            enablePrint = []( bool enable ) { return enable ? "enabling" : "disabling"; };

        if( m_driverInterface->IsSupportEnableRequired() )
        {
            MD_LOG( LOG_INFO, "Driver support %s...", enablePrint( enable ) );
            retVal = m_driverInterface->SendSupportEnableEscape( enable );
            if( retVal != CC_OK )
            {
                MD_LOG( LOG_ERROR, "Driver support %s failed", enablePrint( enable ) );
            }
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Method:
    //     COverrideCommon
    //
    // Description:
    //     Common override class constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    COverrideCommon::COverrideCommon( void )
    {
        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverrideCommon
    //
    // Method:
    //     GetParamsInternal
    //
    // Description:
    //     Returns internal parameters for a given override.
    //
    // Output:
    //     const TOverrideInternalParams* - internal override parameters.
    //
    //////////////////////////////////////////////////////////////////////////////
    const TOverrideInternalParams* COverrideCommon::GetParamsInternal( void )
    {
        return &m_internalParams;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Frequency override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FREQUENCY>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "FrequencyOverride";
        m_params.Description      = "Overrides device GPU frequency with a static value.";
        m_params.ApiMask          = (uint32_t) API_TYPE_ALL;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_NULL_HARDWARE>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Null Hardware override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_NULL_HARDWARE>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "Null Hardware";
        m_params.Description      = "Do not send primitives to the hardware rasterizer.";
        m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NULL_HARDWARE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Flush GPU caches override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "Flush GPU caches";
        m_params.Description      = "Flushes all GPU caches.";
        m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_FLUSH_GPU_CACHES;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_EXTENDED_QUERY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Extended query override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "Extended query";
        m_params.Description      = "Enables extended query mode.";
        m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Multisampled query override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "Multisampled query";
        m_params.Description      = "Enables multisampled query mode.";
        m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>
    //
    // Method:
    //     COverride
    //
    // Description:
    //     Frequency change reports override constructor.
    //
    // Input:
    //     CMetricsDevice* device - parent metrics devcice
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::COverride( CMetricsDevice* device )
    {
        m_device = device;

        m_params.SymbolName       = "FrequencyChangeReports";
        m_params.Description      = "Allows to toggle frequency change reports.";
        m_params.ApiMask          = (uint32_t) API_TYPE_IOSTREAM;
        m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
        m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

        m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     ~COverride
    //
    // Description:
    //     Generic COverride destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    COverride<overrideType>::~COverride()
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns override params.
    //
    // Output:
    //     TOverrideParams_1_2* - override params
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    TOverrideParams_1_2* COverride<overrideType>::GetParams( void )
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enabled or disables frequency override. Requires override specific
    //     params to be passed in place of *params*: TSetFrequencyOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetFrequencyOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET( paramsSize, TSetFrequencyOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode                  ret                     = CC_OK;
        CDriverInterface&                driverInterface         = m_device->GetDriverInterface();
        TSetFrequencyOverrideParams_1_2* frequencyOverrideParams = static_cast<TSetFrequencyOverrideParams_1_2*>( params );

        ret = driverInterface.SetFrequencyOverride( frequencyOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Setting frequency override failed, res: %u", ret );
        }
        else
        {
            // Update Frequency global symbol
            CSymbolSet* symbolSet = m_device->GetSymbolSet();
            symbolSet->RedetectSymbol( "GpuCurrentFrequencyMHz" );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_EXTENDED_QUERY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables or disables extended query mode. Requires override specific
    //     params to be passed in place of *params*: TSetQueryOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET( paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        TTypedValue_1_0* oaBufferSize = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
        if( oaBufferSize == nullptr )
        {
            MD_LOG( LOG_ERROR, "Unable to obtain maximum OA buffer size" );
            return CC_ERROR_GENERAL;
        }

        TSetQueryOverrideParams_1_2* queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>( params );
        TCompletionCode              ret                 = driverInterface.SetQueryOverride( OVERRIDE_TYPE_EXTENDED_QUERY, m_device->GetPlatformType(), oaBufferSize->ValueUInt32, queryOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Setting extended query override failed, res: %u", ret );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables or disables multisampled query mode. Requires override specific
    //     params to be passed in place of *params*: TSetQueryOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET( paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        TTypedValue_1_0* oaBufferSize = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
        if( oaBufferSize == nullptr )
        {
            MD_LOG( LOG_ERROR, "Unable to obtain maximum OA buffer size" );
            return CC_ERROR_GENERAL;
        }

        TSetQueryOverrideParams_1_2* queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>( params );
        TCompletionCode              ret                 = driverInterface.SetQueryOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY, m_device->GetPlatformType(), oaBufferSize->ValueUInt32, queryOverrideParams );
        if( ret != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Setting multisampled query override failed, res: %u", ret );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enabled or disables frequency change reports override. Requires override
    //     specific params to be passed in place of *params*: TSetOverrideParams_1_2.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params, should be TSetOverrideParams_1_2*
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_SIZE_RET( paramsSize, TSetOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        TCompletionCode ret = driverInterface.SetFreqChangeReportsOverride( params->Enable );
        if( ret != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Setting frequency change reports override failed, res: %u", ret );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COverride
    //
    // Method:
    //     SetOverride
    //
    // Description:
    //     Enables override.
    //
    // Input:
    //     TSetOverrideParams_1_2* params     - params
    //     uint32_t                paramsSize - size of the passed params
    //
    // Output:
    //     TCompletionCode                    - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TOverrideType overrideType>
    TCompletionCode COverride<overrideType>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
    {
        MD_LOG( LOG_ERROR, "Override %u not supported in global mode", overrideType );
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     CMetricsDevice constructor
    //
    // Description:
    //     Constructor. Sends DeviceInfoParam escape.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice::CMetricsDevice( CAdapter& adapter, CDriverInterface& driverInterface, const uint32_t subDeviceIndex /* = 0 */ )
        : m_params{}
        , m_referenceCounter( 0 )
        , m_groupsVector()
        , m_overridesVector()
        , m_subDeviceIndex( subDeviceIndex )
        , m_symbolSet( *this, driverInterface )
        , m_platform( PLATFORM_UNKNOWN )
        , m_gtType( GT_TYPE_UNKNOWN )
        , m_isOpenedFromFile( false )
        , m_adapter( adapter )
        , m_driverInterface( driverInterface )
        , m_streamId( -1 )
        , m_streamConfigId( -1 )
    {
        m_params.DeltaFunctionsCount       = DELTA_FUNCTION_LAST_1_0;
        m_params.EquationOperationsCount   = EQUATION_OPER_LAST_1_0;
        m_params.EquationElementTypesCount = EQUATION_ELEM_LAST_1_0;

        m_params.Version.MajorNumber = MD_API_MAJOR_NUMBER_CURRENT;
        m_params.Version.MinorNumber = MD_API_MINOR_NUMBER_CURRENT;
        m_params.Version.BuildNumber = MD_API_BUILD_NUMBER_CURRENT;

        m_params.GlobalSymbolsCount    = m_symbolSet.GetSymbolCount();
        m_params.ConcurrentGroupsCount = 0;
        m_params.OverrideCount         = 0;

        m_params.DeviceName = GetCopiedCString( m_adapter.GetParams()->ShortName );

        m_groupsVector.reserve( GROUPS_VECTOR_INCREASE );
        m_overridesVector.reserve( OVERRIDES_VECTOR_INCREASE );

        GTDIDeviceInfoParamExtOut out = {};
        if( m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &out ) == CC_OK )
        {
            m_platform = (TPlatformType) ( 1 << out.ValueUint32 );
            MD_LOG( LOG_INFO, "PLATFORM_INDEX is %u", m_platform );
        }
        if( m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GT_TYPE, &out ) == CC_OK )
        {
            m_gtType = (TGTType) ( 1 << out.ValueUint32 );
            MD_LOG( LOG_INFO, "GT_TYPE is %u", m_gtType );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     CMetricsDevice destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice::~CMetricsDevice()
    {
        MD_SAFE_DELETE_ARRAY( m_params.DeviceName );
        ClearVector( m_groupsVector );
        ClearVector( m_overridesVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns metrics device params.
    //
    // Output:
    //     TMetricsDeviceParams_1_0*  - pointer to metrics device params
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricsDeviceParams_1_2* CMetricsDevice::GetParams( void )
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetConcurrentGroup
    //
    // Description:
    //     Returns chosen concurrent group or null if not exists.
    //
    // Input:
    //     uint32_t index          - index of concurrent group
    //
    // Output:
    //     IConcurrentGroupLatest* - pointer to concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    IConcurrentGroupLatest* CMetricsDevice::GetConcurrentGroup( uint32_t index )
    {
        if( index < m_groupsVector.size() )
        {
            return m_groupsVector[index];
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetGlobalSymbol
    //
    // Description:
    //     Returns chosen global symbol or null if not exists.
    //
    // Input:
    //     uint32_t index      - index of global symbol
    //
    // Output:
    //     TGlobalSymbol_1_0*  - pointer to global symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbol_1_0* CMetricsDevice::GetGlobalSymbol( uint32_t index )
    {
        return m_symbolSet.GetSymbol( index );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetGlobalSymbolValueByName
    //
    // Description:
    //     Returns chosen global symbol by name or null if not exists.
    //
    // Input:
    //     const char * name   - name of global symbol
    //
    // Output:
    //     TTypedValue_1_0*    - pointer to global symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0* CMetricsDevice::GetGlobalSymbolValueByName( const char* name )
    {
        return m_symbolSet.GetSymbolValueByName( name );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetLastError
    //
    // Description:
    //     Returns last error from enum TCompletionCode.
    //
    // Output:
    //     TCompletionCode - last error from enum
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetLastError()
    {
        return CC_LAST_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetCpuGpuTimestamps
    //
    // Description:
    //     Retrieves both GPU and CPU timestamp at the same time.
    //
    // Input:
    //     uint64_t* gpuTimestampNs         - (out) GPU timestamp in ns
    //     uint64_t* cpuTimestampNs         - (out) CPU timestamp in ns
    //     uint32_t* cpuId                  - (out) CPU id
    //     uint64_t* correlationIndicatorNs - (out) correlation indicator in ns
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId, uint64_t* correlationIndicatorNs )
    {
        if( !gpuTimestampNs && !cpuTimestampNs )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        uint64_t        gpuTS = 0, cpuTS = 0, correlationIndicator = 0;
        uint32_t        cpuID = 0;
        TCompletionCode ret   = m_driverInterface.GetGpuCpuTimestamps( *this, &gpuTS, &cpuTS, &cpuID, &correlationIndicator );

        if( ret == CC_OK )
        {
            if( gpuTimestampNs )
            {
                *gpuTimestampNs = gpuTS;
            }
            if( cpuTimestampNs )
            {
                *cpuTimestampNs = cpuTS;
            }
            if( cpuId )
            {
                *cpuId = cpuID;
            }
            if( correlationIndicatorNs )
            {
                *correlationIndicatorNs = correlationIndicator;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetCpuGpuTimestamps
    //
    // Description:
    //     Retrieves both GPU and CPU timestamp at the same time.
    //
    // Input:
    //     uint64_t* gpuTimestampNs - (out) GPU timestamp in ns
    //     uint64_t* cpuTimestampNs - (out) CPU timestamp in ns
    //     uint32_t* cpuId          - (out) CPU id
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId )
    {
        return GetGpuCpuTimestamps( gpuTimestampNs, cpuTimestampNs, cpuId, nullptr );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetOverride
    //
    // Description:
    //     Returns the chosen override object or null if index doesn't exist.
    //
    // Input:
    //     uint32_t index - index of an override
    //
    // Output:
    //     IOverride_1_2* - chosen override object or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::GetOverride( uint32_t index )
    {
        if( index < m_overridesVector.size() )
        {
            return m_overridesVector[index];
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetOverrideByName
    //
    // Description:
    //     Returns the chosen override object or nullptr if index doesn't exist.
    //
    // Input:
    //     const char* symbolName - name of an override
    //
    // Output:
    //     IOverride_1_2* - chosen override object or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::GetOverrideByName( const char* symbolName )
    {
        MD_CHECK_PTR_RET( symbolName, nullptr );

        for( auto& override : m_overridesVector )
        {
            if( override && ( strcmp( symbolName, override->GetParams()->SymbolName ) == 0 ) )
            {
                return override;
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddConcurrentGroup
    //
    // Description:
    //     Adds concurrent group to the metrics device.
    //
    // Input:
    //     const char *symbolicName - concurrent group name
    //     const char *shortName    - concurrent group short name
    //
    // Output:
    //     CConcurrentGroup*        - pointer to newly created concurrent group
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup* CMetricsDevice::AddConcurrentGroup( const char* symbolicName, const char* shortName, uint32_t measurementTypeMask )
    {
        CConcurrentGroup* group = nullptr;
        if( strstr( symbolicName, "OA" ) != nullptr )
        {
            group = new( std::nothrow ) COAConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
        }
        else if( strstr( symbolicName, "PerfMon" ) != nullptr )
        {
            group = new( std::nothrow ) CPerfMonConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
        }
        else
        {
            group = new( std::nothrow ) CConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
        }

        m_groupsVector.push_back( group );
        m_params.ConcurrentGroupsCount = m_groupsVector.size();

        return group;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddOverride
    //
    // Description:
    //     Adds the given override to MetricsDevice if available on current driver interface and
    //     platform.
    //     All the params are set in specialized constructors.
    //
    // Output:
    //     IOverride_1_2* - added override or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IOverride_1_2* CMetricsDevice::AddOverride( TOverrideType overrideType )
    {
        // 1. CHECK AVAILABILITY ON CURRENT DRIVER INTERFACE
        if( !m_driverInterface.IsOverrideAvailable( overrideType ) )
        {
            MD_LOG( LOG_INFO, "Override %u not available on the current driver interface", overrideType );
            return nullptr;
        }

        // 2. CREATE OVERRIDE OBJECT
        IOverride_1_2* override = nullptr;
        switch( overrideType )
        {
            case OVERRIDE_TYPE_FREQUENCY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FREQUENCY>( this );
                break;
            case OVERRIDE_TYPE_NULL_HARDWARE:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_NULL_HARDWARE>( this );
                break;
            case OVERRIDE_TYPE_MULTISAMPLED_QUERY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>( this );
                break;
            case OVERRIDE_TYPE_EXTENDED_QUERY:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_EXTENDED_QUERY>( this );
                break;
            case OVERRIDE_TYPE_FLUSH_GPU_CACHES:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>( this );
                break;
#if defined( _RELEASE_INTERNAL )
            case OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS:
                override = new( std::nothrow ) COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>( this );
                break;
#endif
            default:
                break;
        }

        // 3. CHECK AVAILABILITY ON CURRENT PLATFORM
        MD_CHECK_PTR_RET( override, nullptr );
        if( IsPlatformTypeOf( override->GetParams()->PlatformMask ) )
        {
            // Add override and update count
            m_overridesVector.push_back( override );
            m_params.OverrideCount = m_overridesVector.size();
            MD_LOG( LOG_INFO, "%s - added", override->GetParams()->SymbolName );
        }
        else
        {
            // Override isn't available on the current platform
            MD_LOG( LOG_INFO, "%s - not available", override->GetParams()->SymbolName );
            MD_SAFE_DELETE( override );
        }

        return override;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     AddOverrides
    //
    // Description:
    //     Fills override vector in MetricsDevice with previously defined overrides.
    //     All the params are set in specialized constructors.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::AddOverrides()
    {
        TCompletionCode ret = CC_OK;

        AddOverride( OVERRIDE_TYPE_FREQUENCY );
        AddOverride( OVERRIDE_TYPE_NULL_HARDWARE );
        AddOverride( OVERRIDE_TYPE_EXTENDED_QUERY );
        AddOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY );
        AddOverride( OVERRIDE_TYPE_FLUSH_GPU_CACHES );
#if defined( _RELEASE_INTERNAL )
        AddOverride( OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS );
#endif
        // ...

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsPlatformTypeOf
    //
    // Description:
    //     Checks if current platform is given type.
    //
    // Input:
    //     uint32_t hwMask - hardware mask in TPlatformType notation
    //     uint32_t gtMask - gt type mask in TGTType notation
    //
    // Output:
    //     bool                - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsPlatformTypeOf( uint32_t hwMask, uint32_t gtMask /*= GT_TYPE_ALL*/ )
    {
        bool platformMatch = ( hwMask & m_platform ) != 0;
        bool gtMatch       = ( gtMask & m_gtType ) != 0;

        return platformMatch && gtMatch;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsPavpDisabled
    //
    // Description:
    //     Checks if the PAVP_DISABLED bit in capabilities global symbol is set.
    //
    // Output:
    //     bool - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsPavpDisabled( uint32_t capabilities )
    {
        return ( capabilities & GTDI_CAPABILITY_PAVP_DISABLED ) > 0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsAvailabilityEquationTrue
    //
    // Description:
    //     Solves the given availability equation.
    //
    // Input:
    //     const char * availabilityEquation   - availability equation to solve
    //
    // Output:
    //     bool                                - result of solving availabilityEquation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsAvailabilityEquationTrue( const char* availabilityEquation )
    {
        if( availabilityEquation == nullptr || strcmp( availabilityEquation, "" ) == 0 )
        {
            return true;
        }

        CEquation equation( this );
        if( equation.ParseEquationString( availabilityEquation ) )
        {
            return equation.SolveBooleanEquation();
        }
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SaveToFile
    //
    // Description:
    //     Saves a custom part of MetricsDevice to file.
    //
    // Input:
    //     const char *    fileName        - file name
    //     const uint32_t  minMajorVersion - required major MDAPI version to save to file
    //     const uint32_t  minMinorVersion - required minor MDAPI version to save to file
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::SaveToFile( const char* fileName, const uint32_t minMajorApiVersion /* =0*/, const uint32_t minMinorApiVersion /* =0*/ )
    {
        TCompletionCode retVal     = CC_OK;
        FILE*           metricFile = nullptr;

        iu_fopen_s( &metricFile, fileName, "wb" );
        MD_CHECK_PTR_RET( metricFile, CC_ERROR_FILE_NOT_FOUND );

        // Specific key indicating plain text MDAPI file
        fwrite( MD_METRICS_FILE_KEY_2_0, sizeof( char ), sizeof( MD_METRICS_FILE_KEY_2_0 ), metricFile );

        // Minimal api vesrion
        fwrite( &minMajorApiVersion, sizeof( uint32_t ), 1, metricFile );
        fwrite( &minMinorApiVersion, sizeof( uint32_t ), 1, metricFile );

        // m_platform
        fwrite( &m_platform, sizeof( m_platform ), 1, metricFile );

        // m_params
        fwrite( &m_params.Version, sizeof( m_params.Version ), 1, metricFile );

        // m_symbolsVector
        m_symbolSet.WriteSymbolSetToFile( metricFile );

        // m_groupsVector
        uint32_t groupsCount = m_groupsVector.size();
        fwrite( &groupsCount, sizeof( groupsCount ), 1, metricFile );
        for( auto& group : m_groupsVector )
        {
            retVal = group->WriteCConcurrentGroupToFile( metricFile );
            if( retVal != CC_OK )
            {
                break;
            }
        }

        fclose( metricFile );

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadGlobalSymbolsFromFileBuffer
    //
    // Description:
    //     Reads global symbols from file buffer and advances the pointer.
    //
    // Input:
    //     uint8_t** fileBuffer - file buffer
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadGlobalSymbolsFromFileBuffer( uint8_t** bufferPtr )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

        TGlobalSymbol globalSymbol;

        uint32_t symbolsCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t i = 0; i < symbolsCount; i++ )
        {
            globalSymbol.symbol_1_0.SymbolName       = ReadCStringFromFileBuffer( bufferPtr );
            globalSymbol.symbol_1_0.SymbolTypedValue = ReadTTypedValueFromFileBuffer( bufferPtr );
            globalSymbol.symbolType                  = (TSymbolType) ReadUInt32FromFileBuffer( bufferPtr );
            if( m_symbolSet.IsSymbolAlreadyAdded( globalSymbol.symbol_1_0.SymbolName ) )
            {
                continue;
            }

            TCompletionCode ret = CC_OK;

            if( globalSymbol.symbolType == SYMBOL_TYPE_DETECT )
            {
                ret = m_symbolSet.DetectSymbolValue( globalSymbol.symbol_1_0.SymbolName, &globalSymbol.symbol_1_0.SymbolTypedValue );
            }

            if( ret == CC_OK )
            {
                m_symbolSet.AddSymbol(
                    globalSymbol.symbol_1_0.SymbolName,
                    globalSymbol.symbol_1_0.SymbolTypedValue,
                    globalSymbol.symbolType );
            }
        }

        m_params.GlobalSymbolsCount = m_symbolSet.GetSymbolCount();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadConcurrentGroupsFromFileBuffer
    //
    // Description:
    //     Reads concurrent groups from file buffer and advances the pointer.
    //
    // Input:
    //     uint8_t**        bufferPtr       - file buffer
    //     bool             isInternalBuild - true if current build is internal
    //     TApiVersion_1_0* apiVersion      - API version
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadConcurrentGroupsFromFileBuffer( uint8_t** bufferPtr, bool isInternalBuild, TApiVersion_1_0* apiVersion )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode   ret                 = CC_OK;
        CConcurrentGroup* aGroup              = nullptr;
        char*             symbolicName        = nullptr;
        char*             shortName           = nullptr;
        uint32_t          measurementTypeMask = 0;

        uint32_t groupsCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t i = 0; i < groupsCount; i++ )
        {
            // ConcurrentGroupParams
            symbolicName        = ReadCStringFromFileBuffer( bufferPtr );
            shortName           = ReadCStringFromFileBuffer( bufferPtr );
            measurementTypeMask = ReadUInt32FromFileBuffer( bufferPtr );

            aGroup = GetConcurrentGroupByName( symbolicName );
            if( !aGroup )
            {
                aGroup = AddConcurrentGroup( symbolicName, shortName, measurementTypeMask );
                MD_CHECK_PTR_RET( aGroup, CC_ERROR_NO_MEMORY );
            }

            // MetricSets
            ret = ReadMetricSetsFromFileBuffer( bufferPtr, aGroup, isInternalBuild, apiVersion );
            MD_CHECK_CC_RET( ret );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadMetricSetsFromFileBuffer
    //
    // Description:
    //     Reads metric sets from file buffer, adds them to the group and advances the pointer.
    //
    // Input:
    //     uint8_t**         bufferPtr       - file buffer
    //     CConcurrentGroup* group           - parent concurrent group
    //     bool              isInternalBuild - true if current build is internal
    //     TApiVersion_1_0*  apiVersion      - API version
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadMetricSetsFromFileBuffer( uint8_t** bufferPtr, CConcurrentGroup* group, bool isInternalBuild, TApiVersion_1_0* apiVersion )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( group, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode       ret                  = CC_OK;
        CMetricSet*           set                  = nullptr;
        CMetricSet*           existingSet          = nullptr;
        char*                 symbolicName         = nullptr;
        char*                 availabilityEquation = nullptr;
        uint32_t              count                = 0;
        TMetricSetParams_1_11 metricSetParams;
        TApiSpecificId_1_0    apiSpecificId;
        TReportType           reportType;

        // MetricSets
        uint32_t metricSetsCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t j = 0; j < metricSetsCount; j++ )
        {
            set         = nullptr;
            existingSet = nullptr;

            // MetricSetParams
            metricSetParams.SymbolName      = ReadCStringFromFileBuffer( bufferPtr );
            metricSetParams.ShortName       = ReadCStringFromFileBuffer( bufferPtr );
            metricSetParams.ApiMask         = ReadUInt32FromFileBuffer( bufferPtr );
            metricSetParams.CategoryMask    = (TMetricCategory) ReadUInt32FromFileBuffer( bufferPtr );
            metricSetParams.RawReportSize   = ReadUInt32FromFileBuffer( bufferPtr );
            metricSetParams.QueryReportSize = ReadUInt32FromFileBuffer( bufferPtr );
            metricSetParams.PlatformMask    = ReadUInt32FromFileBuffer( bufferPtr );
            if( ( apiVersion->MajorNumber == MD_API_MAJOR_NUMBER_1 && apiVersion->MinorNumber >= MD_API_MINOR_NUMBER_4 ) || ( apiVersion->MajorNumber > MD_API_MAJOR_NUMBER_1 ) )
            {
                metricSetParams.GtMask = ReadUInt32FromFileBuffer( bufferPtr );
            }
            else
            {
                metricSetParams.GtMask = (uint32_t) GT_TYPE_ALL;
            }

            if( ( apiVersion->MajorNumber == MD_API_MAJOR_NUMBER_1 && apiVersion->MinorNumber >= MD_API_MINOR_NUMBER_11 ) || ( apiVersion->MajorNumber > MD_API_MAJOR_NUMBER_1 ) )
            {
                availabilityEquation = ReadEquationStringFromFile( bufferPtr );
            }

            reportType = (TReportType) ReadUInt32FromFileBuffer( bufferPtr );

            // For release builds add sets from current platform only, for internal builds add all
            if( IsPlatformTypeOf( metricSetParams.PlatformMask, metricSetParams.GtMask ) || isInternalBuild )
            {
                // Add new MetricSet if there isn't a set with matching SymbolName, platform and gt masks
                existingSet = group->GetMatchingMetricSet( metricSetParams.SymbolName, metricSetParams.PlatformMask, metricSetParams.GtMask );
                if( !existingSet )
                {
                    set = group->AddMetricSet(
                        metricSetParams.SymbolName,
                        metricSetParams.ShortName,
                        metricSetParams.ApiMask,
                        metricSetParams.CategoryMask,
                        metricSetParams.RawReportSize,
                        metricSetParams.QueryReportSize,
                        reportType,
                        metricSetParams.PlatformMask,
                        availabilityEquation,
                        metricSetParams.GtMask,
                        true );
                    MD_CHECK_PTR_RET( set, CC_ERROR_NO_MEMORY );
                    MD_LOG( LOG_DEBUG, "adding set: %s", metricSetParams.ShortName );
                }
                else
                {
                    MD_LOG( LOG_DEBUG, "set not added, using existing one: %s", metricSetParams.ShortName );
                }
            }
            else
            {
                MD_LOG( LOG_DEBUG, "skipping set: %s", metricSetParams.ShortName );
            }

            // ApiSpecificId
            apiSpecificId.D3D9QueryId           = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.D3D9Fourcc            = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.D3D1XQueryId          = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.D3D1XDevDependentId   = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.D3D1XDevDependentName = ReadCStringFromFileBuffer( bufferPtr );
            apiSpecificId.OGLQueryIntelId       = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.OGLQueryIntelName     = ReadCStringFromFileBuffer( bufferPtr );
            apiSpecificId.OGLQueryARBTargetId   = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.OCL                   = ReadUInt32FromFileBuffer( bufferPtr );
            apiSpecificId.HwConfigId            = ReadUInt32FromFileBuffer( bufferPtr );
            if( set )
            {
                set->SetApiSpecificId( apiSpecificId );
            }

            // Metrics - if set's been existing, add only missing metrics
            ret = ReadMetricsFromFileBuffer( bufferPtr, existingSet ? existingSet : set, existingSet == nullptr );
            MD_CHECK_CC_RET( ret );

            // Information
            ret = ReadInformationFromFileBuffer( bufferPtr, set );
            MD_CHECK_CC_RET( ret );

            // Start and stop registers
            ret = ReadRegistersFromFileBuffer( bufferPtr, set );
            MD_CHECK_CC_RET( ret );

            // ComplementaryMetricSets
            count = ReadUInt32FromFileBuffer( bufferPtr );
            for( uint32_t k = 0; k < count; k++ )
            {
                symbolicName = ReadCStringFromFileBuffer( bufferPtr );
                if( set )
                {
                    set->AddComplementaryMetricSet( symbolicName );
                }
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ReadMetricsFromFileBuffer
    //
    // Description:
    //     Reads metrics from file buffer, adds them to the set and advances the pointer.
    //
    // Input:
    //     uint8_t**   fileBuffer - file buffer
    //     CMetricSet* set        - parent metric set
    //     bool        isSetNew   - if true, add all metrics, otherwise add only metrics that
    //                              don't exist in the set. It's to prevent adding duplicated
    //                              metrics when reading existing set (e.g. default RenderBasic)
    //                              with added custom metrics.
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadMetricsFromFileBuffer( uint8_t** bufferPtr, CMetricSet* set, bool isSetNew )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

        CMetric*           metric         = nullptr;
        char*              equationString = nullptr;
        char*              signalName     = nullptr;
        TMetricParams_1_0  metricParams;
        TDeltaFunction_1_0 deltaFunction;
        bool               skip = ( set == nullptr );

        // Metrics
        uint32_t metricsCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t i = 0; i < metricsCount; i++ )
        {
            metric = nullptr;

            // MetricParams
            metricParams.GroupId           = ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.SymbolName        = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.ShortName         = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.GroupName         = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.LongName          = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.DxToOglAlias      = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.UsageFlagsMask    = ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.ApiMask           = ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.ResultType        = (TMetricResultType) ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.MetricResultUnits = ReadCStringFromFileBuffer( bufferPtr );
            metricParams.MetricType        = (TMetricType) ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.HwUnitType        = (THwUnitType) ReadUInt32FromFileBuffer( bufferPtr );
            metricParams.LowWatermark      = ReadInt64FromFileBuffer( bufferPtr );
            metricParams.HighWatermark     = ReadInt64FromFileBuffer( bufferPtr );
            signalName                     = ReadCStringFromFileBuffer( bufferPtr );
            equationString                 = ReadEquationStringFromFile( bufferPtr );

            if( !skip )
            {
                // Add only unique metrics to an existing metric set
                if( isSetNew || !set->IsMetricAlreadyAdded( metricParams.SymbolName ) )
                {
                    metric = set->AddMetric(
                        metricParams.SymbolName,
                        metricParams.ShortName,
                        metricParams.LongName,
                        metricParams.GroupName,
                        metricParams.GroupId,
                        metricParams.UsageFlagsMask,
                        metricParams.ApiMask,
                        metricParams.MetricType,
                        metricParams.ResultType,
                        metricParams.MetricResultUnits,
                        metricParams.LowWatermark,
                        metricParams.HighWatermark,
                        metricParams.HwUnitType,
                        equationString,
                        metricParams.DxToOglAlias,
                        signalName,
                        i,
                        true );
                    MD_CHECK_PTR_RET( metric, CC_ERROR_NO_MEMORY );
                }
            }

            // Delta function
            deltaFunction.FunctionType = (TDeltaFunctionType) ReadUInt32FromFileBuffer( bufferPtr );
            deltaFunction.BitsCount    = ReadUInt32FromFileBuffer( bufferPtr );
            if( metric )
            {
                metric->SetSnapshotReportDeltaFunction( deltaFunction );
            }

            // Snapshot report read equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( metric )
            {
                metric->SetSnapshotReportReadEquation( equationString );
            }

            // Delta report read equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( metric )
            {
                metric->SetDeltaReportReadEquation( equationString );
            }

            // Normalization equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( metric )
            {
                metric->SetNormalizationEquation( equationString );
            }

            // Max value equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( metric )
            {
                metric->SetMaxValueEquation( equationString );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadInformationFromFileBuffer
    //
    // Description:
    //     Reads information from file buffer, adds them to the set and advances the pointer.
    //
    // Input:
    //     uint8_t**   fileBuffer - file buffer
    //     CMetricSet* set        - parent metric set
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadInformationFromFileBuffer( uint8_t** bufferPtr, CMetricSet* set )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

        CInformation*          aInformation   = nullptr;
        char*                  equationString = nullptr;
        TInformationParams_1_0 informationParams;
        TDeltaFunction_1_0     deltaFunction;
        bool                   skip = ( set == nullptr );

        // Information
        uint32_t informationCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t k = 0; k < informationCount; k++ )
        {
            aInformation = nullptr;

            // InformationParams
            informationParams.SymbolName = ReadCStringFromFileBuffer( bufferPtr );
            informationParams.ShortName  = ReadCStringFromFileBuffer( bufferPtr );
            informationParams.GroupName  = ReadCStringFromFileBuffer( bufferPtr );
            informationParams.LongName   = ReadCStringFromFileBuffer( bufferPtr );
            informationParams.ApiMask    = ReadUInt32FromFileBuffer( bufferPtr );
            informationParams.InfoType   = (TInformationType) ReadUInt32FromFileBuffer( bufferPtr );
            informationParams.InfoUnits  = ReadCStringFromFileBuffer( bufferPtr );
            equationString               = ReadEquationStringFromFile( bufferPtr );

            if( !skip )
            {
                aInformation = set->AddInformation(
                    informationParams.SymbolName,
                    informationParams.ShortName,
                    informationParams.LongName,
                    informationParams.GroupName,
                    informationParams.ApiMask,
                    informationParams.InfoType,
                    informationParams.InfoUnits,
                    equationString,
                    k );
                MD_CHECK_PTR_RET( aInformation, CC_ERROR_NO_MEMORY );
            }

            // Delta function
            deltaFunction.FunctionType = (TDeltaFunctionType) ReadUInt32FromFileBuffer( bufferPtr );
            deltaFunction.BitsCount    = ReadUInt32FromFileBuffer( bufferPtr );
            if( aInformation )
            {
                aInformation->SetOverflowFunction( deltaFunction );
            }

            // Snapshot report read equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( aInformation )
            {
                aInformation->SetSnapshotReportReadEquation( equationString );
            }

            // Delta report read equation
            equationString = ReadEquationStringFromFile( bufferPtr );
            if( aInformation )
            {
                aInformation->SetDeltaReportReadEquation( equationString );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     ReadRegistersFromFileBuffer
    //
    // Description:
    //     Reads start and stop registers from file buffer, adds them to the set and
    //     advances the pointer.
    //
    // Input:
    //     uint8_t**   fileBuffer - file buffer
    //     CMetricSet* set        - parent metric set
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::ReadRegistersFromFileBuffer( uint8_t** bufferPtr, CMetricSet* set )
    {
        MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

        TRegister          reg;
        char*              equationString = nullptr;
        TRegisterSetParams registerSetParams;
        uint32_t           regCount = 0;
        bool               skip     = ( set == nullptr );

        // Start register sets
        uint32_t regSetCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t i = 0; i < regSetCount; i++ )
        {
            // RegisterSetParams
            registerSetParams.ConfigId       = ReadUInt32FromFileBuffer( bufferPtr );
            registerSetParams.ConfigPriority = ReadUInt32FromFileBuffer( bufferPtr );
            registerSetParams.ConfigType     = (TConfigType) ReadUInt32FromFileBuffer( bufferPtr );
            equationString                   = ReadEquationStringFromFile( bufferPtr );

            if( !skip )
            {
                TCompletionCode ret = set->AddStartRegisterSet(
                    registerSetParams.ConfigId,
                    registerSetParams.ConfigPriority,
                    equationString,
                    registerSetParams.ConfigType );
                MD_CHECK_CC_RET( ret );
            }

            regCount = ReadUInt32FromFileBuffer( bufferPtr );
            for( uint32_t j = 0; j < regCount; j++ )
            {
                if( !skip )
                {
                    reg = *( (TRegister*) ( *bufferPtr ) );
                    set->AddStartConfigRegister( reg.offset, reg.value, reg.type );
                }
                *bufferPtr += sizeof( TRegister );
            }
        }

        // Stop register sets - !StopRegisters are obsolete, remains to be backward compatible (in new versions count is always 0)!
        regSetCount = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t i = 0; i < regSetCount; i++ )
        {
            // RegisterSetParams
            registerSetParams.ConfigId       = ReadUInt32FromFileBuffer( bufferPtr );
            registerSetParams.ConfigPriority = ReadUInt32FromFileBuffer( bufferPtr );
            registerSetParams.ConfigType     = (TConfigType) ReadUInt32FromFileBuffer( bufferPtr );
            equationString                   = ReadEquationStringFromFile( bufferPtr );

            regCount = ReadUInt32FromFileBuffer( bufferPtr );
            for( uint32_t j = 0; j < regCount; j++ )
            {
                *bufferPtr += sizeof( TRegister );
            }
        }

        if( !skip )
        {
            set->RefreshConfigRegisters();
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     OpenFromFile
    //
    // Description:
    //     Opens, checks for MDAPI plain text format and loads file with saved
    //     metrics device if the format is valid.
    //
    // Input:
    //     const char*    fileName        - file name
    //     bool           isInternalBuild - if true, then this is internal build
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsDevice::OpenFromFile( const char* fileName, bool isInternalBuild )
    {
        TCompletionCode retVal           = CC_OK;
        FILE*           metricFile       = nullptr;
        uint8_t*        metricFileBuffer = nullptr;
        uint8_t*        bufferPtr        = nullptr;
        uint32_t        fileSize         = 0;
        uint32_t        fileVersion      = CUSTOM_METRICS_FILE_VERSION_0;

        iu_fopen_s( &metricFile, fileName, "rb" );
        MD_CHECK_PTR_RET( metricFile, CC_ERROR_FILE_NOT_FOUND );
        fileSize = GetFileSize( metricFile );
        if( fileSize < sizeof( MD_METRICS_FILE_KEY ) )
        {
            fclose( metricFile );
            return CC_ERROR_INVALID_PARAMETER;
        }

        metricFileBuffer = new( std::nothrow ) uint8_t[fileSize];
        if( metricFileBuffer == nullptr )
        {
            fclose( metricFile );
            return CC_ERROR_NO_MEMORY;
        }
        memset( metricFileBuffer, 0, fileSize );

        MD_LOG( LOG_DEBUG, "Check if file is in MDAPI plain text format" );
        if( IsMetricsFileInPlainTextFormat( metricFile, fileVersion ) )
        {
            // Load plain text format file
            iu_fread_s( metricFileBuffer, fileSize, 1, fileSize, metricFile );
            bufferPtr = metricFileBuffer;

            if( fileVersion == CUSTOM_METRICS_FILE_VERSION_1 )
            {
                bufferPtr += sizeof( MD_METRICS_FILE_KEY );
            }
            else if( fileVersion == CUSTOM_METRICS_FILE_VERSION_2 )
            {
                bufferPtr += sizeof( MD_METRICS_FILE_KEY_2_0 );
            }
        }
        else
        {
            MD_LOG( LOG_ERROR, "Metrics device file is not valid" );
            retVal = CC_ERROR_INVALID_PARAMETER;
        }
        fclose( metricFile );

        if( retVal == CC_OK )
        {
            if( fileVersion > CUSTOM_METRICS_FILE_VERSION_1 )
            {
                uint32_t majorApiVersion = ReadUInt32FromFileBuffer( &bufferPtr );
                uint32_t minorApiVersion = ReadUInt32FromFileBuffer( &bufferPtr );

                if( ( majorApiVersion == MD_API_MAJOR_NUMBER_CURRENT && minorApiVersion > MD_API_MINOR_NUMBER_CURRENT ) || majorApiVersion > MD_API_MAJOR_NUMBER_CURRENT )
                {
                    MD_LOG( LOG_ERROR, "Requered MDAPI version %d.%d, current version %d.%d", majorApiVersion, minorApiVersion, MD_API_MAJOR_NUMBER_CURRENT, MD_API_MINOR_NUMBER_CURRENT );
                    m_isOpenedFromFile = false;
                    MD_SAFE_DELETE_ARRAY( metricFileBuffer );
                    return CC_ERROR_NOT_SUPPORTED;
                }
            }

            MD_LOG( LOG_DEBUG, "Metrics device file saved on platform: %d, current: %d", *( (TPlatformType*) bufferPtr ), m_platform );
            bufferPtr += sizeof( TPlatformType );

            // MetricsDeviceParams
            TApiVersion_1_0 apiVersion = {};
            apiVersion.MajorNumber     = ReadUInt32FromFileBuffer( &bufferPtr );
            apiVersion.MinorNumber     = ReadUInt32FromFileBuffer( &bufferPtr );
            apiVersion.BuildNumber     = ReadUInt32FromFileBuffer( &bufferPtr );
            MD_LOG( LOG_DEBUG, "Metrics device file saved with MDAPI v. %d.%d.%d, current v: %d.%d.%d", apiVersion.MajorNumber, apiVersion.MinorNumber, apiVersion.BuildNumber, MD_API_MAJOR_NUMBER_CURRENT, MD_API_MINOR_NUMBER_CURRENT, MD_API_BUILD_NUMBER_CURRENT );

            // GlobalSymbols
            retVal = ReadGlobalSymbolsFromFileBuffer( &bufferPtr );

            // ConcurrentGroup tree
            if( retVal == CC_OK )
            {
                retVal = ReadConcurrentGroupsFromFileBuffer( &bufferPtr, isInternalBuild, &apiVersion );
            }
        }
        m_isOpenedFromFile = ( retVal == CC_OK );

        MD_SAFE_DELETE_ARRAY( metricFileBuffer );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsMetricsFileInPlainTextFormat
    //
    // Description:
    //     Check if metrics file has a proper header with MD_METRICS_FILE_KEY.
    //
    // Input:
    //     FILE*     metricFile  - opened file with custom metrics.
    //     uint32_t& fileVersion - custom file version [out]
    //
    // Output:
    //     bool             - true if file in MDAPI plain text format, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsMetricsFileInPlainTextFormat( FILE* metricFile, uint32_t& fileVersion )
    {
        const uint32_t metricFileKeySize              = sizeof( MD_METRICS_FILE_KEY_2_0 );
        uint8_t        readFileKey[metricFileKeySize] = {
            0,
        };

        // Load fragment of the file as plain text
        iu_fread_s( readFileKey, metricFileKeySize, 1, metricFileKeySize, metricFile );
        // Move file pointer to the start
        rewind( metricFile );

        if( strcmp( MD_METRICS_FILE_KEY, (const char*) &readFileKey ) == 0 )
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_1;
        }
        else if( strcmp( MD_METRICS_FILE_KEY_2_0, (const char*) &readFileKey ) == 0 )
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_2;
        }
        else
        {
            fileVersion = CUSTOM_METRICS_FILE_VERSION_0;
        }

        // Check if the file has MDAPI plain text header
        return fileVersion > CUSTOM_METRICS_FILE_VERSION_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetDriverInterface
    //
    // Description:
    //     Returns driver interface.
    //
    // Output:
    //     CDriverInterface& - driver interface reference
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterface& CMetricsDevice::GetDriverInterface()
    {
        return m_driverInterface;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetAdapter
    //
    // Description:
    //     Returns underlying adapter reference.
    //
    // Output:
    //     CAdapter& - adapter reference
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapter& CMetricsDevice::GetAdapter()
    {
        return m_adapter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetSymbolSet
    //
    // Description:
    //     Returns pointer to the symbol set.
    //
    // Output:
    //     CSymbolSet*   - pointer to the symbol set
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet* CMetricsDevice::GetSymbolSet()
    {
        return &m_symbolSet;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetPlatformType
    //
    // Description:
    //     Returns platform type.
    //
    // Output:
    //     TPlatformType - platform type.
    //
    //////////////////////////////////////////////////////////////////////////////
    TPlatformType CMetricsDevice::GetPlatformType()
    {
        return m_platform;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     IsOpenedFromFile
    //
    // Description:
    //     Returns true if device was opened from a file
    //
    // Output:
    //     bool - true if opened from file
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsDevice::IsOpenedFromFile()
    {
        return m_isOpenedFromFile;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetReferenceCounter
    //
    // Description:
    //     Returns metrics device reference counters.
    //
    // Output:
    //     uint32_t - metrics device reference counter
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t& CMetricsDevice::GetReferenceCounter()
    {
        return m_referenceCounter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetSubDeviceIndex
    //
    // Description:
    //     Returns sub device index.
    //
    // Output:
    //     uint32_t - sub device index
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricsDevice::GetSubDeviceIndex()
    {
        return m_subDeviceIndex;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamConfigId
    //
    // Description:
    //     Returns stream configuration id.
    //
    // Output:
    //     int32_t - configuration id.
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CMetricsDevice::GetStreamConfigId()
    {
        return m_streamConfigId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamId
    //
    // Description:
    //     Returns stream id.
    //
    // Output:
    //     int32_t - stream id.
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CMetricsDevice::GetStreamId()
    {
        return m_streamId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SetStreamId
    //
    // Description:
    //     Sets stream id.
    //
    // Input:
    //     const int32_t id - stream id.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsDevice::SetStreamId( const int32_t id )
    {
        m_streamId = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     SetStreamConfigId
    //
    // Description:
    //     Sets stream configuration id.
    //
    // Input:
    //     const int32_t id - configuration id.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsDevice::SetStreamConfigId( const int32_t id )
    {
        m_streamConfigId = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetStreamBuffer
    //
    // Description:
    //     Returns preallocated buffer for reading data from tbs stream to avoid new allocations on every read.
    //
    // Output:
    //     std::vector<uint8_t> - tbs stream buffer.
    //
    //////////////////////////////////////////////////////////////////////////////
    std::vector<uint8_t>& CMetricsDevice::GetStreamBuffer()
    {
        return m_streamBuffer;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsDevice
    //
    // Method:
    //     GetConcurrentGroupByName
    //
    // Description:
    //     Returns chosen concurrent group by name or nullptr if not exists.
    //
    // Input:
    //     const char* symbolName - name of a concurrent group to look for
    //
    // Output:
    //     CConcurrentGroup*      - found concurrent group or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup* CMetricsDevice::GetConcurrentGroupByName( const char* symbolName )
    {
        MD_CHECK_PTR_RET( symbolName, nullptr );

        for( auto& group : m_groupsVector )
        {
            if( group && ( strcmp( symbolName, group->GetParams()->SymbolName ) == 0 ) )
            {
                return group;
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     CConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device     - parent metrics device
    //     const char * name           - concurrent group name
    //     const char * description    - concurrent group description
    //     uint32_t measurementTypeMask - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup::CConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : m_setsVector()
        , m_otherSetsList()
        , m_informationVector()
        , m_otherInformationVector()
        , m_device( device )
        , m_semaphore( nullptr )
        , m_informationCount( 0 )
        , m_isAvailabile( true )
    {
        m_params_1_0.SymbolName                    = GetCopiedCString( name );
        m_params_1_0.Description                   = GetCopiedCString( description );
        m_params_1_0.MeasurementTypeMask           = measurementTypeMask;
        m_params_1_0.MetricSetsCount               = 0;
        m_params_1_0.IoMeasurementInformationCount = 0;
        m_params_1_0.IoGpuContextInformationCount  = 0;

        m_setsVector.reserve( SETS_VECTOR_INCREASE );
        m_informationVector.reserve( INFORMATION_VECTOR_INCREASE );
        m_otherInformationVector.reserve( INFORMATION_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     CConcurrentGroup destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CConcurrentGroup::~CConcurrentGroup()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.Description );
        ClearVector( m_informationVector );
        ClearVector( m_otherInformationVector );
        ClearVector( m_setsVector );
        ClearList( m_otherSetsList );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns concurrent group params.
    //
    // Output:
    //     TConcurrentGroupParams_1_0*  - concurrent group params
    //
    //////////////////////////////////////////////////////////////////////////////
    TConcurrentGroupParams_1_0* CConcurrentGroup::GetParams( void )
    {
        return &m_params_1_0;
    }

//////////////////////////////////////////////////////////////////////////////
// Helper macro to get CustomMetricSetParams
//////////////////////////////////////////////////////////////////////////////
#define MD_CUSTOM_METRIC_SET_PARAMS( params, version ) ( params )->CustomMetricSetParams_##version

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Wrapper function for adding custom metric sets with the given parameters.
    //
    // Input:
    //     TAddCustomMetricSetParams*  params               - params
    //     IMetricSetLatest*           referenceMetricSet   - (optional) metric set from which copy metrics and information
    //                                                         *IGNORED IN CConcurrentGroup*
    //     bool                        copyInformationOnly  - Copy information without metrics from reference set
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly /*= false*/ )
    {
        if( params == nullptr )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
            return nullptr;
        }

        IMetricSetLatest* set = nullptr;

        if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
        {
            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSetsCount,
                nullptr,
                copyInformationOnly );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_1 )
        {
            set = AddCustomMetricSet(
                nullptr, // don't inherit any metrics and information
                nullptr,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).AvailabilityEquation,
                copyInformationOnly );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     FindSameMetricSetForPlatform
    //
    // Description:
    //     Finds MetricSet with the same symbol name matching the given platform mask.
    //     Used in adding custom metric sets with reference metric sets.
    //
    // Input:
    //     CMetricSet*  metricSet    - metrics set to look for
    //     uint32_t     platformMask - platform mask
    //
    // Output:
    //     CMetricSet* - found metric set, input metric set if not found one with matching
    //                   platform mask
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::FindSameMetricSetForPlatform( CMetricSet* metricSet, uint32_t platformMask )
    {
        if( !metricSet || ( metricSet->GetParams()->PlatformMask & platformMask ) == platformMask )
        {
            return metricSet;
        }

        for( auto& otherSet : m_otherSetsList )
        {
            if( otherSet && ( strcmp( otherSet->GetParams()->SymbolName, metricSet->GetParams()->SymbolName ) == 0 ) && ( otherSet->GetParams()->PlatformMask & platformMask ) == platformMask )
            {
                return otherSet;
            }
        }

        return metricSet;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Adds custom metric set with the given parameters.
    //
    // Input:
    //     CMetricSet*        referenceMetricSet     - (optional) metric set from which inherit metrics and information
    //     const char*        signalName             - (optional) signal name with which metrics should be inherited
    //     const char*        symbolName             -
    //     const char*        shortName              -
    //     uint32_t           apiMask                -
    //     uint32_t           categoryMask           -
    //     uint32_t           rawReportSize          -
    //     uint32_t           queryReportSize        -
    //     uint32_t           complementarySetsCount -
    //     const char*        complementarySetsList  - comma separated copmlementary sets list
    //     TApiSpecificId_1_0 apiSpecificId          -
    //     TRegisterSet*      startRegSets           -
    //     uint32_t           startRegSetsCount      -
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName, const char* symbolName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t platformMask, uint32_t gtMask, uint32_t rawReportSize, uint32_t queryReportSize, const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets, uint32_t startRegSetsCount, const char* availabilityEquation, bool copyInformationOnly /*= false*/ )
    {
        MD_LOG_ENTER();

        if( !AreMetricSetParamsValid( symbolName, shortName, platformMask, gtMask, startRegSets, startRegSetsCount ) )
        {
            MD_LOG( LOG_ERROR, "invalid custom metric set parameters" );
            MD_LOG_EXIT();
            return nullptr;
        }
        if( MatchingSetExists( symbolName, platformMask, gtMask ) )
        {
            MD_LOG( LOG_ERROR, "metric set already added: %s", symbolName );
            MD_LOG_EXIT();
            return nullptr;
        }

        CMetricSet* refMetricSetMatchingPlatform = nullptr;
        CMetricSet* set                          = new( std::nothrow ) CMetricSet( m_device, this, symbolName, shortName, apiMask, categoryMask, rawReportSize, queryReportSize, DEFAULT_METRIC_SET_REPORT_TYPE, platformMask, gtMask, true );
        MD_CHECK_PTR_RET( set, nullptr );

        if( complementarySetsList != nullptr && set->AddComplementaryMetricSets( complementarySetsList ) != CC_OK )
        {
            goto customMetricSetCleanup;
        }

        if( set->SetApiSpecificId( apiSpecificId ) != CC_OK )
        {
            MD_LOG( LOG_DEBUG, "error setting apiSpecificId" );
            goto customMetricSetCleanup;
        }

        refMetricSetMatchingPlatform = FindSameMetricSetForPlatform( referenceMetricSet, platformMask );
        if( refMetricSetMatchingPlatform != nullptr && set->InheritFromMetricSet( refMetricSetMatchingPlatform, signalName, copyInformationOnly ) != CC_OK )
        {
            goto customMetricSetCleanup;
        }
        if( startRegSets && startRegSetsCount )
        {
            for( uint32_t i = 0; i < startRegSetsCount; i++ )
            {
                if( startRegSets[i].StartConfigRegs && startRegSets[i].StartConfigRegsCount )
                {
                    set->AddStartRegisterSet(
                        startRegSets[i].ConfigId,
                        startRegSets[i].ConfigPriority,
                        startRegSets[i].AvailabilityEquation,
                        startRegSets[i].ConfigType );

                    for( uint32_t j = 0; j < startRegSets[i].StartConfigRegsCount; j++ )
                    {
                        set->AddStartConfigRegister(
                            startRegSets[i].StartConfigRegs[j].offset,
                            startRegSets[i].StartConfigRegs[j].value,
                            startRegSets[i].StartConfigRegs[j].type );
                    }
                }
            }
        }
        set->RefreshConfigRegisters();

        if( set->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Error setting metric set equations" );
            goto customMetricSetCleanup;
        }

        if( m_device->IsPlatformTypeOf( platformMask, gtMask ) && m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            m_setsVector.push_back( set );
            m_params_1_0.MetricSetsCount = m_setsVector.size();
        }
        else
        {
            m_otherSetsList.push_back( set );
        }

        return set;

    customMetricSetCleanup:
        MD_SAFE_DELETE( set );
        MD_LOG_EXIT();
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AddMetricSet
    //
    // Description:
    //     Adds a new metric set to  the concurrent group.
    //
    // Input:
    //     const char *     symbolicName          -
    //     const char *     shortName             -
    //     uint32_t         apiMask               -
    //     TMetricCategory  category              - metric set category
    //     uint32_t         snapshotReportSize    -
    //     uint32_t         deltaReportSize       -
    //     TReportType      reportType            -
    //     const char *     availabilityEquation  -
    //     uint32_t         platformMask          -
    //     uint32_t         gtMask                -
    //     bool             isCustom              -
    //
    // Output:
    //     CMetricSet*  - pointer to the newly added metrics set
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, uint32_t platformMask, const char* availabilityEquation /*= nullptr*/, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
    {
        CMetricSet* alreadyAddedSet = nullptr;
        CMetricSet* set             = new( std::nothrow ) CMetricSet( m_device, this, symbolicName, shortName, apiMask, categoryMask, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom );

        if( set->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Error setting metric set equations" );
            MD_SAFE_DELETE( set );
            return nullptr;
        }

        bool isSuitablePlatform = m_device->IsPlatformTypeOf( platformMask, gtMask ) && m_device->IsAvailabilityEquationTrue( availabilityEquation );

        if( isSuitablePlatform )
        {
            // Check if metric set is already present in m_setsVector or m_otherSetsList.
            alreadyAddedSet = GetMatchingMetricSet( symbolicName, platformMask, gtMask, true );
            if( alreadyAddedSet != nullptr )
            {
                // If metric set present in m_setsVector it should be move to m_otherSetsList.
                // Metric set compared to alreadyAddedSet will be added in else section as unavailable on this platform.
                auto iterator = std::find( m_setsVector.begin(), m_setsVector.end(), alreadyAddedSet );
                if( iterator != m_setsVector.end() )
                {
                    MD_LOG( LOG_WARNING, "Attempt to add metric set with the same name and true availability equation." );

                    m_setsVector.erase( iterator );
                    m_params_1_0.MetricSetsCount = m_setsVector.size();

                    m_otherSetsList.push_back( alreadyAddedSet );
                }
            }
        }

        if( isSuitablePlatform && alreadyAddedSet == nullptr )
        {
            m_setsVector.push_back( set );
            m_params_1_0.MetricSetsCount = m_setsVector.size();
            MD_LOG( LOG_INFO, "%s - added", set->GetParams()->SymbolName );
        }
        else
        {
            MD_LOG( LOG_INFO, "%s - not available", set->GetParams()->SymbolName );
            m_otherSetsList.push_back( set );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMetricSet
    //
    // Description:
    //     Returns the chosen metrics set or null if index doesn't exist.
    //
    // Input:
    //     uint32_t index    - index of a chosen metrics set
    //
    // Output:
    //     IMetricSetLatest* - chosen metrics set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* CConcurrentGroup::GetMetricSet( uint32_t index )
    {
        if( index < m_setsVector.size() )
        {
            return m_setsVector[index];
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     Lock
    //
    // Description:
    //     Creates a semaphore on the concurrent group. Waits 1s if needed.
    //     Adapter BDF numbers are added to the semaphore name so different
    //     adapters won't block each other.
    //
    // Output:
    //     TCompletionCode - *CC_OK* if succeeded,
    //                       *CC_CONCURRENT_GROUP_LOCKED* if timeout occurred
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::Lock()
    {
        // 1. Create semaphore name
        char semaphoreName[MD_SEMAPHORE_NAME_MAX_LENGTH] = {};

        TCompletionCode ret = FillLockSemaphoreName( semaphoreName, sizeof( semaphoreName ) );
        if( ret == CC_OK )
        {
            // 2. Get driver interface
            CDriverInterface& driverInterface = m_device->GetDriverInterface();

            // 3. Lock concurrent group
            ret = driverInterface.LockConcurrentGroup( semaphoreName, &m_semaphore );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     Unlock
    //
    // Description:
    //     Releases the semaphore created on concurrent group.
    //     Adapter BDF numbers are added to the semaphore name so different
    //     adapters won't block each other.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::Unlock()
    {
        // 1. Create semaphore name
        char semaphoreName[MD_SEMAPHORE_NAME_MAX_LENGTH] = {};

        TCompletionCode ret = FillLockSemaphoreName( semaphoreName, sizeof( semaphoreName ) );
        if( ret == CC_OK )
        {
            // 2. Get driver interface
            CDriverInterface& driverInterface = m_device->GetDriverInterface();

            // 3. Unlock concurrent group
            ret = driverInterface.UnlockConcurrentGroup( semaphoreName, &m_semaphore );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     WriteCConcurrentGroupToFile
    //
    // Description:
    //     Writes concurrent group to file.
    //
    // Input:
    //     FILE* metricFile    - handle to metric file file
    //
    // Output:
    //     TCompletionCode - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::WriteCConcurrentGroupToFile( FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
        WriteCStringToFile( m_params_1_0.Description, metricFile );
        fwrite( &m_params_1_0.MeasurementTypeMask, sizeof( m_params_1_0.MeasurementTypeMask ), 1, metricFile );

        // m_setsVector & m_otherSetsList
        uint32_t count = GetCustomSetCount();
        fwrite( &count, sizeof( count ), 1, metricFile );

        for( auto& metricSet : m_setsVector )
        {
            if( metricSet->IsCustom() )
            {
                metricSet->WriteCMetricSetToFile( metricFile );
            }
        }

        for( auto& otherMetricSet : m_otherSetsList )
        {
            if( otherMetricSet->IsCustom() )
            {
                otherMetricSet->WriteCMetricSetToFile( metricFile );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     MatchingSetExists
    //
    // Description:
    //     Checks if metric set of the given name, platform and gt is already added to the concurrent group.
    //
    // Input:
    //     const char * symbolicName   - symbolic name of a metric set to check
    //     uint32_t     platformMask   - platform Id bit mask indicates platforms compatible with set.
    //     uint32_t     gtMask         - gt type bit mask indicates platform versions compatible with set.
    //
    // Output:
    //     bool                        - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CConcurrentGroup::MatchingSetExists( const char* symbolName, uint32_t platformMask, uint32_t gtMask )
    {
        return GetMatchingMetricSet( symbolName, platformMask, gtMask ) != nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     AreMetricSetParamsValid
    //
    // Description:
    //     Checks the correctness of the given metricSet parameters.
    //
    // Input:
    //     const char*   symbolName        -
    //     const char*   shortName         -
    //     uint32_t      platformMask      -
    //     TRegisterSet* startRegSets      -
    //     uint32_t      startRegSetsCount -
    //
    // Output:
    //     bool                       - true if valid
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CConcurrentGroup::AreMetricSetParamsValid( const char* symbolName, const char* shortName, uint32_t platformMask, uint32_t gtMask, TRegisterSet* startRegSets, uint32_t startRegSetsCount )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        if( ( symbolName == nullptr ) || ( strcmp( symbolName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, symbolName );
            return false;
        }
        if( ( shortName == nullptr ) || ( strcmp( shortName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, shortName );
            return false;
        }
        if( platformMask == 0 )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, platformMask );
            return false;
        }
        if( gtMask == 0 )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, gtMask );
            return false;
        }
        if( startRegSetsCount > 0 && startRegSets == nullptr )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, startRegSets );
            return false;
        }

        for( uint32_t i = 0; i < startRegSetsCount; i++ )
        {
            if( startRegSets[i].StartConfigRegsCount > 0 )
            {
                if( startRegSets[i].StartConfigRegs == nullptr )
                {
                    MD_LOG_INVALID_PARAMETER( LOG_ERROR, startRegSets[i].StartConfigRegs );
                    return false;
                }

                // Validate registers for every platform in the mask
                uint32_t platform = 1;
                while( platform <= platformMask )
                {
                    if( platformMask & platform )
                    {
                        MD_LOG( LOG_DEBUG, "validating register offsets for platform: %u", platform );
                        if( driverInterface.ValidatePmRegsConfig( startRegSets[i].StartConfigRegs, startRegSets[i].StartConfigRegsCount, (TPlatformType) platform ) != CC_OK )
                        {
                            MD_LOG( LOG_ERROR, "invalid start register offsets for platform: %u", platform );
                            return false;
                        }
                    }
                    platform <<= 1;
                }
            }
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetCustomSetCount
    //
    // Description:
    //     Returns number of custom sets + default sets with custom metrics.
    //
    // Output:
    //     uint32_t - custom set count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CConcurrentGroup::GetCustomSetCount()
    {
        uint32_t customSetCount = 0;

        for( auto& metricSet : m_setsVector )
        {
            if( metricSet->IsCustom() )
            {
                customSetCount++;
            }
        }

        for( auto& metricSet : m_otherSetsList )
        {
            if( metricSet->IsCustom() )
            {
                customSetCount++;
            }
        }

        return customSetCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     FillLockSemaphoreName
    //
    // Description:
    //     Creates semaphore name for the need of lock / unlock concurrent group
    //     calls. Adapter BDF numbers are added to the name so different adapters
    //     won't block each other.
    //
    // Input:
    //     char*  name - buffer for the name
    //     size_t size - size of the name buffer
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CConcurrentGroup::FillLockSemaphoreName( char* name, size_t size )
    {
        MD_ASSERT( name != nullptr );

        // Create a semaphore name: "<CcgSymbolName>_<BusNumber>_<DeviceNumber>_<FunctionNumber>"
        const TAdapterParams_1_9* adapterParams = m_device->GetAdapter().GetParams();
        MD_CHECK_PTR_RET( adapterParams, CC_ERROR_GENERAL );

        int32_t neededSize = snprintf( name, size, "%s_%u_%u_%u", m_params_1_0.SymbolName, adapterParams->BusNumber, adapterParams->DeviceNumber, adapterParams->FunctionNumber );

        // If snprintf failed or buffer size was too small
        if( neededSize < 0 || neededSize >= (int32_t) size )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMatchingMetricSet
    //
    // Description:
    //     Looks through concurrent group for an already added metric set with
    //     a given name, platform and gt. Returns pointer to a found metric set or
    //     null if it doesn't exist.
    //
    // Input:
    //     const char* symbolName                       - name of a metric set to look for
    //     uint32_t    platformMask                     - platform Id bit mask indicates platforms compatible with set.
    //     uint32_t    gtMask                           - gt type bit mask indicates platform versions compatible with set.
    //     bool        findWithTrueAvailabilityEquation - check if availability equation of set contained in m_otherSetsList is true.
    // Output:
    //     CMetricSet*                                  - found metric set or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* CConcurrentGroup::GetMatchingMetricSet( const char* symbolName, uint32_t platformMask, uint32_t gtMask, bool findWithTrueAvailabilityEquation /* = false */ )
    {
        MD_CHECK_PTR_RET( symbolName, nullptr );

        // List of available sets
        for( auto& metricSet : m_setsVector )
        {
            TMetricSetParamsLatest* setParams = metricSet ? metricSet->GetParams() : nullptr;

            if( setParams && ( strcmp( symbolName, setParams->SymbolName ) == 0 ) )
            {
                bool platformMatch = ( platformMask & setParams->PlatformMask ) != 0;
                bool gtMatch       = ( gtMask & setParams->GtMask ) != 0;

                if( platformMatch && gtMatch )
                {
                    return metricSet;
                }
            }
        }

        // List of unavailable sets for current platform
        for( auto& otherMetricSet : m_otherSetsList )
        {
            TMetricSetParamsLatest* setParams = otherMetricSet ? otherMetricSet->GetParams() : nullptr;

            if( setParams && strcmp( symbolName, setParams->SymbolName ) == 0 )
            {
                bool platformMatch = ( platformMask & setParams->PlatformMask ) != 0;
                bool gtMatch       = ( gtMask & setParams->GtMask ) != 0;

                if( platformMatch && gtMatch )
                {
                    if( findWithTrueAvailabilityEquation && !otherMetricSet->IsAvailabilityEquationTrue() )
                    {
                        continue;
                    }

                    return otherMetricSet;
                }
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetInformation
    //
    // Description:
    //     Returns the chosen information or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of an information
    //
    // Output:
    //     IInformation_1_0*   - chosen information or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* CConcurrentGroup::GetInformation( uint32_t index )
    {
        if( index < m_informationVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_informationVector[index] );
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetInformationCount
    //
    // Description:
    //     Returns number of Information objects in concurrent group
    //
    // Output:
    //     uint32_t - number of information objects
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CConcurrentGroup::GetInformationCount()
    {
        return m_informationCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Method:
    //     GetMetricsDevice
    //
    // Description:
    //     Returns metrics device.
    //
    // Output:
    //     CMetricsDevice* - a pointer to a metrics device object.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CConcurrentGroup::GetMetricsDevice()
    {
        return m_device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device             - parent metrics device
    //     const char * name                   - concurrent group name
    //     const char * description            - concurrent group description
    //     uint32_t     measurementTypeMask    -
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::COAConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : CConcurrentGroup( device, name, description, measurementTypeMask )
        , m_ioMeasurementInfoVector()
        , m_ioGpuContextInfoVector()
        , m_processId( 0 )
        , m_contextTagsEnabled( false )
        , m_ioMetricSet( nullptr )
        , m_streamEventHandle( nullptr )
        , m_streamType( STREAM_TYPE_OA )
    {
        AddIoMeasurementInfoPredefined();

        m_ioMeasurementInfoVector.reserve( EXCEPTIONS_VECTOR_INCREASE );
        m_ioGpuContextInfoVector.reserve( GPU_CONTEXTS_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::~COAConcurrentGroup()
    {
        if( m_ioMetricSet )
        {
            CloseIoStream();
        }

        ClearVector( m_ioMeasurementInfoVector );
        ClearVector( m_ioGpuContextInfoVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Wrapper function for adding custom metric sets with the given parameters.
    //
    // Input:
    //     TAddCustomMetricSetParams*  params               - params
    //     IMetricSetLatest*           referenceMetricSet   - (optional) metric set from which copy metrics and information
    //     bool                        copyInformationOnly  - Copy information without metrics from reference set
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* COAConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly /*= false*/ )
    {
        if( params == nullptr )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
            return nullptr;
        }

        IMetricSetLatest* set = nullptr;

        if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
        {
            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSetsCount,
                nullptr,
                copyInformationOnly );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_1 )
        {
            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).AvailabilityEquation,
                copyInformationOnly );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoStreamSamplingType
    //
    // Description:
    //     Sets stream sampling type. OA and BB (batch buffer) supported.
    //
    // Input:
    //     TSamplingType type - requested IO Stream Sampling Type
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::SetIoStreamSamplingType( TSamplingType type )
    {
        TStreamType     newStreamType = STREAM_TYPE_OA;
        TCompletionCode ret           = CC_OK;
        MD_LOG_ENTER();
        switch( type )
        {
            case SAMPLING_TYPE_OA_TIMER:
                newStreamType = STREAM_TYPE_OA;
                break;
            case SAMPLING_TYPE_DMA_BUFFER:
                newStreamType = STREAM_TYPE_BB;
                break;
            default:
                ret = CC_ERROR_NOT_SUPPORTED;
        }
        if( ret == CC_OK && newStreamType != m_streamType )
        {
            // change is disallowed if stream is already opened
            if( m_ioMetricSet != nullptr )
            {
                MD_LOG( LOG_ERROR, "Failed to set IoStream sampling type" );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                m_streamType = newStreamType;
                MD_LOG( LOG_DEBUG, "Stream type changed to: %u", m_streamType );
            }
        }
        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Opens IO Stream for given metric set.
    //     (Enables Timer Mode and opens Counter Stream)
    //
    // Input:
    //     IMetricSet_1_0*      metricSet           - metric set
    //     uint32_t             processId           - PID of the measured app (0 is global context)
    //     uint32_t*            nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t*            oaBufferSize        - (in/out) requested/set OA Buffer size in bytes
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( oaBufferSize, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.OpenIoStream( m_streamType, *m_device, static_cast<CMetricSet*>( metricSet ), m_params_1_0.SymbolName, processId, nsTimerPeriod, oaBufferSize, &m_streamEventHandle );
        if( ret != CC_OK )
        {
            MD_LOG_EXIT();
            return ret;
        }
        MD_LOG( LOG_DEBUG, "Stream opened using type: %u", m_streamType );

        m_ioMetricSet          = static_cast<CMetricSet*>( metricSet );
        m_processId            = processId;
        m_contextTagsEnabled   = m_ioMetricSet->HasInformation( "ContextId" );
        CMetricsCalculator* mc = m_ioMetricSet->GetMetricsCalculator();
        // In case of stream reopen
        ClearVector( m_ioGpuContextInfoVector );
        m_params_1_0.IoGpuContextInformationCount = 0;
        if( mc != nullptr )
        {
            mc->DiscardSavedReport();
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    //     data was read. Additionally, at the end of ReadIoStream GpuContextIds are read and updated.
    //
    // Input:
    //     uint32_t        reportCount - (in/out) requested number of reports to read / reports read from the stream
    //     char*           reportData  - (out) pointer to the read data
    //     uint32_t        readFlags   - read flags (see TIoReadFlag enum), 0 is ok
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
    {
        MD_CHECK_PTR_RET( reportData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( reportCount, CC_ERROR_INVALID_PARAMETER );
        if( m_ioMetricSet == nullptr )
        {
            *reportCount = 0;
            MD_LOG( LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }
        if( *reportCount == 0 )
        {
            MD_LOG( LOG_DEBUG, "0 reports to read" );
            return CC_OK;
        }

        TCompletionCode                 ret             = CC_OK;
        CDriverInterface&               driverInterface = m_device->GetDriverInterface();
        uint32_t                        frequency       = 0;
        GTDIReadCounterStreamExceptions exceptions      = {};

        ret = driverInterface.ReadIoStream( m_streamType, *m_device, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
        if( ret == CC_OK || ret == CC_READ_PENDING )
        {
            driverInterface.HandleIoStreamExceptions( m_params_1_0.SymbolName, m_ioMetricSet, m_processId, reportCount, &exceptions );

            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW, exceptions.BufferOverflow, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERRUN, exceptions.BufferOverrun, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW, exceptions.CountersOverflow, &index );

            m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector.size();
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes IO Stream.
    //     (Closes Counter Stream and disables Timer Mode)
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::CloseIoStream( void )
    {
        MD_LOG_ENTER();
        if( m_ioMetricSet == nullptr )
        {
            MD_LOG( LOG_ERROR, "stream not opened" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.CloseIoStream( m_streamType, *m_device, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
        if( ret != CC_OK )
        {
            MD_LOG_EXIT();
            return ret;
        }

        // m_processId is not cleared after close to define if context filtering was used.
        // Stream reopen will override m_processId
        m_ioMetricSet = nullptr;
        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     WaitForReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     uint32_t     milliseconds   - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::WaitForReports( uint32_t milliseconds )
    {
        TCompletionCode   retVal          = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        retVal = driverInterface.WaitForIoStreamReports( m_streamType, *m_device, milliseconds, m_streamEventHandle );

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoMeasurementInformation
    //
    // Description:
    //     Returns measurement information of given index. Measurement information values
    //     are set after successful ReadIoStream.
    //
    // Input:
    //     uint32_t     index  - index of the measurement information
    //
    // Output:
    //     IInformation_1_0*   - measurement information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoMeasurementInformation( uint32_t index )
    {
        if( m_params_1_0.IoMeasurementInformationCount != 0 && index < m_ioMeasurementInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioMeasurementInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoGpuContextInformation
    //
    // Description:
    //     Returns GPU context id information of given index. GPU context id information values
    //     are set after successful ReadIoStream if IO_READ_FLAG_GET_CONTEXT_ID_TAGS was set.
    //
    // Input:
    //     uint32_t     index  - index of the GPU context information
    //
    // Output:
    //     IInformation_1_0*   - GPU context information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoGpuContextInformation( uint32_t index )
    {
        if( m_params_1_0.IoGpuContextInformationCount != 0 && index < m_ioGpuContextInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioGpuContextInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddAllIoMeasurementInformation
    //
    // Description:
    //     Adds exceptions from GTDIReadCounterStreamExceptions struct and Frequency from
    //     GTDIReadCounterStreamExtOut struct.
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::AddIoMeasurementInfoPredefined( void )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ ) )
        {
            AddIoMeasurementInformation( "CoreFrequencyMHz", "Core Frequency in MHz", "The last core frequency in the measurement.", "Report Meta Data", INFORMATION_TYPE_VALUE, "megahertz" );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED ) )
        {
            AddIoMeasurementInformation( "FrequencyChanged", "Core Frequency Changed", "The flag indicating that core frequency has changed.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID ) )
        {
            AddIoMeasurementInformation( "FrequencyChangedInvalid", "Core Frequency Changed Invalid", "The flag indicating inability to report freq change due to delayed read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN ) )
        {
            AddIoMeasurementInformation( "SliceShutdown", "Slice Shutdown Occurred", "The flag indicating that the Slice Shutdown has occurred.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_REPORT_LOST ) )
        {
            AddIoMeasurementInformation( "ReportLost", "Report Lost reported by HW", "The flag indicating that some samples were lost since last Read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_DATA_OUTSTANDING ) )
        {
            AddIoMeasurementInformation( "DataOutstanding", "Data Outstanding", "The flag indicating that there are still some outstanding data.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "BufferOverflow", "Buffer Overflow", "The flag indicating that some reports have been overwritten.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERRUN ) )
        {
            AddIoMeasurementInformation( "BufferOverrun", "Buffer Overrun", "The flag indicating that the buffer is full (n-1 reports).", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "CountersOverflow", "Counters Overflow", "The flag indicating that counters overflows occurred between two consecutive readings.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoMeasurementInformation
    //
    // Description:
    //     Adds new measurement information to the *m_ioMeasurementInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation. To set use SetInformationValue() from CInformation class.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added measurement information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        CInformation* measurementInfo = new( std::nothrow ) CInformation( m_device, m_ioMeasurementInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | API_TYPE_BBSTREAM, informationType, informationUnits );
        MD_CHECK_PTR_RET( measurementInfo, nullptr );

        measurementInfo->SetSnapshotReportReadEquation( "" );
        measurementInfo->SetDeltaReportReadEquation( "" );

        m_ioMeasurementInfoVector.push_back( measurementInfo );
        return measurementInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoGpuContextInformation
    //
    // Description:
    //     Adds new GPU context information to the *m_ioGpuContextInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added GPU context information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        CInformation* gpuContextInfo = new( std::nothrow ) CInformation( m_device, m_ioGpuContextInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | 0x0, informationType, informationUnits );
        MD_CHECK_PTR_RET( gpuContextInfo, nullptr );

        gpuContextInfo->SetSnapshotReportReadEquation( "" );
        gpuContextInfo->SetDeltaReportReadEquation( "" );

        m_ioGpuContextInfoVector.push_back( gpuContextInfo );
        return gpuContextInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoMeasurementInfoPredefined
    //
    // Description:
    //     Sets value of the previously defined IoMeasurementInformation identified by
    //     the given type.
    //     Used indices should be in sync with AddIoMeasurementInfoPredefined() (right order).
    //
    // Input:
    //     TIoMeasurementInfoType ioMeasurementInfoType - IO measurement information type
    //     uint32_t               value                 - value to set
    //     uint32_t*              index                 - IO measurement information index (should be in sync with AddIoMeasurementInfoPredefined())
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::SetIoMeasurementInfoPredefined( TIoMeasurementInfoType ioMeasurementInfoType, uint32_t value, uint32_t* index )
    {
        if( !index || *index >= m_ioMeasurementInfoVector.size() )
        {
            return;
        }

        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        // Set information if available
        if( driverInterface.IsIoMeasurementInfoAvailable( ioMeasurementInfoType ) )
        {
            m_ioMeasurementInfoVector[( *index )++]->SetInformationValue( value, EQUATION_IO_READ );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     CPerfMonConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device             - parent metrics device
    //     const char * name                   - concurrent group name
    //     const char * description            - concurrent group description
    //     uint32_t     measurementTypeMask    -
    //
    //////////////////////////////////////////////////////////////////////////////
    CPerfMonConcurrentGroup::CPerfMonConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Opens IO Stream for given metric set.
    //     (Enables Timer Mode and opens Counter Stream)
    //
    // Input:
    //     IMetricSet_1_0*      metricSet           - metric set
    //     uint32_t             processId           - PID of the measured app (0 is global context)
    //     uint32_t*            nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t*            sysBufferSize       - (in/out) requested/set Sys Buffer size in bytes
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* sysBufferSize )
    {
        MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( sysBufferSize, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.OpenIoStream( STREAM_TYPE_SYS, *m_device, static_cast<CMetricSet*>( metricSet ), m_params_1_0.SymbolName, processId, nsTimerPeriod, sysBufferSize, &m_streamEventHandle );
        if( ret != CC_OK )
        {
            return ret;
        }

        m_ioMetricSet = static_cast<CMetricSet*>( metricSet );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    //     data was read.
    //
    // Input:
    //     uint32_t            reportCount - (in/out) requested number of reports to read / reports read from the stream
    //     char*               reportData  - (out) pointer to the read data
    //     uint32_t            readFlags   - read flags (see TIoReadFlag enum), 0 is ok
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
    {
        MD_CHECK_PTR_RET( reportData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( reportCount, CC_ERROR_INVALID_PARAMETER );
        if( m_ioMetricSet == nullptr )
        {
            *reportCount = 0;
            MD_LOG( LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode                 ret             = CC_OK;
        uint32_t                        frequency       = 0;
        GTDIReadCounterStreamExceptions exceptions      = {};
        CDriverInterface&               driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.ReadIoStream( STREAM_TYPE_SYS, *m_device, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
        if( ret == CC_OK || ret == CC_READ_PENDING )
        {
            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW, exceptions.BufferOverflow, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERRUN, exceptions.BufferOverrun, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW, exceptions.CountersOverflow, &index );

            m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector.size();
        }
        else
        {
            m_params_1_0.IoMeasurementInformationCount = 0;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes IO Stream.
    //     (Closes Counter Stream and disables Timer Mode)
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::CloseIoStream()
    {
        if( m_ioMetricSet == nullptr )
        {
            MD_LOG( LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.CloseIoStream( STREAM_TYPE_SYS, *m_device, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
        if( ret != CC_OK )
        {
            return ret;
        }

        m_ioMetricSet = nullptr;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Method:
    //     WaitForReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     uint32_t     milliseconds   - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPerfMonConcurrentGroup::WaitForReports( uint32_t milliseconds )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        return driverInterface.WaitForIoStreamReports( STREAM_TYPE_SYS, *m_device, milliseconds, m_streamEventHandle );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CMetricSet constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device             -
    //     CConcurrentGroup * concurrentGroup  -
    //     const char * symbolicName           -
    //     const char * shortName              -
    //     uint32_t     apiMask                -
    //     TMetricCategory category            -
    //     uint32_t     snapshotReportSize     -
    //     uint32_t     deltaReportSize        -
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet::CMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, uint32_t platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : m_metricsVector()
        , m_informationVector()
        , m_complementarySetsVector()
        , m_startRegsVector()
        , m_startRegsQueryVector()
        , m_startRegisterSetList()
        , m_otherMetricsVector()
        , m_otherInformationVector()
        , m_filteredMetricsVector()
        , m_filteredInformationVector()
        , m_reportType( reportType )
        , m_device( device )
        , m_concurrentGroup( concurrentGroup )
        , m_isCustom( isCustom )
        , m_isReadRegsCfgSet( false )
        , m_availabilityEquation( nullptr )
        , m_metricsCalculator( new( std::nothrow ) CMetricsCalculator( m_device ) )
    {
        m_params_1_0.SymbolName      = GetCopiedCString( symbolicName );
        m_params_1_0.ShortName       = GetCopiedCString( shortName );
        m_params_1_0.ApiMask         = apiMask;
        m_params_1_0.CategoryMask    = category;
        m_params_1_0.PlatformMask    = platformMask;
        m_params_1_0.GtMask          = gtMask;
        m_params_1_0.RawReportSize   = snapshotReportSize; // as in HW
        m_params_1_0.QueryReportSize = deltaReportSize;    // as in Query API

        m_params_1_0.MetricsCount           = 0;
        m_params_1_0.InformationCount       = 0;
        m_params_1_0.ComplementarySetsCount = 0;

        m_params_1_0.AvailabilityEquation = "";

        memset( &m_params_1_0.ApiSpecificId, 0, sizeof( m_params_1_0.ApiSpecificId ) );

        m_pmRegsConfigInfo.OaConfigHandle = 0;
        m_pmRegsConfigInfo.GpConfigHandle = 0;
        m_pmRegsConfigInfo.RrConfigHandle = 0;
        m_pmRegsConfigInfo.IsQueryConfig  = 0;

        m_metricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_informationVector.reserve( INFORMATION_VECTOR_INCREASE );
        m_complementarySetsVector.reserve( COMPLEMENTARY_SETS_VECTOR_INCREASE );
        m_startRegsVector.reserve( START_REGS_VECTOR_INCREASE );
        m_startRegsQueryVector.reserve( START_REGS_QUERY_VECTOR_INCREASE );
        m_otherMetricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_otherInformationVector.reserve( INFORMATION_VECTOR_INCREASE );
        m_filteredMetricsVector.reserve( METRICS_VECTOR_INCREASE );
        m_filteredInformationVector.reserve( INFORMATION_VECTOR_INCREASE );

        // Set 'current' variables and mark 'filtered' params as uninitialized
        UseApiFilteredVariables( false );
        m_filteredParams.ApiMask              = 0;
        m_filteredParams.GtMask               = 0;
        m_filteredParams.AvailabilityEquation = nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet destructor
    //
    // Method:
    //     ~CMetricSet
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet::~CMetricSet()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.D3D1XDevDependentName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.OGLQueryIntelName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.AvailabilityEquation );

        ClearCachedMetricsAndInformation();
        ClearVector( m_filteredMetricsVector );
        ClearVector( m_filteredInformationVector );

        ClearVector( m_metricsVector );
        ClearVector( m_informationVector );
        ClearVector( m_complementarySetsVector );

        // Clearing m_startRegsVector and m_startRegsQueryVector is
        // not neccesary as they share pointers with m_startRegisterSetList

        ClearList( m_startRegisterSetList );

        ClearVector( m_otherMetricsVector );
        ClearVector( m_otherInformationVector );
        MD_SAFE_DELETE( m_metricsCalculator );

        MD_SAFE_DELETE( m_availabilityEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns metric set params
    //
    // Output:
    //     TMetricSetParams_1_11*  - metric set params
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricSetParams_1_11* CMetricSet::GetParams( void )
    {
        return m_currentParams;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetMetric
    //
    // Description:
    //     Returns the chosen metric or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of a metric
    //
    // Output:
    //     IMetric_1_0*        - chosen metric or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetric_1_0* CMetricSet::GetMetric( uint32_t index )
    {
        MD_CHECK_PTR_RET( m_currentMetricsVector, nullptr );

        if( index < m_currentMetricsVector->size() )
        {
            return static_cast<IMetric_1_0*>( ( *m_currentMetricsVector )[index] );
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetInformation
    //
    // Description:
    //     Returns the chosen information or nullptr if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of an information
    //
    // Output:
    //     IInformation_1_0*   - chosen information or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* CMetricSet::GetInformation( uint32_t index )
    {
        MD_CHECK_PTR_RET( m_currentInformationVector, nullptr );

        if( m_isFiltered )
        {
            if( index < m_currentInformationVector->size() )
            {
                return static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index] );
            }
            return nullptr;
        }

        // if index is in Concurrent Group indexes bounds ( 0..N, N = amount of infs in concurrent group )
        if( index < m_concurrentGroup->GetInformationCount() )
        {
            // return information from Concurrent Group
            return m_concurrentGroup->GetInformation( index );
        }
        else
        {
            if( index < m_currentInformationVector->size() + m_concurrentGroup->GetInformationCount() )
            {
                return static_cast<IInformation_1_0*>( ( *m_currentInformationVector )[index - m_concurrentGroup->GetInformationCount()] );
            }
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetComplementaryMetricSet
    //
    // Description:
    //     Returns the chosen complementary metric set or null if index doesn't exist.
    //
    // Input:
    //     uint32_t     index  - index of a complementary set
    //
    // Output:
    //     IMetricSet_1_11*     - chosen complementary metric set or null
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSet_1_11* CMetricSet::GetComplementaryMetricSet( uint32_t index )
    {
        if( index < m_complementarySetsVector.size() )
        {
            IMetricSet_1_11* metricSet       = nullptr;
            size_t           stringLength    = strlen( m_complementarySetsVector[index] );
            uint32_t         metricSetsCount = m_concurrentGroup->GetParams()->MetricSetsCount;
            for( uint32_t i = 0; i < metricSetsCount; i++ )
            {
                metricSet = m_concurrentGroup->GetMetricSet( i );
                if( strncmp( metricSet->GetParams()->SymbolName, m_complementarySetsVector[index], stringLength ) == 0 )
                {
                    return metricSet;
                }
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Activate
    //
    // Description:
    //     To enable this configuration before query instance is created or IO stream is opened.
    //     Locks the concurrent group and sends the configuration if lock was successful.
    //
    // Output:
    //     TCompletionCode  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Activate( void )
    {
        return ActivateInternal( true, true );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     Deactivate
    //
    // Description:
    //     Unlocks the concurrent group after query instance is created or IO stream is opened.
    //     Sends 'empty' read regs config if it was previously set.
    //
    // Output:
    //     TCompletionCode  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::Deactivate( void )
    {
        MD_LOG_ENTER();
        TCompletionCode ret = CC_OK;
        if( m_isReadRegsCfgSet )
        {
            CDriverInterface& driverInterface  = m_device->GetDriverInterface();
            TRegister         emptyRrConfig    = { 0, 0, REGISTER_TYPE_MMIO };
            TRegister*        emptyRrConfigPtr = &emptyRrConfig; // Because we will need 'array of pointers'

            ret = driverInterface.SendReadRegsConfig( &emptyRrConfigPtr, 1, m_currentParams->ApiMask );
            if( ret == CC_OK )
            {
                // Update PmRegsHandles and reset rrSet flag
                driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
                m_isReadRegsCfgSet = false;
            }
        }

        if( ret == CC_OK )
        {
            ret = m_concurrentGroup->Unlock();
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     MetricGroupNameToId
    //
    // Description:
    //     To get order of group names
    //
    // Output:
    //     uint32_t - group id, METRIC_GROUP_NAME_ID_INVALID if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricSet::MetricGroupNameToId( const char* groupName )
    {
        MD_CHECK_PTR_RET( groupName, METRIC_GROUP_NAME_ID_INVALID );

        uint32_t groupId = 0, tokenNo = 0;
        char *   token = nullptr, *tokenNext = nullptr, *groupNameCopy = nullptr;

        groupNameCopy = GetCopiedCString( groupName );
        MD_CHECK_PTR_RET( groupNameCopy, METRIC_GROUP_NAME_ID_INVALID );

        token = iu_strtok_s( groupNameCopy, "/", &tokenNext );
        while( token != nullptr )
        {
            uint32_t partialGroupId = GetPartialGroupId( token, tokenNo++ );
            if( partialGroupId == METRIC_GROUP_NAME_ID_INVALID )
            {
                partialGroupId = METRIC_GROUP_NAME_ID_GPU; // Use default group name ID
            }

            groupId += partialGroupId;
            token = iu_strtok_s( nullptr, "/", &tokenNext );
        }

        MD_SAFE_DELETE_ARRAY( groupNameCopy );
        return groupId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetPartialGroupId
    //
    // Description:
    //     Returns group id based on a given depth and group name.
    //
    // Input:
    //     char*        groupName - group name at depth
    //     uint32_t     level     - group name level, e.g. A\B\C - A has level 0, B has level 1
    //
    // Output:
    //     uint32_t    - group id, METRIC_GROUP_NAME_ID_INVALID if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricSet::GetPartialGroupId( char* groupName, uint32_t level )
    {
        MD_ASSERT( groupName != nullptr );

        if( level > MD_METRIC_GROUP_NAME_LEVEL_MAX )
        {
            MD_LOG( LOG_ERROR, "maximum group name level allowed is %u", MD_METRIC_GROUP_NAME_LEVEL_MAX );
            return METRIC_GROUP_NAME_ID_INVALID;
        }

        uint32_t groupId      = METRIC_GROUP_NAME_ID_INVALID;
        uint32_t currentLevel = 1 << level;
        uint32_t shift        = ( MD_METRIC_GROUP_NAME_LEVEL_MAX - level ) * MD_BYTE;
        uint32_t pairCount    = sizeof( GroupNamePairs ) / sizeof( TMetricGroupNameIdPair );

        for( uint32_t i = 0; i < pairCount; i++ )
        {
            if( ( GroupNamePairs[i].LevelMask & currentLevel ) && ( strcmp( groupName, GroupNamePairs[i].Name ) == 0 ) )
            {
                groupId = GroupNamePairs[i].Id << shift;
                break;
            }
        }

        if( groupId == METRIC_GROUP_NAME_ID_INVALID )
        {
            MD_LOG( LOG_ERROR, "invalid group name: %s at level: %u", groupName, level );
        }
        return groupId;
    }

//////////////////////////////////////////////////////////////////////////////
// Helper macro to get CustomMetricParams
//////////////////////////////////////////////////////////////////////////////
#define MD_CUSTOM_METRIC_PARAMS( params, version ) ( params )->CustomMetricParams_##version

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddCustomMetric
    //
    // Description:
    //     Adds the custom metric with the given parameters.
    //
    // Input:
    //     TAddCustomMetricParams * params - params
    //
    // Output:
    //     IMetricLatest* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CMetricSet::AddCustomMetric( TAddCustomMetricParams* params )
    {
        if( params == nullptr )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
            return nullptr;
        }

        if( params->Type != METRIC_CUSTOM_PARAMS_1_0 )
        {
            MD_LOG( LOG_ERROR, "Unsupported TAddCustomMetricParams Type: %u", params->Type );
            return nullptr;
        }

        const char*       symbolName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SymbolName;
        const char*       shortName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ShortName;
        const char*       groupName             = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).GroupName;
        const char*       longName              = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LongName;
        const char*       dxToOglAlias          = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DxToOglAlias;
        uint32_t          usageFlagsMask        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).UsageFlagsMask;
        uint32_t          apiMask               = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ApiMask;
        TMetricResultType resultType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).ResultType;
        const char*       resultUnits           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricResultUnits;
        TMetricType       metricType            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MetricType;
        int64_t           loWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).LowWatermark;
        int64_t           hiWatermark           = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HighWatermark;
        THwUnitType       hwType                = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).HwUnitType;
        const char*       ioReadEquation        = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).IoReadEquation;
        const char*       deltaFunction         = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).DeltaFunction;
        const char*       queryReadEquation     = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).QueryReadEquation;
        const char*       normalizationEquation = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).NormEquation;
        const char*       maxValueEquation      = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).MaxValueEquation;
        const char*       signalName            = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).SignalName;
        const char*       availabilityEquation  = MD_CUSTOM_METRIC_PARAMS( params, 1_0 ).AvailabilityEquation;

        MD_LOG_ENTER();

        if( !AreMetricParamsValid(
                symbolName, shortName, longName, groupName, metricType, resultType, resultUnits, hwType, dxToOglAlias ) )
        {
            MD_LOG( LOG_ERROR, "invalid custom metric parameters" );
            return nullptr;
        }
        if( IsMetricAlreadyAdded( symbolName ) )
        {
            MD_LOG( LOG_ERROR, "metric already added: %s", symbolName );
            return nullptr;
        }

        uint32_t groupId = MetricGroupNameToId( groupName );

        CMetric* metric = new( std::nothrow ) CMetric( m_device, m_metricsVector.size(), symbolName, shortName, longName, groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, resultUnits, loWatermark, hiWatermark, hwType, dxToOglAlias, signalName, true );
        MD_CHECK_PTR_RET( metric, nullptr );

        if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK || metric->SetSnapshotReportReadEquation( ioReadEquation ) != CC_OK || metric->SetDeltaReportReadEquation( queryReadEquation ) != CC_OK || metric->SetNormalizationEquation( normalizationEquation ) != CC_OK || metric->SetSnapshotReportDeltaFunction( deltaFunction ) != CC_OK || metric->SetMaxValueEquation( maxValueEquation ) != CC_OK )
        {
            MD_LOG( LOG_ERROR, "error setting custom metric equations" );
            MD_SAFE_DELETE( metric );
            return nullptr;
        }

        m_metricsVector.push_back( metric );
        m_params_1_0.MetricsCount = m_metricsVector.size();
        m_isCustom                = true;

        // Refresh cached filtered metrics
        RefreshCachedMetricsAndInformation();

        MD_LOG( LOG_DEBUG, "Custom metric %s is added", symbolName );
        MD_LOG_EXIT();
        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddCustomMetric
    //
    // Description:
    //     Adds custom metric with given parameters.
    //
    // Input:
    //     const char * symbolName                  -
    //     const char * shortName                   -
    //     const char * groupName                   -
    //     const char * longName                    -
    //     const char * dxToOglAlias                -
    //     uint32_t     usageFlagsMask              -
    //     uint32_t     apiMask                     -
    //     TMetricResultType resultType             -
    //     const char * resultUnits                 -
    //     TMetricType metricType                   -
    //     int64_t *   loWatermark                  -
    //     int64_t *   hiWatermark                  -
    //     THwUnitType hwType                       -
    //     const char * ioReadEquation              -
    //     const char * deltaFunction               -
    //     const char * queryReadEquation           -
    //     const char * normalizationEquation       -
    //     const char * maxValueEquation            -
    //     const char * signalName                  -
    //
    // Output:
    //     IMetric_1_0* - newly created metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetric_1_0* CMetricSet::AddCustomMetric( const char* symbolName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName )
    {
        TAddCustomMetricParams params = {
            METRIC_CUSTOM_PARAMS_1_0,
        };
        params.CustomMetricParams_1_0.SymbolName           = symbolName;
        params.CustomMetricParams_1_0.ShortName            = shortName;
        params.CustomMetricParams_1_0.GroupName            = groupName;
        params.CustomMetricParams_1_0.LongName             = longName;
        params.CustomMetricParams_1_0.DxToOglAlias         = dxToOglAlias;
        params.CustomMetricParams_1_0.UsageFlagsMask       = usageFlagsMask;
        params.CustomMetricParams_1_0.ApiMask              = apiMask;
        params.CustomMetricParams_1_0.ResultType           = resultType;
        params.CustomMetricParams_1_0.MetricResultUnits    = resultUnits;
        params.CustomMetricParams_1_0.MetricType           = metricType;
        params.CustomMetricParams_1_0.LowWatermark         = loWatermark;
        params.CustomMetricParams_1_0.HighWatermark        = hiWatermark;
        params.CustomMetricParams_1_0.HwUnitType           = hwType;
        params.CustomMetricParams_1_0.IoReadEquation       = ioReadEquation;
        params.CustomMetricParams_1_0.QueryReadEquation    = queryReadEquation;
        params.CustomMetricParams_1_0.DeltaFunction        = deltaFunction;
        params.CustomMetricParams_1_0.NormEquation         = normalizationEquation;
        params.CustomMetricParams_1_0.MaxValueEquation     = maxValueEquation;
        params.CustomMetricParams_1_0.SignalName           = signalName;
        params.CustomMetricParams_1_0.AvailabilityEquation = "1";

        return AddCustomMetric( &params );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiSpecificId
    //
    // Description:
    //     Sets the API specific ids in the metric set params.
    //
    // Input:
    //     const char * dx9        -
    //     uint32_t     dx10       -
    //     uint32_t     ogl        -
    //     uint32_t     ocl        -
    //     uint32_t     hwConfig   -
    //
    // Output:
    //     TCompletionCode         - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiSpecificId( const char* dx9Fourcc, uint32_t dx9QueryId, uint32_t dx10Counter, uint32_t oglQuery, uint32_t ocl, uint32_t hwConfig, const char* dx10CounterName, uint32_t dx10QueryId, const char* oglQueryName, uint32_t oglQueryARB )
    {
        m_params_1_0.ApiSpecificId.D3D9QueryId           = dx9QueryId;
        m_params_1_0.ApiSpecificId.D3D9Fourcc            = dx9Fourcc ? ( dx9Fourcc[0] ) + ( dx9Fourcc[1] << 8 ) + ( dx9Fourcc[2] << 16 ) + ( dx9Fourcc[3] << 24 ) : 0;
        m_params_1_0.ApiSpecificId.D3D1XQueryId          = dx10QueryId;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentId   = dx10Counter;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( dx10CounterName );
        m_params_1_0.ApiSpecificId.OGLQueryIntelId       = oglQuery;
        m_params_1_0.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( oglQueryName );
        m_params_1_0.ApiSpecificId.OGLQueryARBTargetId   = oglQueryARB;
        m_params_1_0.ApiSpecificId.OCL                   = ocl;
        m_params_1_0.ApiSpecificId.HwConfigId            = hwConfig;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiSpecificId
    //
    // Description:
    //     Sets the API specific ids in the metric set params.
    //
    // Input:
    //     TApiSpecificId_1_0 apiSepcificId    - API specific id struct to set
    //
    // Output:
    //     TCompletionCode                     - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiSpecificId( TApiSpecificId_1_0 apiSpecificId )
    {
        m_params_1_0.ApiSpecificId                       = apiSpecificId;
        m_params_1_0.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( apiSpecificId.D3D1XDevDependentName );
        m_params_1_0.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( apiSpecificId.OGLQueryIntelName );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddMetric
    //
    // Description:
    //     Adds a new metric to the metric set. Null if failed.
    //
    // Input:
    //     const char * symbolName             -
    //     const char * shortName              -
    //     const char * longName               -
    //     const char * groupName              -
    //     uint32_t     groupId                -
    //     uint32_t     usageFlagsMask         -
    //     uint32_t     apiMask                -
    //     TMetricType  metricType             -
    //     TMetricResultType resultType        -
    //     const char * units                  -
    //     const char * maxValue               -
    //     int64_t loWatermark                 -
    //     int64_t hiWatermark                 -
    //     THwUnitType hwType                  -
    //     const char * availabilityEquation   -
    //     const char* alias                   -
    //     const char* signalName              -
    //     uint32_t metricXmlId                -
    //     bool isCustom                       -
    //
    // Output:
    //     CMetric*  - pointer to the newly created metric.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric* CMetricSet::AddMetric( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* availabilityEquation, const char* alias, const char* signalName, uint32_t metricXmlId, bool isCustom /*= false*/ )
    {
        if( groupName == nullptr )
        {
            groupName = "";
        }

        CMetric* metric = new( std::nothrow ) CMetric( m_device, metricXmlId, symbolName, shortName, longName, groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, units, loWatermark, hiWatermark, hwType, alias, signalName, isCustom );
        MD_CHECK_PTR_RET( metric, nullptr );

        if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( metric );
            return nullptr;
        }

        if( m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            if( IsMetricAlreadyAdded( symbolName ) )
            {
                m_otherMetricsVector.push_back( metric );
            }
            else
            {
                uint32_t count = m_metricsVector.size();
                metric->SetIdInSetParam( count );
                m_metricsVector.push_back( metric );
                m_params_1_0.MetricsCount = count + 1;
            }
        }
        else
        {
            m_otherMetricsVector.push_back( metric );
        }

        if( isCustom )
        {
            m_isCustom = true;
        }

        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddMetric
    //
    // Description:
    //     Adds a new metric to the metric set. nullptr if failed.
    //
    // Input:
    //     CMetric* metric - metric to add
    //
    // Output:
    //     CMetric*        - added metric, nullptr if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric* CMetricSet::AddMetric( CMetric* metric )
    {
        MD_CHECK_PTR_RET( metric, nullptr );

        if( IsMetricAlreadyAdded( metric->GetParams()->SymbolName ) )
        {
            m_otherMetricsVector.push_back( metric );
        }
        else
        {
            m_metricsVector.push_back( metric );
            m_params_1_0.MetricsCount = m_metricsVector.size();
        }

        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. Null if failed.
    //
    // Input:
    //     const char * symbolicName           -
    //     const char * shortName              -
    //     const char * longName               -
    //     const char * groupName              -
    //     uint32_t     apiMask                -
    //     TInformationType informationType    -
    //     const char*  availabilityEquation   -
    //     uint32_t informationXmlId           -
    //
    // Output:
    //     CInformation*   - pointer to the newly created information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CMetricSet::AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId )
    {
        CInformation* information = new( std::nothrow ) CInformation( m_device, informationXmlId, symbolName, shortName, longName, groupName, apiMask, informationType, informationUnits );
        MD_CHECK_PTR_RET( information, nullptr );

        if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( information );
            return nullptr;
        }

        if( m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            uint32_t count = m_informationVector.size();
            information->SetIdInSetParam( count );
            m_informationVector.push_back( information );
            m_params_1_0.InformationCount++;
        }
        else
        {
            m_otherInformationVector.push_back( information );
        }

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. Null if failed.
    //
    // Input:
    //     const char * symbolicName           -
    //     const char * shortName              -
    //     const char * longName               -
    //     const char * groupName              -
    //     uint32_t     apiMask                -
    //     TInformationType informationType    -
    //     const char*  availabilityEquation   -
    //     uint32_t informationXmlId           -
    //
    // Output:
    //     CInformation*   - pointer to the newly created information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CConcurrentGroup::AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId )
    {
        CInformation* information = new( std::nothrow ) CInformation( m_device, informationXmlId, symbolName, shortName, longName, groupName, apiMask, informationType, informationUnits );
        MD_CHECK_PTR_RET( information, nullptr );

        if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( information );
            return nullptr;
        }

        if( m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            uint32_t count = m_informationVector.size();
            information->SetIdInSetParam( count );
            m_informationVector.push_back( information );
            m_informationCount = count + 1;
        }
        else
        {
            m_otherInformationVector.push_back( information );
        }

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. nullptr if failed.
    //
    // Input:
    //     CInformation* information  - information to add
    //
    // Output:
    //     CInformation*              - pointer to the added information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CMetricSet::AddInformation( CInformation* information )
    {
        MD_CHECK_PTR_RET( information, nullptr );

        m_informationVector.push_back( information );
        m_params_1_0.InformationCount = m_informationVector.size() + m_concurrentGroup->GetInformationCount();

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddInformation
    //
    // Description:
    //     Adds a new information to the metric set. nullptr if failed.
    //
    // Input:
    //     CInformation* information  - information to add
    //
    // Output:
    //     CInformation*              - pointer to the added information
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* CConcurrentGroup::AddInformation( CInformation* information )
    {
        m_informationVector.push_back( information );
        m_informationCount = m_informationVector.size();

        return information;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddComplementaryMetricSet
    //
    // Description:
    //     Adds a complementary metric set by name.
    //
    // Input:
    //     const char * complementaryMetricSetSymbolicName - complementary metric set name to add
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddComplementaryMetricSet( const char* complementaryMetricSetSymbolicName )
    {
        MD_CHECK_PTR_RET( complementaryMetricSetSymbolicName, CC_ERROR_INVALID_PARAMETER );

        if( strcmp( complementaryMetricSetSymbolicName, "" ) == 0 )
        {
            return CC_OK; // 0 is fine condition for "" name
        }

        char* metricSetName = GetCopiedCString( complementaryMetricSetSymbolicName );

        m_complementarySetsVector.push_back( metricSetName );
        m_params_1_0.ComplementarySetsCount = m_complementarySetsVector.size();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddComplementaryMetricSet
    //
    // Description:
    //     Adds multiple complementary metric sets by name.
    //
    // Input:
    //     const char* complementaryMetricSetsList - comma separated list of complementary sets (symbol names)
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddComplementaryMetricSets( const char* complementarySetsList )
    {
        MD_CHECK_PTR_RET( complementarySetsList, CC_ERROR_INVALID_PARAMETER );

        char *token = nullptr, *tokenNext = nullptr, *complementarySets = nullptr;

        complementarySets = GetCopiedCString( complementarySetsList );
        MD_CHECK_PTR_RET( complementarySets, CC_ERROR_NO_MEMORY );

        token = iu_strtok_s( complementarySets, ",", &tokenNext );
        while( token != nullptr )
        {
            if( AddComplementaryMetricSet( token ) != CC_OK )
            {
                MD_LOG( LOG_DEBUG, "error adding complementary metric sets" );
                MD_SAFE_DELETE_ARRAY( complementarySets );
                return CC_ERROR_GENERAL;
            }
            token = iu_strtok_s( nullptr, ",", &tokenNext );
        }
        MD_SAFE_DELETE_ARRAY( complementarySets );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ActivateInternal
    //
    // Description:
    //     To enable this configuration before query instance is created or IO stream is opened.
    //     Locks the concurrent group and sends the configuration if flag was set and the lock was successful.
    //
    // Input:
    //     bool sendConfigFlag      - if true, StartConfigRegs are sent
    //     bool sendQueryConfigFlag - if true, query specific regs are sent too
    //
    // Output:
    //     TCompletionCode           - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::ActivateInternal( bool sendConfigFlag, bool sendQueryConfigFlag )
    {
        MD_LOG_ENTER();
        TCompletionCode retVal = CC_OK;

        retVal = m_concurrentGroup->Lock();
        if( retVal == CC_OK && sendConfigFlag )
        {
            if( SendStartConfiguration( sendQueryConfigFlag ) != CC_OK )
            {
                m_concurrentGroup->Unlock();
                MD_LOG( LOG_DEBUG, "sending start configuration failed" );
                retVal = CC_ERROR_GENERAL;
            }
        }

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddStartConfigRegisterSet
    //
    // Description:
    //     Adds a new empty start config register set to the metric set.
    //
    // Input:
    //     uint32_t     configId             - config id
    //     uint32_t     configPriority       - priority, lower is more important
    //     const char*  availabilityEquation - availability equation (default nullptr - available)
    //     TConfigType  configType           - e.g. COMMON, SNAPSHOT (default COMMON)
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddStartRegisterSet( uint32_t configId, uint32_t configPriority, const char* availabilityEquation /*= nullptr */, TConfigType configType /*= CONFIG_TYPE_COMMON*/ )
    {
        CRegisterSet* registerSet = new( std::nothrow ) CRegisterSet( m_device, configId, configPriority, configType );
        MD_CHECK_PTR_RET( registerSet, CC_ERROR_NO_MEMORY );

        if( registerSet->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
        {
            MD_SAFE_DELETE( registerSet );
            return CC_ERROR_GENERAL;
        }
        m_startRegisterSetList.push_back( registerSet );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AddStartConfigRegister
    //
    // Description:
    //     Adds configuration register to the metric set to send it during Activate method.
    //     It only adds registers to a register set. RefreshConfigRegisters() adds them to
    //     a real configuration which will be sent.
    //
    // Input:
    //     uint32_t      offset - register offset
    //     uint32_t      value  - register value
    //     TRegisterType type   - register type
    //
    // Output:
    //     TCompletionCode      - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::AddStartConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
    {
        CRegisterSet* registerSet = m_startRegisterSetList.size() > 0 ? m_startRegisterSetList.back() : nullptr;
        MD_CHECK_PTR_RET( registerSet, CC_ERROR_GENERAL );

        TRegister* reg = registerSet->AddConfigRegister( offset, value, type );
        MD_CHECK_PTR_RET( reg, CC_ERROR_GENERAL );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     RefreshConfigRegisters
    //
    // Description:
    //     Chooses start registers with the highest priorities and adds them to a configuration.
    //     Only one set with a given ID can be used in the configuration.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::RefreshConfigRegisters()
    {
        uint32_t      id          = 0;
        CRegisterSet* registerSet = nullptr;

        while( GetStartRegSetHiPriority( id++, &registerSet ) )
        {
            if( registerSet )
            {
                // Add registers
                TRegisterSetParams* params = registerSet->GetParams();
                if( params->ConfigType == CONFIG_TYPE_COMMON )
                {
                    registerSet->RegsToVector( m_startRegsVector );
                }
                else if( params->ConfigType == CONFIG_TYPE_QUERY )
                {
                    registerSet->RegsToVector( m_startRegsQueryVector );
                }
                else
                {
                    MD_LOG( LOG_ERROR, "Unknown register method" );
                    return CC_ERROR_GENERAL;
                }
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetRegSetLoIdHiPriority
    //
    // Description:
    //     Iterates through all the start register sets looking for a set with the highest
    //     priority and a given ID. If there's no such registerSet is nullptr. If there's no
    //     sets with the given ID or higher it returns false.
    //
    // Input:
    //     uint32_t       id          - config id to look for
    //     CRegisterSet** registerSet - (out) found register set, nullptr if not found
    //
    // Output:
    //     bool - false if there is no register sets with given id or higher (end of search)
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::GetStartRegSetHiPriority( uint32_t id, CRegisterSet** registerSet )
    {
        MD_CHECK_PTR_RET( registerSet, false );

        bool          ret             = false;
        CRegisterSet* set             = nullptr;
        uint32_t      highestPriority = 0xFFFFFFFF; // Lower is more important

        for( auto& registerSet : m_startRegisterSetList )
        {
            TRegisterSetParams* params = registerSet->GetParams();
            if( params->ConfigId >= id )
            {
                ret = true;
                if( params->ConfigId == id && registerSet->IsAvailable() && params->ConfigPriority < highestPriority )
                {
                    highestPriority = params->ConfigPriority;
                    set             = registerSet;
                }
            }
        }
        *registerSet = set;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetStartConfiguration
    //
    // Description:
    //     Returns common start config registers (without query specific).
    //
    // Input:
    //     uint32_t*     count - (out) registers count
    //
    // Output:
    //     TRegister**         - pointers to the common start config registers
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegister** CMetricSet::GetStartConfiguration( uint32_t* count )
    {
        if( count != nullptr )
        {
            *count = m_startRegsVector.size();
        }
        return m_startRegsVector.data();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SendStartConfiguration
    //
    // Description:
    //     Sends a start configuration to the driver.
    //
    // Input:
    //     bool sendQueryConfigFlag - if true, send also query specific configuration
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SendStartConfiguration( bool sendQueryConfigFlag )
    {
        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        if( CheckSendConfigRequired( sendQueryConfigFlag ) )
        {
            // Prepare register reference lists to sent
            std::vector<TRegister*> pmRegs;
            std::vector<TRegister*> readRegs;
            pmRegs.reserve( START_REGS_VECTOR_INCREASE );
            readRegs.reserve( START_REGS_VECTOR_INCREASE );

            AppendToConfiguration( m_startRegsVector, pmRegs, readRegs );
            if( sendQueryConfigFlag )
            {
                AppendToConfiguration( m_startRegsQueryVector, pmRegs, readRegs );
            }

            // Verify if programming is present
            // "m_startRegisterSetList may be empty for e.g. PipelineStatistics"
            if( ( pmRegs.size() > 0 || readRegs.size() > 0 ) || m_startRegisterSetList.size() == 0 )
            {
                // Send configurations
                ret = driverInterface.SendPmRegsConfig( pmRegs.data(), pmRegs.size(), m_currentParams->ApiMask );
                if( ret == CC_OK && readRegs.size() )
                {
                    ret = driverInterface.SendReadRegsConfig( readRegs.data(), readRegs.size(), m_currentParams->ApiMask );
                }

                if( ret == CC_OK )
                {
                    m_isReadRegsCfgSet = readRegs.size() > 0;

                    m_pmRegsConfigInfo.IsQueryConfig = sendQueryConfigFlag;
                    driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle, &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
                }
            }
            else
            {
                MD_LOG( LOG_ERROR, "Programming missing" );
                ret = CC_ERROR_NOT_SUPPORTED;
            }

            // Do not clear local register vectors to preserve original references
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AppendToConfiguration
    //
    // Description:
    //     Appends register from the source vector to the two destination (PmRegs and ReadRegs)
    //     vectors. It's because read and pm regs are sent using different way.
    //
    // Input:
    //     Vector<TRegister*>& sourceRegs  - source vector for all regs
    //     Vector<TRegister*>& outPmRegs   - dest vector for PmRegs
    //     Vector<TRegister*>& outReadRegs - dest vector for ReadRegs
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::AppendToConfiguration( std::vector<TRegister*>& sourceRegs, std::vector<TRegister*>& outPmRegs, std::vector<TRegister*>& outReadRegs )
    {
        for( auto& sourceRegister : sourceRegs )
        {
            if( sourceRegister->type == REGISTER_TYPE_MMIO )
            {
                outReadRegs.push_back( sourceRegister );
            }
            else
            {
                outPmRegs.push_back( sourceRegister );
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CheckSendConfigRequired
    //
    // Description:
    //     Checks whether the configuration in KMD needs to be updated to be used with
    //     the current metric set.
    //
    // Output:
    //     bool - false if sending is unnecessary
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::CheckSendConfigRequired( bool sendQueryConfigFlag )
    {
        bool              ret             = true;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        // If measurement type didn't change and config handles were checked before
        if( m_pmRegsConfigInfo.IsQueryConfig == sendQueryConfigFlag && ( m_pmRegsConfigInfo.OaConfigHandle != 0 || m_pmRegsConfigInfo.GpConfigHandle != 0 || m_pmRegsConfigInfo.RrConfigHandle != 0 ) )
        {
            uint32_t        oaCfgHandle = 0;
            uint32_t        gpCfgHandle = 0;
            uint32_t        rrCfgHandle = 0;
            TCompletionCode retCode     = CC_OK;

            retCode = driverInterface.GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &oaCfgHandle, &gpCfgHandle, &rrCfgHandle );

            if( retCode == CC_OK && oaCfgHandle == m_pmRegsConfigInfo.OaConfigHandle && gpCfgHandle == m_pmRegsConfigInfo.GpConfigHandle && rrCfgHandle == m_pmRegsConfigInfo.RrConfigHandle )
            {
                ret = false;
                MD_LOG( LOG_DEBUG, "No need to send PmRegs configuration" );
            }
        }

        if( ret )
        {
            MD_LOG( LOG_DEBUG, "Sending PmRegs configuration required" );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetReportType
    //
    // Description:
    //     Returns metric's report type for IO Stream.
    //
    // Output:
    //     TReportType - metric's report type
    //
    //////////////////////////////////////////////////////////////////////////////
    TReportType CMetricSet::GetReportType()
    {
        return m_reportType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     WriteCMetricSetToFile
    //
    // Description:
    //     Writes metric set to file.
    //
    // Input:
    //     FILE* metricFile - handle to metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::WriteCMetricSetToFile( FILE* metricFile )
    {
        uint32_t count = 0;

        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.CategoryMask, sizeof( m_params_1_0.CategoryMask ), 1, metricFile );
        fwrite( &m_params_1_0.RawReportSize, sizeof( m_params_1_0.RawReportSize ), 1, metricFile );
        fwrite( &m_params_1_0.QueryReportSize, sizeof( m_params_1_0.QueryReportSize ), 1, metricFile );
        fwrite( &m_params_1_0.PlatformMask, sizeof( m_params_1_0.PlatformMask ), 1, metricFile );
        fwrite( &m_params_1_0.GtMask, sizeof( m_params_1_0.GtMask ), 1, metricFile );
        WriteEquationToFile( m_availabilityEquation, metricFile );
        fwrite( &m_reportType, sizeof( m_reportType ), 1, metricFile );
        // m_params_1_0.ApiSpecificId (placeholder is not saved!)
        fwrite( &m_params_1_0.ApiSpecificId.D3D9QueryId, sizeof( m_params_1_0.ApiSpecificId.D3D9QueryId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D9Fourcc, sizeof( m_params_1_0.ApiSpecificId.D3D9Fourcc ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D1XQueryId, sizeof( m_params_1_0.ApiSpecificId.D3D1XQueryId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.D3D1XDevDependentId, sizeof( m_params_1_0.ApiSpecificId.D3D1XDevDependentId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.ApiSpecificId.D3D1XDevDependentName, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.OGLQueryIntelId, sizeof( m_params_1_0.ApiSpecificId.OGLQueryIntelId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.ApiSpecificId.OGLQueryIntelName, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.OGLQueryARBTargetId, sizeof( m_params_1_0.ApiSpecificId.OGLQueryARBTargetId ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.OCL, sizeof( m_params_1_0.ApiSpecificId.OCL ), 1, metricFile );
        fwrite( &m_params_1_0.ApiSpecificId.HwConfigId, sizeof( m_params_1_0.ApiSpecificId.HwConfigId ), 1, metricFile );

        // m_metricsVector & m_otherMetricsVector
        count = m_metricsVector.size() + m_otherMetricsVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        uint32_t i = 0;
        uint32_t j = 0;
        while( i < m_metricsVector.size() || j < m_otherMetricsVector.size() )
        {
            // Define which vector is not finished and write remaining available metrics
            if( i == m_metricsVector.size() )
            {
                for( uint32_t k = j; k < m_otherMetricsVector.size(); k++ )
                {
                    m_otherMetricsVector[k]->WriteCMetricToFile( metricFile );
                }
                break;
            }
            if( j == m_otherMetricsVector.size() )
            {
                for( uint32_t k = i; k < m_metricsVector.size(); k++ )
                {
                    m_metricsVector[k]->WriteCMetricToFile( metricFile );
                }
                break;
            }

            // Write in the correct order
            if( m_metricsVector[i]->m_id < m_otherMetricsVector[j]->m_id )
            {
                m_metricsVector[i]->WriteCMetricToFile( metricFile );
                i++;
            }
            else
            {
                m_otherMetricsVector[j]->WriteCMetricToFile( metricFile );
                j++;
            }
        }

        // m_informationVector & m_otherInformationVector
        count = m_informationVector.size() + m_otherInformationVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        i = 0;
        j = 0;
        while( i < m_informationVector.size() || j < m_otherInformationVector.size() )
        {
            // Define which vector is not finished and write remaining available informations
            if( i == m_informationVector.size() )
            {
                for( uint32_t k = j; k < m_otherInformationVector.size(); k++ )
                {
                    m_otherInformationVector[k]->WriteCInformationToFile( metricFile );
                }
                break;
            }
            if( j == m_otherInformationVector.size() )
            {
                for( uint32_t k = i; k < m_informationVector.size(); k++ )
                {
                    m_informationVector[k]->WriteCInformationToFile( metricFile );
                }
                break;
            }

            // Write in the correct order
            if( m_informationVector[i]->m_id < m_otherInformationVector[j]->m_id )
            {
                m_informationVector[i++]->WriteCInformationToFile( metricFile );
            }
            else
            {
                m_otherInformationVector[j++]->WriteCInformationToFile( metricFile );
            }
        }

        // m_startRegisterSetList
        count = m_startRegisterSetList.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        for( auto& registerSet : m_startRegisterSetList )
        {
            registerSet->WriteCRegisterSetToFile( metricFile );
        }

        // m_stopRegisterSetList - remains to be backward compatible, count is always 0
        count = 0;
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );

        // m_complementarySetsVector
        count = m_complementarySetsVector.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );
        for( i = 0; i < count; i++ )
        {
            WriteCStringToFile( m_complementarySetsVector[i], metricFile );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InheritFromMetricSet
    //
    // Description:
    //     Inherits metrics with signal name containing specified string and all the information from
    //     the reference metric set. When signalName is nullptr copy all the metrics.
    //
    // Input:
    //     CMetricSet* referenceMetricSet   - metric set to be copied
    //     const char* signalName           - signal name
    //     bool        copyInformationOnly  - Inherit only informations
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::InheritFromMetricSet( CMetricSet* referenceMetricSet, const char* signalName, bool copyInformationOnly )
    {
        MD_CHECK_PTR_RET( referenceMetricSet, CC_ERROR_INVALID_PARAMETER );

        CMetric*      metric               = nullptr;
        CMetric*      referenceMetric      = nullptr;
        CInformation* information          = nullptr;
        CInformation* referenceInformation = nullptr;
        const char*   metricSignalName     = nullptr;
        uint32_t      count                = 0;

        // Copy metrics with signal name containing signalName
        if( !copyInformationOnly )
        {
            count = referenceMetricSet->GetParams()->MetricsCount;
            for( uint32_t i = 0; i < count; i++ )
            {
                referenceMetric = static_cast<CMetric*>( referenceMetricSet->GetMetric( i ) );
                if( referenceMetric == nullptr )
                {
                    MD_ASSERT( false );
                    return CC_ERROR_GENERAL;
                }
                metricSignalName = referenceMetric->GetSignalName();
                if( signalName == nullptr || ( metricSignalName != nullptr && strstr( metricSignalName, signalName ) != nullptr ) )
                {
                    metric = new( std::nothrow ) CMetric( *referenceMetric );
                    if( !metric )
                    {
                        MD_LOG( LOG_DEBUG, "error copying metrics" );
                        return CC_ERROR_GENERAL;
                    }
                    AddMetric( metric );
                }
            }
        }

        // Copy all the information
        count = referenceMetricSet->GetParams()->InformationCount;
        for( uint32_t i = 0; i < count; i++ )
        {
            referenceInformation = static_cast<CInformation*>( referenceMetricSet->GetInformation( i ) );
            if( referenceInformation == nullptr )
            {
                MD_ASSERT( false );
                return CC_ERROR_GENERAL;
            }
            information = new( std::nothrow ) CInformation( *referenceInformation );
            if( !information )
            {
                MD_LOG( LOG_DEBUG, "error copying information" );
                return CC_ERROR_GENERAL;
            }
            AddInformation( information );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsMetricAlreadyAdded
    //
    // Description:
    //     Checks if metric of the given name is already added to the metrics set.
    //
    // Input:
    //     const char * symbolicName   - symbolic name of a metric to check
    //
    // Output:
    //     bool                        - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsMetricAlreadyAdded( const char* symbolName )
    {
        MD_CHECK_PTR_RET( symbolName, false );

        for( auto& metric : m_metricsVector )
        {
            if( metric && ( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 ) )
            {
                return true;
            }
        }

        for( auto& metric : m_otherMetricsVector )
        {
            if( strcmp( symbolName, metric->GetParams()->SymbolName ) == 0 )
            {
                return true;
            }
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsCustom
    //
    // Description:
    //     True if this is a custom Metric Set or default with custom metrics added.
    //
    // Output:
    //     bool - true if custom
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsCustom()
    {
        return m_isCustom;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetApiFiltering
    //
    // Description:
    //     Sets filtering by the given API mask. After enabling the set will contain only
    //     metrics and information available for the given API.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Output:
    //     TCompletionCode - *CC_OK* mease succcess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetApiFiltering( uint32_t apiMask )
    {
        MD_LOG_ENTER();

        if( !IsApiFilteringMaskValid( apiMask ) )
        {
            MD_LOG( LOG_ERROR, "error: invalid filtering API mask" );
            MD_LOG_EXIT();
            return CC_ERROR_INVALID_PARAMETER;
        }

        if( apiMask == 0 || apiMask == API_TYPE_ALL )
        {
            // Disable API filtering
            MD_LOG( LOG_INFO, "disabling API filtering, apiMask: %u", apiMask );
            EnableApiFiltering( apiMask, false );
        }
        else
        {
            // Enable API filtering
            MD_LOG( LOG_INFO, "enabling API filtering, apiMask: %u", apiMask );
            EnableApiFiltering( apiMask, true );
        }

        MD_LOG_EXIT();
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsApiFilteringMaskValid
    //
    // Description:
    //     Validates API mask used in SetApiFiltering method.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Output:
    //     bool - true if valid, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsApiFilteringMaskValid( uint32_t apiMask )
    {
        bool     ret        = true;
        uint32_t streamMask = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;

        if( apiMask == 0 || apiMask == API_TYPE_ALL )
        {
            ret = true;
        }
        // Do not allow mixing stream and query metrics
        else if( ( apiMask & streamMask ) && ( apiMask & ~streamMask ) )
        {
            MD_LOG( LOG_DEBUG, "error: IoStream and Query api mask mixed, apiMask: %u", apiMask );
            ret = false;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricSet
    //
    // Method:
    //     EnableApiFiltering
    //
    // Description:
    //     Enables or disables API filtering for the current metric set.
    //     IoStream and Query measurements MUST NOT be mixed.
    //
    // Input:
    //     uint32_t     apiMask - API mask for filtering
    //     bool         enable  - if true enable, if false disable
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::EnableApiFiltering( uint32_t apiMask, bool enable )
    {
        MD_LOG_ENTER();
        if( !enable )
        {
            UseApiFilteredVariables( false );
        }
        else
        {
            // Used cached metrics if possible
            if( apiMask == m_filteredParams.ApiMask )
            {
                MD_LOG( LOG_DEBUG, "using cached metrics for API filtering, apiMask: %u", apiMask );
            }
            else
            {
                // Copy (shallow) params, then modify apiMask
                iu_memcpy_s( &m_filteredParams, sizeof( m_filteredParams ), &m_params_1_0, sizeof( m_params_1_0 ) );
                m_filteredParams.ApiMask = apiMask;

                // Cache and modify counts in params
                RefreshCachedMetricsAndInformation();
            }

            UseApiFilteredVariables( true );
        }

        UpdateMetricIndicesInEquations();

        MD_LOG( LOG_DEBUG, "API filtering %s", m_isFiltered ? "enabled" : "disabled" );
        MD_LOG_EXIT();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricSet
    //
    // Method:
    //     UpdateMetricIndicesInEquations
    //
    // Description:
    //     Sets internal indices values depending on whether the symbol name was found
    //     in a metric set.
    //     These are later used in calculating the normalization equation.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::UpdateMetricIndicesInEquations()
    {
        std::unordered_map<std::string, uint32_t> metricsIndexMap( GetParams()->MetricsCount );

        // Update metric indices
        for( uint32_t i = 0; i < GetParams()->MetricsCount; i++ )
        {
            IMetric_1_0* metric = GetMetric( i );

            if( metric )
            {
                metricsIndexMap[metric->GetParams()->SymbolName] = i;

                if( metric->GetParams()->NormEquation )
                {
                    // Get an equation
                    IEquation_1_0* equation = metric->GetParams()->NormEquation;

                    // Metrics equation can use only preceding metrics' values
                    for( uint32_t j = 0; j < equation->GetEquationElementsCount(); j++ )
                    {
                        CEquationElementInternal* internalElement = (CEquationElementInternal*) equation->GetEquationElement( j );

                        if( internalElement->Element_1_0.Type == EQUATION_ELEM_LOCAL_COUNTER_SYMBOL || internalElement->Element_1_0.Type == EQUATION_ELEM_LOCAL_METRIC_SYMBOL )
                        {
                            // Find if symbol name is in the index map
                            const auto foundMetric = metricsIndexMap.find( internalElement->Element_1_0.SymbolName );

                            // Check for the results
                            if( foundMetric != metricsIndexMap.end() )
                            {
                                internalElement->MetricIndexInternal = foundMetric->second;
                            }
                            else
                            {
                                internalElement->MetricIndexInternal = -1;
                            }
                        }
                    }
                }
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     UseApiFilteredVariables
    //
    // Description:
    //     Swaps currently used variables in such methods as GetParams, GetMetric etc. to
    //     filtered or non-filtered ones.
    //
    // Input:
    //     bool enable - if true change to filtered
    //                   if false change to non-filtered
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::UseApiFilteredVariables( bool enable )
    {
        if( enable )
        {
            m_currentParams            = &m_filteredParams;
            m_currentMetricsVector     = &m_filteredMetricsVector;
            m_currentInformationVector = &m_filteredInformationVector;
            m_isFiltered               = true;
        }
        else
        {
            m_currentParams            = &m_params_1_0;
            m_currentMetricsVector     = &m_metricsVector;
            m_currentInformationVector = &m_informationVector;
            m_isFiltered               = false;
        }

        MD_LOG( LOG_DEBUG, "use API filtered variables: %s", enable ? "TRUE" : "FALSE" );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CacheMetricsAndInformation
    //
    // Description:
    //     Clears cached metrics and information, then updates them using the whole
    //     MetricSet and API mask stored in filtered params.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::RefreshCachedMetricsAndInformation()
    {
        if( m_filteredParams.ApiMask == 0 )
        {
            // Filtering uninitialized, nothing to do
            return;
        }

        // Do not use API filtered variables - need to look through all metrics/information
        bool filteringEnabled = m_isFiltered;
        if( filteringEnabled )
        {
            UseApiFilteredVariables( false );
        }

        ClearCachedMetricsAndInformation();

        // Cache metrics
        for( uint32_t i = 0, j = 0; i < m_params_1_0.MetricsCount; i++ )
        {
            IMetric_1_0* metric = GetMetric( i );
            if( metric && ( metric->GetParams()->ApiMask & m_filteredParams.ApiMask ) > 0 )
            {
                CMetric* filteredMetric = static_cast<CMetric*>( metric );
                filteredMetric->SetIdInSetParam( j++ );

                m_filteredMetricsVector.push_back( filteredMetric );
            }
        }

        // Cache information
        for( uint32_t i = 0, j = 0; i < m_params_1_0.InformationCount; i++ )
        {
            IInformation_1_0* information = GetInformation( i );
            if( information && ( information->GetParams()->ApiMask & m_filteredParams.ApiMask ) > 0 )
            {
                CInformation* filteredInformation = static_cast<CInformation*>( information );
                filteredInformation->SetIdInSetParam( j++ );

                m_filteredInformationVector.push_back( filteredInformation );
            }
        }

        // Modify counts
        m_filteredParams.MetricsCount     = m_filteredMetricsVector.size();
        m_filteredParams.InformationCount = m_filteredInformationVector.size();

        if( filteringEnabled )
        {
            UseApiFilteredVariables( true );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ClearCachedMetricsAndInformation
    //
    // Description:
    //     Clear cached metrics and information. Instances are set to nullptr because
    //     Clear() method deletes objects stored in the List. This's not desired.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::ClearCachedMetricsAndInformation()
    {
        // To prevent double memory freeing, original instances are in m_metrics/informationVector
        uint32_t count = m_filteredMetricsVector.size();
        for( uint32_t i = 0; i < count; i++ )
        {
            m_filteredMetricsVector[i] = nullptr;
        }
        count = m_filteredInformationVector.size();
        for( uint32_t i = 0; i < count; i++ )
        {
            m_filteredInformationVector[i] = nullptr;
        }

        m_filteredMetricsVector.clear();
        m_filteredInformationVector.clear();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateMetrics
    //
    // Description:
    //     Conducts the whole process of metrics and information calculation for multiple reports.
    //     It's API agnostic - user doesn't have to worry about API he has used.
    //     User has to provide input buffer and its size, output buffer and its size with enough space for
    //     all calculated metrics and information.
    //     The amount of input reports is calculated based on rawData size and the size of single raw report.
    //
    // Input:
    //     const uint8_t*   rawData                - raw report data
    //     uint32_t         rawDataSize            - size of raw report data
    //     TTypedValue_1_0* out                    - (OUT) buffer for calculated reports
    //     uint32_t         outSize                - size of the provided output buffer
    //     uint32_t*        outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    //     bool             enableContextFiltering - if true enable context filtering during calculation
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering )
    {
        if( enableContextFiltering )
        {
            MD_LOG( LOG_ERROR, "error: context filtering not supported" );
            return CC_ERROR_NOT_SUPPORTED;
        }

        return CalculateMetrics( rawData, rawDataSize, out, outSize, outReportCount, nullptr, 0 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateMetrics
    //
    // Description:
    //     Conducts the whole process of metrics and information calculation for multiple reports.
    //     It's API agnostic - user doesn't have to worry about API he has used.
    //     User has to provide input buffer and its size, output buffer and its size with enough space for
    //     all calculated metrics and information.
    //     The amount of input reports is calculated based on rawData size and the size of single raw report.
    //
    //     Optional MaxValues calculation added, if MaxValueEquation isn't defined for the metric its current
    //     normalized value is used.
    //
    // Input:
    //     const uint8_t*   rawData                - raw report data
    //     uint32_t         rawDataSize            - size of raw report data in bytes
    //     TTypedValue_1_0* out                    - (OUT) buffer for calculated reports
    //     uint32_t         outSize                - size of the provided output buffer in bytes
    //     uint32_t*        outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    //     TTypedValue_1_0* outMaxValues           - (OUT - optional) should have a memory for at least 'MetricCount * RawReportCount' values, can be nullptr. Calculated maxValues for each metric.
    //                                               If MaxValueEquation isn't defined for the metric, MaxValue will be equal to the current, normalized metric value.
    //     uint32_t         outMaxValuesSize       - size of the provided buffer for max values in bytes
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( out, CC_ERROR_INVALID_PARAMETER );
        if( !rawDataSize )
        {
            MD_LOG( LOG_DEBUG, "nothing to calculate, rawDataSize: 0" );
            MD_LOG_EXIT();
            return CC_OK;
        }
        if( !outMaxValues || !outMaxValuesSize )
        {
            MD_LOG( LOG_DEBUG, "max values won't be calculated, outMaxValues: %p, outMaxValuesSize: %u", outMaxValues, outMaxValuesSize );
            outMaxValues     = nullptr;
            outMaxValuesSize = 0;
        }

        if( !m_isFiltered )
        {
            MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }
        if( ( m_currentParams->MetricsCount + m_currentParams->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG( LOG_WARNING, "nothing to calculate, empty MetricSet" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        TCompletionCode  ret             = CC_OK;
        uint32_t         streamMask      = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;
        TMeasurementType measurementType = ( m_currentParams->ApiMask & streamMask ) ? MEASUREMENT_TYPE_SNAPSHOT_IO : MEASUREMENT_TYPE_DELTA_QUERY;
        uint32_t         rawReportSize   = ( measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO ) ? m_currentParams->RawReportSize : m_currentParams->QueryReportSize;
        uint32_t         rawReportCount  = rawDataSize / rawReportSize;

        // Validation
        ret = ValidateCalculateMetricsParams( rawDataSize, rawReportSize, outSize, rawReportCount, outMaxValuesSize );
        MD_CHECK_CC_RET( ret );

        // Initialize manager and context
        CCalculationManager* calculationManager = nullptr;
        TCalculationContext  calculationContext;

        InitializeCalculationManager( measurementType, &calculationManager, true );
        MD_CHECK_PTR_RET( calculationManager, CC_ERROR_NO_MEMORY );

        ret = InitializeCalculationContext( calculationContext, calculationManager, measurementType, out, outMaxValues, rawData, rawReportCount, true );
        if( ret != CC_OK )
        {
            goto deinitialize_manager;
        }

        MD_LOG( LOG_DEBUG, "about to calculate %u raw reports", rawReportCount );

        // CALCULATE METRICS
        while( calculationManager->CalculateNextReport( calculationContext ) )
        { // void
        }

        MD_LOG( LOG_DEBUG, "calculated %u out reports", calculationContext.CommonCalculationContext.OutReportCount );
        MD_LOG( LOG_DEBUG, "max values%s calculated", outMaxValues ? "" : " not" );

        if( outReportCount )
        {
            *outReportCount = calculationContext.CommonCalculationContext.OutReportCount;
        }

        InitializeCalculationContext( calculationContext, nullptr, measurementType, nullptr, nullptr, nullptr, 0, false );
    deinitialize_manager:
        InitializeCalculationManager( measurementType, &calculationManager, false );

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     CalculateIoMeasurementInformation
    //
    // Description:
    //     Calculates IoMeasurementInformation obtained on every ReadIoStream.
    //
    // Input:
    //     TTypedValue_1_0* out     - (OUT) buffer for calculated IoMeasurementInformation
    //     uint32_t         outSize - output buffer size, should be at least
    //                                IoMeasurementInformation count * sizeof(TTypedValue_1_0)
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( m_concurrentGroup, CC_ERROR_GENERAL );

        MD_CHECK_PTR_RET( out, CC_ERROR_INVALID_PARAMETER );
        if( outSize < m_concurrentGroup->GetParams()->IoMeasurementInformationCount )
        {
            MD_LOG( LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG( LOG_DEBUG, "outSize: %u", outSize );
            MD_LOG_EXIT();
            return CC_ERROR_INVALID_PARAMETER;
        }

        MD_CHECK_PTR_RET( m_metricsCalculator, CC_ERROR_GENERAL );

        m_metricsCalculator->ReadIoMeasurementInformation( *m_concurrentGroup, out );
        MD_LOG( LOG_DEBUG, "calculated %u out io information", m_concurrentGroup->GetParams()->IoMeasurementInformationCount );

        MD_LOG_EXIT();
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     ValidateCalculateMetricsParams
    //
    // Description:
    //     Validates parameters passed to CalculateMetrics.
    //     Subjects of validation: i.a. input and output buffer alignments, output buffer size.
    //
    // Input:
    //     uint32_t rawDataSize      - raw report data size
    //     uint32_t rawReportSize    - size of one individual raw report
    //     uint32_t outSize          - size of out buffer in bytes
    //     uint32_t rawReportCount   - raw report count
    //     uint32_t outMaxValuesSize - size of max values buffer in bytes
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::ValidateCalculateMetricsParams( uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize, uint32_t rawReportCount, uint32_t outMaxValuesSize )
    {
        // Size of one individual calculated report in bytes
        uint32_t outReportSize = ( m_currentParams->MetricsCount + m_currentParams->InformationCount ) * sizeof( TTypedValue_1_0 );
        // Size of one individual calculated max values report in bytes
        uint32_t maxValuesReportSize = m_currentParams->MetricsCount * sizeof( TTypedValue_1_0 );

        MD_ASSERT( rawReportSize != 0 );

        if( rawDataSize % rawReportSize != 0 )
        {
            MD_LOG( LOG_ERROR, "error: input buffer has incorrect size" );
            MD_LOG( LOG_DEBUG, "rawDataSize: %u, rawReportSize: %u", rawDataSize, rawReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outReportSize == 0 )
        {
            MD_LOG( LOG_DEBUG, "outReportSize: 0. Nothing to calculate." );
            return CC_OK;
        }
        if( outSize % outReportSize != 0 )
        {
            MD_LOG( LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG( LOG_DEBUG, "outSize: %u, outReportSize: %u", outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( rawReportCount > ( outSize / outReportSize ) )
        {
            MD_LOG( LOG_ERROR, "error: output buffer to small" );
            MD_LOG( LOG_DEBUG, "rawReportCount: %u, outSize: %u, outReportSize: %u", rawReportCount, outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outMaxValuesSize && maxValuesReportSize && rawReportCount > ( outMaxValuesSize / maxValuesReportSize ) )
        {
            MD_LOG( LOG_ERROR, "error: maxValues buffer to small" );
            MD_LOG( LOG_DEBUG, "rawReportCount: %u, outMaxValuesSize: %u, maxValueReportSize: %u", rawReportCount, outMaxValuesSize, maxValuesReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InitializeCalculationManager
    //
    // Description:
    //     Creates or destroys CalculationManager adequate to the given measurement type.
    //
    // Input:
    //     TMeasurementType      measurementType     - type of measurement for which manager will be created
    //     CCalculationManager** calculationManager  - (OUT) pointer to the newly created CalculationManager, null if error
    //     bool                  init                - if true initialization,
    //                                                 if false deinitialization
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricSet::InitializeCalculationManager( TMeasurementType measurementType, CCalculationManager** calculationManager, bool init )
    {
        if( !init )
        {
            MD_SAFE_DELETE( *calculationManager );
            MD_LOG( LOG_DEBUG, "calculation manager deinitialization" );
            return;
        }

        MD_ASSERT( *calculationManager == nullptr );
        switch( measurementType )
        {
            case MEASUREMENT_TYPE_DELTA_QUERY:
                *calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>();
                MD_LOG( LOG_DEBUG, "query calculation manager created" );
                return;

            case MEASUREMENT_TYPE_SNAPSHOT_IO:
                *calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>();
                MD_LOG( LOG_DEBUG, "ioStream calculation manager created" );
                return;

            default:
                *calculationManager = nullptr;
                MD_LOG( LOG_ERROR, "not supported measurement type" );
                return;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     InitializeCalculationContext
    //
    // Description:
    //     Resets calculation context and initializes it with user provided data.
    //     After execution the context is ready for metrics calculations.
    //
    // Input:
    //     TCalculationContext& context            - (OUT) calculation context
    //     CalcManager*         calculationManager - already initialized calculation manager
    //     TMeasurementType     measurementType    - type of measurements
    //     TTypedValue_1_0*     out                - output buffer
    //     TTypedValue_1_0*     outMaxValues       - output buffer for MaxValues, can be nullptr
    //     const uint8_t*       rawData            - input buffer with raw report data
    //     uint32_t             rawReportCount     - raw report count
    //     bool                 init               - if true initialization,
    //                                               if false deinitialization
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::InitializeCalculationContext( TCalculationContext& context, CCalculationManager* calculationManager, TMeasurementType measurementType, TTypedValue_1_0* out, TTypedValue_1_0* outMaxValues, const uint8_t* rawData, uint32_t rawReportCount, bool init )
    {
        MD_LOG_ENTER();
        if( !init )
        {
            MD_SAFE_DELETE_ARRAY( context.CommonCalculationContext.DeltaValues );
            MD_LOG( LOG_DEBUG, "calculation context deinitialization" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        // Initialize context
        calculationManager->ResetContext( context );
        context.CommonCalculationContext.DeltaValues    = new( std::nothrow ) TTypedValue_1_0[m_currentParams->MetricsCount];
        context.CommonCalculationContext.Calculator     = m_metricsCalculator;
        context.CommonCalculationContext.MetricSet      = this;
        context.CommonCalculationContext.Out            = out;
        context.CommonCalculationContext.OutMaxValues   = outMaxValues;
        context.CommonCalculationContext.RawData        = rawData;
        context.CommonCalculationContext.RawReportCount = rawReportCount;
        MD_CHECK_PTR_RET( context.CommonCalculationContext.DeltaValues, CC_ERROR_NO_MEMORY );
        if( measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO )
        {
            // Not supported
            context.StreamCalculationContext.DoContextFiltering = false;
        }
        if( calculationManager->PrepareContext( context ) != CC_OK )
        {
            // Deinitialize and return error
            InitializeCalculationContext( context, nullptr, measurementType, nullptr, nullptr, nullptr, 0, false );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        MD_LOG( LOG_DEBUG, "calculation context initialized" );
        MD_LOG( LOG_DEBUG, "metricSet: %s", context.CommonCalculationContext.MetricSet->GetParams()->ShortName );
        MD_LOG_EXIT();
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     AreMetricParamsValid
    //
    // Description:
    //     Checks the correctness of the given metric parameters.
    //
    // Input:
    //     const char* symbolicName     -
    //     const char* shortName        -
    //     const char* longName         -
    //     const char* groupName        -
    //     TMetricType metricType       -
    //     TMetricResultType resultType -
    //     const char* units            -
    //     THwUnitType hwType           -
    //     const char* alias            -
    //
    // Output:
    //     bool -
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::AreMetricParamsValid( const char* symbolName, const char* shortName, const char* longName, const char* groupName, TMetricType metricType, TMetricResultType resultType, const char* units, THwUnitType hwType, const char* alias )
    {
        if( ( symbolName == nullptr ) || ( strcmp( symbolName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, symbolName );
            return false;
        }
        if( ( shortName == nullptr ) || ( strcmp( shortName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, shortName );
            return false;
        }
        if( ( longName == nullptr ) || ( strcmp( longName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, longName );
            return false;
        }
        if( ( groupName == nullptr ) || ( strcmp( groupName, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, groupName );
            return false;
        }
        if( (uint32_t) metricType >= METRIC_TYPE_LAST )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, metricType );
            return false;
        }
        if( (uint32_t) resultType >= RESULT_LAST )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, resultType );
            return false;
        }
        if( ( units == nullptr ) || ( strcmp( units, "" ) == 0 ) )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, units );
            return false;
        }
        if( (uint32_t) hwType >= HW_UNIT_LAST )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, hwType );
            return false;
        }
        if( alias == nullptr )
        {
            MD_LOG_INVALID_PARAMETER( LOG_ERROR, alias );
            return false;
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     HasInformation
    //
    // Description:
    //     Returns true if in the m_informationVector there is an information with the given
    //     symbol name.
    //
    // Input:
    //     const char * symbolName - information name to look for
    //
    // Output:
    //     bool - true if found
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::HasInformation( const char* symbolName )
    {
        MD_CHECK_PTR_RET( symbolName, false );

        for( uint32_t i = 0; i < m_params_1_0.InformationCount; i++ )
        {
            IInformation_1_0* information = GetInformation( i );
            if( information && information->GetParams()->SymbolName != nullptr && strcmp( information->GetParams()->SymbolName, symbolName ) == 0 )
            {
                return true;
            }
        }

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     GetMetricsCalculator
    //
    // Description:
    //     Returns metrics calculator.
    //
    // Output:
    //     CMetricsCalculator* - metrics calculator or *nullptr* if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsCalculator* CMetricSet::GetMetricsCalculator()
    {
        return m_metricsCalculator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the metric set. It's used to determine if the metric
    //     set is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricSet::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );

        if( ret == CC_OK )
        {
            m_params_1_0.AvailabilityEquation = GetCopiedCString( equationString );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Method:
    //     IsAvailabilityEquationTrue
    //
    // Description:
    //     Returns true if metric set availability equation is true.
    //
    // Output:
    //     bool -
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricSet::IsAvailabilityEquationTrue()
    {
        return m_availabilityEquation->SolveBooleanEquation();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     CMetric constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device      -
    //     uint32_t     id              -
    //     const char * name            -
    //     const char * shortName       -
    //     const char * longName        -
    //     const char * group           -
    //     uint32_t groupId             -
    //     uint32_t usageFlagsMask      -
    //     uint32_t     apiMask         -
    //     TMetricType metricType       -
    //     TMetricResultType resultType -
    //     const char * units           -
    //     int64_t loWatermark          -
    //     int64_t hiWatermark          -
    //     const char * maxValue        -
    //     THwUnitType hwType           -
    //     const char* alias            -
    //     const char* signalName       -
    //     bool isCustom                - flag shows that metric was created from function AddCustomMetric
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::CMetric( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName, const char* group, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* alias, const char* signalName, bool isCustom )
    {
        m_params_1_0.IdInSet           = id; // filtered id, equal to original on creation
        m_id                           = id; // id in original set, equal to filtered on creation
        m_params_1_0.SymbolName        = GetCopiedCString( name );
        m_params_1_0.ShortName         = GetCopiedCString( shortName );
        m_params_1_0.LongName          = GetCopiedCString( longName );
        m_params_1_0.GroupName         = GetCopiedCString( group );
        m_params_1_0.DxToOglAlias      = GetCopiedCString( alias );
        m_params_1_0.GroupId           = groupId;
        m_params_1_0.UsageFlagsMask    = usageFlagsMask;
        m_params_1_0.ApiMask           = apiMask;
        m_params_1_0.MetricType        = metricType;
        m_params_1_0.ResultType        = resultType;
        m_params_1_0.MetricResultUnits = GetCopiedCString( units );
        m_params_1_0.LowWatermark      = loWatermark;
        m_params_1_0.HighWatermark     = hiWatermark;
        m_params_1_0.HwUnitType        = hwType;
        m_signalName                   = GetCopiedCString( signalName );

        m_params_1_0.DeltaFunction.FunctionType = DELTA_FUNCTION_NULL;
        m_params_1_0.DeltaFunction.BitsCount    = 0;
        m_params_1_0.IoReadEquation             = nullptr;
        m_params_1_0.QueryReadEquation          = nullptr;
        m_params_1_0.NormEquation               = nullptr;
        m_params_1_0.MaxValueEquation           = nullptr;
        m_availabilityEquation                  = nullptr;

        m_normEquation      = nullptr;
        m_ioReadEquation    = nullptr;
        m_queryReadEquation = nullptr;
        m_maxValueEquation  = nullptr;

        m_device   = device;
        m_isCustom = isCustom;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     CMetric copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::CMetric( const CMetric& other )
        : m_device( other.m_device )
    {
        memset( &m_params_1_0, 0, sizeof( m_params_1_0 ) );

        m_params_1_0.IdInSet           = other.m_params_1_0.IdInSet; // id after filterings
        m_id                           = other.m_id;                 // initial id before filterings
        m_params_1_0.GroupId           = other.m_params_1_0.GroupId;
        m_params_1_0.SymbolName        = GetCopiedCString( other.m_params_1_0.SymbolName );
        m_params_1_0.ShortName         = GetCopiedCString( other.m_params_1_0.ShortName );
        m_params_1_0.GroupName         = GetCopiedCString( other.m_params_1_0.GroupName );
        m_params_1_0.LongName          = GetCopiedCString( other.m_params_1_0.LongName );
        m_params_1_0.DxToOglAlias      = GetCopiedCString( other.m_params_1_0.DxToOglAlias );
        m_params_1_0.UsageFlagsMask    = other.m_params_1_0.UsageFlagsMask;
        m_params_1_0.ApiMask           = other.m_params_1_0.ApiMask;
        m_params_1_0.ResultType        = other.m_params_1_0.ResultType;
        m_params_1_0.MetricResultUnits = GetCopiedCString( other.m_params_1_0.MetricResultUnits );
        m_params_1_0.MetricType        = other.m_params_1_0.MetricType;
        m_params_1_0.LowWatermark      = other.m_params_1_0.LowWatermark;
        m_params_1_0.HighWatermark     = other.m_params_1_0.HighWatermark;
        m_params_1_0.HwUnitType        = other.m_params_1_0.HwUnitType;
        m_params_1_0.DeltaFunction     = other.m_params_1_0.DeltaFunction;
        m_signalName                   = GetCopiedCString( other.m_signalName );
        m_isCustom                     = other.m_isCustom;

        m_availabilityEquation = ( other.m_availabilityEquation ) ? new( std::nothrow ) CEquation( *other.m_availabilityEquation ) : nullptr;
        m_ioReadEquation       = ( other.m_ioReadEquation ) ? new( std::nothrow ) CEquation( *other.m_ioReadEquation ) : nullptr;
        m_queryReadEquation    = ( other.m_queryReadEquation ) ? new( std::nothrow ) CEquation( *other.m_queryReadEquation ) : nullptr;
        m_normEquation         = ( other.m_normEquation ) ? new( std::nothrow ) CEquation( *other.m_normEquation ) : nullptr;
        m_maxValueEquation     = ( other.m_maxValueEquation ) ? new( std::nothrow ) CEquation( *other.m_maxValueEquation ) : nullptr;

        m_params_1_0.IoReadEquation    = (IEquation_1_0*) m_ioReadEquation;
        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
        m_params_1_0.NormEquation      = (IEquation_1_0*) m_normEquation;
        m_params_1_0.MaxValueEquation  = (IEquation_1_0*) m_maxValueEquation;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     ~CMetric destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::~CMetric()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.LongName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.MetricResultUnits );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.DxToOglAlias );
        MD_SAFE_DELETE_ARRAY( m_signalName );
        MD_SAFE_DELETE( m_availabilityEquation );
        MD_SAFE_DELETE( m_ioReadEquation );
        MD_SAFE_DELETE( m_queryReadEquation );
        MD_SAFE_DELETE( m_normEquation );
        MD_SAFE_DELETE( m_maxValueEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns the metric params.
    //
    // Output:
    //     TMetricParams_1_0*  - pointer to metric params.
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricParams_1_0* CMetric::GetParams( void )
    {
        return &m_params_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetMetricValue
    //
    // Description:
    //     Decodes and returns value from the string which may be a symbol.
    //     Empty string is equal to zero.
    //
    // Input:
    //     const char* valueString     - value string
    //
    // Output:
    //     uint64_t            - read value
    //
    //////////////////////////////////////////////////////////////////////////////
    uint64_t CMetric::GetMetricValue( const char* valueString )
    {
        uint64_t ret = 0LL;

        if( ( valueString == nullptr ) || ( strcmp( valueString, "" ) == 0 ) )
        {
            return 0LL;
        }

        if( ( valueString[0] == '$' ) && ( valueString[1] != 0 ) )
        {
            TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( &valueString[1] );
            if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ) )
            {
                ret = (uint64_t) pValue->ValueUInt64;
            }
            else if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ) )
            {
                ret = (uint64_t) pValue->ValueUInt32;
            }
            else
            {
                MD_ASSERT( false );
            }
        }
        else
        {
            ret = (uint64_t) atol( valueString );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportReadEquation
    //
    // Description:
    //     Sets the snapshot (IO) read equation in the metric.
    //
    // Input:
    //     const char * equationString - euqation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportReadEquation( const char* equationString )
    {
        TCompletionCode ret         = SetEquation( m_device, &m_ioReadEquation, equationString );
        m_params_1_0.IoReadEquation = (IEquation_1_0*) m_ioReadEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetDeltaReportReadEquation
    //
    // Description:
    //     Sets the delta (query) read equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetDeltaReportReadEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_queryReadEquation, equationString );

        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetNormalizationEquation
    //
    // Description:
    //     Sets the normalization equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetNormalizationEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_normEquation, equationString );

        m_params_1_0.NormEquation = (IEquation_1_0*) m_normEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetMaxValueEquation
    //
    // Description:
    //     Sets the max value equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetMaxValueEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_maxValueEquation, equationString );

        m_params_1_0.MaxValueEquation = (IEquation_1_0*) m_maxValueEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetIdInSetParam
    //
    // Description:
    //     Updates IdInSet parameter in the metric.
    //
    // Input:
    //     uint32_t id - id in current metric set
    //
    // Output:
    //     void        - return values is absent
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetric::SetIdInSetParam( uint32_t id )
    {
        m_params_1_0.IdInSet = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportDeltaFunction
    //
    // Description:
    //     Sets the snapshot report delta equation in the metric.
    //     It's an equation to calculate delta values of to snapshot report values.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportDeltaFunction( const char* equationString )
    {
        return SetDeltaFunction( equationString, &m_params_1_0.DeltaFunction );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportDeltaFunction
    //
    // Description:
    //     Sets the snapshot report delta equation in the metric.
    //     It's an equation to calculate delta values of to snapshot report values.
    //
    // Input:
    //     TDeltaFunction_1_0 deltaFunction    - parsed equation
    //
    // Output:
    //     TCompletionCode                     - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportDeltaFunction( TDeltaFunction_1_0 deltaFunction )
    {
        m_params_1_0.DeltaFunction = deltaFunction;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the metric. It's used to determine if the metric
    //     is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     WriteCMetricToFile
    //
    // Description:
    //     Writes the metric object to file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::WriteCMetricToFile( FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        fwrite( &m_params_1_0.GroupId, sizeof( m_params_1_0.GroupId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile );
        WriteCStringToFile( m_params_1_0.GroupName, metricFile );
        WriteCStringToFile( m_params_1_0.LongName, metricFile );
        WriteCStringToFile( m_params_1_0.DxToOglAlias, metricFile );
        fwrite( &m_params_1_0.UsageFlagsMask, sizeof( m_params_1_0.UsageFlagsMask ), 1, metricFile );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.ResultType, sizeof( m_params_1_0.ResultType ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.MetricResultUnits, metricFile );
        fwrite( &m_params_1_0.MetricType, sizeof( m_params_1_0.MetricType ), 1, metricFile );
        fwrite( &m_params_1_0.HwUnitType, sizeof( m_params_1_0.HwUnitType ), 1, metricFile );
        fwrite( &m_params_1_0.LowWatermark, sizeof( m_params_1_0.LowWatermark ), 1, metricFile );
        fwrite( &m_params_1_0.HighWatermark, sizeof( m_params_1_0.HighWatermark ), 1, metricFile );

        WriteCStringToFile( m_signalName, metricFile );

        // Availability equation
        WriteEquationToFile( m_availabilityEquation, metricFile );
        // DeltaFunction
        fwrite( &m_params_1_0.DeltaFunction.FunctionType, sizeof( m_params_1_0.DeltaFunction.FunctionType ), 1, metricFile );
        fwrite( &m_params_1_0.DeltaFunction.BitsCount, sizeof( m_params_1_0.DeltaFunction.BitsCount ), 1, metricFile );

        // Equations
        WriteEquationToFile( m_ioReadEquation, metricFile );
        WriteEquationToFile( m_queryReadEquation, metricFile );
        WriteEquationToFile( m_normEquation, metricFile );

        WriteEquationToFile( m_maxValueEquation, metricFile );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetSignalName
    //
    // Description:
    //     Returns signal name, can be nullptr.
    //
    // Output:
    //     const char* - signal name
    //
    //////////////////////////////////////////////////////////////////////////////
    const char* CMetric::GetSignalName()
    {
        return m_signalName;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     CInformation constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device          -
    //     uint32_t         id              -
    //     const char*      name            -
    //     const char*      shortName       -
    //     const char*      longName        -
    //     const char*      group           -
    //     uint32_t         apiMask         -
    //     TInformationType informationType -
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::CInformation( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName, const char* group, uint32_t apiMask, TInformationType informationType, const char* informationUnits )
    {
        m_params_1_0.IdInSet    = id; // filtered, equal to original on creation
        m_id                    = id; // original, equal to filtered on creation
        m_params_1_0.SymbolName = GetCopiedCString( name );
        m_params_1_0.ShortName  = GetCopiedCString( shortName );
        m_params_1_0.LongName   = GetCopiedCString( longName );
        m_params_1_0.GroupName  = GetCopiedCString( group );
        m_params_1_0.ApiMask    = apiMask;
        m_params_1_0.InfoType   = informationType;
        m_params_1_0.InfoUnits  = GetCopiedCString( informationUnits );

        m_params_1_0.OverflowFunction.FunctionType = DELTA_FUNCTION_NULL;

        m_params_1_0.IoReadEquation    = nullptr;
        m_params_1_0.QueryReadEquation = nullptr;

        m_availabilityEquation = nullptr;
        m_ioReadEquation       = nullptr;
        m_queryReadEquation    = nullptr;

        m_device = device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     CInformation copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::CInformation( const CInformation& other )
        : m_device( other.m_device )
    {
        m_params_1_0.IdInSet    = other.m_params_1_0.IdInSet; // id after filterings
        m_id                    = other.m_id;                 // initial id before filterings
        m_params_1_0.SymbolName = GetCopiedCString( other.m_params_1_0.SymbolName );
        m_params_1_0.ShortName  = GetCopiedCString( other.m_params_1_0.ShortName );
        m_params_1_0.GroupName  = GetCopiedCString( other.m_params_1_0.GroupName );
        m_params_1_0.LongName   = GetCopiedCString( other.m_params_1_0.LongName );
        m_params_1_0.ApiMask    = other.m_params_1_0.ApiMask;
        m_params_1_0.InfoType   = other.m_params_1_0.InfoType;
        m_params_1_0.InfoUnits  = GetCopiedCString( other.m_params_1_0.InfoUnits );

        m_params_1_0.OverflowFunction = other.m_params_1_0.OverflowFunction;

        m_availabilityEquation = ( other.m_availabilityEquation ) ? new( std::nothrow ) CEquation( *other.m_availabilityEquation ) : nullptr;
        m_ioReadEquation       = ( other.m_ioReadEquation ) ? new( std::nothrow ) CEquation( *other.m_ioReadEquation ) : nullptr;
        m_queryReadEquation    = ( other.m_queryReadEquation ) ? new( std::nothrow ) CEquation( *other.m_queryReadEquation ) : nullptr;

        m_params_1_0.IoReadEquation    = (IEquation_1_0*) m_ioReadEquation;
        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     ~CInformation destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::~CInformation()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.LongName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.InfoUnits );
        MD_SAFE_DELETE( m_availabilityEquation );
        MD_SAFE_DELETE( m_ioReadEquation );
        MD_SAFE_DELETE( m_queryReadEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns the information params.
    //
    // Output:
    //     TInformationParams_1_0* - pointer to the information params
    //
    //////////////////////////////////////////////////////////////////////////////
    TInformationParams_1_0* CInformation::GetParams( void )
    {
        return &m_params_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetSnapshotReportReadEquation
    //
    // Description:
    //     Sets the snapshot (IO) read equation in the information.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetSnapshotReportReadEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_ioReadEquation, equationString );

        m_params_1_0.IoReadEquation = (IEquation_1_0*) m_ioReadEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetDeltaReportReadEquation
    //
    // Description:
    //     Sets the delta (query) read equation in the information.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetDeltaReportReadEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_queryReadEquation, equationString );

        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the information. It's used to determine if
    //     the information is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetOverflowFunction
    //
    // Description:
    //     Sets the overflow delta equation in the information.
    //     It's an equation to calculate whether the overflow occurs.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetOverflowFunction( const char* equationString )
    {
        return SetDeltaFunction( equationString, &m_params_1_0.OverflowFunction );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetOverflowFunction
    //
    // Description:
    //     Sets the overflow delta equation in the information.
    //     It's an equation to calculate whether the overflow occurs.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetOverflowFunction( TDeltaFunction_1_0 overflowFunction )
    {
        m_params_1_0.OverflowFunction = overflowFunction;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     WriteCInformationToFile
    //
    // Description:
    //     Write the information object to file.
    //
    // Input:
    //     FILE* metricFile - handle to metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::WriteCInformationToFile( FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile );
        WriteCStringToFile( m_params_1_0.GroupName, metricFile );
        WriteCStringToFile( m_params_1_0.LongName, metricFile );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.InfoType, sizeof( m_params_1_0.InfoType ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.InfoUnits, metricFile );

        // Availability equation
        WriteEquationToFile( m_availabilityEquation, metricFile );

        // OverflowFunction
        fwrite( &m_params_1_0.OverflowFunction.FunctionType, sizeof( m_params_1_0.OverflowFunction.FunctionType ), 1, metricFile );
        fwrite( &m_params_1_0.OverflowFunction.BitsCount, sizeof( m_params_1_0.OverflowFunction.BitsCount ), 1, metricFile );

        // Equations
        WriteEquationToFile( m_ioReadEquation, metricFile );
        WriteEquationToFile( m_queryReadEquation, metricFile );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetInformationValue
    //
    // Description:
    //     Sets the value for the information as a given equation.
    //
    // Input:
    //     uint32_t        value           - information value
    //     TEquationType   equationType    - equation to be set
    //
    // Output:
    //     TCompletionCode - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetInformationValue( uint32_t value, TEquationType equationType )
    {
        TCompletionCode ret = CC_OK;

        char strValue[11]; // Max string length for decimal uint32_t
        iu_sprintf_s( strValue, sizeof( strValue ), "%d", value );

        if( equationType == EQUATION_IO_READ )
        {
            ret = SetSnapshotReportReadEquation( strValue );
        }
        else if( equationType == EQUATION_QUERY_READ )
        {
            ret = SetDeltaReportReadEquation( strValue );
        }
        else
        {
            ret = CC_ERROR_INVALID_PARAMETER;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetIdInSetParam
    //
    // Description:
    //     Updates IdInSet parameter in the information element.
    //
    // Input:
    //     uint32_t id - id in current information set
    //
    // Output:
    //     void        - return values is absent
    //
    //////////////////////////////////////////////////////////////////////////////
    void CInformation::SetIdInSetParam( uint32_t id )
    {
        m_params_1_0.IdInSet = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     CRegisterSet
    //
    // Description:
    //     CRegisterSet constructor.
    //
    // Input:
    //     CMetricsDevice* device         - metrics device
    //     uint32_t        configId       - config id
    //     uint32_t        configPriority - priority, lower more important
    //     TConfigType     configType     - e.g. COMMON, SNAPSHOT
    //
    //////////////////////////////////////////////////////////////////////////////
    CRegisterSet::CRegisterSet( CMetricsDevice* device, uint32_t configId, uint32_t configPriority, TConfigType configType )
        : m_regList()
        , m_device( device )
        , m_availabilityEquation( nullptr )
        , m_isAvailable( true )
    {
        m_params.ConfigId       = configId;
        m_params.ConfigPriority = configPriority;
        m_params.ConfigType     = configType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     ~CRegisterSet
    //
    // Description:
    //     CRegisterSet destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CRegisterSet::~CRegisterSet()
    {
        ClearList( m_regList );
        MD_SAFE_DELETE( m_availabilityEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns params.
    //
    // Output:
    //     TRegisterSetParams* - register set params
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegisterSetParams* CRegisterSet::GetParams()
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in a register set. It's used to determine if the set
    //     is available on the current platform.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );
        if( ret == CC_OK )
        {
            m_isAvailable = m_availabilityEquation ? m_availabilityEquation->SolveBooleanEquation() : true;
        }
        else
        {
            MD_LOG( LOG_ERROR, "Error setting availability equation" );
            m_isAvailable = false;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     AddConfigRegister
    //
    // Description:
    //     Adds config register to the register set.
    //
    // Input:
    //     uint32_t      offset - register offset
    //     uint32_t      value  - value
    //     TRegisterType type   - register type
    //
    // Output:
    //     TRegister* - added register
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegister* CRegisterSet::AddConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
    {
        TRegister reg;
        reg.offset = offset;
        reg.value  = value;
        reg.type   = ( type > REGISTER_TYPE_UNKNOWN && type < REGISTER_TYPE_LAST ) ? type : REGISTER_TYPE_UNKNOWN;

        m_regList.push_back( reg );

        return &m_regList.back();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     IsAvailable
    //
    // Description:
    //     True if register set is available on a current platform.
    //
    // Output:
    //     bool - true if available on current platform
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CRegisterSet::IsAvailable()
    {
        return m_isAvailable;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     RegsToVector
    //
    // Description:
    //     Copies register pointers to a given vector.
    //     !!WATCH OUT FOR DOUBLE MEMORY FREEING!!
    //
    // Input:
    //     Vector<TRegister*>& regVector - destination vector
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::RegsToVector( std::vector<TRegister*>& regVector )
    {
        for( TRegister& registerNode : m_regList )
        {
            regVector.push_back( &registerNode );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     WriteCRegisterSetToFile
    //
    // Description:
    //     Writes CRegisterSet object to a file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::WriteCRegisterSetToFile( FILE* metricFile )
    {
        MD_CHECK_PTR_RET( metricFile, CC_ERROR_INVALID_PARAMETER );

        uint32_t count = 0;

        // m_params and availability equation
        fwrite( &m_params.ConfigId, sizeof( m_params.ConfigId ), 1, metricFile );
        fwrite( &m_params.ConfigPriority, sizeof( m_params.ConfigPriority ), 1, metricFile );
        fwrite( &m_params.ConfigType, sizeof( m_params.ConfigType ), 1, metricFile );
        WriteEquationToFile( m_availabilityEquation, metricFile );

        // Registers
        count = m_regList.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );

        for( TRegister& reg : m_regList )
        {
            fwrite( &reg, sizeof( reg ), 1, metricFile );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     CEquationElementInternal constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal::CEquationElementInternal()
    {
        memset( &Element_1_0, 0x0, sizeof( Element_1_0 ) );
        SymbolNameInternal[0]  = 0;
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = -1;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     CEquationElementInternal copy constructor
    //
    // Description:
    //     CEquationElementInternal copy constructor
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal::CEquationElementInternal( const CEquationElementInternal& element )
    {
        Element_1_0 = element.Element_1_0;
        iu_memcpy_s( SymbolNameInternal, sizeof( SymbolNameInternal ), element.SymbolNameInternal, sizeof( SymbolNameInternal ) );
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = element.MetricIndexInternal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     operator=
    //
    // Description:
    //     Assignment operator. Copies whole memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal& CEquationElementInternal::operator=( const CEquationElementInternal& element )
    {
        Element_1_0 = element.Element_1_0;
        iu_memcpy_s( SymbolNameInternal, sizeof( SymbolNameInternal ), element.SymbolNameInternal, sizeof( SymbolNameInternal ) );
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = element.MetricIndexInternal;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice * device - parent metric device
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::CEquation( CMetricsDevice* device )
        : m_elementsVector()
        , m_device( device )
    {
        m_elementsVector.reserve( EQUATION_VECTOR_INCREASE );
        m_equationString = nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::CEquation( const CEquation& other )
        : m_device( other.m_device )
        , m_elementsVector( other.m_elementsVector )
    {
        m_equationString = GetCopiedCString( other.m_equationString );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::~CEquation()
    {
        MD_SAFE_DELETE_ARRAY( m_equationString );
        ClearVector( m_elementsVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     GetEquationElementsCount
    //
    // Description:
    //     Returns equation elements count.
    //
    // Output:
    //     uint32_t  - equation elements count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CEquation::GetEquationElementsCount()
    {
        return m_elementsVector.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     GetEquationElement
    //
    // Description:
    //     Returns the equation element with given index. Null if doesn't exist.
    //
    // Input:
    //     uint32_t     index      - equation element index
    //
    // Output:
    //     TEquationElement_1_0*   - pointer to the chosen element
    //
    //////////////////////////////////////////////////////////////////////////////
    TEquationElement_1_0* CEquation::GetEquationElement( uint32_t index )
    {
        if( index < m_elementsVector.size() )
        {
            return &( m_elementsVector[index].Element_1_0 );
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     SolveBooleanEquation
    //
    // Description:
    //     Used only for availability equations.
    //
    // Output:
    //     bool    -   result of the solved boolean equation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::SolveBooleanEquation( void )
    {
        std::list<uint64_t> equationStack;
        uint64_t            qwordValue;
        uint32_t            algorithmCheck = 0;

        for( uint32_t i = 0; i < m_elementsVector.size(); i++ )
        {
            TEquationElement_1_0* element = &( m_elementsVector[i].Element_1_0 );
            switch( element->Type )
            {
                case EQUATION_ELEM_IMM_UINT64:
                    equationStack.push_back( element->ImmediateUInt64 );
                    algorithmCheck++;
                    break;

                case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
                    // Push 0 to stack for unavailable unpacked mask symbol.
                    if( element->SymbolName != nullptr
                        && strstr( element->SymbolName, "GtSlice" ) != nullptr
                        && strstr( element->SymbolName, "Mask" ) == nullptr )
                    {
                        qwordValue = 0;
                        equationStack.push_back( qwordValue );
                        algorithmCheck++;
                    }
                    else
                    {
                        MD_LOG( LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element->Type );
                        MD_ASSERT( false );
                        ClearList( equationStack );
                        return false;
                    }
                    break;

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( element->SymbolName );

                    if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueUInt64;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueUInt32;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BOOL ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueBool;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BYTEARRAY ) )
                    {
                        // TODO: should be improved (the array can be bigger than 64bits)
                        qwordValue = *( reinterpret_cast<uint64_t*>( pValue->ValueByteArray->Data ) );
                    }
                    else
                    {
                        MD_ASSERT( false );
                        qwordValue = 0;
                    }
                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    // Pop two values from stack
                    uint64_t valueLast = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;
                    uint64_t valuePrev = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;

                    switch( element->Operation )
                    {
                        case EQUATION_OPER_AND:
                            qwordValue = valuePrev & valueLast;
                            break;

                        case EQUATION_OPER_OR:
                            qwordValue = valuePrev | valueLast;
                            break;

                        case EQUATION_OPER_XOR:
                            qwordValue = valuePrev ^ valueLast;
                            break;

                        case EQUATION_OPER_XNOR:
                            qwordValue = ~( valuePrev ^ valueLast );
                            break;

                        case EQUATION_OPER_EQUALS:
                            qwordValue = valuePrev == valueLast;
                            break;

                        case EQUATION_OPER_AND_L:
                            qwordValue = valuePrev && valueLast;
                            break;

                        case EQUATION_OPER_RSHIFT:
                            qwordValue = valuePrev >> valueLast;
                            break;

                        case EQUATION_OPER_LSHIFT:
                            qwordValue = valuePrev << valueLast;
                            break;

                        case EQUATION_OPER_UADD:
                            qwordValue = valuePrev + valueLast;
                            break;

                        case EQUATION_OPER_USUB:
                            qwordValue = valuePrev - valueLast;
                            break;

                        case EQUATION_OPER_UDIV:
                            qwordValue = ( valueLast != 0 ) ? valuePrev / valueLast : 0;
                            break;

                        case EQUATION_OPER_UMUL:
                            qwordValue = valuePrev * valueLast;
                            break;

                        case EQUATION_OPER_UGT:
                            qwordValue = valuePrev > valueLast;
                            break;

                        case EQUATION_OPER_ULT:
                            qwordValue = valuePrev < valueLast;
                            break;

                        case EQUATION_OPER_UGTE:
                            qwordValue = valuePrev >= valueLast;
                            break;

                        case EQUATION_OPER_ULTE:
                            qwordValue = valuePrev <= valueLast;
                            break;

                        default:
                            MD_LOG( LOG_DEBUG, "Not allowed equation element operation in availability equation: %u", element->Operation );
                            MD_ASSERT( false );
                            ClearList( equationStack );
                            return false;
                    }
                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                default:
                    MD_LOG( LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element->Type );
                    MD_ASSERT( false );
                    ClearList( equationStack );
                    return false;
            }
        }
        if( m_elementsVector.size() > 0 )
        {
            // here should be only 1 element on the list - the result (if the equation is fine)
            MD_ASSERT( algorithmCheck == 1 );
            qwordValue = equationStack.back();
        }
        else
        {
            qwordValue = 0LL;
        }
        ClearList( equationStack );

        return ( qwordValue != 0LL );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     ParseEquationString
    //
    // Description:
    //     Parses the equation string.
    //
    // Input:
    //     const char * equationString - equation string to parse
    //
    // Output:
    //     bool                        - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::ParseEquationString( const char* equationString )
    {
        if( ( equationString == nullptr ) || ( strcmp( equationString, "" ) == 0 ) )
        {
            m_equationString = nullptr;
            return false;
        }

        char *token = nullptr, *tokenNext = nullptr, *string = nullptr;

        string = GetCopiedCString( equationString );
        MD_CHECK_PTR_RET( string, false );

        token = iu_strtok_s( string, " ", &tokenNext );
        while( token != nullptr )
        {
            if( !ParseEquationElement( token ) )
            {
                delete[] string;
                return false;
            }
            token = iu_strtok_s( nullptr, " ", &tokenNext );
        }

        m_equationString = GetCopiedCString( equationString );
        delete[] string;
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     AddEquationElement
    //
    // Description:
    //     Adds the element to the equation list.
    //
    // Input:
    //     const CEquationElementInternal * element  - equation element to add
    //
    // Output:
    //     bool                                - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::AddEquationElement( const CEquationElementInternal* element )
    {
        m_elementsVector.push_back( *element );

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     ParseEquationElement
    //
    // Description:
    //     Parses and adds the element to the equation list.
    //
    // Input:
    //     const char* element    - equation element string to parse;
    //                              expected to be nullptr-terminated
    //
    // Output:
    //     bool                   - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::ParseEquationElement( const char* element )
    {
        if( strcmp( element, "EuAggrDurationSlice" ) == 0 )
        {
            return ParseEquationString( "$Self $GpuSliceClocksCount $EuCoresTotalCount UMUL FDIV 100 FMUL" );
        }
        else if( strcmp( element, "EuAggrDuration" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "GpuDurationSlice" ) == 0 )
        {
            return ParseEquationString( "$Self $GpuSliceClocksCount FDIV 100 FMUL" );
        }
        else if( strcmp( element, "GpuDuration" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_STD_NORM_GPU_DURATION;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UADD" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UADD;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "USUB" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_USUB;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMUL" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMUL;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UDIV" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UDIV;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "AND" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_AND;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "OR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_OR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "XNOR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_XNOR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "XOR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_XOR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "==" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_EQUALS;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "&&" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_AND_L;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "<<" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_LSHIFT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, ">>" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_RSHIFT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FADD" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FADD;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FSUB" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FSUB;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMUL" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMUL;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FDIV" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FDIV;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UGTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UGTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "ULTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_ULTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UGT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UGT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "ULT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_ULT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FGTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FGTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FLTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FLTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FGT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FGT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FLT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FLT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMIN" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMIN;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMAX" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMAX;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMIN" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMIN;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMAX" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMAX;
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "dw@", sizeof( "dw@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT32;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "fl@", sizeof( "fl@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_FLOAT;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "qw@", sizeof( "qw@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT64;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "rd40@", sizeof( "rd40@" ) - 1 ) == 0 )
        {
            char*                    pEnd = (char*) &element[5];
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_40BIT_CNTR;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd )
            {
                anElement.Element_1_0.ReadParams.ByteOffsetExt = strtoul( ++pEnd, &pEnd, 0 );
                return AddEquationElement( &anElement );
            }
            return false;
        }
        else if( strncmp( element, "bm@", sizeof( "bm@" ) - 1 ) == 0 )
        {
            char*                    pEnd = (char*) &element[3];
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_BITFIELD;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd )
            {
                anElement.Element_1_0.ReadParams.BitOffset = strtoul( ++pEnd, &pEnd, 0 );
                if( pEnd )
                {
                    anElement.Element_1_0.ReadParams.BitsCount = strtoul( ++pEnd, &pEnd, 10 );
                    return AddEquationElement( &anElement );
                }
            }
            return false;
        }
        else if( strcmp( element, "$Self" ) == 0 )
        {
            CEquationElementInternal anElement;

            anElement.Element_1_0.Type = EQUATION_ELEM_SELF_COUNTER_VALUE;
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "$$", sizeof( "$$" ) - 1 ) == 0 )
        {
            // Add element
            CEquationElementInternal anElement;

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[2], sizeof( anElement.SymbolNameInternal ) - 1 );
            // finish element
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;
            anElement.Element_1_0.Type       = EQUATION_ELEM_LOCAL_METRIC_SYMBOL;

            return AddEquationElement( &anElement );
        }
        else if( ( element[0] == '$' ) && ( element[1] != 0 ) )
        {
            CEquationElementInternal anElement;
            TTypedValue_1_0*         value = m_device->GetGlobalSymbolValueByName( &element[1] );

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[1], sizeof( anElement.SymbolNameInternal ) - 1 );
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;

            if( value == nullptr )
            {
                // Finish element as local counter symbol
                anElement.Element_1_0.Type = EQUATION_ELEM_LOCAL_COUNTER_SYMBOL;
            }
            else
            {
                // Finish element as global symbol
                anElement.Element_1_0.Type = EQUATION_ELEM_GLOBAL_SYMBOL;
            }
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "i$", sizeof( "i$" ) - 1 ) == 0 )
        {
            // Add element
            CEquationElementInternal anElement;

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[2], sizeof( anElement.SymbolNameInternal ) - 1 );
            // finish element
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;
            anElement.Element_1_0.Type       = EQUATION_ELEM_INFORMATION_SYMBOL;

            return AddEquationElement( &anElement );
        }
        else if( strchr( element, '.' ) != nullptr ) // assume float number
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type           = EQUATION_ELEM_IMM_FLOAT;
            anElement.Element_1_0.ImmediateFloat = (float) atof( element );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "0x", sizeof( "0x" ) - 1 ) == 0 ) // assume hex integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
            anElement.Element_1_0.ImmediateUInt64 = strtoull( element, nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( element[0] >= '0' && element[0] <= '9' ) // assume decimal integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
            anElement.Element_1_0.ImmediateUInt64 = strtoull( element, nullptr, 10 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "mask$", sizeof( "mask$" ) - 1 ) == 0 ) // assume hex integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_MASK;
            anElement.Element_1_0.Mask = GetByteArrayFromMask( element + sizeof( "mask$" ) );
            return AddEquationElement( &anElement );
        }

        MD_LOG( LOG_ERROR, "Unknown equation element: %s", element );
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     WriteCEquationToFile
    //
    // Description:
    //     Writes equation string to file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CEquation::WriteCEquationToFile( FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        WriteCStringToFile( m_equationString, metricFile );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     CSymbolSet constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet::CSymbolSet( CMetricsDevice& metricsDevice, CDriverInterface& driverInterface )
        : m_symbolVector()
        , m_metricsDevice( metricsDevice )
        , m_driverInterface( driverInterface )
        , m_maxSlice( 0 )
        , m_maxSubslicePerSlice( 0 )
        , m_maxDualSubslicePerSlice( 0 )
    {
        m_symbolVector.reserve( SYMBOLS_VECTOR_INCREASE );

        if( DetectMaxSlicesInfo() != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Cannot detect max slices, subslices per slice or dual subslices per slice" );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     CSymbolSet destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSymbolSet::~CSymbolSet()
    {
        for( auto& symbol : m_symbolVector )
        {
            MD_SAFE_DELETE_ARRAY( symbol->symbol_1_0.SymbolName );
            if( symbol->symbol_1_0.SymbolTypedValue.ValueType == VALUE_TYPE_CSTRING )
            {
                MD_SAFE_DELETE_ARRAY( symbol->symbol_1_0.SymbolTypedValue.ValueCString );
            }
            else if( symbol->symbol_1_0.SymbolTypedValue.ValueType == VALUE_TYPE_BYTEARRAY )
            {
                MD_SAFE_DELETE_ARRAY( symbol->symbol_1_0.SymbolTypedValue.ValueByteArray->Data );
                MD_SAFE_DELETE( symbol->symbol_1_0.SymbolTypedValue.ValueByteArray );
            }
        }

        ClearVector( m_symbolVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbolCount
    //
    // Description:
    //     Returns symbol count.
    //
    // Output:
    //     uint32_t -  symbol count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSymbolSet::GetSymbolCount()
    {
        return m_symbolVector.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbol
    //
    // Description:
    //     Returns chosen symbol or null if not exists.
    //
    // Input:
    //     uint32_t index      - index of symbol
    //
    // Output:
    //     TGlobalSymbol_1_0*  - pointer to the symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TGlobalSymbol_1_0* CSymbolSet::GetSymbol( uint32_t index )
    {
        if( index < m_symbolVector.size() && m_symbolVector[index] )
        {
            return &( m_symbolVector[index]->symbol_1_0 );
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     GetSymbolValueByName
    //
    // Description:
    //     Returns chosen symbol by name or nullptr if not exists.
    //
    // Input:
    //     const char * name   - name of symbol
    //
    // Output:
    //     TTypedValue_1_0*    - pointer to symbol
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0* CSymbolSet::GetSymbolValueByName( const char* name )
    {
        MD_CHECK_PTR_RET( name, nullptr );

        for( auto& symbol : m_symbolVector )
        {
            if( symbol && ( strcmp( name, symbol->symbol_1_0.SymbolName ) == 0 ) )
            {
                return &( symbol->symbol_1_0.SymbolTypedValue );
            }
        }

        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbol
    //
    // Description:
    //     Adds symbol to symbol set.
    //
    // Input:
    //     const char * name           - symbol name
    //     TTypedValue_1_0 typedValue  - symbol value
    //     TSymbolType symbolType      - symbol type
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbol( const char* name, TTypedValue_1_0 typedValue, TSymbolType symbolType )
    {
        MD_CHECK_PTR_RET( name, CC_ERROR_GENERAL );
        MD_LOG( LOG_DEBUG, "%s - adding...", name );
        TCompletionCode ret = CC_OK;

        if( symbolType == SYMBOL_TYPE_DETECT )
        {
            // if it is a CString or a ByteArray, a memory is allocated here
            ret = DetectSymbolValue( name, &typedValue );

            if( ret == CC_ERROR_NOT_SUPPORTED )
            {
                MD_LOG( LOG_INFO, "Symbol is not supported." );
                // do nothing if a symbol is not supported and return success
                return CC_OK;
            }

            MD_CHECK_CC_RET( ret );
        }

        TGlobalSymbol* symbol = (TGlobalSymbol*) new( std::nothrow ) TGlobalSymbol;
        MD_CHECK_PTR_RET( symbol, CC_ERROR_NO_MEMORY );

        symbol->version               = API_VERSION_1_0;
        symbol->symbolType            = symbolType;
        symbol->symbol_1_0.SymbolName = GetCopiedCString( name );
        if( typedValue.ValueType == VALUE_TYPE_CSTRING )
        {
            symbol->symbol_1_0.SymbolTypedValue.ValueType    = typedValue.ValueType;
            symbol->symbol_1_0.SymbolTypedValue.ValueCString = ( symbolType == SYMBOL_TYPE_DETECT )
                ? typedValue.ValueCString // CString is already copied
                : GetCopiedCString( typedValue.ValueCString );
        }
        else if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
        {
            symbol->symbol_1_0.SymbolTypedValue.ValueType      = typedValue.ValueType;
            symbol->symbol_1_0.SymbolTypedValue.ValueByteArray = ( symbolType == SYMBOL_TYPE_DETECT )
                ? typedValue.ValueByteArray // ByteArray is already copied
                : GetCopiedByteArray( typedValue.ValueByteArray );
        }
        else
        {
            symbol->symbol_1_0.SymbolTypedValue = typedValue;
        }
        m_symbolVector.push_back( symbol );

        if( typedValue.ValueType == VALUE_TYPE_BYTEARRAY )
        {
            // check if this ByteArray is a mask
            return UnpackMask( symbol );
        }

        MD_LOG( LOG_INFO, "Symbol added successfully." );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     DetectSymbolValue
    //
    // Description:
    //     Gets certain symbol's values sending escapes to KMD.
    //
    // Input:
    //     const char * name               - symbol name
    //     TTypedValue_1_0 * typedValue    - output value
    //
    // Output:
    //     TCompletionCode                 - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::DetectSymbolValue( const char* name, TTypedValue_1_0* typedValue )
    {
        TCompletionCode           ret = CC_OK;
        GTDIDeviceInfoParamExtOut out = {};

        if( strcmp( name, "EuCoresTotalCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "EuCoresPerSubsliceCount" ) == 0 )
        {
            uint32_t euCoresTotalCount   = 0;
            uint32_t subslicesTotalCount = 0;

            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            euCoresTotalCount = out.ValueUint32;

            {
                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, &out );
                MD_CHECK_CC_RET( ret );
                subslicesTotalCount = out.ValueUint32;
            }

            typedValue->ValueUInt32 = ( subslicesTotalCount != 0 ) ? euCoresTotalCount / subslicesTotalCount : 0;
        }
        else if( strcmp( name, "EuSubslicesTotalCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "EuSubslicesPerSliceCount" ) == 0 )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }
        else if( strcmp( name, "EuDualSubslicesTotalCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "EuSlicesTotalCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_COUNT, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "EuThreadsCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_THREADS_COUNT, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( ( strcmp( name, "SliceMask" ) == 0 ) || ( strcmp( name, "GtSliceMask" ) == 0 ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_MASK, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            if( typedValue->ValueType == VALUE_TYPE_BYTEARRAY )
            {
                TByteArray_1_0 byteArray   = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue->ValueByteArray = GetCopiedByteArray( &byteArray );
            }
            else
            {
                typedValue->ValueUInt32 = out.ValueUint32;
            }
        }
        else if( ( strcmp( name, "SubsliceMask" ) == 0 ) || ( strcmp( name, "GtSubsliceMask" ) == 0 ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_MASK, &out );
            MD_CHECK_CC_RET( ret );
            if( typedValue->ValueType == VALUE_TYPE_BYTEARRAY )
            {
                TByteArray_1_0 byteArray   = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue->ValueByteArray = GetCopiedByteArray( &byteArray );
            }
            else
            {
                typedValue->ValueUInt64 = out.ValueUint64;
            }
        }
        else if( ( strcmp( name, "DualSubsliceMask" ) == 0 ) || ( strcmp( name, "GtDualSubsliceMask" ) == 0 ) )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK, &out, &m_metricsDevice );
            MD_CHECK_CC_RET( ret );
            if( typedValue->ValueType == VALUE_TYPE_BYTEARRAY )
            {
                TByteArray_1_0 byteArray   = { sizeof( out.ValueByteArray ), out.ValueByteArray };
                typedValue->ValueByteArray = GetCopiedByteArray( &byteArray );
            }
            else
            {
                typedValue->ValueUInt64 = out.ValueUint64;
            }
        }

        else if( strcmp( name, "SamplersTotalCount" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SAMPLERS_COUNT, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "SamplersPerSubliceCount" ) == 0 )
        {
            // obsolete
            return CC_ERROR_NOT_SUPPORTED;
        }

        else if( strcmp( name, "MemoryPeakThroghputMB" ) == 0 )
        {
            if( m_metricsDevice.GetAdapter().GetParams()->Type == ADAPTER_TYPE_INTEGRATED )
            {
                ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT, &out );

                MD_CHECK_CC_RET( ret );
                typedValue->ValueUInt32 = static_cast<uint32_t>( out.ValueUint64 / static_cast<uint64_t>( MD_MBYTE ) );
            }
            else
            {
                return CC_ERROR_NOT_SUPPORTED;
            }
        }
        else if( strcmp( name, "MemoryFrequencyMHz" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_FREQUENCY, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
        }
        else if( strcmp( name, "GpuMinFrequencyMHz" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY, &out );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG( LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", name );
                ret = DetectSymbolValue( "GpuCurrentFrequencyMHz", typedValue );
                MD_CHECK_CC_RET( ret );
            }
            else
            {
                typedValue->ValueUInt32 = out.ValueUint32;
            }
        }
        else if( strcmp( name, "GpuMaxFrequencyMHz" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY, &out );

            if( ret != CC_OK )
            {
                // Possibly caused by disabled Turbo
                MD_LOG( LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", name );
                ret = DetectSymbolValue( "GpuCurrentFrequencyMHz", typedValue );
                MD_CHECK_CC_RET( ret );
            }
            else
            {
                typedValue->ValueUInt32 = out.ValueUint32;
            }
        }
        else if( strcmp( name, "GpuCurrentFrequencyMHz" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
        }

        else if( strcmp( name, "PciDeviceId" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PCI_DEVICE_ID, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "SkuRevisionId" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_REVISION_ID, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
            MD_LOG( LOG_INFO, "SkuRevisionId is %u", typedValue->ValueUInt32 );
        }
        else if( strcmp( name, "PlatformIndex" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
            MD_LOG( LOG_INFO, "PlatformIndex is %u", typedValue->ValueUInt32 );
        }
        else if( strcmp( name, "ApertureSize" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_APERTURE_SIZE, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "Capabilities" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "PavpDisabled" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueBool = IsPavpDisabled( out.ValueUint32 );
        }

        else if( strcmp( name, "NumberOfRenderOutputUnits" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "NumberOfShadingUnits" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }

        else if( strcmp( name, "OABufferMinSize" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }
        else if( strcmp( name, "OABufferMaxSize" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = out.ValueUint32;
        }

        else if( strcmp( name, "GpuTimestampFrequency" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = (uint32_t) out.ValueUint64;
        }
        else if( strcmp( name, "EdramSize" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EDRAM_SIZE, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = (uint32_t) out.ValueUint64;
        }
        else if( strcmp( name, "LLCSize" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_LLC_SIZE, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = (uint32_t) out.ValueUint64;
        }
        else if( strcmp( name, "L3Size" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_SIZE, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt32 = (uint32_t) out.ValueUint64;
        }
        else if( strcmp( name, "MaxTimestamp" ) == 0 )
        {
            ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
            MD_CHECK_CC_RET( ret );
            typedValue->ValueUInt64 = MD_GPU_TIMESTAMP_MASK * MD_SECOND_IN_NS / out.ValueUint64;
        }
        else
        {
            MD_LOG( LOG_ERROR, "Unknown global symbol name: %s", name );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolUINT32
    //
    // Description:
    //     Adds 32-bit uint32_t symbol to the symbol set.
    //
    // Input:
    //     const char * name       - symbol name
    //     uint32_t     value      - symbol value
    //     TSymbolType symbolType  - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolUINT32( const char* name, uint32_t value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType   = VALUE_TYPE_UINT32;
        typedValue.ValueUInt32 = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolUINT64
    //
    // Description:
    //     Adds 64-bit uint64_t symbol to the symbol set.
    //
    // Input:
    //     const char*  name       - symbol name
    //     uint64_t     value      - symbol value
    //     TSymbolType  symbolType - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType   = VALUE_TYPE_UINT64;
        typedValue.ValueUInt64 = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolBOOL
    //
    // Description:
    //     Adds boolean symbol to the symbol set.
    //
    // Input:
    //     const char * name       - symbol name
    //     bool value              - symbol value
    //     TSymbolType symbolType  - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolBOOL( const char* name, bool value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType = VALUE_TYPE_BOOL;
        typedValue.ValueBool = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolFLOAT
    //
    // Description:
    //     Adds float symbol to the symbol set.
    //
    // Input:
    //     const char * name       - symbol name
    //     float value             - symbol value
    //     TSymbolType symbolType  - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType  = VALUE_TYPE_FLOAT;
        typedValue.ValueFloat = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolCSTRING
    //
    // Description:
    //     Adds cstring symbol to the symbol set.
    //
    // Input:
    //     const char * name       - symbol name
    //     const char * value      - symbol value
    //     TSymbolType symbolType  - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolCSTRING( const char* name, char* value, TSymbolType symbolType )
    {
        TCompletionCode ret = CC_OK;
        TTypedValue_1_0 typedValue;
        typedValue.ValueType    = VALUE_TYPE_CSTRING;
        typedValue.ValueCString = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     AddSymbolBYTEARRAY
    //
    // Description:
    //     Adds byte array symbol to the symbol set.
    //
    // Input:
    //     const char * name       - symbol name
    //     TByteArray_1_0 * value  - symbol value
    //     TSymbolType symbolType  - symbol type
    //
    // Output:
    //     TCompletionCode         - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::AddSymbolBYTEARRAY( const char* name, TByteArray_1_0* value, TSymbolType symbolType )
    {
        TCompletionCode ret        = CC_OK;
        TTypedValue_1_0 typedValue = {};

        typedValue.ValueType      = VALUE_TYPE_BYTEARRAY;
        typedValue.ValueByteArray = value;

        ret = AddSymbol( name, typedValue, symbolType );

        MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     WriteSymbolSetToFile
    //
    // Description:
    //     Writes symbol set to a file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::WriteSymbolSetToFile( FILE* metricFile )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT( metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        uint32_t symbolCount = m_symbolVector.size();
        fwrite( &symbolCount, sizeof( symbolCount ), 1, metricFile );
        for( auto& symbol : m_symbolVector )
        {
            // symbol_1_0
            WriteCStringToFile( symbol->symbol_1_0.SymbolName, metricFile );
            WriteTTypedValueToFile( &symbol->symbol_1_0.SymbolTypedValue, metricFile );
            fwrite( &symbol->symbolType, sizeof( symbol->symbolType ), 1, metricFile );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     IsSymbolAlreadyAdded
    //
    // Description:
    //     Checks if the symbol of the given name is already added to the symbol set.
    //
    // Input:
    //     const char* symbolName  - symbolic name of a symbol to check
    //
    // Output:
    //     bool                    - true when already added
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSymbolSet::IsSymbolAlreadyAdded( const char* symbolName )
    {
        return ( GetSymbolValueByName( symbolName ) != nullptr );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     RedetectSymbol
    //
    // Description:
    //     Redetects (updates) the symbol value.
    //
    // Input:
    //     const char * name - name of a symbol to redetect
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::RedetectSymbol( const char* symbolName )
    {
        TTypedValue_1_0* symbolValue = GetSymbolValueByName( symbolName );
        if( !symbolValue )
        {
            MD_LOG( LOG_DEBUG, "Symbol doesn't exist, name: %s", symbolName );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return DetectSymbolValue( symbolName, symbolValue );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     IsPavpDisabled
    //
    // Description:
    //     Checks if the PAVP_DISABLED bit in capabilities symbol is set.
    //
    // Output:
    //     bool - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSymbolSet::IsPavpDisabled( uint32_t capabilities )
    {
        return ( capabilities & GTDI_CAPABILITY_PAVP_DISABLED ) > 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     UnpackMask
    //
    // Description:
    //     Generate a separate global symbol for each instance from the mask
    //
    // Input:
    //     const TGlobalSymbol* symbol  - global symbol handle
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::UnpackMask( const TGlobalSymbol* symbol )
    {
        const char*     name      = symbol->symbol_1_0.SymbolName;
        uint8_t*        mask      = symbol->symbol_1_0.SymbolTypedValue.ValueByteArray->Data;
        TTypedValue_1_0 boolValue = { VALUE_TYPE_BOOL, true };

        // Unpack mask
        if( strcmp( name, "GtSliceMask" ) == 0 )
        {
            for( uint32_t i = 0; i < m_maxSlice; i++ )
            {
                uint32_t currentByte = i / MD_BITS_PER_BYTE;
                uint32_t currentBit  = i % MD_BITS_PER_BYTE;

                if( mask[currentByte] & MD_BIT( currentBit ) )
                {
                    std::string dynamicSymbolName = "GtSlice" + std::to_string( i );
                    AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                }
            }
        }
        else if( strcmp( name, "GtSubsliceMask" ) == 0 )
        {
            for( uint32_t i = 0; i < m_maxSlice; i++ )
            {
                for( uint32_t j = 0; j < m_maxSubslicePerSlice; j++ )
                {
                    uint32_t currentByte = ( i * m_maxSubslicePerSlice + j ) / MD_BITS_PER_BYTE;
                    uint32_t currentBit  = ( i * m_maxSubslicePerSlice + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtSlice" + std::to_string( i ) + "Subslice" + std::to_string( j );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );
                    }
                }
            }
        }
        else if( strcmp( name, "GtDualSubsliceMask" ) == 0 )
        {
            TTypedValue_1_0 activeDualSubsliceForHalfSlices = { VALUE_TYPE_UINT32, 0 };
            TPlatformType   platformType                    = m_metricsDevice.GetPlatformType();
            uint32_t        halfOfAvailableSlices           = m_maxSlice / 2;

            for( uint32_t i = 0; i < m_maxSlice; i++ )
            {
                for( uint32_t j = 0; j < m_maxDualSubslicePerSlice; j++ )
                {
                    uint32_t currentByte = ( i * m_maxDualSubslicePerSlice + j ) / MD_BITS_PER_BYTE;
                    uint32_t currentBit  = ( i * m_maxDualSubslicePerSlice + j ) % MD_BITS_PER_BYTE;

                    if( mask[currentByte] & MD_BIT( currentBit ) )
                    {
                        std::string dynamicSymbolName = "GtSlice" + std::to_string( i ) + "DualSubslice" + std::to_string( j );
                        AddSymbol( dynamicSymbolName.c_str(), boolValue, SYMBOL_TYPE_IMMEDIATE );

                        // Count active dual subslices for a half of available slices
                        if( i < halfOfAvailableSlices )
                        {
                            ++activeDualSubsliceForHalfSlices.ValueUInt32;
                        }
                    }
                }
            }
        }
        else
        {
            MD_LOG( LOG_WARNING, "%s - unknown mask, cannot unpack", name );
        }

        return CC_OK;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSymbolSet
    //
    // Method:
    //     DetectMaxSlicesInfo
    //
    // Description:
    //     Gets information about max slices, max subslices per slice and
    //     max dual subslices per slice sending escapes to KMD.
    //
    // Output:
    //     TCompletionCode - result of the operation
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSymbolSet::DetectMaxSlicesInfo()
    {
        TCompletionCode           ret = CC_OK;
        GTDIDeviceInfoParamExtOut out = {};

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SLICE, &out );
        MD_CHECK_CC_RET( ret )
        m_maxSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE, &out );
        MD_CHECK_CC_RET( ret )
        m_maxSubslicePerSlice = out.ValueUint32;

        ret = m_driverInterface.SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE, &out );
        MD_CHECK_CC_RET( ret )
        m_maxDualSubslicePerSlice = out.ValueUint32;

        return CC_OK;
    }

} // namespace MetricsDiscoveryInternal
