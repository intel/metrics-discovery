/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_xe.cpp
//
//     Abstract:   C++ implementation for Linux with XE KMD

#include "md_sub_devices_linux.h"
#include "md_driver_ifc_linux_xe.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_utils.h"

#include <cmath>
#include <cstring>
#include <inttypes.h> // for PRIu64 (printing uint64_t)
#include <errno.h>
#include <array>
#include <vector>
#include <string>
#include <functional> // for std::hash
#include <algorithm>  // for std::find, std::remove
#include <iomanip>
#include <sstream>
#include <regex>

#include <sys/stat.h>
#include <sys/sysmacros.h> // for major, minor
#include <fcntl.h>
#include <dirent.h>
#include <poll.h>
#include <unistd.h> // close, write, read

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
#define DRM_XE_ENGINE_CLASS_GSC    65535
#define DRM_XE_ENGINE_INSTANCE_GSC 65535

    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     iu_xe_oa_config_register
    //
    // Description:
    //     For adding configs to kernel. Based on xe_oa_reg defined in kernel in xe_oa.c.
    //     DRM_XE_OBSERVATION_OP_ADD_CONFIG expects just (address, value) tuples.
    //
    //////////////////////////////////////////////////////////////////////////////
    struct iu_xe_oa_config_register
    {
        uint32_t address;
        uint32_t value;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     CDriverInterfaceLinuxXe constructor
    //
    // Description:
    //     Creates driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxXe::CDriverInterfaceLinuxXe( CAdapterHandle& adapterHandle )
        : CDriverInterfaceLinuxCommon( adapterHandle, DRM_VERSION_XE )
        , m_xeObservationCapabilities{}
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     CDriverInterfaceLinuxXe destructor
    //
    // Description:
    //     Deletes driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxXe::~CDriverInterfaceLinuxXe()
    {
        MD_LOG_ENTER_A( m_adapterId );

        for( int32_t oaConfigId : m_AddedOaConfigs )
        {
            RemoveOaConfig( oaConfigId );
        }
        m_AddedOaConfigs.clear();

        MD_LOG_EXIT_A( m_adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     CreateContext
    //
    // Description:
    //     Creates driver context.
    //
    // Output:
    //     bool - *true* if successful
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxXe::CreateContext()
    {
        if( !InitializeIntelDrm() )
        {
            return false;
        }

        AcquireAdapterId();

        return ReadXeObservationCapabilities() == CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetSysFsPath
    //
    // Description:
    //     Returns a path to a given system file.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN)  metrics device
    //     const char* fileName          - (IN)  a system file name
    //     const char* filePath          - (OUT) a path to the system file
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxXe::GetSysFsPath( CMetricsDevice& metricsDevice, const TSysFsType fileType, char* filePath, const uint32_t filePathLength )
    {
        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();
        const uint32_t gt             = 0;
        const uint32_t freq           = 0;
        const char*    fileName       = "";

        switch( fileType )
        {
            case SYS_FS_ACT_FREQ:
                fileName = "act_freq";
                break;

            case SYS_FS_MAX_FREQ:
                fileName = "rp0_freq";
                break;

            case SYS_FS_MIN_FREQ:
                fileName = "rpn_freq";
                break;

            case SYS_FS_MAX_FREQ_OV:
            case SYS_FS_BOOST_FREQ_OV:
                fileName = "max_freq";
                break;

            case SYS_FS_MIN_FREQ_OV:
                fileName = "min_freq";
                break;

            default:
                MD_ASSERT_A( m_adapterId, false );
                break;
        }

        snprintf( filePath, filePathLength, "/sys/class/drm/card%d/device/tile%u/gt%u/freq%u/%s", m_DrmCardNumber, subDeviceIndex, gt, freq, fileName );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetGpuCpuTimestamps
    //
    // Description:
    //     Reads GPU and CPU timestamp.
    //
    // Input:
    //     CMetricsDevice& device         - (IN)  metrics device
    //     uint64_t& gpuTimestamp         - (OUT) GPU timestamp in ns
    //     uint64_t& cpuTimestamp         - (OUT) CPU timestamp in ns
    //     uint32_t& cpuId                - (OUT) CPU id
    //     uint64_t& correlationIndicator - (out) correlation indicator in ns
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t& gpuTimestamp, uint64_t& cpuTimestamp, uint32_t& cpuId, uint64_t& correlationIndicator )
    {
        auto& subDevices     = device.GetAdapter().GetSubDevices();
        auto  subDeviceIndex = device.GetSubDeviceIndex();
        auto  engine         = TEngineParamsLatest{};
        auto  result         = subDevices.GetTbsEngineParams( subDeviceIndex, engine );

        MD_CHECK_CC_RET_A( m_adapterId, result );

        auto     query                 = drm_xe_device_query{};
        auto     queryTimestamp        = drm_xe_query_engine_cycles{};
        uint64_t oaGpuTimestampCycles  = 0;
        uint64_t gpuTimestampFrequency = 0;

        // Get gpu timestamp frequency.
        result = GetGpuTimestampFrequency( gpuTimestampFrequency );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        // Query timestamp data.
        queryTimestamp.clockid             = CLOCK_MONOTONIC;
        queryTimestamp.eci.engine_class    = static_cast<uint16_t>( engine.EngineId.ClassInstance.Class );
        queryTimestamp.eci.engine_instance = static_cast<uint16_t>( engine.EngineId.ClassInstance.Instance );
        queryTimestamp.width               = 64;

        // Query data.
        query.query = DRM_XE_DEVICE_QUERY_ENGINE_CYCLES;
        query.data  = reinterpret_cast<uint64_t>( &queryTimestamp );
        query.size  = sizeof( queryTimestamp );

        // Send io control.
        result = QueryDrm( query );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        // Convert CS timestamp to OA timestamp.
        result = GetOaTimestamp( queryTimestamp.engine_cycles, oaGpuTimestampCycles );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        // Convert gpu timestamp to ns.
        gpuTimestamp = device.ConvertGpuTimestampToNs( oaGpuTimestampCycles, gpuTimestampFrequency );
        cpuTimestamp = queryTimestamp.cpu_timestamp;

        // Set correlation.
        correlationIndicator = queryTimestamp.cpu_delta;

        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     IsTbsEngineValid
    //
    // Input:
    //     TEngineParamsLatest& engineParams      - engine params
    //     const uint32_t       requestedInstance - requested engine instance
    //     const bool           isOam             - indicates if validated engine is related to oam
    //
    // Output:
    //      bool                                  - result
    //
    // Description:
    //     Checks if engine with given params can be used to open tbs.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxXe::IsTbsEngineValid(
        const TEngineParamsLatest& engineParams,
        const uint32_t             requestedInstance /*= -1*/,
        const bool                 isOam /*= false*/ ) const
    {
        const bool isRenderEngine       = engineParams.EngineId.ClassInstance.Class == DRM_XE_ENGINE_CLASS_RENDER;
        const bool isComputeEngine      = engineParams.EngineId.ClassInstance.Class == DRM_XE_ENGINE_CLASS_COMPUTE;
        const bool isVideoEnhanceEngine = engineParams.EngineId.ClassInstance.Class == DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE;
        const bool isGscEngine          = engineParams.EngineId.ClassInstance.Class == DRM_XE_ENGINE_CLASS_GSC;
        const bool isValidInstance      = ( requestedInstance == static_cast<uint32_t>( -1 ) ) || ( engineParams.EngineId.ClassInstance.Instance == requestedInstance );

        return isValidInstance &&
            ( ( isOam && ( isVideoEnhanceEngine || isGscEngine ) ) ||
                ( !isOam && ( isRenderEngine || isComputeEngine ) ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     IsSubDeviceSupported
    //
    // Description:
    //     Returns true if sub device support is available.
    //
    // Output:
    //     bool - *true* if available
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxXe::IsSubDeviceSupported()
    {
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     EnumerateSubDevices
    //
    // Description:
    //     Detects available sub devices.
    //
    // Input:
    //     CSubDevices& subDevices - sub devices
    //
    // Output:
    //     TCompletionCode         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::EnumerateSubDevices( CSubDevices& subDevices )
    {
        auto            engines = std::vector<OaUnitEngineClassInstancePair>();
        TCompletionCode ret     = CC_OK;

        // Enumerate engines.
        ret = GetEngines( engines );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        // Enumerate sub device engines.
        ret = GetSubDeviceEngines( subDevices, engines );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        // Make space for CMetricsDevices.
        subDevices.MakeSpaceForMetricsDevices();

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Sub devices count %u", subDevices.GetAllEnginesCount() );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetEngines
    //
    // Description:
    //     Returns available engines.
    //
    // Output:
    //     std::vector<OaUnitEngineClassInstancePair>& engines - available engines
    //     TCompletionCode                                     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetEngines(
        std::vector<OaUnitEngineClassInstancePair>& engines )
    {
        auto            buffer = std::vector<uint8_t>();
        TCompletionCode ret    = QueryDrm( DRM_XE_DEVICE_QUERY_OA_UNITS, buffer );
        const size_t    size   = buffer.size();

        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, size ? CC_OK : CC_ERROR_GENERAL );

        // Copy engine data.
        const auto oaData       = reinterpret_cast<drm_xe_query_oa_units*>( buffer.data() );
        auto       oaUnitOffset = reinterpret_cast<uint8_t*>( oaData->oa_units );

        uint32_t currentRenderGtId = 0;

        for( uint32_t i = 0; i < oaData->num_oa_units; ++i )
        {
            const auto& oaUnit = *reinterpret_cast<drm_xe_oa_unit*>( oaUnitOffset );

            if( oaUnit.num_engines == 0 )
            {
                switch( oaUnit.oa_unit_type )
                {
                    case DRM_XE_OA_UNIT_TYPE_OAM_SAG: // GSC engine is not exposed to userspace in the Xe driver.
                    {
                        // OAM SAG unit is not attached to any engine, but it is still a valid unit, so we create a dummy GSC engine for it.
                        drm_xe_engine_class_instance eci = {};
                        eci.engine_class                 = DRM_XE_ENGINE_CLASS_GSC;
                        eci.engine_instance              = DRM_XE_ENGINE_INSTANCE_GSC;
                        eci.gt_id                        = currentRenderGtId + 1; // GSC engine is always on the media GT ID.

                        engines.emplace_back( oaUnit.oa_unit_id, eci );

                        break;
                    }

                    default:
                        MD_LOG_A( m_adapterId, LOG_DEBUG, "OA unit %u has no engines", oaUnit.oa_unit_id );
                        break;
                }
            }
            else
            {
                for( uint32_t j = 0; j < oaUnit.num_engines; ++j )
                {
                    switch( oaUnit.eci[j].engine_class )
                    {
                        case DRM_XE_ENGINE_CLASS_RENDER:
                        case DRM_XE_ENGINE_CLASS_COMPUTE:
                            currentRenderGtId = oaUnit.eci[j].gt_id;
                            [[fallthrough]];

                        case DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE:
                            engines.emplace_back( oaUnit.oa_unit_id, oaUnit.eci[j] );

                        default:
                            break;
                    }
                }
            }

            oaUnitOffset += sizeof( oaUnit ) + oaUnit.num_engines * sizeof( oaUnit.eci[0] );
        }

        MD_ASSERT_A( m_adapterId, engines.size() );

        return engines.size()
            ? CC_OK
            : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetSubDeviceEngines
    //
    // Description:
    //     Returns sub device engines.
    //
    // Input:
    //     CSubDevices&                                      subDevices - sub devices class
    //     const std::vector<OaUnitEngineClassInstancePair>& engines    - engine distances
    //
    // Output:
    //     TCompletionCode                                              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetSubDeviceEngines(
        CSubDevices&                                      subDevices,
        const std::vector<OaUnitEngineClassInstancePair>& engines )
    {
        subDevices.AppendSubDeviceEngine();

        for( uint32_t i = 0; i < engines.size(); ++i )
        {
            auto& [oaUnit, engine]      = engines[i];
            const uint32_t previousGtId = ( i > 0 )
                ? engines[i - 1].second.gt_id
                : engine.gt_id;

            // Video engines have different gt_ids than render, compute and copy engines, so a different gt_id does not mean a new sub device.
            const bool newDevice =
                ( engine.gt_id != previousGtId ) &&
                ( engine.engine_class != DRM_XE_ENGINE_CLASS_VIDEO_DECODE &&
                    engine.engine_class != DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE &&
                    engine.engine_class != DRM_XE_ENGINE_CLASS_GSC );

            if( newDevice )
            {
                subDevices.AppendSubDeviceEngine();
            }

            switch( engine.engine_class )
            {
                case DRM_XE_ENGINE_CLASS_RENDER:
                case DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE:
                case DRM_XE_ENGINE_CLASS_COMPUTE:
                case DRM_XE_ENGINE_CLASS_GSC:
                    MD_LOG_A( m_adapterId, LOG_DEBUG, "Sub device %u / engine %u:%u / GT ID: %u / OA unit: %u", subDevices.GetAllEnginesCount() - 1, engine.engine_class, engine.engine_instance, engine.gt_id, oaUnit );
                    subDevices.AddEngine( engine.engine_class, engine.engine_instance, engine.gt_id, oaUnit );
                    break;

                default:
                    MD_LOG_A( m_adapterId, LOG_ERROR, "Unknown engine type: %u", engine.engine_class );
                    MD_ASSERT_A( m_adapterId, 0 );
                    break;
            }
        }

        const uint32_t subDeviceEngines = subDevices.GetAllEnginesCount();

        MD_ASSERT_A( m_adapterId, subDeviceEngines );

        return subDeviceEngines
            ? CC_OK
            : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     OpenOaStream
    //
    // Description:
    //     Sends IOCTL opening oa stream. Output reports will include header and
    //     OA report part. OA configuration should be already added to kernel at this
    //     point.
    //
    // Input:
    //     CMetricsDevice&           metricsDevice       - metrics device
    //     uint32_t                  oaMetricSetId       - oa configuration ID (previously added)
    //     uint32_t                  oaReportType        - oa report type
    //     uint32_t                  oaReportSize        - oa report size
    //     uint32_t                  timerPeriodExponent - timer period exponent
    //     uint32_t                  bufferSize          - oa buffer size
    //     const GTDI_OA_BUFFER_TYPE oaBufferType        - oa buffer type
    //
    // Output:
    //     TCompletionCode                               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::OpenOaStream( CMetricsDevice& metricsDevice, uint32_t oaMetricSetId, uint32_t oaReportType, uint32_t oaReportSize, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        TCompletionCode         ret                                                                          = CC_ERROR_GENERAL;
        int32_t                 oaEventFd                                                                    = -1;
        uint32_t                requiredEngineInstance                                                       = -1;
        const bool              isOamRequested                                                               = IsOamRequested( oaReportType, oaBufferType );
        const uint32_t          subDeviceIndex                                                               = metricsDevice.GetSubDeviceIndex();
        auto                    subDevices                                                                   = metricsDevice.GetAdapter().GetSubDevices();
        auto                    engine                                                                       = TEngineParamsLatest{};
        auto                    param                                                                        = drm_xe_observation_param{};
        drm_xe_ext_set_property properties[DRM_XE_OA_PROPERTY_NO_PREEMPT - DRM_XE_OA_EXTENSION_SET_PROPERTY] = {};
        uint32_t                currentIndex                                                                 = 0;

        auto isValidValue = []( uint32_t value )
        {
            return value != static_cast<uint32_t>( -1 );
        };

        auto addProperty = [&]( const uint64_t key, const uint64_t value )
        {
            auto& property     = properties[currentIndex];
            property           = {};
            property.base.name = DRM_XE_OA_EXTENSION_SET_PROPERTY;
            property.property  = key;
            property.value     = value;

            if( currentIndex > 0 )
            {
                properties[currentIndex - 1].base.next_extension = reinterpret_cast<uint64_t>( &property );
            }

            ++currentIndex;
        };

        if( oaBufferType != GTDI_OA_BUFFER_TYPE_OAG )
        {
            if( m_xeObservationCapabilities.IsOamSagSupported && oaBufferType == GTDI_OA_BUFFER_TYPE_OAM_SAG )
            {
                requiredEngineInstance = DRM_XE_ENGINE_INSTANCE_GSC;
            }
            else
            {
                const uint32_t oamBufferSlice = static_cast<uint32_t>( oaBufferType ) - GTDI_OA_BUFFER_TYPE_OAM_SLICE_0;
                if( !isValidValue( oamBufferSlice ) )
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Incorrect oa buffer type for OAM. oaBufferType: %d, oamBufferSlice: %d", static_cast<uint32_t>( oaBufferType ), oamBufferSlice );
                    return CC_ERROR_INVALID_PARAMETER;
                }

                uint32_t baseEngineInstance = 0;
                for( uint32_t i = 0; i < subDeviceIndex; ++i )
                {
                    const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( i, DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE );

                    ret = isValidValue( videoEnhanceEngineCount )
                        ? CC_ERROR_GENERAL
                        : CC_OK;
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    baseEngineInstance += videoEnhanceEngineCount;
                }

                requiredEngineInstance = baseEngineInstance + oamBufferSlice;
            }
        }

        ret = subDevices.GetTbsEngineParams( subDeviceIndex, engine, requiredEngineInstance, isOamRequested );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Error: No requested engine found, unable to open tbs on sub device. subDeviceIndex: %d, isOam: %d", subDeviceIndex, isOamRequested );
            return CC_ERROR_NOT_SUPPORTED;
        }

        // Standard tbs properties.
        addProperty( DRM_XE_OA_PROPERTY_OA_UNIT_ID, engine.OaUnit );
        addProperty( DRM_XE_OA_PROPERTY_SAMPLE_OA, true );
        addProperty( DRM_XE_OA_PROPERTY_OA_METRIC_SET, oaMetricSetId );
        addProperty( DRM_XE_OA_PROPERTY_OA_FORMAT, oaReportType );
        addProperty( DRM_XE_OA_PROPERTY_OA_PERIOD_EXPONENT, timerPeriodExponent );

        // Oa buffer size.
        if( m_xeObservationCapabilities.IsConfigurableOaBufferSize )
        {
            bufferSize = CalculateOaBufferSize( bufferSize, metricsDevice );
            addProperty( DRM_XE_OA_PROPERTY_OA_BUFFER_SIZE, bufferSize );
        }
        else
        {
            bufferSize = MD_OA_BUFFER_SIZE_MAX;
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Cannot set oa buffer size. Configurable OA buffer size is not available." );
        }

        // Half-full buffer interrupt.
        if( m_xeObservationCapabilities.IsOaNotifyNumReportsSupported )
        {
            const uint32_t halfSizeInReports = bufferSize / 2 / oaReportSize;

            addProperty( DRM_XE_OA_PROPERTY_WAIT_NUM_REPORTS, halfSizeInReports );

            MD_LOG_A( m_adapterId, LOG_DEBUG, "Number of reports KMD needs to wait before unblocking is %u", halfSizeInReports );
        }

        param.observation_type = DRM_XE_OBSERVATION_TYPE_OA;
        param.observation_op   = DRM_XE_OBSERVATION_OP_STREAM_OPEN;
        param.param            = reinterpret_cast<uint64_t>( properties );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Opening XE OA stream with params: oaUnit: %u, oaMetricSetId: %u, oaReportType: %u, timerPeriodExponent: %u, bufferSize: %u", engine.OaUnit, oaMetricSetId, oaReportType, timerPeriodExponent, bufferSize );

        oaEventFd = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_XE_OBSERVATION, &param );

        if( oaEventFd == -1 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Opening XE OA stream failed, errno: %d (%s)", errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        // We want a non-blocking read.
        if( const int32_t oldFlags = fcntl( oaEventFd, F_GETFL, 0 );
            oldFlags != -1 )
        {
            if( fcntl( oaEventFd, F_SETFL, oldFlags | O_CLOEXEC | O_NONBLOCK ) == -1 )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Cannot set a non-blocking read" );
                return CC_ERROR_GENERAL;
            }
        }

        metricsDevice.SetStreamId( oaEventFd );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "XE OA stream opened successfully, fd: %d", oaEventFd );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     ReadOaStream
    //
    // Description:
    //     Reads data from the previously opened oa stream and copies only OA reports
    //     to the output buffer. If report lost header is obtained or oa buffer overflows,
    //     exception flags are set.
    //
    // Input:
    //     CMetricsDevice&                  metricsDevice - metrics device
    //     uint32_t                         reportSize    - size of a single OA report
    //     uint32_t                         reportsToRead - number of reports to read
    //     char*                            reportData    - (OUT) buffer for reports
    //     uint32_t&                        readBytes     - (OUT) number of bytes read and copied to the output buffer
    //     GTDIReadCounterStreamExceptions& exceptions    - (OUT) exception flags reported by XE OA
    //
    // Output:
    //     TCompletionCode                   - *CC_OK* means success, BUT IT DOESN'T MEAN ALL REQUESTED DATA WAS READ !!
    //                                         (check readBytes for that).
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::ReadOaStream( CMetricsDevice& metricsDevice, uint32_t reportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions )
    {
        const int32_t streamId = metricsDevice.GetStreamId();

        if( streamId < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: oa stream not opened" );
            return CC_ERROR_FILE_NOT_FOUND;
        }

        const size_t bytesToRead = reportsToRead * reportSize;

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Trying to read %u reports from XE OA stream, fd: %d", reportsToRead, streamId );

        // #Note May read 1 sample less than requested if ReportLost is returned from kernel

        // 1. READ STREAM DATA
        int32_t xeReadBytes = read( streamId, reportData, bytesToRead );
        if( xeReadBytes < 0 )
        {
            if( errno == EIO )
            {
                // 2. READ STREAM STATUS
                auto    status = drm_xe_oa_stream_status{};
                int32_t result = SendIoctl( streamId, DRM_XE_OBSERVATION_IOCTL_STATUS, &status );

                if( result != -1 )
                {
                    exceptions.ReportLost     = ( status.oa_status & DRM_XE_OASTATUS_REPORT_LOST ) != 0;
                    exceptions.BufferOverflow = ( status.oa_status & DRM_XE_OASTATUS_BUFFER_OVERFLOW ) != 0;

                    // 3. READ STREAM DATA AGAIN
                    xeReadBytes = read( streamId, reportData, bytesToRead );
                }
                else
                {
                    readBytes = 0;
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to send DRM_XE_OBSERVATION_IOCTL_STATUS ioctl" );
                    return CC_ERROR_GENERAL;
                }
            }

            if( xeReadBytes < 0 )
            {
                readBytes = 0;
                if( errno == EAGAIN )
                {
                    MD_LOG_A( m_adapterId, LOG_DEBUG, "XE OA stream data not available yet" );
                    return CC_OK;
                }
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Reading XE OA stream failed, errno: %d (%s)", errno, strerror( errno ) );
                return CC_ERROR_GENERAL;
            }
        }
        MD_LOG_A( m_adapterId, LOG_DEBUG, "Read %u bytes (= %lu reports)", xeReadBytes, xeReadBytes / reportSize );

        readBytes = xeReadBytes;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     AddOaConfig
    //
    // Description:
    //     Adds OA configuration to the kernel through XE OA interface. If no GUID passed
    //     in parameter, GUID of the added configuration is calculated based on concatenated
    //     register offsets and values string.
    //     When the same configuration is already added, its ID is reused (configuration isn't
    //     send for the second time).
    //
    // Input:
    //     TRegister**    regVector      - array of pointers to registers to send (add)
    //     const uint32_t regCount       - register count
    //     const uint32_t subDeviceIndex - sub device index
    //     const char*    requestedGuid  - [optional] GUID under which configuration will be added, if nullptr GUID will be generated
    //     int32_t&       addedConfigId  - (OUT) added oa configuration ID, -1 if error
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::AddOaConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, regVector, CC_ERROR_INVALID_PARAMETER );
        if( !regCount )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Empty configuration" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode                       ret  = CC_OK;
        const char*                           guid = requestedGuid;
        std::vector<iu_xe_oa_config_register> registers;
        std::string                           regsString; // For hash (guid)

        // 1. TRANSFORM CONFIG TO XE OA FORMAT
        MD_LOG_A( m_adapterId, LOG_DEBUG, "AddOaConfig regCount: %u", regCount );
        for( uint32_t i = 0; i < regCount; i++ )
        {
            if( regVector[i] )
            {
                registers.push_back( { regVector[i]->offset, regVector[i]->value } );
                if( !guid )
                {
                    regsString += regVector[i]->offset;
                    regsString += regVector[i]->value;
                }
                MD_LOG_A( m_adapterId, LOG_DEBUG, "regOffset: %#x, regValue: %#x", regVector[i]->offset, regVector[i]->value );
            }
        }

        // 2. GENERATE CONFIG GUID (if needed) - string formatted like "%08x-%04x-%04x-%04x-%012x"
        char generatedGuid[MD_PERF_GUID_LENGTH];
        if( !guid )
        {
            std::hash<std::string> stringHash;

            // Use std::hash for GUID generation
            snprintf( generatedGuid, sizeof( generatedGuid ), "%08x-%04x-%04x-%04x-%012x", 0, 0, subDeviceIndex, 0, static_cast<uint32_t>( stringHash( regsString ) ) );
            guid = generatedGuid;
        }

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Adding configuration under guid: %s", guid );

        // 3. SET PARAMS
        drm_xe_oa_config configParam = {};

        static_assert( sizeof( configParam.uuid ) == ( MD_PERF_GUID_LENGTH - 1 ), "GUID length mismatch with XE OA API" );
        iu_memcpy_s( configParam.uuid, sizeof( configParam.uuid ), guid, MD_PERF_GUID_LENGTH - 1 ); // Copy without ending '\0' (size 36)

        configParam.regs_ptr = reinterpret_cast<uint64_t>( registers.data() );
        configParam.n_regs   = static_cast<uint32_t>( registers.size() );

        auto param = drm_xe_observation_param{};

        param.observation_type = DRM_XE_OBSERVATION_TYPE_OA;
        param.observation_op   = DRM_XE_OBSERVATION_OP_ADD_CONFIG;
        param.param            = reinterpret_cast<uint64_t>( &configParam );

        // 4. ADD CONFIG TO XE OA
        addedConfigId = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_XE_OBSERVATION, &param );
        if( addedConfigId == -1 )
        {
            if( errno != EADDRINUSE ) // errno == 98 (EADDRINUSE) means set with the given GUID is already added
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Adding XE OA configuration failed, errno: %s (%d)", strerror( errno ), errno );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Configuration with the given GUID already added, reusing" );
                ret = GetOaMetricSetId( guid, addedConfigId );
            }
        }

        if( ret == CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "XE OA configuration added/reused, id: %d", addedConfigId );
        }

        MD_LOG_EXIT_A( m_adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     RemoveOaConfig
    //
    // Description:
    //     Removes from XE OA previously added OA config based on its ID.
    //
    //     Note from XE: "Configs can be removed while being used, they will stop appearing in SysFs
    //                    and their content will be freed when the stream using the config is closed."
    //
    // Input:
    //     int32_t oaConfigId - valid oa configuration ID (previously added)
    //
    // Output:
    //     TCompletionCode    - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::RemoveOaConfig( int32_t oaConfigId )
    {
        TCompletionCode ret = CC_OK;

        // Note from XE: "Configs can be removed while being used, they will stop appearing in SysFs
        //                and their content will be freed when the stream using the config is closed."

        if( oaConfigId != -1 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Removing XE OA configuration with id: %d", oaConfigId );

            uint64_t oaConfigId64 = static_cast<uint64_t>( oaConfigId );

            auto param             = drm_xe_observation_param{};
            param.observation_type = DRM_XE_OBSERVATION_TYPE_OA;
            param.observation_op   = DRM_XE_OBSERVATION_OP_REMOVE_CONFIG;
            param.param            = reinterpret_cast<uint64_t>( &oaConfigId64 );

            const int32_t ioctlResult = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_XE_OBSERVATION, &param );
            if( ioctlResult )
            {
                if( errno != ENOENT ) // errno == 2 (ENOENT) means set with the given ID doesn't exist
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing XE OA configuration with id %d failed, config not found", oaConfigId );
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing XE OA configuration with id %d failed, errno: %d (%s)", oaConfigId, errno, strerror( errno ) );
                }
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "XE OA configuration with id %d removed", oaConfigId );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaReportType
    //
    // Description:
    //     Returns XE OA report format based on MDAPI report type and current platform.
    //
    // Input:
    //     const TReportType reportType - MDAPI report type
    //
    // Output:
    //     uint32_t                     - XE OA report format, XE_OA_FORMAT_MAX if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxXe::GetOaReportType( const TReportType reportType )
    {
        // Get platform ID
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  ret           = GetGfxDeviceInfo( gfxDeviceInfo );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Cannot obtain device info" );
            return -1;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_BMG:
            case GENERATION_LNL:
            case GENERATION_PTL:
            case GENERATION_NVL:
            case GENERATION_CRI:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_320B_PEC64:
                        return ( DRM_XE_OA_FMT_TYPE_PEC | ( 1 << 8 ) | ( 0 << 16 ) | ( 0 << 24 ) ); // counter select = 1, counter size = 0, bc report = 0
                    case OA_REPORT_TYPE_576B_PEC64LL:
                        return ( DRM_XE_OA_FMT_TYPE_PEC | ( 1 << 8 ) | ( 1 << 16 ) | ( 0 << 24 ) ); // counter select = 1, counter size = 1, bc report = 0
                    case OA_REPORT_TYPE_640B_PEC64LL_NOA16:
                        return ( DRM_XE_OA_FMT_TYPE_PEC | ( 1 << 8 ) | ( 1 << 16 ) | ( 1 << 24 ) ); // counter select = 1, counter size = 1, bc report = 1
                    case OA_REPORT_TYPE_128B_MPEC8_NOA16:
                        return ( DRM_XE_OA_FMT_TYPE_OAM_MPEC | ( 2 << 8 ) | ( 0 << 16 ) | ( 0 << 24 ) ); // counter select = 2, counter size = 0, bc report = 0
                    case OA_REPORT_TYPE_192B_MPEC8LL_NOA16:
                        return ( DRM_XE_OA_FMT_TYPE_OAM_MPEC | ( 1 << 8 ) | ( 0 << 16 ) | ( 0 << 24 ) ); // counter select = 1, counter size = 0, bc report = 0
                    default:
                        return -1;
                }
            }
            default:
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "ERROR: Unknown platform" );
                return -1;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetQueryDrmDataLength
    //
    // Description:
    //     Returns drm data information length.
    //
    // Input:
    //     const uint32_t   queryId   - query identifier
    //     const uint32_t   flags     - query item flags
    //
    // Output:
    //     uint32_t                   - drm query information length
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxXe::GetQueryDrmDataLength( const uint32_t queryId )
    {
        auto query = drm_xe_device_query{};

        query.query = queryId;

        const bool validCall   = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_XE_DEVICE_QUERY, &query ) == 0;
        const bool validLength = query.size > 0;

        return ( validCall && validLength )
            ? query.size
            : 0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     QueryDrm
    //
    // Description:
    //     Allows to query drm to obtain needed information.
    //
    // Input:
    //     const uint32_t           queryId   - query identifier
    //     const uint32_t           flags     - query item flags
    //
    // Output:
    //     std::vector<uint8_t>&    data      - query data
    //     TCompletionCode                    - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::QueryDrm(
        const uint32_t        queryId,
        std::vector<uint8_t>& data )
    {
        // Prepare space for query data.
        data.resize( GetQueryDrmDataLength( queryId ) );

        // Prepare query.
        auto query = drm_xe_device_query{};

        query.query = queryId;
        query.size  = data.size();
        query.data  = reinterpret_cast<uint64_t>( data.data() );

        // Input check.
        if( query.size == 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: invalid drm query data length" );
            return CC_ERROR_GENERAL;
        }

        // Send io control.
        return QueryDrm( query );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     QueryDrm
    //
    // Description:
    //     Allows to query drm to obtain needed information.
    //
    // Input:
    //     drm_xe_device_query& query - [In/Out] query data
    //
    // Output:
    //     TCompletionCode            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::QueryDrm( drm_xe_device_query& query )
    {
        if( SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_XE_DEVICE_QUERY, &query ) )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: invalid drm query result" );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     ReadXeObservationCapabilities
    //
    // Description:
    //     Checks whether certain Xe observation features are supported.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::ReadXeObservationCapabilities()
    {
        m_xeObservationCapabilities = {};

        auto            buffer = std::vector<uint8_t>();
        TCompletionCode ret    = QueryDrm( DRM_XE_DEVICE_QUERY_OA_UNITS, buffer );
        const size_t    size   = buffer.size();

        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, size ? CC_OK : CC_ERROR_GENERAL );

        // Copy engine data.
        const auto oaData       = reinterpret_cast<drm_xe_query_oa_units*>( buffer.data() );
        auto       oaUnitOffset = reinterpret_cast<uint8_t*>( oaData->oa_units );

        for( uint32_t i = 0; i < oaData->num_oa_units; ++i )
        {
            const auto& oaUnit = *reinterpret_cast<drm_xe_oa_unit*>( oaUnitOffset );

            switch( oaUnit.oa_unit_type )
            {
                case DRM_XE_OA_UNIT_TYPE_OAG:
                    m_xeObservationCapabilities.IsConfigurableOaBufferSize    = oaUnit.capabilities & DRM_XE_OA_CAPS_OA_BUFFER_SIZE;
                    m_xeObservationCapabilities.IsOaNotifyNumReportsSupported = oaUnit.capabilities & DRM_XE_OA_CAPS_WAIT_NUM_REPORTS;

                    MD_LOG_A( m_adapterId, LOG_INFO, "Configurable OA buffer size is%s supported", m_xeObservationCapabilities.IsConfigurableOaBufferSize ? "" : " not" );
                    MD_LOG_A( m_adapterId, LOG_INFO, "Oa notify num reports is%s supported", m_xeObservationCapabilities.IsOaNotifyNumReportsSupported ? "" : " not" );
                    break;

                case DRM_XE_OA_UNIT_TYPE_OAM:
                    m_xeObservationCapabilities.IsOamScmiSupported = oaUnit.capabilities & DRM_XE_OA_CAPS_OAM;

                    MD_LOG_A( m_adapterId, LOG_INFO, "OAM SCMI is%s supported", m_xeObservationCapabilities.IsOamScmiSupported ? "" : " not" );
                    break;

                case DRM_XE_OA_UNIT_TYPE_OAM_SAG:
                    m_xeObservationCapabilities.IsOamSagSupported = oaUnit.capabilities & DRM_XE_OA_CAPS_OAM;

                    MD_LOG_A( m_adapterId, LOG_INFO, "OAM SAG is%s supported", m_xeObservationCapabilities.IsOamSagSupported ? "" : " not" );
                    break;

                default:
                    MD_LOG_A( m_adapterId, LOG_DEBUG, "Unknown OA unit type: %u", oaUnit.oa_unit_type );
                    break;
            }

            oaUnitOffset += sizeof( oaUnit ) + oaUnit.num_engines * sizeof( oaUnit.eci[0] );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetGeometryTopology
    //
    // Description:
    //     Allows to query drm to obtain query information per subdevice.
    //
    // Input:
    //     std::vector<uint8_t>&    buffer         - [In/Out] data
    //     CMetricsDevice&          metricsDevice  - a reference to device
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetGeometryTopology( std::vector<uint8_t>& buffer, CMetricsDevice& metricsDevice )
    {
        TCompletionCode ret = QueryDrm( DRM_XE_DEVICE_QUERY_GT_TOPOLOGY, buffer );

        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetSliceMask
    //
    // Description:
    //     Allows to obtain slice mask value.
    //     Works only on Xe+ platforms.
    //
    // Input:
    //     int32_t&        sliceMask        - (OUT) data
    //     CMetricsDevice& metricsDevice    - a reference to device
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetSliceMask( int32_t& sliceMask, CMetricsDevice& metricsDevice )
    {
        TCompletionCode ret = CC_OK;

        sliceMask = 0;

        // Return value is a mask of enabled subslices or dual-subslices
        uint32_t subslicePerSlice = GetGtMaxSubslicePerSlice();
        int64_t  subsliceMask     = 0;
        ret                       = GetSubsliceMask( subsliceMask, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        for( uint32_t i = 0; i < MD_MAX_SLICE; ++i )
        {
            if( ( subsliceMask >> ( subslicePerSlice * i ) ) & MD_BITMASK( subslicePerSlice ) )
            {
                sliceMask |= MD_BIT( i );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetSubsliceMask
    //
    // Description:
    //     Allows to obtain subslice mask or dual-subslice mask (depends on platform) value per sub device.
    //
    // Input:
    //     int64_t&        subsliceMask     - (OUT) data
    //     CMetricsDevice& metricsDevice    - a reference to device
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetSubsliceMask( int64_t& subsliceMask, CMetricsDevice& metricsDevice )
    {
        TCompletionCode ret = CC_OK;

        subsliceMask = 0;

        MD_LOG_A( m_adapterId, LOG_INFO, "Obtaining subslice mask" );

        // Get subslice mask per sub device.
        auto buffer = std::vector<uint8_t>();
        ret         = GetGeometryTopology( buffer, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        uint32_t dataOffset = 0;

        int64_t geometrySubsliceMask = 0;
        int64_t computeSubsliceMask  = 0;

        while( dataOffset < buffer.size() )
        {
            auto topology = reinterpret_cast<drm_xe_query_topology_mask*>( buffer.data() + dataOffset );

            if( topology->gt_id == subDeviceIndex * 2 ) // GT ID = x is 3D/Compute, GT ID = x+1 is Media, where x is even number.
            {
                for( uint32_t i = 0; i < topology->num_bytes; ++i )
                {
                    switch( topology->type )
                    {
                        case DRM_XE_TOPO_DSS_GEOMETRY:
                            geometrySubsliceMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                            break;

                        case DRM_XE_TOPO_DSS_COMPUTE:
                            computeSubsliceMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                            break;

                        default:
                            // Nothing on purpose.
                            break;
                    }
                }
            }

            dataOffset += sizeof( drm_xe_query_topology_mask ) + topology->num_bytes;
        }

        // Choose the mask with more enabled bits.
        const uint32_t geometrySubsliceCount = CalculateEnabledBits( geometrySubsliceMask );
        const uint32_t computeSubsliceCount  = CalculateEnabledBits( computeSubsliceMask );

        subsliceMask = ( geometrySubsliceCount > computeSubsliceCount )
            ? geometrySubsliceMask
            : computeSubsliceMask;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetEuCoresTotalCount
    //
    // Description:
    //     Allows to obtain EuCoresTotalCount value per sub device.
    //
    // Input:
    //     GTDIDeviceInfoParamExtOut& out            - (OUT) data
    //     CMetricsDevice&            metricsDevice  - a reference to device
    //
    // Output:
    //     TCompletionCode                           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )
    {
        // Get EuCoresTotalCount per sub device.
        auto buffer = std::vector<uint8_t>();

        TCompletionCode ret = GetGeometryTopology( buffer, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        out.ValueUint32 = 0;
        out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;

        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        uint64_t geometrySubsliceMask = 0;
        uint64_t computeSubsliceMask  = 0;
        uint64_t vectorEngineMask     = 0;

        uint32_t dataOffset = 0;

        while( dataOffset < buffer.size() )
        {
            auto topology = reinterpret_cast<drm_xe_query_topology_mask*>( buffer.data() + dataOffset );

            if( topology->gt_id == subDeviceIndex * 2 ) // GT ID = x is 3D/Compute, GT ID = x+1 is Media, where x is even number.
            {
                for( uint32_t i = 0; i < topology->num_bytes; ++i )
                {
                    switch( topology->type )
                    {
                        case DRM_XE_TOPO_DSS_GEOMETRY:
                            geometrySubsliceMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                            break;

                        case DRM_XE_TOPO_DSS_COMPUTE:
                            computeSubsliceMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                            break;

                        case DRM_XE_TOPO_SIMD16_EU_PER_DSS:
                            vectorEngineMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                            break;

                        default:
                            // Nothing on purpose.
                            break;
                    }
                }
            }

            dataOffset += sizeof( drm_xe_query_topology_mask ) + topology->num_bytes;
        }

        const uint32_t geometrySubsliceCount = CalculateEnabledBits( geometrySubsliceMask );
        const uint32_t computeSubsliceCount  = CalculateEnabledBits( computeSubsliceMask );
        const uint32_t vectorEngineCount     = CalculateEnabledBits( vectorEngineMask );

        out.ValueUint32 = std::max( geometrySubsliceCount, computeSubsliceCount ) * vectorEngineCount;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetEuCoresPerSubsliceCount
    //
    // Description:
    //     Allows to obtain EuCoresTotalCount value per sub device.
    //
    // Input:
    //     GTDIDeviceInfoParamExtOut& out            - (OUT) data
    //     CMetricsDevice&            metricsDevice  - a reference to device
    //
    // Output:
    //     TCompletionCode                           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetEuCoresPerSubsliceCount( GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )
    {
        TCompletionCode ret = GetEuCoresTotalCount( out, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        int64_t subsliceMask = 0;
        ret                  = GetSubsliceMask( subsliceMask, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        uint32_t subslicesTotalCount = CalculateEnabledBits( subsliceMask );
        uint32_t euCoresTotalCount   = out.ValueUint32;

        out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
        out.ValueUint32 = ( subslicesTotalCount > 0 ) ? ( euCoresTotalCount / subslicesTotalCount ) : 0;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetChipsetId
    //
    // Description:
    //     Returns DeviceId (ChipsetId) obtained from kernel using DRM_XE_DEVICE_QUERY_CONFIG IOCTL.
    //
    // Input:
    //     int32_t& deviceId - (OUT) returned DeviceId
    //
    // Output:
    //     TCompletionCode   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetDeviceId( int32_t& deviceId )
    {
        TCompletionCode ret = CC_OK;

        if( m_CachedDeviceId == -1 )
        {
            std::vector<uint8_t> buffer = {};

            ret = QueryDrm( DRM_XE_DEVICE_QUERY_CONFIG, buffer );

            MD_CHECK_CC_RET_A( m_adapterId, ret );
            MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

            auto config = reinterpret_cast<drm_xe_query_config*>( buffer.data() );

            m_CachedDeviceId = config->info[DRM_XE_QUERY_CONFIG_REV_AND_DEVICE_ID] & 0xffff;

            // Get revision id.
            if( m_CachedRevisionId == -1 )
            {
                m_CachedRevisionId = config->info[DRM_XE_QUERY_CONFIG_REV_AND_DEVICE_ID] >> 16;
            }
        }

        deviceId = m_CachedDeviceId;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetRevisionId
    //
    // Description:
    //     Returns RevisionId obtained from kernel using DRM_XE_DEVICE_QUERY_CONFIG IOCTL.
    //
    // Input:
    //     int32_t& revisionId - (OUT) returned RevisionId
    //
    // Output:
    //     TCompletionCode     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetRevisionId( int32_t& revisionId )
    {
        TCompletionCode ret = CC_OK;

        if( m_CachedRevisionId == -1 )
        {
            std::vector<uint8_t> buffer = {};

            ret = QueryDrm( DRM_XE_DEVICE_QUERY_CONFIG, buffer );

            MD_CHECK_CC_RET_A( m_adapterId, ret );
            MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

            auto config = reinterpret_cast<drm_xe_query_config*>( buffer.data() );

            m_CachedRevisionId = config->info[DRM_XE_QUERY_CONFIG_REV_AND_DEVICE_ID] >> 16;

            // Get device id.
            if( m_CachedDeviceId == -1 )
            {
                m_CachedDeviceId = config->info[DRM_XE_QUERY_CONFIG_REV_AND_DEVICE_ID] & 0xffff;
            }
        }

        revisionId = m_CachedRevisionId;

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaTimestampFrequency
    //
    // Description:
    //     Returns oa timestamp frequency.
    //
    // Input:
    //     uint64_t& frequency - (OUT) oa timestamp frequency
    //
    // Output:
    //     TCompletionCode     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetOaTimestampFrequency( uint64_t& frequency )
    {
        if( m_CachedOaTimestampFrequency == 0 )
        {
            std::vector<uint8_t> buffer = {};
            TCompletionCode      ret    = QueryDrm( DRM_XE_DEVICE_QUERY_OA_UNITS, buffer );

            MD_CHECK_CC_RET_A( m_adapterId, ret );
            MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

            const auto oaData = reinterpret_cast<drm_xe_query_oa_units*>( buffer.data() );
            const auto oaUnit = reinterpret_cast<drm_xe_oa_unit*>( oaData->oa_units );

            m_CachedOaTimestampFrequency = oaUnit->oa_timestamp_freq;
        }

        frequency = m_CachedOaTimestampFrequency;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetCsTimestampFrequency
    //
    // Description:
    //     Returns cs timestamp frequency.
    //
    // Input:
    //     uint64_t& frequency - (OUT) cs timestamp frequency
    //
    // Output:
    //     TCompletionCode     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetCsTimestampFrequency( uint64_t& frequency )
    {
        if( m_CachedCsTimestampFrequency == 0 )
        {
            std::vector<uint8_t> buffer = {};
            TCompletionCode      ret    = QueryDrm( DRM_XE_DEVICE_QUERY_GT_LIST, buffer );

            MD_CHECK_CC_RET_A( m_adapterId, ret );
            MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

            auto gtsData = reinterpret_cast<drm_xe_query_gt_list*>( buffer.data() );

            m_CachedCsTimestampFrequency = gtsData->gt_list[0].reference_clock;
        }

        frequency = m_CachedCsTimestampFrequency;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     IsOamRequested
    //
    // Description:
    //     Returns information if access to oam requested.
    //
    // Input:
    //     const uint32_t            reportType   - report type
    //     const GTDI_OA_BUFFER_TYPE oaBufferType - oa buffer type
    //
    // Output:
    //     bool                      - true if access to oam requested.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxXe::IsOamRequested( const uint32_t reportType, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        return ( DRM_XE_OA_FORMAT_MASK_FMT_TYPE & reportType ) == DRM_XE_OA_FMT_TYPE_OAM_MPEC;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaBufferSize
    //
    // Description:
    //     Returns oa buffer size for current platform.
    //
    // Input:
    //     const int32_t   streamId     - (IN) stream id
    //     uint32_t&       oaBufferSize - (OUT) oa buffer size
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetOaBufferSize( const int32_t streamId, uint32_t& oaBufferSize )
    {
        auto properties = drm_xe_oa_stream_info{};

        int32_t result = SendIoctl( streamId, DRM_XE_OBSERVATION_IOCTL_INFO, &properties );

        if( result == -1 )
        {
            oaBufferSize = 0;
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to send DRM_XE_OBSERVATION_IOCTL_INFO ioctl" );
            return CC_ERROR_GENERAL;
        }

        oaBufferSize = properties.oa_buf_size;
        MD_LOG_A( m_adapterId, LOG_INFO, "Oa buffer size is %d", oaBufferSize );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaBufferSupportedSizes
    //
    // Description:
    //     Returns oa buffer supported sizes.
    //
    // Input:
    //     const uint32_t  platformId - (IN) platform index
    //     uint32_t&       minSize    - (OUT) oa buffer minimum supported size
    //     uint32_t&       maxSize    - (OUT) oa buffer maximum supported size
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetOaBufferSupportedSizes( const uint32_t platformId, uint32_t& minSize, uint32_t& maxSize )
    {
        if( m_xeObservationCapabilities.IsConfigurableOaBufferSize )
        {
            minSize = MD_OA_BUFFER_SIZE_MIN;
            maxSize = MD_OA_BUFFER_SIZE_MAX_XE_HP;
        }
        else
        {
            minSize = MD_OA_BUFFER_SIZE_MAX;
            maxSize = MD_OA_BUFFER_SIZE_MAX;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaBufferCount
    //
    // Description:
    //     Returns oa buffer count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - metrics device
    //
    // Output:
    //     uint32_t                      - oa buffer count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxXe::GetOaBufferCount( CMetricsDevice& metricsDevice )
    {
        uint32_t oaBufferCount = 1; // OAG/OA buffer

        auto           subDevices     = metricsDevice.GetAdapter().GetSubDevices();
        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        if( m_xeObservationCapabilities.IsOamScmiSupported )
        {
            const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( subDeviceIndex, DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE );

            if( videoEnhanceEngineCount == std::numeric_limits<uint32_t>::max() )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Getting video enhance engine count failed" );
                return 0;
            }

            oaBufferCount += videoEnhanceEngineCount; // Video enhance engines map to media slices (OAM SCMI).
        }

        if( m_xeObservationCapabilities.IsOamSagSupported )
        {
            const uint32_t gscEngineCount = subDevices.GetClassInstancesCount( subDeviceIndex, DRM_XE_ENGINE_CLASS_GSC );

            if( gscEngineCount == std::numeric_limits<uint32_t>::max() )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Getting GSC engine count failed" );
                return 0;
            }

            oaBufferCount += gscEngineCount; // OAM SAG
        }

        return oaBufferCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetOaBufferMask
    //
    // Description:
    //     Returns oa buffer mask for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - metrics device
    //
    // Output:
    //     uint32_t                      - oa buffer mask
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxXe::GetOaBufferMask( CMetricsDevice& metricsDevice )
    {
        uint32_t oaBufferMask = GTDI_OA_BUFFER_MASK_OAG;

        auto           subDevices     = metricsDevice.GetAdapter().GetSubDevices();
        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        if( m_xeObservationCapabilities.IsOamScmiSupported )
        {
            const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( subDeviceIndex, DRM_XE_ENGINE_CLASS_VIDEO_ENHANCE );

            for( uint32_t i = 0; i < videoEnhanceEngineCount; ++i )
            {
                oaBufferMask |= ( 1 << ( GTDI_OA_BUFFER_TYPE_OAM_SLICE_0 + i ) ); // Video enhance engines map to media slices (OAM SCMI).
            }
        }

        if( m_xeObservationCapabilities.IsOamSagSupported )
        {
            if( subDevices.GetClassInstancesCount( subDeviceIndex, DRM_XE_ENGINE_CLASS_GSC ) > 0 )
            {
                oaBufferMask |= GTDI_OA_BUFFER_MASK_OAM_SAG; // OAM SAG
            }
        }

        return oaBufferMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetL3NodeTotalCount
    //
    // Description:
    //     Returns L3 node count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint32_t&       l3NodeCount   - (OUT) L3 node count
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetL3NodeTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3NodeCount )
    {
        uint64_t l3NodeMask = 0;
        auto     ret        = GetL3NodeMask( metricsDevice, l3NodeMask );

        MD_CHECK_CC_RET_A( m_adapterId, ret );

        l3NodeCount = CalculateEnabledBits( l3NodeMask );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetL3BankTotalCount
    //
    // Description:
    //     Returns L3 bank count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint32_t&       l3BankCount   - (OUT) L3 bank count
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetL3BankTotalCount( CMetricsDevice& metricsDevice, uint32_t& l3BankCount )
    {
        uint64_t l3BankMask = 0;
        auto     ret        = GetL3BankMask( metricsDevice, l3BankMask );

        MD_CHECK_CC_RET_A( m_adapterId, ret );

        l3BankCount = CalculateEnabledBits( l3BankMask );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetCopyEngineTotalCount
    //
    // Description:
    //     Returns copy engine count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice   - (IN) metrics device
    //     uint32_t&       copyEngineCount - (OUT) copy engine count
    //
    // Output:
    //     TCompletionCode                 - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetCopyEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& copyEngineCount )
    {
        uint64_t copyEngineMask = 0;
        auto     ret            = GetCopyEngineMask( metricsDevice, copyEngineMask );

        MD_CHECK_CC_RET_A( m_adapterId, ret );

        copyEngineCount = CalculateEnabledBits( copyEngineMask );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetComputeEngineTotalCount
    //
    // Description:
    //     Returns compute engines count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice        - (IN) metrics device
    //     uint32_t&       computeEngineCount   - (OUT) compute engine count
    //
    // Output:
    //     TCompletionCode                      - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetComputeEngineTotalCount( CMetricsDevice& metricsDevice, uint32_t& computeEngineCount )
    {
        auto           subDevices     = metricsDevice.GetAdapter().GetSubDevices();
        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();
        computeEngineCount            = subDevices.GetClassInstancesCount( subDeviceIndex, DRM_XE_ENGINE_CLASS_COMPUTE );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetSqidiTotalCount
    //
    // Description:
    //     Returns SQIDI count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint32_t&       sqidiCount    - (OUT) SQIDI count
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetSqidiTotalCount( CMetricsDevice& metricsDevice, uint32_t& sqidiCount )
    {
        sqidiCount                          = 0;
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  ret           = GetGfxDeviceInfo( gfxDeviceInfo );

        MD_CHECK_CC_RET_A( m_adapterId, ret );

        if( ( gfxDeviceInfo->PlatformIndex == GENERATION_PTL && gfxDeviceInfo->PlatformVersion == 2 ) ||
            gfxDeviceInfo->PlatformIndex == GENERATION_NVL )
        {
            // On small PTL/NVL SKUs, SQIDI count is fixed to 2 regardless of L3 node count.
            // SQIDI mask is still 0x1 to not break disaggregation. Disaggregation is applied on mempipe level.
            sqidiCount = 2;
        }
        else
        {
            ret = GetL3NodeTotalCount( metricsDevice, sqidiCount );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetL3BankMask
    //
    // Description:
    //     Returns l3 bank mask for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint64_t&       l3BankMask    - (OUT) l3 bank mask
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetL3BankMask( CMetricsDevice& metricsDevice, uint64_t& l3BankMask )
    {
        l3BankMask = 0;

        MD_LOG_A( m_adapterId, LOG_INFO, "Obtaining l3 bank mask" );

        // Get l3 bank mask per sub device.
        auto buffer = std::vector<uint8_t>();
        auto ret    = GetGeometryTopology( buffer, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        const uint32_t subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        uint32_t dataOffset = 0;

        while( dataOffset < buffer.size() )
        {
            auto topology = reinterpret_cast<drm_xe_query_topology_mask*>( buffer.data() + dataOffset );

            if( topology->type == DRM_XE_TOPO_L3_BANK )
            {
                if( topology->gt_id == subDeviceIndex * 2 ) // GT ID = x is 3D/Compute, GT ID = x+1 is Media, where x is even number.
                {
                    for( uint32_t i = 0; i < topology->num_bytes; ++i )
                    {
                        l3BankMask |= static_cast<uint64_t>( topology->mask[i] ) << ( i * 8 );
                    }
                }
            }

            dataOffset += sizeof( drm_xe_query_topology_mask ) + topology->num_bytes;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetL3NodeMask
    //
    // Description:
    //     Returns l3 node mask for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint64_t&       l3NodeMask    - (OUT) l3 node mask
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetL3NodeMask( CMetricsDevice& metricsDevice, uint64_t& l3NodeMask )
    {
        uint64_t       l3BankMask         = 0;
        const uint32_t maxL3BankPerL3Node = GetGtMaxL3BankPerL3Node();
        auto           result             = GetL3BankMask( metricsDevice, l3BankMask );

        MD_CHECK_CC_RET_A( m_adapterId, result );

        l3NodeMask = 0;

        for( uint32_t i = 0; i < MD_MAX_L3_NODE; ++i )
        {
            if( ( l3BankMask >> ( maxL3BankPerL3Node * i ) ) & MD_BITMASK( maxL3BankPerL3Node ) )
            {
                l3NodeMask |= MD_BIT( i );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxXe
    //
    // Method:
    //     GetCopyEngineMask
    //
    // Description:
    //     Returns copy engine mask for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice  - (IN) metrics device
    //     uint64_t&       copyEngineMask - (OUT) copy engine mask
    //
    // Output:
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxXe::GetCopyEngineMask( CMetricsDevice& metricsDevice, uint64_t& copyEngineMask )
    {
        uint64_t l3NodeMask = 0;
        auto     result     = GetL3NodeMask( metricsDevice, l3NodeMask );

        MD_CHECK_CC_RET_A( m_adapterId, result );

        copyEngineMask = 0;

        for( uint32_t i = 0; i < MD_MAX_L3_NODE / MD_MAX_L3_NODE_PER_COPY_ENGINE; ++i )
        {
            if( ( l3NodeMask >> ( MD_MAX_L3_NODE_PER_COPY_ENGINE * i ) ) & MD_BITMASK( MD_MAX_L3_NODE_PER_COPY_ENGINE ) )
            {
                copyEngineMask |= MD_BIT( i );
            }
        }

        return CC_OK;
    }

} // namespace MetricsDiscoveryInternal
