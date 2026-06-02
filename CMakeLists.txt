#=========================== begin_copyright_notice ============================
#
# Copyright (C) 2020-2026 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
#============================ end_copyright_notice =============================

cmake_minimum_required (VERSION 3.20)

# Uncomment for logs during build (during 'make' command)
#set (CMAKE_VERBOSE_MAKEFILE ON)

#################################################################################
# PROJECT
#################################################################################
set (PROJECT_NAME metrics_discovery)
project (${PROJECT_NAME})

set (LIB igdmd)
set (LIB_NAME libigdmd)

#################################################################################
# CONFIGURE C++ STANDARD
#################################################################################
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10)
    set (CMAKE_CXX_STANDARD 17)
else ()
    set (CMAKE_CXX_STANDARD 20)
endif ()
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# instrumentation common settings & macros
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    include (md_cmake_adapter.cmake NO_POLICY_SCOPE)
else ()
    include (../instr.cmake NO_POLICY_SCOPE) # windows and others
endif()

#################################################################################
# SOURCES
#################################################################################

# generic
set (_SOURCES ${_SOURCES}
    # mdapi metrics definitions
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_TGL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_TGL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_DG1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_RKL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_PVC_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_PVC_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLS.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLN.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_MTL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_MTL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_BMG.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_LNL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_PTL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ARL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ARL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_NVL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_NVLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_CRI.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics.cpp
    # external events
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_external_events.cpp
    # mdapi core
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_main.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_utils.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_common.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_adapter.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_adapter_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_oa_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_oam_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_mert_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_equation.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_events.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_information.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric_enumerator.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric_prototype.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric_prototype_manager.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metrics_device.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_override.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_register_manager.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_register_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_symbol_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_calculation.cpp
    # calculation specific
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_TGL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_TGL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_DG1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_RKL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_PVC_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_PVC_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLS.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLN.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_MTL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_MTL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_BMG.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_LNL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_PTL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ARL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ARL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_NVL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_NVLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_CRI.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_common.cpp
    # utils
    ${BS_DIR_INSTRUMENTATION}/utils/common/iu_debug.c
    )

# platform dependent
if (${PLATFORM} STREQUAL Windows) # windows
    set (_SOURCES ${_SOURCES}
        # driver interface
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/md_driver_ifc_win.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/md_sub_devices_win.cpp
        # performance api
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_common.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_dx12.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_vulkan.cpp
        # resource file
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/md.rc
        # instr utils
        ${BS_DIR_INSTRUMENTATION}/utils/windows/umd/iu_os.cpp
        ${BS_DIR_INSTRUMENTATION}/utils/windows/umd/iu_std.cpp
        )

    # linux files in solution explorer
    set (_LINUX_SOURCES_ON_WINDOWS
        # driver interface
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_common.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_perf.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_xe.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_sub_devices_linux.cpp
        # instr utils
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_os.cpp
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_std.cpp
        )

    # linux files will not be being built
    set_source_files_properties (
        ${_LINUX_SOURCES_ON_WINDOWS} PROPERTIES HEADER_FILE_ONLY ON
        )

    set (_SOURCES ${_SOURCES} ${_LINUX_SOURCES_ON_WINDOWS})

elseif (${PLATFORM} STREQUAL linux) # linux
    set (_SOURCES ${_SOURCES}
        # driver interface
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_common.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_perf.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_xe.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_sub_devices_linux.cpp
        # instr utils
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_os.cpp
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_std.cpp
        )
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

set (SOURCES ${_SOURCES})

