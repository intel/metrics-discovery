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

    File Name:  md_main.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/
#include "metrics_discovery_api.h"
#include "md_exports.h"
#include "md_internal.h"
#include "md_per_platform_preamble.h"

// Global handle to MetricsDevice
CMetricsDevice* g_MetricsDevice = NULL;


#if (!defined(MD_INCLUDE_SKL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT2_METRICS
#define MD_CALL_SKL_GT2_METRICS 1
    TCompletionCode CreateObjectTreeSKL_GT2_OA(CConcurrentGroup* aGroup);
#endif

#if (!defined(MD_INCLUDE_SKL_GT3_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT3_METRICS
#define MD_CALL_SKL_GT3_METRICS 1
    TCompletionCode CreateObjectTreeSKL_GT3_OA(CConcurrentGroup* aGroup);
#endif

#if (!defined(MD_INCLUDE_SKL_GT4_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT4_METRICS
#define MD_CALL_SKL_GT4_METRICS 1
    TCompletionCode CreateObjectTreeSKL_GT4_OA(CConcurrentGroup* aGroup);
#endif

#if (!defined(MD_INCLUDE_BXT_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_BXT_METRICS
#define MD_CALL_BXT_METRICS 1
    TCompletionCode CreateObjectTreeBXT_OA(CConcurrentGroup* aGroup);
#endif

#if (!defined(MD_INCLUDE_KBL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_KBL_GT2_METRICS
#define MD_CALL_KBL_GT2_METRICS 1
    TCompletionCode CreateObjectTreeKBL_GT2_OA(CConcurrentGroup* aGroup);
#endif

#if (!defined(MD_INCLUDE_KBL_GT3_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_KBL_GT3_METRICS
#define MD_CALL_KBL_GT3_METRICS 1
    TCompletionCode CreateObjectTreeKBL_GT3_OA(CConcurrentGroup* aGroup);
#endif

uint32_t        g_mdRefCounter       = 0;
void*           g_OpenCloseSemaphore = NULL;

TCompletionCode AddGlobalSymbols( CSymbolSet* globalSymbolSet )
{
    MD_CHECK_PTR_RET( globalSymbolSet, CC_ERROR_INVALID_PARAMETER );
    
    globalSymbolSet->AddSymbolUINT32( "EuCoresTotalCount", 60, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EuCoresPerSubsliceCount", 10, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EuSubslicesTotalCount", 6, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EuSubslicesPerSliceCount", 3, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EuSlicesTotalCount", 2, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EuThreadsCount", 8, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "SubsliceMask", 0x1FF, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "SliceMask", 0x7, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "SamplersTotalCount", 6, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "MemoryPeakThroghputMB", 25600, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "MemoryFrequencyMHz", 1600, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "GpuMinFrequencyMHz", 650, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "GpuMaxFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "GpuCurrentFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "PciDeviceId", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "SkuRevisionId", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "PlatformIndex", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "ApertureSize", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "Capabilities", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolBOOL( "PavpDisabled", false, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "NumberOfRenderOutputUnits", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "NumberOfShadingUnits", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "OABufferMinSize", 16384, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "OABufferMaxSize", 131072, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "GpuTimestampFrequency", 12500000, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "EdramSize", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "LLCSize", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT32( "L3Size", 0, SYMBOL_TYPE_DETECT );
  
    globalSymbolSet->AddSymbolUINT64( "MaxTimestamp", 0, SYMBOL_TYPE_DETECT );
  
    return CC_OK;
}

TCompletionCode CreateObjectTree( IMetricsDevice_1_5** metricsDevice )
{
    MD_LOG_ENTER();
    CConcurrentGroup* aGroup       = NULL;
    CMetricSet*       aSet         = NULL;
    CMetric*          aMetric      = NULL;
    CInformation*     aInformation = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask = 0;

    aInformation = NULL; // To omit warning C4189 - local variable is initialized but not referenced

    g_MetricsDevice = new (std::nothrow) CMetricsDevice();
    MD_CHECK_PTR_RET( g_MetricsDevice, CC_ERROR_NO_MEMORY );

    CSymbolSet* symbolSet = g_MetricsDevice->GetSymbolSet();
    MD_CHECK_PTR( symbolSet );
    AddGlobalSymbols( symbolSet );
    g_MetricsDevice->GetParams()->GlobalSymbolsCount = symbolSet->GetSymbolCount();
  
    aGroup = g_MetricsDevice->AddConcurrentGroup( "OcclusionQueryStats", "Occlusion Query Statistics", MEASUREMENT_TYPE_DELTA_QUERY );
    MD_CHECK_PTR( aGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_KBL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderedPixelsStats", "Rendered Pixels Statistics", API_TYPE_OGL4_X,
           GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 9, 0, 0, 0, 0,
            "", 1, "", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsRendered", "Depth passed pixels",
            "The total number of pixels that passed depth test. Note: not all rendered pixels are necessarily written to render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_KBL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderedFragmentsStats", "Rendered Fragments Statistics", API_TYPE_OGL|API_TYPE_OGL4_X,
           GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 0, 0, 0, 0, 0,
            "", 0, "", 0x8C2F) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsRendered", "Depth passed fragments",
            "The total number of fragments that passed depth test. Note: not all rendered fragments are necessarily written to render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "fragments", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    aGroup = g_MetricsDevice->AddConcurrentGroup( "TimestampQuery", "Timestamp Query", MEASUREMENT_TYPE_SNAPSHOT_QUERY );
    MD_CHECK_PTR( aGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_KBL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "GPUTimestamp", "GPU Timestamp", API_TYPE_OGL4_X,
           GPU_GENERIC, 8, 0, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 10, 0, 0, 0, 0,
            "", 2, "", 0x88BF) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuDuration", "GPU Duration",
            "Total GPU duration for selected work items.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 64" ));
        }

        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    aGroup = g_MetricsDevice->AddConcurrentGroup( "PipelineStatistics", "Pipeline Statistics", MEASUREMENT_TYPE_DELTA_QUERY );
    MD_CHECK_PTR( aGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_KBL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL|API_TYPE_OGL4_X,
           GPU_RENDER|GPU_COMPUTE, 0, 88, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 0, 0, 0x80000206, 0, 0,
            "", 0, "Intel_Raw_Pipeline_Statistics_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "IAVertices", "Input vertices",
            "The total number of vertices that entered the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "vertices", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "IAPrimitives", "Input primitives",
            "The total number of rendering primitives assembled and put into the input assembly stage of the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsInvocations", "VS per vertex invocations",
            "The total number of times a vertex shader was invoked. 3D rendering invokes the vertex shader once per vertex.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsInvocations", "HS invocations",
            "The total number of times a hull shader was invoked.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsInvocations", "DS invocations",
            "The total number of times a domain shader was invoked.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsInvocations", "GS per triangle invocations",
            "The total number of times a geometry shader was invoked per triangle.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsPrimitives", "Post-GS primitives",
            "The total number of primitives that flowed through from GS to the clipper if GS was enabled.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClipperInvocations", "Clipper invocations",
            "The total number of primitives sent to the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClipperPrimitives", "Clipper primitives",
            "The total number of primitives that flowed out of the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsInvocations", "PS invocations",
            "The total number of times a pixel shader was invoked. 3D rendering invokes a pixel shader once per pixel or subsample.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsInvocations", "CS invocations",
            "The total number of times a compute shader was invoked.",
            "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
        }

        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    aGroup = g_MetricsDevice->AddConcurrentGroup( "OA", "OA Unit Metrics", MEASUREMENT_TYPE_DELTA_QUERY|MEASUREMENT_TYPE_SNAPSHOT_IO );
    MD_CHECK_PTR( aGroup );
    
    // Add platform specific metric sets
