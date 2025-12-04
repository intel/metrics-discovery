/*========================== begin_copyright_notice ============================

Copyright (C) 2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_CRI.cpp
//
//     Abstract:   C++ automated generated file that defines Metric Sets
//                 for each Concurrent Group

#include "md_concurrent_group.h"
#include "md_metric_set.h"
#include "md_metric_sets_CRI.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_utils.h"
#include <algorithm>

#if MD_INCLUDE_CRI_METRICS

namespace MetricsDiscoveryInternal::MetricSets_CRI_OA
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;

        information = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "qw@0x290" ) );
        MD_CHECK_CC( information->SetOverflowFunction( "NS_TIME" ) );

        information = concurrentGroup->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency", "The last GPU core (unslice) frequency in the measurement.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, "MHz", nullptr, 1 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ) );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "qw@0x2d8 1000000 UDIV" ) );

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 2 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x7f AND" ) );

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 3 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" ) );

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 4 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x10 dw@0x0 22 >> 0x1 AND UMUL" ) );

        information = concurrentGroup->AddInformation( "SourceId", "SourceId", "SourceId", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 5 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 26 >> 0x3f AND" ) );

        information = concurrentGroup->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed", "The flag indicating that GPU core frequency has changed.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 6 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2d4" ) );

        information = concurrentGroup->AddInformation( "QuerySplitOccurred", "Query Split Occurred", "The flag indicating that query has been split during execution on the GPU.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 7 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2d0" ) );

        information = concurrentGroup->AddInformation( "ReportId", "Query report id", "Query report identification number.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 8 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2e0" ) );

        information = concurrentGroup->AddInformation( "ReportsCount", "Query reports count", "The number of available query reports.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 9 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2e4" ) );

        information = concurrentGroup->AddInformation( "OverrunOccured", "Query Overrun Occurred", "The flag indicating that Oa buffer has been overran.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 10 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2ac" ) );

        information = concurrentGroup->AddInformation( "MidQueryTimer", "Mid Query Timer", "The flag indicating that timer report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 11 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x01 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryProgramming", "Mid Query Programming", "The flag indicating that counter programming report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 12 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x02 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryMarker", "Mid Query Marker", "The flag indicating that query marker report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 13 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x04 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryCtxSwitch", "Mid Query Context Switch", "The flag indicating that context switch report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 14 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x08 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryC6", "Mid Query C6", "The flag indicating that C6 report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 15 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x10 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryFreqChange", "Mid Query Freq Change", "The flag indicating that frequency change report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 16 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x20 AND" ) );

        information = concurrentGroup->AddInformation( "MidQueryMmioTrigger", "Mid Query Mmio Trigger", "The flag indicating that mmio trigger report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 17 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x2a8 0x40 AND" ) );

        information = concurrentGroup->AddInformation( "StreamMarker", "Stream marker", "Stream marker value.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 18 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x10 dw@0x0 19 >> 0x8 AND 0x0 == UMUL" ) );

        information = concurrentGroup->AddInformation( "ReportError", "Query report error", "An error in the query execution, the received report should be ignored.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 19 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x73 AND" ) );

        information = concurrentGroup->AddInformation( "ReportLost", "Query report lost", "Begin or end query report has not been triggered due to hw limitations.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 20 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x01 AND" ) );

        information = concurrentGroup->AddInformation( "ReportInconsistent", "Query report inconsistent", "The contextId inconsistency in the Oa buffer within the query window.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 21 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x02 AND" ) );

        information = concurrentGroup->AddInformation( "ReportCtxSwitchLost", "Query report context switch lost", "Other contexts activity is not filter out from the query report.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 22 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x08 AND" ) );

        information = concurrentGroup->AddInformation( "ReportWithoutWorkload", "Query report missing workload", "Missing workload between query begin and query end.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 23 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x10 AND" ) );

        information = concurrentGroup->AddInformation( "ReportContextMismatch", "Query report context mismatch", "Contexts on query begin and query end are different.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 24 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x20 AND" ) );

        information = concurrentGroup->AddInformation( "ReportQueryModeMismatch", "Report query mode mismatch", "Query mode is different than command streamer used for executing query commands.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 25 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x40 AND" ) );

        information = concurrentGroup->AddInformation( "ReportQueryNotExecuted", "Query report not executed", "Begin or end query report was not executed.", "Report Meta Data", API_TYPE_DX12 | API_TYPE_VULKAN, INFORMATION_TYPE_FLAG, nullptr, nullptr, 26 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetDeltaReportReadEquation( "dw@0x36c 0x04 AND" ) );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CComputeBasicMetricSet::CComputeBasicMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CComputeBasicMetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "GPU_BUSY", "GPU Busy",
            "Percentage of time in which GPU is not idle including all GPU engines",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREADGROUP_COUNT", "Async GpGpu Threadgroup Count",
            "Number of Async GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_HIT", "ICache Hit",
            "Number of Instruction Cache hits",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_MISS", "ICache Miss",
            "Number of Instruction Cache misses",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_ACTIVE", "XVE Active",
            "Percentage of time in which at least one pipe is active in XVE",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU0_ALL", "XVE Inst Executed ALU0 All",
            "Number of execution slots taken by instructions executed on ALU0 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU1_ALL", "XVE Inst Executed ALU1 All",
            "Number of execution slots taken by instructions executed on ALU1 pipe. Does not include extended math instructions.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_SEND_ALL", "XVE Inst Executed Send All",
            "Number of instruction (GRF or SRF) dispatches executed on SEND Pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_ISSUED_ALL", "XVE Inst Issued All",
            "Number of instructions issued (decoded) to any pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 12 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SHARED_FUNCTION_ACCESS_HOLD", "XVE Shared Function Access Hold",
            "Percentage of time in which XVE requests stalled by Shared Function units",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 13 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL", "XVE Stall",
            "Percentage of time in which any thread loaded but not even a single pipe is active in XVE",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 14 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_THREADS_OCCUPANCY_ALL", "XVE Threads Occupancy All",
            "Percentage of thread slots occupied",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 15 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe0 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd0 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU2_ALL", "XVE Inst Executed ALU2 All",
            "Number of execution slots taken by instructions executed in ALU2 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 16 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_MULTIPLE_PIPE_ACTIVE", "XVE Multiple Pipe Active",
            "Percentage of time in which at least two pipes are actively executing a Gen ISA instruction among ALU0, ALU1, ALU2 and ALU3 pipes",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 17 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_PARTIAL_WRITE_COUNT", "Load Store Cache Partial Write Count",
            "Number of writes to the Load Store Cache that don't fill a subsector",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 18 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BANK_CONFLICT_COUNT", "SLM Bank Conflict Count",
            "Number of SLM accesses resulting in a bank conflict",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 19 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BYTE_READ", "SLM Byte Read",
            "Number of bytes read from SLM",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 20 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BYTE_WRITE", "SLM Byte Write",
            "Number of bytes written to SLM",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 21 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_BYTE_READ", "Load Store Cache Byte Read",
            "Number of bytes read out of the Load Store Cache, excluding SLM accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 22 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_BYTE_WRITE", "Load Store Cache Byte Write",
            "Number of bytes written to the Load Store Cache, excluding SLM accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 23 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_ACCESS", "Load Store Cache Access",
            "Number of Load Store Cache accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 24 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_HIT", "Load Store Cache Hit",
            "Number of Load Store Cache hits",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 25 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREAD_EXIT_COUNT", "Async GpGpu Thread Exit Count",
            "Number of Async GPGPU EOT messages received",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 26 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPGPU_DISPATCH", "GpGpu Dispatch",
            "Percentage of time in which spent dispatching GPGPU threads to XVEs",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 27 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x78 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x68 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_COMPUTE_ENGINE_BUSY", "Command Parser Compute Engine Busy",
            "Percentage of time in which there is a context loaded and active on the compute queue",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 28 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x128 $ComputeEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x118 $ComputeEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_COMPUTE_ENGINE_DISPATCH_KERNEL_COUNT", "Command Parser Compute Engine Dispatch Kernel Count",
            "Number of compute walker commands parsed on the compute engine",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 29 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x130" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_COPY_ENGINE_BUSY", "Command Parser Copy Engine Busy",
            "Percentage of time in which there is a context loaded and active on the copy queue.",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 30 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x138" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x128" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_FLUSH_COUNT", "Command Parser Flush Count",
            "Number of Stalling flushes at the top of the pipe",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 31 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x140" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x130" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_PIPE_ALU0_AND_ALU1_ACTIVE", "XVE Pipe ALU0 And ALU1 Active",
            "Percentage of time in which ALU0 and ALU1 pipes are both actively executing a Gen ISA instruction",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 32 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_PIPE_ALU0_AND_ALU2_ACTIVE", "XVE Pipe ALU0 And ALU2 Active",
            "Percentage of time in which ALU0 and ALU2 pipes are both actively executing a Gen ISA instruction",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 33 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU0_ALL_UTILIZATION", "XVE Inst Executed ALU0 All Utilization",
            "Percentage of time taken by instructions executed on ALU0 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 34 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU1_ALL_UTILIZATION", "XVE Inst Executed ALU1 All Utilization",
            "Percentage of time taken by instructions executed on ALU1 pipe. Does not include extended math instructions.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 35 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU2_ALL_UTILIZATION", "XVE Inst Executed ALU2 All Utilization",
            "Percentage of time taken by instructions executed in ALU2 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 36 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8 2 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8 2 UMUL" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_BARRIER", "XVE Inst Executed Barrier",
            "Number of sync.bar and sync.host instructions executed",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 37 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COPY_ENGINE_READ_REQUEST", "Copy Engine Read Request",
            "Number of read requests sent by the Copy Engine",
            "Copy Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 38 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x148" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x138" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COPY_ENGINE_REQUEST_STALL", "Copy Engine Request Stall",
            "Percentage of time in which copy engine is stalled on the memory path due to stall on the read or write path when there are commands pending within copy engine",
            "Copy Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 39 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x150 $CopyEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x140 $CopyEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COPY_ENGINE_WRITE_REQUEST", "Copy Engine Write Request",
            "Number of write requests sent by the Copy Engine",
            "Copy Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 40 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x158" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x148" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPU_MEMORY_BYTE_READ", "GPU Memory Byte Read",
            "Number of device local memory (HBM, GDDR, LPDDR, etc.) read bytes",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 41 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x160" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x150" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPU_MEMORY_BYTE_WRITE", "GPU Memory Byte Write",
            "Number of device local memory (HBM, GDDR, LPDDR, etc.) write bytes",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 42 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x168" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x158" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPU_MEMORY_ACTIVE", "GPU Memory Active",
            "Percentage of time in which local memory is active",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 43 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x170 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x160 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPU_MEMORY_READ", "GPU Memory Read",
            "Number of local memory reads",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 44 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x178" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x168" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPU_MEMORY_WRITE", "GPU Memory Write",
            "Number of local memory writes",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 45 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x180" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x170" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TLB_MISS", "TLB Miss",
            "Number of misses from all TLBs and all engines",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 46 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x188" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x178" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TLB_PAGE_SIZE_1G", "TLB Page Size 1g",
            "Number of TLB accesses to pages of size 1 GB",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 47 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x190" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x180" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TLB_PAGE_SIZE_2M", "TLB Page Size 2m",
            "Number of TLB accesses to pages of size 2 MB",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 48 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x198" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x188" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TLB_PAGE_SIZE_4K", "TLB Page Size 4k",
            "Number of TLB accesses to pages of size 4 KB",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 49 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1a0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x190" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TLB_PAGE_SIZE_64K", "TLB Page Size 64k",
            "Number of TLB accesses to pages of size 64 KB",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 50 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1a8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x198" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMPRESSOR_INPUT", "Compressor Input",
            "Number of 256B writes to compressible surfaces at the input of the compressor",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 51 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1b0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMPRESSOR_OUTPUT", "Compressor Output",
            "Number of 256B writes to compressible surfaces at the output of the compressor",
            "Memory", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 52 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1b8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_READ", "L3 Read",
            "Number of Device Cache 64B read requests",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 53 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1c0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1b0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_WRITE", "L3 Write",
            "Number of Device Cache 64B write requests",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 54 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1c8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1b8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_BYTE_READ", "L3 Byte Read",
            "Number of Device Cache bytes read",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 55 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1c0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1b0" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$Self 64 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_BYTE_WRITE", "L3 Byte Write",
            "Number of Device Cache bytes written",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 56 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1c8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1b8" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$Self 64 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_ATOMIC_ACCESS", "L3 Atomic Access",
            "Number of atomic accesses to Device Cache bank",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 57 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1d0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1c0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_HIT", "L3 Hit",
            "Number of Device Cache accesses which hits in the Device Cache cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 58 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1d8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1c8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_MISS", "L3 Miss",
            "Number of Device Cache accesses which miss in the Device Cache cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 59 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1e0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1d0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_SUPERQ_FULL", "L3 Superq Full",
            "Percentage of time in which all slots in Device Cache request queue are waiting for data return / response",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 60 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x1e8 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x1d8 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU3_ALL", "XVE Inst Executed Alu3 All",
            "Number of execution slots taken by instructions executed in ALU3 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 61 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_GRFBLOCK_OCCUPANCY_ALL", "XVE Grfblock Occupancy All",
            "Number of GRF register blocks occupied",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 62 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_LANE_ENABLED", "XVE Inst Lane Enabled",
            "Number of execution lanes enabled for instructions executed on ALU0 and ALU1. Does not include control-flow instructions such as CALL, CALLA, RET, etc.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 63 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_LANE_TOTAL", "XVE Inst Lane Total",
            "Number of available execution lanes (enabled and not enabled) for instructions executed on ALU0 and ALU1, evaluated after shootdown. Does not include control-flow instructions such as CALL, CALLA, RET, etc.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 64 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xb0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_OP_FP32", "XVE Op Fp32",
            "Number of effective 32-bit floating-point operations (FLOPs) executed on ALU0 and ALU1",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 65 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xa8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_OP_FP64", "XVE Op Fp64",
            "Number of effective 64-bit floating-point operations (FLOPs) executed on ALU0 and ALU1",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 66 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13000, 0x00001802, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13004, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13008, 0x00000622, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1300c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13010, 0x00000623, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13014, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13018, 0x00000605, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1301c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13020, 0x0000060f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13024, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13028, 0x00000603, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1302c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13030, 0x00000601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13034, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13038, 0x00000a14, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1303c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13040, 0x00000a0b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13044, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13048, 0x00000a0a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1304c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13050, 0x00001804, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13054, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13058, 0x00001600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1305c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13060, 0x00000625, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13064, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13068, 0x00000626, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1306c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13070, 0x00000608, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13074, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13078, 0x00000632, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1307c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13080, 0x00000627, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13084, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13088, 0x00000634, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1308c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13090, 0x00000635, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13094, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13098, 0x00000636, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1309c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a0, 0x00000637, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a8, 0x0000060b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b0, 0x00000600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b8, 0x00000606, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c0, 0x00000604, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c8, 0x00000614, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d0, 0x00000624, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d8, 0x00000a0e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130dc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e0, 0x00000a0d, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e8, 0x00000a15, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ec, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f0, 0x00000a16, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f8, 0x00000a13, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130fc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13300, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13304, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13500, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13504, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13700, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13704, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13308, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1330c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13508, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1350c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13708, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1370c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13310, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13314, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13510, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13514, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13710, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13714, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13318, 0x00005000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1331c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13518, 0x00005000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1351c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13718, 0x00005000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1371c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13320, 0x00005010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13324, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13520, 0x00005010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13524, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13720, 0x00005010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13724, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13328, 0x00006e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1332c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13528, 0x00006e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1352c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13728, 0x00006e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1372c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13330, 0x00006e02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13334, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13530, 0x00006e02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13534, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13730, 0x00006e02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13734, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13338, 0x00006e01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1333c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13538, 0x00006e01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1353c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13738, 0x00006e01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1373c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13340, 0x00006021, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13344, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13540, 0x00006021, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13544, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13740, 0x00006021, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13744, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13348, 0x00006022, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1334c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13548, 0x00006022, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1354c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13748, 0x00006022, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1374c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13350, 0x00006020, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13354, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13550, 0x00006020, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13554, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13750, 0x00006020, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13754, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13358, 0x0000601e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1335c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13558, 0x0000601e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1355c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13758, 0x0000601e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1375c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13360, 0x0000601f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13364, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13560, 0x0000601f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13564, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13760, 0x0000601f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13764, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13368, 0x00005c00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1336c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13568, 0x00005c00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1356c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13768, 0x00005c00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1376c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13370, 0x00005c04, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13374, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13570, 0x00005c04, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13574, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13770, 0x00005c04, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13774, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13378, 0x00005c03, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1337c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13578, 0x00005c03, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1357c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13778, 0x00005c03, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1377c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13380, 0x00005c01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13384, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13580, 0x00005c01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13584, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13780, 0x00005c01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13784, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13388, 0x00005c02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1338c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13588, 0x00005c02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1358c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13788, 0x00005c02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1378c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13390, 0x00004600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13394, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13590, 0x00004600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13594, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13790, 0x00004600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13794, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13398, 0x00004601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1339c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13598, 0x00004601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1359c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13798, 0x00004601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1379c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133a0, 0x0000600f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133a4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135a0, 0x0000600f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135a4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137a0, 0x0000600f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137a4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133a8, 0x00006010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135a8, 0x00006010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137a8, 0x00006010, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133b0, 0x00006002, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135b0, 0x00006002, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137b0, 0x00006002, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133b8, 0x00006012, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135b8, 0x00006012, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137b8, 0x00006012, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133c0, 0x00006011, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135c0, 0x00006011, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137c0, 0x00006011, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133c8, 0x00006013, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x133cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135c8, 0x00006013, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x135cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137c8, 0x00006013, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x137cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CL1ProfileMetricSet::CL1ProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CL1ProfileMetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "GPU_BUSY", "GPU Busy",
            "Percentage of time in which GPU is not idle including all GPU engines",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREADGROUP_COUNT", "Async GpGpu Threadgroup Count",
            "Number of Async GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_ACCESS", "Load Store Cache Access",
            "Number of Load Store Cache accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_BYTE_READ", "Load Store Cache Byte Read",
            "Number of bytes read out of the Load Store Cache, excluding SLM accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_BYTE_WRITE", "Load Store Cache Byte Write",
            "Number of bytes written to the Load Store Cache, excluding SLM accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_HIT", "Load Store Cache Hit",
            "Number of Load Store Cache hits",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_INPUT_AVAILABLE", "Load Store Cache Input Available",
            "Percentage of time in which the Load Store Cache has input available",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_NUMBER_OF_BANK_ACCESS_COUNT", "Load Store Cache Number Of Bank Access Count",
            "Number of Load Store Cache banks accessed in a clock.",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50 4 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40 4 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_OUTPUT_READY", "Load Store Cache Output Ready",
            "Percentage of time in which the Load Store Cache has output ready",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 12 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_PARTIAL_WRITE_COUNT", "Load Store Cache Partial Write Count",
            "Number of writes to the Load Store Cache that don't fill a subsector",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 13 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_ACCESS_COUNT", "SLM Access Count",
            "Number of SLM accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 14 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BANK_CONFLICT_COUNT", "SLM Bank Conflict Count",
            "Number of SLM accesses resulting in a bank conflict",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 15 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BYTE_READ", "SLM Byte Read",
            "Number of bytes read from SLM",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 16 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_BYTE_WRITE", "SLM Byte Write",
            "Number of bytes written to SLM",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 17 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_ATOMIC_MESSAGE_COUNT", "XVE Load Store Cache Atomic Message Count",
            "Number of atomic operations sent by XVEs to the Load Store Cache",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 18 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_FENCE_MESSAGE_COUNT", "XVE Load Store Cache Fence Message Count",
            "Number of fence messages sent by XVEs to the Load Store Cache",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 19 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_READ_MESSAGE_COUNT", "XVE Load Store Cache Read Message Count",
            "Number of read messages sent by XVEs to the Load Store Cache",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 20 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_REGISTER_REQUEST_COUNT", "XVE Load Store Cache Register Request Count",
            "Number of message payload transactions sent by XVEs to the Load Store Cache",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 21 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_REGISTER_RESPONSE_COUNT", "XVE Load Store Cache Register Response Count",
            "Number of message payload transactions sent from the Load Store Cache back to XVEs",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 22 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_LOAD_STORE_CACHE_WRITE_MESSAGE_COUNT", "XVE Load Store Cache Write Message Count",
            "Number of write messages sent by XVEs to the Load Store Cache",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 23 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SLM_ATOMIC_MESSAGE_COUNT", "XVE SLM Atomic Message Count",
            "Number of SLM atomic operations sent by XVEs",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 24 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SLM_FENCE_MESSAGE_COUNT", "XVE SLM Fence Message Count",
            "Number of SLM fence operations sent by XVEs",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 25 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SLM_READ_MESSAGE_COUNT", "XVE SLM Read Message Count",
            "Number of SLM read messages sent by XVEs",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 26 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SLM_WRITE_MESSAGE_COUNT", "XVE SLM Write Message Count",
            "Number of SLM write messages sent by XVEs",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 27 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_ATOMIC_ACCESS_COUNT", "SLM Atomic Access Count",
            "Number of SLM atomic accesses",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 28 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "SLM_OVERLAPPED_ATOMIC_ACCESS_COUNT", "SLM Overlapped Atomic Access Count",
            "Number of overlapped SLM atomic accesses within a message",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 29 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GLOBAL_OVERLAPPED_ATOMIC_ACCESS_COUNT", "Global Overlapped Atomic Access Count",
            "Number of overlapped global memory atomic accesses within a message",
            "L1 Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 30 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_L3_HIT", "ICache L3 Hit",
            "Number of XVE instruction cache requests that hit the Device Cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 31 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x128" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_L3_READ", "ICache L3 Read",
            "Number of Device Cache read requests coming from XVE Instruction Cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 32 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x130" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_BUSY", "L3 Busy",
            "Percentage of time in which Device Cache request queue has one or more requests pending",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 33 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x138 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x128 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_INPUT_AVAILABLE", "L3 Input Available",
            "Percentage of time in which Device Cache bank has input requests",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 34 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x140 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x130 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_OUTPUT_READY", "L3 Output Ready",
            "Percentage of time in which Device Cache bank has output ready",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 35 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x148 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x138 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "L3_STALL", "L3 Stall",
            "Percentage of time in which Device Cache bank stalled",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 36 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x150 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x140 $L3BankTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_L3_HIT", "Load Store Cache L3 Hit",
            "Number of Load Store Cache requests to Device Cache that are hit",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 37 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x158" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x148" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_L3_READ", "Load Store Cache L3 Read",
            "Number of cacheline read requests from the Load Store Cache to Device Cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 38 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x160" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x150" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "LOAD_STORE_CACHE_L3_WRITE", "Load Store Cache L3 Write",
            "Number of cacheline write requests from the Load Store Cache to Device Cache",
            "Device Cache", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 39 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x168" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x158" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13000, 0x00001802, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13004, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13008, 0x00000a0b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1300c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13010, 0x00000a13, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13014, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13018, 0x00000a14, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1301c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13020, 0x00000a0a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13024, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13028, 0x00000a11, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1302c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13030, 0x00000a0c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13034, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13038, 0x00000a01, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1303c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13040, 0x00000a06, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13044, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13048, 0x00000a07, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1304c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13050, 0x00000a04, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13054, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13058, 0x00000a05, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1305c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13060, 0x00000a18, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13064, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13068, 0x00000a19, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1306c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13070, 0x00000a1a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13074, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a8, 0x00000a12, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b0, 0x00000a0e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b8, 0x00000a17, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c0, 0x00000a0d, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c8, 0x00000a15, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d0, 0x00000a16, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d8, 0x00000a02, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130dc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e0, 0x00000a03, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e8, 0x00000a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ec, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f0, 0x00000a0f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f8, 0x00000a10, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130fc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13300, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13304, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13500, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13504, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13700, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13704, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13308, 0x00006008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1330c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13508, 0x00006008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1350c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13708, 0x00006008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1370c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13310, 0x00006007, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13314, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13510, 0x00006007, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13514, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13710, 0x00006007, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13714, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13318, 0x00006014, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1331c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13518, 0x00006014, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1351c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13718, 0x00006014, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1371c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13320, 0x00006000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13324, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13520, 0x00006000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13524, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13720, 0x00006000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13724, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13328, 0x00006001, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1332c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13528, 0x00006001, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1352c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13728, 0x00006001, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1372c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13330, 0x00006015, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13334, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13530, 0x00006015, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13534, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13730, 0x00006015, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13734, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13338, 0x0000601c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1333c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13538, 0x0000601c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1353c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13738, 0x0000601c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1373c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13340, 0x0000601a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13344, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13540, 0x0000601a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13544, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13740, 0x0000601a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13744, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13348, 0x0000601b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1334c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13548, 0x0000601b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1354c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13748, 0x0000601b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1374c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CVectorEngineProfileMetricSet::CVectorEngineProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CVectorEngineProfileMetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "GPU_BUSY", "GPU Busy",
            "Percentage of time in which GPU is not idle including all GPU engines",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREADGROUP_COUNT", "Async GpGpu Threadgroup Count",
            "Number of Async GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_HIT", "ICache Hit",
            "Number of Instruction Cache hits",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ICACHE_MISS", "ICache Miss",
            "Number of Instruction Cache misses",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU0_ALL", "XVE Inst Executed ALU0 All",
            "Number of execution slots taken by instructions executed on ALU0 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU1_ALL", "XVE Inst Executed ALU1 All",
            "Number of execution slots taken by instructions executed on ALU1 pipe. Does not include extended math instructions.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_ALU2_ALL", "XVE Inst Executed ALU2 All",
            "Number of execution slots taken by instructions executed in ALU2 pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_BARRIER", "XVE Inst Executed Barrier",
            "Number of sync.bar and sync.host instructions executed",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_BITCONV", "XVE Inst Executed Bitconv",
            "Number of execution slots taken by bit manipulation instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 12 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_CONTROL_ALL", "XVE Inst Executed Control All",
            "Number of instructions executed on JEU Pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 13 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_FP16", "XVE Inst Executed Fp16",
            "Number of execution slots taken by FP16 ALU instructions. Does not include extended math instructions.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 14 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_FP32", "XVE Inst Executed Fp32",
            "Number of execution slots taken by FP32 ALU instructions. Does not include extended math instructions.",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 15 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_FP64", "XVE Inst Executed Fp64",
            "Number of execution slots taken by FP64 ALU instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 16 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_FP64_2ND", "XVE Inst Executed Fp64 2nd",
            "Number of execution slots taken by FP64 ALU instructions executed in the second pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 17 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_INT16", "XVE Inst Executed Int16",
            "Number of execution slots taken by INT16 ALU instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 18 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_INT32", "XVE Inst Executed Int32",
            "Number of execution slots taken by INT32 ALU instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 19 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_INT64", "XVE Inst Executed Int64",
            "Number of execution slots taken by INT64 instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 20 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_MATH", "XVE Inst Executed Math",
            "Number of execution slots taken by extended math instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 21 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_NONDIVERGENT", "XVE Inst Executed Nondivergent",
            "Number of non-divergent instructions (not execution slots) executed",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 22 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_PREDICATION", "XVE Inst Executed Predication",
            "Number of instructions (not execution slots) executed with predication mask enabled",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 23 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_SEND_ALL", "XVE Inst Executed Send All",
            "Number of instruction (GRF or SRF) dispatches executed on SEND Pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 24 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_BF16", "XVE Inst Executed XMX Bf16",
            "Number of execution slots taken by BF16 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 25 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_FP16", "XVE Inst Executed XMX Fp16",
            "Number of execution slots taken by FP16 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 26 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_INT4", "XVE Inst Executed XMX Int4",
            "Number of execution slots taken by INT4 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 27 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_INT8", "XVE Inst Executed XMX Int8",
            "Number of execution slots taken by INT8 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 28 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_ISSUED_ALL", "XVE Inst Issued All",
            "Number of instructions issued (decoded) to any pipe",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 29 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_THREADS_OCCUPANCY_ALL", "XVE Threads Occupancy All",
            "Percentage of thread slots occupied",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 30 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x90 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x80 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_COMPUTE_ENGINE_BUSY", "Command Parser Compute Engine Busy",
            "Percentage of time in which there is a context loaded and active on the compute queue",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 31 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x128 $ComputeEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x118 $ComputeEngineTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "COMMAND_PARSER_COMPUTE_ENGINE_DISPATCH_KERNEL_COUNT", "Command Parser Compute Engine Dispatch Kernel Count",
            "Number of compute walker commands parsed on the compute engine",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 32 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x130" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_BF16", "XVE Inst Executed Bf16",
            "Number of execution slots taken by BF16 ALU instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 33 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_FP4", "XVE Inst Executed XMX Fp4",
            "Number of execution slots taken by FP4 XMX instruction",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 34 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_FP64", "XVE Inst Executed XMX Fp64",
            "Number of execution slots taken by FP64 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 35 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_INST_EXECUTED_XMX_FP8", "XVE Inst Executed XMX Fp8",
            "Number of execution slots taken by FP8 XMX instructions",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 36 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xb0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13000, 0x00001802, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13004, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13008, 0x00000622, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1300c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13010, 0x00000623, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13014, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13018, 0x0000060f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1301c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13020, 0x00000603, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13024, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13028, 0x00000614, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1302c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13030, 0x00000608, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13034, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13038, 0x00000609, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1303c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13040, 0x00000601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13044, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13048, 0x00000616, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1304c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13050, 0x00000615, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13054, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13058, 0x00000618, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1305c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13060, 0x00000617, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13064, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13068, 0x0000060b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1306c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13070, 0x00000604, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13074, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13078, 0x00000638, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1307c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13080, 0x00000639, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13084, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13088, 0x00000630, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1308c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13090, 0x00000631, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13094, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a8, 0x00000607, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b0, 0x00000602, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b8, 0x00000611, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c0, 0x00000610, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c8, 0x00000612, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d0, 0x00000629, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d8, 0x0000060c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130dc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e0, 0x0000060d, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e8, 0x00000613, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ec, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f0, 0x0000060e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f8, 0x0000060a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130fc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13300, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13304, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13500, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13504, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13700, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13704, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13308, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1330c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13508, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1350c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13708, 0x00005009, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1370c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13310, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13314, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13510, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13514, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13710, 0x00005008, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13714, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0xe558, 0x00000000, REGISTER_TYPE_FLEX ) );
        MD_CHECK_CC( AddStartConfigRegister( 0xe658, 0x00000000, REGISTER_TYPE_FLEX ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CVectorEngineStallsMetricSet::CVectorEngineStallsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CVectorEngineStallsMetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "GPU_BUSY", "GPU Busy",
            "Percentage of time in which GPU is not idle including all GPU engines",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREADGROUP_COUNT", "Async GpGpu Threadgroup Count",
            "Number of Async GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_ALUWR", "XVE Stall Aluwr",
            "Percentage of time in which XVE stalled, with at least one thread waiting for ALU to write GRF/ACC register. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_BARRIER", "XVE Stall Barrier",
            "Percentage of time in which XVE stalled, with at least one thread waiting for Gateway to write Notify register. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_CONTROL", "XVE Stall Control",
            "Percentage of time in which XVE stalled, with at least one thread waiting for JEU to complete branch instruction. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_INSTFETCH", "XVE Stall Instfetch",
            "Percentage of time in which XVE stalled, with at least one thread waiting for Instruction Fetch. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_OTHER", "XVE Stall Other",
            "Percentage of time in which XVE stalled, with at least one thread waiting on any other dependency (Flag/EoT etc). Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_PIPESTALL", "XVE Stall Pipestall",
            "Percentage of time in which XVE stalled, with at least one thread ready to be scheduled (Grf conf/send holds etc). Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_SBID", "XVE Stall Sbid",
            "Percentage of time in which XVE stalled, with at least one thread waiting for Scoreboard token to be available. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 12 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL_SENDWR", "XVE Stall Sendwr",
            "Percentage of time in which XVE stalled, with at least one thread waiting for SEND message to be dispatched from XVE. Multiple stall reasons can qualify during the same cycle",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 13 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_QUEUE0_ACTIVE", "Thread Dispatch Queue0 Active",
            "Percentage of time in which non-Pixel Shader threads are ready for dispatch in a particular Xe core",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, "Pixel|Fragment", nullptr, 14 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_QUEUE0_STALL", "Thread Dispatch Queue0 Stall",
            "Percentage of time in which queue 0 is stalled waiting for threads to be available",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 15 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_QUEUE1_ACTIVE", "Thread Dispatch Queue1 Active",
            "Percentage of time in which non-Pixel Shader threads are ready for dispatch in a particular Xe core",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, "Pixel|Fragment", nullptr, 16 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_QUEUE1_STALL", "Thread Dispatch Queue1 Stall",
            "Percentage of time in which queue 1 is stalled waiting for threads to be available",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 17 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREADGROUP_DISPATCH_QUEUE0_RESOURCE_STALL", "Threadgroup Dispatch Queue0 Resource Stall",
            "Percentage of time in which Thread Spawner queue 0 is stalled waiting for any resource to be available (for example, SLM, Barrier, BTD stack, etc.)",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 18 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREADGROUP_DISPATCH_QUEUE1_RESOURCE_STALL", "Threadgroup Dispatch Queue1 Resource Stall",
            "Percentage of time in which Thread Spawner queue 1 is stalled waiting for any resource to be available (for example, SLM, Barrier, BTD stack, etc.)",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 19 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x100 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_ACTIVE", "XVE Active",
            "Percentage of time in which at least one pipe is active in XVE",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 20 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_SHARED_FUNCTION_ACCESS_HOLD", "XVE Shared Function Access Hold",
            "Percentage of time in which XVE requests stalled by Shared Function units",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 21 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_STALL", "XVE Stall",
            "Percentage of time in which any thread loaded but not even a single pipe is active in XVE",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 22 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_THREADS_OCCUPANCY_ALL", "XVE Threads Occupancy All",
            "Percentage of thread slots occupied",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 23 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48 $VectorEngineThreadsCount $VectorEngineTotalCount UMUL UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_MULTIPLE_PIPE_ACTIVE", "XVE Multiple Pipe Active",
            "Percentage of time in which at least two pipes are actively executing a Gen ISA instruction among ALU0, ALU1, ALU2 and ALU3 pipes",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 24 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_PIPE_ALU0_AND_ALU1_ACTIVE", "XVE Pipe ALU0 And ALU1 Active",
            "Percentage of time in which ALU0 and ALU1 pipes are both actively executing a Gen ISA instruction",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 25 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "XVE_PIPE_ALU0_AND_ALU2_ACTIVE", "XVE Pipe ALU0 And ALU2 Active",
            "Percentage of time in which ALU0 and ALU2 pipes are both actively executing a Gen ISA instruction",
            "Vector Engine", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 26 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "EuAggrDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREAD_EXIT_COUNT", "Async GpGpu Thread Exit Count",
            "Number of Async GPGPU EOT messages received",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 27 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_GPGPU_COMMON_ENGINE", "Thread Dispatch GpGpu Common Engine",
            "Number of Common (non-Async)) GPGPU threads dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 28 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_GPGPU_COMPUTE_ENGINE", "Thread Dispatch GpGpu Compute Engine",
            "Number of Compute (Async) GPGPU threads dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 29 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_INPUT_AVAILABLE", "Thread Dispatch Input Available",
            "Percentage of time in which Thread Dispatch input is available",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 30 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x90 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x80 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREAD_DISPATCH_OTHER", "Thread Dispatch Other",
            "Number of threads dispatched that do not fit into any of the other identified groups. This group includes, at least, AMFS threads and may include other groups.",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 31 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREADGROUP_DISPATCH_QUEUE0_INPUT_AVAILABLE", "Threadgroup Dispatch Queue0 Input Available",
            "Percentage of time in which Thread Spawner has input available on queue 0",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 32 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa0 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x90 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "THREADGROUP_DISPATCH_QUEUE1_INPUT_AVAILABLE", "Threadgroup Dispatch Queue1 Input Available",
            "Percentage of time in which Thread Spawner has input available on queue 1",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 33 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa8 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x98 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13000, 0x00001802, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13004, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13008, 0x0000061d, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1300c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13010, 0x0000061b, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13014, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13018, 0x00000620, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1301c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13020, 0x0000061a, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13024, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13028, 0x00000621, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1302c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13030, 0x0000061f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13034, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13038, 0x00000604, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1303c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13040, 0x00000624, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13044, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13048, 0x00000625, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1304c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13050, 0x00000626, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13054, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13058, 0x00001804, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1305c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13060, 0x0000160f, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13064, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13068, 0x00001610, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1306c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13070, 0x00001605, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13074, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13078, 0x00001611, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1307c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13080, 0x00001805, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13084, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13088, 0x00001806, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1308c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a8, 0x0000061c, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b0, 0x0000061e, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b8, 0x00001601, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c0, 0x00001604, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c8, 0x00001602, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d0, 0x00001606, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d8, 0x00001807, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130dc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e0, 0x00001808, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e8, 0x00000605, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ec, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f0, 0x00000600, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f8, 0x00000606, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130fc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13300, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13304, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13500, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13504, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13700, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13704, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CTestOaMetricSet::CTestOaMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CTestOaMetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "GPU_BUSY", "GPU Busy",
            "Percentage of time in which GPU is not idle including all GPU engines",
            "Front End", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x120" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "GPGPU_THREADGROUP_COUNT", "GpGpu Threadgroup Count",
            "Number of GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "ASYNC_GPGPU_THREADGROUP_COUNT", "Async GpGpu Threadgroup Count",
            "Number of Async GPGPU threadgroups dispatched",
            "Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1", "Test Event1",
            "Number of GPU (gt) clock cycles at every clock period",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES", "Test Event1 Cycles",
            "Number of GPU (gt) clock cycles at every clock period",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE0", "Test Event1 Cycles Xecore0",
            "Number of GPU (gt) clock cycles at every clock period (XECORE0)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore0", nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE1", "Test Event1 Cycles Xecore1",
            "Number of GPU (gt) clock cycles at every clock period (XECORE1)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore1", nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE2", "Test Event1 Cycles Xecore2",
            "Number of GPU (gt) clock cycles at every clock period (XECORE2)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore2", nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE3", "Test Event1 Cycles Xecore3",
            "Number of GPU (gt) clock cycles at every clock period (XECORE3)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore3", nullptr, nullptr, 12 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE4", "Test Event1 Cycles Xecore4",
            "Number of GPU (gt) clock cycles at every clock period (XECORE4)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore4", nullptr, nullptr, 13 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE5", "Test Event1 Cycles Xecore5",
            "Number of GPU (gt) clock cycles at every clock period (XECORE5)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore5", nullptr, nullptr, 14 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE6", "Test Event1 Cycles Xecore6",
            "Number of GPU (gt) clock cycles at every clock period (XECORE6)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore6", nullptr, nullptr, 15 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xc8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE7", "Test Event1 Cycles Xecore7",
            "Number of GPU (gt) clock cycles at every clock period (XECORE7)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore7", nullptr, nullptr, 16 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE8", "Test Event1 Cycles Xecore8",
            "Number of GPU (gt) clock cycles at every clock period (XECORE8)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore8", nullptr, nullptr, 17 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xd8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE9", "Test Event1 Cycles Xecore9",
            "Number of GPU (gt) clock cycles at every clock period (XECORE9)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore9", nullptr, nullptr, 18 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE10", "Test Event1 Cycles Xecore10",
            "Number of GPU (gt) clock cycles at every clock period (XECORE10)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore10", nullptr, nullptr, 19 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xe8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE11", "Test Event1 Cycles Xecore11",
            "Number of GPU (gt) clock cycles at every clock period (XECORE11)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore11", nullptr, nullptr, 20 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE12", "Test Event1 Cycles Xecore12",
            "Number of GPU (gt) clock cycles at every clock period (XECORE12)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore12", nullptr, nullptr, 21 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xf8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE13", "Test Event1 Cycles Xecore13",
            "Number of GPU (gt) clock cycles at every clock period (XECORE13)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore13", nullptr, nullptr, 22 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x110" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x100" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE14", "Test Event1 Cycles Xecore14",
            "Number of GPU (gt) clock cycles at every clock period (XECORE14)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore14", nullptr, nullptr, 23 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x108" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE15", "Test Event1 Cycles Xecore15",
            "Number of GPU (gt) clock cycles at every clock period (XECORE15)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore15", nullptr, nullptr, 24 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE16", "Test Event1 Cycles Xecore16",
            "Number of GPU (gt) clock cycles at every clock period (XECORE16)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore16", nullptr, nullptr, 25 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE17", "Test Event1 Cycles Xecore17",
            "Number of GPU (gt) clock cycles at every clock period (XECORE17)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore17", nullptr, nullptr, 26 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE18", "Test Event1 Cycles Xecore18",
            "Number of GPU (gt) clock cycles at every clock period (XECORE18)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore18", nullptr, nullptr, 27 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x60" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE19", "Test Event1 Cycles Xecore19",
            "Number of GPU (gt) clock cycles at every clock period (XECORE19)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore19", nullptr, nullptr, 28 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x68" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE20", "Test Event1 Cycles Xecore20",
            "Number of GPU (gt) clock cycles at every clock period (XECORE20)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore20", nullptr, nullptr, 29 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x70" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE21", "Test Event1 Cycles Xecore21",
            "Number of GPU (gt) clock cycles at every clock period (XECORE21)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore21", nullptr, nullptr, 30 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x78" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE22", "Test Event1 Cycles Xecore22",
            "Number of GPU (gt) clock cycles at every clock period (XECORE22)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore22", nullptr, nullptr, 31 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x80" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE23", "Test Event1 Cycles Xecore23",
            "Number of GPU (gt) clock cycles at every clock period (XECORE23)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore23", nullptr, nullptr, 32 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x88" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE24", "Test Event1 Cycles Xecore24",
            "Number of GPU (gt) clock cycles at every clock period (XECORE24)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore24", nullptr, nullptr, 33 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x90" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE25", "Test Event1 Cycles Xecore25",
            "Number of GPU (gt) clock cycles at every clock period (XECORE25)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore25", nullptr, nullptr, 34 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xa8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x98" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE26", "Test Event1 Cycles Xecore26",
            "Number of GPU (gt) clock cycles at every clock period (XECORE26)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore26", nullptr, nullptr, 35 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xb0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xa0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE27", "Test Event1 Cycles Xecore27",
            "Number of GPU (gt) clock cycles at every clock period (XECORE27)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore27", nullptr, nullptr, 36 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xb8" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xa8" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_XECORE28", "Test Event1 Cycles Xecore28",
            "Number of GPU (gt) clock cycles at every clock period (XECORE28)",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, "$GtXeCore28", nullptr, nullptr, 37 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0xc0" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0xb0" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT1_CYCLES_AVERAGE", "Test Event1 Cycles Average",
            "Average number of GPU (gt) clock cycles at every clock period",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 38 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20 $XeCoreTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_RENDER | QUERY_MODE_MASK_COMPUTE | QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT2", "Test Event2",
            "Number of GPU (gt) clock cycles at every other clock period",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 39 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x128 $SliceTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x118 $SliceTotalCount UDIV" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        metric = AddMetric( "TEST_EVENT2_CYCLES", "Test Event2 Cycles",
            "Number of GPU (gt) clock cycles at every other clock period",
            "Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 40 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x128" ) );
        MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x118" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );
        metric->SetQueryModeMask( QUERY_MODE_MASK_GLOBAL | QUERY_MODE_MASK_GLOBAL_EXTENDED );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13000, 0x00001801, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13004, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13008, 0x00001802, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1300c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13010, 0x00003e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13014, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13018, 0x00013e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1301c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13020, 0x00113e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13024, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13028, 0x00213e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1302c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13030, 0x00313e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13034, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13038, 0x00f13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1303c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13040, 0x01013e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13044, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13048, 0x01113e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1304c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13050, 0x01213e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13054, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13058, 0x01313e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1305c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13060, 0x01413e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13064, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13068, 0x01513e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1306c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13070, 0x01613e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13074, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13078, 0x01713e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1307c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13080, 0x01813e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13084, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13088, 0x01913e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1308c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13090, 0x01a13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13094, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13098, 0x01b13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1309c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a0, 0x01c13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130a8, 0x00413e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ac, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b0, 0x00513e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130b8, 0x00613e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130bc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c0, 0x00713e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130c8, 0x00813e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130cc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d0, 0x00913e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130d8, 0x00a13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130dc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e0, 0x00b13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130e8, 0x00c13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130ec, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f0, 0x00d13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f4, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130f8, 0x00e13e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x130fc, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13300, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13304, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13500, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13504, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13700, 0x00005a00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13704, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13308, 0x00007e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1330c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13508, 0x00007e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1350c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x13708, 0x00007e00, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x1370c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

} // namespace MetricsDiscoveryInternal::MetricSets_CRI_OA

namespace MetricsDiscoveryInternal::MetricSets_CRI_OAM0
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;

        information = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( information->SetOverflowFunction( "NS_TIME" ) );

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 1 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x7f AND" ) );

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 2 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" ) );

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 3 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x10 dw@0x0 22 >> 0x1 AND UMUL" ) );

        information = concurrentGroup->AddInformation( "SourceId", "SourceId", "SourceId", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 4 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 26 >> 0x3f AND" ) );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CMediaSet1MetricSet::CMediaSet1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CMediaSet1MetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0, 0, 0, "", 0, "", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Media Clocks",
            "The total number of media slice clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Media Frequency",
            "Average GPU Media Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "MEDIA_READ_REQUEST", "Media Read Request",
            "Number of read requests from stand alone media",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "MEDIA_WRITE_REQUEST", "Media Write Request",
            "Number of write requests from stand alone media",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_DECODE_ENGINE0_BUSY", "Command Parser Video Decode Engine0 Busy",
            "Number of VCS0 (VDBOX0) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX0_READ_REQUEST", "Video Decode Box0 Read Request",
            "Number of VDBOX0 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX0_WRITE_REQUEST", "Video Decode Box0 Write Request",
            "Number of VDBOX0 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_DECODE_ENGINE1_BUSY", "Command Parser Video Decode Engine1 Busy",
            "Number of VCS1 (VDBOX1) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX1_READ_REQUEST", "Video Decode Box1 Read Request",
            "Number of VDBOX1 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX1_WRITE_REQUEST", "Video Decode Box1 Write Request",
            "Number of VDBOX1 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394200, 0x00000001, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394204, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394208, 0x00000002, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39420c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394210, 0x00000200, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394214, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394218, 0x00000201, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39421c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394220, 0x00000202, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394224, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394228, 0x00000400, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39422c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394230, 0x00000401, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394234, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394238, 0x00000402, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39423c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CMediaSet2MetricSet::CMediaSet2MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CMediaSet2MetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0, 0, 0, "", 0, "", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Media Clocks",
            "The total number of media slice clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Media Frequency",
            "Average GPU Media Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_ENHANCEMENT_ENGINE0_BUSY", "Command Parser Video Enhancement Engine0 Busy",
            "Number of VECS0 (VEBOX0) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX0_READ_REQUEST", "Video Enhancement Box0 Read Request",
            "Number of VEBOX0 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX0_WRITE_REQUEST", "Video Enhancement Box0 Write Request",
            "Number of VEBOX0 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_ENHANCEMENT_ENGINE1_BUSY", "Command Parser Video Enhancement Engine1 Busy",
            "Number of VECS1 (VEBOX1) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX1_READ_REQUEST", "Video Enhancement Box1 Read Request",
            "Number of VEBOX1 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX1_WRITE_REQUEST", "Video Enhancement Box1 Write Request",
            "Number of VEBOX1 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394200, 0x00002200, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394204, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394208, 0x00002201, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39420c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394210, 0x00002202, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394214, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394218, 0x00002400, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39421c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394220, 0x00002401, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394224, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394228, 0x00002402, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x39422c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

} // namespace MetricsDiscoveryInternal::MetricSets_CRI_OAM0

namespace MetricsDiscoveryInternal::MetricSets_CRI_OAM1
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;

        information = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( information->SetOverflowFunction( "NS_TIME" ) );

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 1 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x7f AND" ) );

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 2 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" ) );

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 3 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x10 dw@0x0 22 >> 0x1 AND UMUL" ) );

        information = concurrentGroup->AddInformation( "SourceId", "SourceId", "SourceId", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 4 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 26 >> 0x3f AND" ) );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CMediaSet1MetricSet::CMediaSet1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CMediaSet1MetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0, 0, 0, "", 0, "", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Media Clocks",
            "The total number of media slice clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Media Frequency",
            "Average GPU Media Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "MEDIA_READ_REQUEST", "Media Read Request",
            "Number of read requests from stand alone media",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "MEDIA_WRITE_REQUEST", "Media Write Request",
            "Number of write requests from stand alone media",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_DECODE_ENGINE0_BUSY", "Command Parser Video Decode Engine0 Busy",
            "Number of VCS0 (VDBOX0) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX0_READ_REQUEST", "Video Decode Box0 Read Request",
            "Number of VDBOX0 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX0_WRITE_REQUEST", "Video Decode Box0 Write Request",
            "Number of VDBOX0 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_DECODE_ENGINE1_BUSY", "Command Parser Video Decode Engine1 Busy",
            "Number of VCS1 (VDBOX1) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX1_READ_REQUEST", "Video Decode Box1 Read Request",
            "Number of VDBOX1 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 10 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x50" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_DECODE_BOX1_WRITE_REQUEST", "Video Decode Box1 Write Request",
            "Number of VDBOX1 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 11 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x58" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a00, 0x00000001, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a04, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a08, 0x00000002, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a0c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a10, 0x00000200, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a14, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a18, 0x00000201, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a1c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a20, 0x00000202, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a24, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a28, 0x00000400, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a2c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a30, 0x00000401, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a34, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a38, 0x00000402, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a3c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CMediaSet2MetricSet::CMediaSet2MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CMediaSet2MetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0, 0, 0, "", 0, "", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Media Clocks",
            "The total number of media slice clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Media Frequency",
            "Average GPU Media Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_ENHANCEMENT_ENGINE0_BUSY", "Command Parser Video Enhancement Engine0 Busy",
            "Number of VECS0 (VEBOX0) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX0_READ_REQUEST", "Video Enhancement Box0 Read Request",
            "Number of VEBOX0 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 5 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x28" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX0_WRITE_REQUEST", "Video Enhancement Box0 Write Request",
            "Number of VEBOX0 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 6 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x30" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "COMMAND_PARSER_VIDEO_ENHANCEMENT_ENGINE1_BUSY", "Command Parser Video Enhancement Engine1 Busy",
            "Number of VECS1 (VEBOX1) activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 7 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x38" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX1_READ_REQUEST", "Video Enhancement Box1 Read Request",
            "Number of VEBOX1 read requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 8 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x40" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "VIDEO_ENHANCEMENT_BOX1_WRITE_REQUEST", "Video Enhancement Box1 Write Request",
            "Number of VEBOX1 write requests",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 9 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x48" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a00, 0x00002200, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a04, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a08, 0x00002201, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a0c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a10, 0x00002202, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a14, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a18, 0x00002400, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a1c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a20, 0x00002401, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a24, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a28, 0x00002402, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x394a2c, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

} // namespace MetricsDiscoveryInternal::MetricSets_CRI_OAM1

namespace MetricsDiscoveryInternal::MetricSets_CRI_OAMG
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;

        information = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( information->SetOverflowFunction( "NS_TIME" ) );

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 1 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x7f AND" ) );

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 2 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" ) );

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 3 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "qw@0x10 dw@0x0 22 >> 0x1 AND UMUL" ) );

        information = concurrentGroup->AddInformation( "SourceId", "SourceId", "SourceId", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 4 );
        MD_CHECK_PTR( information );
        MD_CHECK_CC( information->SetSnapshotReportReadEquation( "dw@0x0 26 >> 0x3f AND" ) );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

    CMediaSet1MetricSet::CMediaSet1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }

    TCompletionCode CMediaSet1MetricSet::Initialize()
    {
        CMetric* metric           = nullptr;
        m_params.InformationCount = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0, 0, 0, "", 0, "", 0 ) );

        metric = AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 0 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x08 100 UMUL $GpuTimestampFrequency 100000 UDIV UDIV 100 UMUL" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) );

        metric = AddMetric( "GpuCoreClocks", "GPU Media Clocks",
            "The total number of media slice clocks elapsed during the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 1 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x18" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        metric = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Media Frequency",
            "Average GPU Media Frequency in the measurement.",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 2 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) );

        metric = AddMetric( "ResultUncertainty", "Result Uncertainty",
            "Result uncertainty indicator",
            "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 3 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetNormalizationEquation( "100 $GpuCoreClocks 500 UMAX 5000 UMIN 500 USUB 45 UDIV USUB" ) );

        metric = AddMetric( "COMMAND_PARSER_GRAPHICS_SECURITY_CONTROLLER_BUSY", "Command Parser Graphics Security Controller Busy",
            "Number of GSCCS activities",
            "Media", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, nullptr, nullptr, nullptr, 4 );
        MD_CHECK_PTR( metric );
        MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x20" ) );
        MD_CHECK_CC( metric->SetNormalizationEquation( "GpuDuration" ) );
        MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ) );

        MD_CHECK_CC( AddStartRegisterSet( 0, 0, nullptr ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x393200, 0x00000003, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( AddStartConfigRegister( 0x393204, 0x00000000, REGISTER_TYPE_OA ) );
        MD_CHECK_CC( RefreshConfigRegisters() );

        return CC_OK;

    exception:
        return CC_ERROR_GENERAL;
    }

} // namespace MetricsDiscoveryInternal::MetricSets_CRI_OAMG

#endif