#################################################################################
# HEADERS
#################################################################################
# These headers are not necessary for building, they are just for easier work
# with sources (e.g. in Visual Studio).
# common headers
file (GLOB_RECURSE _HEADERS
    ${BS_DIR_INC}/common/instrumentation/api/*_api.h
    ${BS_DIR_INSTRUMENTATION}/utils/common/inc/*.h
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/*.h
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/*.h
    )
# platform dependent
if (${PLATFORM} STREQUAL Windows) # windows
    file (GLOB_RECURSE _WINDOWS_HEADERS
        ${BS_DIR_INSTRUMENTATION}/utils/windows/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc/*.h
        )

    set (_WINDOWS_HEADERS ${_WINDOWS_HEADERS}
        ${BS_DIR_D3D12}/PCH/D3D12PerformanceAPI.H
        ${BS_DIR_VULKAN}/Core/PCH/vulkan/vk_intel_performance_query.h
        )

    set (_HEADERS ${_HEADERS} ${_WINDOWS_HEADERS})

    # linux files in solution explorer
    file (GLOB_RECURSE _LINUX_HEADERS
        ${BS_DIR_INSTRUMENTATION}/utils/linux/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/external/drm/*.h
        )
    set (_HEADERS ${_HEADERS} ${_LINUX_HEADERS})
elseif (${PLATFORM} STREQUAL linux) # linux
    file (GLOB_RECURSE _LINUX_HEADERS
        ${BS_DIR_INSTRUMENTATION}/utils/linux/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/external/drm/*.h
        )
    set (_HEADERS ${_HEADERS} ${_LINUX_HEADERS})
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

set (HEADERS ${_HEADERS})

#################################################################################
# SOURCE GROUPS
#################################################################################
# Not necessary for building, needed for directories e.g. in Visual Studio.
# Source group may appear only once so some common files are added together with
# platform dependent ones. The order of adding files matters.

# common
source_group ("Header Files\\api"                          "${BS_DIR_INC}/common/instrumentation/api/.*_api.h")
source_group ("Header Files\\codegen"                      "${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/.*.h")
source_group ("Header Files\\internal"                     "${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal/.*.h")
source_group ("Header Files\\internal\\concurrent_groups"  "${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal/concurrent_groups/.*.h")

source_group ("Source Files\\codegen"                      "${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/.*.cpp")
source_group ("Source Files\\internal"                     "${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/.*.cpp")
source_group ("Source Files\\internal\\concurrent_groups"  "${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/.*.cpp")

# platform dependent
if (${PLATFORM} STREQUAL Windows) # windows
    # common
    source_group ("Header Files\\api\\performance_api"      "${BS_DIR_INC}/common/instrumentation/api/.*performance_api.h")
    source_group ("Header Files"                            "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc/.*.h)")
    source_group ("Header Files\\iu"                        "(${BS_DIR_INSTRUMENTATION}/utils/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/utils/windows/inc/.*.h)")
    source_group ("Header Files\\performance_api"           FILES              "${BS_DIR_D3D12}/PCH/D3D12PerformanceAPI.H"
                                                                               "${BS_DIR_VULKAN}/Core/PCH/vulkan/vk_intel_performance_query.h"
                                                            REGULAR_EXPRESSION "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc/.*performance.*.h)")

    source_group ("Source Files"                            "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/.*.cpp)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/.*.rc)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/.*.cpp)")
    source_group ("Source Files\\iu"                        "(${BS_DIR_INSTRUMENTATION}/utils/common/.*.c)|(${BS_DIR_INSTRUMENTATION}/utils/windows/umd/.*.cpp)|(${BS_DIR_INSTRUMENTATION}/utils/windows/.*.cpp)")
    source_group ("Source Files\\performance_api"           "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/.*performance.*.cpp)")

    # add linux headers to solution explorer
    source_group ("Header Files\\linux"                     "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/.*.h)")
    source_group ("Header Files\\linux\\iu"                 "(${BS_DIR_INSTRUMENTATION}/utils/linux/inc/.*.h)")
    source_group ("Header Files\\external\\drm"             "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/external/drm/.*.h)")

    source_group ("Source Files\\linux"                     "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/.*.cpp)")
    source_group ("Source Files\\linux\\iu"                 "(${BS_DIR_INSTRUMENTATION}/utils/linux/.*.cpp)")
elseif (${PLATFORM} STREQUAL linux) # linux
    # common
    source_group ("Header Files"                            "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/.*.h)")
    source_group ("Header Files\\iu"                        "(${BS_DIR_INSTRUMENTATION}/utils/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/utils/linux/inc/.*.h)")

    source_group ("Source Files"                            "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/.*.cpp)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/.*.cpp)")
    source_group ("Source Files\\iu"                        "(${BS_DIR_INSTRUMENTATION}/utils/common/.*.c)|(${BS_DIR_INSTRUMENTATION}/utils/linux/.*.cpp)")
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# TARGET FLAGS (add_library & link_libraries)
#################################################################################
# project specific target settings
if (${PLATFORM} STREQUAL Windows) # windows
    # add library
    add_library (${PROJECT_NAME} SHARED ${SOURCES})
    target_sources (${PROJECT_NAME} PRIVATE ${HEADERS})
    instr_target_settings (${PROJECT_NAME})
    set (CMAKE_CXX_STANDARD_LIBRARIES "")
    set (CMAKE_C_STANDARD_LIBRARIES "")
    set_target_properties (${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${LIB}${ARCH})
    set_target_properties (${PROJECT_NAME} PROPERTIES VS_GLOBAL_DriverTargetPlatform Universal)
    set_target_properties (${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET "WindowsApplicationForDrivers10.0")
    target_link_libraries (${PROJECT_NAME}
        dxgi.lib    # used in performance_api_dx12.cpp
        dxcore.lib  # used in performance_api_dx12.cpp
        gdi32.lib
        )
    windows_apps_props_universal (${PROJECT_NAME})
elseif (${PLATFORM} STREQUAL linux) # linux
    # add library
    add_library (${PROJECT_NAME} SHARED ${SOURCES})
    target_sources (${PROJECT_NAME} PRIVATE ${HEADERS})
    set_metrics_discovery_version ()
    set_target_properties (${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    set_target_properties (${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${LIB})
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

# version
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${MD_VERSION} SOVERSION ${MD_VERSION_MAJOR})

#################################################################################
# INCLUDES
#################################################################################
set (COMMON_TARGET_INCLUDE_DIRECTORIES
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal/concurrent_groups
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen
    )

if (${PLATFORM} STREQUAL Windows) # windows
    target_include_directories (${PROJECT_NAME} PUBLIC
        ${COMMON_TARGET_INCLUDE_DIRECTORIES}
        # instrumentation
        ${BS_DIR_INSTRUMENTATION}/utils/windows/inc
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc
        # dx12
        ${BS_DIR_D3D12}/PCH
        # vulkan
        ${BS_DIR_VULKAN}/Core/PCH/vulkan
        )
elseif (${PLATFORM} STREQUAL linux) # linux
    target_include_directories (${PROJECT_NAME} PUBLIC
        ${COMMON_TARGET_INCLUDE_DIRECTORIES}
        # external
        ${BS_DIR_EXTERNAL}/drm
        # mdapi core
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc
        # utils
        ${BS_DIR_INSTRUMENTATION}/utils/common/inc
        ${BS_DIR_INSTRUMENTATION}/utils/linux/inc
        # common
        ${BS_DIR_INC}/common
        ${BS_DIR_INC}/common/instrumentation
        ${BS_DIR_INC}/common/instrumentation/api
        )
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# COMPILER FLAGS
#################################################################################
# platform specific
if (${PLATFORM} STREQUAL Windows) # windows
    bs_set_extra_target_properties (${PROJECT_NAME}
        USERMODE_DRIVER
        STD_CALL
        )
    set (COMMON_COMPILE_OPTIONS
        /Zp8 # struct member alignment - 8 bytes
        )
    target_compile_options (
        ${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:
            ${COMMON_COMPILE_OPTIONS}
            /W4     # display warnings level 4
            /WX     # treats warnings as errors
            /wd4100 # 'adapterId': unreferenced parameter
            /Ot     # favor fast code
            /O2     # favor speed
            /Gy     # function-level linking
            /GL     # whole program optimization
        >
        $<$<CONFIG:ReleaseInternal>:
            ${COMMON_COMPILE_OPTIONS}
            /W4     # display warnings level 4
            /WX     # treats warnings as errors
            /Ot     # favor fast code
            /O2     # favor speed
            /Gy     # function-level linking
        >
        $<$<CONFIG:Debug>:
            ${COMMON_COMPILE_OPTIONS}
        >
        )

elseif (${PLATFORM} STREQUAL linux) # linux
    # select ENABLED_METRICS
    # include only ENABLED_METRICS or all metrics if not defined.
    if (DEFINED ENABLED_METRICS)
        message ("Enable MDAPI metrics for platforms: ${ENABLED_METRICS}")
        foreach (hwPlatform ${ENABLED_METRICS})
            target_compile_definitions (${PROJECT_NAME} PRIVATE MD_INCLUDE_${hwPlatform}_METRICS)
        endforeach ()
    else ()
        message ("Enable MDAPI metrics for platforms: ALL")
    endif ()

    set (COMMON_COMPILE_OPTIONS
        -Wall                    # enables all compiler's warning messages
        #-Wfatal-errors          # abort compilation on the first error occurred
        -Wextra                  # enables a comprehensive set of warning options, providing a high level of warning coverage for potential issues
        -Wno-unknown-pragmas     # allows unknown pragmas (such as #pragma region)
        -fpack-struct=8          # struct member alignment - 8 bytes
        -Wformat                 # enables format string checking warnings during compilation
        -Wformat-security        # warns about potentially insecure format string usages
        -Werror=format-security  # treats format string security warnings as errors
        -Wno-comment             # allows multi-line comments
        -fstack-protector-strong # enables stack protection for vulnerable functions that contain: An array of any size and type
        -fdiagnostics-color=auto # color=auto only to colorize compiler output
        #-pedantic               # warns on language extensions not in the standard
        #-pedantic-errors        # treats those warnings as errors
        -Wshadow                 # warns when a variable shadows another
        #-Wcast-qual             # warns on casts that remove type qualifiers (e.g. const)
        #-Wcast-align            # warns on potentially misaligned pointer casts
        #-Wstrict-aliasing=2     # strict aliasing rule violations
        #-Wundef                 # warns when an undefined macro is used in #if
        -Wunused                 # warns on any unused entity
        #-Wnon-virtual-dtor      # warns on non-virtual destructors in polymorphic classes
        #-Woverloaded-virtual    # warns when a derived class hides a virtual function
        )

    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -Wno-extern-c-compat # disables "empty struct has size 0 in C, size 1 in C++" warning
            )
    endif ()

    # configuration specific defines
    if ("${BUILD_TYPE}" STREQUAL "release")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -DNDEBUG
            )
    elseif ("${BUILD_TYPE}" STREQUAL "release-internal" OR
            "${BUILD_TYPE}" STREQUAL "releaseinternal")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -D_RELEASE_INTERNAL
            -DNDEBUG
            )
    elseif ("${BUILD_TYPE}" STREQUAL "debug")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -D_DEBUG
            -g
            )
    endif ()

    # configuration specific defines
    if ("${BUILD_TYPE}" STREQUAL "release" OR
        "${BUILD_TYPE}" STREQUAL "release-internal" OR
        "${BUILD_TYPE}" STREQUAL "releaseinternal")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -O3                 # optimize for speed with conforming optimizations
            -Werror             # treats warning as errors
            -fvisibility=hidden # hides non-exported symbols
            -flto               # enables Link-Time Optimization (LTO)
            -fPIC               # generates position-independent code during the compilation phase
            )
    endif ()

    if (NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -msse
            )
    endif ()

    if ("${TARGET_ARCH}" STREQUAL "32")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -m32 # to enable x86 build on x64 host
            )
    elseif("${TARGET_ARCH}" STREQUAL "64" AND ${HOST_ARCH} STREQUAL "32")
        set (COMMON_COMPILE_OPTIONS ${COMMON_COMPILE_OPTIONS}
            -m64 # to enable x64 build on x86 host
            )
    endif ()

    target_compile_options (
        ${PROJECT_NAME} PRIVATE
        ${COMMON_COMPILE_OPTIONS}
        )

else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# LINKER FLAGS
#################################################################################
if (${PLATFORM} STREQUAL Windows) # windows
    set (PUBLIC_EXPORTS
        /EXPORT:OpenAdapterGroup
        /EXPORT:OpenMetricsDevice
        /EXPORT:CloseMetricsDevice
        /EXPORT:OpenMetricsDeviceFromFile
        /EXPORT:OpenPerformanceInterface
        /EXPORT:ClosePerformanceInterface)
    instr_set_linker_flags ("RELEASE"         "${PUBLIC_EXPORTS} /LTCG /INCREMENTAL:NO /OPT:ICF /OPT:REF")
    instr_set_linker_flags ("RELEASEINTERNAL" "${PUBLIC_EXPORTS} /LTCG /INCREMENTAL:NO /OPT:ICF /OPT:REF")
    instr_set_linker_flags ("DEBUG"           "${PUBLIC_EXPORTS}")
elseif (${PLATFORM} STREQUAL linux) # linux
    set (COMMON_LINK_OPTIONS
        LINKER:--no-undefined
        LINKER:-z,defs
        LINKER:-z,noexecstack
        LINKER:-z,relro
        LINKER:-z,now
        )
    if ("${TARGET_ARCH}" STREQUAL "32")
        set (COMMON_LINK_OPTIONS ${COMMON_LINK_OPTIONS}
            LINKER:-m32 # to enable x86 build on x64 host
            )
    elseif("${TARGET_ARCH}" STREQUAL "64" AND ${HOST_ARCH} STREQUAL "32")
        set (COMMON_LINK_OPTIONS ${COMMON_LINK_OPTIONS}
            LINKER:-m64 # to enable x64 build on x86 host
            )
    endif ()
    target_link_options (
        ${PROJECT_NAME} PRIVATE
        ${COMMON_LINK_OPTIONS}
        )
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# LINK LIBRARIES
#################################################################################
if (${PLATFORM} STREQUAL linux)
    # find libdrm-dev
    find_library (libdrm drm)
    if (${libdrm} STREQUAL libdrm-NOTFOUND)
        message (FATAL_ERROR "You need to install libdrm-dev")
    else ()
        message (STATUS "libdrm-dev found as ${libdrm}")
    endif ()

    target_link_libraries (
        ${PROJECT_NAME}
        drm
    )
endif ()

#################################################################################
# INSTALLER
#################################################################################

set (API_HEADER_LOCATION "${BS_DIR_INC}/common/instrumentation/api/metrics_discovery_api.h")

if (${PLATFORM} STREQUAL Windows) # windows
    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Release/bin
        CONFIGURATIONS Release
    )

    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Release-Internal/bin
        CONFIGURATIONS ReleaseInternal
    )

    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Debug/bin
        CONFIGURATIONS Debug
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Release/pdb
        CONFIGURATIONS Release
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Release-Internal/pdb
        CONFIGURATIONS ReleaseInternal
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Debug/pdb
        CONFIGURATIONS Debug
    )
elseif (${PLATFORM} STREQUAL linux) # linux
    include (GNUInstallDirs)

    if (${TARGET_ARCH} STREQUAL 64)
        set (CPACK_PACKAGE_ARCHITECTURE        "x86_64")
        set (CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
        set (CPACK_RPM_PACKAGE_ARCHITECTURE    "x86_64")
    else ()
        set (CPACK_PACKAGE_ARCHITECTURE        "i386")
        set (CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")
        set (CPACK_RPM_PACKAGE_ARCHITECTURE    "i386")
    endif ()

    # pkg-config
    set (PC_FILE ${LIB_NAME}.pc)
    set (PC_IN ${PC_FILE}.in)

    configure_file (${PC_IN} ${CMAKE_BINARY_DIR}/${PC_FILE} @ONLY)

    install (FILES ${CMAKE_BINARY_DIR}/${PC_FILE}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
        COMPONENT metrics-discovery-pkgconfig
    )

    # header
    install (FILES ${API_HEADER_LOCATION}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT metrics-discovery-devel
    )

    # library
    install (TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT metrics-discovery
        NAMELINK_SKIP
    )

    install (TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT metrics-discovery-devel
        NAMELINK_ONLY
    )

    # software package generator
    if (LIB_CPACK_GENERATOR)
        set (CPACK_GENERATOR ${LIB_CPACK_GENERATOR})
    else ()
        if (EXISTS "/etc/debian_version")
            set (CPACK_GENERATOR "DEB")
        elseif (EXISTS "/etc/redhat-release")
            set (CPACK_GENERATOR "RPM")
        elseif (EXISTS "/etc/os-release")
            set (CPACK_GENERATOR "RPM")
        else ()
            set (CPACK_GENERATOR "TXZ")
        endif ()
    endif ()

    set (CPACK_SET_DESTDIR                 TRUE)
    set (CPACK_PACKAGE_NAME                "intel")
    set (CPACK_PACKAGE_VERSION             ${MD_VERSION})
    set (CPACK_PACKAGE_RELOCATABLE         FALSE)
    set (CPACK_PACKAGE_INSTALL_DIRECTORY   ${CMAKE_INSTALL_PREFIX})
    set (CPACK_PACKAGE_CONTACT             "Intel Corporation")
    set (CPACK_DEBIAN_PACKAGE_MAINTAINER   "intel")
    set (CPACK_DEBIAN_PACKAGE_DESCRIPTION  "Intel(R) Metrics Discovery Application Programming Interface")
    set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS    ON)
    set (CPACK_RPM_COMPRESSION_TYPE        "xz")
    set (CPACK_RPM_PACKAGE_AUTOREQ         OFF)
    set (CPACK_RPM_PACKAGE_DESCRIPTION     "Intel(R) Metrics Discovery Application Programming Interface")
    set (CPACK_RPM_PACKAGE_LICENSE         "MIT")

    if (DEFINED LIB_PACKAGE_RELEASE)
        set (CPACK_DEBIAN_PACKAGE_RELEASE ${LIB_PACKAGE_RELEASE})
        set (CPACK_RPM_PACKAGE_RELEASE    ${LIB_PACKAGE_RELEASE})
    else ()
        set (CPACK_DEBIAN_PACKAGE_RELEASE 1)
        set (CPACK_RPM_PACKAGE_RELEASE    1)
    endif ()

    set (CPACK_DEBIAN_METRICS-DISCOVERY-PKGCONFIG_FILE_NAME  "intel-metrics-discovery-pkgconfig-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb")
    set (CPACK_RPM_METRICS-DISCOVERY-PKGCONFIG_FILE_NAME     "intel-metrics-discovery-pkgconfig-${CPACK_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}.${CPACK_RPM_PACKAGE_ARCHITECTURE}.rpm")
    set (CPACK_ARCHIVE_METRICS-DISCOVERY-PKGCONFIG_FILE_NAME "intel-metrics-discovery-pkgconfig-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}.${CPACK_PACKAGE_ARCHITECTURE}")

    set (CPACK_DEBIAN_METRICS-DISCOVERY-DEVEL_FILE_NAME  "intel-metrics-discovery-devel-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb")
    set (CPACK_RPM_METRICS-DISCOVERY-DEVEL_FILE_NAME     "intel-metrics-discovery-devel-${CPACK_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}.${CPACK_RPM_PACKAGE_ARCHITECTURE}.rpm")
    set (CPACK_ARCHIVE_METRICS-DISCOVERY-DEVEL_FILE_NAME "intel-metrics-discovery-devel-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}.${CPACK_PACKAGE_ARCHITECTURE}")

    set (CPACK_DEBIAN_METRICS-DISCOVERY_FILE_NAME  "intel-metrics-discovery-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}_${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}.deb")
    set (CPACK_RPM_METRICS-DISCOVERY_FILE_NAME     "intel-metrics-discovery-${CPACK_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}.${CPACK_RPM_PACKAGE_ARCHITECTURE}.rpm")
    set (CPACK_ARCHIVE_METRICS-DISCOVERY_FILE_NAME "intel-metrics-discovery-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}.${CPACK_PACKAGE_ARCHITECTURE}")

    set(CPACK_DEBIAN_METRICS-DISCOVERY-DEVEL_PACKAGE_DEPENDS "intel-metrics-discovery(=${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE})")
    set(CPACK_RPM_METRICS-DISCOVERY-DEVEL_PACKAGE_REQUIRES "intel-metrics-discovery = ${CPACK_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}")

    set (CPACK_DEB_COMPONENT_INSTALL     ON)
    set (CPACK_RPM_COMPONENT_INSTALL     ON)
    set (CPACK_ARCHIVE_COMPONENT_INSTALL ON)

    set (CPACK_COMPONENTS_ALL metrics-discovery-pkgconfig metrics-discovery-devel metrics-discovery)

    include (CPack)
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# DEBUG
#################################################################################
if (${PLATFORM} STREQUAL Windows) # windows
    instr_debug (${PROJECT_NAME})
elseif (${PLATFORM} STREQUAL linux) # linux
    message ("INFO: PROJECT_NAME           = ${PROJECT_NAME}")
    message ("INFO: VERSION                = ${MD_VERSION}")
    message ("INFO: BUILD_TYPE             = ${BUILD_TYPE}")
    message ("INFO: PLATFORM               = ${PLATFORM}")
    message ("INFO: HOST_ARCH              = ${HOST_ARCH}")
    message ("INFO: TARGET_ARCH            = ${TARGET_ARCH}")
    message ("INFO: DUMP_DIR               = ${DUMP_DIR}")
    message ("INFO: LIB_INSTALL_DIR        = ${CMAKE_INSTALL_FULL_LIBDIR}")
    message ("INFO: DRM_LIB_PATH           = ${DRM_LIB_PATH}")
    message ("INFO: BS_DIR_INSTRUMENTATION = ${BS_DIR_INSTRUMENTATION}")
    message ("INFO: BS_DIR_INC             = ${BS_DIR_INC}")
    message ("INFO: BS_DIR_EXTERNAL        = ${BS_DIR_EXTERNAL}")
    message ("INFO: CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
    message ("INFO: CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
    message ("INFO: CMAKE_CXX_COMPILER_ID  = ${CMAKE_CXX_COMPILER_ID}")
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()