#if MD_CALL_SKL_GT2_METRICS
    MD_CHECK_CC( CreateObjectTreeSKL_GT2_OA(aGroup) );
#endif
  
#if MD_CALL_SKL_GT3_METRICS
    MD_CHECK_CC( CreateObjectTreeSKL_GT3_OA(aGroup) );
#endif
  
#if MD_CALL_SKL_GT4_METRICS
    MD_CHECK_CC( CreateObjectTreeSKL_GT4_OA(aGroup) );
#endif
  
#if MD_CALL_BXT_METRICS
    MD_CHECK_CC( CreateObjectTreeBXT_OA(aGroup) );
#endif
  
#if MD_CALL_KBL_GT2_METRICS
    MD_CHECK_CC( CreateObjectTreeKBL_GT2_OA(aGroup) );
#endif
  
#if MD_CALL_KBL_GT3_METRICS
    MD_CHECK_CC( CreateObjectTreeKBL_GT3_OA(aGroup) );
#endif
  

    MD_CHECK_CC( g_MetricsDevice->AddOverrides() );

    *metricsDevice  = g_MetricsDevice;

    MD_LOG_EXIT();
    return CC_OK;

  exception:
    MD_SAFE_DELETE( g_MetricsDevice );
    MD_LOG(LOG_ERROR, "creating tree failed");
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}

TCompletionCode CreateObjectTreeFromFile( const char* fileName, IMetricsDevice_1_5** metricsDevice )
{
    TCompletionCode retVal = CC_OK;

    MD_CHECK_PTR_RET( g_MetricsDevice, CC_ERROR_GENERAL );

    retVal = g_MetricsDevice->OpenFromFile( fileName, MD_IS_INTERNAL_BUILD );
    if( retVal == CC_OK )
    {
        *metricsDevice = g_MetricsDevice;
    }
    else
    {
        if( !g_mdRefCounter )
        {
            MD_SAFE_DELETE( g_MetricsDevice );
        }
        *metricsDevice = NULL;
    }

    return retVal;
}

