/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_XEHP_SDV_GT1.cpp
//
//     Abstract:   C++ automated generated file that defines Metric Sets
//                 for each Concurrent Group

#include "md_metric_sets_XEHP_SDV_GT1.h"
#include <algorithm>

#if MD_INCLUDE_XEHP_SDV_GT1_METRICS

namespace MetricsDiscoveryInternal::MetricSets_XEHP_SDV_GT1_OA
{
    void AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;
        information               = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM | API_TYPE_MEDIA, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" );
            information->SetDeltaReportReadEquation( "qw@0x1c0" );
            information->SetOverflowFunction( "NS_TIME" );
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency", "The last GPU core (unslice) frequency in the measurement.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, "MHz", nullptr, 1 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" );
            information->SetDeltaReportReadEquation( "qw@0x218 1000000 UDIV" );
        }

        information = concurrentGroup->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency", "The last GPU Execution Unit slice frequency in the measurement.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, "MHz", nullptr, 2 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" );
        }

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 3 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "0x40 dw@0x0 19 >> 0x3f AND 0x0 == UMUL dw@0x0 19 >> 0x3f AND OR" );
        }

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 4 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" );
        }

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 5 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x08 0xfc7fffbf AND dw@0x0 16 >> 0x1 AND UMUL" );
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed", "The flag indicating that GPU core frequency has changed.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 6 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x214" );
        }

        information = concurrentGroup->AddInformation( "QuerySplitOccurred", "Query Split Occurred", "The flag indicating that query has been split during execution on the GPU.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 7 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x210" );
        }

        information = concurrentGroup->AddInformation( "ReportId", "Query report id", "Query report identification number.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 8 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x220" );
        }

        information = concurrentGroup->AddInformation( "ReportsCount", "Query reports count", "The number of available query reports.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 9 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x224" );
        }

        information = concurrentGroup->AddInformation( "OverrunOccured", "Query Overrun Occurred", "The flag indicating that Oa buffer has been overran.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 10 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1dc" );
        }

        information = concurrentGroup->AddInformation( "SampleSequence", "Sample sequence", "Number identifying report sequence.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 11 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 0x7f AND" );
        }

        information = concurrentGroup->AddInformation( "SamplePhase", "Sample phase", "Buffer execution phase.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_SAMPLE_PHASE, nullptr, nullptr, 12 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 7 >> 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "GpuNode", "Gpu node", "GPU node buffer was sent to.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_GPU_NODE, nullptr, nullptr, 13 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 8 >> 0x07 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryTimer", "Mid Query Timer", "The flag indicating that timer report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 14 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryProgramming", "Mid Query Programming", "The flag indicating that counter programming report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 15 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x02 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryMarker", "Mid Query Marker", "The flag indicating that query marker report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 16 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x04 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryCtxSwitch", "Mid Query Context Switch", "The flag indicating that context switch report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 17 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x08 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryC6", "Mid Query C6", "The flag indicating that C6 report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 18 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x10 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryFreqChange", "Mid Query Freq Change", "The flag indicating that frequency change report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 19 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1d8 0x20 AND" );
        }

        information = concurrentGroup->AddInformation( "StreamMarker", "Stream marker", "Stream marker value.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 20 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x08 dw@0x0 19 >> 0x8 AND 0x0 == UMUL" );
        }

        information = concurrentGroup->AddInformation( "ReportError", "Query report error", "An error in the query execution, the received report should be ignored.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 21 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x2ac 0x13 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportLost", "Query report lost", "Begin or end query report has not been triggered due to hw limitations.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 22 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x2ac 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportInconsistent", "Query report inconsistent", "The contextId inconsistency in the Oa buffer within the query window.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 23 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x2ac 0x02 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportCtxSwitchLost", "Query report context switch lost", "Oa buffer has not been browsed to find context switch reports to filter out unfamiliar contexts from the query report.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 24 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x2ac 0x08 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportWithoutWorkload", "Query report missing workload", "Missing workload between query begin and query end.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 25 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x2ac 0x10 AND" );
        }
    }

    CRenderBasicMetricSet::CRenderBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CRenderBasicMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x70 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x74 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x78 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x7c 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmReads", "SLM Bytes Read",
                          "The total number of reads from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmWrites", "SLM Writes",
                          "The total number of writes into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "128 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 512 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "128 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 512 UMUL" ) ) );
        }

        availabilityEquation = "$GtSlice0DualSubslice0";
        metric               = AddMetric( "Sampler00OrL1CacheBusy", "Sampler or L1 Cache Slice0 Dualsubslice0 is busy",
                          "The percentage of time when sampler or L1 cache slice0 dualsubslice0 is busy",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1b8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "SamplersOrL1CacheBusy", "Samplers Or L1 Cache Busy",
                          "The percentage of time in which samplers or L1 caches are not idle.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 30 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$Sampler00OrL1CacheBusy" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$GtSlice0DualSubslice0";
        metric               = AddMetric( "Sampler00Bottleneck", "Sampler00 Bottleneck",
                          "The percentage of time in which Slice0 Sampler0 has been slowing down the pipe when processing EU requests.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 31 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1b0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
                          "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_INDICATE | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 32 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$Sampler00Bottleneck" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$GtSlice0DualSubslice0 $GtSlice2DualSubslice0 $GtSlice4DualSubslice0 $GtSlice6DualSubslice0 OR OR OR";
        metric               = AddMetric( "SamplersBusy", "Samplers Busy",
                          "The percentage of time in which samplers inputs or outputs are active",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 33 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 FADD dw@0xc8 FADD dw@0xcc FADD $GtSlice0DualSubslice0 $GtSlice2DualSubslice0 FADD $GtSlice4DualSubslice0 FADD $GtSlice6DualSubslice0 FADD FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140 qw@0x148 FADD qw@0x150 FADD qw@0x158 FADD $GtSlice0DualSubslice0 $GtSlice2DualSubslice0 FADD $GtSlice4DualSubslice0 FADD $GtSlice6DualSubslice0 FADD FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e820160, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18845200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e84000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08820017, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00830001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0484002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06841c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0884000f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14840de0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00840001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00850015, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02855000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0008003f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0208f000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000a0015, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a5000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e820160, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18845200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a8205c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00830040, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0484002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a8403c7, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00840040, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00850540, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00080fc0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000a0540, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000e, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e820160, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18845200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e820017, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00831000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0484002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c8401c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e84000f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00841000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00855000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02850001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0008f000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02080003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000a5000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a0001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e820160, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18845200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x108205c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02820000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02830004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0484002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x108403c7, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08840000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02840004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02850054, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020800fc, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a0054, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00015000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020100a9, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000401c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00020a95, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02025000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00031249, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02032491, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04031012, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06030001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x48034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4c030842, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x28030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4e0341c2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x3a030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x40030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x50031610, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x520300d0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x54031c0d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4a030010, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x22030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0011002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0211a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0012c007, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0013002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0213a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00110a80, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00120038, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00130a80, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0011a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02110002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x001201c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0013a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02130002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x0000000b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x021100a8, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00120e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x021300a8, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x66030002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000038, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fff8, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x000001c0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000ffc7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000e00, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000fe3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00007000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000f1ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CComputeBasicMetricSet::CComputeBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CComputeBasicMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x70 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x74 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x78 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x7c 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmReads", "SLM Bytes Read",
                          "The total number of reads from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmWrites", "SLM Writes",
                          "The total number of writes into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "128 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 512 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "128 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 512 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity1MetricSet::CEuActivity1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity1MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsFpuActive", "VS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsFpuActive", "PS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuSendActive", "EU Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00810710, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a10910, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00850750, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a50950, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00802702, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a02902, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity2MetricSet::CEuActivity2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity2MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsEmActive", "CS EM Pipe Active",
                          "The percentage of time in which EU FPU1 pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsFpuActive", "CS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsSendActive", "CS Send Pipeline Active",
                          "The percentage of time in which EU send pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00861761, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a61961, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00860760, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a60960, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00862762, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a62962, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity3MetricSet::CEuActivity3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity3MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsEmActive", "VS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsEmActive", "PS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsSendActive", "PS Send Pipeline Active",
                          "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00811711, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a11911, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00851751, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a51951, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00852752, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a52952, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity4MetricSet::CEuActivity4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity4MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsFpuActive", "HS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a hull shader instruction.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsFpuActive", "DS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a domain shader instructions.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsSendActive", "VS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00820720, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a20920, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00830730, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a30930, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00812712, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a12912, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity5MetricSet::CEuActivity5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity5MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsEmActive", "HS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a hull shader instructions.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsEmActive", "DS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a domain shader instructions.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsSendActive", "HS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a hull shader instruction.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00821721, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a21921, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00831731, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a31931, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00822722, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a22922, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity6MetricSet::CEuActivity6MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity6MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsFpuActive", "GS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a geometry shader instructions.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsEmActive", "GS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a geometry shader instructions.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsSendActive", "GS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a geometry shader instruction.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00840740, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a40940, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00841741, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a41941, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00842742, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a42942, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity7MetricSet::CEuActivity7MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity7MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "FpuActive", "EU FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EmActive", "EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuFpuEmActive", "EU FPU And EM Pipes Active",
                          "The percentage of time in which EU FPU and EM pipelines were actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
                          "The average rate of IPC calculated for 2 FPU pipelines.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$EuFpuEmActive $FpuActive $EmActive FADD $EuFpuEmActive FSUB FDIV 1 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "2" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00803703, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a03903, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00800700, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a00900, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00801701, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a01901, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity8MetricSet::CEuActivity8MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity8MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsSendActive", "DS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a domain shader instruction.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuSysFpuActive", "EU FPU And SYS Pipes Active",
                          "The percentage of time in which EU FPU and SYS pipelines were actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SysActive", "SYS Pipe Active",
                          "The percentage of time in which EU SYS pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00832732, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a32932, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00809709, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a09909, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x0080a70a, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a0a90a, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CGpuBusynessMetricSet::CGpuBusynessMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CGpuBusynessMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD $EuDualSubslicesTotalCount FMUL $EuDualSubslicesSlice0123Count FDIV FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x14" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x1c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self $EuDualSubslicesTotalCount UMUL $EuDualSubslicesSlice0123Count UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1b8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeEngine0Busy", "ComputeEngine0 Ring Busy",
                          "The percentage of time when compute command streamer 0 was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeEngine1Busy", "ComputeEngine1 Ring Busy",
                          "The percentage of time when compute command streamer 1 was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeEngine2Busy", "ComputeEngine2 Ring Busy",
                          "The percentage of time when compute command streamer 2 was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeEngine3Busy", "ComputeEngine3 Ring Busy",
                          "The percentage of time when compute command streamer 3 was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PoshEngineBusy", "Posh Ring Busy",
                          "The percentage of time when posh command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1b0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "BlitterBusy", "Blitter Ring Busy",
                          "The percentage of time when blitter command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VeboxBusy", "Vebox Ring Busy",
                          "The percentage of time when vebox command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Vdbox0Busy", "Vdbox0 Ring Busy",
                          "The percentage of time when Vdbox0 command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Vdbox1Busy", "Vdbox1 Ring Busy",
                          "The percentage of time when Vdbox1 command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AnyComputeEngineBusy", "Any compute engine busy",
                          "The percentage of time when any compute engine is busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndAnyComputeEngineBusy", "Render and any compute engines are simultaneously busy",
                          "The percentage of time when render and any compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x470b0120, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x478b0120, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x22030120, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x090b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x170b08c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x050b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x030b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x098b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x178b0023, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x058b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x038b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020101b0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04030004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12030023, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a042400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x22042400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a042400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34040009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x3e041200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x52040009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04010006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16010003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00015000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02015005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020426e9, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040401b7, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0604000f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0400c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0404cb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1004001b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14040cc0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16040023, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00040000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02050150, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02032490, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040324db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06030002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x50030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x52030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x54030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x48030800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4a030c42, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x22030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4c030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02040150, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x66030002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00040001, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x00007c3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fc3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc48, 0x00ff00f0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdd48, 0x000f000c, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CTestOaMetricSet::CTestOaMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CTestOaMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter0", "TestCounter0",
                          "HW test counter 0. Factor: 0.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter1", "TestCounter1",
                          "HW test counter 1. Factor: 1.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter2", "TestCounter2",
                          "HW test counter 2. Factor: 1.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter3", "TestCounter3",
                          "HW test counter 3. Factor: 0.5",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter4", "TestCounter4",
                          "HW test counter 4. Factor: 0.3333",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter5", "TestCounter5",
                          "HW test counter 5. Factor: 0.3333",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter6", "TestCounter6",
                          "HW test counter 6. Factor: 0.16666",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter7", "TestCounter7",
                          "HW test counter 7. Factor: 0.6666",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter8", "TestCounter8",
                          "HW test counter 8. Should be equal to 1 in IOStream or in OAG query mode",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter9", "TestCounter9 - OAR enable",
                          "HW test counter 9. Should be equal to 1 in query.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5a010000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4a040000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08010016, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10010cc0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04010000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02010004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06040004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10040037, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02040000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00040000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02032400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x52030000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x54030003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x66030002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000004, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000003, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000007, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00100082, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd970, 0x001000c2, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd974, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd978, 0x00100001, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd97c, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0x2b2c, 0x00000000, REGISTER_TYPE_OA );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
} // namespace MetricsDiscoveryInternal::MetricSets_XEHP_SDV_GT1_OA

#endif
