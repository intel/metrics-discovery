/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_gfx_device_info.h
//
//     Abstract:   Device information for Linux.

#include "md_driver_ifc_linux_common.h"
#include <map>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    const std::map<int32_t, TPlatformIndexGt> platformIndexMap{
        { 0x4C8A, TPlatformIndexGt( GENERATION_RKL, GFX_GTTYPE_GT1 ) },
        { 0x4C8B, TPlatformIndexGt( GENERATION_RKL, GFX_GTTYPE_GT1 ) },
        { 0x4C8C, TPlatformIndexGt( GENERATION_RKL, GFX_GTTYPE_GT1 ) },
        { 0x4C90, TPlatformIndexGt( GENERATION_RKL, GFX_GTTYPE_GT1 ) },
        { 0x4C9A, TPlatformIndexGt( GENERATION_RKL, GFX_GTTYPE_GT1 ) },

        { 0x4626, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x4628, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x462A, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46A0, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46A1, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },

        { 0x46A3, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46A6, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46A8, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46AA, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },

        { 0x46B0, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46B1, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46B3, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46C0, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46C1, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0x46C3, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7A0, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) }, // RPLP
        { 0xA720, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7A8, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7A1, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA721, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7A9, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },

        { 0xA7AA, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) }, // RPLP refresh
        { 0xA7AB, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7AC, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },
        { 0xA7AD, TPlatformIndexGt( GENERATION_ADLP, GFX_GTTYPE_GT2 ) },

        { 0x4680, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x4682, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x4688, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x468A, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x468B, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x4690, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x4692, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0x4693, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },

        { 0xA780, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) }, // RPLS
        { 0xA781, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA782, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA783, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA788, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA789, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA78A, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },
        { 0xA78B, TPlatformIndexGt( GENERATION_ADLS, GFX_GTTYPE_GT1 ) },

        { 0x46D0, TPlatformIndexGt( GENERATION_ADLN, GFX_GTTYPE_GT1 ) }, // ADLN
        { 0x46D1, TPlatformIndexGt( GENERATION_ADLN, GFX_GTTYPE_GT1 ) },
        { 0x46D2, TPlatformIndexGt( GENERATION_ADLN, GFX_GTTYPE_GT1 ) },
        { 0x46D3, TPlatformIndexGt( GENERATION_ADLN, GFX_GTTYPE_GT1 ) },
        { 0x46D4, TPlatformIndexGt( GENERATION_ADLN, GFX_GTTYPE_GT1 ) },

        { 0x9A40, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9A49, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9A59, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9A60, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT1 ) },
        { 0x9A68, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT1 ) },
        { 0x9A70, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT1 ) },
        { 0x9A78, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9AC0, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9AC9, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9AD9, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },
        { 0x9AF8, TPlatformIndexGt( GENERATION_TGL, GFX_GTTYPE_GT2 ) },

        { 0x4905, TPlatformIndexGt( GENERATION_DG1, GFX_GTTYPE_UNDEFINED ) },
        { 0x4907, TPlatformIndexGt( GENERATION_DG1, GFX_GTTYPE_UNDEFINED ) },
        { 0x4908, TPlatformIndexGt( GENERATION_DG1, GFX_GTTYPE_UNDEFINED ) },
        { 0x4909, TPlatformIndexGt( GENERATION_DG1, GFX_GTTYPE_UNDEFINED ) },

        { 0x0BD0, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD4, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD5, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD6, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD7, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD8, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BD9, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BDA, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0BDB, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0B69, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },
        { 0x0B6E, TPlatformIndexGt( GENERATION_PVC, GFX_GTTYPE_UNDEFINED ) },

        { 0x4f80, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x4f81, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x4f82, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x4f83, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x4f84, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x4f85, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x4f86, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x4f87, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x4f88, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x5690, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x5691, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x5692, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x5693, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x5694, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x5695, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x5696, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x5697, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x56a0, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56a1, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56a2, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56a3, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x56a4, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x56a5, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56a6, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56af, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56b0, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56b1, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56b2, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x56b3, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT2 ) },
        { 0x56ba, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56bb, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56bc, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56bd, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56be, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56bf, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56c0, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },
        { 0x56c1, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT1 ) },
        { 0x56c2, TPlatformIndexGt( GENERATION_ACM, GFX_GTTYPE_GT3 ) },

        { 0x7D40, TPlatformIndexGt( GENERATION_MTL, GFX_GTTYPE_GT2 ) },
        { 0x7D45, TPlatformIndexGt( GENERATION_MTL, GFX_GTTYPE_GT2 ) },
        { 0x7D55, TPlatformIndexGt( GENERATION_MTL, GFX_GTTYPE_GT3 ) },
        { 0x7DD5, TPlatformIndexGt( GENERATION_MTL, GFX_GTTYPE_GT3 ) },

        { 0x7D41, TPlatformIndexGt( GENERATION_ARL, GFX_GTTYPE_GT1 ) },
        { 0x7D51, TPlatformIndexGt( GENERATION_ARL, GFX_GTTYPE_GT2 ) },
        { 0x7D67, TPlatformIndexGt( GENERATION_ARL, GFX_GTTYPE_GT1 ) },
        { 0x7DD1, TPlatformIndexGt( GENERATION_ARL, GFX_GTTYPE_GT2 ) },

        { 0xE202, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) }, // G21
        { 0xE209, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE20B, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE20C, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE20D, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE210, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE211, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE212, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE216, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 2 ) },
        { 0xE220, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 3 ) },
        { 0xE221, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 3 ) },
        { 0xE222, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 3 ) },
        { 0xE223, TPlatformIndexGt( GENERATION_BMG, GFX_GTTYPE_UNDEFINED, 3 ) },

        { 0x64A0, TPlatformIndexGt( GENERATION_LNL, GFX_GTTYPE_UNDEFINED ) },
        { 0x6420, TPlatformIndexGt( GENERATION_LNL, GFX_GTTYPE_UNDEFINED ) },

        { 0xB080, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) }, // H
        { 0xB081, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB082, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB083, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB084, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB085, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB086, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB087, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
        { 0xB08F, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },

        { 0xB090, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 2 ) }, // U

        { 0xB0A0, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 2 ) }, // H
        { 0xB0B0, TPlatformIndexGt( GENERATION_PTL, GFX_GTTYPE_UNDEFINED, 1 ) },
    };

    const std::map<GTDI_PLATFORM_INDEX, uint32_t> threadsPerEuMap{
        { GENERATION_TGL, 7 },
        { GENERATION_DG1, 7 },
        { GENERATION_RKL, 7 },
        { GENERATION_ADLP, 7 },
        { GENERATION_ADLS, 7 },
        { GENERATION_ADLN, 7 },
        { GENERATION_ACM, 8 },
        { GENERATION_PVC, 8 },
        { GENERATION_MTL, 8 },
        { GENERATION_ARL, 8 },
        { GENERATION_BMG, 8 },
        { GENERATION_LNL, 8 },
        { GENERATION_PTL, 10 },
    };

} // namespace MetricsDiscoveryInternal
