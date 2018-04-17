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

    File Name:  md_main_BXT.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/

#include "md_per_platform_preamble.h"




#if ((!defined(MD_INCLUDE_BXT_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_BXT_METRICS)
TCompletionCode CreateObjectTreeBXT_OA( CConcurrentGroup* aGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET(g_MetricsDevice, CC_ERROR_GENERAL);
    MD_CHECK_PTR_RET(aGroup, CC_ERROR_INVALID_PARAMETER);

    CMetricSet*       aSet         = NULL;
    CMetric*          aMetric      = NULL;
    CInformation*     aInformation = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask = 0;
  
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderBasic", "Render Metrics Basic Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which Sampler 0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which Sampler 1 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The percentage of time in which samplers have been processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Busy $$Sampler1Busy FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which Sampler 0 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which Sampler 1 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerL1Misses", "Sampler Cache Misses",
            "The total number of sampler cache misses in all LODs in all sampler units.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Lookups", "L3 Lookup Accesses w/o IC",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SamplerL1Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfThroughput", "GTI Fixed Pipe Throughput",
            "The total number of GPU memory bytes transferred between 3D Pipeline (Command Dispatch, Input Assembly and Stream Output) and GTI.",
            "GTI/3D Pipe", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiDepthThroughput", "GTI Depth Throughput",
            "The total number of GPU memory bytes transferred between depth caches and GTI.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccThroughput", "GTI RCC Throughput",
            "The total number of GPU memory bytes transferred between render color caches and GTI.",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8 dw@0xec UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x188 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHdcLookupsThroughput", "GTI HDC TLB Lookup Throughput",
            "The total number of GPU memory bytes transferred between GTI and HDC, when HDC is doing TLB lookups.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
            "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Bottleneck $$Sampler1Bottleneck FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        availabilityEquation = "$SkuRevisionId 0x03 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C00F0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12120280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12320280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11930317, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x159303DF, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x419000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A2D1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E0800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E5900, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4C4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4E2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F0010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A6C0053, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0FCC00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00101000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04101000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00114000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08114000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00120020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08120021, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00141000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08141000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02308000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04302000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06318000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08318000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06320800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08320840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00320000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06344000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08344000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D931831, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F939F3F, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01939E80, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x039303BC, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0593000E, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993002A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900177, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900187, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901110, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900423, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900111, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900C02, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59901111, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900821, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeBasic", "Compute Metrics Basic Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 8 UMUL $EuCoresTotalCount UDIV $EuThreadsCount UDIV 100 UMUL  $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesRead", "Typed Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesWritten", "Typed Bytes Written",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc dw@0xd0 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148 qw@0x150 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesRead", "Untyped Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesWritten", "Untyped Writes",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe8 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178 qw@0x180 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00778008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00088078, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00808708, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00a08908, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104F00E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124F1C00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x39900340, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900C00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A2D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E1400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E5100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0114, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004F6B42, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064F6200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084F4100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4F0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4F6C4C, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4F4B00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F8800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F08A2, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x182C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C1451, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19938A28, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19900177, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B900178, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900125, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900123, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderDX1x", "Render Metrics DX1x Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerL1Misses", "Sampler Cache Misses",
            "The total number of sampler cache misses in all LODs in all sampler units.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Lookups", "L3 Lookup Accesses w/o IC",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SamplerL1Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which Sampler 0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which Sampler 1 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The percentage of time in which samplers have been processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Busy $$Sampler1Busy FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which Sampler 0 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which Sampler 1 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
            "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Bottleneck $$Sampler1Bottleneck FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfThroughput", "GTI Fixed Pipe Throughput",
            "The total number of GPU memory bytes transferred between 3D Pipeline (Command Dispatch, Input Assembly and Stream Output) and GTI.",
            "GTI/3D Pipe", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiDepthThroughput", "GTI Depth Throughput",
            "The total number of GPU memory bytes transferred between depth caches and GTI.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccThroughput", "GTI RCC Throughput",
            "The total number of GPU memory bytes transferred between render color caches and GTI.",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8 dw@0xec UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x188 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHdcLookupsThroughput", "GTI HDC TLB Lookup Throughput",
            "The total number of GPU memory bytes transferred between GTI and HDC, when HDC is doing TLB lookups.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C00F0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12120280, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12320280, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11930317, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x159303DF, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900C00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x419000A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A2D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E5900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A6C0053, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0FCC00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00101000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04101000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00120020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08120021, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00141000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08141000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02308000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04302000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06318000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08318000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06320800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08320840, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06344000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08344000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D931831, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F939F3F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01939E80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x039303BC, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0593000E, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993002A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900177, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900187, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901110, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900423, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900C02, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59901111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900821, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderPipeProfile", "Render Metrics for 3D Pipeline Profile Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VfBottleneck", "VF Bottleneck",
            "The percentage of time in which vertex fetch pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsBottleneck", "VS Bottleneck",
            "The percentage of time in which vertex shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsBottleneck", "HS Bottleneck",
            "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsBottleneck", "DS Bottleneck",
            "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsBottleneck", "GS Bottleneck",
            "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoBottleneck", "SO Bottleneck",
            "The percentage of time in which stream output pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClBottleneck", "Clipper Bottleneck",
            "The percentage of time in which clipper pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfBottleneck", "Strip-Fans Bottleneck",
            "The percentage of time in which strip-fans pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 10, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthBottleneck", "Hi-Depth Bottleneck",
            "The percentage of time in which early hierarchical depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthBottleneck", "Early Depth Bottleneck",
            "The percentage of time in which early depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "BcBottleneck", "BC Bottleneck",
            "The percentage of time in which barycentric coordinates calculation pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Barycentric Calc", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_BC * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsStall", "HS Stall",
            "The percentage of time in which hull stall pipeline stage was stalled.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsStall", "DS Stall",
            "The percentage of time in which domain shader pipeline stage was stalled.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoStall", "SO Stall",
            "The percentage of time in which stream-output pipeline stage was stalled.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClStall", "CL Stall",
            "The percentage of time in which clipper pipeline stage was stalled.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfStall", "SF Stall",
            "The percentage of time in which strip-fans pipeline stage was stalled.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007ffea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00007ffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007affa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f5fd, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00079ffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000f3fb, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007bf7a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000f7e7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fefa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000f7cf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00077ffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000efdf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0006fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000cfbf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0003fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x00005f7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E001F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A2F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10186800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11810019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15810013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13820020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11830020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17840000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11860007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21860000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x178703E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022E5400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002E0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082F0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06143000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06174000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06180012, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00180000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D804000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F804000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05804000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09810200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B810030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03810003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21819140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23819050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25810018, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B820980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03820D80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11820000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0182C000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07828000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09824000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F828000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D830004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0583000C, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F831000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01848072, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11840000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07848000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09844000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F848000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07860000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09860092, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F860400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01869100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F870065, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01870000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19930800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B952000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D955055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F951455, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0992A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1192A800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1392028A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B92A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900C01, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900863, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900C22, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryReads", "Memory Reads Distribution Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryReads", "GtiCmdStreamerMemoryReads",
            "The total number of GTI memory reads from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRsMemoryReads", "GtiRsMemoryReads",
            "The total number of GTI memory reads from Resource Streamer.",
            "GTI/3D Pipe/Resource Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfMemoryReads", "GtiVfMemoryReads",
            "The total number of GTI memory reads from Vertex Fetch.",
            "GTI/3D Pipe/Vertex Fetch", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_VF * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryReads", "GtiRccMemoryReads",
            "The total number of GTI memory reads from Render Color Cache (Render Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryReads", "GtiMscMemoryReads",
            "The total number of GTI memory reads from Multisampling Color Cache (Multisampling Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHizMemoryReads", "GtiHizMemoryReads",
            "The total number of GTI memory reads from Hierarchical Depth Cache (Hi-Depth Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryReads", "GtiStcMemoryReads",
            "The total number of GTI memory reads from Stencil Cache (Stencil Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryReads", "GtiRczMemoryReads",
            "The total number of GTI memory reads from Render Depth Cache (Render Depth Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryReads", "GtiMemoryReads",
            "The total number of GTI memory reads.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank0Reads", "GtiL3Bank0Reads",
            "The total number of GTI memory reads from L3 Bank 0 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank1Reads", "GtiL3Bank1Reads",
            "The total number of GTI memory reads from L3 Bank 1 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank2Reads", "GtiL3Bank2Reads",
            "The total number of GTI memory reads from L3 Bank 2 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank3Reads", "GtiL3Bank3Reads",
            "The total number of GTI memory reads from L3 Bank 3 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Reads", "GtiL3Reads",
            "The total number of GTI memory reads from L3 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$GtiL3Bank0Reads $$GtiL3Bank1Reads $$GtiL3Bank2Reads $$GtiL3Bank3Reads UADD UADD UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRingAccesses", "GtiRingAccesses",
            "The total number of all accesses from GTI to the ring.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x272c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2728, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x271c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2718, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00006667, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x00006465, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f872, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19800343, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x39900340, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F901000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03803180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x058035E2, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0780006A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2181A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2381000A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D950550, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D92A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13900170, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21900171, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23900172, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25900173, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27900174, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29900175, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B900176, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D900177, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F90017F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900125, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900123, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900121, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47901080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryWrites", "Memory Writes Distribution Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryWrites", "GtiCmdStreamerMemoryWrites",
            "The total number of GTI memory writes from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiSoMemoryWrites", "GtiSoMemoryWrites",
            "The total number of GTI memory writes from Stream Output.",
            "GTI/3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SO * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryWrites", "GtiRccMemoryWrites",
            "The total number of GTI memory writes from Render Color Cache (Render Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryWrites", "GtiMscMemoryWrites",
            "The total number of GTI memory writes from Multisampling Color Cache (Multisampling Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHizMemoryWrites", "GtiHizMemoryWrites",
            "The total number of GTI memory writes from Hierarchical Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryWrites", "GtiStcMemoryWrites",
            "The total number of GTI memory writes from Stencil Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryWrites", "GtiRczMemoryWrites",
            "The total number of GTI memory writes from Render Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryWrites", "GtiMemoryWrites",
            "The total number of GTI memory writes.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank0Writes", "GtiL3Bank0Writes",
            "The total number of GTI memory writes from L3 Bank 0 (L3 Bank 0 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank1Writes", "GtiL3Bank1Writes",
            "The total number of GTI memory writes from L3 Bank 1 (L3 Bank 1 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank2Writes", "GtiL3Bank2Writes",
            "The total number of GTI memory writes from L3 Bank 2 (L3 Bank 2 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank3Writes", "GtiL3Bank3Writes",
            "The total number of GTI memory writes from L3 Bank 3 (L3 Bank 3 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Writes", "GtiL3Writes",
            "The total number of GTI memory writes from L3 (L3 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$GtiL3Bank0Writes $$GtiL3Bank1Writes $$GtiL3Bank2Writes $$GtiL3Bank3Writes UADD UADD UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRingAccesses", "GtiRingAccesses",
            "The total number of all GTI accesses to the ring.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x272c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2728, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x271c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2718, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00006667, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x00006465, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f822, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19800343, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x39900340, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03803180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x058035E2, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0780006A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2181A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2381000A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D950550, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D92A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13900180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21900181, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23900182, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25900183, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27900184, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29900185, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B900186, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D900187, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F900170, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900125, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900123, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900121, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47901080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtended", "Compute Metrics Extended Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 8 UMUL $EuCoresTotalCount UDIV $EuThreadsCount UDIV 100 UMUL $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedReads0", "EuUntypedReads0",
            "The subslice 0 EU Untyped Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedReads0", "EuTypedReads0",
            "The subslice 0 EU Typed Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedWrites0", "EuUntypedWrites0",
            "The subslice 0 EU Untyped Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedWrites0", "EuTypedWrites0",
            "The subslice 0 EU Typed Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedAtomics0", "EuUntypedAtomics0",
            "The subslice 0 EU Untyped Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedAtomics0", "EuTypedAtomics0",
            "The subslice 0 EU Typed Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuA64UntypedReads0", "EuA64UntypedReads0",
            "The subslice 0 EU A64 Untyped Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuA64UntypedWrites0", "EuA64UntypedWrites0",
            "The subslice 0 EU A64 Untyped Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReads0", "Typed Reads 0",
            "The subslice 0 typed reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWrites0", "Typed Writes 0",
            "The subslice 0 typed writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReads0", "Untyped Reads 0",
            "The subslice 0 untyped reads (including SLM reads).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWrites0", "Untyped Writes 0",
            "The subslice 0 untyped writes (including SLM writes).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomics0", "Typed Atomics 0",
            "The subslice 0 typed atomics.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReadsPerCacheLine", "TypedReadsPerCacheLine",
            "The ratio of EU typed read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedReads0 $$TypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWritesPerCacheLine", "TypedWritesPerCacheLine",
            "The ratio of EU typed write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedWrites0 $$TypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReadsPerCacheLine", "UntypedReadsPerCacheLine",
            "The ratio of EU untyped read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedReads0 $$EuA64UntypedReads0 UADD $$UntypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWritesPerCacheLine", "UntypedWritesPerCacheLine",
            "The ratio of EU untyped write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedWrites0 $$EuA64UntypedWrites0 UADD $$UntypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomicsPerCacheLine", "TypedAtomicsPerCacheLine",
            "The ratio of EU typed atomics requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedAtomics0 $$TypedAtomics0 FDIV" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00778008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00088078, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00808708, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00a08908, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007fc2a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007fc6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007fc92, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007fca2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fc32, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007fc9a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007fe6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007fe7a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104F00E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x141C0160, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x161C0015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x181C0120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E5515, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x144C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4F4B41, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004F4200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024F404C, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x001B4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x061B8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x081BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A1BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C1BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x041BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x001C0031, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x061C1900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x081C1A33, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A1C1B35, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C1C3337, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x041C31C7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0FA8AA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0AAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x182C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C6AAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C2950, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993AAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900001, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeL3Cache", "Compute Metrics L3 Cache Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuHybridFpu0Instruction", "EU FPU0 Hybrid Instruction",
            "The percentage of time in which execution units were actively processing hybrid instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuHybridFpu1Instruction", "EU FPU1 Hybrid Instruction",
            "The percentage of time in which execution units were actively processing hybrid instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x48:0xae" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTernaryFpu0Instruction", "EU FPU0 Ternary Instruction",
            "The percentage of time in which execution units were actively processing ternary instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTernaryFpu1Instruction", "EU FPU1 Ternary Instruction",
            "The percentage of time in which execution units were actively processing ternary instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuBinaryFpu0Instruction", "EU FPU0 Binary Instruction",
            "The percentage of time in which execution units were actively processing binary instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuBinaryFpu1Instruction", "EU FPU1 Binary Instruction",
            "The percentage of time in which execution units were actively processing binary instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuMoveFpu0Instruction", "EU FPU0 Move Instruction",
            "The percentage of time in which execution units were actively processing move instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x5c:0xb3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuMoveFpu1Instruction", "EU FPU1 Move Instruction",
            "The percentage of time in which execution units were actively processing move instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x60:0xb4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerAccesses", "Sampler Accesses",
            "The total number of messages send to samplers.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Accesses", "L3 Accesses",
            "The total number of L3 accesses from all entities.",
            "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 dw@0xc8 dw@0xcc UADD UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 qw@0x140 qw@0x148 UADD UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderLookups", "L3 Shader Lookup Accesses",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3TotalThroughput", "L3 Total Throughput",
            "The total number of GPU memory bytes transferred via L3.",
            "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Accesses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00Accesses", "L3 Bank 00 Accesses",
                "The total number of accesses to L3 Bank 00.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank01Accesses", "L3 Bank 01 Accesses",
                "The total number of accesses to L3 Bank 01.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank02Accesses", "L3 Bank 02 Accesses",
                "The total number of accesses to L3 Bank 02.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank03Accesses", "L3 Bank 03 Accesses",
                "The total number of accesses to L3 Bank 03.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00IcAccesses", "L3 Bank 00 IC Accesses",
                "The total number of accesses to L3 Bank 00 from IC cache.",
                "L3/IC", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_IC * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 UADD" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL $$L3Bank00Accesses UMIN" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00IcHits", "L3 Bank 00 IC Hits",
                "The total number of hits in L3 Bank 00 from IC cache.",
                "L3/IC", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_IC * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL $$L3Bank00IcAccesses UMIN" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00101100, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00201200, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00301300, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00401400, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fefe, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fefd, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fbef, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fbdf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C03B0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1593001E, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900C00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x082D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E1500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x144C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F4001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F5005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x006C0051, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x066C5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x086C5C5D, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E6C5E5F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x146C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A6C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0FA800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0A00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x182C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C4015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03931980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05930032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993A00A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900177, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900178, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900400, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "HDCAndSF", "Metric set HDCAndSF", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PolyDataReady", "Polygon Data Ready",
                "The percentage of time in which geometry pipeline output is ready",
                "GPU/3D Pipe/Strip-Fans", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonSamplerShader00AccessStalledOnL3", "HDC stalled by L3 (s0.ss0)",
                "Percentage of time when HDC has messges to L3, but it's stalled due to lack of credits (s0.ss0)",
                "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 USUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 USUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonSamplerShader01AccessStalledOnL3", "HDC stalled by L3 (s0.ss1)",
                "Percentage of time when HDC has messges to L3, but it's stalled due to lack of credits (s0.ss1)",
                "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 USUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 USUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fdff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104F0232, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124F4640, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11834400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024F6100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044F416B, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064F004B, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F02A8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C5500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F808000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25810020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F8305C0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F951000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13920200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "L3_1", "Metric set L3_1", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Stalled", "Slice0 L3 Bank0 Stalled",
                "The percentage of time in which slice0 L3 bank0 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Stalled", "Slice0 L3 Bank1 Stalled",
                "The percentage of time in which slice0 L3 bank1 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Active", "Slice0 L3 Bank1 Active",
                "The percentage of time in which slice0 L3 bank1 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Active", "Slice0 L3 Bank0 Active",
                "The percentage of time in which slice0 L3 bank0 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        availabilityEquation = "$SkuRevisionId 0x03 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100070, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff1, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00014002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000c3ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00010002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000c7ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00004002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000d3ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00100700, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ff1f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00001402, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fc3f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00001002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fc7f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00000402, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fd3f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12643400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x12653400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C6800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x126C001E, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C0010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0154, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0055, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x144C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F5500, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F1554, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A640024, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10640000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04640000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C650024, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10650000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06650000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C6C5327, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E6C5425, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x006C2A00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x026C285B, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x046C005C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A6C0900, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0AA0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F02AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C5550, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993AA00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900420, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900021, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x03 ULT";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100070, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff1, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00014002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000c3ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00010002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000c7ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00004002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000d3ff, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00100700, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ff1f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00001402, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fc3f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00001002, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fc7f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00000402, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fd3f, REGISTER_TYPE_OA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x14640340, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x14650340, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C6800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x126C001E, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C0010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0154, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0055, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x144C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044EA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4F5500, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4F1554, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04642400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x22640000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A640000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06650024, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x22650000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C650000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C6C5327, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E6C5425, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x006C2A00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x026C285B, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x046C005C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A6C0900, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0AA0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F02AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C2C5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C5550, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993AA00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900420, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900021, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RasterizerAndPixelBackend", "Metric set RasterizerAndPixelBackend", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PixelData0Ready", "Slice0 Post-EarlyZ Pixel Data Ready",
                "The percentage of time in which slice0 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
                "GPU/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0InputAvailable", "Slice0 Rasterizer Input Available",
                "The percentage of time in which slice0 rasterizer input is available",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSOutput0Available", "Slice0 PS Output Available",
                "The percentage of time in which slice0 PS output is available",
                "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PixelValues0Ready", "Slice0 Pixel Values Ready",
                "The percentage of time in which slice0 pixel values are ready",
                "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0OutputReady", "Slice0 Rasterizer Output Ready",
                "The percentage of time in which slice0 rasterizer output is ready",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000efff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00006000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102D7800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x122D79E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2F0004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x100E3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D0940, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D802F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D4013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022F0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x040E0480, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x000E0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x060F0027, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x100F0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x439014A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x459000A4, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "Sampler", "Metric set Sampler", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01InputAvailable", "Slice0 Subslice1 Input Available",
                "The percentage of time in which slice0 subslice1 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02InputAvailable", "Slice0 Subslice2 Input Available",
                "The percentage of time in which slice0 subslice2 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00InputAvailable", "Slice0 Subslice0 Input Available",
                "The percentage of time in which slice0 subslice0 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02OutputReady", "Slice0 Subslice2 Sampler Output Ready",
                "The percentage of time in which slice0 subslice2 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00OutputReady", "Slice0 Subslice0 Sampler Output Ready",
                "The percentage of time in which slice0 subslice0 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01OutputReady", "Slice0 Subslice1 Sampler Output Ready",
                "The percentage of time in which slice0 subslice1 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x70800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0000c000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000e7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00003000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f9ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000c00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x121300A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x141600AB, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x123300A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x143600AB, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x125300A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x145600AB, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E01A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0065, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F023F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2CC030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04132180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E142000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E150140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C150040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C163000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E160068, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10160000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x18160000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04330043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02330000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0234A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04342000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C350015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02363460, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10360000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04360000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06360000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08364000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06530043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02530000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E548000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00548000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06542000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E550400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A552000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C550100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E563000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00563400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10560000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x18560000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02560000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C564000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993A800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B9014A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900820, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45901022, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "TDL_1", "Metric set TDL_1", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread01ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice1",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread00ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice0",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread00ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice0",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread02ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice2",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread02ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice2",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread01ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice1",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00007fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x00009fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000efff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fdff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x141A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x143A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x145A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x102E0150, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E006A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x144C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x164C2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C0F0BC0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F0302, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E2C0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C00F0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x021A3080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x041A31E5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0414A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C150054, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C3A3280, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E3A0063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x063A0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x023A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C348000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E342000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06342000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E350140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C350100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x18360028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E5A3080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x005A3280, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x025A0063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E548000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00548000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02542000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E550400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A552000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C550001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x18560080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02568000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04568000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1993A800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4D900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45901084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900001, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "TDL_2", "Metric set TDL_2", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort0", "Thread Header Ready on Slice0 Subslice1 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort1", "Thread Header Ready on Slice0 Subslice0 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort0", "Thread Header Ready on Slice0 Subslice0 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort1", "Thread Header Ready on Slice0 Subslice2 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort0", "Thread Header Ready on Slice0 Subslice2 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort1", "Thread Header Ready on Slice0 Subslice1 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x141A026B, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x143A0173, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x145A026B, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002D4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042D5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x062D1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2E5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2E0069, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x044C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064CC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024EA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064E2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x180F6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A0F030A, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A2C03C0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x041A37E7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x021A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0414A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C150050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x08168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x003A3380, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x063A006F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x023A0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x00348000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06342000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A352000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C350100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x02368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x025A37E7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0254A000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C550005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x04568000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06568000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45901080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtra", "Compute Metrics Extra Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1ActiveAdjusted", "EU FPU1 Pipe Active including Ext Math",
            "The percentage of time in which EU FPU1 pipeline was actively processing including Extended Math processing",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD dw@0xf4 FADD 8 FMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD qw@0x198 FADD 8 FMUL" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Fpu1Active $Self FADD 100 FMUL $EuCoresTotalCount FDIV $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141a001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x143a001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x145a001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042d5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062d1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2e0094, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044ea000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a0f00e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2c0c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061a0063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06142000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c150100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x043a3180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x023a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04348000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c350040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045a0063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04542000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c550010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08568000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d938000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00001000, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00003002, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe65c, 0x00000008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "GpuBusyness", "Gpu Rings Busyness", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RenderBusy", "Render Ring Busy",
            "The percentage of time when render command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Vdbox0Busy", "Vdbox0 Ring Busy",
            "The percentage of time when Vdbox0 command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VeboxBusy", "Vebox Ring Busy",
            "The percentage of time when vebox command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "BlitterBusy", "Blitter Ring Busy",
            "The percentage of time when blitter command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AnyRingBusy", "AnyRingBusy",
            "The percentage of time when any command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13805800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05962c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19950016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21c05800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07800035, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23810008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07960025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d960000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f960000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b934000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09948000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05950085, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11950000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d950400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b924000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0bc000a5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900442, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00078000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00000fff, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_BXT;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "TestOa", "MDAPI testing set Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter0", "TestCounter0",
                "HW test counter 0. Factor: 0.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter1", "TestCounter1",
                "HW test counter 1. Factor: 1.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter2", "TestCounter2",
                "HW test counter 2. Factor: 1.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter3", "TestCounter3",
                "HW test counter 3. Factor: 0.5",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter4", "TestCounter4",
                "HW test counter 4. Factor: 0.333",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter5", "TestCounter5",
                "HW test counter 5. Factor: 0.333",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter6", "TestCounter6",
                "HW test counter 6. Factor: 0.166",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter7", "TestCounter7",
                "HW test counter 7. Factor: 0.666",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter8", "TestCounter8",
                "HW test counter 8. Should be equal to 1.",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07800063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23810008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d950400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f922000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000004, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000003, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000007, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fff7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00100082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000ffef, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x001000c2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00100001, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000ffe7, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    MD_LOG_EXIT();
    return CC_OK;

  exception:
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}
#endif
