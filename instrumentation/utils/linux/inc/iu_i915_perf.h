/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  iu_i915_perf.h

//     Abstract:   Contains definitions for i915 Perf usage

#pragma once

#include <inttypes.h>

#if defined( __cplusplus )
extern "C"
{
#endif

#define __user
#include <i915_drm.h>

    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     iu_i915_perf_config_register
    //
    // Description:
    //     For adding configs to kernel. Based on i915_oa_reg defined in kernel in i915_drv.h.
    //     DRM_IOCTL_I915_PERF_ADD_CONFIG expects just (address, value) tuples.
    //
    //////////////////////////////////////////////////////////////////////////////
    struct iu_i915_perf_config_register
    {
        uint32_t address;
        uint32_t value;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //     iu_i915_perf_record
    //
    // Description:
    //     For reading reports from kernel. Content of 'data' depends on flags passed to
    //     DRM_IOCTL_I915_PERF_OPEN, it may contain multiple different information at once,
    //     e.g. PID, CTX, timestamp, OA report.
    //
    //////////////////////////////////////////////////////////////////////////////
    struct iu_i915_perf_record
    {
        struct drm_i915_perf_record_header header;
        uint8_t                            data[];
    };

#if defined( __cplusplus )
} // extern "C"
#endif
