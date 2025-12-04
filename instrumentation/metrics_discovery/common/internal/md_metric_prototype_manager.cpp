/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_prototype_manager.cpp
//
//     Abstract:   C++ Metrics Discovery internal metric prototype manager implementation

#include "md_adapter.h"
#include "md_metric.h"
#include "md_concurrent_group.h"
#include "md_metric_set.h"
#include "md_metric_prototype.h"
#include "md_metric_prototype_manager.h"
#include "md_utils.h"

#include <sstream>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     CPrototypeManager constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice& device    - metrics device
    //     CMetricSet&     metricSet - metric set related to the prototype manager
    //
    //////////////////////////////////////////////////////////////////////////////
    CPrototypeManager::CPrototypeManager( CMetricsDevice& device, CMetricSet& metricSet )
        : m_device( device )
        , m_set( metricSet )
        , m_deltaCounterSize( sizeof( uint64_t ) )
        , m_snapshotCounterSize( ( m_set.GetReportType() == OA_REPORT_TYPE_128B_MPEC8_NOA16 || m_set.GetReportType() == OA_REPORT_TYPE_320B_PEC64 ) ? sizeof( uint32_t ) : sizeof( uint64_t ) )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     AddPrototype
    //
    // Description:
    //     Adds a prototype to a metric set if all constraints are met.
    //
    // Input:
    //     CMetricPrototype& prototype - a prototype to be added
    //
    // Output:
    //     TCompletionCode             - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::AddPrototype( CMetricPrototype& prototype )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        // Do not accept already added prototypes or prototypes with same symbol names.
        if( IsPrototypeAlreadyAdded( prototype ) )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "Prototype is already added to the metric set" );
            return CC_ERROR_INVALID_PARAMETER;
        }
        // Check group constrains
        auto result = AddHwEvent( prototype );

        if( result != CC_OK )
        {
            return result;
        }

        prototype.IncreaseReferenceCounter();

        m_metricPrototypes.push_back( &prototype );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     RemovePrototype
    //
    // Description:
    //     Removes a prototype from a metric set.
    //
    // Input:
    //     CMetricPrototype& prototype - a prototype to be removed
    //
    // Output:
    //     TCompletionCode             - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::RemovePrototype( CMetricPrototype& prototype )
    {
        auto metricPrototypeIterator = std::find( m_metricPrototypes.begin(), m_metricPrototypes.end(), &prototype );

        if( metricPrototypeIterator == m_metricPrototypes.end() || !( *metricPrototypeIterator )->CanBeDeleted() )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        auto result = RemoveHwEvent( prototype );
        if( result != CC_OK )
        {
            return result;
        }

        m_metricPrototypes.erase( metricPrototypeIterator );

        prototype.DecreaseReferenceCounter();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     CreateMetricsFromPrototypes
    //
    // Description:
    //     Creates metrics and their equations from prototypes.
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::CreateMetricsFromPrototypes()
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        uint32_t          flexProgramming[] = { 0, 0, 0, 0, 0, 0, 0 };
        std::vector<bool> pesProgrammed( GetMaxPesCount() );

        uint32_t metricIndex = m_set.GetParams()->MetricsCount;

        for( auto& metricPrototype : m_metricPrototypes )
        {
            CMetric* metric = AddMetricToSet( *metricPrototype, metricIndex++ );

            MD_CHECK_PTR_RET_A( adapterId, metric, CC_ERROR_NO_MEMORY );

            const auto& hwEvent = metricPrototype->GetHwEvent();

            const uint64_t pesProgramming = hwEvent.m_archEvent.m_eventEncoding | hwEvent.m_disaggregationMask;

            uint32_t snapshotReportOffsets = 0;
            uint32_t deltaReportOffsets    = 0;

            MD_CHECK_CC( AppendPesConfiguration( hwEvent, pesProgramming, pesProgrammed, flexProgramming, snapshotReportOffsets, deltaReportOffsets ) );

            MD_CHECK_CC( AddEquations( *metricPrototype, *metric, snapshotReportOffsets, deltaReportOffsets ) );
        }

        MD_CHECK_CC( AppendFlexConfiguration( flexProgramming ) );

        return CC_OK;

    exception:
        MD_LOG_A( adapterId, LOG_ERROR, "Failed to create metrics and their equations from prototypes" );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     DecreasePrototypesReferenceCounters
    //
    // Description:
    //     Decreases reference counters for all metric prototypes added to the
    //     metric set.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CPrototypeManager::DecreasePrototypesReferenceCounters()
    {
        for( auto prototype : m_metricPrototypes )
        {
            prototype->DecreaseReferenceCounter();
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     IsEmpty
    //
    // Description:
    //     Returns true if there are no added prototypes.
    //
    // Output:
    //     bool - true if there are no added prototypes, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CPrototypeManager::IsEmpty()
    {
        return m_metricPrototypes.empty();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AddHwEvent
    //
    // Description:
    //     Adds a hw event from a given prototype if all constraints are met.
    //
    // Input:
    //     CMetricPrototype& prototype - a metric prototype
    //
    // Output:
    //     TCompletionCode             - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::AddHwEvent( CMetricPrototype& prototype )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
        const auto&    hwEvent   = prototype.GetHwEvent();
        const auto     group     = GetHwEventGroup( hwEvent );

        uint32_t            maxSize    = GetGroupMaxSize( group );
        THwEventPairVector* eventGroup = nullptr;

        switch( group )
        {
            case HW_EVENT_GROUP_FIRST:
                eventGroup = &m_firstEventGroup;
                break;

            case HW_EVENT_GROUP_SECOND:
                eventGroup = &m_secondEventGroup;
                break;

            case HW_EVENT_GROUP_FLEX:
                eventGroup = &m_flexEventGroup;
                break;

            default:
                MD_ASSERT_A( adapterId, false );
                return CC_ERROR_GENERAL;
        }

        if( !AddHwEvent( *eventGroup, maxSize, hwEvent ) )
        {
            // Try to add to flex group if the first group is full.
            const uint32_t flexGroupMaxSize = GetGroupMaxSize( HW_EVENT_GROUP_FLEX );

            if( flexGroupMaxSize > 0 && group == HW_EVENT_GROUP_FIRST )
            {
                if( !AddHwEvent( m_flexEventGroup, flexGroupMaxSize, hwEvent ) )
                {
                    MD_LOG_A( adapterId, LOG_WARNING, "Group %u is full", HW_EVENT_GROUP_FLEX );
                    return CC_ERROR_GENERAL;
                }
            }
            else
            {
                MD_LOG_A( adapterId, LOG_WARNING, "Group %u is full", group );
                return CC_ERROR_GENERAL;
            }
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     RemoveHwEvent
    //
    // Description:
    //     Removes a hw event from a given prototype.
    //
    // Input:
    //     CMetricPrototype& prototype - a metric prototype
    //
    // Output:
    //     TCompletionCode             - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::RemoveHwEvent( CMetricPrototype& prototype )
    {
        // Remove hw events from corresponding groups.
        const auto& hwEvent = prototype.GetHwEvent();
        return RemoveHwEvent( hwEvent ) ? CC_OK : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Method:
    //     IsPrototypeAlreadyAdded
    //
    // Description:
    //     Returns true if a given prototype has already been added.
    //
    // Input:
    //     const CMetricPrototype& prototype - a prototype to be checked
    //
    // Output:
    //     bool - true if a given prototype has already been added, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CPrototypeManager::IsPrototypeAlreadyAdded( const CMetricPrototype& prototype )
    {
        auto metricPrototypeIterator = std::find_if(
            m_metricPrototypes.begin(),
            m_metricPrototypes.end(),
            [&prototype]( const CMetricPrototype* addedPrototype )
            {
                if( addedPrototype != &prototype )
                {
                    std::string_view addedPrototypeSymbolName = addedPrototype->GetParams()->SymbolName;
                    std::string_view prototypeSymbolName      = prototype.GetParams()->SymbolName;

                    return addedPrototypeSymbolName == prototypeSymbolName;
                }

                return true;
            } );

        return metricPrototypeIterator != m_metricPrototypes.end();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AddHwEvent
    //
    // Description:
    //     Adds hw event to a vector to check if a given group is full.
    //
    // Input:
    //     THwEventPairVector& group   - a group hw event will be added.
    //     const uint32_t      maxSize - max size of the group.
    //     const THwEvent*     hwEvent - a hw event to be added.
    //
    // Output:
    //     bool - true if hw event was successfully added, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CPrototypeManager::AddHwEvent( THwEventPairVector& group, const uint32_t maxSize, const THwEvent& hwEvent )
    {
        // Check if already added.
        auto hwEventPair = GetHwEventIteratorFromGroup( group, hwEvent );

        if( hwEventPair != group.end() )
        {
            // Already added. Increase usage and continue the loop.
            hwEventPair->second++;

            return true;
        }

        // Add hw event if there is a space.
        if( group.size() < maxSize )
        {
            group.emplace_back( &hwEvent, 1 );
            return true;
        }
        else
        {
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     RemoveHwEvent
    //
    // Description:
    //     Removes hw event from a vector.
    //
    // Input:
    //     const THwEvent* hwEvent - a hw event pointer to remove from metric set.
    //
    // Output:
    //     bool - true if hw event was successfully removed, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CPrototypeManager::RemoveHwEvent( const THwEvent& hwEvent )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        // Search for a given hw event in first group.
        auto hwEventToRevertIterator = GetHwEventIteratorFromGroup( m_firstEventGroup, hwEvent );

        if( hwEventToRevertIterator != m_firstEventGroup.end() )
        {
            // Decrease usage.
            hwEventToRevertIterator->second--;

            // Remove hw event from the group if the event was used once.
            if( hwEventToRevertIterator->second == 0 )
            {
                m_firstEventGroup.erase( hwEventToRevertIterator );
            }

            return true;
        }

        // Search for a given hw event in second group.
        hwEventToRevertIterator = GetHwEventIteratorFromGroup( m_secondEventGroup, hwEvent );

        if( hwEventToRevertIterator != m_secondEventGroup.end() )
        {
            // Decrease usage.
            hwEventToRevertIterator->second--;

            // Remove hw event from the group if the event was used once.
            if( hwEventToRevertIterator->second == 0 )
            {
                m_secondEventGroup.erase( hwEventToRevertIterator );
            }

            return true;
        }

        // Search for a given hw event in flex group.
        hwEventToRevertIterator = GetHwEventIteratorFromGroup( m_flexEventGroup, hwEvent );

        if( hwEventToRevertIterator != m_flexEventGroup.end() )
        {
            // Decrease usage.
            hwEventToRevertIterator->second--;

            // Remove hw event from the group if the event was used once.
            if( hwEventToRevertIterator->second == 0 )
            {
                m_flexEventGroup.erase( hwEventToRevertIterator );
            }

            return true;
        }

        MD_LOG_A( adapterId, LOG_WARNING, "Cannot find hw event to remove it" );

        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetHwEventIteratorFromGroup
    //
    // Description:
    //     Returns a hw event pair from a given hw event group.
    //
    // Input:
    //     THwEventPairVector& group   - a hw event group.
    //     const THwEvent*     hwEvent - a hw event to be searched.
    //
    // Output:
    //     THwEventPairIterator - a hw event pair iterator.
    //
    //////////////////////////////////////////////////////////////////////////////
    CPrototypeManager::THwEventPairIterator CPrototypeManager::GetHwEventIteratorFromGroup( THwEventPairVector& group, const THwEvent& hwEvent )
    {
        auto hwEventIterator = std::find_if(
            group.begin(),
            group.end(),
            [&]( const THwEventPair& pair )
            {
                auto& event = *pair.first;

                return event.m_archEvent.m_eventEncoding == hwEvent.m_archEvent.m_eventEncoding &&
                    event.m_disaggregationMask == hwEvent.m_disaggregationMask &&
                    event.m_filterValue == hwEvent.m_filterValue;
            } );

        return hwEventIterator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AddMetricToSet
    //
    // Description:
    //     Creates a metric from a metric prototype and adds it to the metric set.
    //
    // Input:
    //     const CMetricPrototype& prototype   - a metric prototype.
    //     const uint32_t          metricIndex - a metric index in the set.
    //
    // Output:
    //     CMetric*                            - a pointer to the newly created metric.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric* CPrototypeManager::AddMetricToSet( const CMetricPrototype& prototype, const uint32_t metricIndex )
    {
        const auto& params = *prototype.GetParams();

        CMetric* metric = m_set.AddMetric(
            params.SymbolName,
            params.ShortName,
            params.LongName,
            params.GroupName,
            0, // groupId
            params.UsageFlagsMask,
            params.ApiMask,
            params.MetricType,
            params.ResultType,
            params.MetricResultUnits,
            0, // loWatermark
            0, // hiWatermark
            params.HwUnitType,
            nullptr,           // availabilityEquation
            nullptr,           // alias
            params.SymbolName, // signalName
            metricIndex,
            true ); // isCustom

        if( metric )
        {
            metric->SetQueryModeMask( params.QueryModeMask );
        }

        return metric;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AddEquations
    //
    // Description:
    //     Appends report offset equations to the newly created metric.
    //
    // Input:
    //     CMetricPrototype& prototype            - a metric prototype.
    //     CMetric&          metric               - a newly metric.
    //     const uint32_t    snapshotReportOffset - snapshot report offset for the metric.
    //     const uint32_t    deltaReportOffset    - delta report offset for the metric.
    //
    // Output:
    //     TCompletionCode                        - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::AddEquations( CMetricPrototype& prototype, CMetric& metric, const uint32_t snapshotReportOffset, const uint32_t deltaReportOffset )
    {
        TCompletionCode ret       = CC_OK;
        const uint32_t  adapterId = m_device.GetAdapter().GetAdapterId();

        // Snapshot report read equation.
        std::stringstream snapshotReportReadEquation;
        if( m_snapshotCounterSize == sizeof( uint64_t ) )
        {
            snapshotReportReadEquation << "qw@0x" << std::hex << snapshotReportOffset;
            ret = metric.SetSnapshotReportDeltaFunction( "DELTA 64" );
            MD_CHECK_CC_RET_A( adapterId, ret );
        }
        else
        {
            snapshotReportReadEquation << "dw@0x" << std::hex << snapshotReportOffset;
            ret = metric.SetSnapshotReportDeltaFunction( "DELTA 32" );
            MD_CHECK_CC_RET_A( adapterId, ret );
        }

        // Delta report read equation.
        std::stringstream deltaReportReadEquation;
        deltaReportReadEquation << "qw@0x" << std::hex << deltaReportOffset;

        // Get equations for enabled options and workarounds.
        ret = AppendNormalizationsAndWorkarounds( prototype, metric, snapshotReportReadEquation, deltaReportReadEquation );
        MD_CHECK_CC_RET_A( adapterId, ret );

        // Set snapshot and delta report read equations.
        ret = metric.SetSnapshotReportReadEquation( ( snapshotReportOffset != 0 ) ? snapshotReportReadEquation.str().c_str() : "" );
        MD_CHECK_CC_RET_A( adapterId, ret );

        ret = metric.SetDeltaReportReadEquation( ( deltaReportOffset != 0 ) ? deltaReportReadEquation.str().c_str() : "" );
        MD_CHECK_CC_RET_A( adapterId, ret );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AppendNormalizationsAndWorkarounds
    //
    // Description:
    //     Appends normalization and workaround equations to the newly created metric.
    //
    // Input:
    //     CMetricPrototype&  prototype                  - a metric prototype.
    //     CMetric&           metric                     - a newly metric.
    //     std::stringstream& snapshotReportReadEquation - snapshot report read equation to be modified.
    //     std::stringstream& deltaReportReadEquation    - delta report read equation to be modified.
    //
    // Output:
    //     TCompletionCode                               - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CPrototypeManager::AppendNormalizationsAndWorkarounds( CMetricPrototype& prototype, CMetric& metric, std::stringstream& snapshotReportReadEquation, std::stringstream& deltaReportReadEquation )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        // Enabled options.
        const auto& hwEvent        = prototype.GetHwEvent();
        const auto& appliedOptions = prototype.GetAppliedOptions();

        const bool isDisaggregationEnabled = std::find( appliedOptions.begin(), appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_DISAGGREGATION ) != appliedOptions.end();
        const bool isUtilizationEnabled    = std::find( appliedOptions.begin(), appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ) != appliedOptions.end();
        const bool isAverageEnabled        = std::find( appliedOptions.begin(), appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE ) != appliedOptions.end();
        const bool isRateEnabled           = std::find( appliedOptions.begin(), appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE ) != appliedOptions.end();
        const bool isByteEnabled           = std::find( appliedOptions.begin(), appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE ) != appliedOptions.end();

        // Apply workarounds if any.
        switch( auto& archWorkaround = hwEvent.m_archEvent.m_workaround;
            archWorkaround.m_type )
        {
            case EVENT_WORKAROUND_TYPE_ALL_COUNTERS:
                snapshotReportReadEquation << ' ' << hwEvent.m_archEvent.m_workaround.m_equation;
                deltaReportReadEquation << ' ' << hwEvent.m_archEvent.m_workaround.m_equation;
                break;

            default:
                // Nothing on purpose.
                break;
        }

        switch( auto& hwWorkaround = hwEvent.m_workaround;
            hwWorkaround.m_type )
        {
            case EVENT_WORKAROUND_TYPE_ALL_COUNTERS:
                snapshotReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                deltaReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                break;

            case EVENT_WORKAROUND_TYPE_DISAGGREGATED_ONLY:
                if( isDisaggregationEnabled )
                {
                    snapshotReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                    deltaReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                }
                break;

            case EVENT_WORKAROUND_TYPE_UTILIZATION_ONLY:
                if( isUtilizationEnabled )
                {
                    snapshotReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                    deltaReportReadEquation << ' ' << hwEvent.m_workaround.m_equation;
                }
                break;

            default:
                // Nothing on purpose.
                break;
        }

        // Normalization equations.
        const std::string& instance = hwEvent.m_archEvent.m_instance;

        if( isUtilizationEnabled || isAverageEnabled )
        {
            if( isUtilizationEnabled )
            {
                // Metric is calculated using the following normalization equation:
                // metric = event * 100% / cycles / instance_count
                // Metric unit is updated to percent.
                // Max value is set to 100%.
                MD_CHECK_CC( metric.SetMaxValueEquation( "100" ) );

                if( isRateEnabled || isByteEnabled )
                {
                    // Utilization and rate or byte normalizations do not make sense. We do not expose prototypes with these both options available.
                    MD_ASSERT_A( adapterId, false );
                }

                if( ( instance == "eu" || instance == "thread" ) && !isDisaggregationEnabled )
                {
                    // Use built-in vector engine normalization equation: $Self $GpuCoreClocks $VectorEngineTotalCount UMUL FDIV 100 FMUL
                    MD_CHECK_CC( metric.SetNormalizationEquation( "EuAggrDuration" ) );
                }
                else
                {
                    // Use standard gpu core clocks normalization equation: $Self $GpuCoreClocks FDIV 100 FMUL
                    MD_CHECK_CC( metric.SetNormalizationEquation( "GpuDuration" ) );
                }
            }
            else // Average.
            {
                if( isByteEnabled )
                {
                    // Metric is calculated using the following normalization equation:
                    // metric = event * 64
                    // Metric unit is updated to bytes.
                    // Max value is not used.
                    MD_CHECK_CC( metric.SetNormalizationEquation( "$Self 64 UMUL" ) );
                }

                // Metric is calculated using the following normalization equation:
                // metric = event / instance_count
                // Metric unit is not updated.
                // Max value is not used.

                if( instance == "" )
                {
                    // There is no metric prototype that supports average normalization and has no instance.
                    MD_ASSERT_A( adapterId, false );
                }
            }
            // Divide by the number of instances if disaggregation is disabled.
            if( !isDisaggregationEnabled )
            {
                if( instance == "xecore" )
                {
                    snapshotReportReadEquation << " $XeCoreTotalCount UDIV";
                    deltaReportReadEquation << " $XeCoreTotalCount UDIV";
                }
                else if( instance == "l3bank" )
                {
                    snapshotReportReadEquation << " $L3BankTotalCount UDIV";
                    deltaReportReadEquation << " $L3BankTotalCount UDIV";
                }
                else if( instance == "slice" )
                {
                    snapshotReportReadEquation << " $SliceTotalCount UDIV";
                    deltaReportReadEquation << " $SliceTotalCount UDIV";
                }
                else if( instance == "sqidi" )
                {
                    snapshotReportReadEquation << " $SqidiTotalCount UDIV";
                    deltaReportReadEquation << " $SqidiTotalCount UDIV";
                }
                else if( instance == "l3node" )
                {
                    snapshotReportReadEquation << " $L3NodeTotalCount UDIV";
                    deltaReportReadEquation << " $L3NodeTotalCount UDIV";
                }
                else if( instance == "copyengine" )
                {
                    snapshotReportReadEquation << " $CopyEngineTotalCount UDIV";
                    deltaReportReadEquation << " $CopyEngineTotalCount UDIV";
                }
                else if( instance == "eu" )
                {
                    // EuAggrDuration for utilization has already divided by vector engine count.
                    if( isAverageEnabled )
                    {
                        snapshotReportReadEquation << " $VectorEngineTotalCount UDIV";
                        deltaReportReadEquation << " $VectorEngineTotalCount UDIV";
                    }
                }
                else if( instance == "thread" )
                {
                    if( isAverageEnabled )
                    {
                        snapshotReportReadEquation << " $VectorEngineTotalCount UDIV $VectorEngineThreadsCount UDIV";
                        deltaReportReadEquation << " $VectorEngineTotalCount UDIV $VectorEngineThreadsCount UDIV";
                    }
                    else
                    {
                        // EuAggrDuration for utilization has already divided by vector engine count.
                        snapshotReportReadEquation << " $VectorEngineThreadsCount UDIV";
                        deltaReportReadEquation << " $VectorEngineThreadsCount UDIV";
                    }
                }
                else if( instance == "pixpipe" )
                {
                    snapshotReportReadEquation << " $ColorPipeTotalCount UDIV";
                    deltaReportReadEquation << " $ColorPipeTotalCount UDIV";
                }
                else if( instance == "zpipe" )
                {
                    snapshotReportReadEquation << " $DepthPipeTotalCount UDIV";
                    deltaReportReadEquation << " $DepthPipeTotalCount UDIV";
                }
                else if( instance == "geompipe" )
                {
                    snapshotReportReadEquation << " $GeometryPipeTotalCount UDIV";
                    deltaReportReadEquation << " $GeometryPipeTotalCount UDIV";
                }
                else if( instance == "ccs" )
                {
                    snapshotReportReadEquation << " $ComputeEngineTotalCount UDIV";
                    deltaReportReadEquation << " $ComputeEngineTotalCount UDIV";
                }
                else if( instance == "" )
                {
                    // Do nothing on purpose.
                }
                else
                {
                    // Not acceptable instance.
                    MD_ASSERT_A( adapterId, false );
                }
            }
            else // Disaggregation is enabled.
            {
                if( instance == "eu" )
                {
                    if( hwEvent.m_archEvent.m_disaggregationMode == DISAGGREGATION_MODE_XECORE )
                    {
                        snapshotReportReadEquation << " $VectorEnginePerXeCoreCount UDIV";
                        deltaReportReadEquation << " $VectorEnginePerXeCoreCount UDIV";
                    }
                    else
                    {
                        // These disaggregation mode and instance type are not supported.
                        MD_ASSERT_A( adapterId, false );
                    }
                }
                else if( instance == "thread" )
                {
                    if( hwEvent.m_archEvent.m_disaggregationMode == DISAGGREGATION_MODE_XECORE )
                    {
                        snapshotReportReadEquation << " $VectorEnginePerXeCoreCount UDIV $VectorEngineThreadsCount UDIV";
                        deltaReportReadEquation << " $VectorEnginePerXeCoreCount UDIV $VectorEngineThreadsCount UDIV";
                    }
                    else
                    {
                        // These disaggregation mode and instance type are not supported.
                        MD_ASSERT_A( adapterId, false );
                    }
                }
                else if( instance == "pixpipe" )
                {
                    if( hwEvent.m_archEvent.m_disaggregationMode == DISAGGREGATION_MODE_SLICE )
                    {
                        snapshotReportReadEquation << " $ColorPipeTotalCount $SliceTotalCount UDIV UDIV";
                        deltaReportReadEquation << " $ColorPipeTotalCount $SliceTotalCount UDIV UDIV";
                    }
                    else
                    {
                        // These disaggregation mode and instance type are not supported.
                        MD_ASSERT_A( adapterId, false );
                    }
                }
                else if( instance == "zpipe" )
                {
                    if( hwEvent.m_archEvent.m_disaggregationMode == DISAGGREGATION_MODE_SLICE )
                    {
                        snapshotReportReadEquation << " $DepthPipeTotalCount $SliceTotalCount UDIV UDIV";
                        deltaReportReadEquation << " $DepthPipeTotalCount $SliceTotalCount UDIV UDIV";
                    }
                    else
                    {
                        // These disaggregation mode and instance type are not supported.
                        MD_ASSERT_A( adapterId, false );
                    }
                }
                else if( instance == "geompipe" )
                {
                    if( hwEvent.m_archEvent.m_disaggregationMode == DISAGGREGATION_MODE_SLICE )
                    {
                        snapshotReportReadEquation << " $GeometryPipeTotalCount $SliceTotalCount UDIV UDIV";
                        deltaReportReadEquation << " $GeometryPipeTotalCount $SliceTotalCount UDIV UDIV";
                    }
                    else
                    {
                        // These disaggregation mode and instance type are not supported.
                        MD_ASSERT_A( adapterId, false );
                    }
                }
                else if( instance == "xecore" ||
                    instance == "l3bank" ||
                    instance == "slice" ||
                    instance == "sqidi" ||
                    instance == "l3node" ||
                    instance == "copyengine" ||
                    instance == "" )
                {
                    // Do nothing on purpose.
                }
                else
                {
                    // These disaggregation mode and instance type are not supported.
                    MD_ASSERT_A( adapterId, false );
                }
            }
        }
        else if( isRateEnabled )
        {
            // Metric is calculated using the following normalization equation:
            // metric = event / timestamp
            // Metric unit is updated to per second.
            // Max value is not used.
            MD_CHECK_CC( metric.SetNormalizationEquation( "$Self $$GpuTime FDIV" ) );
        }
        else if( isByteEnabled )
        {
            // Metric is calculated using the following normalization equation:
            // metric = event * 64
            // Metric unit is updated to bytes.
            // Max value is not used.
            MD_CHECK_CC( metric.SetNormalizationEquation( "$Self 64 UMUL" ) );
        }

        return CC_OK;

    exception:
        MD_LOG_A( adapterId, LOG_INFO, "Failed to append normalizations and workarounds" );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     CMetricPrototypeManager constructor
    //
    // Description:
    //     Constructor for OA unit.
    //
    // Input:
    //     CMetricsDevice& device    - metrics device
    //     CMetricSet&     metricSet - metric set related to the prototype manager
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>::CMetricPrototypeManager( CMetricsDevice& device, CMetricSet& metricSet )
        : CPrototypeManager( device, metricSet )
        , m_mediaPesOffset( 0 )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     CMetricPrototypeManager constructor
    //
    // Description:
    //     Constructor for OAM unit.
    //
    // Input:
    //     CMetricsDevice& device    - metrics device
    //     CMetricSet&     metricSet - metric set related to the prototype manager
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::CMetricPrototypeManager( CMetricsDevice& device, CMetricSet& metricSet )
        : CPrototypeManager( device, metricSet )
        , m_mediaPesOffset( GetMediaPesOffset( *metricSet.GetConcurrentGroup() ) )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Returns true if the prototype manager is support for OA unit.
    //
    // Output:
    //     bool - true if the prototype manager is support for OA unit, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>::IsSupported()
    {
        return IsPlatformMatch(
            m_device.GetPlatformIndex(),
            GENERATION_BMG,
            GENERATION_LNL,
            GENERATION_PTL,
            GENERATION_NVL,
            GENERATION_CRI );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Returns true if the prototype manager is support for OAM unit.
    //
    // Output:
    //     bool - true if the prototype manager is support for OAM unit, false otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::IsSupported()
    {
        return IsPlatformMatch(
            m_device.GetPlatformIndex(),
            GENERATION_MTL,
            GENERATION_ARL,
            GENERATION_BMG,
            GENERATION_LNL,
            GENERATION_PTL,
            GENERATION_NVL,
            GENERATION_CRI );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetMediaPesOffset
    //
    // Description:
    //     Returns media PES starting offset.
    //
    // Input:
    //     CConcurrentGroup& concurrentGroup - concurrent group
    //
    // Output:
    //     uint32_t                          - media PES starting offset.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    uint32_t CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::GetMediaPesOffset( CConcurrentGroup& concurrentGroup )
    {
        const bool isXeLPG = IsPlatformMatch(
            m_device.GetPlatformIndex(),
            GENERATION_MTL,
            GENERATION_ARL );

        switch( const char* concurrentGroupSymbolName = concurrentGroup.GetParams()->SymbolName;
            concurrentGroupSymbolName[3] )
        {
            case '0': // OAM0
                return isXeLPG ? 0x00393200 : 0x00394200;

            case '1': // OAM1
                return 0x00394A00;

            case 'G': // OAMG
                return 0x00393200;

            default:
                MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_ERROR, "ERROR: Not supported OAM concurrent group with symbol name: %s", concurrentGroupSymbolName );
                return 0;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetMediaPesOffset
    //
    // Description:
    //     Returns media PES starting offset. This method is for non OAM units.
    //
    // Input:
    //     CConcurrentGroup& concurrentGroup - concurrent group
    //
    // Output:
    //     uint32_t                          - media PES starting offset.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMetricPrototypeManagerType T>
    uint32_t CMetricPrototypeManager<T>::GetMediaPesOffset( CConcurrentGroup& concurrentGroup )
    {
        // Media PES group is supported for OAM units only.
        return 0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetHwEventGroup
    //
    // Description:
    //     Returns group number from hw event. This is method for OA unit.
    //
    // Input:
    //     const THwEvent* hwEvent - a hw event.
    //
    // Output:
    //     THwEventGroup           - group enum that a hw event belongs to.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    THwEventGroup CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>::GetHwEventGroup( const THwEvent& hwEvent )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
        const auto     groupMask = hwEvent.m_archEvent.m_groupMask;

        THwEventGroup group = HW_EVENT_GROUP_FIRST;

        switch( groupMask )
        {
            case ARCH_EVENT_GROUP_FIRST:
                group = HW_EVENT_GROUP_FIRST;
                break;

            case ARCH_EVENT_GROUP_SECOND:
                group = HW_EVENT_GROUP_SECOND;
                break;

            case ARCH_EVENT_GROUP_FLEX:
                group = HW_EVENT_GROUP_FLEX;
                break;

            default:
                group = ( ( groupMask & ARCH_EVENT_GROUP_FLEX ) && hwEvent.m_filterValue != 0 )
                    ? HW_EVENT_GROUP_FLEX
                    : HW_EVENT_GROUP_FIRST;
                break;
        }

        if( group != HW_EVENT_GROUP_SECOND && hwEvent.m_archEvent.m_eventEncoding >= 0x4000 )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "Group %d mismach (expected: group %d)", group, HW_EVENT_GROUP_SECOND );
            group = HW_EVENT_GROUP_SECOND;
        }

        return group;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetHwEventGroup
    //
    // Description:
    //     Returns group number from hw event. This is method for OAM unit.
    //
    // Input:
    //     const THwEvent* hwEvent - a hw event.
    //
    // Output:
    //     THwEventGroup           - group enum that a hw event belongs to.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    THwEventGroup CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::GetHwEventGroup( const THwEvent& hwEvent )
    {
        return HW_EVENT_GROUP_FIRST;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AppendPesConfiguration
    //
    // Description:
    //     Appends PES configuration. This is method for OA unit.
    //
    // Input:
    //     const THwEvent&    hwEvent               - a hw event.
    //     const uint64_t     pesProgramming        - PES programming for the hw event.
    //     std::vector<bool>& pesProgrammed         - a vector of already programmed PES-es.
    //     uint32_t           flexProgramming[]     - an array with flex programming.
    //     uint32_t&          snapshotReportOffsets - snapshot report offset for the metric.
    //     uint32_t&          deltaReportOffsets    - delta report offset for the metric.
    //
    // Output:
    //     TCompletionCode                          - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>::AppendPesConfiguration(
        const THwEvent&    hwEvent,
        const uint64_t     pesProgramming,
        std::vector<bool>& pesProgrammed,
        uint32_t           flexProgramming[],
        uint32_t&          snapshotReportOffsets,
        uint32_t&          deltaReportOffsets )
    {
        constexpr uint32_t pesFirstGroup   = 0x00013000;
        constexpr uint32_t pesSecondGroup0 = 0x00013300;
        constexpr uint32_t pesSecondGroup1 = 0x00013500;
        constexpr uint32_t pesSecondGroup2 = 0x00013700;

        const uint32_t lowerPesProgramming = static_cast<uint32_t>( pesProgramming );
        const uint32_t upperPesProgramming = static_cast<uint32_t>( pesProgramming >> 32 );

        auto hwEventPair = GetHwEventIteratorFromGroup( m_firstEventGroup, hwEvent );

        if( hwEventPair != m_firstEventGroup.end() )
        {
            uint32_t hwEventIndex = static_cast<uint32_t>( std::distance( m_firstEventGroup.begin(), hwEventPair ) );

            if( hwEventIndex > 6 ) // PEC 21-31
            {
                hwEventIndex += 14;
            }

            snapshotReportOffsets = m_snapshotReportOffsetStart + m_snapshotCounterSize * hwEventIndex;
            deltaReportOffsets    = m_deltaReportOffsetStart + m_deltaCounterSize * hwEventIndex;

            if( !pesProgrammed[hwEventIndex] )
            {
                const uint32_t pesProgrammingOffset = pesFirstGroup + sizeof( uint64_t ) * hwEventIndex;

                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset + 4, upperPesProgramming, REGISTER_TYPE_OA ) );

                pesProgrammed[hwEventIndex] = true;
            }
        }

        hwEventPair = GetHwEventIteratorFromGroup( m_secondEventGroup, hwEvent );

        if( hwEventPair != m_secondEventGroup.end() )
        {
            const uint32_t hwEventIndex = static_cast<uint32_t>( std::distance( m_secondEventGroup.begin(), hwEventPair ) );

            // PEC 32-63
            snapshotReportOffsets = m_snapshotReportOffsetStart + m_snapshotCounterSize * ( hwEventIndex + 32 );
            deltaReportOffsets    = m_deltaReportOffsetStart + m_deltaCounterSize * ( hwEventIndex + 32 );

            if( !pesProgrammed[hwEventIndex + 32] )
            {
                const uint32_t pesProgrammingOffset0 = pesSecondGroup0 + sizeof( uint64_t ) * hwEventIndex;
                const uint32_t pesProgrammingOffset1 = pesSecondGroup1 + sizeof( uint64_t ) * hwEventIndex;
                const uint32_t pesProgrammingOffset2 = pesSecondGroup2 + sizeof( uint64_t ) * hwEventIndex;

                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset0, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset0 + 4, upperPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset1, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset1 + 4, upperPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset2, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset2 + 4, upperPesProgramming, REGISTER_TYPE_OA ) );

                pesProgrammed[hwEventIndex + 32] = true;
            }
        }

        hwEventPair = GetHwEventIteratorFromGroup( m_flexEventGroup, hwEvent );

        if( hwEventPair != m_flexEventGroup.end() )
        {
            const uint32_t hwEventIndex = static_cast<uint32_t>( std::distance( m_flexEventGroup.begin(), hwEventPair ) );

            // PEC 7-20
            snapshotReportOffsets = m_snapshotReportOffsetStart + m_snapshotCounterSize * ( hwEventIndex + 7 );
            deltaReportOffsets    = m_deltaReportOffsetStart + m_deltaCounterSize * ( hwEventIndex + 7 );

            if( !pesProgrammed[hwEventIndex + 7] )
            {
                const uint32_t pesProgrammingOffset = pesFirstGroup + sizeof( uint64_t ) * ( hwEventIndex + 7 );

                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset + 4, upperPesProgramming, REGISTER_TYPE_OA ) );

                // Coarse filters.
                if( hwEvent.m_filterValue > 0 )
                {
                    if( !( hwEventIndex & 1 ) ) // 7:4 bits
                    {
                        flexProgramming[hwEventIndex >> 1] |= ( hwEvent.m_filterValue << 4 );
                    }
                    else // 19:16 bits
                    {
                        flexProgramming[hwEventIndex >> 1] |= ( hwEvent.m_filterValue << 16 );
                    }
                }

                pesProgrammed[hwEventIndex + 7] = true;
            }
        }

        return CC_OK;

    exception:
        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_INFO, "Failed to append PES configuration" );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AppendPesConfiguration
    //
    // Description:
    //     Appends PES configuration. This is method for OAM unit.
    //
    // Input:
    //     const THwEvent&    hwEvent               - a hw event.
    //     const uint64_t     pesProgramming        - PES programming for the hw event.
    //     std::vector<bool>& pesProgrammed         - a vector of already programmed PES-es.
    //     uint32_t           flexProgramming[]     - an array with flex programming.
    //     uint32_t&          snapshotReportOffsets - snapshot report offset for the metric.
    //     uint32_t&          deltaReportOffsets    - delta report offset for the metric.
    //
    // Output:
    //     TCompletionCode                          - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::AppendPesConfiguration(
        const THwEvent&    hwEvent,
        const uint64_t     pesProgramming,
        std::vector<bool>& pesProgrammed,
        uint32_t           flexProgramming[],
        uint32_t&          snapshotReportOffsets,
        uint32_t&          deltaReportOffsets )
    {
        const uint32_t lowerPesProgramming = static_cast<uint32_t>( pesProgramming );
        const uint32_t upperPesProgramming = static_cast<uint32_t>( pesProgramming >> 32 );

        auto hwEventPair = GetHwEventIteratorFromGroup( m_firstEventGroup, hwEvent );

        if( hwEventPair != m_firstEventGroup.end() )
        {
            const uint32_t hwEventIndex = static_cast<uint32_t>( std::distance( m_firstEventGroup.begin(), hwEventPair ) );

            const uint32_t pesProgrammingOffset = m_mediaPesOffset + sizeof( uint64_t ) * hwEventIndex;
            snapshotReportOffsets               = m_snapshotReportOffsetStart + m_snapshotCounterSize * hwEventIndex;

            if( !pesProgrammed[hwEventIndex] )
            {
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset, lowerPesProgramming, REGISTER_TYPE_OA ) );
                MD_CHECK_CC( m_set.AddStartConfigRegister( pesProgrammingOffset + 4, upperPesProgramming, REGISTER_TYPE_OA ) );

                pesProgrammed[hwEventIndex] = true;
            }
        }

        return CC_OK;

    exception:
        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_INFO, "Failed to append PES configuration" );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AppendFlexConfiguration
    //
    // Description:
    //     Appends flex configuration. This is method for OA unit.
    //
    // Input:
    //     const uint32_t flexProgramming[] - an array with flex programming.
    //
    // Output:
    //     TCompletionCode                  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OA>::AppendFlexConfiguration( const uint32_t flexProgramming[] )
    {
        constexpr uint32_t flexEuEventControl0 = 0xE458;
        constexpr uint32_t flexEuEventControl1 = 0xE558;
        constexpr uint32_t flexEuEventControl2 = 0xE658;
        constexpr uint32_t flexEuEventControl3 = 0xE758;
        constexpr uint32_t flexEuEventControl4 = 0xE45C;
        constexpr uint32_t flexEuEventControl5 = 0xE55C;
        constexpr uint32_t flexEuEventControl6 = 0xE65C;

        constexpr uint32_t flexRegisters[] = { flexEuEventControl0, flexEuEventControl1, flexEuEventControl2, flexEuEventControl3, flexEuEventControl4, flexEuEventControl5, flexEuEventControl6 };

        for( uint32_t i = 0; i < sizeof( flexRegisters ) / sizeof( flexRegisters[0] ); ++i )
        {
            MD_CHECK_CC( m_set.AddStartConfigRegister( flexRegisters[i], flexProgramming[i], REGISTER_TYPE_FLEX ) );
        }

        return CC_OK;

    exception:
        MD_LOG_A( m_device.GetAdapter().GetAdapterId(), LOG_INFO, "Failed to append Flex configuration" );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     AppendFlexConfiguration
    //
    // Description:
    //     Appends flex configuration. This is method for non OA units.
    //
    // Input:
    //     const uint32_t flexProgramming[] - an array with flex programming.
    //
    // Output:
    //     TCompletionCode                  - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMetricPrototypeManagerType T>
    TCompletionCode CMetricPrototypeManager<T>::AppendFlexConfiguration( const uint32_t flexProgramming[] )
    {
        // Flex configuration is supported for OA unit only.
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetMaxPesCount
    //
    // Description:
    //     Returns max performance event selector register count.
    //
    // Output:
    //     uint32_t - max PES count
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMetricPrototypeManagerType T>
    uint32_t CMetricPrototypeManager<T>::GetMaxPesCount()
    {
        return m_maxPesCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Method:
    //     GetGroupMaxSize
    //
    // Description:
    //     Returns max size for a given group.
    //
    // Output:
    //     uint32_t - max size of a given group.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMetricPrototypeManagerType T>
    uint32_t CMetricPrototypeManager<T>::GetGroupMaxSize( const THwEventGroup group )
    {
        switch( group )
        {
            case HW_EVENT_GROUP_FIRST:
                return FIRST_EVENT_GROUP_VECTOR_INCREASE;

            case HW_EVENT_GROUP_SECOND:
                return SECOND_EVENT_GROUP_VECTOR_INCREASE;

            case HW_EVENT_GROUP_FLEX:
                return FLEX_EVENT_GROUP_VECTOR_INCREASE;

            default:
                MD_ASSERT( false );
                return 0;
        }
    }
} // namespace MetricsDiscoveryInternal