TCompletionCode SaveObjectTreeToFile( const char* fileName, IMetricsDevice_1_5* metricsDevice )
{
    TCompletionCode retVal = CC_OK;

    g_MetricsDevice = static_cast<CMetricsDevice*>(metricsDevice);
    if( g_MetricsDevice == NULL ) return CC_ERROR_INVALID_PARAMETER;

    retVal = g_MetricsDevice->SaveToFile(fileName);

    return retVal;
}

#ifdef __cplusplus
    extern "C" {
#endif

TCompletionCode OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice )
{
    MD_LOG_ENTER();
    TCompletionCode retVal = CC_OK;

    if( metricsDevice == NULL )
    {
        MD_LOG(LOG_DEBUG, "NULL metrics device");
        MD_LOG_EXIT();
        return CC_ERROR_INVALID_PARAMETER;
    }

    // Init driver interface if needed
    CDriverInterface *pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_INFO, "driver support enabling...");
        retVal = pDriverInterface->SendSupportEnableEscape(true);
        if( retVal != CC_OK )
        {
            MD_LOG(LOG_ERROR, "driver support enabling failed");
            MD_LOG_EXIT();
            return retVal;
        }
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( g_MetricsDevice != NULL )
    {
        *metricsDevice  = g_MetricsDevice;
        retVal          = CC_ALREADY_INITIALIZED;
        g_mdRefCounter++;
    }
    else
    {
        retVal = CreateObjectTree( metricsDevice );
        if( retVal == CC_OK )
        {
            g_mdRefCounter++;
        }
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice )
{
    MD_LOG_ENTER();
    TCompletionCode   retVal           = CC_OK;
    CDriverInterface* pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( static_cast<CMetricsDevice*>(metricsDevice) != g_MetricsDevice )
    {
        MD_LOG(LOG_ERROR, "pointers mismatch");
        retVal = CC_ERROR_GENERAL;
    }

    if( retVal == CC_OK )
    {
        if( g_mdRefCounter > 1 )
        {
            g_mdRefCounter--;
            retVal = CC_STILL_INITIALIZED;
        }
        else if( g_mdRefCounter == 1 )
        {
            MD_SAFE_DELETE(g_MetricsDevice);
            g_mdRefCounter = 0;
            retVal         = CC_OK;
        }
        else
        {
            retVal = CC_ERROR_GENERAL;
        }
    }

    // disable instrumentation support if needed
    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_INFO, "driver support disabling...");
        pDriverInterface->SendSupportEnableEscape(false);
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( !g_mdRefCounter )
    {
        DestroyDriverIfc();
    }

    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** device )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( device, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode retVal = CC_OK;

    // Init driver interface if needed
    CDriverInterface *pDriverInterface = GetDriverIfc();
    if( !pDriverInterface )
    {
        MD_LOG(LOG_ERROR, "failed to get driver interface");
        MD_LOG_EXIT();
        return CC_ERROR_NOT_SUPPORTED;
    }

    if( pDriverInterface->GetNeedSupportEnable() )
    {
        MD_LOG(LOG_DEBUG, "enabling driver support");
        retVal = pDriverInterface->SendSupportEnableEscape(true);
        if( retVal != CC_OK )
        {
            MD_LOG(LOG_ERROR, "driver support enabling failed");
            MD_LOG_EXIT();
            return retVal;
        }
    }

    retVal = GetOpenCloseSemaphore( &g_OpenCloseSemaphore );
    if( retVal != CC_OK )
    {
        MD_LOG(LOG_ERROR, "get semaphore failed");
        MD_LOG_EXIT();
        return retVal;
    }

    if( g_MetricsDevice == NULL )
    {
        g_MetricsDevice = new (std::nothrow) CMetricsDevice();
        if( g_MetricsDevice == NULL )
        {
            retVal = CC_ERROR_NO_MEMORY;
        }
        else
        {
            retVal = CreateObjectTree( device );
        }
    }

    if( retVal == CC_OK )
    {
        if( g_MetricsDevice->IsOpenedFromFile() )
        {
            *device = g_MetricsDevice;
            retVal  = CC_ALREADY_INITIALIZED;
            g_mdRefCounter++;
        }
        else
        {
            retVal = CreateObjectTreeFromFile( fileName, device );
            if( retVal == CC_OK )
            {
                g_mdRefCounter++;
            }
        }
    }

    ReleaseOpenCloseSemaphore( &g_OpenCloseSemaphore );
    MD_LOG_EXIT();
    return retVal;
}

TCompletionCode SaveMetricsDeviceToFile(const char* fileName, void* saveParams, IMetricsDevice_1_5* device)
{
    MD_LOG_ENTER();
    TCompletionCode retVal = CC_OK;
    retVal = SaveObjectTreeToFile(fileName, device);

    MD_LOG_EXIT();
    return retVal;
}

#ifdef __cplusplus
    }
#endif
  