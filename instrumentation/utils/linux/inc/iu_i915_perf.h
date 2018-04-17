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

    File Name:  iu_i915_perf.h

    Abstract:   Contains definitions for i915 Perf usage

\*****************************************************************************/
#pragma once

#include <inttypes.h>

#if defined(__cplusplus)
extern "C" {
#endif

#include <i915_drm.h>

/*****************************************************************************\

Struct:
    iu_i915_perf_config_register

Description:
    For adding configs to kernel. Based on i915_oa_reg defined in kernel in i915_drv.h.
    DRM_IOCTL_I915_PERF_ADD_CONFIG expects just (address, value) tuples.

\*****************************************************************************/
struct iu_i915_perf_config_register
{
    uint32_t address;
    uint32_t value;
};

/*****************************************************************************\

Struct:
    iu_i915_perf_record

Description:
    For reading reports from kernel. Content of 'data' depends on flags passed to
    DRM_IOCTL_I915_PERF_OPEN, it may contain multiple different information at once,
    e.g. PID, CTX, timestamp, OA report.

\*****************************************************************************/
struct iu_i915_perf_record
{
   struct drm_i915_perf_record_header header;
   uint8_t                            data[];
};

#if defined(__cplusplus)
} // extern "C"
#endif
