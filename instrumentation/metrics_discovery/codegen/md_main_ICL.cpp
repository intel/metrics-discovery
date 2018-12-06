/*****************************************************************************\

    Copyright © 2019, Intel Corporation

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

    File Name:  md_main_ICL.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/

#include "md_per_platform_preamble.h"




#if ((!defined(MD_INCLUDE_ICL_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_ICL_METRICS)
TCompletionCode CreateObjectTreeICL_OA( CConcurrentGroup* aGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET(g_MetricsDevice, CC_ERROR_GENERAL);
    MD_CHECK_PTR_RET(aGroup, CC_ERROR_INVALID_PARAMETER);

    CMetricSet*       aSet         = NULL;
    CMetric*          aMetric      = NULL;
    CInformation*     aInformation = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask = 0;
  
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderBasic", "Render Metrics Basic Gen11", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00Busy", "Sampler00 Busy",
                "The percentage of time in which Slice0 Sampler0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 9 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
                "The percentage of time in which samplers have been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_UINT64, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler00Busy" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00Bottleneck", "Sampler00 Bottleneck",
                "The percentage of time in which Slice0 Sampler0 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4 dw@0xcc UADD dw@0xd0 UADD dw@0xd4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138 qw@0x148 UADD qw@0x150 UADD qw@0x158 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "64 $Self UMUL" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc8 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x140 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "64 $Self UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = "$SubsliceMask 9 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
                "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_UINT64, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler00Bottleneck" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142c0014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14120700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121500e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1e000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c200014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16212800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2c2041, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24061800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04120023, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06131000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02150980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1815000f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e18a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14190028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c01c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a5c01c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001c0097, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061c9400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1c00a7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081d8100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1d0004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x085c9497, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a5ca700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x105c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a5d000b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e1eef80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f2404, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f0092, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0303, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0303, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f4001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00000052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeBasic", "Compute Metrics Basic Gen10", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9 rd40@0x38:0xaa rd40@0x3c:0xab FADD rd40@0x34:0xa9 FSUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58 qw@0x60 qw@0x68 FADD qw@0x58 FSUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x44:0xad FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x78 FMUL $EuThreadsCount FDIV" ));
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesWritten", "Typed Bytes Written",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesRead", "Untyped Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesWritten", "Untyped Writes",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe0 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178 qw@0x170 UADD $EuSubslicesTotalCount UMUL 32 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomics", "Typed Atomics Accesses",
            "The total number of typed atomic accesses via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_FLOAT, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 dw@0xd4 FADD 2 FDIV $EuSubslicesTotalCount FMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150 qw@0x158 FADD 2 FDIV $EuSubslicesTotalCount FMUL" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4 dw@0xcc UADD dw@0xdc UADD dw@0xd8 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138 qw@0x148 UADD qw@0x168 UADD qw@0x160 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "64 $Self UMUL" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc8 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x140 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "64 $Self UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12230012, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10230019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12a30012, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10a30019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a200400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c200020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a230031, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e231e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0223003d, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04230032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06230033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00230000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aa01000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ca00008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aa08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aa31880, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ea3003c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00a31e80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a31900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a31980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e044055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040141, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600cc, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24067e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18123000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a12000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0212c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0612c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a12c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a134000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06132000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16150380, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1815000d, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0415c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0815c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12190400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14190020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1c2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121d1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141d0008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c01c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a5c01c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001c0097, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061c9400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1ca700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081d8100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1d0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x085c9497, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c5c00a7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x105c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a5d0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e1e0f80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x201e000b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f2524, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f2522, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2430, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0303, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f3003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00000008, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtended", "ComputeExtended Gen11", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedAtomics00", "Typed Atomics 00",
                "Slice 0 Subslice group 0 typed atomics.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedReads00", "Typed Reads 00",
                "Slice 0 Subslice group 0 typed reads.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedWrites00", "Typed Writes 00",
                "Slice 0 Subslice group 0 typed writes.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "UntypedReads00", "Untyped Reads 00",
                "Slice 0 Subslice group 0 untyped reads (including SLM reads).",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "UntypedWrites00", "Untyped Writes 00",
                "Slice 0 Subslice group 0 untyped writes (including SLM writes).",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuTypedReads00", "Eu Typed Reads 00",
                "Slice0 Subslice group 0 Eu Typed Reads",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuTypedWrites00", "Eu Typed Writes 00",
                "Slice0 Subslice group 0 Eu Typed Writes",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuTypedAtomics00", "Eu Typed Atomics 00",
                "Slice0 Subslice group 0 Eu Typed Atomics",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuA32UntypedReads00", "Eu A32 Untyped Reads 00",
                "Slice0 Subslice group 0 Eu A32 Untyped Reads",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuA32UntypedWrites00", "Eu A32 Untyped Writes 00",
                "Slice0 Subslice group 0 Eu A32 Untyped Writes",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xc4 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168 qw@0x138 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuA64UntypedReads00", "Eu 64 Untyped Reads 00",
                "Slice0 Subslice group 0 Eu 64 Untyped Reads",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_FLOAT, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4 dw@0xe4 FADD dw@0xd8 FADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158 qw@0x178 FADD qw@0x160 FADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "EuA64UntypedWrites00", "Eu A64 Untyped Writes 00",
                "Slice0 Subslice group 0 Eu A64 Untyped Writes",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedAtomicsPerCacheLine", "TypedAtomicsPerCacheLine",
                "The ratio of EU typed atomics requests to L3 cache line writes.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedAtomics00 $$TypedAtomics00 FDIV" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedReadsPerCacheLine", "TypedReadsPerCacheLine",
                "The ratio of EU typed read requests to L3 cache line reads.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedReads00 $$TypedReads00 FDIV" ));
            }
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "TypedWritesPerCacheLine", "TypedWritesPerCacheLine",
                "The ratio of EU typed write requests to L3 cache line writes.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedWrites00 $$TypedWrites00 FDIV" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReadsPerCacheLine", "UntypedReadsPerCacheLine",
            "The ratio of EU untyped read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xd4 dw@0xe4 FADD dw@0xd8 FADD FADD dw@0xf0 FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x158 qw@0x178 FADD qw@0x160 FADD FADD qw@0x190 FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "UntypedWritesPerCacheLine", "UntypedWritesPerCacheLine",
                "The ratio of EU untyped write requests to L3 cache line writes.",
                "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xc4 FADD dw@0xe8 FADD dw@0xec FDIV" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168 qw@0x138 FADD qw@0x180 FADD qw@0x188 FDIV" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1222000b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16220009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12230019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10230012, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1ef800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1e0007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1ff800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1f0007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a202aa0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c200005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c208000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00214000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e214000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14214000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16210555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00220011, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06220900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08220a13, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a220b15, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c222317, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e220043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02231ab4, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04231dba, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06230039, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00230000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c044400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2406fd00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2606007f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0015c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16157ff8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0415c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0615c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0815c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0618a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0818a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a18a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c18a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0218a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0418a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e19a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12195540, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1419000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a19a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c19a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16136860, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24000004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20000040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e132980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00132d80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2413, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f3013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x30000036, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x01fffe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x31000034, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x01fffe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000c9a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00000c92, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00000ca2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00000e42, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00000e6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00000c32, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x87643210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00001811, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x87654310, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeL3Cache", "Compute Metrics L3 Cache Gen11", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9 rd40@0x38:0xaa rd40@0x3c:0xab FADD rd40@0x34:0xa9 FSUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58 qw@0x60 qw@0x68 FADD qw@0x58 FSUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerAccesses 4 UMUL" ));
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00Accesses", "Slice0 L3 Bank0 Accesses",
                "The total number of accesses to Slice0 L3 Bank0.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank01Accesses", "Slice0 L3 Bank1 Accesses",
                "The total number of accesses to Slice0 L3 Bank1.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank02Accesses", "Slice0 L3 Bank2 Accesses",
                "The total number of accesses to Slice0 L3 Bank2.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank03Accesses", "Slice0 L3 Bank3 Accesses",
                "The total number of accesses to Slice0 L3 Bank3.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank04Accesses", "Slice0 L3 Bank4 Accesses",
                "The total number of accesses to Slice0 L3 Bank4.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank05Accesses", "Slice0 L3 Bank5 Accesses",
                "The total number of accesses to Slice0 L3 Bank5.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank06Accesses", "Slice0 L3 Bank6 Accesses",
                "The total number of accesses to Slice0 L3 Bank6.",
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank07Accesses", "Slice0 L3 Bank7 Accesses",
                "The total number of accesses to Slice0 L3 Bank7.",
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Accesses", "L3 Accesses",
            "The total number of L3 accesses from all entities.",
            "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Bank00Accesses $$L3Bank01Accesses UADD $$L3Bank02Accesses UADD $$L3Bank03Accesses UADD $$L3Bank04Accesses UADD $$L3Bank05Accesses UADD $$L3Bank06Accesses UADD $$L3Bank07Accesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Lookups", "L3 Lookup Accesses w/o IC",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xd8 UADD 8 UMUL dw@0x90 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168 qw@0x160 UADD 8 UMUL qw@0x110 UADD" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "2 dw@0xd4 dw@0xd0 UADD UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "2 qw@0x158 qw@0x150 UADD UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xd8 UADD 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168 qw@0x160 UADD 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "64 $Self UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14120700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121500e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040154, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600f0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24067e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c120023, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e12152b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00121480, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02120028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13d000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04136000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c150980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154d80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154c9a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06150018, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16150800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1473a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1217241c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22000550, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18137c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a130001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061434a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00140000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081710b0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10170000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f1124, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4849, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f3100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f3131, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0031, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00101100, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00201200, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00301300, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe65c, 0x00401400, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderPipeProfile", "Render Metrics for 3D Pipeline Profile Gen10", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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
        aMetric = aSet->AddMetric( "VfBottleneck", "VF Bottleneck",
            "The percentage of time in which vertex fetch pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsBottleneck", "VS Bottleneck",
            "The percentage of time in which vertex shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsBottleneck", "HS Bottleneck",
            "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsBottleneck", "DS Bottleneck",
            "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsBottleneck", "GS Bottleneck",
            "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoBottleneck", "SO Bottleneck",
            "The percentage of time in which stream output pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClBottleneck", "Clipper Bottleneck",
            "The percentage of time in which clipper pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfBottleneck", "Strip-Fans Bottleneck",
            "The percentage of time in which strip-fans pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 10, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthBottleneck", "Hi-Depth Bottleneck",
            "The percentage of time in which early hierarchical depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthBottleneck", "Early Depth Bottleneck",
            "The percentage of time in which early depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "BcBottleneck", "BC Bottleneck",
            "The percentage of time in which barycentric coordinates calculation pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Barycentric Calc", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_BC * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsStall", "HS Stall",
            "The percentage of time in which hull stall pipeline stage was stalled.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsStall", "DS Stall",
            "The percentage of time in which domain shader pipeline stage was stalled.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoStall", "SO Stall",
            "The percentage of time in which stream-output pipeline stage was stalled.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClStall", "CL Stall",
            "The percentage of time in which clipper pipeline stage was stalled.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfStall", "SF Stall",
            "The percentage of time in which strip-fans pipeline stage was stalled.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001f001e, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10160000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1017001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1f0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a200800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x26060038, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16157e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c160022, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08160000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c170540, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04170000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c181000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12195000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14190001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100b7c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100f0019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10107c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x120703c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10090000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06010080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e014180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060b0015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080b8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0b2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020ba000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040ba000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0e0a02, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0ea800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020f0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x180f0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a100017, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04107113, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18100020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08110c40, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02110c80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00024000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06028000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e02c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00039000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06036000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0803a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a032000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e035000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0203a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0403a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00044000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e044000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c068000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00070032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e070033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04070000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08098011, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00090980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18090a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02090000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04098000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06098000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a098000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c098000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f36db, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f491b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f001b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f1b41, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f2100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f4141, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f1160, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f2120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f0141, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f1160, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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
        aMetric = aSet->AddMetric( "NonSamplerShader00AccessStalledOnL3", "Slice0 Subslice group 0 Non-sampler Shader Access Stalled On L3",
            "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Subslice group 0)",
            "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xdc FSUB" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x168 FSUB" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "NonSamplerShader01AccessStalledOnL3", "Slice0 Subslice group 1 Non-sampler Shader Access Stalled On L3",
            "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Subslice group 1)",
            "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8 dw@0xe4 FSUB" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x178 FSUB" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "NonSamplerShader02AccessStalledOnL3", "Slice0 Subslice group 2 Non-sampler Shader Access Stalled On L3",
            "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Subslice group 2)",
            "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xec FSUB" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x188 FSUB" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "NonSamplerShader03AccessStalledOnL3", "Slice0 Subslice group 3 Non-sampler Shader Access Stalled On L3",
            "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Subslice group 3)",
            "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8 dw@0xf4 FSUB" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x198 FSUB" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1223000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10230009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1263000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10630009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12a3000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10a30009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12e3000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10e30009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10150019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c20000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c231900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e23003c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00230000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c600020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02608000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e631900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00631e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a31e32, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00a30000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae08000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04e31e32, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00e30000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040150, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050054, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24063f00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14090040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080e5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a120020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0412c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0612c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0214c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00150047, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16156000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1419000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1f3061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3330, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0InputAvailable", "Slice0 Rasterizer Input Available",
                "The percentage of time in which slice0 rasterizer input is available",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0OutputReady", "Slice0 Rasterizer Output Ready",
                "The percentage of time in which slice0 rasterizer output is ready",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelData00Ready", "Slice0 Pipe0 Post-EarlyZ Pixel Data Ready",
            "The percentage of time in which slice0  pipe0 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
            "GPU/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelData01Ready", "Slice0 Pipe1 Post-EarlyZ Pixel Data Ready",
            "The percentage of time in which slice0  pipe1 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
            "GPU/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PSOutput00Available", "Slice0 Pipe0 PS Output Available",
            "The percentage of time in which slice0 pipe0 PS output is available",
            "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PSOutput01Available", "Slice0 Pipe1 PS Output Available",
            "The percentage of time in which slice0 pipe1 PS output is available",
            "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelValues00Ready", "Slice0 Pipe0 Pixel Values Ready",
            "The percentage of time in which slice0 pipe0 pixel values are ready",
            "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelValues01Ready", "Slice0 Pipe1 Pixel Values Ready",
            "The percentage of time in which slice0 pipe1 pixel values are ready",
            "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x140a001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040c5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x140f001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04115017, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10136000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1213001c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16140000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10160018, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101a0018, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045545, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2406df00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x26060007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00084000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02084000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000a3080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x160a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020c05c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020d1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040d1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020f0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x160f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18120c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0613092f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08134025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148066, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10140000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0614c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161500e8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08161000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08184000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12190100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1a0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1c1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121d0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1f0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4904, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f5050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f1040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f4010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f5033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x70800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000038, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fff7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ffef, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Active", "Slice0 L3 Bank0 Active",
                "The percentage of time in which slice0 L3 bank0 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Active", "Slice0 L3 Bank1 Active",
                "The percentage of time in which slice0 L3 bank1 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank2Active", "Slice0 L3 Bank2 Active",
                "The percentage of time in which slice0 L3 bank2 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank3Active", "Slice0 L3 Bank3 Active",
                "The percentage of time in which slice0 L3 bank3 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank4Active", "Slice0 L3 Bank4 Active",
                "The percentage of time in which slice0 L3 bank4 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank5Active", "Slice0 L3 Bank5 Active",
                "The percentage of time in which slice0 L3 bank5 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank6Active", "Slice0 L3 Bank6 Active",
                "The percentage of time in which slice0 L3 bank6 is active",
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

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank7Active", "Slice0 L3 Bank7 Active",
                "The percentage of time in which slice0 L3 bank7 is active",
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17740000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17b40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17f40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16740000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16b40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16f40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07340037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09740037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21740000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0bb40037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21b40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0df40037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21f40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0000a7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08012000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c038000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c340037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e740037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20740000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02b40037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20b40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04f40037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20f40000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050070, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06056000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24067e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02074000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04078000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06137000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0414c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2a1f0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2460, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f0124, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0133, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f6060, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "L3_2", "Gen11 L2Bank0 stalled metric set", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x38:0xaa FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x60 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Stalled", "Slice0 L3 Bank0 Stalled",
                "The percentage of time in which slice0 L3 bank0 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 FADD dw@0xc8 FADD dw@0xcc FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 FADD qw@0x140 FADD qw@0x148 FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10050c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12050002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00050025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06050900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080508ea, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0508ab, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c050a21, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e050a60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24068100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000022, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ff1f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00001002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00008003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00000053, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "L3_3", "Gen11 L2Bank1 stalled metric set", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x38:0xaa FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x60 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Stalled", "Slice0 L3 Bank1 Stalled",
                "The percentage of time in which slice0 L3 bank1 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 FADD dw@0xc8 FADD dw@0xcc FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 FADD qw@0x140 FADD qw@0x148 FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10050400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00050025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06050900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080508ea, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0508ab, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c050a21, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e050a60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24068100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000022, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ff1f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00001002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00008003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00000053, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "L3_4", "Gen11 L2Bank4 stalled metric set", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x38:0xaa FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x60 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank4Stalled", "Slice0 L3 Bank4 Stalled",
                "The percentage of time in which slice0 L3 bank4 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 FADD dw@0xc8 FADD dw@0xcc FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 FADD qw@0x140 FADD qw@0x148 FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10010c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12010002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c000400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e005500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10000155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00010025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06010900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080108ea, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0108ab, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c010a21, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e010a60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c040400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24068100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18125540, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a120015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04131000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0814c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16152aa8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000022, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ff1f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00001002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00008003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00000053, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "L3_5", "Gen11 L2Bank5 stalled metric set", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x38:0xaa FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x60 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank5Stalled", "Slice0 L3 Bank5 Stalled",
                "The percentage of time in which slice0 L3 bank5 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8 dw@0xcc FADD dw@0xc0 FADD dw@0xc4 FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140 qw@0x148 FADD qw@0x130 FADD qw@0x138 FADD 4 FDIV" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10010400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c000400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e005500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10000155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00010022, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06010840, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08010828, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a010969, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c010aa4, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e010ae3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14010000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c040400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24068100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18125540, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a120015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04131000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0814c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16152aa8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000022, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ff1f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00001002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00008003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00000053, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "Sampler_1", "Metric set Sampler 1", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00InputAvailable", "Slice0 Subslice0 Input Available",
                "The percentage of time in which slice0 subslice0 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01InputAvailable", "Slice0 Subslice1 Input Available",
                "The percentage of time in which slice0 subslice1 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02InputAvailable", "Slice0 Subslice2 Input Available",
                "The percentage of time in which slice0 subslice2 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler03InputAvailable", "Slice0 Subslice3 Input Available",
                "The percentage of time in which slice0 subslice3 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler04InputAvailable", "Slice0 Subslice4 Input Available",
                "The percentage of time in which slice0 subslice4 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler05InputAvailable", "Slice0 Subslice5 Input Available",
                "The percentage of time in which slice0 subslice5 sampler input is available",
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

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler06InputAvailable", "Slice0 Subslice6 Input Available",
                "The percentage of time in which slice0 subslice6 sampler input is available",
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

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler07InputAvailable", "Slice0 Subslice7 Input Available",
                "The percentage of time in which slice0 subslice7 sampler input is available",
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142a0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142f0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146a0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146f0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14aa0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14af0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ea0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ef0165, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181ec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1e0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1f0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042a1800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062ac038, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f0048, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5e000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x145e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e5f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c600014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16612800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006a1800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026a0038, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6a00f0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x066c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x086c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e6f2440, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a9ec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c9e0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c9fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e9f0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aa02a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ca00001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16a102a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0caa1c30, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10aa0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18aaf000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aaa0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18acaa00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aaf2440, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10af0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10de8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ade3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00df8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cdf3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00e04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ee04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ae000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ee18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16e10002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08ea1c30, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ea0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00eac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0eeac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ea0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04ec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ec00a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00ef0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ef2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ef0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2406ff00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e08a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02082000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14090050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06091000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0e5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1812fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a12002b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04136000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16152ad0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0615c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0815c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0418a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a198000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c19a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121d5400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141d0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f4030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f1010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f4040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000018, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000060, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000180, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00000600, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000ff3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00001800, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00006000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00018000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000cfff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00060000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x00003fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "Sampler_2", "Metric set Sampler 2", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00OutputReady", "Slice0 Subslice0 Sampler Output Ready",
                "The percentage of time in which slice0 subslice0 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01OutputReady", "Slice0 Subslice1 Sampler Output Ready",
                "The percentage of time in which slice0 subslice1 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02OutputReady", "Slice0 Subslice2 Sampler Output Ready",
                "The percentage of time in which slice0 subslice2 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler03OutputReady", "Slice0 Subslice3 Sampler Output Ready",
                "The percentage of time in which slice0 subslice3 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler04OutputReady", "Slice0 Subslice4 Sampler Output Ready",
                "The percentage of time in which slice0 subslice4 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler05OutputReady", "Slice0 Subslice5 Sampler Output Ready",
                "The percentage of time in which slice0 subslice5 sampler output is ready",
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

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler06OutputReady", "Slice0 Subslice6 Sampler Output Ready",
                "The percentage of time in which slice0 subslice6 sampler output is ready",
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

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler07OutputReady", "Slice0 Subslice7 Sampler Output Ready",
                "The percentage of time in which slice0 subslice7 sampler output is ready",
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142d0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14320005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146d0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14720005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ad0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14b20005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ed0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14f20005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1e000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c200014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16212800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22290010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2a00d0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2d0033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e300080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a310008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e321980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x145e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12698000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x066c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x086c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006d1980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a702000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08718000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02720033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x169e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x189e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x069f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x089f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16a98000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06aa4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08aac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02ad1980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04af4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cb00002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cb18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04b20033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02b20000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18de8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ade0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0adf8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cdf0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ce04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ce18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ee98000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aea4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ceac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0eec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ec0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04ed1980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02ed0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ef4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cf00020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18f10002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06f20033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02f20000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a051000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24067e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02082000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06091000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0612c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0812c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06131000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0214c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1815000f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e18a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14190028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041c2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2a1f0061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2430, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f0124, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f5047, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad rd40@0x14:0xa1 UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78 qw@0x18 UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x48:0xae rd40@0x14:0xa1 UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80 qw@0x18 UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x5c:0xb3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x5c:0xb3 rd40@0x28:0xa6 UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8 qw@0x40 UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x60:0xb4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x60:0xb4 rd40@0x28:0xa6 UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb0 qw@0x40 UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread00ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice0 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread01ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice1 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread02ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice2 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
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

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread03ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice3 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice3 thread dispatcher",
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

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread04ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice4 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice4 thread dispatcher",
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

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread05ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice5 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice5 thread dispatcher",
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

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread06ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice6 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice6 thread dispatcher",
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

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread07ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice7 Thread Dispatcher",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice7 thread dispatcher",
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14a90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ae0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ee0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181ec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1e0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1f0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0429c300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062900c5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022ec300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042e00c5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a304000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c300001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5e000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x145e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e5f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c600014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16612800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0069c300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026900c5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6a00f0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x066c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x086c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e6ec5c3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e6fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e700050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a9ec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c9e0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c9fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e9f0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aa02a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ca00001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16a102a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ca9c5c3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22a90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18aaf000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aaa0005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18acaa00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aaec5c3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ae0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aafc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cb05000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10de8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ade3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00df8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cdf3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00e04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ee04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ae000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ee18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16e10002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e9c5c3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00eac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0eeac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ea0500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04ec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ec00a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00ee00c3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06eec500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ee0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00ef4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ef8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18f04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cf00040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2406ff00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e08a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02082000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14090050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06091000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0e5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1812fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a12002b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04136000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16152ad0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0615c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0815c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0418a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a198000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c19a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121d5400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141d0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f5030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f0050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f2020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f5050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000018, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000060, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000180, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00000600, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000ff3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00001800, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fcff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00006000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00018000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000cfff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00060000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x00003fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe65c, 0x00055054, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread00ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice0 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xdc FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x168 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread01ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice1 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xe0 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x170 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread02ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice2 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xe4 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x178 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread03ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice3 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice3 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xe8 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x180 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread04ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice4 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice4 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xec FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x188 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread05ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice5 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice5 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xf0 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x190 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread06ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice6 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice6 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xf4 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x198 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread07ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 Subslice7 Thread Dispatcher",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice7 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c dw@0xf8 FSUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08 qw@0x1a0 FSUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14a90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ae0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ee0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1e0006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1f0006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c200005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16210a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c29c100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2a0034, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2c0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2e00c1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e300010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5e0008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e5f0008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c600010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16612000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02618000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e69c100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6a0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c0008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x066c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006ec100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a700400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x149e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x169e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x049f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x069f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a900c1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22a90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04aa4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06aac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08ac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02aec100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ae0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02af8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ab04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18dec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08df8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0adf8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04e900c1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ce90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08ea4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aeac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0eec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04eec100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ee0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04ef8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cf00004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040150, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e040015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050054, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24063e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00088000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14090040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04094000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080e5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a120020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0412c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0612c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0214c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16156000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1419000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1f3061, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f3050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3730, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "TDL_3", "Metric set TDL_3", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
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
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe rd40@0x8c:0xbf UADD dw@0x90 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100 qw@0x108 UADD qw@0x110 UADD 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort0", "Thread Header Ready on Slice0 Subslice0 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort1", "Thread Header Ready on Slice0 Subslice0 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 1",
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

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort0", "Thread Header Ready on Slice0 Subslice1 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort1", "Thread Header Ready on Slice0 Subslice1 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 1",
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

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort0", "Thread Header Ready on Slice0 Subslice2 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort1", "Thread Header Ready on Slice0 Subslice2 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 1",
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

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader03ReadyPort0", "Thread Header Ready on Slice0 Subslice3 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice3 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader03ReadyPort1", "Thread Header Ready on Slice0 Subslice3 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice3 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader04ReadyPort0", "Thread Header Ready on Slice0 Subslice4 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice4 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 16 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader04ReadyPort1", "Thread Header Ready on Slice0 Subslice4 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice4 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader05ReadyPort0", "Thread Header Ready on Slice0 Subslice5 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice5 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 32 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader05ReadyPort1", "Thread Header Ready on Slice0 Subslice5 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice5 thread dispatcher port 1",
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

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader06ReadyPort0", "Thread Header Ready on Slice0 Subslice6 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice6 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 64 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader06ReadyPort1", "Thread Header Ready on Slice0 Subslice6 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice6 thread dispatcher port 1",
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

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader07ReadyPort0", "Thread Header Ready on Slice0 Subslice7 Thread Dispatcher Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice7 thread dispatcher port 0",
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

        availabilityEquation = "$SubsliceMask 128 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader07ReadyPort1", "Thread Header Ready on Slice0 Subslice7 Thread Dispatcher Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice7 thread dispatcher port 1",
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14292c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16290013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x142e2c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162e0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14692c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16690013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146e2c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x166e0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14a92c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16a90013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ae2c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16ae0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14e92c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16e90013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14ee2c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16ee0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1e3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1f3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a2000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16210002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002900c7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0629cf00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20290000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182a0f00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c00a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082ecfc7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c300500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a5ec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c5e0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c5fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e5f0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a602a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c600001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x166102a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a69cfc7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22690000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x186a5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6a000f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x186caa00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c6ecfc7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c6fc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e700005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c9e000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x129e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x149e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e9f000c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x029f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x049f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ca00014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16a12800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04a18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ea9cfc7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22a90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aaa0050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02aac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04aac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1aac000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08ac8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00aec700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02ae00cf, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ae0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00af8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02af4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ab01400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16de8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18dec000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ade0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06df8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08df8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0adf8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cdf0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06e04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ce04000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08e18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ae18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ce18000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02e9c700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04e900cf, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22e90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1ce90000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ea4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08ea4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aeac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0ceac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0aec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0cec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0eec8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18ec0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04eec700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ee00cf, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10ee0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04ef8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06ef4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1cf00014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c045400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e045555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10040155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14050055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2406ff00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x260600ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a08a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c08a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e095000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14090005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080e5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1812a800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a12003e, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0212c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0412c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a13f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04136000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e14c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02144000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0015c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e15c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16152af8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x18150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04154000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c158000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00182000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06188000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0818a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08192000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e198000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12190140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021c2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141d0028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x521f4924, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3e1f5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x461f3050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x481f2030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4a1f0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f5050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00053052, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
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
        aMetric = aSet->AddMetric( "Vdbox1Busy", "Vdbox1 Ring Busy",
            "The percentage of time when Vdbox1 command streamer was busy.",
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
        aMetric = aSet->AddMetric( "VeboxBusy", "Vebox Ring Busy",
            "The percentage of time when vebox command streamer was busy.",
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
        aMetric = aSet->AddMetric( "BlitterBusy", "Blitter Ring Busy",
            "The percentage of time when blitter command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e061200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x22062400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10002400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00038000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06032000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020600f3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c060043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20060000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02000023, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x20002000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3a1f6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4e1f2900, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x501f00e9, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10204000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c214000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x401f4131, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x421f1021, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x441f3100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181b2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x185b2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12240120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06218000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08212000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x180b8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e080010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041b8300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x221b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x184b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e480004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045b0083, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x105b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x225b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045e1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0823a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02242980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10240000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06240000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a244000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c250004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08268000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007c000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x000007ff, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "TestOa", "Metric set TestOa", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
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

        availabilityEquation = NULL;
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

        availabilityEquation = NULL;
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

        availabilityEquation = NULL;
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

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Counter4", "TestCounter4",
            "HW test counter 4. Factor: 0.3333",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Counter5", "TestCounter5",
            "HW test counter 5. Factor: 0.3333",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Counter6", "TestCounter6",
            "HW test counter 6. Factor: 0.16666",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Counter7", "TestCounter7",
            "HW test counter 7. Factor: 0.6666",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Counter8", "TestCounter8",
            "HW test counter 8. Should be equal to 1.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
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
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x24000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e130056, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a130000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x541f0001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4c1f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x301f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000004, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000003, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000007, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ffff, REGISTER_TYPE_OA ));
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
