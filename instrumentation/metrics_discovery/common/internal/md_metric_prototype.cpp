/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_prototype.cpp
//
//     Abstract:   C++ Metrics Discovery internal metric prototype implementation

#include "md_metric_prototype.h"
#include "md_oa_concurrent_group.h"
#include "md_metric_enumerator.h"

#include "md_utils.h"

#include <cstring>
#include <limits>
#include <regex>

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Query mode validation:                                                    //
    ///////////////////////////////////////////////////////////////////////////////
    static_assert( static_cast<uint32_t>( QUERY_MODE_MASK_NONE ) == QUERY_MODE_NONE );
    static_assert( QUERY_MODE_MASK_RENDER == MD_BIT( QUERY_MODE_RENDER - 1 ) );
    static_assert( QUERY_MODE_MASK_COMPUTE == MD_BIT( QUERY_MODE_COMPUTE - 1 ) );
    static_assert( QUERY_MODE_MASK_GLOBAL == MD_BIT( QUERY_MODE_GLOBAL - 1 ) );
    static_assert( QUERY_MODE_MASK_GLOBAL_EXTENDED == MD_BIT( QUERY_MODE_GLOBAL_EXTENDED - 1 ) );

    static_assert( QUERY_MODE_MASK_NONE == 0x0 );
    static_assert( QUERY_MODE_MASK_RENDER == 0x1 );
    static_assert( QUERY_MODE_MASK_COMPUTE == 0x2 );
    static_assert( QUERY_MODE_MASK_GLOBAL == 0x4 );
    static_assert( QUERY_MODE_MASK_GLOBAL_EXTENDED == 0x8 );

    ///////////////////////////////////////////////////////////////////////////////
    // Oa reporting types validation:                                            //
    ///////////////////////////////////////////////////////////////////////////////
    static_assert( OA_REPORTING_NONE == 0x0 );
    static_assert( OA_REPORTING_RENDER == 0x1 );
    static_assert( OA_REPORTING_COMPUTE == 0x2 );
    static_assert( OA_REPORTING_GLOBAL == 0x4 );
    static_assert( OA_REPORTING_GLOBAL_EXTENDED == 0x8 );

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     CMetricPrototype constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricEnumerator&      metricEnumerator -
    //     THwEvent&&              hwEvent          -
    //     const CMetricPrototype* parent           -
    //     const bool              canBeDeleted     -
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricPrototype::CMetricPrototype( CMetricEnumerator& metricEnumerator, THwEvent&& hwEvent, const CMetricPrototype* parent, const bool canBeDeleted )
        : m_metricEnumerator( metricEnumerator )
        , m_hwEvent( std::move( hwEvent ) )
        , m_optionsDescriptor()
        , m_parent( parent )
        , m_params_1_13()
        , m_availableOptions()
        , m_appliedOptions()
        , m_referenceCounter( 0 )
        , m_symbolNameSeparator( '_' )
        , m_canBeDeleted( canBeDeleted ) // Indicates if the metric prototype can be deleted from metric set.
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     ~CMetricPrototype destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricPrototype::~CMetricPrototype()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_13.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_13.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_13.LongName );
        MD_SAFE_DELETE_ARRAY( m_params_1_13.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params_1_13.DxToOglAlias );
        MD_SAFE_DELETE_ARRAY( m_params_1_13.MetricResultUnits );

        // Delete all dynamically allocated members of option descriptor.
        if( m_parent == nullptr )
        {
            for( auto optionDescriptor : m_optionsDescriptor )
            {
                MD_SAFE_DELETE_ARRAY( optionDescriptor->SymbolName );
                MD_SAFE_DELETE_ARRAY( optionDescriptor->ValidValues );
            }

            ClearVector( m_optionsDescriptor );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     Initialize
    //
    // Description:
    //     Initializes metric prototype.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricPrototype::Initialize()
    {
        auto&          device    = m_metricEnumerator.GetMetricsDevice();
        const uint32_t adapterId = device.GetAdapter().GetAdapterId();

        if( m_parent != nullptr )
        {
            // Copy params.
            m_params_1_13 = m_parent->m_params_1_13;

            // Copy pointers.
            m_params_1_13.SymbolName        = GetCopiedCString( m_parent->m_params_1_13.SymbolName, adapterId );
            m_params_1_13.ShortName         = GetCopiedCString( m_parent->m_params_1_13.ShortName, adapterId );
            m_params_1_13.GroupName         = GetCopiedCString( m_parent->m_params_1_13.GroupName, adapterId );
            m_params_1_13.LongName          = GetCopiedCString( m_parent->m_params_1_13.LongName, adapterId );
            m_params_1_13.MetricResultUnits = GetCopiedCString( m_parent->m_params_1_13.MetricResultUnits, adapterId );

            m_appliedOptions      = m_parent->m_appliedOptions;
            m_availableOptions    = m_parent->m_availableOptions;
            m_optionsDescriptor   = m_parent->m_availableOptions;
            m_symbolNameSeparator = m_parent->m_symbolNameSeparator;

            m_params_1_13.OptionDescriptorCount = static_cast<uint32_t>( m_parent->m_availableOptions.size() );

            return m_params_1_13.SymbolName &&
                    m_params_1_13.ShortName &&
                    m_params_1_13.GroupName &&
                    m_params_1_13.LongName &&
                    m_params_1_13.MetricResultUnits
                ? CC_OK
                : CC_ERROR_NO_MEMORY;
        }

        if( m_hwEvent.m_name.find( '.' ) != std::string::npos )
        {
            m_symbolNameSeparator = '.';
        }

        m_params_1_13.SymbolName        = GetCopiedCString( m_hwEvent.m_name.c_str(), adapterId );
        m_params_1_13.ShortName         = GetCopiedCString( m_hwEvent.m_shortName.c_str(), adapterId );
        m_params_1_13.GroupName         = GetCopiedCString( m_hwEvent.m_archEvent.m_groupName.c_str(), adapterId );
        m_params_1_13.LongName          = GetCopiedCString( m_hwEvent.m_description.c_str(), adapterId );
        m_params_1_13.DxToOglAlias      = nullptr;
        m_params_1_13.UsageFlagsMask    = USAGE_FLAG_OVERVIEW; // OVERVIEW (all disaggregated, no filters), FRAME and DRAW (oar/oac)
        m_params_1_13.ApiMask           = 0;
        m_params_1_13.ResultType        = RESULT_UINT64;
        m_params_1_13.MetricResultUnits = GetCopiedCString( m_hwEvent.m_archEvent.m_resultUnits.c_str(), adapterId );
        m_params_1_13.MetricType        = m_hwEvent.m_archEvent.m_metricType;
        m_params_1_13.HwUnitType        = m_hwEvent.m_archEvent.m_hwUnitType;
        m_params_1_13.QueryModeMask     = static_cast<uint32_t>( m_hwEvent.m_archEvent.m_oaReportingType & ~OA_REPORTING_MEDIA ); // Media metric prototypes don't support query

        const auto oaReportingType = m_hwEvent.m_archEvent.m_oaReportingType;
        if( oaReportingType & ( OA_REPORTING_GLOBAL | OA_REPORTING_GLOBAL_EXTENDED | OA_REPORTING_MEDIA ) )
        {
            m_params_1_13.ApiMask |= API_TYPE_IOSTREAM;
        }

        if( IsQueryModeMatch( device.GetQueryMode(), static_cast<uint32_t>( oaReportingType ) ) )
        {
            m_params_1_13.UsageFlagsMask |= USAGE_FLAG_FRAME | USAGE_FLAG_DRAW;
            m_params_1_13.ApiMask |= MD_QUERY_API_MASK;
        }

        // Normalization.
        if( const TNormalizationType normalization = m_hwEvent.m_archEvent.m_normalization;
            normalization != NORMALIZATION_TYPE_NONE )
        {
            // Utilization.
            if( normalization & NORMALIZATION_TYPE_UTILIZATION )
            {
                auto optionDescriptor = new( std::nothrow ) TMetricPrototypeOptionDescriptorLatest;

                if( optionDescriptor == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: optionDescriptor" );
                    return CC_ERROR_NO_MEMORY;
                }

                auto validValue = new( std::nothrow ) TValidValueLatest[1]();

                if( validValue == nullptr )
                {
                    MD_SAFE_DELETE( optionDescriptor );
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: validValue" );
                    return CC_ERROR_NO_MEMORY;
                }

                validValue[0].ValueType   = VALUE_TYPE_UINT32;
                validValue[0].ValueUInt32 = 1;

                optionDescriptor->Type            = OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION;
                optionDescriptor->SymbolName      = GetCopiedCString( "Normalization_utilization", adapterId );
                optionDescriptor->ValidValues     = validValue;
                optionDescriptor->ValidValueCount = 1;

                m_optionsDescriptor.push_back( optionDescriptor );
            }

            // Average.
            if( normalization & NORMALIZATION_TYPE_AVERAGE )
            {
                auto optionDescriptor = new( std::nothrow ) TMetricPrototypeOptionDescriptorLatest;

                if( optionDescriptor == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: optionDescriptor" );
                    return CC_ERROR_NO_MEMORY;
                }

                auto validValue = new( std::nothrow ) TValidValueLatest[1]();

                if( validValue == nullptr )
                {
                    MD_SAFE_DELETE( optionDescriptor );
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: validValue" );
                    return CC_ERROR_NO_MEMORY;
                }

                validValue[0].ValueType   = VALUE_TYPE_UINT32;
                validValue[0].ValueUInt32 = 1;

                optionDescriptor->Type            = OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE;
                optionDescriptor->SymbolName      = GetCopiedCString( "Normalization_average", adapterId );
                optionDescriptor->ValidValues     = validValue;
                optionDescriptor->ValidValueCount = 1;

                m_optionsDescriptor.push_back( optionDescriptor );
            }

            // Rate.
            if( normalization & NORMALIZATION_TYPE_RATE )
            {
                auto optionDescriptor = new( std::nothrow ) TMetricPrototypeOptionDescriptorLatest;

                if( optionDescriptor == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: optionDescriptor" );
                    return CC_ERROR_NO_MEMORY;
                }

                auto validValue = new( std::nothrow ) TValidValueLatest[1]();

                if( validValue == nullptr )
                {
                    MD_SAFE_DELETE( optionDescriptor );
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: validValue" );
                    return CC_ERROR_NO_MEMORY;
                }

                validValue[0].ValueType   = VALUE_TYPE_UINT32;
                validValue[0].ValueUInt32 = 1;

                optionDescriptor->Type            = OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE;
                optionDescriptor->SymbolName      = GetCopiedCString( "Normalization_rate", adapterId );
                optionDescriptor->ValidValues     = validValue;
                optionDescriptor->ValidValueCount = 1;

                m_optionsDescriptor.push_back( optionDescriptor );
            }

            // Byte.
            if( normalization & NORMALIZATION_TYPE_BYTE )
            {
                auto optionDescriptor = new( std::nothrow ) TMetricPrototypeOptionDescriptorLatest;

                if( optionDescriptor == nullptr )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: optionDescriptor" );
                    return CC_ERROR_NO_MEMORY;
                }

                auto validValue = new( std::nothrow ) TValidValueLatest[1]();

                if( validValue == nullptr )
                {
                    MD_SAFE_DELETE( optionDescriptor );
                    MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: validValue" );
                    return CC_ERROR_NO_MEMORY;
                }

                validValue[0].ValueType   = VALUE_TYPE_UINT32;
                validValue[0].ValueUInt32 = 1;

                optionDescriptor->Type            = OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE;
                optionDescriptor->SymbolName      = GetCopiedCString( "Normalization_byte", adapterId );
                optionDescriptor->ValidValues     = validValue;
                optionDescriptor->ValidValueCount = 1;

                m_optionsDescriptor.push_back( optionDescriptor );
            }
        }

        m_availableOptions = m_optionsDescriptor;

        m_params_1_13.OptionDescriptorCount = static_cast<uint32_t>( m_availableOptions.size() );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns the metric prototype params.
    //
    // Output:
    //     TMetricPrototypeParams_1_13* - pointer to metric prototype params.
    //
    //////////////////////////////////////////////////////////////////////////////
    const TMetricPrototypeParams_1_13* CMetricPrototype::GetParams( void ) const
    {
        return &m_params_1_13;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetOptionDescriptor
    //
    // Description:
    //     Get option descriptor by index.
    //
    // Input:
    //     uint32_t index                     - option index.
    //
    // Output:
    //     const TMetricPrototypeParams_1_13* - pointer to metric prototype params.
    //
    //////////////////////////////////////////////////////////////////////////////
    const TMetricPrototypeOptionDescriptor_1_13* CMetricPrototype::GetOptionDescriptor( uint32_t index ) const
    {
        return ( index < m_optionsDescriptor.size() )
            ? m_optionsDescriptor[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     SetOption
    //
    // Description:
    //     Set option by its descriptor id.
    //
    // Input:
    //     const TOptionDescriptorType optionType - option type.
    //     const TTypedValue_1_0*      typedValue - option typed value.
    //
    // Output:
    //     TCompletionCode             - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricPrototype::SetOption( const TOptionDescriptorType optionType, const TTypedValue_1_0* typedValue )
    {
        if( m_params_1_13.OptionDescriptorCount == 0 || typedValue == nullptr || m_referenceCounter > 0 )
        {
            return CC_ERROR_GENERAL;
        }

        const uint32_t adapterId = m_metricEnumerator.GetMetricsDevice().GetAdapter().GetAdapterId();

        uint64_t value = 0;

        // Check value type.
        switch( typedValue->ValueType )
        {
            case VALUE_TYPE_UINT32:
                value = typedValue->ValueUInt32;
                break;

            case VALUE_TYPE_UINT64:
                value = typedValue->ValueUInt64;
                break;

            default:
                return CC_ERROR_INVALID_PARAMETER;
        }

        // Check valid option.
        const auto optionIterator = std::find_if(
            m_availableOptions.begin(),
            m_availableOptions.end(),
            [optionType]( const TMetricPrototypeOptionDescriptorLatest* availableOption )
            {
                return availableOption->Type == optionType;
            } );

        if( optionIterator == m_availableOptions.end() )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        // Check valid ranges.
        const auto option       = *optionIterator;
        bool       isValidValue = false;

        for( uint32_t i = 0; i < option->ValidValueCount; ++i )
        {
            switch( const auto& validValue = option->ValidValues[i];
                    validValue.ValueType )
            {
                case VALUE_TYPE_UINT32:
                    isValidValue = value == validValue.ValueUInt32;
                    break;

                case VALUE_TYPE_UINT64:
                    isValidValue = value == validValue.ValueUInt64;
                    break;

                case VALUE_TYPE_UINT32_RANGE:
                    isValidValue = value >= validValue.ValueUInt32Range.Min && value <= validValue.ValueUInt32Range.Max;
                    break;

                case VALUE_TYPE_UINT64_RANGE:
                    isValidValue = value >= validValue.ValueUInt64Range.Min && value <= validValue.ValueUInt64Range.Max;
                    break;

                default:
                    return CC_ERROR_NOT_SUPPORTED;
            }

            if( isValidValue )
            {
                break;
            }
        }

        if( !isValidValue )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        std::string symbolName = m_params_1_13.SymbolName;
        std::string longName   = m_params_1_13.LongName;
        std::string shortName  = m_params_1_13.ShortName;

        // Modify parameters.
        std::string suffix      = "";
        std::string resultUnits = "";

        switch( option->Type )
        {
            case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION:
                suffix                   = "Utilization";
                resultUnits              = "percent";
                m_params_1_13.ResultType = RESULT_FLOAT;
                m_params_1_13.MetricType = METRIC_TYPE_DURATION;
                break;

            case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE:
                suffix = "Average";
                break;

            case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE:
                suffix = "Rate";
                if( std::string_view( m_params_1_13.MetricResultUnits ) == "bytes" )
                {
                    resultUnits = "GBpS";
                }
                else
                {
                    resultUnits = m_params_1_13.MetricResultUnits;
                    resultUnits += "pS";
                    MD_LOG_A( adapterId, LOG_DEBUG, "Unsupported result units conversion: %s", m_params_1_13.MetricResultUnits );
                }
                m_params_1_13.ResultType = RESULT_FLOAT;
                m_params_1_13.MetricType = METRIC_TYPE_THROUGHPUT;
                break;

            case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE:
                suffix      = "Byte";
                resultUnits = "bytes";
                break;

            default:
                MD_ASSERT_A( adapterId, false );
        }

        UpdateNames( symbolName, shortName, optionType );

        UpdateDescription( longName, suffix, optionType );

        if( ChangeNames( symbolName.c_str(), shortName.c_str(), longName.c_str(), resultUnits.c_str() ) != CC_OK )
        {
            return CC_ERROR_GENERAL;
        }

        // Remove option from vector.
        m_availableOptions.erase( optionIterator );

        // Remember applied option.
        m_appliedOptions.push_back( option->Type );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     ChangeNames
    //
    // Description:
    //     Updates symbol, short, long or units names.
    //
    // Input:
    //     const char* symbolName  - symbol name to update.
    //     const char* shortName   - short name to update.
    //     const char* longName    - long name to update.
    //     const char* resultUnits - metric result units to update.
    //
    // Output:
    //     TCompletionCode         - result of the operation.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricPrototype::ChangeNames( const char* symbolName, const char* shortName, const char* longName, const char* resultUnits )
    {
        if( m_referenceCounter > 0 )
        {
            return CC_ERROR_GENERAL;
        }

        const uint32_t adapterId = m_metricEnumerator.GetMetricsDevice().GetAdapter().GetAdapterId();

        if( symbolName != nullptr && *symbolName != '\0' )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Old symbol name: %s, new symbol name: %s", m_params_1_13.SymbolName, symbolName );
            MD_SAFE_DELETE( m_params_1_13.SymbolName );
            m_params_1_13.SymbolName = GetCopiedCString( symbolName, adapterId );
        }
        if( shortName != nullptr && *shortName != '\0' )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Old short name: %s, new short name: %s", m_params_1_13.ShortName, shortName );
            MD_SAFE_DELETE( m_params_1_13.ShortName );
            m_params_1_13.ShortName = GetCopiedCString( shortName, adapterId );
        }
        if( longName != nullptr && *longName != '\0' )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Old long name: %s, new long name: %s", m_params_1_13.LongName, longName );
            MD_SAFE_DELETE( m_params_1_13.LongName );
            m_params_1_13.LongName = GetCopiedCString( longName, adapterId );
        }
        if( resultUnits != nullptr && *resultUnits != '\0' )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Old result units: %s, new result units: %s", m_params_1_13.MetricResultUnits, resultUnits );
            MD_SAFE_DELETE( m_params_1_13.MetricResultUnits );
            m_params_1_13.MetricResultUnits = GetCopiedCString( resultUnits, adapterId );
        }

        return ( m_params_1_13.SymbolName && m_params_1_13.ShortName && m_params_1_13.LongName && m_params_1_13.MetricResultUnits )
            ? CC_OK
            : CC_ERROR_NO_MEMORY;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     Clone
    //
    // Description:
    //     Clones metric prototype.
    //
    // Output:
    //     IMetricPrototype_1_13* - a pointer to a cloned metric prototype.
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricPrototype_1_13* CMetricPrototype::Clone( void )
    {
        const uint32_t adapterId = m_metricEnumerator.GetMetricsDevice().GetAdapter().GetAdapterId();

        // Clone hw event.
        THwEvent clonedHwEvent = m_hwEvent;

        auto clonedMetricPropotype = new( std::nothrow ) CMetricPrototype( m_metricEnumerator, std::move( clonedHwEvent ), this );

        if( clonedMetricPropotype == nullptr )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: clonedMetricPropotype" );
            return nullptr;
        }
        else if( clonedMetricPropotype->Initialize() != CC_OK )
        {
            MD_SAFE_DELETE( clonedMetricPropotype );
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: cannot initialize metric prototype" );
            return nullptr;
        }

        auto& metricPrototypes = m_metricEnumerator.GetMetricPrototypes();

        metricPrototypes.push_back( clonedMetricPropotype );

        return clonedMetricPropotype;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     IncreaseReferenceCounter
    //
    // Description:
    //     Increases a reference counter.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricPrototype::IncreaseReferenceCounter()
    {
        ++m_referenceCounter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     DecreaseReferenceCounter
    //
    // Description:
    //     Decreases a reference counter.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricPrototype::DecreaseReferenceCounter()
    {
        if( m_referenceCounter > 0 )
        {
            --m_referenceCounter;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetReferenceCounter
    //
    // Description:
    //     Returns reference counter.
    //
    // Output:
    //     uint32_t - reference counter.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetricPrototype::GetReferenceCounter() const
    {
        return m_referenceCounter;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     CanBeDeleted
    //
    // Description:
    //     Returns true if metric prototype can be deleted from metric set.
    //
    // Output:
    //     bool - indicator if metric prototype can be deleted.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricPrototype::CanBeDeleted() const
    {
        return m_canBeDeleted;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetParent
    //
    // Description:
    //     Returns a pointer to the parent.
    //
    // Output:
    //     const CMetricPrototype* - pointer to the parent.
    //
    //////////////////////////////////////////////////////////////////////////////
    const CMetricPrototype* CMetricPrototype::GetParent() const
    {
        return m_parent;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     UpdateParent
    //
    // Description:
    //     Updates the current parent to a given one.
    //
    // Input:
    //     const CMetricPrototype* - pointer to the new parent.
    //
    // Output:
    //     TCompletionCode         - completion code.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricPrototype::UpdateParent( const CMetricPrototype* parent )
    {
        const uint32_t adapterId = m_metricEnumerator.GetMetricsDevice().GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, m_parent, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, parent, CC_ERROR_INVALID_PARAMETER );

        m_parent = parent;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetHwEvent
    //
    // Description:
    //     Returns hardware event.
    //
    // Output:
    //     THwEvent& - reference to hw event.
    //
    //////////////////////////////////////////////////////////////////////////////
    THwEvent& CMetricPrototype::GetHwEvent()
    {
        return m_hwEvent;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetAppliedOptions
    //
    // Description:
    //     Returns applied options vector.
    //
    // Output:
    //     const std::vector<TOptionDescriptorType>& - applied options vector.
    //
    //////////////////////////////////////////////////////////////////////////////
    const std::vector<TOptionDescriptorType>& CMetricPrototype::GetAppliedOptions() const
    {
        return m_appliedOptions;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetMetricEnumerator
    //
    // Description:
    //     Returns metric enumerator.
    //
    // Output:
    //     CMetricEnumerator& - a reference to metric enumerator
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricEnumerator& CMetricPrototype::GetMetricEnumerator() const
    {
        return m_metricEnumerator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     UpdateDescription
    //
    // Description:
    //     Returns long name (description).
    //
    // Input:
    //     std::string&                longName   - (out) long name to be updated.
    //     std::string&                suffix     - suffix to be added.
    //     const TOptionDescriptorType optionType - option type.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricPrototype::UpdateDescription( std::string& longName, std::string& suffix, const TOptionDescriptorType optionType ) const
    {
        const uint32_t adapterId = m_metricEnumerator.GetMetricsDevice().GetAdapter().GetAdapterId();

        auto toLower = []( char character )
        {
            return static_cast<char>( std::tolower( character ) );
        };

        auto toUpper = []( char character )
        {
            return static_cast<char>( std::toupper( character ) );
        };

        std::string hwEventNameLowerCase( m_hwEvent.m_name.size(), 0 );
        std::transform( m_hwEvent.m_name.begin(), m_hwEvent.m_name.end(), hwEventNameLowerCase.begin(), toLower );

        // Check if the original hw event name contained "cycles" and the option is utilization normalization.
        if( optionType == OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION &&
            hwEventNameLowerCase.find( "cycles" ) != std::string::npos )
        {
            if( std::smatch cyclesMatch;
                std::regex_search( longName, cyclesMatch, std::regex( "(Average )?(Number|number) of( SIF| copy read data| copy write data)? (active |stall |starve )?(cycles|thread slots)( when| at the| on the)?([^\\.]*)(\\.)?" ) ) )
            {
                MD_ASSERT_A( adapterId, cyclesMatch.size() == 9 );

                const char* prefix = ( cyclesMatch[1].matched )
                    ? "Average percentage of "
                    : "Percentage of ";

                const char* suffixCycles = ( cyclesMatch[4] == "active " )
                    ? " is active"
                    : ( cyclesMatch[4] == "stall " )
                    ? " stalled"
                    : ( cyclesMatch[4] == "starve " )
                    ? " starved"
                    : "";

                if( cyclesMatch[5].str() == "cycles" )
                {
                    longName = prefix + ( "time in which" + cyclesMatch[3].str() + cyclesMatch[7].str() + suffixCycles + cyclesMatch[8].str() + cyclesMatch.suffix().str() );
                }
                else
                {
                    // Exception for XVE_THREADS_OCCUPANCY_*_CYCLES
                    longName = prefix + ( cyclesMatch[5].str() + cyclesMatch.suffix().str() + suffixCycles );
                }
            }
        }
        else
        {
            // Lowercase for long name (description).
            std::transform( suffix.begin(), suffix.end(), suffix.begin(), toLower );

            switch( optionType )
            {
                case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION:
                    if( std::smatch cyclesMatch;
                        std::regex_search( longName, cyclesMatch, std::regex( "(Average )?(Number|number) (of)( execution slots)?" ) ) )
                    {
                        MD_ASSERT_A( adapterId, cyclesMatch.size() == 5 );

                        const char* prefix = ( cyclesMatch[1].matched )
                            ? "Average percentage of time"
                            : "Percentage of time";

                        const char* prefixUtilization = ( !cyclesMatch[4].matched )
                            ? " taken by"
                            : "";

                        longName = prefix + ( prefixUtilization + cyclesMatch.suffix().str() );
                    }
                    break;

                case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE:
                    std::transform( longName.begin(), longName.begin() + 1, longName.begin(), toLower );
                    std::transform( suffix.begin(), suffix.begin() + 1, suffix.begin(), toUpper );

                    longName = suffix + ' ' + longName;
                    break;

                case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE:
                    if( std::smatch bytesMatch; // TODO: "(, excluding SLM accesses)?" match is not working
                        std::regex_search( longName, bytesMatch, std::regex( "(Average )?(Number|number) of bytes (read|written|transfered) (out of the|to the|from|to) (.+)(, excluding SLM accesses)?" ) ) )
                    {
                        MD_ASSERT_A( adapterId, bytesMatch.size() == 7 );

                        const char* prefix = ( bytesMatch[1].matched )
                            ? "Average "
                            : "";

                        const char* infix = ( bytesMatch[3] == "written" )
                            ? " write bandwidth"
                            : ( bytesMatch[3] == "read" )
                            ? " read bandwidth"
                            : " bandwidth";

                        longName = prefix + bytesMatch[5].str() + infix + bytesMatch[6].str();
                    }
                    else if( std::smatch localMemoryMatch;
                             std::regex_search( longName, localMemoryMatch, std::regex( "(Average )?(Number|number) of device(.+)( read| write) (bytes)" ) ) )
                    {
                        MD_ASSERT_A( adapterId, localMemoryMatch.size() == 6 );

                        const char* prefix = ( localMemoryMatch[1].matched )
                            ? "Average device"
                            : "Device";

                        longName = prefix + localMemoryMatch[3].str() + localMemoryMatch[4].str() + " bandwidth";
                    }

                    break;

                case OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE:
                    if( std::smatch l3BytesMatch;
                        std::regex_search( longName, l3BytesMatch, std::regex( "(Average )?(Number|number) of (Device Cache 64B) (read requests|write requests)" ) ) )
                    {
                        MD_ASSERT_A( adapterId, l3BytesMatch.size() == 5 );

                        const char* prefix = ( l3BytesMatch[1].matched )
                            ? "Average "
                            : "";

                        const char* infix = ( l3BytesMatch[4] == "read requests" )
                            ? "read from Device Cache "
                            : "written to Device Cache ";

                        longName = prefix + l3BytesMatch[2].str() + " of bytes " + infix;
                    }
                    else if( std::smatch bytesMatch;
                             std::regex_search( longName, bytesMatch, std::regex( "(Average )?(Number|number) of (|Device Cache|cacheline|system memory 64B) (read requests|write requests|read|write|reads|writes) (.+)" ) ) )
                    {
                        MD_ASSERT_A( adapterId, bytesMatch.size() == 6 );

                        const char* prefix = ( bytesMatch[1].matched )
                            ? "Average "
                            : "";

                        const char* infix = ( bytesMatch[3] == "system memory 64B" )
                            ? "system memory bytes "
                            : "bytes ";

                        const char* infix2 = ( bytesMatch[4] == "read requests" )
                            ? "read from Device Cache "
                            : bytesMatch[4] == "write requests"
                            ? "written to Device Cache "
                            : bytesMatch[4] == "reads"
                            ? "read "
                            : "written ";

                        longName = prefix + bytesMatch[2].str() + " of " + infix + infix2 + bytesMatch[5].str();
                    }
                    else if( std::smatch gpuMemBytesMatch;
                             std::regex_search( longName, gpuMemBytesMatch, std::regex( "(Average )?(Number|number) of host 64B (reads to|writes to) (.+)" ) ) )
                    {
                        MD_ASSERT_A( adapterId, gpuMemBytesMatch.size() == 5 );

                        const char* prefix = ( gpuMemBytesMatch[1].matched )
                            ? "Average "
                            : "";

                        const char* infix = ( gpuMemBytesMatch[3] == "reads to" )
                            ? " read by host from "
                            : " written by host to ";

                        longName = prefix + gpuMemBytesMatch[2].str() + " of bytes" + infix + gpuMemBytesMatch[4].str();
                    }

                    break;

                default:
                    longName += " (" + suffix + ')';
                    break;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     UpdateNames
    //
    // Description:
    //     Returns updated symbol and short names.
    //
    // Input:
    //     std::string&                symbolName - (out) symbol name to be updated.
    //     std::string&                shortName  - (out) short name to be updated.
    //     const TOptionDescriptorType optionType - option type.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricPrototype::UpdateNames( std::string& symbolName, std::string& shortName, const TOptionDescriptorType optionType ) const
    {
        auto toLower = []( char character )
        {
            return static_cast<char>( std::tolower( character ) );
        };

        auto toUpper = []( char character )
        {
            return static_cast<char>( std::toupper( character ) );
        };

        char symbolNameTemplate[128];
        char shortNameTemplate[128];

        const bool isUtilizationEnabled =
            ( optionType == OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ) ||
            ( std::find( m_appliedOptions.begin(), m_appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_UTILIZATION ) != m_appliedOptions.end() );

        const bool isAverageEnabled =
            ( optionType == OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE ) ||
            ( std::find( m_appliedOptions.begin(), m_appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_AVERAGE ) != m_appliedOptions.end() );

        const bool isRateEnabled =
            ( optionType == OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE ) ||
            ( std::find( m_appliedOptions.begin(), m_appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_RATE ) != m_appliedOptions.end() );
        const bool isByteEnabled =
            ( optionType == OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE ) ||
            ( std::find( m_appliedOptions.begin(), m_appliedOptions.end(), OPTION_DESCRIPTOR_TYPE_NORMALIZATION_BYTE ) != m_appliedOptions.end() );

        std::string eventSymbolName = symbolName;
        std::string eventShortName  = shortName;
        std::string units           = "";
        std::string average         = "";
        std::string byte            = "";

        std::string symbolNameLowerCase( eventSymbolName.size(), 0 );
        std::transform( eventSymbolName.begin(), eventSymbolName.end(), symbolNameLowerCase.begin(), toLower );

        std::string shortNameLowerCase( eventShortName.size(), 0 );
        std::transform( eventShortName.begin(), eventShortName.end(), shortNameLowerCase.begin(), toLower );

        // All suffixes must be lowercased for short name.
        auto convertToShortNameFormat = [&]( std::string& suffix )
        {
            if( suffix.length() > 2 )
            {
                std::transform( suffix.begin() + 1, suffix.begin() + 2, suffix.begin() + 1, toUpper );
                std::transform( suffix.begin() + 2, suffix.end(), suffix.begin() + 2, toLower );
            }
        };

        if( isUtilizationEnabled )
        {
            std::string hwEventNameLowerCase( m_hwEvent.m_name.size(), 0 );
            std::transform( m_hwEvent.m_name.begin(), m_hwEvent.m_name.end(), hwEventNameLowerCase.begin(), toLower );

            if( constexpr std::string_view cyclesSuffix = "cycles";
                hwEventNameLowerCase.find( cyclesSuffix ) != std::string::npos ) // Check the original hw event name if contained "cycles".
            {
                // Delete cycles from symbol name and short name.
                DeleteSuffixFromName( eventSymbolName, symbolNameLowerCase, cyclesSuffix );
                DeleteSuffixFromName( eventShortName, shortNameLowerCase, cyclesSuffix );
            }
            else // If the original hw event name did not contain "cycles", add "utilization" to the both names.
            {
                std::string utilizationSuffix = "utilization";

                // Delete utilization from symbol name and short name.
                DeleteSuffixFromName( eventSymbolName, symbolNameLowerCase, utilizationSuffix );
                DeleteSuffixFromName( eventShortName, shortNameLowerCase, utilizationSuffix );

                // Get utilization suffix.
                units = GetSuffix( utilizationSuffix );
            }
        }

        if( isAverageEnabled )
        {
            std::string averageSuffix = "average";

            // Delete average from symbol name and short name.
            DeleteSuffixFromName( eventSymbolName, symbolNameLowerCase, averageSuffix );
            DeleteSuffixFromName( eventShortName, shortNameLowerCase, averageSuffix );

            // Get average suffix.
            average = GetSuffix( averageSuffix );
        }

        if( isRateEnabled )
        {
            std::string rateSuffix = "rate";

            // Delete rate from symbol name and symbol name.
            DeleteSuffixFromName( eventSymbolName, symbolNameLowerCase, rateSuffix );
            DeleteSuffixFromName( eventShortName, shortNameLowerCase, rateSuffix );

            // Get rate suffix.
            units = GetSuffix( rateSuffix );
        }
        if( isByteEnabled )
        {
            std::string byteSuffix = "byte";

            // Delete byte from symbol name and symbol name.
            DeleteSuffixFromName( eventSymbolName, symbolNameLowerCase, byteSuffix );
            DeleteSuffixFromName( eventShortName, shortNameLowerCase, byteSuffix );

            // Get byte suffix.
            byte = GetSuffix( byteSuffix );

            size_t posRead  = eventSymbolName.find( "_READ" );
            size_t posWrite = eventSymbolName.find( "_WRITE" );
            if( posRead != std::string::npos )
            {
                eventSymbolName.insert( posRead, byte );
                convertToShortNameFormat( byte );
                std::replace( byte.begin(), byte.end(), m_symbolNameSeparator, ' ' );
                eventShortName.insert( posRead, byte );
            }
            else if( posWrite != std::string::npos )
            {
                eventSymbolName.insert( posWrite, byte );
                convertToShortNameFormat( byte );
                std::replace( byte.begin(), byte.end(), m_symbolNameSeparator, ' ' );
                eventShortName.insert( posWrite, byte );
            }
            else
            {
                eventSymbolName += byte;
                convertToShortNameFormat( byte );
                std::replace( byte.begin(), byte.end(), m_symbolNameSeparator, ' ' );
                eventShortName += byte;
            }
        }

        // Produce symbol name.
        iu_sprintf_s( symbolNameTemplate, sizeof( symbolNameTemplate ), "%s%s%s", eventSymbolName.c_str(), units.c_str(), average.c_str() );

        convertToShortNameFormat( units );
        convertToShortNameFormat( average );

        // Change separators to spaces.
        std::replace( units.begin(), units.end(), m_symbolNameSeparator, ' ' );
        std::replace( average.begin(), average.end(), m_symbolNameSeparator, ' ' );

        // Produce short name.
        iu_sprintf_s( shortNameTemplate, sizeof( symbolNameTemplate ), "%s%s%s", eventShortName.c_str(), units.c_str(), average.c_str() );

        symbolName = symbolNameTemplate;
        shortName  = shortNameTemplate;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     DeleteSuffixFromName
    //
    // Description:
    //     Deletes suffix from symbol or short name.
    //
    // Input:
    //     std::string&           name          - (out) name to be updated.
    //     std::string&           nameLowerCase - (out) lower cased name to be updated.
    //     const std::string_view suffix        - suffix to be deleted.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricPrototype::DeleteSuffixFromName( std::string& name, std::string& nameLowerCase, const std::string_view suffix ) const
    {
        const uint32_t suffixLength = static_cast<uint32_t>( suffix.length() );

        if( const auto& suffixPosition = nameLowerCase.rfind( suffix );
            suffixPosition != std::string::npos )
        {
            // Also remove separator before the suffix.
            name.erase( suffixPosition - 1, suffixLength + 1 );
            nameLowerCase.erase( suffixPosition - 1, suffixLength + 1 );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Method:
    //     GetSuffix
    //
    // Description:
    //     Returns suffix with a symbol name separator.
    //
    // Input:
    //     std::string& suffix - input suffix.
    //
    // Output:
    //     std::string         - suffix with a symbol name separator.
    //
    //////////////////////////////////////////////////////////////////////////////
    std::string CMetricPrototype::GetSuffix( std::string& suffix ) const
    {
        auto toUpper = []( char character )
        {
            return static_cast<char>( std::toupper( character ) );
        };

        std::transform( suffix.begin(), suffix.end(), suffix.begin(), toUpper );

        // Add instance suffix.
        return m_symbolNameSeparator + suffix;
    }

} // namespace MetricsDiscoveryInternal
