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

    File Name:  md_internal.cpp

    Abstract:   C++ Metrics Discovery internal implementation

\*****************************************************************************/
#include "md_internal.h"

#include <string.h>
#include <stdlib.h>
#include <new>

using namespace MetricsDiscovery;

namespace MetricsDiscovery
{
    IEquation_1_0::~IEquation_1_0() {}
    uint32_t                    IEquation_1_0::GetEquationElementsCount( void )                         { return 0; }
    TEquationElement_1_0*       IEquation_1_0::GetEquationElement( uint32_t index )                     { return NULL; }

    IMetricsDevice_1_0::~IMetricsDevice_1_0() {}
    TMetricsDeviceParams_1_0*   IMetricsDevice_1_0::GetParams( void )                                   { return NULL; }
    IConcurrentGroup_1_0*       IMetricsDevice_1_0::GetConcurrentGroup( uint32_t index )                { return NULL; }
    TGlobalSymbol_1_0*          IMetricsDevice_1_0::GetGlobalSymbol( uint32_t index )                   { return NULL; }
    TTypedValue_1_0*            IMetricsDevice_1_0::GetGlobalSymbolValueByName( const char* name )      { return NULL; }
    TCompletionCode             IMetricsDevice_1_0::GetLastError( void )                                { return CC_LAST_1_0; }
    TCompletionCode             IMetricsDevice_1_0::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs,
                                    uint32_t* cpuId )                                                   { return CC_ERROR_NOT_SUPPORTED; }
    IConcurrentGroup_1_1*       IMetricsDevice_1_1::GetConcurrentGroup( uint32_t index )                { return NULL; }
    TMetricsDeviceParams_1_2*   IMetricsDevice_1_2::GetParams( void )                                   { return NULL; }
    IOverride_1_2*              IMetricsDevice_1_2::GetOverride( uint32_t index )                       { return NULL; }
    IOverride_1_2*              IMetricsDevice_1_2::GetOverrideByName( const char* name )               { return NULL; }
    IConcurrentGroup_1_5*       IMetricsDevice_1_5::GetConcurrentGroup( uint32_t index )                { return NULL; }

    IOverride_1_2::~IOverride_1_2() {}
    TOverrideParams_1_2*        IOverride_1_2::GetParams( void )                                        { return NULL; }
    TCompletionCode             IOverride_1_2::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
                                                                                                        { return CC_ERROR_NOT_SUPPORTED; }

    IConcurrentGroup_1_0::~IConcurrentGroup_1_0() {}
    TConcurrentGroupParams_1_0* IConcurrentGroup_1_0::GetParams( void )                                 { return NULL; }
    IMetricSet_1_0*             IConcurrentGroup_1_0::GetMetricSet( uint32_t index )                    { return NULL; }
    TCompletionCode             IConcurrentGroup_1_0::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod,
                                    uint32_t* oaBufferSize )                                            { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IConcurrentGroup_1_0::ReadIoStream( uint32_t* reportsCount, char* reportData, uint32_t readFlags )
                                                                                                        { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IConcurrentGroup_1_0::CloseIoStream( void )                             { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IConcurrentGroup_1_0::WaitForReports( uint32_t milliseconds )           { return CC_ERROR_NOT_SUPPORTED; }
    IInformation_1_0*           IConcurrentGroup_1_0::GetIoMeasurementInformation( uint32_t index )     { return NULL; }
    IInformation_1_0*           IConcurrentGroup_1_0::GetIoGpuContextInformation( uint32_t index )      { return NULL; }

    IMetricSet_1_1*             IConcurrentGroup_1_1::GetMetricSet( uint32_t index )                    { return NULL; }
    TCompletionCode             IConcurrentGroup_1_3::SetIoStreamSamplingType( TSamplingType type )     { return CC_ERROR_NOT_SUPPORTED; };
    IMetricSet_1_5*             IConcurrentGroup_1_5::GetMetricSet( uint32_t index )                    { return NULL; }

    IMetricSet_1_0::~IMetricSet_1_0() {}
    TMetricSetParams_1_0*       IMetricSet_1_0::GetParams( void )                                       { return NULL; }
    IMetric_1_0*                IMetricSet_1_0::GetMetric( uint32_t index )                             { return NULL; }
    IInformation_1_0*           IMetricSet_1_0::GetInformation( uint32_t index )                        { return NULL; }
    IMetricSet_1_0*             IMetricSet_1_0::GetComplementaryMetricSet( uint32_t index  )            { return NULL; }
    TCompletionCode             IMetricSet_1_0::Activate( void )                                        { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IMetricSet_1_0::Deactivate( void )                                      { return CC_ERROR_NOT_SUPPORTED; }
    IMetric_1_0*                IMetricSet_1_0::AddCustomMetric( const char* symbolicName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias,
                                    uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType,
                                    int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction,
                                    const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName )
                                                                                                        { return NULL; }

    IMetricSet_1_1::~IMetricSet_1_1() {}
    TCompletionCode             IMetricSet_1_1::SetApiFiltering( uint32_t apiMask )                     { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IMetricSet_1_1::CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize,
                                    uint32_t* outReportCount, bool enableContextFiltering )             { return CC_ERROR_NOT_SUPPORTED; }
    TCompletionCode             IMetricSet_1_1::CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize )
                                                                                                        { return CC_ERROR_NOT_SUPPORTED; }
    IMetricSet_1_4::~IMetricSet_1_4() {}
    TMetricSetParams_1_4*       IMetricSet_1_4::GetParams( void )                                       { return NULL; }

    IMetricSet_1_5*             IMetricSet_1_5::GetComplementaryMetricSet( uint32_t index )             { return NULL; }
    TCompletionCode             IMetricSet_1_5::CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize,
                                    uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
                                                                                                        { return CC_ERROR_NOT_SUPPORTED; }

    IMetric_1_0::~IMetric_1_0() {}
    TMetricParams_1_0*          IMetric_1_0 ::GetParams()                                               { return NULL; }

    IInformation_1_0::~IInformation_1_0() {}
    TInformationParams_1_0*     IInformation_1_0::GetParams()                                           { return NULL; }

    // Internal API
    IInternalConcurrentGroup::~IInternalConcurrentGroup() {}
    IMetricSet_1_5*             IInternalConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly )
                                                                                                        { return NULL; }

    IInternalMetricSet::~IInternalMetricSet() {}
    IMetric_1_0*                IInternalMetricSet::AddCustomMetric( TAddCustomMetricParams* params )   { return NULL; }
}

namespace MetricsDiscoveryInternal
{
static TMetricGroupNameIdPair GroupNamePairs[] = {
        { "GPU",               METRIC_GROUP_NAME_ID_GPU,        METRIC_GROUP_LEVEL_0 },
        { "GTI",               METRIC_GROUP_NAME_ID_GTI,        METRIC_GROUP_LEVEL_0 },
        { "LLC",               METRIC_GROUP_NAME_ID_LLC,        METRIC_GROUP_LEVEL_0 },
        { "EDRAM",             METRIC_GROUP_NAME_ID_EDRAM,      METRIC_GROUP_LEVEL_0 },
        { "DRAM",              METRIC_GROUP_NAME_ID_DRAM,       METRIC_GROUP_LEVEL_0 },
        { "EU Array",          METRIC_GROUP_NAME_ID_EU_ARRAY,   METRIC_GROUP_LEVEL_0 },
        { "Sampler",           METRIC_GROUP_NAME_ID_SAMPLER,    METRIC_GROUP_LEVEL_0 },
        { "Uncore",            METRIC_GROUP_NAME_UNCORE,        METRIC_GROUP_LEVEL_0 },
        { "Memory Controller", METRIC_GROUP_NAME_UNCORE_MC,     METRIC_GROUP_LEVEL_0 },
        { "3D Pipe",           METRIC_GROUP_NAME_ID_3D_PIPE,    METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "VE Pipe",           METRIC_GROUP_NAME_ID_VE_PIPE,    METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "VD Pipe",           METRIC_GROUP_NAME_ID_VD_PIPE,    METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "WD Pipe",           METRIC_GROUP_NAME_ID_WD_PIPE,    METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "VME Pipe",          METRIC_GROUP_NAME_ID_VME_PIPE,   METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "L3",                METRIC_GROUP_NAME_ID_L3,         METRIC_GROUP_LEVEL_0|METRIC_GROUP_LEVEL_1 },
        { "Thread Dispatcher", METRIC_GROUP_NAME_ID_TD,                              METRIC_GROUP_LEVEL_1 },
        { "Rasterizer",        METRIC_GROUP_NAME_ID_WM,                              METRIC_GROUP_LEVEL_1 },
        { "Data Port",         METRIC_GROUP_NAME_ID_DATA_PORT,                       METRIC_GROUP_LEVEL_1 },
        { "IME Pipe",          METRIC_GROUP_NAME_ID_IME_PIPE,                        METRIC_GROUP_LEVEL_1 },
        { "CRE Pipe",          METRIC_GROUP_NAME_ID_CRE_PIPE,                        METRIC_GROUP_LEVEL_1 },
        { "Instruction Cache", METRIC_GROUP_NAME_ID_IC,                              METRIC_GROUP_LEVEL_1 },
        { "IC",                METRIC_GROUP_NAME_ID_IC,                              METRIC_GROUP_LEVEL_1 },
        { "Sampler",           METRIC_GROUP_NAME_ID_SAMPLER,                         METRIC_GROUP_LEVEL_1 },
        { "Pipes",             METRIC_GROUP_NAME_ID_EU_PIPES,                        METRIC_GROUP_LEVEL_1 },
        { "Color Cache",       METRIC_GROUP_NAME_ID_RCC,                             METRIC_GROUP_LEVEL_1 },
        { "Sampler Input",     METRIC_GROUP_NAME_ID_SAMPLER_IN,                      METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Sampler Cache",     METRIC_GROUP_NAME_ID_SAMPLER_CACHE,                   METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Sampler Filter",    METRIC_GROUP_NAME_ID_SAMPLER_FL,                      METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Sampler Output",    METRIC_GROUP_NAME_ID_SAMPLER_OUT,                     METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "TAG",               METRIC_GROUP_NAME_ID_L3_TAG,                          METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Instructions",      METRIC_GROUP_NAME_ID_EU_INSTR,                        METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Barrier",           METRIC_GROUP_NAME_ID_EU_BARRIER,                      METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Input Assembler",   METRIC_GROUP_NAME_ID_IA,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Vertex Shader",     METRIC_GROUP_NAME_ID_VS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Hull Shader",       METRIC_GROUP_NAME_ID_HS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Control Shader",    METRIC_GROUP_NAME_ID_HS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Tesselator",        METRIC_GROUP_NAME_ID_TE,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Domain Shader",     METRIC_GROUP_NAME_ID_DS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Evaluation Shader", METRIC_GROUP_NAME_ID_DS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Geometry Shader",   METRIC_GROUP_NAME_ID_GS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Stream Output",     METRIC_GROUP_NAME_ID_SO,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Clipper",           METRIC_GROUP_NAME_ID_CL,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Pixel Shader",      METRIC_GROUP_NAME_ID_PS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Fragment Shader",   METRIC_GROUP_NAME_ID_PS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Output Merger",     METRIC_GROUP_NAME_ID_OM,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Compute Shader",    METRIC_GROUP_NAME_ID_CS,                              METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "SLM",               METRIC_GROUP_NAME_ID_SLM,                             METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "URB",               METRIC_GROUP_NAME_ID_URB,                             METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Depth Cache",       METRIC_GROUP_NAME_ID_RCZ,                             METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Stencil Cache",     METRIC_GROUP_NAME_ID_STC,                             METRIC_GROUP_LEVEL_1|METRIC_GROUP_LEVEL_2 },
        { "Atomics",           METRIC_GROUP_NAME_ID_ATOMICS,                                              METRIC_GROUP_LEVEL_2 },
        { "Strip-Fans",        METRIC_GROUP_NAME_ID_SF,                                                   METRIC_GROUP_LEVEL_2 },
        { "Early Depth Test",  METRIC_GROUP_NAME_ID_IZ,                                                   METRIC_GROUP_LEVEL_2 },
        { "Hi-Depth Test",     METRIC_GROUP_NAME_ID_HZ,                                                   METRIC_GROUP_LEVEL_2 },
        { "Barycentric Calc",  METRIC_GROUP_NAME_ID_BC,                                                   METRIC_GROUP_LEVEL_2 },
        { "Command Streamer",  METRIC_GROUP_NAME_ID_RCS,                                                  METRIC_GROUP_LEVEL_2 },
        { "Resource Streamer", METRIC_GROUP_NAME_ID_RS,                                                   METRIC_GROUP_LEVEL_2 },
        { "Vertex Fetch",      METRIC_GROUP_NAME_ID_VF,                                                   METRIC_GROUP_LEVEL_2 }
};

static CDriverInterface* g_driverInterface = NULL;

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    GetDriverInterface

Description:
    Obtains object to the driver interface.

Output:
    CDriverInterface* - driver interface

\*****************************************************************************/
CDriverInterface* GetDriverIfc()
{
    if( g_driverInterface == NULL )
    {
        g_driverInterface = CDriverInterface::GetInstance();
    }

    return g_driverInterface;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    DestoryDriverInterface

Description:
    Destroys driver interface

\*****************************************************************************/
void DestroyDriverIfc()
{
    MD_SAFE_DELETE( g_driverInterface );
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    GetOpenCloseSemaphore

Description:
    Creates / Opens semaphore and waits 1s if needed. *CC_OK* if wait was successful.

Input:
    void** semaphorePtr - (out) pointer to the newly created sempahore

Output:
    TCompletionCode     - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode GetOpenCloseSemaphore( void** semaphorePtr )
{
    MD_LOG_ENTER();
    TCompletionCode   retVal          = CC_OK;
    CDriverInterface* driverInterface = GetDriverIfc();
    MD_CHECK_PTR_RET( driverInterface, CC_ERROR_NO_MEMORY );

    if( !(*semaphorePtr) )
    {
        if( driverInterface->SemaphoreCreate( "OpenClose", semaphorePtr ) != CC_OK )
        {
            MD_LOG(LOG_ERROR, "semaphore create failed");
            return CC_ERROR_GENERAL;
        }
    }

    TSemaphoreWaitResult result = driverInterface->SemaphoreWait( 1000L, *semaphorePtr ); // Wait 1 sec
    switch( result )
    {
        case WAIT_RESULT_SUCCESSFUL: // The semaphore object was signaled
            MD_LOG(LOG_DEBUG, "semaphore wait successful");
            retVal = CC_OK;
            break;

        case WAIT_RESULT_TIMEOUT: // A time-out occurred
            MD_LOG(LOG_DEBUG, "semaphore wait timeout");
            retVal = CC_ERROR_GENERAL;
            break;

        default:
            retVal = CC_ERROR_GENERAL;
            MD_LOG(LOG_ERROR, "semaphore wait error");
            break;
    }

    MD_LOG_EXIT();
    return retVal;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    ReleaseOpenCloseSemaphore

Description:
    Releases semaphore.

Input:
    void** semaphore - pointer to the semaphore

Output:
    TCompletionCode  - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode ReleaseOpenCloseSemaphore( void** semaphore )
{
    MD_LOG_ENTER();
    CDriverInterface* driverInterface = GetDriverIfc();
    MD_CHECK_PTR_RET( driverInterface, CC_ERROR_NO_MEMORY );

    if( driverInterface->SemaphoreRelease( semaphore ) != CC_OK )
    {
        // ERROR while releasing semaphore
        MD_LOG(LOG_ERROR, "semaphore release failed");
        return CC_ERROR_GENERAL;
    }

    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    WriteEquationToFile

Description:
    Writes CEquation class to file. If it's equal to null 0xFF will be written.

Input:
    CEquation* equation    - CEquation to be written
    FILE*      metricFile  - handle to metric file

Output:
    TCompletionCode        - result

\*****************************************************************************/
static TCompletionCode WriteEquationToFile( CEquation* equation, FILE* metricFile )
{
    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
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

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    SetDeltaFunction

Description:
    Sets the delta function from parsed string.

Input:
    const char* equationString - equation string, could be empty
    TDeltaFunction_1_0*        - (out) delta function

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
static TCompletionCode SetDeltaFunction( const char* equationString, TDeltaFunction_1_0* deltaFunction )
{
    if( equationString == NULL || strcmp( equationString, "" ) == 0 )
    {
        deltaFunction->FunctionType = DELTA_FUNCTION_NULL;
        return CC_OK;
    }
    if( strncmp( equationString, "DELTA", sizeof( "DELTA" ) - 1 ) == 0 )
    {
        deltaFunction->FunctionType = DELTA_N_BITS;
        if( equationString[5] == ' ' )
        {
            deltaFunction->BitsCount = strtoul( (char*)&equationString[6], NULL, 10 );
        }
        else
        {
            deltaFunction->BitsCount = strtoul( (char*)&equationString[5], NULL, 10 );
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

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    SetEquation

Description:
    Sets the given equation.

Input:
    CMetricsDevice* device         - metric device
    CEquation**     equation       - pointer to the equation to be set
    const char*     equationString - euqation string, could be empty or null

Output:
    TCompletionCode            - result of the operation

\*****************************************************************************/
static TCompletionCode SetEquation( CMetricsDevice* device, CEquation** equation, const char* equationString )
{
    MD_CHECK_PTR_RET( device, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( equation, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret = CC_OK;

    // Delete previous equation if any
    MD_SAFE_DELETE( *equation );

    // NULL is fine condition for "" equations
    if( equationString != NULL && strcmp( equationString, "" ) != 0 )
    {
        *equation = (CEquation *) new (std::nothrow) CEquation( device );
        if( *equation == NULL || !(*equation)->ParseEquationString( equationString ) )
        {
            MD_SAFE_DELETE( *equation );
            ret = CC_ERROR_GENERAL;
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    COverrideCommon

Method:
    COverrideCommon

Description:
    Common override class constructor.

\*****************************************************************************/
COverrideCommon::COverrideCommon( void )
{
    m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
}

/*****************************************************************************\

Class:
    COverrideCommon

Method:
    GetParamsInternal

Description:
    Returns internal parameters for a given override.

Output:
    const TOverrideInternalParams* - internal override parameters.

\*****************************************************************************/
const TOverrideInternalParams* COverrideCommon::GetParamsInternal( void )
{
    return &m_internalParams;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_FREQUENCY>

Method:
    COverride

Description:
    Frequency override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_FREQUENCY>::COverride( CMetricsDevice* device )
{
    m_device                  = device;

    m_params.SymbolName       = "FrequencyOverride";
    m_params.Description      = "Overrides device GPU frequency with a static value.";
    m_params.ApiMask          = (uint32_t) API_TYPE_ALL;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_NULL_HARDWARE>

Method:
    COverride

Description:
    Null Hardware override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_NULL_HARDWARE>::COverride( CMetricsDevice* device )
{
    m_device                  = device;

    m_params.SymbolName       = "Null Hardware";
    m_params.Description      = "Do not send primitives to the hardware rasterizer.";
    m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_NULL_HARDWARE;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>

Method:
    COverride

Description:
    Flush GPU caches override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>::COverride( CMetricsDevice* device )
{
    m_device                  = device;

    m_params.SymbolName       = "Flush GPU caches";
    m_params.Description      = "Flushes all GPU caches.";
    m_params.ApiMask          = API_TYPE_DX12 | API_TYPE_VULKAN;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_LOCAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_FLUSH_GPU_CACHES;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_EXTENDED_QUERY>

Method:
    COverride

Description:
    Extended query override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::COverride( CMetricsDevice* device )
{
    m_device                  = device;

    m_params.SymbolName       = "Extended query";
    m_params.Description      = "Enables extended query mode.";
    m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>

Method:
    COverride

Description:
    Multisampled query override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::COverride( CMetricsDevice* device )
{
    m_device                  = device;

    m_params.SymbolName       = "Multisampled query";
    m_params.Description      = "Enables multisampled query mode.";
    m_params.ApiMask          = API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_OGL | API_TYPE_DX12 | API_TYPE_VULKAN;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>

Method:
    COverride

Description:
    Frequency change reports override constructor.

Input:
    CMetricsDevice* device - parent metrics devcice

\*****************************************************************************/
template<>
COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::COverride(CMetricsDevice* device)
{
    m_device                  = device;

    m_params.SymbolName       = "FrequencyChangeReports";
    m_params.Description      = "Allows to toggle frequency change reports.";
    m_params.ApiMask          = (uint32_t) API_TYPE_IOSTREAM;
    m_params.PlatformMask     = (uint32_t) PLATFORM_ALL;
    m_params.OverrideModeMask = OVERRIDE_MODE_GLOBAL;

    m_internalParams.QueryOverrideId = OVERRIDE_ID_NOT_AVAILABLE;
}

/*****************************************************************************\

Class:
    COverride

Method:
    ~COverride

Description:
    Generic COverride destructor.

\*****************************************************************************/
template<TOverrideType overrideType>
COverride<overrideType>::~COverride()
{

}

/*****************************************************************************\

Class:
    COverride

Method:
    GetParams

Description:
    Returns override params.

Output:
    TOverrideParams_1_2* - override params

\*****************************************************************************/
template<TOverrideType overrideType>
TOverrideParams_1_2* COverride<overrideType>::GetParams( void )
{
    return &m_params;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_FREQUENCY>

Method:
    SetOverride

Description:
    Enabled or disables frequency override. Requires override specific
    params to be passed in place of *params*: TSetFrequencyOverrideParams_1_2.

Input:
    TSetOverrideParams_1_2* params     - params, should be TSetFrequencyOverrideParams_1_2*
    uint32_t                paramsSize - size of the passed params

Output:
    TCompletionCode                    - result, *CC_OK* means success

\*****************************************************************************/
template<>
TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_SIZE_RET( paramsSize, TSetFrequencyOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( !driverInterface )
    {
        MD_LOG( LOG_ERROR, "Error: could not find Driver Interface" );
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    TCompletionCode ret = CC_OK;
    TSetFrequencyOverrideParams_1_2* frequencyOverrideParams = static_cast<TSetFrequencyOverrideParams_1_2*>(params);

    ret = driverInterface->SetFrequencyOverride( frequencyOverrideParams );
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

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_EXTENDED_QUERY>

Method:
    SetOverride

Description:
    Enables or disables extended query mode. Requires override specific
    params to be passed in place of *params*: TSetQueryOverrideParams_1_2.

Input:
    TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    uint32_t                paramsSize - size of the passed params

Output:
    TCompletionCode                    - result, *CC_OK* means success

\*****************************************************************************/
template<>
TCompletionCode COverride<OVERRIDE_TYPE_EXTENDED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_SIZE_RET( paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( !driverInterface )
    {
        MD_LOG( LOG_ERROR, "Error: could not find Driver Interface" );
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    TTypedValue_1_0* oaBufferSize = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
    if( oaBufferSize == NULL )
    {
        MD_LOG( LOG_ERROR, "Unable to obtain maximum OA buffer size" );
        return CC_ERROR_GENERAL;
    }

    TSetQueryOverrideParams_1_2* queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>(params);
    TCompletionCode ret = driverInterface->SetQueryOverride( OVERRIDE_TYPE_EXTENDED_QUERY, m_device->GetPlatformType(), oaBufferSize->ValueUInt32, queryOverrideParams );
    if( ret != CC_OK )
    {
        MD_LOG( LOG_ERROR, "Setting extended query override failed, res: %u", ret );
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>

Method:
    SetOverride

Description:
    Enables or disables multisampled query mode. Requires override specific
    params to be passed in place of *params*: TSetQueryOverrideParams_1_2.

Input:
    TSetOverrideParams_1_2* params     - params, should be TSetQueryOverrideParams_1_2*
    uint32_t                paramsSize - size of the passed params

Output:
    TCompletionCode                    - result, *CC_OK* means success

\*****************************************************************************/
template<>
TCompletionCode COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_SIZE_RET( paramsSize, TSetQueryOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( !driverInterface )
    {
        MD_LOG( LOG_ERROR, "Error: could not find Driver Interface" );
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    TTypedValue_1_0* oaBufferSize = m_device->GetGlobalSymbolValueByName( "OABufferMaxSize" );
    if( oaBufferSize == NULL )
    {
        MD_LOG( LOG_ERROR, "Unable to obtain maximum OA buffer size" );
        return CC_ERROR_GENERAL;
    }

    TSetQueryOverrideParams_1_2* queryOverrideParams = static_cast<TSetQueryOverrideParams_1_2*>(params);
    TCompletionCode ret = driverInterface->SetQueryOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY, m_device->GetPlatformType(), oaBufferSize->ValueUInt32, queryOverrideParams );
    if( ret != CC_OK )
    {
        MD_LOG( LOG_ERROR, "Setting multisampled query override failed, res: %u", ret );
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>

Method:
    SetOverride

Description:
    Enabled or disables frequency change reports override. Requires override
    specific params to be passed in place of *params*: TSetOverrideParams_1_2.

Input:
    TSetOverrideParams_1_2* params     - params, should be TSetOverrideParams_1_2*
    uint32_t                paramsSize - size of the passed params

Output:
    TCompletionCode                    - result, *CC_OK* means success

\*****************************************************************************/
template<>
TCompletionCode COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_SIZE_RET( paramsSize, TSetOverrideParams_1_2, CC_ERROR_INVALID_PARAMETER );

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if (!driverInterface)
    {
        MD_LOG( LOG_ERROR, "Error: could not find Driver Interface" );
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    TCompletionCode ret = driverInterface->SetFreqChangeReportsOverride( params->Enable );
    if (ret != CC_OK)
    {
        MD_LOG( LOG_ERROR, "Setting frequency change reports override failed, res: %u", ret );
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COverride

Method:
    SetOverride

Description:
    Enables override.

Input:
    TSetOverrideParams_1_2* params     - params
    uint32_t                paramsSize - size of the passed params

Output:
    TCompletionCode                    - result, *CC_OK* means success

\*****************************************************************************/
template<TOverrideType overrideType>
TCompletionCode COverride<overrideType>::SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize )
{
    MD_LOG( LOG_ERROR, "Override %u not supported in global mode", overrideType );
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    CMetricsDevice constructor

Description:
    Constructor. Sends DeviceInfoParam escape.

\*****************************************************************************/
CMetricsDevice::CMetricsDevice()
{
    m_driverInterface = GetDriverIfc();

    m_params.DeltaFunctionsCount       = DELTA_FUNCTION_LAST_1_0;
    m_params.EquationOperationsCount   = EQUATION_OPER_LAST_1_0;
    m_params.EquationElementTypesCount = EQUATION_ELEM_LAST_1_0;

    m_params.Version.MajorNumber       = MD_API_MAJOR_NUMBER_CURRENT;
    m_params.Version.MinorNumber       = MD_API_MINOR_NUMBER_CURRENT;
    m_params.Version.BuildNumber       = MD_API_BUILD_NUMBER_CURRENT;

    m_params.GlobalSymbolsCount        = m_symbolSet.GetSymbolCount();
    m_params.ConcurrentGroupsCount     = 0;
    m_params.OverrideCount             = 0;

    m_groupsVector      = new (std::nothrow) Vector<CConcurrentGroup*>( GROUPS_VECTOR_INCREASE );
    m_overridesVector   = new (std::nothrow) Vector<IOverride_1_2*>( OVERRIDES_VECTOR_INCREASE );

    if( m_driverInterface )
    {
        GTDIDeviceInfoParamOut out;
        memset( &out, 0, sizeof(out) );
        TCompletionCode ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &out );
        m_platform          = ret == CC_OK ? (TPlatformType)( 1 << out.ValueUint32 ) : PLATFORM_UNKNOWN;

        m_params.DeviceName = GetCopiedCString( m_driverInterface->GetDeviceName() );

        ret                 = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GT_TYPE, &out );
        m_gtType            = ret == CC_OK ? (TGTType)( 1 << out.ValueUint32 ) : GT_TYPE_UNKNOWN;
    }
    else
    {
        m_platform = PLATFORM_UNKNOWN;
        m_params.DeviceName = NULL;
        m_gtType = GT_TYPE_UNKNOWN;
    }

    m_isOpenedFromFile = false;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    CMetricsDevice destructor

Description:
    Deallocates memory.

\*****************************************************************************/
CMetricsDevice::~CMetricsDevice()
{
    MD_SAFE_DELETE_ARRAY( m_params.DeviceName );
    MD_SAFE_DELETE( m_groupsVector );
    MD_SAFE_DELETE( m_overridesVector );
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetParams

Description:
    Returns metrics device params.

Output:
    TMetricsDeviceParams_1_0*  - pointer to metrics device params

\*****************************************************************************/
TMetricsDeviceParams_1_2* CMetricsDevice::GetParams( void )
{
    return &m_params;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetConcurrentGroup

Description:
    Returns chosen concurrent group or null if not exists.

Input:
    uint32_t index          - index of concurrent group

Output:
    IConcurrentGroup_1_5*   - pointer to concurrent group

\*****************************************************************************/
IConcurrentGroup_1_5* CMetricsDevice::GetConcurrentGroup( uint32_t index )
{
    MD_CHECK_PTR_RET( m_groupsVector, NULL );

    if( index < m_groupsVector->GetCount() )
    {
        return (*m_groupsVector)[ index ];
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetGlobalSymbol

Description:
    Returns chosen global symbol or null if not exists.

Input:
    uint32_t index      - index of global symbol

Output:
    TGlobalSymbol_1_0*  - pointer to global symbol

\*****************************************************************************/
TGlobalSymbol_1_0* CMetricsDevice::GetGlobalSymbol( uint32_t index )
{
    return m_symbolSet.GetSymbol( index );
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetGlobalSymbolValueByName

Description:
    Returns chosen global symbol by name or null if not exists.

Input:
    const char * name   - name of global symbol

Output:
    TTypedValue_1_0*    - pointer to global symbol

\*****************************************************************************/
TTypedValue_1_0* CMetricsDevice::GetGlobalSymbolValueByName( const char* name )
{
    return m_symbolSet.GetSymbolValueByName( name );
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetLastError

Description:
    Returns last error from enum TCompletionCode.

Output:
    TCompletionCode - last error from enum

\*****************************************************************************/
TCompletionCode CMetricsDevice::GetLastError()
{
    return CC_LAST_1_0;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetCpuGpuTimestamps

Description:
    Retrieves both GPU and CPU timestamp at the same time.

Input:
    uint64_t* gpuTimestampNs - (out) GPU timestamp in ns
    uint64_t* cpuTimestampNs - (out) CPU timestamp in ns
    uint32_t* cpuId          - (out) CPU id

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId )
{
    MD_CHECK_PTR_RET( m_driverInterface, CC_ERROR_GENERAL );

    if( !gpuTimestampNs && !cpuTimestampNs )
    {
        return CC_ERROR_INVALID_PARAMETER;
    }

    uint64_t gpuTS = 0, cpuTS = 0;
    uint32_t cpuID = 0;
    TCompletionCode ret = m_driverInterface->GetGpuCpuTimestamps( &gpuTS, &cpuTS, &cpuID );

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
    }

    return ret;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetOverride

Description:
    Returns the chosen override object or null if index doesn't exist.

Input:
    uint32_t index - index of an override

Output:
    IOverride_1_2* - chosen override object or null

\*****************************************************************************/
IOverride_1_2* CMetricsDevice::GetOverride( uint32_t index )
{
    MD_CHECK_PTR_RET( m_overridesVector, NULL );

    if( index < m_overridesVector->GetCount() )
    {
        return (*m_overridesVector)[index];
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetOverrideByName

Description:
    Returns the chosen override object or null if index doesn't exist.

Input:
    const char* symbolName - name of an override

Output:
    IOverride_1_2* - chosen override object or null

\*****************************************************************************/
IOverride_1_2* CMetricsDevice::GetOverrideByName( const char* symbolName )
{
    MD_CHECK_PTR_RET( m_overridesVector, NULL );
    MD_CHECK_PTR_RET( symbolName, NULL );

    for( uint32_t i = 0; i < m_overridesVector->GetCount(); i++ )
    {
        if( ((*m_overridesVector)[i]) && (strcmp( symbolName, (*m_overridesVector)[i]->GetParams()->SymbolName ) == 0) )
        {
            return (*m_overridesVector)[i];
        }
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    AddConcurrentGroup

Description:
    Adds concurrent group to the metrics device.

Input:
    const char * symbolicName   - concurrent group name
    const char * shortName      - concurrent group short name

Output:
    CConcurrentGroup*           - pointer to newly created concurrent group

\*****************************************************************************/
CConcurrentGroup* CMetricsDevice::AddConcurrentGroup( const char* symbolicName, const char* shortName, uint32_t measurementTypeMask )
{
    MD_CHECK_PTR_RET( m_groupsVector, NULL );

    CConcurrentGroup* group = NULL;
    if( strstr( symbolicName, "OA" ) != NULL )
    {
        group = ( COAConcurrentGroup* ) new (std::nothrow) COAConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
    }
    else if( strstr( symbolicName, "PerfMon" ) != NULL )
    {
        group = ( CPerfMonConcurrentGroup* ) new (std::nothrow) CPerfMonConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
    }
    else
    {
        group = ( CConcurrentGroup* ) new (std::nothrow) CConcurrentGroup( this, symbolicName, shortName, measurementTypeMask );
    }

    MD_CHECK_PTR_RET( group, NULL );

    m_groupsVector->PushBack(group);
    m_params.ConcurrentGroupsCount = m_groupsVector->GetCount();

    return group;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    AddOverride

Description:
    Adds the given override to MetricsDevice if available on current driver interface and
    platform.
    All the params are set in specialized constructors.

Output:
    IOverride_1_2* - added override or null

\*****************************************************************************/
IOverride_1_2* CMetricsDevice::AddOverride( TOverrideType overrideType )
{
    MD_CHECK_PTR_RET( m_overridesVector, NULL );

    // 1. CHECK AVAILABILITY ON CURRENT DRIVER INTERFACE
    if( !m_driverInterface->IsOverrideAvailable( overrideType ) )
    {
        MD_LOG( LOG_INFO, "Override %u not available on the current driver interface", overrideType );
        return NULL;
    }

    // 2. CREATE OVERRIDE OBJECT
    IOverride_1_2* override = NULL;
    switch( overrideType )
    {
        case OVERRIDE_TYPE_FREQUENCY:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_FREQUENCY>( this );
            break;
        case OVERRIDE_TYPE_NULL_HARDWARE:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_NULL_HARDWARE>( this );
            break;
        case OVERRIDE_TYPE_MULTISAMPLED_QUERY:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_MULTISAMPLED_QUERY>( this );
            break;
        case OVERRIDE_TYPE_EXTENDED_QUERY:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_EXTENDED_QUERY>( this );
            break;
        case OVERRIDE_TYPE_FLUSH_GPU_CACHES:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_FLUSH_GPU_CACHES>( this );
            break;
#if defined(_RELEASE_INTERNAL)
        case OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS:
            override = new (std::nothrow) COverride<OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS>( this );
            break;
#endif
        default:
            break;
    }

    // 3. CHECK AVAILABILITY ON CURRENT PLATFORM
    MD_CHECK_PTR_RET( override, NULL );
    if( IsPlatformTypeOf( override->GetParams()->PlatformMask ) )
    {
        // Add override and update count
        m_overridesVector->PushBack( override );
        m_params.OverrideCount = m_overridesVector->GetCount();
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

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    AddOverrides

Description:
    Fills override vector in MetricsDevice with previously defined overrides.
    All the params are set in specialized constructors.

Output:
    TCompletionCode - result, *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricsDevice::AddOverrides()
{
    MD_CHECK_PTR_RET( m_overridesVector, CC_ERROR_GENERAL );

    TCompletionCode ret = CC_OK;

    AddOverride( OVERRIDE_TYPE_FREQUENCY );
    AddOverride( OVERRIDE_TYPE_NULL_HARDWARE );
    AddOverride( OVERRIDE_TYPE_EXTENDED_QUERY );
    AddOverride( OVERRIDE_TYPE_MULTISAMPLED_QUERY );
    AddOverride( OVERRIDE_TYPE_FLUSH_GPU_CACHES );
#if defined(_RELEASE_INTERNAL)
    AddOverride( OVERRIDE_TYPE_FREQUENCY_CHANGE_REPORTS );
#endif
    // ...

    return ret;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    IsPlatformTypeOf

Description:
    Checks if current platform is given type.

Input:
    uint32_t hwMask - hardware mask in TPlatformType notation
    uint32_t gtMask - gt type mask in TGTType notation

Output:
    bool                - result

\*****************************************************************************/
bool CMetricsDevice::IsPlatformTypeOf( uint32_t hwMask, uint32_t gtMask /*= GT_TYPE_ALL*/ )
{
    bool platformMatch = ( hwMask & m_platform ) != 0;
    bool gtMatch       = ( gtMask & m_gtType   ) != 0;

    return platformMatch && gtMatch;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    IsPavpDisabled

Description:
    Checks if the PAVP_DISABLED bit in capabilities global symbol is set.

Output:
    bool - result

\*****************************************************************************/
bool CMetricsDevice::IsPavpDisabled( uint32_t capabilities )
{
    return (capabilities & GTDI_CAPABILITY_PAVP_DISABLED) > 0;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    IsAvailabilityEquationTrue

Description:
    Solves the given availability equation.

Input:
    const char * availabilityEquation   - availability equation to solve

Output:
    bool                                - result of solving availabilityEquation

\*****************************************************************************/
bool CMetricsDevice::IsAvailabilityEquationTrue( const char* availabilityEquation )
{
    if( availabilityEquation == NULL || strcmp( availabilityEquation, "" ) == 0 )
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

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    SaveToFile

Description:
    Saves a custom part of MetricsDevice to file.

Input:
    const char * fileName       - file name

Output:
    TCompletionCode             - result

\*****************************************************************************/
TCompletionCode CMetricsDevice::SaveToFile( const char* fileName )
{
    TCompletionCode retVal     = CC_OK;
    FILE*           metricFile = NULL;

    iu_fopen_s( &metricFile, fileName, "wb" );
    MD_CHECK_PTR_RET( metricFile, CC_ERROR_FILE_NOT_FOUND );

    // Specific key indicating plain text MDAPI file
    fwrite( MD_METRICS_FILE_KEY, sizeof( char ) , sizeof( MD_METRICS_FILE_KEY ), metricFile );

    // m_platform
    fwrite( &m_platform, sizeof( m_platform ), 1, metricFile );

    // m_params
    fwrite( &m_params.Version, sizeof( m_params.Version ), 1, metricFile );

    // m_symbolsVector
    m_symbolSet.WriteSymbolSetToFile( metricFile );

    // m_groupsVector
    uint32_t groupsCount = m_groupsVector->GetCount();
    fwrite( &groupsCount, sizeof( groupsCount ), 1, metricFile );
    for( uint32_t i = 0; i < groupsCount; i++ )
    {
        retVal = (*m_groupsVector)[i]->WriteCConcurrentGroupToFile( metricFile );
        if( retVal != CC_OK )
        {
            break;
        }
    }

    fclose( metricFile );

    return retVal;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    ReadGlobalSymbolsFromFileBuffer

Description:
    Reads global symbols from file buffer and advances the pointer.

Input:
    unsigned char** fileBuffer - file buffer

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadGlobalSymbolsFromFileBuffer( unsigned char** bufferPtr )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

    TGlobalSymbol globalSymbol;

    uint32_t  symbolsCount = ReadUInt32FromFileBuffer( bufferPtr );
    for( uint32_t i = 0; i < symbolsCount; i++ )
    {
        globalSymbol.symbol_1_0.SymbolName       = ReadCStringFromFileBuffer( bufferPtr );
        globalSymbol.symbol_1_0.SymbolTypedValue = ReadTTypedValueFromFileBuffer( bufferPtr );
        globalSymbol.symbolType                  = (TSymbolType)ReadUInt32FromFileBuffer( bufferPtr );
        if( m_symbolSet.IsSymbolAlreadyAdded( globalSymbol.symbol_1_0.SymbolName ) )
        {
            continue;
        }

        if( globalSymbol.symbolType == SYMBOL_TYPE_DETECT )
        {
            m_symbolSet.DetectSymbolValue( globalSymbol.symbol_1_0.SymbolName, &globalSymbol.symbol_1_0.SymbolTypedValue );
        }

        m_symbolSet.AddSymbol(
            globalSymbol.symbol_1_0.SymbolName,
            globalSymbol.symbol_1_0.SymbolTypedValue,
            globalSymbol.symbolType );
    }

    m_params.GlobalSymbolsCount = m_symbolSet.GetSymbolCount();

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    ReadConcurrentGroupsFromFileBuffer

Description:
    Reads concurrent groups from file buffer and advances the pointer.

Input:
    unsigned char** fileBuffer - file buffer

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadConcurrentGroupsFromFileBuffer( unsigned char** bufferPtr, bool isInternalBuild, SMetricsDeviceParams_1_0::SApiVersion* apiVersion )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode     ret             = CC_OK;
    CConcurrentGroup*   aGroup          = NULL;
    char*               symbolicName    = NULL;
    char*               shortName       = NULL;
    uint32_t            measurementTypeMask = 0;

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

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    ReadMetricSetsFromFileBuffer

Description:
    Reads metric sets from file buffer, adds them to the group and advances the pointer.

Input:
    unsigned char**   fileBuffer - file buffer
    CConcurrentGroup* group      - parent concurrent group

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadMetricSetsFromFileBuffer( unsigned char** bufferPtr, CConcurrentGroup* group, bool isInternalBuild, SMetricsDeviceParams_1_0::SApiVersion* apiVersion )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( group, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode         ret             = CC_OK;
    CMetricSet*             aSet            = NULL;
    CMetricSet*             defaultSet      = NULL;
    char*                   symbolicName    = NULL;
    uint32_t                count           = 0;
    TMetricSetParams_1_4    metricSetParams;
    TApiSpecificId_1_0      apiSpecificId;
    TReportType             reportType;

    // MetricSets
    uint32_t metricSetsCount = ReadUInt32FromFileBuffer( bufferPtr );
    for( uint32_t j = 0; j < metricSetsCount; j++ )
    {
        aSet       = NULL;
        defaultSet = NULL;

        // MetricSetParams
        metricSetParams.SymbolName      = ReadCStringFromFileBuffer( bufferPtr );
        metricSetParams.ShortName       = ReadCStringFromFileBuffer( bufferPtr );
        metricSetParams.ApiMask         = ReadUInt32FromFileBuffer( bufferPtr );
        metricSetParams.CategoryMask    = (TMetricCategory)ReadUInt32FromFileBuffer( bufferPtr );
        metricSetParams.RawReportSize   = ReadUInt32FromFileBuffer( bufferPtr );
        metricSetParams.QueryReportSize = ReadUInt32FromFileBuffer( bufferPtr );
        metricSetParams.PlatformMask    = ReadUInt32FromFileBuffer( bufferPtr );
        if( ( apiVersion->MajorNumber == MD_API_MAJOR_NUMBER_1 && apiVersion->MinorNumber >= MD_API_MINOR_NUMBER_4 ) ||
            ( apiVersion->MajorNumber > MD_API_MAJOR_NUMBER_1 ) )
        {
            metricSetParams.GtMask      = ReadUInt32FromFileBuffer( bufferPtr );
        }
        else
        {
            metricSetParams.GtMask      = (uint32_t) GT_TYPE_ALL;
        }
        reportType                      = (TReportType)ReadUInt32FromFileBuffer( bufferPtr );

        if( IsPlatformTypeOf( metricSetParams.PlatformMask, metricSetParams.GtMask ) || isInternalBuild )
        {
            defaultSet = group->GetMetricSetByName( metricSetParams.SymbolName );
            if( !defaultSet ||
                ( isInternalBuild && strcmp(defaultSet->GetParams()->ShortName, metricSetParams.ShortName) != 0 ) )
            {
                aSet = group->AddMetricSet(
                    metricSetParams.SymbolName,
                    metricSetParams.ShortName,
                    metricSetParams.ApiMask,
                    metricSetParams.CategoryMask,
                    metricSetParams.RawReportSize,
                    metricSetParams.QueryReportSize,
                    reportType,
                    metricSetParams.PlatformMask,
                    metricSetParams.GtMask,
                    true );
                MD_CHECK_PTR_RET( aSet, CC_ERROR_NO_MEMORY );
                MD_LOG(LOG_DEBUG, "adding set: %s", metricSetParams.ShortName);
            }
            else
            {
                MD_LOG(LOG_DEBUG, "set not added, using existing one: %s", metricSetParams.ShortName);
            }
        }
        else
        {
            MD_LOG(LOG_DEBUG, "skipping set: %s", metricSetParams.ShortName);
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
        if( aSet )
        {
            aSet->SetApiSpecificId( apiSpecificId );
        }

        // Metrics - if set's been existing, add only missing metrics
        ret = ReadMetricsFromFileBuffer( bufferPtr, defaultSet ? defaultSet : aSet, defaultSet != NULL );
        MD_CHECK_CC_RET( ret );

        // Information
        ret = ReadInformationFromFileBuffer( bufferPtr, aSet );
        MD_CHECK_CC_RET( ret );

        // Start and stop registers
        ret = ReadRegistersFromFileBuffer( bufferPtr, aSet );
        MD_CHECK_CC_RET( ret );

        // ComplementaryMetricSets
        count = ReadUInt32FromFileBuffer( bufferPtr );
        for( uint32_t k = 0; k < count; k++ )
        {
            symbolicName = ReadCStringFromFileBuffer( bufferPtr );
            if( aSet )
            {
                aSet->AddComplementaryMetricSet( symbolicName );
            }
        }
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    ReadMetricsFromFileBuffer

Description:
    Reads metrics from file buffer, adds them to the set and advances the pointer.

Input:
    unsigned char** fileBuffer   - file buffer
    CMetricSet*     set          - parent metric set
    bool            isSetDefault - if true then add only metrics that don't exist
                                   in the set. It's to prevent adding duplicated
                                   default metrics when reading default set with
                                   custom metrics.

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadMetricsFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set, bool isSetDefault )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

    CMetric*            aMetric        = NULL;
    char*               equationString = NULL;
    char*               signalName     = NULL;
    TMetricParams_1_0   metricParams;
    TDeltaFunction_1_0  deltaFunction;
    bool                skip = (set == NULL);

    // Metrics
    uint32_t metricsCount = ReadUInt32FromFileBuffer( bufferPtr );
    for( uint32_t i = 0; i < metricsCount; i++ )
    {
        aMetric = NULL;

        // MetricParams
        metricParams.GroupId            = ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.SymbolName         = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.ShortName          = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.GroupName          = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.LongName           = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.DxToOglAlias       = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.UsageFlagsMask     = ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.ApiMask            = ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.ResultType         = (TMetricResultType)ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.MetricResultUnits  = ReadCStringFromFileBuffer( bufferPtr );
        metricParams.MetricType         = (TMetricType)ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.HwUnitType         = (THwUnitType)ReadUInt32FromFileBuffer( bufferPtr );
        metricParams.LowWatermark       = ReadInt64FromFileBuffer( bufferPtr );
        metricParams.HighWatermark      = ReadInt64FromFileBuffer( bufferPtr );
        signalName                      = ReadCStringFromFileBuffer( bufferPtr );
        equationString                  = ReadEquationStringFromFile( bufferPtr );

        if( !skip )
        {
            // Add only unique metrics to a default metric set
            if( !isSetDefault || !set->IsMetricAlreadyAdded( metricParams.SymbolName ) )
            {
                aMetric = set->AddMetric(
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
                    true );
                MD_CHECK_PTR_RET( aMetric, CC_ERROR_NO_MEMORY );
            }
        }

        // Delta function
        deltaFunction.FunctionType = (TDeltaFunctionType)ReadUInt32FromFileBuffer( bufferPtr );
        deltaFunction.BitsCount    = ReadUInt32FromFileBuffer( bufferPtr );
        if( aMetric )
        {
            aMetric->SetSnapshotReportDeltaFunction( deltaFunction );
        }

        // Snapshot report read equation
        equationString = ReadEquationStringFromFile( bufferPtr );
        if( aMetric )
        {
            aMetric->SetSnapshotReportReadEquation( equationString );
        }

        // Delta report read equation
        equationString = ReadEquationStringFromFile( bufferPtr );
        if( aMetric )
        {
            aMetric->SetDeltaReportReadEquation( equationString );
        }

        // Normalization equation
        equationString = ReadEquationStringFromFile( bufferPtr );
        if( aMetric )
        {
            aMetric->SetNormalizationEquation( equationString );
        }

        // Max value equation
        equationString = ReadEquationStringFromFile( bufferPtr );
        if( aMetric )
        {
            aMetric->SetMaxValueEquation( equationString );
        }
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    ReadInformationFromFileBuffer

Description:
    Reads information from file buffer, adds them to the set and advances the pointer.

Input:
    unsigned char** fileBuffer - file buffer
    CMetricSet*     set        - parent metric set

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadInformationFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

    CInformation*           aInformation   = NULL;
    char*                   equationString = NULL;
    TInformationParams_1_0  informationParams;
    TDeltaFunction_1_0      deltaFunction;
    bool                    skip = (set == NULL);

    // Information
    uint32_t informationCount = ReadUInt32FromFileBuffer( bufferPtr );
    for( uint32_t k = 0; k < informationCount; k++ )
    {
        aInformation = NULL;

        // InformationParams
        informationParams.SymbolName = ReadCStringFromFileBuffer( bufferPtr );
        informationParams.ShortName  = ReadCStringFromFileBuffer( bufferPtr );
        informationParams.GroupName  = ReadCStringFromFileBuffer( bufferPtr );
        informationParams.LongName   = ReadCStringFromFileBuffer( bufferPtr );
        informationParams.ApiMask    = ReadUInt32FromFileBuffer( bufferPtr );
        informationParams.InfoType   = (TInformationType)ReadUInt32FromFileBuffer( bufferPtr );
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
                equationString );
            MD_CHECK_PTR_RET( aInformation, CC_ERROR_NO_MEMORY );
        }

        // Delta function
        deltaFunction.FunctionType = (TDeltaFunctionType)ReadUInt32FromFileBuffer( bufferPtr );
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

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    ReadRegistersFromFileBuffer

Description:
    Reads start and stop registers from file buffer, adds them to the set and
    advances the pointer.

Input:
    unsigned char** fileBuffer - file buffer
    CMetricSet*     set        - parent metric set

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricsDevice::ReadRegistersFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set )
{
    MD_CHECK_PTR_RET( bufferPtr, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *bufferPtr, CC_ERROR_INVALID_PARAMETER );

    TRegister          reg;
    char*              equationString = NULL;
    TRegisterSetParams registerSetParams;
    uint32_t           regCount       = 0;
    bool               skip = (set == NULL);

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
                reg =  *( (TRegister*)(*bufferPtr) );
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

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    OpenFromFile

Description:
    Opens, checks for MDAPI plain text format and loads file with saved
    metrics device if the format is valid.

Input:
    const char* fileName        - file name
    bool        isInternalBuild - if true, then this is internal build

Output:
    TCompletionCode             - result

\*****************************************************************************/
TCompletionCode CMetricsDevice::OpenFromFile( const char* fileName, bool isInternalBuild )
{
    TCompletionCode retVal           = CC_OK;
    FILE*           metricFile       = NULL;
    unsigned char*  metricFileBuffer = NULL;
    unsigned char*  bufferPtr        = NULL;
    uint32_t        fileSize         = 0;

    iu_fopen_s( &metricFile, fileName, "rb" );
    MD_CHECK_PTR_RET( metricFile, CC_ERROR_FILE_NOT_FOUND );
    fileSize = GetFileSize( metricFile );
    if( fileSize < sizeof( MD_METRICS_FILE_KEY ) )
    {
        fclose( metricFile );
        return CC_ERROR_INVALID_PARAMETER;
    }
    metricFileBuffer = new (std::nothrow) unsigned char[ fileSize ];
    if( metricFileBuffer == NULL )
    {
        fclose( metricFile );
        return CC_ERROR_NO_MEMORY;
    }
    memset( metricFileBuffer, 0, fileSize );
    MD_LOG( LOG_DEBUG, "Check if file is in MDAPI plain text format");
    if( IsMetricsFileInPlainTextFormat( metricFile ) )
    {
        // Load plain text format file
        iu_fread_s( metricFileBuffer, fileSize, 1, fileSize, metricFile );
        bufferPtr = metricFileBuffer;
        bufferPtr += sizeof( MD_METRICS_FILE_KEY );
    }
    else
    {
        MD_LOG( LOG_DEBUG, "Metrics device file is not valid" );
        retVal = CC_ERROR_INVALID_PARAMETER;
    }
    fclose( metricFile );

    if( retVal == CC_OK )
    {
        MD_LOG(LOG_DEBUG, "Metrics device file saved on platform: %d, current: %d", *((TPlatformType*)bufferPtr), m_platform);
        bufferPtr += sizeof( TPlatformType );

        // MetricsDeviceParams
        SMetricsDeviceParams_1_0::SApiVersion apiVersion;
        apiVersion.MajorNumber = ReadUInt32FromFileBuffer( &bufferPtr );
        apiVersion.MinorNumber = ReadUInt32FromFileBuffer( &bufferPtr );
        apiVersion.BuildNumber = ReadUInt32FromFileBuffer( &bufferPtr );
        MD_LOG(LOG_DEBUG, "Metrics device file saved with MDAPI v. %d.%d.%d, current v: %d.%d.%d", apiVersion.MajorNumber, apiVersion.MinorNumber, apiVersion.BuildNumber,
            MD_API_MAJOR_NUMBER_CURRENT, MD_API_MINOR_NUMBER_CURRENT, MD_API_BUILD_NUMBER_CURRENT );

        // GlobalSymbols
        retVal = ReadGlobalSymbolsFromFileBuffer( &bufferPtr );

        // ConcurrentGroup tree
        if( retVal == CC_OK )
        {
            retVal = ReadConcurrentGroupsFromFileBuffer( &bufferPtr, isInternalBuild, &apiVersion );
        }
    }
    m_isOpenedFromFile = (retVal == CC_OK);

    MD_SAFE_DELETE_ARRAY( metricFileBuffer );
    return retVal;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    IsMetricsFileInPlainTextFormat

Description:
    Check if metrics file has a proper header with MD_METRICS_FILE_KEY.

Input:
    FILE* metricFile - opened file with custom metrics.

Output:
    bool             - true if file in MDAPI plain text format, false otherwise

\*****************************************************************************/
bool CMetricsDevice::IsMetricsFileInPlainTextFormat( FILE* metricFile )
{
    const uint32_t metricFileKeySize              = sizeof( MD_METRICS_FILE_KEY );
    unsigned char  readFileKey[metricFileKeySize] = { 0, };

    // Load fragment of the file as plain text
    iu_fread_s( readFileKey, metricFileKeySize, 1, metricFileKeySize, metricFile );
    // Move file pointer to the start
    rewind( metricFile );

    // Check if the file has MDAPI plain text header
    return strcmp( MD_METRICS_FILE_KEY, (const char*)&readFileKey ) == 0;
}
/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetDriverInterface

Description:
    Returns driver interface.

Output:
    CDriverInterface*   - pointer to driver interface

\*****************************************************************************/
CDriverInterface* CMetricsDevice::GetDriverInterface()
{
    return m_driverInterface;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetSymbolSet

Description:
    Returns pointer to the symbol set.

Output:
    CSymbolSet*   - pointer to the symbol set

\*****************************************************************************/
CSymbolSet* CMetricsDevice::GetSymbolSet()
{
    return &m_symbolSet;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetPlatformType

Description:
    Returns platform type.

Output:
    TPlatformType - platform type.

\*****************************************************************************/
TPlatformType CMetricsDevice::GetPlatformType()
{
    return m_platform;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    IsOpenedFromFile

Description:
    Returns true if device was opened from a file

Output:
    bool - true if opened from file

\*****************************************************************************/
bool CMetricsDevice::IsOpenedFromFile()
{
    return m_isOpenedFromFile;
}

/*****************************************************************************\

Class:
    CMetricsDevice

Method:
    GetConcurrentGroupByName

Description:
    Returns chosen concurrent group by name or null if not exists.

Input:
    const char* symbolName - name of a concurrent group to look for

Output:
    CConcurrentGroup*      - found concurrent group or NULL

\*****************************************************************************/
CConcurrentGroup* CMetricsDevice::GetConcurrentGroupByName( const char* symbolName )
{
    MD_CHECK_PTR_RET( symbolName, NULL );
    MD_CHECK_PTR_RET( m_groupsVector, NULL );

    for( uint32_t i = 0; i < m_groupsVector->GetCount(); i++ )
    {
        if( ((*m_groupsVector)[i]) && (strcmp( symbolName, (*m_groupsVector)[i]->GetParams()->SymbolName ) == 0) )
        {
            return (*m_groupsVector)[i];
        }
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    CConcurrentGroup constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device     - parent metrics device
    const char * name           - concurrent group name
    const char * description    - concurrent group description
    uint32_t measurementTypeMask - measurement type mask

\*****************************************************************************/
CConcurrentGroup::CConcurrentGroup( CMetricsDevice *device, const char* name, const char* description, uint32_t measurementTypeMask )
{
    m_params_1_0.SymbolName             = GetCopiedCString( name );
    m_params_1_0.Description            = GetCopiedCString( description );
    m_params_1_0.MeasurementTypeMask    = measurementTypeMask;
    m_params_1_0.MetricSetsCount        = 0;
    m_params_1_0.IoMeasurementInformationCount = 0;
    m_params_1_0.IoGpuContextInformationCount  = 0;

    m_device    = device;
    m_semaphore = NULL;

    m_setsVector    = new (std::nothrow) Vector<CMetricSet*>( SETS_VECTOR_INCREASE );
    m_otherSetsList = new (std::nothrow) List<CMetricSet*>();
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    CConcurrentGroup destructor

Description:
    Deallocates memory.

\*****************************************************************************/
CConcurrentGroup::~CConcurrentGroup()
{
    MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
    MD_SAFE_DELETE_ARRAY( m_params_1_0.Description );
    MD_SAFE_DELETE( m_setsVector );
    MD_SAFE_DELETE( m_otherSetsList );
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    GetParams

Description:
    Returns concurrent group params.

Output:
    TConcurrentGroupParams_1_0*  - concurrent group params

\*****************************************************************************/
TConcurrentGroupParams_1_0* CConcurrentGroup::GetParams( void )
{
    return &m_params_1_0;
}

//****************************************************************************/
// Helper macro to get CustomMetricSetParams
//****************************************************************************/
#define MD_CUSTOM_METRIC_SET_PARAMS(params, version) (params)->CustomMetricSetParams_##version

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    AddCustomMetricSet

Description:
    Wrapper function for adding custom metric sets with the given parameters.

Input:
    TAddCustomMetricSetParams* params               - params
    IMetricSet_1_0*            referenceMetricSet   - (optional) metric set from which copy metrics and information
                                                        *IGNORED IN CConcurrentGroup*
    bool                       copyInformationOnly  - Copy information without metrics from reference set

Output:
    IMetricSet_1_5* - added metric set

\*****************************************************************************/
IMetricSet_1_5* CConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly /*= false*/ )
{
    if( params == NULL )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
        return NULL;
    }

    IMetricSet_1_5* set = NULL;

    if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
    {
        set = AddCustomMetricSet(
            NULL,                                           // don't inherit any metrics and information
            NULL,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).SymbolName,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ShortName,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ApiMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).CategoryMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).PlatformMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).GtMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).RawReportSize,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).QueryReportSize,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ComplementarySetsList,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ApiSpecificId,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).StartConfigRegSets,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).StartConfigRegSetsCount,
            copyInformationOnly);
    }

    return set;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    FindSameMetricSetForPlatform

Description:
    Finds MetricSet with the same symbol name matching the given platform mask.
    Used in adding custom metric sets with reference metric sets.

Input:
    CMetricSet*  metricSet    - metrics set to look for
    uint32_t     platformMask - platform mask

Output:
    CMetricSet* - found metric set, input metric set if not found one with matching
                  platform mask

\*****************************************************************************/
CMetricSet* CConcurrentGroup::FindSameMetricSetForPlatform( CMetricSet* metricSet, uint32_t platformMask )
{
    if( !metricSet ||
        (metricSet->GetParams()->PlatformMask & platformMask) == platformMask )
    {
        return metricSet;
    }

    Node<CMetricSet*>* metricSetNode = m_otherSetsList->GetHeadNode();
    while( metricSetNode != NULL )
    {
        if( (metricSetNode->value) && (strcmp(metricSet->GetParams()->SymbolName, metricSetNode->value->GetParams()->SymbolName) == 0) &&
            (metricSetNode->value->GetParams()->PlatformMask & platformMask) == platformMask )
        {
            return (metricSetNode->value);
        }
        metricSetNode = metricSetNode->nextNode;
    }

    return metricSet;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    AddCustomMetricSet

Description:
    Adds custom metric set with the given parameters.

Input:
    CMetricSet*  referenceMetricSet     - (optional) metric set from which inherit metrics and information
    const char*  signalName             - (optional) signal name with which metrics should be inherited
    const char*  symbolName             -
    const char*  shortName              -
    uint32_t     apiMask                -
    uint32_t     categoryMask           -
    uint32_t     rawReportSize          -
    uint32_t     queryReportSize        -
    uint32_t     complementarySetsCount -
    const char*  complementarySetsList  - comma separated copmlementary sets list
    TApiSpecificId_1_0 apiSpecificId    -
    TRegisterSet* startRegSets          -
    uint32_t     startRegSetsCount      -

Output:
    IMetricSet_1_5* - added metric set

\*****************************************************************************/
IMetricSet_1_5* CConcurrentGroup::AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName,
    const char* symbolName, const char* shortName, uint32_t apiMask, uint32_t categoryMask,
    uint32_t platformMask, uint32_t gtMask, uint32_t rawReportSize, uint32_t queryReportSize,
    const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets,
    uint32_t startRegSetsCount, bool copyInformationOnly )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( m_setsVector, NULL );
    MD_CHECK_PTR_RET( m_otherSetsList, NULL );

    if( !AreMetricSetParamsValid( symbolName, shortName, platformMask, gtMask, startRegSets, startRegSetsCount ) )
    {
        MD_LOG( LOG_ERROR, "invalid custom metric set parameters" );
        MD_LOG_EXIT();
        return NULL;
    }
    if( MatchingSetExists( symbolName, platformMask, gtMask ) )
    {
        MD_LOG( LOG_ERROR, "metric set already added: %s", symbolName );
        MD_LOG_EXIT();
        return NULL;
    }

    CMetricSet* refMetricSetMatchingPlatform = NULL;
    CMetricSet* set = ( CMetricSet* ) new (std::nothrow) CMetricSet( m_device, this, symbolName, shortName, apiMask, categoryMask,
        rawReportSize, queryReportSize, DEFAULT_METRIC_SET_REPORT_TYPE, platformMask, gtMask, true );
    MD_CHECK_PTR_RET( set, NULL );

    if( complementarySetsList != NULL &&
        set->AddComplementaryMetricSets( complementarySetsList ) != CC_OK )
    {
        goto customMetricSetCleanup;
    }

    if( set->SetApiSpecificId( apiSpecificId ) != CC_OK )
    {
        MD_LOG( LOG_DEBUG, "error setting apiSpecificId" );
        goto customMetricSetCleanup;
    }

    refMetricSetMatchingPlatform = FindSameMetricSetForPlatform(referenceMetricSet, platformMask);
    if( refMetricSetMatchingPlatform != NULL &&
        set->InheritFromMetricSet(refMetricSetMatchingPlatform, signalName, copyInformationOnly) != CC_OK )
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

    if( m_device->IsPlatformTypeOf( platformMask, gtMask ) )
    {
        m_setsVector->PushBack( set );
        m_params_1_0.MetricSetsCount = m_setsVector->GetCount();
    }
    else
    {
        m_otherSetsList->PushBack( set );
    }

    return set;

customMetricSetCleanup:
    MD_SAFE_DELETE( set );
    MD_LOG_EXIT();
    return NULL;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    AddMetricSet

Description:
    Adds a new metric set to  the concurrent group.

Input:
    const char * symbolicName       -
    const char * shortName          -
    uint32_t     apiMask            -
    TMetricCategory category        - metric set category
    uint32_t     snapshotReportSize -
    uint32_t     deltaReportSize    -
    TReportType  reportType         -
    uint32_t     platformMask       -
    uint32_t     gtMask             -
    bool isCustom                   -

Output:
    CMetricSet*  - pointer to the newly added metrics set

\*****************************************************************************/
CMetricSet* CConcurrentGroup::AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask,
    uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType,
    uint32_t platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/ , bool isCustom /*= false*/ )
{
    MD_CHECK_PTR_RET( m_setsVector, NULL );
    MD_CHECK_PTR_RET( m_otherSetsList, NULL );

    CMetricSet* set = ( CMetricSet* ) new (std::nothrow) CMetricSet( m_device, this, symbolicName, shortName, apiMask, categoryMask,
        snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom );
    MD_CHECK_PTR_RET( set, NULL );

    if( m_device->IsPlatformTypeOf( platformMask, gtMask ) )
    {
        m_setsVector->PushBack( set );
        m_params_1_0.MetricSetsCount = m_setsVector->GetCount();
        MD_LOG( LOG_INFO, "%s - added", set->GetParams()->SymbolName );
    }
    else
    {
        MD_LOG( LOG_INFO, "%s - not available", set->GetParams()->SymbolName );
        m_otherSetsList->PushBack( set );
    }

    return set;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    GetMetricSet

Description:
    Returns the chosen metrics set or null if index doesn't exist.

Input:
    uint32_t index      - index of a chosen metrics set

Output:
    IMetricSet_1_5*     - chosen metrics set

\*****************************************************************************/
IMetricSet_1_5* CConcurrentGroup::GetMetricSet( uint32_t index )
{
    MD_CHECK_PTR_RET( m_setsVector, NULL );
    if( index < m_setsVector->GetCount() )
    {
        return (*m_setsVector)[ index ];
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    Lock

Description:
    Creates a semaphore on the concurrent group. Waits 1s if needed.

Output:
    TCompletionCode - *CC_OK* if succeeded,
                      *CC_CONCURRENT_GROUP_LOCKED* if timeout occurred

\*****************************************************************************/
TCompletionCode CConcurrentGroup::Lock()
{
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    return driverInterface->LockConcurrentGroup( m_params_1_0.SymbolName, &m_semaphore );
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    Unlock

Description:
    Releases the semaphore created on concurrent group.

Output:
    TCompletionCode - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CConcurrentGroup::Unlock()
{
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    return driverInterface->UnlockConcurrentGroup( m_params_1_0.SymbolName, &m_semaphore );
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    WriteCConcurrentGroupToFile

Description:
    Writes concurrent group to file.

Input:
    FILE* metricFile    - handle to metric file file

Output:
    TCompletionCode - result of operation

\*****************************************************************************/
TCompletionCode CConcurrentGroup::WriteCConcurrentGroupToFile( FILE* metricFile )
{
    uint32_t           count   = 0;
    Node<CMetricSet*>* setNode = NULL;

    MD_CHECK_PTR_RET( m_setsVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_otherSetsList, CC_ERROR_GENERAL );

    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
        return CC_ERROR_INVALID_PARAMETER;
    }

    // m_params_1_0
    WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
    WriteCStringToFile( m_params_1_0.Description, metricFile );
    fwrite( &m_params_1_0.MeasurementTypeMask, sizeof( m_params_1_0.MeasurementTypeMask ), 1, metricFile );

    // m_setsVector & m_otherSetsList
    count = GetCustomSetCount();
    fwrite( &count, sizeof( count ), 1, metricFile );

    count = m_setsVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        if( (*m_setsVector)[i]->IsCustom() )
        {
            (*m_setsVector)[i]->WriteCMetricSetToFile( metricFile );
        }
    }

    setNode = m_otherSetsList->GetHeadNode();
    while( setNode != NULL )
    {
        if( setNode->value->IsCustom() )
        {
            setNode->value->WriteCMetricSetToFile( metricFile );
        }
        setNode = setNode->nextNode;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    MatchingSetExists

Description:
    Checks if metric set of the given name, platform and gt is already added to the concurrent group.

Input:
    const char * symbolicName   - symbolic name of a metric set to check
    uint32_t     platformMask   - platform Id bit mask indicates platforms compatible with set.
    uint32_t     gtMask         - gt type bit mask indicates platform versions compatible with set.

Output:
    bool                        - true when already added

\*****************************************************************************/
bool CConcurrentGroup::MatchingSetExists( const char* symbolName, uint32_t platformMask, uint32_t gtMask )
{
    MD_CHECK_PTR_RET( symbolName, false );
    MD_CHECK_PTR_RET( m_setsVector, false );
    MD_CHECK_PTR_RET( m_otherSetsList, false );

    // List of available sets
    for( uint32_t i = 0; i < m_setsVector->GetCount(); i++ )
    {
        TMetricSetParams_1_4* setParams = (*m_setsVector)[i] ? (*m_setsVector)[i]->GetParams() : NULL;

        if( setParams && (strcmp( symbolName, setParams->SymbolName ) == 0) )
        {
            bool platformMatch = ( platformMask & setParams->PlatformMask ) != 0;
            bool gtMatch       = ( gtMask       & setParams->GtMask )       != 0;

            if( platformMatch && gtMatch )
            {
                return true;
            }
        }
    }
    // List of unavailable sets for current platform
    Node<CMetricSet*>* metricSetNode = m_otherSetsList->GetHeadNode();
    while( metricSetNode != NULL )
    {
        TMetricSetParams_1_4* setParams = metricSetNode->value ? metricSetNode->value->GetParams() : NULL;

        if( setParams && strcmp( symbolName, setParams->SymbolName ) == 0 )
        {
            bool platformMatch = ( platformMask & setParams->PlatformMask ) != 0;
            bool gtMatch       = ( gtMask       & setParams->GtMask )       != 0;

            if( platformMatch && gtMatch )
            {
                return true;
            }
        }
        metricSetNode = metricSetNode->nextNode;
    }

    return false;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    AreMetricSetParamsValid

Description:
    Checks the correctness of the given metricSet parameters.

Input:
    const char*   symbolName        -
    const char*   shortName         -
    uint32_t      platformMask      -
    TRegisterSet* startRegSets      -
    uint32_t      startRegSetsCount -

Output:
    bool                       - true if valid

\*****************************************************************************/
bool CConcurrentGroup::AreMetricSetParamsValid( const char* symbolName, const char* shortName, uint32_t platformMask,
     uint32_t gtMask, TRegisterSet* startRegSets, uint32_t startRegSetsCount)
{
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_LOG( LOG_ERROR, "could not interface with the driver" );
        MD_ASSERT( false );
        return false;
    }

    if( ( symbolName == NULL ) || ( strcmp( symbolName, "" ) == 0 ) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, symbolName );
        return false;
    }
    if( ( shortName == NULL ) || ( strcmp( shortName, "" ) == 0 ) )
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
    if( startRegSetsCount > 0 && startRegSets == NULL )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, startRegSets );
        return false;
    }

    for( uint32_t i = 0; i < startRegSetsCount; i++ )
    {
        if( startRegSets[i].StartConfigRegsCount > 0 )
        {
            if( startRegSets[i].StartConfigRegs == NULL )
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
                    if( driverInterface->ValidatePmRegsConfig( startRegSets[i].StartConfigRegs, startRegSets[i].StartConfigRegsCount, (TPlatformType)platform ) != CC_OK )
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

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    GetCustomSetCount

Description:
    Returns number of custom sets + default sets with custom metrics.

Output:
    uint32_t - custom set count

\*****************************************************************************/
uint32_t CConcurrentGroup::GetCustomSetCount()
{
    uint32_t customSetCount = 0;

    MD_CHECK_PTR_RET( m_setsVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_otherSetsList, CC_ERROR_GENERAL );

    uint32_t count = m_setsVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        if( (*m_setsVector)[i]->IsCustom() )
        {
            customSetCount++;
        }
    }

    Node<CMetricSet*>* setNode = m_otherSetsList->GetHeadNode();
    while( setNode != NULL )
    {
        if( setNode->value->IsCustom() )
        {
            customSetCount++;
        }
        setNode = setNode->nextNode;
    }

    return customSetCount;
}

/*****************************************************************************\

Class:
    CConcurrentGroup

Method:
    GetMetricSetByName

Description:
    Returns chosen metric set by name or null if not exists.

Input:
    const char* symbolName - name of a metric set to look for

Output:
    CMetricSet*            - found metric set or NULL

\*****************************************************************************/
CMetricSet* CConcurrentGroup::GetMetricSetByName( const char* symbolName )
{
    MD_CHECK_PTR_RET( symbolName, NULL );
    MD_CHECK_PTR_RET( m_setsVector, NULL );
    MD_CHECK_PTR_RET( m_otherSetsList, NULL );

    for( uint32_t i = 0; i < m_setsVector->GetCount(); i++ )
    {
        if( ((*m_setsVector)[i]) && (strcmp( symbolName, (*m_setsVector)[i]->GetParams()->SymbolName ) == 0) )
        {
            return (*m_setsVector)[i];
        }
    }

    Node<CMetricSet*>* metricSetNode = m_otherSetsList->GetHeadNode();
    while( metricSetNode != NULL )
    {
        if( (metricSetNode->value) && (strcmp( symbolName, metricSetNode->value->GetParams()->SymbolName ) == 0) )
        {
            return (metricSetNode->value);
        }
        metricSetNode = metricSetNode->nextNode;
    }

    return NULL;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    COAConcurrentGroup constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device             - parent metrics device
    const char * name                   - concurrent group name
    const char * description            - concurrent group description
    uint32_t     measurementTypeMask    -

\*****************************************************************************/
COAConcurrentGroup::COAConcurrentGroup( CMetricsDevice *device, const char* name, const char* description, uint32_t measurementTypeMask )
    : CConcurrentGroup( device, name, description, measurementTypeMask )
{
    m_processId          = 0;
    m_contextTagsEnabled = false;
    m_ioMetricSet        = NULL;
    m_streamEventHandle  = NULL;
    m_streamType         = STREAM_TYPE_OA;
    m_ioMeasurementInfoVector = new (std::nothrow) Vector<CInformation*>( EXCEPTIONS_VECTOR_INCREASE );
    m_ioGpuContextInfoVector  = new (std::nothrow) Vector<CInformation*>( GPU_CONTEXTS_VECTOR_INCREASE );
    AddIoMeasurementInfoPredefined();
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    COAConcurrentGroup destructor

Description:
    Deallocates memory.

\*****************************************************************************/
COAConcurrentGroup::~COAConcurrentGroup()
{
    MD_SAFE_DELETE( m_ioMeasurementInfoVector );
    MD_SAFE_DELETE( m_ioGpuContextInfoVector );
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    AddCustomMetricSet

Description:
    Wrapper function for adding custom metric sets with the given parameters.

Input:
    TAddCustomMetricSetParams* params              - params
    IMetricSet_1_0*            referenceMetricSet  - (optional) metric set from which copy metrics and information
    bool                       copyInformationOnly - Copy information without metrics from reference set

Output:
    IMetricSet_1_5* - added metric set

\*****************************************************************************/
IMetricSet_1_5* COAConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly /*= false*/ )
{
    if( params == NULL )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
        return NULL;
    }

    IMetricSet_1_5* set = NULL;

    if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
    {
        set = CConcurrentGroup::AddCustomMetricSet(
            (CMetricSet*)referenceMetricSet,
            "oa.fixed",                                        // inherit metrics with signalName containing this string
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).SymbolName,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ShortName,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ApiMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).CategoryMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).PlatformMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).GtMask,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).RawReportSize,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).QueryReportSize,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ComplementarySetsList,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).ApiSpecificId,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).StartConfigRegSets,
            MD_CUSTOM_METRIC_SET_PARAMS(params, 1_0).StartConfigRegSetsCount,
            copyInformationOnly);
    }

    return set;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    SetIoStreamSamplingType

Description:
    Sets stream sampling type. OA and BB (batch buffer) supported.

Input:
    TSamplingType type - requested IO Stream Sampling Type

Output:
    TCompletionCode - result of operation (*CC_OK* is ok)

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::SetIoStreamSamplingType( TSamplingType type )
{
    TStreamType newStreamType = STREAM_TYPE_OA;
    TCompletionCode ret = CC_OK;
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
        if( m_ioMetricSet != NULL )
        {
            MD_LOG(LOG_ERROR, "Failed to set IoStream sampling type");
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

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    OpenIoStream

Description:
    Opens IO Stream for given metric set.
    (Enables Timer Mode and opens Counter Stream)

Input:
    IMetricSet_1_0* metricSet           - metric set
    uint32_t        processId           - PID of the measured app (0 is global context)
    uint32_t*       nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    uint32_t*       oaBufferSize        - (in/out) requested/set OA Buffer size in bytes

Output:
    TCompletionCode - result of operation (*CC_OK* is ok)

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( metricSet,     CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( oaBufferSize,  CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret = CC_OK;

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->OpenIoStream( m_streamType, (CMetricSet*)metricSet, m_params_1_0.SymbolName, processId, nsTimerPeriod, oaBufferSize, &m_streamEventHandle );
    if( ret != CC_OK )
    {
        MD_LOG_EXIT();
        return ret;
    }
    MD_LOG( LOG_DEBUG, "Stream opened using type: %u", m_streamType );

    m_ioMetricSet           = (CMetricSet*)metricSet;
    m_processId             = processId;
    m_contextTagsEnabled    = m_ioMetricSet->HasInformation( "ContextId" );
    CMetricsCalculator* mc  = m_ioMetricSet->GetMetricsCalculator();
    if( mc != NULL )
    {
        mc->DiscardSavedReport();
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    ReadIoStream

Description:
    Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    data was read. Additionally, at the end of ReadIoStream GpuContextIds are read and updated.

Input:
    uint32_t        reportCount - (in/out) requested number of reports to read / reports read from the stream
    char*           reportData  - (out) pointer to the read data
    uint32_t        readFlags   - read flags (see TIoReadFlag enum), 0 is ok

Output:
    TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
{
    MD_CHECK_PTR_RET( reportData,  CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( reportCount, CC_ERROR_INVALID_PARAMETER );
    if( m_ioMetricSet == NULL )
    {
        *reportCount = 0;
        MD_LOG(LOG_ERROR, "stream not opened");
        return CC_ERROR_GENERAL;
    }
    if( *reportCount == 0)
    {
        MD_LOG(LOG_DEBUG, "0 reports to read");
        return CC_OK;
    }

    TCompletionCode                 ret       = CC_OK;
    uint32_t                        frequency = 0;
    GTDIReadCounterStreamExceptions exceptions;

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->ReadIoStream( m_streamType, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
    if( ret == CC_OK || ret == CC_READ_PENDING )
    {
        if( m_ioMeasurementInfoVector )
        {
            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );

            m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector->GetCount();
        }
        else
        {
            m_params_1_0.IoMeasurementInformationCount = 0;
        }

        if( m_contextTagsEnabled && m_processId > 0 &&
            readFlags & IO_READ_FLAG_GET_CONTEXT_ID_TAGS )
        {
            ReadGpuContextIdTags();
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    CloseIoStream

Description:
    Closes IO Stream.
    (Closes Counter Stream and disables Timer Mode)

Output:
    TCompletionCode - result of operation (*CC_OK* is ok)

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::CloseIoStream( void )
{
    MD_LOG_ENTER();
    if( m_ioMetricSet == NULL )
    {
        MD_LOG(LOG_ERROR, "stream not opened");
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    TCompletionCode ret = CC_OK;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->CloseIoStream( m_streamType, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
    if( ret != CC_OK )
    {
        MD_LOG_EXIT();
        return ret;
    }

    m_ioMetricSet = NULL;
    m_processId   = 0;
    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    WaitForReports

Description:
    Waits the given number of milliseconds for reports from IoStream.
    Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).

Input:
    uint32_t     milliseconds   - number of milliseconds to wait

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::WaitForReports( uint32_t milliseconds )
{
    TCompletionCode   retVal          = CC_OK;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();

    retVal = driverInterface->WaitForIoStreamReports( m_streamType, milliseconds, m_streamEventHandle );

    return retVal;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    GetIoMeasurementInformation

Description:
    Returns measurement information of given index. Measurement information values
    are set after successful ReadIoStream.

Input:
    uint32_t     index  - index of the measurement information

Output:
    IInformation_1_0*   - measurement information, NULL if count is 0

\*****************************************************************************/
IInformation_1_0* COAConcurrentGroup::GetIoMeasurementInformation( uint32_t index )
{
    MD_CHECK_PTR_RET( m_ioMeasurementInfoVector, NULL );
    if( m_params_1_0.IoMeasurementInformationCount != 0 && index < m_ioMeasurementInfoVector->GetCount() )
    {
        return (IInformation_1_0*)(*m_ioMeasurementInfoVector)[ index ];
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    GetIoGpuContextInformation

Description:
    Returns GPU context id information of given index. GPU context id information values
    are set after successful ReadIoStream if IO_READ_FLAG_GET_CONTEXT_ID_TAGS was set.

Input:
    uint32_t     index  - index of the GPU context information

Output:
    IInformation_1_0*   - GPU context information, NULL if count is 0

\*****************************************************************************/
IInformation_1_0* COAConcurrentGroup::GetIoGpuContextInformation( uint32_t index )
{
    MD_CHECK_PTR_RET( m_ioGpuContextInfoVector, NULL );
    if( m_params_1_0.IoGpuContextInformationCount != 0 && index < m_ioGpuContextInfoVector->GetCount() )
    {
        return (IInformation_1_0*)(*m_ioGpuContextInfoVector)[ index ];
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    AddAllIoMeasurementInformation

Description:
    Adds exceptions from GTDIReadCounterStreamExceptions struct and Frequency from
    GTDIReadCounterStreamExtOut struct.

\*****************************************************************************/
void COAConcurrentGroup::AddIoMeasurementInfoPredefined( void )
{
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( false );
        return;
    }

    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ ) )
    {
        AddIoMeasurementInformation( "CoreFrequencyMHz", "Core Frequency in MHz", "The last core frequency in the measurement.",
            "Report Meta Data", INFORMATION_TYPE_VALUE, "megahertz" );
    }
    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED ) )
    {
        AddIoMeasurementInformation( "FrequencyChanged", "Core Frequency Changed", "The flag indicating that core frequency has changed.",
            "Exception", INFORMATION_TYPE_FLAG, NULL );
    }
    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID ) )
    {
        AddIoMeasurementInformation( "FrequencyChangedInvalid", "Core Frequency Changed Invalid", "The flag indicating inability to report freq change due to delayed read.",
            "Exception", INFORMATION_TYPE_FLAG, NULL );
    }
    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN ) )
    {
        AddIoMeasurementInformation( "SliceShutdown", "Slice Shutdown Occurred", "The flag indicating that the Slice Shutdown has occurred.",
            "Exception", INFORMATION_TYPE_FLAG, NULL );
    }
    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_REPORT_LOST ) )
    {
        AddIoMeasurementInformation( "ReportLost", "Report Lost reported by HW", "The flag indicating that some samples were lost since last Read.",
            "Exception", INFORMATION_TYPE_FLAG, NULL );
    }
    if( driverInterface->IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_DATA_OUTSTANDING ) )
    {
        AddIoMeasurementInformation( "DataOutstanding", "Data Outstanding", "The flag indicating that there are still some outstanding data.",
            "Report Meta Data", INFORMATION_TYPE_FLAG, NULL );
    }
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    AddIoMeasurementInformation

Description:
    Adds new measurement information to the *m_ioMeasurementInfoVector*. The value will be stored
    as a SnapshotReportReadEquation. To set use SetInformationValue() from CInformation class.

Input:
    const char*         name                -
    const char*         shortName           -
    const char*         longName            -
    const char*         group               -
    TInformationType    informationType     -
    const char*         informationUnits    -

Output:
    CInformation*   - pointer to the newly added measurement information. NULL if error.

\*****************************************************************************/
CInformation* COAConcurrentGroup::AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group,
    TInformationType informationType, const char* informationUnits )
{
    MD_CHECK_PTR_RET( m_ioMeasurementInfoVector, NULL );

    CInformation* measurementInfo = ( CInformation* ) new (std::nothrow) CInformation( m_device, m_ioMeasurementInfoVector->GetCount(), name, shortName,
        longName, group, API_TYPE_IOSTREAM | API_TYPE_BBSTREAM, informationType, informationUnits );
    MD_CHECK_PTR_RET( measurementInfo, NULL );

    measurementInfo->SetSnapshotReportReadEquation( "" );
    measurementInfo->SetDeltaReportReadEquation( "" );

    m_ioMeasurementInfoVector->PushBack( measurementInfo );
    return measurementInfo;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    AddIoGpuContextInformation

Description:
    Adds new GPU context information to the *m_ioGpuContextInfoVector*. The value will be stored
    as a SnapshotReportReadEquation.

Input:
    const char*         name                -
    const char*         shortName           -
    const char*         longName            -
    const char*         group               -
    TInformationType    informationType     -
    const char*         informationUnits    -

Output:
    CInformation*   - pointer to the newly added GPU context information. NULL if error.

\*****************************************************************************/
CInformation* COAConcurrentGroup::AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group,
    TInformationType informationType, const char* informationUnits )
{
    MD_CHECK_PTR_RET( m_ioGpuContextInfoVector, NULL );

    CInformation* gpuContextInfo = ( CInformation* ) new (std::nothrow) CInformation( m_device, m_ioGpuContextInfoVector->GetCount(), name, shortName,
        longName, group, API_TYPE_IOSTREAM|0x0, informationType, informationUnits );
    MD_CHECK_PTR_RET( gpuContextInfo, NULL );

    gpuContextInfo->SetSnapshotReportReadEquation( "" );
    gpuContextInfo->SetDeltaReportReadEquation( "" );

    m_ioGpuContextInfoVector->PushBack( gpuContextInfo );
    return gpuContextInfo;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    SetIoMeasurementInfoPredefined

Description:
    Sets value of the previously defined IoMeasurementInformation identified by
    the given type.
    Used indices should be in sync with AddIoMeasurementInfoPredefined() (right order).

Input:
    TIoMeasurementInfoType ioMeasurementInfoType - IO measurement information type
    uint32_t               value                 - value to set
    uint32_t*              index                 - IO measurement information index (should be in sync with AddIoMeasurementInfoPredefined())

\*****************************************************************************/
void COAConcurrentGroup::SetIoMeasurementInfoPredefined( TIoMeasurementInfoType ioMeasurementInfoType, uint32_t value, uint32_t* index )
{
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( !driverInterface || !index )
    {
        MD_ASSERT( driverInterface != NULL );
        return;
    }

    // Set information if available
    if( driverInterface->IsIoMeasurementInfoAvailable( ioMeasurementInfoType ) )
    {
        (*m_ioMeasurementInfoVector)[(*index)++]->SetInformationValue( value, EQUATION_IO_READ );
    }
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    ReadGpuContextIdTags

Description:
    Obtains GPU context tags from KMD using GetCtxIdTags escape. Tags are added to
    m_ioGpuContextInfoVector. ProcessIds are stored as a SymbolName of the information.

Output:
    CompletionCode - result of the operation, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::ReadGpuContextIdTags()
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET(m_ioGpuContextInfoVector, CC_ERROR_GENERAL);

    const uint32_t     maxReadCount = 3;
    TCompletionCode    ret          = CC_OK;

    // Try read up to maxReadCount times
    uint32_t count = 0;
    do
    {
        m_ioGpuContextInfoVector->Clear();
        m_params_1_0.IoGpuContextInformationCount = 0;

        ret = TryReadGpuCtxTags();
    }
    while( ret == CC_TRY_AGAIN && ++count < maxReadCount );

    if( ret != CC_OK )
    {
        MD_LOG( LOG_DEBUG, "unable to read GPU Context tags, ret: %u", ret );
        m_ioGpuContextInfoVector->Clear();
        m_params_1_0.IoGpuContextInformationCount = 0;
        if( ret == CC_TRY_AGAIN )
        {
            ret = CC_ERROR_GENERAL;
        }
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    TryReadGpuCtxTags

Description:
    Try read all GPU context tags data. If stateChangeCount has changed, readAgain
    flag is set.

Output:
    TCompletionCode - result of the operation, *CC_OK* is ok, *CC_READ_AGAIN* means
                      it's needed to read again

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::TryReadGpuCtxTags()
{
    TCompletionCode         ret              = CC_OK;
    uint32_t                stateChangeCount = 0;
    uint32_t                offset           = 0;
    TGetCtxTagsIdParams     params;

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    MD_LOG( LOG_DEBUG, "reading GPU Context tags, pid: %d, offset: %d", m_processId, offset );

    // Read context tag batches
    params.PID = m_processId;
    do
    {
        params.Offset           = offset;
        params.TagCount         = 0;
        params.AvailableTags    = 0;
        params.StateChangeCount = 0;

        ret = driverInterface->SendGetCtxIdTagsEscape( &params );
        if( ret == CC_OK )
        {
            if( offset == 0 )
            {
                stateChangeCount = params.StateChangeCount;
            }
            else if( stateChangeCount != params.StateChangeCount )
            {
                MD_LOG( LOG_DEBUG, "GPU Context tags stage changed, requesting to read again" );
                ret = CC_TRY_AGAIN;
                break;
            }

            offset += params.TagCount;
            ProcessGpuContextTags( params.Tags, params.TagCount );
        }
    } while( ret == CC_OK && offset < params.AvailableTags && params.TagCount != 0 );

    return ret;
}

/*****************************************************************************\

Class:
    COAConcurrentGroup

Method:
    ProcessGpuContextTags

Description:
    Adds tags obtained from the driver to the m_ioGpuContextInfoVector.

Input:
    TContextTag* tags     - result of the GetCtxIdTags escape
    uint32_t     tagCount - tag count

Output:
    TCompletionCode - result of the operation, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode COAConcurrentGroup::ProcessGpuContextTags( TContextTag* tags, uint32_t tagCount )
{
    MD_ASSERT( tags != NULL );

    TCompletionCode ret         = CC_OK;
    CInformation*   information = NULL;
    char            pidTagComboEquation[31]; // Max string length for "%u 32 << %u OR"

    MD_LOG(LOG_DEBUG, "read %d GPU Context tags", tagCount);
    for( uint32_t i = 0; i < tagCount; i++ )
    {
        if( tags[i].ContextTagType < CONTEXT_TAG_TYPE_LAST )
        {
            information = AddIoGpuContextInformation( "GPUContextId", "GPU Context Id", "GPU Context Id tag for PID specified during open stream",
                "Context ID", INFORMATION_TYPE_CONTEXT_ID_TAG, NULL );
            if( !information )
            {
                ret = CC_ERROR_NO_MEMORY;
                break;
            }

            memset( pidTagComboEquation, 0, sizeof(pidTagComboEquation) );
            iu_sprintf_s( pidTagComboEquation, sizeof( pidTagComboEquation ), "%u 32 << %u OR", tags[i].PID, tags[i].ContextTag );

            ret = information->SetSnapshotReportReadEquation( pidTagComboEquation );
            if( ret != CC_OK )
            {
                break;
            }
        }
        else
        {
            MD_LOG( LOG_DEBUG, "Unknown context tag type: %u", tags[i].ContextTagType );
        }
    }

    m_params_1_0.IoGpuContextInformationCount = m_ioGpuContextInfoVector->GetCount();

    return ret;
}

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Method:
    CPerfMonConcurrentGroup constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device             - parent metrics device
    const char * name                   - concurrent group name
    const char * description            - concurrent group description
    uint32_t     measurementTypeMask    -

\*****************************************************************************/
CPerfMonConcurrentGroup::CPerfMonConcurrentGroup( CMetricsDevice *device, const char* name, const char* description, uint32_t measurementTypeMask )
    : COAConcurrentGroup( device, name, description, measurementTypeMask )
{
}

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Method:
    OpenIoStream

Description:
    Opens IO Stream for given metric set.
    (Enables Timer Mode and opens Counter Stream)

Input:
    IMetricSet_1_0* metricSet           - metric set
    uint32_t        processId           - PID of the measured app (0 is global context)
    uint32_t*       nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    uint32_t*       sysBufferSize       - (in/out) requested/set Sys Buffer size in bytes

Output:
    TCompletionCode - result of operation (*CC_OK* is ok)

\*****************************************************************************/
TCompletionCode CPerfMonConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* sysBufferSize )
{
    MD_CHECK_PTR_RET( metricSet,     CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( sysBufferSize, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret = CC_OK;

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( false );
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->OpenIoStream( STREAM_TYPE_SYS, (CMetricSet*)metricSet, m_params_1_0.SymbolName, processId, nsTimerPeriod, sysBufferSize, &m_streamEventHandle );
    if( ret != CC_OK )
    {
        return ret;
    }

    m_ioMetricSet = (CMetricSet*)metricSet;
    return ret;
}

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Method:
    ReadIoStream

Description:
    Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    data was read.

Input:
    uint32_t            reportCount - (in/out) requested number of reports to read / reports read from the stream
    char*               reportData  - (out) pointer to the read data
    uint32_t            readFlags   - read flags (see TIoReadFlag enum), 0 is ok

Output:
    TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)

\*****************************************************************************/
TCompletionCode CPerfMonConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
{
    MD_CHECK_PTR_RET( reportData,  CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( reportCount, CC_ERROR_INVALID_PARAMETER );
    if( m_ioMetricSet == NULL )
    {
        *reportCount = 0;
        MD_LOG(LOG_ERROR, "stream not opened");
        return CC_ERROR_GENERAL;
    }

    TCompletionCode                 ret       = CC_OK;
    uint32_t                        frequency = 0;
    GTDIReadCounterStreamExceptions exceptions;

    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->ReadIoStream( STREAM_TYPE_SYS, m_ioMetricSet, reportData, reportCount, readFlags, &frequency, &exceptions );
    if( m_ioMeasurementInfoVector && ( ret == CC_OK || ret == CC_READ_PENDING ) )
    {
        // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
        uint32_t index = 0;
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, &index );
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, &index );
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, &index );
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, &index );
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, &index );
        SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, &index );

        m_params_1_0.IoMeasurementInformationCount = m_ioMeasurementInfoVector->GetCount();
    }
    else
    {
        m_params_1_0.IoMeasurementInformationCount = 0;
    }

    return ret;
}

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Method:
    CloseIoStream

Description:
    Closes IO Stream.
    (Closes Counter Stream and disables Timer Mode)

Output:
    TCompletionCode - result of operation (*CC_OK* is ok)

\*****************************************************************************/
TCompletionCode CPerfMonConcurrentGroup::CloseIoStream( void )
{
    if( m_ioMetricSet == NULL )
    {
        MD_LOG(LOG_ERROR, "stream not opened");
        return CC_ERROR_GENERAL;
    }

    TCompletionCode ret = CC_OK;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();
    if( driverInterface == NULL )
    {
        MD_ASSERT( driverInterface != NULL );
        return CC_ERROR_GENERAL;
    }

    ret = driverInterface->CloseIoStream( STREAM_TYPE_SYS, &m_streamEventHandle, m_params_1_0.SymbolName, m_ioMetricSet );
    if( ret != CC_OK )
    {
        return ret;
    }

    m_ioMetricSet = NULL;
    return ret;
}

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Method:
    WaitForReports

Description:
    Waits the given number of milliseconds for reports from IoStream.
    Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).

Input:
    uint32_t     milliseconds   - number of milliseconds to wait

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CPerfMonConcurrentGroup::WaitForReports( uint32_t milliseconds )
{
    TCompletionCode   retVal          = CC_OK;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();

    retVal = driverInterface->WaitForIoStreamReports( STREAM_TYPE_SYS, milliseconds, m_streamEventHandle );

    return retVal;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CMetricSet constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device             -
    CConcurrentGroup * concurrentGroup  -
    const char * symbolicName           -
    const char * shortName              -
    uint32_t     apiMask                -
    TMetricCategory category            -
    uint32_t     snapshotReportSize     -
    uint32_t     deltaReportSize        -

\*****************************************************************************/
CMetricSet::CMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName,
    uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType,
    uint32_t platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
{
    m_params_1_0.SymbolName      = GetCopiedCString( symbolicName );
    m_params_1_0.ShortName       = GetCopiedCString( shortName );
    m_params_1_0.ApiMask         = apiMask;
    m_params_1_0.CategoryMask    = category;
    m_params_1_0.PlatformMask    = platformMask;
    m_params_1_0.GtMask          = gtMask;
    m_params_1_0.RawReportSize   = snapshotReportSize;  // as in HW
    m_params_1_0.QueryReportSize = deltaReportSize;     // as in Query API

    m_params_1_0.MetricsCount           = 0;
    m_params_1_0.InformationCount       = 0;
    m_params_1_0.ComplementarySetsCount = 0;

    memset( &m_params_1_0.ApiSpecificId, 0, sizeof( m_params_1_0.ApiSpecificId ));

    m_reportType       = reportType;
    m_isCustom         = isCustom;
    m_isReadRegsCfgSet = false;

    m_device          = device;
    m_concurrentGroup = concurrentGroup;

    m_pmRegsConfigInfo.OaConfigHandle = 0;
    m_pmRegsConfigInfo.GpConfigHandle = 0;
    m_pmRegsConfigInfo.RrConfigHandle = 0;
    m_pmRegsConfigInfo.IsQueryConfig  = 0;

    m_metricsVector             = new (std::nothrow) Vector<CMetric*>( METRICS_VECTOR_INCREASE );
    m_informationVector         = new (std::nothrow) Vector<CInformation*>( INFORMATION_VECTOR_INCREASE );
    m_complementarySetsVector   = new (std::nothrow) Vector<const char*>( COMPLEMENTARY_SETS_VECTOR_INCREASE );
    m_startRegsVector           = new (std::nothrow) Vector<TRegister*>( START_REGS_VECTOR_INCREASE );
    m_startRegsQueryVector      = new (std::nothrow) Vector<TRegister*>( START_REGS_QUERY_VECTOR_INCREASE );
    m_startRegisterSetList      = new (std::nothrow) List<CRegisterSet*>();
    m_otherMetricsList          = new (std::nothrow) List<CMetric*>();
    m_otherInformationList      = new (std::nothrow) List<CInformation*>();
    m_filteredMetricsVector     = new (std::nothrow) Vector<CMetric*>( METRICS_VECTOR_INCREASE );
    m_filteredInformationVector = new (std::nothrow) Vector<CInformation*>( INFORMATION_VECTOR_INCREASE );
    m_metricsCalculator         = new (std::nothrow) CMetricsCalculator( m_device );
    // Set 'current' variables
    UseApiFilteredVariables( false );
    iu_memcpy_s( &m_filteredParams, sizeof(m_filteredParams), &m_params_1_0, sizeof(m_params_1_0) );
}

/*****************************************************************************\

Class:
    CMetricSet destructor

Method:
    ~CMetricSet

Description:
    Deallocates memory.

\*****************************************************************************/
CMetricSet::~CMetricSet()
{
    MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
    MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
    MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.D3D1XDevDependentName );
    MD_SAFE_DELETE_ARRAY( m_params_1_0.ApiSpecificId.OGLQueryIntelName );

    ClearCachedMetricsAndInformation();
    MD_SAFE_DELETE( m_filteredMetricsVector );
    MD_SAFE_DELETE( m_filteredInformationVector );

    MD_SAFE_DELETE( m_metricsVector );
    MD_SAFE_DELETE( m_informationVector );
    MD_SAFE_DELETE( m_complementarySetsVector );

    // To prevent double memory freeing, original instances are in m_startRegisterSetList
    m_startRegsVector->FillWith( NULL );
    m_startRegsQueryVector->FillWith( NULL );

    MD_SAFE_DELETE( m_startRegsVector );
    MD_SAFE_DELETE( m_startRegsQueryVector );

    MD_SAFE_DELETE( m_startRegisterSetList );

    MD_SAFE_DELETE( m_otherMetricsList );
    MD_SAFE_DELETE( m_otherInformationList );
    MD_SAFE_DELETE( m_metricsCalculator );
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetParams

Description:
    Returns metric set params

Output:
    TMetricSetParams_1_4*  - metric set params

\*****************************************************************************/
TMetricSetParams_1_4* CMetricSet::GetParams( void )
{
    return m_currentParams;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetMetric

Description:
    Returns the chosen metric or null if index doesn't exist.

Input:
    uint32_t     index  - index of a metric

Output:
    IMetric_1_0*        - chosen metric or null

\*****************************************************************************/
IMetric_1_0* CMetricSet::GetMetric( uint32_t index )
{
    MD_CHECK_PTR_RET( m_currentMetricsVector, NULL );
    if( index < m_currentMetricsVector->GetCount() )
    {
        return (IMetric_1_0*)(*m_currentMetricsVector)[index];
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetInformation

Description:
    Returns the chosen information or null if index doesn't exist.

Input:
    uint32_t     index  - index of an information

Output:
    IInformation_1_0*   - chosen information or null

\*****************************************************************************/
IInformation_1_0* CMetricSet::GetInformation( uint32_t index )
{
    MD_CHECK_PTR_RET( m_currentInformationVector, NULL );
    if( index < m_currentInformationVector->GetCount() )
    {
        return (IInformation_1_0*)(*m_currentInformationVector)[index];
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetComplementaryMetricSet

Description:
    Returns the chosen complementary metric set or null if index doesn't exist.

Input:
    uint32_t     index  - index of a complementary set

Output:
    IMetricSet_1_5*     - chosen complementary metric set or null

\*****************************************************************************/
IMetricSet_1_5* CMetricSet::GetComplementaryMetricSet( uint32_t index )
{
    MD_CHECK_PTR_RET( m_complementarySetsVector, NULL );
    if( index < m_complementarySetsVector->GetCount() )
    {
        IMetricSet_1_5* metricSet = NULL;
        size_t stringLength = strlen( (*m_complementarySetsVector)[ index ] );
        uint32_t metricSetsCount = m_concurrentGroup->GetParams()->MetricSetsCount;
        for( uint32_t i = 0; i < metricSetsCount; i++ )
        {
            metricSet = m_concurrentGroup->GetMetricSet( i );
            if( strncmp( metricSet->GetParams()->SymbolName, (*m_complementarySetsVector)[ index ] , stringLength ) == 0 )
            {
                return metricSet;
            }
        }
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    Activate

Description:
    To enable this configuration before query instance is created or IO stream is opened.
    Locks the concurrent group and sends the configuration if lock was successful.

Output:
    TCompletionCode  - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CMetricSet::Activate( void )
{
    return ActivateInternal( true, true );
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    Deactivate

Description:
    Unlocks the concurrent group after query instance is created or IO stream is opened.
    Sends 'empty' read regs config if it was previously set.

Output:
    TCompletionCode  - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CMetricSet::Deactivate( void )
{
    MD_LOG_ENTER();
    TCompletionCode ret = CC_OK;

    if( m_isReadRegsCfgSet )
    {
        CDriverInterface* driverInterface  = m_device->GetDriverInterface();
        TRegister         emptyRrConfig    = {0, 0, REGISTER_TYPE_MMIO};
        TRegister*        emptyRrConfigPtr = &emptyRrConfig;                    // Because we will need 'array of pointers'

        ret = driverInterface->SendReadRegsConfig( &emptyRrConfigPtr, 1, m_currentParams->ApiMask );
        if( ret == CC_OK )
        {
            // Update PmRegsHandles and reset rrSet flag
            driverInterface->GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle,
                &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
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

/*****************************************************************************\

Class:
    CMetricSet

Method:
    MetricGroupNameToId

Description:
    To get order of group names

Output:
    uint32_t - group id, METRIC_GROUP_NAME_ID_INVALID if error

\*****************************************************************************/
uint32_t CMetricSet::MetricGroupNameToId( const char* groupName )
{
    MD_CHECK_PTR_RET( groupName, METRIC_GROUP_NAME_ID_INVALID );

    uint32_t groupId = 0, tokenNo = 0;
    char *token = NULL, *tokenNext = NULL, *groupNameCopy = NULL;

    groupNameCopy = GetCopiedCString( groupName );
    MD_CHECK_PTR_RET( groupNameCopy, METRIC_GROUP_NAME_ID_INVALID );

    token = iu_strtok_s( groupNameCopy, "/", &tokenNext );
    while( token != NULL )
    {
        uint32_t partialGroupId = GetPartialGroupId( token, tokenNo++ );
        if( partialGroupId == METRIC_GROUP_NAME_ID_INVALID )
        {
            groupId = METRIC_GROUP_NAME_ID_INVALID;
            break;
        }

        groupId += partialGroupId;
        token    = iu_strtok_s( NULL, "/", &tokenNext );
    }

    MD_SAFE_DELETE_ARRAY( groupNameCopy );
    return groupId;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetPartialGroupId

Description:
    Returns group id based on a given depth and group name.

Input:
    char*        groupName - group name at depth
    uint32_t     level     - group name level, e.g. A\B\C - A has level 0, B has level 1

Output:
    uint32_t    - group id, METRIC_GROUP_NAME_ID_INVALID if error

\*****************************************************************************/
uint32_t CMetricSet::GetPartialGroupId( char* groupName, uint32_t level )
{
    MD_ASSERT( groupName != NULL );

    if( level > MD_METRIC_GROUP_NAME_LEVEL_MAX )
    {
        MD_LOG( LOG_ERROR, "maximum group name level allowed is %u", MD_METRIC_GROUP_NAME_LEVEL_MAX );
        return METRIC_GROUP_NAME_ID_INVALID;
    }

    uint32_t groupId      = METRIC_GROUP_NAME_ID_INVALID;
    uint32_t currentLevel = 1 << level;
    uint32_t shift        = (MD_METRIC_GROUP_NAME_LEVEL_MAX - level) * MD_BYTE;
    uint32_t pairCount    = sizeof(GroupNamePairs) / sizeof(TMetricGroupNameIdPair);

    for( uint32_t i = 0; i < pairCount; i++ )
    {
        if( ( GroupNamePairs[i].LevelMask & currentLevel ) && ( strcmp(groupName, GroupNamePairs[i].Name) == 0 ) )
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

//****************************************************************************/
// Helper macro to get CustomMetricParams
//****************************************************************************/
#define MD_CUSTOM_METRIC_PARAMS(params, version) (params)->CustomMetricParams_##version

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddCustomMetric

Description:
    Adds the custom metric with the given parameters.

Input:
    TAddCustomMetricParams * params - params

Output:
    IMetric_1_0* - newly created metric, NULL if error

\*****************************************************************************/
IMetric_1_0* CMetricSet::AddCustomMetric( TAddCustomMetricParams* params )
{
    if( params == NULL )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, params );
        return NULL;
    }

    if( params->Type != METRIC_CUSTOM_PARAMS_1_0 )
    {
        MD_LOG(LOG_ERROR, "Unsupported TAddCustomMetricParams Type: %u", params->Type);
        return NULL;
    }

    const char*       symbolName              = MD_CUSTOM_METRIC_PARAMS(params, 1_0).SymbolName;
    const char*       shortName               = MD_CUSTOM_METRIC_PARAMS(params, 1_0).ShortName;
    const char*       groupName               = MD_CUSTOM_METRIC_PARAMS(params, 1_0).GroupName;
    const char*       longName                = MD_CUSTOM_METRIC_PARAMS(params, 1_0).LongName;
    const char*       dxToOglAlias            = MD_CUSTOM_METRIC_PARAMS(params, 1_0).DxToOglAlias;
    uint32_t          usageFlagsMask          = MD_CUSTOM_METRIC_PARAMS(params, 1_0).UsageFlagsMask;
    uint32_t          apiMask                 = MD_CUSTOM_METRIC_PARAMS(params, 1_0).ApiMask;
    TMetricResultType resultType              = MD_CUSTOM_METRIC_PARAMS(params, 1_0).ResultType;
    const char*       resultUnits             = MD_CUSTOM_METRIC_PARAMS(params, 1_0).MetricResultUnits;
    TMetricType       metricType              = MD_CUSTOM_METRIC_PARAMS(params, 1_0).MetricType;
    int64_t           loWatermark             = MD_CUSTOM_METRIC_PARAMS(params, 1_0).LowWatermark;
    int64_t           hiWatermark             = MD_CUSTOM_METRIC_PARAMS(params, 1_0).HighWatermark;
    THwUnitType       hwType                  = MD_CUSTOM_METRIC_PARAMS(params, 1_0).HwUnitType;
    const char*       ioReadEquation          = MD_CUSTOM_METRIC_PARAMS(params, 1_0).IoReadEquation;
    const char*       deltaFunction           = MD_CUSTOM_METRIC_PARAMS(params, 1_0).DeltaFunction;
    const char*       queryReadEquation       = MD_CUSTOM_METRIC_PARAMS(params, 1_0).QueryReadEquation;
    const char*       normalizationEquation   = MD_CUSTOM_METRIC_PARAMS(params, 1_0).NormEquation;
    const char*       maxValueEquation        = MD_CUSTOM_METRIC_PARAMS(params, 1_0).MaxValueEquation;
    const char*       signalName              = MD_CUSTOM_METRIC_PARAMS(params, 1_0).SignalName;
    const char*       availabilityEquation    = MD_CUSTOM_METRIC_PARAMS(params, 1_0).AvailabilityEquation;

    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( m_metricsVector, NULL );

    if( !AreMetricParamsValid(
        symbolName, shortName, longName, groupName, metricType, resultType, resultUnits, hwType, dxToOglAlias) )
    {
        MD_LOG( LOG_ERROR, "invalid custom metric parameters" );
        return NULL;
    }
    if( IsMetricAlreadyAdded( symbolName ) )
    {
        MD_LOG( LOG_ERROR, "metric already added: %s", symbolName );
        return NULL;
    }

    uint32_t groupId = MetricGroupNameToId( groupName );
    if( groupId == METRIC_GROUP_NAME_ID_INVALID )
    {
        MD_LOG( LOG_ERROR, "invalid metric group name" );
        return NULL;
    }

    CMetric* metric = ( CMetric* ) new (std::nothrow) CMetric( m_device, m_metricsVector->GetCount(), symbolName, shortName, longName,
        groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, resultUnits, loWatermark, hiWatermark, hwType,
        dxToOglAlias, signalName );
    MD_CHECK_PTR_RET( metric, NULL );

    if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK   ||
        metric->SetSnapshotReportReadEquation( ioReadEquation ) != CC_OK   ||
        metric->SetDeltaReportReadEquation( queryReadEquation ) != CC_OK   ||
        metric->SetNormalizationEquation( normalizationEquation ) != CC_OK ||
        metric->SetSnapshotReportDeltaFunction( deltaFunction ) != CC_OK   ||
        metric->SetMaxValueEquation( maxValueEquation ) != CC_OK )
    {
        MD_LOG( LOG_ERROR, "error setting custom metric equations" );
        MD_SAFE_DELETE( metric );
        return NULL;
    }

    m_metricsVector->PushBack( metric );
    m_params_1_0.MetricsCount = m_metricsVector->GetCount();
    m_isCustom = true;

    // Refresh cached filtered metrics
    RefreshCachedMetricsAndInformation();

    MD_LOG_EXIT();
    return metric;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddCustomMetric

Description:
    Adds custom metric with given parameters.

Input:
    const char * symbolName                  -
    const char * shortName                   -
    const char * groupName                   -
    const char * longName                    -
    const char * dxToOglAlias                -
    uint32_t     usageFlagsMask              -
    uint32_t     apiMask                     -
    TMetricResultType resultType             -
    const char * resultUnits                 -
    TMetricType metricType                   -
    int64_t *   loWatermark                  -
    int64_t *   hiWatermark                  -
    THwUnitType hwType                       -
    const char * ioReadEquation              -
    const char * deltaFunction               -
    const char * queryReadEquation           -
    const char * normalizationEquation       -
    const char * maxValueEquation            -
    const char * signalName                  -

Output:
    IMetric_1_0* - newly created metric, NULL if error

\*****************************************************************************/
IMetric_1_0* CMetricSet::AddCustomMetric( const char* symbolName, const char* shortName, const char* groupName, const char* longName,
    const char* dxToOglAlias, uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits,
    TMetricType metricType, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation,
    const char* deltaFunction, const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation,
    const char* signalName )
{
    TAddCustomMetricParams params                      = {METRIC_CUSTOM_PARAMS_1_0,};
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

/*****************************************************************************\

Class:
    CMetricSet

Method:
    SetApiSpecificId

Description:
    Sets the API specific ids in the metric set params.

Input:
    const char * dx9        -
    uint32_t     dx10       -
    uint32_t     ogl        -
    uint32_t     ocl        -
    uint32_t     hwConfig   -

Output:
    TCompletionCode         - result

\*****************************************************************************/
TCompletionCode CMetricSet::SetApiSpecificId( const char* dx9Fourcc, uint32_t dx9QueryId, uint32_t dx10Counter, uint32_t oglQuery,
    uint32_t ocl, uint32_t hwConfig, const char* dx10CounterName, uint32_t dx10QueryId, const char* oglQueryName, uint32_t oglQueryARB )
{
    m_params_1_0.ApiSpecificId.D3D9QueryId              = dx9QueryId;
    m_params_1_0.ApiSpecificId.D3D9Fourcc               = dx9Fourcc ? (dx9Fourcc[0]) + (dx9Fourcc[1]<<8) + (dx9Fourcc[2]<<16) + (dx9Fourcc[3]<<24) : 0;
    m_params_1_0.ApiSpecificId.D3D1XQueryId             = dx10QueryId;
    m_params_1_0.ApiSpecificId.D3D1XDevDependentId      = dx10Counter;
    m_params_1_0.ApiSpecificId.D3D1XDevDependentName    = GetCopiedCString( dx10CounterName );
    m_params_1_0.ApiSpecificId.OGLQueryIntelId          = oglQuery;
    m_params_1_0.ApiSpecificId.OGLQueryIntelName        = GetCopiedCString( oglQueryName );
    m_params_1_0.ApiSpecificId.OGLQueryARBTargetId      = oglQueryARB;
    m_params_1_0.ApiSpecificId.OCL                      = ocl;
    m_params_1_0.ApiSpecificId.HwConfigId               = hwConfig;

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    SetApiSpecificId

Description:
    Sets the API specific ids in the metric set params.

Input:
    TApiSpecificId_1_0 apiSepcificId    - API specific id struct to set

Output:
    TCompletionCode                     - result

\*****************************************************************************/
TCompletionCode CMetricSet::SetApiSpecificId( TApiSpecificId_1_0 apiSpecificId )
{
    m_params_1_0.ApiSpecificId                       = apiSpecificId;
    m_params_1_0.ApiSpecificId.D3D1XDevDependentName = GetCopiedCString( apiSpecificId.D3D1XDevDependentName );
    m_params_1_0.ApiSpecificId.OGLQueryIntelName     = GetCopiedCString( apiSpecificId.OGLQueryIntelName );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddMetric

Description:
    Adds a new metric to the metric set. Null if failed.

Input:
    const char * symbolicName           -
    const char * shortName              -
    const char * longName               -
    const char * groupName              -
    uint32_t     apiMask                -
    TMetricType metricType              -
    TMetricResultType resultType        -
    const char * units                  -
    const char * maxValue               -
    THwUnitType hwType                  -
    const char * availabilityEquation   -

Output:
    CMetric*  - pointer to the newly created metric.

\*****************************************************************************/
CMetric* CMetricSet::AddMetric( const char* symbolName, const char* shortName, const char* longName, const char* groupName,
    uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType,
    const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* availabilityEquation,
    const char* alias, const char* signalName, bool isCustom /*= false*/ )
{
    MD_CHECK_PTR_RET( m_metricsVector, NULL );
    MD_CHECK_PTR_RET( m_otherMetricsList, NULL );

    if( groupName == NULL )
    {
        groupName = "";
    }

    CMetric* metric = ( CMetric* ) new (std::nothrow) CMetric( m_device, m_metricsVector->GetCount(), symbolName, shortName, longName,
        groupName, groupId, usageFlagsMask, apiMask, metricType, resultType, units, loWatermark, hiWatermark, hwType, alias,
        signalName );
    MD_CHECK_PTR_RET( metric, NULL );

    if( metric->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
    {
        MD_SAFE_DELETE( metric );
        return NULL;
    }

    if( m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
    {
        if( IsMetricAlreadyAdded( symbolName ) )
        {
            m_otherMetricsList->PushBack( metric );
        }
        else
        {
            m_metricsVector->PushBack( metric );
            m_params_1_0.MetricsCount = m_metricsVector->GetCount();
        }
    }
    else
    {
        m_otherMetricsList->PushBack( metric );
    }

    if( isCustom )
    {
        m_isCustom = true;
    }

    return metric;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddMetric

Description:
    Adds a new metric to the metric set. Null if failed.

Input:
    CMetric* metric - metric to add

Output:
    CMetric*        - added metric, NULL if error

\*****************************************************************************/
CMetric* CMetricSet::AddMetric( CMetric* metric )
{
    MD_CHECK_PTR_RET( m_metricsVector, NULL );
    MD_CHECK_PTR_RET( m_otherMetricsList, NULL );
    MD_CHECK_PTR_RET( metric, NULL );

    if( IsMetricAlreadyAdded( metric->GetParams()->SymbolName ) )
    {
        m_otherMetricsList->PushBack( metric );
    }
    else
    {
        m_metricsVector->PushBack( metric );
        m_params_1_0.MetricsCount = m_metricsVector->GetCount();
    }

    return metric;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddInformation

Description:
    Adds a new information to the metric set. Null if failed.

Input:
    const char * symbolicName           -
    const char * shortName              -
    const char * longName               -
    const char * groupName              -
    uint32_t     apiMask                -
    TInformationType informationType    -
    const char*  availabilityEquation   -

Output:
    CInformation*   - pointer to the newly created information

\*****************************************************************************/
CInformation* CMetricSet::AddInformation( const char* symbolName, const char* shortName, const char* longName,
    const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits,
    const char* availabilityEquation )
{
    MD_CHECK_PTR_RET( m_informationVector, NULL );
    MD_CHECK_PTR_RET( m_otherInformationList, NULL );

    CInformation* information = ( CInformation* ) new (std::nothrow) CInformation( m_device, m_informationVector->GetCount(), symbolName, shortName,
        longName, groupName, apiMask, informationType, informationUnits );
    MD_CHECK_PTR_RET( information, NULL );

    if( information->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
    {
        MD_SAFE_DELETE( information );
        return NULL;
    }

    if( m_device->IsAvailabilityEquationTrue( availabilityEquation ) )
    {
        m_informationVector->PushBack( information );
        m_params_1_0.InformationCount = m_informationVector->GetCount();
    }
    else
    {
        m_otherInformationList->PushBack( information );
    }

    return information;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddInformation

Description:
    Adds a new information to the metric set. Null if failed.

Input:
    CInformation* information  - information to add

Output:
    CInformation*              - pointer to the added information

\*****************************************************************************/
CInformation* CMetricSet::AddInformation( CInformation* information )
{
    MD_CHECK_PTR_RET( m_informationVector, NULL );
    MD_CHECK_PTR_RET( information, NULL );

    m_informationVector->PushBack( information );
    m_params_1_0.InformationCount = m_informationVector->GetCount();

    return information;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddComplementaryMetricSet

Description:
    Adds a complementary metric set by name.

Input:
    const char * complementaryMetricSetSymbolicName - complementary metric set name to add

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricSet::AddComplementaryMetricSet( const char* complementaryMetricSetSymbolicName )
{
    MD_CHECK_PTR_RET( complementaryMetricSetSymbolicName, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( m_complementarySetsVector, CC_ERROR_GENERAL );

    if( strcmp( complementaryMetricSetSymbolicName, "" ) == 0 )
    {
        return CC_OK; //NULL is fine condition for "" name
    }

    char* metricSetName = GetCopiedCString( complementaryMetricSetSymbolicName );

    m_complementarySetsVector->PushBack( metricSetName );
    m_params_1_0.ComplementarySetsCount = m_complementarySetsVector->GetCount();

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddComplementaryMetricSet

Description:
    Adds multiple complementary metric sets by name.

Input:
    const char* complementaryMetricSetsList - comma separated list of complementary sets (symbol names)

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricSet::AddComplementaryMetricSets( const char* complementarySetsList )
{
    MD_CHECK_PTR_RET( complementarySetsList, CC_ERROR_INVALID_PARAMETER );

    char *token = NULL, *tokenNext = NULL, *complementarySets = NULL;

    complementarySets = GetCopiedCString( complementarySetsList );
    MD_CHECK_PTR_RET( complementarySets, CC_ERROR_NO_MEMORY );

    token = iu_strtok_s( complementarySets, ",", &tokenNext );
    while( token != NULL )
    {
        if( AddComplementaryMetricSet( token ) != CC_OK )
        {
            MD_LOG( LOG_DEBUG, "error adding complementary metric sets" );
            MD_SAFE_DELETE_ARRAY( complementarySets );
            return CC_ERROR_GENERAL;
        }
        token = iu_strtok_s( NULL, ",", &tokenNext );
    }
    MD_SAFE_DELETE_ARRAY( complementarySets );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    ActivateInternal

Description:
    To enable this configuration before query instance is created or IO stream is opened.
    Locks the concurrent group and sends the configuration if flag was set and the lock was successful.

Input:
    bool sendConfigFlag      - if true, StartConfigRegs are sent
    bool sendQueryConfigFlag - if true, query specific regs are sent too

Output:
    TCompletionCode           - result, *CC_OK* is ok

\*****************************************************************************/
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
            MD_LOG(LOG_DEBUG, "sending start configuration failed");
            retVal = CC_ERROR_GENERAL;
        }
    }

    MD_LOG_EXIT();
    return retVal;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddStartConfigRegisterSet

Description:
    Adds a new empty start config register set to the metric set.

Input:
    uint32_t     configId             - config id
    uint32_t     configPriority       - priority, lower is more important
    const char*  availabilityEquation - availability equation (default NULL - available)
    TConfigType  configType           - e.g. COMMON, SNAPSHOT (default COMMON)

Output:
    TCompletionCode - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CMetricSet::AddStartRegisterSet( uint32_t configId, uint32_t configPriority,
    const char* availabilityEquation /*= NULL */, TConfigType configType /*= CONFIG_TYPE_COMMON*/ )
{
    MD_CHECK_PTR_RET( m_startRegisterSetList, CC_ERROR_GENERAL );

    CRegisterSet* registerSet = ( CRegisterSet* ) new (std::nothrow) CRegisterSet( m_device, configId, configPriority, configType );
    MD_CHECK_PTR_RET( registerSet, CC_ERROR_NO_MEMORY );

    if( registerSet->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
    {
        MD_SAFE_DELETE( registerSet );
        return CC_ERROR_GENERAL;
    }
    m_startRegisterSetList->PushBack( registerSet );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AddStartConfigRegister

Description:
    Adds configuration register to the metric set to send it during Activate method.
    It only adds registers to a register set. RefreshConfigRegisters() adds them to
    a real configuration which will be sent.

Input:
    uint32_t      offset - register offset
    uint32_t      value  - register value
    TRegisterType type   - register type

Output:
    TCompletionCode      - result

\*****************************************************************************/
TCompletionCode CMetricSet::AddStartConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
{
    MD_CHECK_PTR_RET( m_startRegsVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_startRegisterSetList, CC_ERROR_GENERAL );

    CRegisterSet* registerSet = m_startRegisterSetList->GetCount() > 0 ? m_startRegisterSetList->Back() : NULL;
    MD_CHECK_PTR_RET( registerSet, CC_ERROR_GENERAL );

    TRegister* reg = registerSet->AddConfigRegister( offset, value, type );
    MD_CHECK_PTR_RET( reg, CC_ERROR_GENERAL );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    RefreshConfigRegisters

Description:
    Chooses start registers with the highest priorities and adds them to a configuration.
    Only one set with a given ID can be used in the configuration.

Output:
    TCompletionCode - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CMetricSet::RefreshConfigRegisters()
{
    uint32_t      id          = 0;
    CRegisterSet* registerSet = NULL;

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

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetRegSetLoIdHiPriority

Description:
    Iterates through all the start register sets looking for a set with the highest
    priority and a given ID. If there's no such registerSet is NULL. If there's no
    sets with the given ID or higher it returns false.

Input:
    uint32_t       id          - config id to look for
    CRegisterSet** registerSet - (out) found register set, NULL if not found

Output:
    bool - false if there is no register sets with given id or higher (end of search)

\*****************************************************************************/
bool CMetricSet::GetStartRegSetHiPriority( uint32_t id, CRegisterSet** registerSet )
{
    MD_CHECK_PTR_RET( registerSet, false );
    MD_CHECK_PTR_RET( m_startRegisterSetList, false );

    bool          ret = false;
    CRegisterSet* set = NULL;
    uint32_t      highestPriority = 0xFFFFFFFF; // Lower is more important

    Node<CRegisterSet*>* registerSetNode = m_startRegisterSetList->GetHeadNode();
    while( registerSetNode != NULL )
    {
        TRegisterSetParams* params = registerSetNode->value->GetParams();
        if( params->ConfigId >= id )
        {
            ret = true;
            if( params->ConfigId == id && registerSetNode->value->IsAvailable() && params->ConfigPriority < highestPriority )
            {
                highestPriority = params->ConfigPriority;
                set = registerSetNode->value;
            }
        }
        registerSetNode = registerSetNode->nextNode;
    }
   *registerSet = set;

    return ret;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetStartConfiguration

Description:
    Returns common start config registers (without query specific).

Input:
    uint32_t*     count - (out) registers count

Output:
    TRegister**         - pointers to the common start config registers

\*****************************************************************************/
TRegister** CMetricSet::GetStartConfiguration( uint32_t* count )
{
    MD_CHECK_PTR_RET( m_startRegsVector, NULL );

    if( count != NULL )
    {
        *count = m_startRegsVector->GetCount();
    }
    return m_startRegsVector->GetMemoryPointer();
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    SendStartConfiguration

Description:
    Sends a start configuration to the driver.

Input:
    bool sendQueryConfigFlag - if true, send also query specific configuration

Output:
    TCompletionCode - result, *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricSet::SendStartConfiguration( bool sendQueryConfigFlag )
{
    MD_CHECK_PTR_RET( m_startRegsVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_startRegsQueryVector, CC_ERROR_GENERAL );

    TCompletionCode   ret             = CC_OK;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();

    if( CheckSendConfigRequired( sendQueryConfigFlag ) )
    {
        // Prepare register reference lists to sent
        Vector<TRegister*>* pmRegs   = new (std::nothrow) Vector<TRegister*>( START_REGS_VECTOR_INCREASE );
        Vector<TRegister*>* readRegs = new (std::nothrow) Vector<TRegister*>( START_REGS_VECTOR_INCREASE );
        if( !pmRegs || !readRegs )
        {
            MD_SAFE_DELETE( pmRegs );
            MD_SAFE_DELETE( readRegs );
            return CC_ERROR_NO_MEMORY;
        }

        AppendToConfiguration( m_startRegsVector, pmRegs, readRegs );
        if( sendQueryConfigFlag )
        {
            AppendToConfiguration( m_startRegsQueryVector, pmRegs, readRegs );
        }

        //Verify if NOA programming is present
        if( pmRegs->GetCount() == 0 || CheckNoaProgrammingExists( pmRegs ) )
        {
            // Send configurations
            ret = driverInterface->SendPmRegsConfig( pmRegs->GetMemoryPointer(), pmRegs->GetCount(), m_currentParams->ApiMask );
            if( ret == CC_OK && readRegs->GetCount() )
            {
                ret = driverInterface->SendReadRegsConfig( readRegs->GetMemoryPointer(), readRegs->GetCount(), m_currentParams->ApiMask );
            }

            if( ret == CC_OK )
            {
                m_isReadRegsCfgSet = readRegs->GetCount() > 0;

                m_pmRegsConfigInfo.IsQueryConfig = sendQueryConfigFlag;
                driverInterface->GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId, &m_pmRegsConfigInfo.OaConfigHandle,
                    &m_pmRegsConfigInfo.GpConfigHandle, &m_pmRegsConfigInfo.RrConfigHandle );
            }
        }
        else
        {
            MD_LOG( LOG_ERROR, "NOA programming missing" );
            ret = CC_ERROR_NOT_SUPPORTED;
        }

        // To prevent deleting of the original references
        pmRegs->FillWith( NULL );
        readRegs->FillWith( NULL );

        MD_SAFE_DELETE( pmRegs );
        MD_SAFE_DELETE( readRegs );
    }

    return ret;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AppendToConfiguration

Description:
    Appends register from the source vector to the two destination (PmRegs and ReadRegs)
    vectors. It's because read and pm regs are sent using different way.

Input:
    Vector<TRegister*>* sourceRegs  - source vector for all regs
    Vector<TRegister*>* outPmRegs   - dest vector for PmRegs
    Vector<TRegister*>* outReadRegs - dest vector for ReadRegs

\*****************************************************************************/
void CMetricSet::AppendToConfiguration( Vector<TRegister*>* sourceRegs, Vector<TRegister*>* outPmRegs, Vector<TRegister*>* outReadRegs )
{
    MD_ASSERT( sourceRegs != NULL );
    MD_ASSERT( outReadRegs != NULL );
    MD_ASSERT( outPmRegs != NULL );

    for( uint32_t i = 0; i < sourceRegs->GetCount(); i++ )
    {
        if( (*sourceRegs)[i]->type == REGISTER_TYPE_MMIO )
        {
            outReadRegs->PushBack( (*sourceRegs)[i] );
        }
        else
        {
            outPmRegs->PushBack( (*sourceRegs)[i] );
        }
    }
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CheckNoaProgrammingExists

Description:
    Check if NOA regs are present in given vector

Input:
    Vector<TRegister*>* regVector  - vector to check for NOA regs

Output:
    bool - false if no NOA regs found in given vector

\*****************************************************************************/
bool CMetricSet::CheckNoaProgrammingExists( Vector<TRegister*>* regVector )
{
    for( uint32_t i = 0; i < regVector->GetCount(); i++ )
    {
        if( (*regVector)[i]->type == REGISTER_TYPE_NOA )
        {
            return true;
        }
    }
    return false;
}
/*****************************************************************************\

Class:
    CMetricSet

Method:
    CheckSendConfigRequired

Description:
    Checks whether the configuration in KMD needs to be updated to be used with
    the current metric set.

Output:
    bool - false if sending is unnecessary

\*****************************************************************************/
bool CMetricSet::CheckSendConfigRequired( bool sendQueryConfigFlag )
{
    bool ret = true;
    CDriverInterface* driverInterface = m_device->GetDriverInterface();

    // If measurement type didn't change and config handles were checked before
    if( m_pmRegsConfigInfo.IsQueryConfig == sendQueryConfigFlag &&
        (m_pmRegsConfigInfo.OaConfigHandle != 0 ||
         m_pmRegsConfigInfo.GpConfigHandle != 0 ||
         m_pmRegsConfigInfo.RrConfigHandle != 0) )
    {
        uint32_t        oaCfgHandle = 0;
        uint32_t        gpCfgHandle = 0;
        uint32_t        rrCfgHandle = 0;
        TCompletionCode retCode     = CC_OK;

        retCode = driverInterface->GetPmRegsConfigHandles( m_params_1_0.ApiSpecificId.HwConfigId,
            &oaCfgHandle, &gpCfgHandle, &rrCfgHandle );

        if( retCode == CC_OK &&
            oaCfgHandle == m_pmRegsConfigInfo.OaConfigHandle &&
            gpCfgHandle == m_pmRegsConfigInfo.GpConfigHandle &&
            rrCfgHandle == m_pmRegsConfigInfo.RrConfigHandle )
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

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetReportType

Description:
    Returns metric's report type for IO Stream.

Output:
    TReportType - metric's report type

\*****************************************************************************/
TReportType CMetricSet::GetReportType()
{
    return m_reportType;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    WriteCMetricSetToFile

Description:
    Writes metric set to file.

Input:
    FILE* metricFile - handle to metric file

Output:
    TCompletionCode  - result of the operation

\*****************************************************************************/
TCompletionCode CMetricSet::WriteCMetricSetToFile( FILE* metricFile )
{
    uint32_t             count           = 0;
    Node<CMetric*>*      metricNode      = NULL;
    Node<CInformation*>* informationNode = NULL;
    Node<CRegisterSet*>* registerSetNode = NULL;

    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
        return CC_ERROR_INVALID_PARAMETER;
    }

    MD_CHECK_PTR_RET( m_metricsVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_informationVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_otherMetricsList, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_otherInformationList, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_startRegisterSetList, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_complementarySetsVector, CC_ERROR_GENERAL );

    // m_params_1_0
    WriteCStringToFile( m_params_1_0.SymbolName, metricFile );
    WriteCStringToFile( m_params_1_0.ShortName, metricFile );
    fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
    fwrite( &m_params_1_0.CategoryMask, sizeof( m_params_1_0.CategoryMask ), 1, metricFile );
    fwrite( &m_params_1_0.RawReportSize, sizeof( m_params_1_0.RawReportSize ), 1, metricFile );
    fwrite( &m_params_1_0.QueryReportSize, sizeof( m_params_1_0.QueryReportSize ), 1, metricFile );
    fwrite( &m_params_1_0.PlatformMask, sizeof( m_params_1_0.PlatformMask ), 1, metricFile );
    fwrite( &m_params_1_0.GtMask, sizeof( m_params_1_0.GtMask ), 1, metricFile );
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

    // m_metricsVector & m_otherMetricsList
    count = m_metricsVector->GetCount() + m_otherMetricsList->GetCount();
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );
    count = m_metricsVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        // Write in the correct order
        metricNode = m_otherMetricsList->GetHeadNode();
        while( metricNode != NULL )
        {
            if( i == metricNode->value->GetParams()->IdInSet )
            {
                metricNode->value->WriteCMetricToFile( metricFile );
            }
            metricNode = metricNode->nextNode;
        }

        (*m_metricsVector)[i]->WriteCMetricToFile( metricFile );
    }
    // Write remaining unavailable metrics
    metricNode = m_otherMetricsList->GetHeadNode();
    while( metricNode != NULL )
    {
        if( metricNode->value->GetParams()->IdInSet >= count )
        {
            metricNode->value->WriteCMetricToFile( metricFile );
        }
        metricNode = metricNode->nextNode;
    }

    // m_informationVector & m_otherInformationList
    count = m_informationVector->GetCount() + m_otherInformationList->GetCount();
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );
    count = m_informationVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        // Write in the correct order
        informationNode = m_otherInformationList->GetHeadNode();
        while( informationNode != NULL )
        {
            if( i == informationNode->value->GetParams()->IdInSet )
            {
                informationNode->value->WriteCInformationToFile( metricFile );
            }
            informationNode = informationNode->nextNode;
        }
        (*m_informationVector)[i]->WriteCInformationToFile( metricFile );
    }
    // Write remaining unavailable information
    informationNode = m_otherInformationList->GetHeadNode();
    while( informationNode != NULL )
    {
        if( informationNode->value->GetParams()->IdInSet >= count )
        {
            informationNode->value->WriteCInformationToFile( metricFile );
        }
        informationNode = informationNode->nextNode;
    }

    // m_startRegisterSetList
    count = m_startRegisterSetList->GetCount();
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );
    registerSetNode = m_startRegisterSetList->GetHeadNode();
    while( registerSetNode != NULL )
    {
        registerSetNode->value->WriteCRegisterSetToFile( metricFile );
        registerSetNode = registerSetNode->nextNode;
    }

    // m_stopRegisterSetList - remains to be backward compatible, count is always 0
    count = 0;
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );

    // m_complementarySetsVector
    count = m_complementarySetsVector->GetCount();
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );
    for( uint32_t i = 0; i < count; i++ )
    {
        WriteCStringToFile( (*m_complementarySetsVector)[i], metricFile );
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    InheritFromMetricSet

Description:
    Inherits metrics with signal name containing specified string and all the information from
    the reference metric set. When signalName is NULL copy all the metrics.

Input:
    CMetricSet* referenceMetricSet   - metric set to be copied
    const char* signalName           - signal name
    bool        copyInformationOnly  - Inherit only informations

Output:
    TCompletionCode - result of the operation

\*****************************************************************************/
TCompletionCode CMetricSet::InheritFromMetricSet( CMetricSet* referenceMetricSet, const char* signalName, bool copyInformationOnly )
{
    MD_CHECK_PTR_RET( referenceMetricSet, CC_ERROR_INVALID_PARAMETER );

    CMetric*      metric               = NULL;
    CMetric*      referenceMetric      = NULL;
    CInformation* information          = NULL;
    CInformation* referenceInformation = NULL;
    const char*   metricSignalName     = NULL;
    uint32_t      count                = 0;

    // Copy metrics with signal name containing signalName
    if( !copyInformationOnly )
    {
        count = referenceMetricSet->GetParams()->MetricsCount;
        for( uint32_t i = 0; i < count; i++ )
        {
            referenceMetric = (CMetric*)referenceMetricSet->GetMetric( i );
            if( referenceMetric == NULL )
            {
                MD_ASSERT( false );
                return CC_ERROR_GENERAL;
            }
            metricSignalName = referenceMetric->GetSignalName();
            if( signalName == NULL ||
                ( metricSignalName != NULL && strstr( metricSignalName, signalName ) != NULL ) )
            {
                metric = new (std::nothrow) CMetric( *referenceMetric );
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
        referenceInformation = (CInformation*)referenceMetricSet->GetInformation( i );
        if( referenceInformation == NULL )
        {
            MD_ASSERT( false );
            return CC_ERROR_GENERAL;
        }
        information = new (std::nothrow) CInformation( *referenceInformation );
        if( !information )
        {
            MD_LOG( LOG_DEBUG, "error copying information" );
            return CC_ERROR_GENERAL;
        }
        AddInformation( information );
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    IsMetricAlreadyAdded

Description:
    Checks if metric of the given name is already added to the metrics set.

Input:
    const char * symbolicName   - symbolic name of a metric to check

Output:
    bool                        - true when already added

\*****************************************************************************/
bool CMetricSet::IsMetricAlreadyAdded( const char* symbolName )
{
    MD_CHECK_PTR_RET( m_metricsVector, false );
    MD_CHECK_PTR_RET( m_otherMetricsList, false );
    MD_CHECK_PTR_RET( symbolName, false );

    for( uint32_t i = 0; i < m_metricsVector->GetCount(); i++ )
    {
        if( ((*m_metricsVector)[i]) && (strcmp( symbolName, (*m_metricsVector)[i]->GetParams()->SymbolName ) == 0) )
        {
            return true;
        }
    }

    Node<CMetric*>* metricNode = m_otherMetricsList->GetHeadNode();
    while( metricNode != NULL )
    {
        if( (metricNode->value) && (strcmp( symbolName, metricNode->value->GetParams()->SymbolName ) == 0) )
        {
            return true;
        }
        metricNode = metricNode->nextNode;
    }

    return false;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    IsCustom

Description:
    True if this is a custom Metric Set or default with custom metrics added.

Output:
    bool - true if custom

\*****************************************************************************/
bool CMetricSet::IsCustom()
{
    return m_isCustom;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    SetApiFiltering

Description:
    Sets filtering by the given API mask. After enabling the set will contain only
    metrics and information available for the given API.
    IoStream and Query measurements MUST NOT be mixed.

Output:
    TCompletionCode - *CC_OK* mease succcess

\*****************************************************************************/
TCompletionCode CMetricSet::SetApiFiltering( uint32_t apiMask )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( m_filteredMetricsVector,     CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( m_filteredInformationVector, CC_ERROR_GENERAL );

    if( !IsApiFilteringMaskValid( apiMask ) )
    {
        MD_LOG( LOG_ERROR, "error: invalid filtering API mask" );
        MD_LOG_EXIT();
        return CC_ERROR_INVALID_PARAMETER;
    }

    if( apiMask == 0 || apiMask == API_TYPE_ALL || apiMask == m_params_1_0.ApiMask )
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

/*****************************************************************************\

Class:
    CMetricSet

Method:
    IsApiFilteringMaskValid

Description:
    Validates API mask used in SetApiFiltering method.
    IoStream and Query measurements MUST NOT be mixed.

Output:
    bool - true if valid, false otherwise

\*****************************************************************************/
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

/*****************************************************************************\

Class:
   CMetricSet

Method:
    EnableApiFiltering

Description:
    Enables or disables API filtering for the current metric set.
    IoStream and Query measurements MUST NOT be mixed.

Input:
    uint32_t     apiMask - API mask for filtering
    bool         enable  - if true enable, if false disable

\*****************************************************************************/
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
            iu_memcpy_s( &m_filteredParams, sizeof(m_filteredParams), &m_params_1_0, sizeof(m_params_1_0) );
            m_filteredParams.ApiMask = apiMask;

            // Cache and modify counts in params
            RefreshCachedMetricsAndInformation();
        }

        UseApiFilteredVariables( true );
    }

    MD_LOG( LOG_DEBUG, "API filtering %s", m_isFiltered ? "enabled" : "disabled" );
    MD_LOG_EXIT();
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    UseApiFilteredVariables

Description:
    Swaps currently used variables in such methods as GetParams, GetMetric etc. to
    filtered or non-filtered ones.

Input:
    bool enable - if true change to filtered
                  if false change to non-filtered

\*****************************************************************************/
void CMetricSet::UseApiFilteredVariables( bool enable )
{
    if( enable )
    {
        m_currentParams            = &m_filteredParams;
        m_currentMetricsVector     = m_filteredMetricsVector;
        m_currentInformationVector = m_filteredInformationVector;
        m_isFiltered               = true;
    }
    else
    {
        m_currentParams            = &m_params_1_0;
        m_currentMetricsVector     = m_metricsVector;
        m_currentInformationVector = m_informationVector;
        m_isFiltered               = false;
    }

    MD_LOG( LOG_DEBUG, "use API filtered variables: %s", enable ? "TRUE" : "FALSE" );
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CacheMetricsAndInformation

Description:
    Clears cached metrics and information, then updates them using the whole
    MetricSet and API mask stored in filtered params.

\*****************************************************************************/
void CMetricSet::RefreshCachedMetricsAndInformation()
{
    if( m_filteredParams.ApiMask == m_params_1_0.ApiMask )
    {
        // Nothing to do, return
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
    for( uint32_t i = 0; i < m_params_1_0.MetricsCount; i++ )
    {
        IMetric_1_0* metric = GetMetric( i );
        if( metric && (metric->GetParams()->ApiMask & m_filteredParams.ApiMask) > 0 )
        {
            m_filteredMetricsVector->PushBack( (CMetric*)metric );
        }
    }

    // Cache information
    for( uint32_t i = 0; i < m_params_1_0.InformationCount; i++ )
    {
        IInformation_1_0* information = GetInformation( i );
        if( information && (information->GetParams()->ApiMask & m_filteredParams.ApiMask) > 0 )
        {
            m_filteredInformationVector->PushBack( (CInformation*)information );
        }
    }

    // Modify counts
    m_filteredParams.MetricsCount     = m_filteredMetricsVector->GetCount();
    m_filteredParams.InformationCount = m_filteredInformationVector->GetCount();

    if( filteringEnabled )
    {
        UseApiFilteredVariables( true );
    }
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    ClearCachedMetricsAndInformation

Description:
    Clear cached metrics and information. Instances are set to NULL because
    Clear() method deletes objects stored in the List. This's not desired.

\*****************************************************************************/
void CMetricSet::ClearCachedMetricsAndInformation()
{
    // To prevent double memory freeing, original instances are in m_metrics/informationVector
    uint32_t count = m_filteredMetricsVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        (*m_filteredMetricsVector)[i] = NULL;
    }
    count = m_filteredInformationVector->GetCount();
    for( uint32_t i = 0; i < count; i++ )
    {
        (*m_filteredInformationVector)[i] = NULL;
    }

    m_filteredMetricsVector->Clear();
    m_filteredInformationVector->Clear();
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CalculateMetrics

Description:
    Conducts the whole process of metrics and information calculation for multiple reports.
    It's API agnostic - user doesn't have to worry about API he has used.
    User has to provide input buffer and its size, output buffer and its size with enough space for
    all calculated metrics and information.
    The amount of input reports is calculated based on rawData size and the size of single raw report.

Input:
    const unsigned char* rawData                - raw report data
    uint32_t             rawDataSize            - size of raw report data
    TTypedValue_1_0*     out                    - (OUT) buffer for calculated reports
    uint32_t             outSize                - size of the provided output buffer
    uint32_t*            outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    bool                 enableContextFiltering - if true enable context filtering during calculation

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricSet::CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out,
    uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering )
{
    if( enableContextFiltering )
    {
        MD_LOG( LOG_ERROR, "error: context filtering not supported" );
        return CC_ERROR_NOT_SUPPORTED;
    }

    return CalculateMetrics( rawData, rawDataSize, out, outSize, outReportCount, NULL, 0 );
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CalculateMetrics

Description:
    Conducts the whole process of metrics and information calculation for multiple reports.
    It's API agnostic - user doesn't have to worry about API he has used.
    User has to provide input buffer and its size, output buffer and its size with enough space for
    all calculated metrics and information.
    The amount of input reports is calculated based on rawData size and the size of single raw report.

    Optional MaxValues calculation added, if MaxValueEquation isn't defined for the metric its current
    normalized value is used.

Input:
    const unsigned char* rawData                - raw report data
    uint32_t             rawDataSize            - size of raw report data in bytes
    TTypedValue_1_0*     out                    - (OUT) buffer for calculated reports
    uint32_t             outSize                - size of the provided output buffer in bytes
    uint32_t*            outReportCount         - (OUT - optional) how much reports were calculated and are stored in the out buffer
    TTypedValue_1_0*     outMaxValues           - (OUT - optional) should have a memory for at least 'MetricCount * RawReportCount' values, can be NULL. Calculated maxValues for each metric.
                                                  If MaxValueEquation isn't defined for the metric, MaxValue will be equal to the current, normalized metric value.
    uint32_t             outMaxValuesSize       - size of the provided buffer for max values in bytes

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricSet::CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out,
    uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( out,     CC_ERROR_INVALID_PARAMETER );
    if( !rawDataSize )
    {
        MD_LOG( LOG_DEBUG, "nothing to calculate, rawDataSize: 0" );
        MD_LOG_EXIT();
        return CC_OK;
    }
    if( !outMaxValues || !outMaxValuesSize )
    {
        MD_LOG( LOG_DEBUG, "max values won't be calculated, outMaxValues: %p, outMaxValuesSize: %u", outMaxValues, outMaxValuesSize );
        outMaxValues     = NULL;
        outMaxValuesSize = 0;
    }

    if( !m_isFiltered )
    {
        MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
        return CC_ERROR_GENERAL;
    }

    TCompletionCode  ret             = CC_OK;
    uint32_t         streamMask      = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;
    TMeasurementType measurementType = (m_currentParams->ApiMask & streamMask ) ? MEASUREMENT_TYPE_SNAPSHOT_IO :
                                                                                  MEASUREMENT_TYPE_DELTA_QUERY;
    uint32_t         rawReportSize   = (measurementType == MEASUREMENT_TYPE_SNAPSHOT_IO) ? m_currentParams->RawReportSize :
                                                                                           m_currentParams->QueryReportSize;
    uint32_t         rawReportCount  = rawDataSize / rawReportSize;

    // Validation
    ret = ValidateCalculateMetricsParams( rawDataSize, rawReportSize, outSize, rawReportCount, outMaxValuesSize );
    MD_CHECK_CC_RET( ret );

    // Initialize manager and context
    CCalculationManager* calculationManager = NULL;
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
    {   /*  void */ }

    MD_LOG( LOG_DEBUG, "calculated %u out reports", calculationContext.CommonCalculationContext.OutReportCount );
    MD_LOG( LOG_DEBUG, "max values%s calculated", outMaxValues ? "" : " not" );

    if( outReportCount )
    {
        *outReportCount = calculationContext.CommonCalculationContext.OutReportCount;
    }

    InitializeCalculationContext( calculationContext, NULL, measurementType, NULL, NULL, NULL, 0, false );
deinitialize_manager:
    InitializeCalculationManager( measurementType, &calculationManager, false );

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    CalculateIoMeasurementInformation

Description:
    Calculates IoMeasurementInformation obtained on every ReadIoStream.

Input:
    TTypedValue_1_0* out     - (OUT) buffer for calculated IoMeasurementInformation
    uint32_t         outSize - output buffer size, should be at least
                               IoMeasurementInformation count * sizeof(TTypedValue_1_0)

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
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

    m_metricsCalculator->ReadIoMeasurementInformation( m_concurrentGroup, out );
    MD_LOG( LOG_DEBUG, "calculated %u out io information", m_concurrentGroup->GetParams()->IoMeasurementInformationCount );

    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    ValidateCalculateMetricsParams

Description:
    Validates parameters passed to CalculateMetrics.
    Subjects of validation: i.a. input and output buffer alignments, output buffer size.

Input:
    uint32_t rawDataSize      - raw report data size
    uint32_t rawReportSize    - size of one individual raw report
    uint32_t outSize          - size of out buffer in bytes
    uint32_t rawReportCount   - raw report count
    uint32_t outMaxValuesSize - size of max values buffer in bytes

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricSet::ValidateCalculateMetricsParams( uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize,
    uint32_t rawReportCount, uint32_t outMaxValuesSize )
{
    // size of one individual calculated report in bytes
    uint32_t outReportSize       = (m_currentParams->MetricsCount + m_currentParams->InformationCount) * sizeof(TTypedValue_1_0);
    // size of one individual calculated max values report in bytes
    uint32_t maxValuesReportSize = m_currentParams->MetricsCount * sizeof(TTypedValue_1_0);

    if( rawDataSize % rawReportSize != 0 )
    {
        MD_LOG( LOG_ERROR, "error: input buffer has incorrect size" );
        MD_LOG( LOG_DEBUG, "rawDataSize: %u, rawReportSize: %u", rawDataSize, rawReportSize );
        return CC_ERROR_INVALID_PARAMETER;
    }
    if( outSize % outReportSize != 0 )
    {
        MD_LOG( LOG_ERROR, "error: output buffer has incorrect size" );
        MD_LOG( LOG_DEBUG, "outSize: %u, outReportSize: %u", outSize, outReportSize );
        return CC_ERROR_INVALID_PARAMETER;
    }
    if( outReportSize == 0 )
    {
        MD_LOG( LOG_DEBUG, "outReportSize: 0. Nothing to calculate." );
        return CC_OK;
    }
    if( rawReportCount > (outSize / outReportSize) )
    {
        MD_LOG( LOG_ERROR, "error: output buffer to small" );
        MD_LOG( LOG_DEBUG, "rawReportCount: %u, outSize: %u, outReportSize: %u", rawReportCount, outSize, outReportSize );
        return CC_ERROR_INVALID_PARAMETER;
    }
    if( outMaxValuesSize &&
        rawReportCount > (outMaxValuesSize / maxValuesReportSize) )
    {
        MD_LOG( LOG_ERROR, "error: maxValues buffer to small" );
        MD_LOG( LOG_DEBUG, "rawReportCount: %u, outMaxValuesSize: %u, maxValueReportSize: %u", rawReportCount, outMaxValuesSize, maxValuesReportSize );
        return CC_ERROR_INVALID_PARAMETER;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    InitializeCalculationManager

Description:
    Creates or destroys CalculationManager adequate to the given measurement type.

Input:
    TMeasurementType      measurementType     - type of measurement for which manager will be created
    CCalculationManager** calculationManager  - (OUT) pointer to the newly created CalculationManager, null if error
    bool                  init                - if true initialization,
                                                if false deinitialization

\*****************************************************************************/
void CMetricSet::InitializeCalculationManager( TMeasurementType measurementType, CCalculationManager** calculationManager, bool init )
{
    if( !init )
    {
        MD_SAFE_DELETE( *calculationManager );
        MD_LOG( LOG_DEBUG, "calculation manager deinitialization" );
        return;
    }

    MD_ASSERT( *calculationManager == NULL );
    switch( measurementType )
    {
        case MEASUREMENT_TYPE_DELTA_QUERY:
            *calculationManager = new (std::nothrow) CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>();
            MD_LOG( LOG_DEBUG, "query calculation manager created" );
            return;

        case MEASUREMENT_TYPE_SNAPSHOT_IO:
            *calculationManager = new (std::nothrow) CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>();
            MD_LOG( LOG_DEBUG, "ioStream calculation manager created" );
            return;

        default:
            *calculationManager = NULL;
            MD_LOG( LOG_ERROR, "not supported measurement type" );
            return;
    }
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    InitializeCalculationContext

Description:
    Resets calculation context and initializes it with user provided data.
    After execution the context is ready for metrics calculations.

Input:
    TCalculationContext& context            - (OUT) calculation context
    CalcManager*         calculationManager - already initialized calculation manager
    TMeasurementType     measurementType    - type of measurements
    TTypedValue_1_0*     out                - output buffer
    TTypedValue_1_0*     outMaxValues       - output buffer for MaxValues, can be NULL
    const unsigned char* rawData            - input buffer with raw report data
    uint32_t             rawReportCount     - raw report count
    bool                 init               - if true initialization,
                                              if false deinitialization

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CMetricSet::InitializeCalculationContext( TCalculationContext& context, CCalculationManager* calculationManager,
    TMeasurementType measurementType, TTypedValue_1_0* out, TTypedValue_1_0* outMaxValues, const unsigned char* rawData, uint32_t rawReportCount, bool init )
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
    context.CommonCalculationContext.DeltaValues    = new (std::nothrow) TTypedValue_1_0[m_currentParams->MetricsCount];
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
        InitializeCalculationContext( context, NULL, measurementType, NULL, NULL, NULL, 0, false );
        MD_LOG_EXIT();
        return CC_ERROR_GENERAL;
    }

    MD_LOG( LOG_DEBUG, "calculation context initialized" );
    MD_LOG( LOG_DEBUG, "metricSet: %s", context.CommonCalculationContext.MetricSet->GetParams()->ShortName );
    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    AreMetricParamsValid

Description:
    Checks the correctness of the given metric parameters.

Input:
    const char* symbolicName     -
    const char* shortName        -
    const char* longName         -
    const char* groupName        -
    TMetricType metricType       -
    TMetricResultType resultType -
    const char* units            -
    THwUnitType hwType           -
    const char* alias            -

Output:
    bool -

\*****************************************************************************/
bool CMetricSet::AreMetricParamsValid( const char* symbolName, const char* shortName, const char* longName, const char* groupName,
    TMetricType metricType, TMetricResultType resultType, const char* units, THwUnitType hwType, const char* alias )
{
    if( (symbolName == NULL) || (strcmp( symbolName, "" ) == 0) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, symbolName );
        return false;
    }
    if( (shortName == NULL) || (strcmp( shortName, "" ) == 0) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, shortName );
        return false;
    }
    if( (longName == NULL) || (strcmp( longName, "" ) == 0) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, longName );
        return false;
    }
    if( (groupName == NULL) || (strcmp( groupName, "" ) == 0) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, groupName );
        return false;
    }
    if( (uint32_t)metricType >= METRIC_TYPE_LAST )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, metricType );
        return false;
    }
    if( (uint32_t)resultType >= RESULT_LAST )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, resultType );
        return false;
    }
    if( (units == NULL) || (strcmp( units, "" ) == 0) )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, units );
        return false;
    }
    if( (uint32_t)hwType >= HW_UNIT_LAST )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, hwType );
        return false;
    }
    if( alias == NULL )
    {
        MD_LOG_INVALID_PARAMETER( LOG_ERROR, alias );
        return false;
    }

    return true;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    HasInformation

Description:
    Returns true if in the m_informationVector there is an information with the given
    symbol name.

Input:
    const char * symbolName - information name to look for

Output:
    bool - true if found

\*****************************************************************************/
bool CMetricSet::HasInformation( const char* symbolName )
{
    MD_CHECK_PTR_RET( m_informationVector, false );
    MD_CHECK_PTR_RET( symbolName, false );

    for( uint32_t i = 0; i < m_params_1_0.InformationCount; i++ )
    {
        IInformation_1_0* information = GetInformation( i );
        if( information && information->GetParams()->SymbolName != NULL &&
            strcmp( information->GetParams()->SymbolName, symbolName ) == 0 )
        {
            return true;
        }
    }

    return false;
}

/*****************************************************************************\

Class:
    CMetricSet

Method:
    GetMetricsCalculator

Description:
    Returns metrics calculator.

Output:
    CMetricsCalculator* - metrics calculator or *NULL* if error

\*****************************************************************************/
CMetricsCalculator* CMetricSet::GetMetricsCalculator()
{
    return m_metricsCalculator;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    CMetric constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device      -
    uint32_t     id              -
    const char * name            -
    const char * shortName       -
    const char * longName        -
    const char * group           -
    uint32_t     apiMask         -
    TMetricType metricType       -
    TMetricResultType resultType -
    const char * units           -
    const char * maxValue        -
    THwUnitType hwType           -

\*****************************************************************************/
CMetric::CMetric( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName,
    const char* group, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType,
    TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType,
    const char* alias, const char* signalName )
{
    m_params_1_0.IdInSet           = id;
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
    m_params_1_0.IoReadEquation             = NULL;
    m_params_1_0.QueryReadEquation          = NULL;
    m_params_1_0.NormEquation               = NULL;
    m_params_1_0.MaxValueEquation           = NULL;
    m_availabilityEquation                  = NULL;

    m_normEquation      = NULL;
    m_ioReadEquation    = NULL;
    m_queryReadEquation = NULL;
    m_maxValueEquation  = NULL;

    m_device = device;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    CMetric copy constructor

Description:
    Copy constructor.

\*****************************************************************************/
CMetric::CMetric(const CMetric& other)
    : m_device(other.m_device)
{
    memset( &m_params_1_0, 0, sizeof(m_params_1_0) );

    m_params_1_0.IdInSet           = other.m_params_1_0.IdInSet;
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

    m_availabilityEquation         = ( other.m_availabilityEquation ) ? new (std::nothrow) CEquation( *other.m_availabilityEquation ) : NULL;
    m_ioReadEquation               = ( other.m_ioReadEquation )    ? new (std::nothrow) CEquation( *other.m_ioReadEquation )    : NULL;
    m_queryReadEquation            = ( other.m_queryReadEquation ) ? new (std::nothrow) CEquation( *other.m_queryReadEquation ) : NULL;
    m_normEquation                 = ( other.m_normEquation )      ? new (std::nothrow) CEquation( *other.m_normEquation )      : NULL;
    m_maxValueEquation             = ( other.m_maxValueEquation )  ? new (std::nothrow) CEquation( *other.m_maxValueEquation )  : NULL;

    m_params_1_0.IoReadEquation    = (IEquation_1_0*)m_ioReadEquation;
    m_params_1_0.QueryReadEquation = (IEquation_1_0*)m_queryReadEquation;
    m_params_1_0.NormEquation      = (IEquation_1_0*)m_normEquation;
    m_params_1_0.MaxValueEquation  = (IEquation_1_0*)m_maxValueEquation;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    ~CMetric destructor

Description:
    Deallocates memory.

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CMetric

Method:
    GetParams

Description:
    Returns the metric params.

Output:
    TMetricParams_1_0*  - pointer to metric params.

\*****************************************************************************/
TMetricParams_1_0* CMetric::GetParams( void )
{
    return &m_params_1_0;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    GetMetricValue

Description:
    Decodes and returns value from the string which may be a symbol.
    Empty string is equal to zero.

Input:
    const char* valueString     - value string

Output:
    uint64_t            - read value

\*****************************************************************************/
uint64_t CMetric::GetMetricValue( const char* valueString )
{
    uint64_t ret = 0LL;

    if( ( valueString == NULL ) || ( strcmp( valueString, "" ) == 0 ) )
    {
        return 0LL;
    }

    if( ( valueString[0] == '$' ) && ( valueString[1] != 0 ) )
    {
        TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( &valueString[1] );
        if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ))
        {
            ret = (uint64_t) pValue->ValueUInt64;
        }
        else if ( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ))
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

/*****************************************************************************\

Class:
    CMetric

Method:
    SetSnapshotReportReadEquation

Description:
    Sets the snapshot (IO) read equation in the metric.

Input:
    const char * equationString - euqation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetSnapshotReportReadEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_ioReadEquation, equationString );

    m_params_1_0.IoReadEquation = ( IEquation_1_0* )m_ioReadEquation;
    return ret;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetDeltaReportReadEquation

Description:
    Sets the delta (query) read equation in the metric.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetDeltaReportReadEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_queryReadEquation, equationString );

    m_params_1_0.QueryReadEquation = ( IEquation_1_0* )m_queryReadEquation;
    return ret;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetNormalizationEquation

Description:
    Sets the normalization equation in the metric.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetNormalizationEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_normEquation, equationString );

    m_params_1_0.NormEquation = ( IEquation_1_0* )m_normEquation;
    return ret;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetMaxValueEquation

Description:
    Sets the max value equation in the metric.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetMaxValueEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_maxValueEquation, equationString );

    m_params_1_0.MaxValueEquation = ( IEquation_1_0* )m_maxValueEquation;
    return ret;
}


/*****************************************************************************\

Class:
    CMetric

Method:
    SetSnapshotReportDeltaFunction

Description:
    Sets the snapshot report delta equation in the metric.
    It's an equation to calculate delta values of to snapshot report values.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetSnapshotReportDeltaFunction( const char* equationString )
{
    return SetDeltaFunction( equationString, &m_params_1_0.DeltaFunction );
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetSnapshotReportDeltaFunction

Description:
    Sets the snapshot report delta equation in the metric.
    It's an equation to calculate delta values of to snapshot report values.

Input:
    TDeltaFunction_1_0 deltaFunction    - parsed equation

Output:
    TCompletionCode                     - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetSnapshotReportDeltaFunction( TDeltaFunction_1_0 deltaFunction )
{
    m_params_1_0.DeltaFunction = deltaFunction;

    return CC_OK;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetAvailabilityEquation

Description:
    Sets the availability equation in the metric. It's used to determine if the metric
    is available on the current platform.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::SetAvailabilityEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );

    return ret;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    WriteCMetricToFile

Description:
    Writes the metric object to file.

Input:
    FILE* metricFile - handle to a metric file

Output:
    TCompletionCode  - result of the operation

\*****************************************************************************/
TCompletionCode CMetric::WriteCMetricToFile( FILE* metricFile )
{
    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
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

/*****************************************************************************\

Class:
    CMetric

Method:
    GetSignalName

Description:
    Returns signal name, can be NULL.

Output:
    const char* - signal name

\*****************************************************************************/
const char* CMetric::GetSignalName()
{
    return m_signalName;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    CInformation constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device          -
    uint32_t         id              -
    const char*      name            -
    const char*      shortName       -
    const char*      longName        -
    const char*      group           -
    uint32_t         apiMask         -
    TInformationType informationType -

\*****************************************************************************/
CInformation::CInformation( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName,
    const char* longName, const char* group, uint32_t apiMask, TInformationType informationType, const char* informationUnits )
{
    m_params_1_0.IdInSet    = id;
    m_params_1_0.SymbolName = GetCopiedCString( name );
    m_params_1_0.ShortName  = GetCopiedCString( shortName );
    m_params_1_0.LongName   = GetCopiedCString( longName );
    m_params_1_0.GroupName  = GetCopiedCString( group );
    m_params_1_0.ApiMask    = apiMask;
    m_params_1_0.InfoType   = informationType;
    m_params_1_0.InfoUnits  = GetCopiedCString( informationUnits );

    m_params_1_0.OverflowFunction.FunctionType = DELTA_FUNCTION_NULL;

    m_params_1_0.IoReadEquation    = NULL;
    m_params_1_0.QueryReadEquation = NULL;

    m_availabilityEquation = NULL;
    m_ioReadEquation       = NULL;
    m_queryReadEquation    = NULL;

    m_device = device;

}

/*****************************************************************************\

Class:
    CInformation

Method:
    CInformation copy constructor

Description:
    Copy constructor.

\*****************************************************************************/
CInformation::CInformation(const CInformation& other)
    : m_device( other.m_device )
{
    m_params_1_0.IdInSet    = other.m_params_1_0.IdInSet;
    m_params_1_0.SymbolName = GetCopiedCString( other.m_params_1_0.SymbolName );
    m_params_1_0.ShortName  = GetCopiedCString( other.m_params_1_0.ShortName );
    m_params_1_0.GroupName  = GetCopiedCString( other.m_params_1_0.GroupName );
    m_params_1_0.LongName   = GetCopiedCString( other.m_params_1_0.LongName );
    m_params_1_0.ApiMask    = other.m_params_1_0.ApiMask;
    m_params_1_0.InfoType   = other.m_params_1_0.InfoType;
    m_params_1_0.InfoUnits  = GetCopiedCString( other.m_params_1_0.InfoUnits );

    m_params_1_0.OverflowFunction = other.m_params_1_0.OverflowFunction;

    m_availabilityEquation  = ( other.m_availabilityEquation ) ? new (std::nothrow) CEquation( *other.m_availabilityEquation ) : NULL;
    m_ioReadEquation        = ( other.m_ioReadEquation )    ? new (std::nothrow) CEquation( *other.m_ioReadEquation )    : NULL;
    m_queryReadEquation     = ( other.m_queryReadEquation ) ? new (std::nothrow) CEquation( *other.m_queryReadEquation ) : NULL;

    m_params_1_0.IoReadEquation    = (IEquation_1_0*)m_ioReadEquation;
    m_params_1_0.QueryReadEquation = (IEquation_1_0*)m_queryReadEquation;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    ~CInformation destructor

Description:
    Deallocates memory.

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CInformation

Method:
    GetParams

Description:
    Returns the information params.

Output:
    TInformationParams_1_0* - pointer to the information params

\*****************************************************************************/
TInformationParams_1_0* CInformation::GetParams( void )
{
    return &m_params_1_0;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    SetSnapshotReportReadEquation

Description:
    Sets the snapshot (IO) read equation in the information.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::SetSnapshotReportReadEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_ioReadEquation, equationString );

    m_params_1_0.IoReadEquation = ( IEquation_1_0* )m_ioReadEquation;
    return ret;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    SetDeltaReportReadEquation

Description:
    Sets the delta (query) read equation in the information.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::SetDeltaReportReadEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_queryReadEquation, equationString );

    m_params_1_0.QueryReadEquation = ( IEquation_1_0* )m_queryReadEquation;
    return ret;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    SetAvailabilityEquation

Description:
    Sets the availability equation in the information. It's used to determine if
    the information is available on the current platform.

Input:
    const char * equationString - equation string, could be empty

Output:
    TCompletionCode             - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::SetAvailabilityEquation( const char* equationString )
{
    TCompletionCode ret = SetEquation( m_device, &m_availabilityEquation, equationString );

    return ret;
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetOverflowFunction

Description:
    Sets the overflow delta equation in the information.
    It's an equation to calculate whether the overflow occurs.

Input:
    const char* equationString - equation string, could be empty

Output:
    TCompletionCode            - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::SetOverflowFunction( const char* equationString )
{
    return SetDeltaFunction( equationString, &m_params_1_0.OverflowFunction );
}

/*****************************************************************************\

Class:
    CMetric

Method:
    SetOverflowFunction

Description:
    Sets the overflow delta equation in the information.
    It's an equation to calculate whether the overflow occurs.

Input:
    const char* equationString - equation string, could be empty

Output:
    TCompletionCode            - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::SetOverflowFunction( TDeltaFunction_1_0 overflowFunction )
{
    m_params_1_0.OverflowFunction = overflowFunction;

    return CC_OK;
}

/*****************************************************************************\

Class:
    CInformation

Method:
    WriteCInformationToFile

Description:
    Write the information object to file.

Input:
    FILE* metricFile - handle to metric file

Output:
    TCompletionCode  - result of the operation

\*****************************************************************************/
TCompletionCode CInformation::WriteCInformationToFile( FILE* metricFile )
{
    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
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

/*****************************************************************************\

Class:
    CInformation

Method:
    SetInformationValue

Description:
    Sets the value for the information as a given equation.

Input:
    uint32_t        value           - information value
    TEquationType   equationType    - equation to be set

Output:
    TCompletionCode - result of operation

\*****************************************************************************/
TCompletionCode CInformation::SetInformationValue( uint32_t value, TEquationType equationType )
{
    TCompletionCode ret = CC_OK;

    char strValue[11];  // Max string length for decimal uint32_t
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

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    CRegisterSet

Description:
    CRegisterSet constructor.

Input:
    CMetricsDevice* device         - metrics device
    uint32_t        configId       - config id
    uint32_t        configPriority - priority, lower more important
    TConfigType     configType     - e.g. COMMON, SNAPSHOT

\*****************************************************************************/
CRegisterSet::CRegisterSet( CMetricsDevice* device, uint32_t configId, uint32_t configPriority, TConfigType configType )
{
    m_device                = device;
    m_params.ConfigId       = configId;
    m_params.ConfigPriority = configPriority;
    m_params.ConfigType     = configType;
    m_availabilityEquation  = NULL;
    m_isAvailable           = true;

    m_regList               = new (std::nothrow) List<TRegister>();
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    ~CRegisterSet

Description:
    CRegisterSet destructor.

\*****************************************************************************/
CRegisterSet::~CRegisterSet()
{
    MD_SAFE_DELETE( m_regList );
    MD_SAFE_DELETE( m_availabilityEquation );
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    GetParams

Description:
    Returns params.

Output:
    TRegisterSetParams* - register set params

\*****************************************************************************/
TRegisterSetParams* CRegisterSet::GetParams()
{
    return &m_params;
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    SetAvailabilityEquation

Description:
    Sets the availability equation in a register set. It's used to determine if the set
    is available on the current platform.

Input:
    const char* equationString - equation string, could be empty

Output:
    TCompletionCode            - result of the operation

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    AddConfigRegister

Description:
    Adds config register to the register set.

Input:
    uint32_t      offset - register offset
    uint32_t      value  - value
    TRegisterType type   - register type

Output:
    TRegister* - added register

\*****************************************************************************/
TRegister* CRegisterSet::AddConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
{
    MD_CHECK_PTR_RET( m_regList, NULL );

    TRegister       reg;
    reg.offset = offset;
    reg.value  = value;
    reg.type   = ( type > REGISTER_TYPE_UNKNOWN && type < REGISTER_TYPE_LAST ) ? type : REGISTER_TYPE_UNKNOWN;

    m_regList->PushBack( reg );

    return &m_regList->Back();
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    IsAvailable

Description:
    True if register set is available on a current platform.

Output:
    bool - true if available on current platform

\*****************************************************************************/
bool CRegisterSet::IsAvailable()
{
    return m_isAvailable;
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    RegsToVector

Description:
    Copies register pointers to a given vector.
    !!WATCH OUT FOR DOUBLE MEMORY FREEING!!

Input:
    Vector<TRegister*>* regVector - destination vector

Output:
    TCompletionCode - result, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CRegisterSet::RegsToVector( Vector<TRegister*>* regVector )
{
    MD_CHECK_PTR_RET( regVector, CC_ERROR_INVALID_PARAMETER );

    Node<TRegister>* registerNode = m_regList->GetHeadNode();
    while( registerNode != NULL )
    {
        regVector->PushBack( &registerNode->value );
        registerNode = registerNode->nextNode;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CRegisterSet

Method:
    WriteCRegisterSetToFile

Description:
    Writes CRegisterSet object to a file.

Input:
    FILE* metricFile - handle to a metric file

Output:
    TCompletionCode  - result of the operation, *CC_OK* is ok

\*****************************************************************************/
TCompletionCode CRegisterSet::WriteCRegisterSetToFile( FILE* metricFile )
{
    MD_CHECK_PTR_RET( metricFile, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( m_regList, CC_ERROR_GENERAL );

    uint32_t         count        = 0;
    Node<TRegister>* registerNode = NULL;

    // m_params and availability equation
    fwrite( &m_params.ConfigId, sizeof(m_params.ConfigId), 1, metricFile );
    fwrite( &m_params.ConfigPriority, sizeof(m_params.ConfigPriority), 1, metricFile );
    fwrite( &m_params.ConfigType, sizeof(m_params.ConfigType), 1, metricFile );
    WriteEquationToFile( m_availabilityEquation, metricFile );

    // Registers
    count = m_regList->GetCount();
    fwrite( &count, sizeof( uint32_t ), 1, metricFile );
    registerNode = m_regList->GetHeadNode();
    while( registerNode != NULL )
    {
        fwrite( &registerNode->value, sizeof( registerNode->value ), 1, metricFile );
        registerNode = registerNode->nextNode;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CEquationElementInternal

Method:
    CEquationElementInternal constructor

Description:
    Constructor.

\*****************************************************************************/
CEquationElementInternal::CEquationElementInternal()
{
    memset( &Element_1_0, 0x0, sizeof( Element_1_0 ) );
    SymbolNameInternal[0] = 0;
    Element_1_0.SymbolName = SymbolNameInternal;
}

/*****************************************************************************\

Class:
    CEquationElementInternal

Method:
    CEquationElementInternal copy constructor

Description:
    CEquationElementInternal copy constructor

\*****************************************************************************/
CEquationElementInternal::CEquationElementInternal( const CEquationElementInternal& element )
{
    Element_1_0 = element.Element_1_0;
    iu_memcpy_s( SymbolNameInternal, sizeof(SymbolNameInternal), element.SymbolNameInternal, sizeof(SymbolNameInternal) );
    Element_1_0.SymbolName = SymbolNameInternal;
}

/*****************************************************************************\

Class:
    CEquationElementInternal

Method:
    operator=

Description:
    Assignment operator. Copies whole memory.

\*****************************************************************************/
CEquationElementInternal& CEquationElementInternal::operator= ( const CEquationElementInternal& element )
{
    Element_1_0 = element.Element_1_0;
    iu_memcpy_s( SymbolNameInternal, sizeof(SymbolNameInternal), element.SymbolNameInternal, sizeof(SymbolNameInternal) );
    Element_1_0.SymbolName = SymbolNameInternal;
    return *this;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    CEquation constructor

Description:
    Constructor.

Input:
    CMetricsDevice * device - parent metric device

\*****************************************************************************/
CEquation::CEquation( CMetricsDevice* device )
{
    m_elementsVector = new (std::nothrow) Vector<CEquationElementInternal>( EQUATION_VECTOR_INCREASE );
    m_device = device;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    CEquation copy constructor

Description:
    Copy constructor.

\*****************************************************************************/
CEquation::CEquation( const CEquation& other )
    : m_device(other.m_device)
{
    m_equationString = GetCopiedCString( other.m_equationString );
    m_elementsVector = new (std::nothrow) Vector<CEquationElementInternal>( EQUATION_VECTOR_INCREASE );

    uint32_t elementsCount = other.m_elementsVector->GetCount();
    for( uint32_t i = 0; i < elementsCount; i++ )
    {
        AddEquationElement( &(*other.m_elementsVector)[i] );
    }
}

/*****************************************************************************\

Class:
    CEquation

Method:
    CEquation destructor

Description:
    Deallocates memory.

\*****************************************************************************/
CEquation::~CEquation()
{
    MD_SAFE_DELETE_ARRAY( m_equationString );
    MD_SAFE_DELETE( m_elementsVector );
}

/*****************************************************************************\

Class:
    CEquation

Method:
    GetEquationElementsCount

Description:
    Returns equation elements count.

Output:
    uint32_t  - equation elements count

\*****************************************************************************/
uint32_t CEquation::GetEquationElementsCount()
{
    MD_CHECK_PTR_RET( m_elementsVector, 0 );
    return m_elementsVector->GetCount();
}

/*****************************************************************************\

Class:
    CEquation

Method:
    GetEquationElement

Description:
    Returns the equation element with given index. Null if doesn't exist.

Input:
    uint32_t     index      - equation element index

Output:
    TEquationElement_1_0*   - pointer to the chosen element

\*****************************************************************************/
TEquationElement_1_0* CEquation::GetEquationElement( uint32_t index )
{
    MD_CHECK_PTR_RET( m_elementsVector, NULL );
    if( index < m_elementsVector->GetCount() )
    {
        return &( (*m_elementsVector)[ index ].Element_1_0 );
    }
    return NULL;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    SolveBooleanEquation

Description:
    Used only for availability equations.

Output:
    bool    -   result of the solved boolean equation

\*****************************************************************************/
bool CEquation::SolveBooleanEquation( void )
{
    List<uint64_t> equationStack;
    uint64_t       qwordValue;
    uint32_t       algorithmCheck = 0;

    MD_CHECK_PTR_RET( m_elementsVector, false );

    for( uint32_t i = 0; i < m_elementsVector->GetCount(); i++ )
    {
        TEquationElement_1_0* element = &( (*m_elementsVector)[ i ].Element_1_0 );
        switch( element->Type )
        {
            case EQUATION_ELEM_IMM_UINT64:
                equationStack.PushBack( element->ImmediateUInt64 );
                algorithmCheck++;
                break;

            case EQUATION_ELEM_GLOBAL_SYMBOL:
            {
                TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( element->SymbolName );

                if( pValue && (pValue->ValueType == VALUE_TYPE_UINT64) )
                {
                    qwordValue = (uint64_t) pValue->ValueUInt64;
                }
                else if( pValue && (pValue->ValueType == VALUE_TYPE_UINT32) )
                {
                    qwordValue = (uint64_t) pValue->ValueUInt32;
                }
                else if( pValue && (pValue->ValueType == VALUE_TYPE_BOOL) )
                {
                    qwordValue = (uint64_t) pValue->ValueBool;
                }
                else
                {
                    MD_ASSERT( false );
                    qwordValue = 0;
                }
                equationStack.PushBack( qwordValue );
                algorithmCheck++;
                break;
            }

            case EQUATION_ELEM_OPERATION:
            {
                // Pop two values from stack
                uint64_t valueLast = equationStack.Back();
                equationStack.PopBack();
                algorithmCheck--;
                uint64_t valuePrev = equationStack.Back();
                equationStack.PopBack();
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
                        equationStack.Clear();
                        return false;
                }
                equationStack.PushBack( qwordValue );
                algorithmCheck++;
                break;
            }

            default:
                MD_LOG( LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element->Type );
                MD_ASSERT( false );
                equationStack.Clear();
                return false;
        }
    }
    if( m_elementsVector->GetCount() > 0 )
    {
        // here should be only 1 element on the list - the result (if the equation is fine)
        MD_ASSERT( algorithmCheck == 1 );
        qwordValue = equationStack.Back();
    }
    else
    {
        qwordValue = 0LL;
    }
    equationStack.Clear();

    return ( qwordValue != 0LL );
}

/*****************************************************************************\

Class:
    CEquation

Method:
    ParseEquationString

Description:
    Parses the equation string.

Input:
    const char * equationString - equation string to parse

Output:
    bool                        - result of the operation

\*****************************************************************************/
bool CEquation::ParseEquationString( const char* equationString )
{
    if(( equationString == NULL ) || ( strcmp( equationString, "" ) == 0 ))
    {
        m_equationString = NULL;
        return false;
    }

    char* token = NULL, *tokenNext = NULL, *string = NULL;

    string = GetCopiedCString( equationString );
    MD_CHECK_PTR_RET( string, false );

    token = iu_strtok_s( string, " ", &tokenNext );
    while( token != NULL )
    {
        if( !ParseEquationElement( token ) )
        {
            delete [] string;
            return false;
        }
        token = iu_strtok_s( NULL, " ", &tokenNext );
    }

    m_equationString = GetCopiedCString( equationString );
    delete [] string;
    return true;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    AddEquationElement

Description:
    Adds the element to the equation list.

Input:
    CEquationElementInternal * element  - equation element to add

Output:
    bool                                - result of the operation

\*****************************************************************************/
bool CEquation::AddEquationElement(CEquationElementInternal* element)
{
    MD_CHECK_PTR_RET( m_elementsVector, false );
    m_elementsVector->PushBack( *element );

    return true;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    ParseEquationElement

Description:
    Parses and adds the element to the equation list.

Input:
    const char* element    - equation element string to parse;
                             expected to be NULL-terminated

Output:
    bool                   - result of the operation

\*****************************************************************************/
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
    else if( strncmp( element, "dw@" , sizeof("dw@") - 1 ) == 0 )
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT32;
        anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], NULL, 0 );
        return AddEquationElement( &anElement );
    }
    else if( strncmp( element, "fl@" , sizeof("fl@") - 1 ) == 0 )
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_FLOAT;
        anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], NULL, 0 );
        return AddEquationElement( &anElement );
    }
    else if( strncmp( element, "qw@" , sizeof("qw@") - 1 ) == 0 )
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT64;
        anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], NULL, 0 );
        return AddEquationElement( &anElement );
    }
    else if( strncmp( element, "rd40@" , sizeof("rd40@") - 1 ) == 0 )
    {
        char* pEnd = (char *)&element[5];
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
    else if( strncmp( element, "bm@" , sizeof("bm@") - 1 ) == 0 )
    {
        char* pEnd = (char *)&element[3];
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
    else if( strncmp( element, "$$" , sizeof("$$") - 1 ) == 0 )
    {
        //Add element
        CEquationElementInternal anElement;

        iu_strncpy_s( anElement.SymbolNameInternal, sizeof(anElement.SymbolNameInternal), &element[2], sizeof(anElement.SymbolNameInternal) - 1 );
        //finish element
        anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;
        anElement.Element_1_0.Type       = EQUATION_ELEM_LOCAL_METRIC_SYMBOL;

        return AddEquationElement( &anElement );
    }
    else if( ( element[0] == '$' ) && ( element[1] != 0 ) )
    {
        CEquationElementInternal anElement;
        TTypedValue_1_0* value = m_device->GetGlobalSymbolValueByName( &element[1] );

        iu_strncpy_s( anElement.SymbolNameInternal, sizeof(anElement.SymbolNameInternal), &element[1], sizeof(anElement.SymbolNameInternal) - 1 );
        anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;

        if( value == NULL )
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
    else if( strchr( element, '.' ) != NULL ) //assume float number
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type           = EQUATION_ELEM_IMM_FLOAT;
        anElement.Element_1_0.ImmediateFloat = (float)atof( element );
        return AddEquationElement( &anElement );
    }
    else if( strncmp( element, "0x" , sizeof("0x") - 1 ) == 0 ) //assume hex integer 64
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
        anElement.Element_1_0.ImmediateUInt64 = iu_strtoull( element, NULL, 0 );
        return AddEquationElement( &anElement );
    }
    else if( element[0] >= '0' && element[0] <= '9' ) //assume decimal integer 64
    {
        CEquationElementInternal anElement;
        anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
        anElement.Element_1_0.ImmediateUInt64 = iu_strtoull( element, NULL, 10 );
        return AddEquationElement( &anElement );
    }

    MD_LOG( LOG_ERROR, "Unknown equation element: %s", element );
    return false;
}

/*****************************************************************************\

Class:
    CEquation

Method:
    WriteCEquationToFile

Description:
    Writes equation string to file.

Input:
    FILE* metricFile - handle to a metric file

Output:
    TCompletionCode  - result of the operation

\*****************************************************************************/
TCompletionCode CEquation::WriteCEquationToFile( FILE* metricFile )
{
    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
        return CC_ERROR_INVALID_PARAMETER;
    }

    WriteCStringToFile( m_equationString, metricFile );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    CSymbolSet constructor

Description:
    Constructor.

\*****************************************************************************/
CSymbolSet::CSymbolSet()
{
    m_driverInterface = GetDriverIfc();
    m_symbolVector    = new (std::nothrow) Vector<TGlobalSymbol*>( SYMBOLS_VECTOR_INCREASE );
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    CSymbolSet destructor

Description:
    Deallocates memory.

\*****************************************************************************/
CSymbolSet::~CSymbolSet()
{
    TGlobalSymbol* symbol = NULL;
    for( uint32_t i = 0; i < m_symbolVector->GetCount(); i++ )
    {
        symbol = (*m_symbolVector)[ i ];
        MD_SAFE_DELETE_ARRAY( symbol->symbol_1_0.SymbolName );
        if( symbol->symbol_1_0.SymbolTypedValue.ValueType == VALUE_TYPE_CSTRING )
        {
            MD_SAFE_DELETE_ARRAY( symbol->symbol_1_0.SymbolTypedValue.ValueCString );
        }
    }

    MD_SAFE_DELETE( m_symbolVector );
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    GetSymbolCount

Description:
    Returns symbol count.

Output:
    uint32_t -  symbol count

\*****************************************************************************/
uint32_t CSymbolSet::GetSymbolCount()
{
    MD_CHECK_PTR_RET( m_symbolVector, 0 );
    return m_symbolVector->GetCount();
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    GetSymbol

Description:
    Returns chosen symbol or null if not exists.

Input:
    uint32_t index      - index of symbol

Output:
    TGlobalSymbol_1_0*  - pointer to the symbol

\*****************************************************************************/
TGlobalSymbol_1_0* CSymbolSet::GetSymbol( uint32_t index )
{
    MD_CHECK_PTR_RET( m_symbolVector, NULL );

    if(( index < m_symbolVector->GetCount() ) && ( (*m_symbolVector)[ index ] ))
    {
        return &((*m_symbolVector)[ index ]->symbol_1_0);
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    GetSymbolValueByName

Description:
    Returns chosen symbol by name or null if not exists.

Input:
    const char * name   - name of symbol

Output:
    TTypedValue_1_0*    - pointer to symbol

\*****************************************************************************/
TTypedValue_1_0* CSymbolSet::GetSymbolValueByName( const char* name )
{
    MD_CHECK_PTR_RET( name, NULL );
    MD_CHECK_PTR_RET( m_symbolVector, NULL );

    for( uint32_t i = 0; i < m_symbolVector->GetCount(); i++ )
    {
        if(( (*m_symbolVector)[ i ] ) && ( strcmp( name, (*m_symbolVector)[ i ]->symbol_1_0.SymbolName ) == 0 ))
        {
            return &((*m_symbolVector)[ i ]->symbol_1_0.SymbolTypedValue);
        }
    }

    return NULL;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbol

Description:
    Adds symbol to symbol set.

Input:
    const char * name           - symbol name
    TTypedValue_1_0 typedValue  - symbol value
    TSymbolType symbolType      - symbol type

Output:
    TCompletionCode  - result of the operation

\*****************************************************************************/
TCompletionCode CSymbolSet::AddSymbol( const char* name, TTypedValue_1_0 typedValue, TSymbolType symbolType )
{
    MD_CHECK_PTR_RET( m_symbolVector, CC_ERROR_GENERAL );
    MD_CHECK_PTR_RET( name, CC_ERROR_GENERAL );

    MD_LOG( LOG_INFO, "%s - adding...", name );

    if( symbolType == SYMBOL_TYPE_DETECT )
    {
        TCompletionCode ret = DetectSymbolValue( name, &typedValue );
        MD_CHECK_CC_RET( ret );
    }

    TGlobalSymbol* symbol = (TGlobalSymbol*) new (std::nothrow) TGlobalSymbol;
    MD_CHECK_PTR_RET( symbol, CC_ERROR_NO_MEMORY );

    symbol->version = API_VERSION_1_0;
    symbol->symbol_1_0.SymbolName = GetCopiedCString( name );
    if( typedValue.ValueType == VALUE_TYPE_CSTRING )
    {
        symbol->symbol_1_0.SymbolTypedValue.ValueType = VALUE_TYPE_CSTRING;
        symbol->symbol_1_0.SymbolTypedValue.ValueCString = GetCopiedCString( typedValue.ValueCString );
    }
    else
    {
        symbol->symbol_1_0.SymbolTypedValue = typedValue;
    }
    symbol->symbolType = symbolType;

    m_symbolVector->PushBack( symbol );
    return CC_OK;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    DetectSymbolValue

Description:
    Gets certain symbol's values sending escapes to KMD.

Input:
    const char * name               - symbol name
    TTypedValue_1_0 * typedValue    - output value

Output:
    TCompletionCode                 - result of the operation

\*****************************************************************************/
TCompletionCode CSymbolSet::DetectSymbolValue( const char* name, TTypedValue_1_0* typedValue )
{
    MD_CHECK_PTR_RET( m_driverInterface, CC_ERROR_GENERAL );

    TCompletionCode        ret = CC_OK;
    GTDIDeviceInfoParamOut out;
    memset( &out, 0, sizeof(out) );

    if( strcmp( name, "EuCoresTotalCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "EuCoresPerSubsliceCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "EuSubslicesTotalCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "EuSubslicesPerSliceCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_PER_SLICE_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "EuSlicesTotalCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "EuThreadsCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EU_THREADS_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }

    else if( strcmp( name, "SubsliceMask" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SUBSLICES_MASK, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "SliceMask" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SLICES_MASK, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }

    else if( strcmp( name, "SamplersTotalCount" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_SAMPLERS_COUNT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "SamplersPerSubliceCount" ) == 0 )
    {
        // obsolete
        typedValue->ValueUInt32 = 1;
    }

    else if( strcmp( name, "MemoryPeakThroghputMB" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = (uint32_t)( out.ValueUint64 / (uint64_t)(MD_MBYTE) ); // value / MBYTE
    }
    else if( strcmp( name, "MemoryFrequencyMHz" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_DRAM_FREQUENCY, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
    }
    else if( strcmp( name, "GpuMinFrequencyMHz" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY, &out );
        if( ret != CC_OK )
        {
            // Possibly caused by disabled Turbo
            MD_LOG(LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", name);
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
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY, &out );
        if( ret != CC_OK )
        {
            // Possibly caused by disabled Turbo
            MD_LOG(LOG_WARNING, "%s not available, GpuCurrentFrequencyMHz used instead", name);
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
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32 / MD_MHERTZ;
    }

    else if( strcmp( name, "PciDeviceId" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PCI_DEVICE_ID, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "SkuRevisionId" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_REVISION_ID, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "PlatformIndex" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "ApertureSize" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_APERTURE_SIZE, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "Capabilities" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "PavpDisabled" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_CAPABILITIES, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueBool = IsPavpDisabled( out.ValueUint32 );
    }

    else if( strcmp( name, "NumberOfRenderOutputUnits" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "NumberOfShadingUnits" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }

    else if( strcmp( name, "OABufferMinSize" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }
    else if( strcmp( name, "OABufferMaxSize" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = out.ValueUint32;
    }

    else if( strcmp( name, "GpuTimestampFrequency" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = (uint32_t)out.ValueUint64;
    }
    else if( strcmp( name, "EdramSize") == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_EDRAM_SIZE, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = (uint32_t)out.ValueUint64;
    }
    else if( strcmp( name, "LLCSize") == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_LLC_SIZE, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = (uint32_t)out.ValueUint64;
    }
    else if( strcmp( name, "L3Size") == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_L3_SIZE, &out );
        MD_CHECK_CC_RET( ret );
        typedValue->ValueUInt32 = (uint32_t)out.ValueUint64;
    }
    else if( strcmp( name, "MaxTimestamp" ) == 0 )
    {
        ret = m_driverInterface->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY, &out );
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

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbolUINT32

Description:
    Adds 32-bit uint32_t symbol to the symbol set.

Input:
    const char * name       - symbol name
    uint32_t     value      - symbol value
    TSymbolType symbolType  - symbol type

Output:
    TCompletionCode         - result of the operation

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbolUINT64

Description:
    Adds 64-bit uint64_t symbol to the symbol set.

Input:
    const char*  name       - symbol name
    uint64_t     value      - symbol value
    TSymbolType  symbolType - symbol type

Output:
    TCompletionCode         - result of the operation

\*****************************************************************************/
TCompletionCode CSymbolSet::AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType )
{
    TCompletionCode ret = CC_OK;
    TTypedValue_1_0 typedValue;
    typedValue.ValueType = VALUE_TYPE_UINT64;
    typedValue.ValueUInt64 = value;

    ret = AddSymbol( name, typedValue, symbolType );

    MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
    return ret;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbolBOOL

Description:
    Adds boolean symbol to the symbol set.

Input:
    const char * name       - symbol name
    bool value              - symbol value
    TSymbolType symbolType  - symbol type

Output:
    TCompletionCode         - result of the operation

\*****************************************************************************/
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

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbolFLOAT

Description:
    Adds float symbol to the symbol set.

Input:
    const char * name       - symbol name
    float value             - symbol value
    TSymbolType symbolType  - symbol type

Output:
    TCompletionCode         - result of the operation

\*****************************************************************************/
TCompletionCode CSymbolSet::AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType )
{
    TCompletionCode ret = CC_OK;
    TTypedValue_1_0 typedValue;
    typedValue.ValueType = VALUE_TYPE_FLOAT;
    typedValue.ValueFloat = value;

    ret = AddSymbol( name, typedValue, symbolType );

    MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
    return ret;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    AddSymbolCSTRING

Description:
    Adds cstring symbol to the symbol set.

Input:
    const char * name       - symbol name
    const char * value      - symbol value
    TSymbolType symbolType  - symbol type

Output:
    TCompletionCode         - result of the operation

\*****************************************************************************/
TCompletionCode CSymbolSet::AddSymbolCSTRING( const char* name, char * value, TSymbolType symbolType )
{
    TCompletionCode ret = CC_OK;
    TTypedValue_1_0 typedValue;
    typedValue.ValueType = VALUE_TYPE_CSTRING;
    typedValue.ValueCString = value;

    ret = AddSymbol( name, typedValue, symbolType );

    MD_CHECK_CC_MSG( ret, "Failed to add global symbol: %s, ret: %d", name, ret );
    return ret;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    IsPavpDisabled

Description:
    Checks if the PAVP_DISABLED bit in capabilities symbol is set.

Output:
    bool - result

\*****************************************************************************/
bool CSymbolSet::IsPavpDisabled( uint32_t capabilities )
{
    return (capabilities & GTDI_CAPABILITY_PAVP_DISABLED) > 0;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    WriteSymbolSetToFile

Description:
    Writes symbol set to a file.

Input:
    FILE* metricFile - handle to a metric file

Output:
    TCompletionCode  - result of operation

\*****************************************************************************/
TCompletionCode CSymbolSet::WriteSymbolSetToFile( FILE* metricFile )
{
    if( metricFile == NULL )
    {
        MD_ASSERT( metricFile != NULL );
        return CC_ERROR_INVALID_PARAMETER;
    }

    MD_CHECK_PTR_RET(m_symbolVector, CC_ERROR_GENERAL);

    TGlobalSymbol* symbol      = NULL;
    uint32_t       symbolCount = m_symbolVector->GetCount();
    fwrite( &symbolCount, sizeof( symbolCount ), 1, metricFile );
    for( uint32_t i = 0; i < symbolCount; i++ )
    {
        symbol = (*m_symbolVector)[i];
        // symbol_1_0
        WriteCStringToFile( symbol->symbol_1_0.SymbolName, metricFile );
        WriteTTypedValueToFile( &symbol->symbol_1_0.SymbolTypedValue, metricFile );
        fwrite( &symbol->symbolType, sizeof( symbol->symbolType ), 1, metricFile );
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    IsSymbolAlreadyAdded

Description:
    Checks if the symbol of the given name is already added to the symbol set.

Input:
    const char* symbolName  - symbolic name of a symbol to check

Output:
    bool                    - true when already added

\*****************************************************************************/
bool CSymbolSet::IsSymbolAlreadyAdded( const char* symbolName )
{
    return (GetSymbolValueByName( symbolName ) != NULL);
}

/*****************************************************************************\

Class:
    CSymbolSet

Method:
    RedetectSymbol

Description:
    Redetects (updates) the symbol value.

Input:
    const char * name - name of a symbol to redetect

Output:
    TCompletionCode - result, *CC_OK* means success

\*****************************************************************************/
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

}
