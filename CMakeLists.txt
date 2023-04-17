# Copyright © 2020-2022, Intel Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#################################################################################
cmake_minimum_required (VERSION 3.5)
#set (CMAKE_VERBOSE_MAKEFILE ON)

#################################################################################
# CMAKE POLICIES
#################################################################################
# Cmake policies based on instr.cmake
if (COMMAND cmake_policy)
    if (POLICY CMP0005)
        # automatic quoting of brackets
        cmake_policy (SET CMP0005 NEW)
    endif (POLICY CMP0005)

    if (POLICY CMP0015)
        # .vcproj contains relative paths to additional library directories, thus we need to be able to cope with that
        cmake_policy (SET CMP0015 NEW)
    endif (POLICY CMP0015)
endif (COMMAND cmake_policy)

# Uncomment for logs during build (during 'make' comamnd)
#set (CMAKE_VERBOSE_MAKEFILE ON)

#################################################################################
# TARGET
#################################################################################

set (PROJECT_NAME metrics_discovery)
project (${PROJECT_NAME})

set (LIB igdmd)
set (LIB_NAME libigdmd)

#################################################################################
# CONFIGURE C++ STANDARD
#################################################################################
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# instrumentation common settings & macros
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    include (md_cmake_adapter.cmake NO_POLICY_SCOPE)
else ()
    include (../instr.cmake NO_POLICY_SCOPE) # windows and others
endif()

# find libdrm-dev
find_library(libdrm drm)
if (${libdrm} STREQUAL libdrm-NOTFOUND)
    message(FATAL_ERROR "You need to install libdrm-dev")
else ()
    message(STATUS "libdrm-dev found as ${libdrm}")
endif ()
    
#################################################################################
# SOURCES
#################################################################################

# mdapi internal files
if (("${BUILD_TYPE}" STREQUAL "release-internal") OR
    ("${BUILD_TYPE}" STREQUAL "releaseinternal") OR
    ("${BUILD_TYPE}" STREQUAL "debug"))
    set(MD_INTERNAL_BUILD TRUE)
endif ()

# generic
set (_SOURCES ${_SOURCES}
    # mdapi metrics definitions
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_HSW.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_BDW.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_SKL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_SKL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_SKL_GT4.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_BXT.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_KBL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_KBL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_CFL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_CFL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_GLK.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ICL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_EHL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_TGL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_TGL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_DG1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_RKL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_XEHP_SDV_GT1_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_XEHP_SDV_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_XEHP_SDV_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ACM_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLS.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_ADLN.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_PVC_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_PVC_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_MTL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics_MTL_GT3.cpp

    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_HSW.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_BDW.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_SKL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_SKL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_SKL_GT4.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_BXT.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_KBL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_KBL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_CFL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_CFL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_GLK.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ICL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_EHL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_TGL_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_TGL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_DG1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_RKL.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_XEHP_SDV_GT1_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_XEHP_SDV_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_XEHP_SDV_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ACM_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLP.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLS.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_ADLN.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_PVC_GT1.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_PVC_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_MTL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_MTL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metric_sets_common.cpp

    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_metrics.cpp
    # mdapi core
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_main.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_utils.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_common.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_adapter.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_adapter_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_oa_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/concurrent_groups/md_oam_concurrent_group.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_equation.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_information.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metric_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_metrics_device.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_override.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_register_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/internal/md_symbol_set.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_calculation.cpp
    # utils
    ${BS_DIR_INSTRUMENTATION}/utils/common/iu_debug.c
    )

# platform dependent
if ("${PLATFORM}" STREQUAL Windows) # windows
    set (_SOURCES ${_SOURCES}
        # mdapi core
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/md_driver_ifc_win.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_common.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_dx12.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/performance_api_vulkan.cpp
        # resource file
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/md.rc
        # instr utils
        ${BS_DIR_INSTRUMENTATION}/utils/windows/umd/iu_std.cpp
        ${BS_DIR_INSTRUMENTATION}/utils/windows/umd/iu_os.cpp
        )

    # linux files in solution explorer
    set (_LINUX_SOURCES_ON_WINDOWS
         # mdapi core
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_perf.cpp
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_sub_devices_linux.cpp
        # instr utils
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_std.cpp
        ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_os.cpp
        )
    # linux files will not be being built
    set_source_files_properties (
        ${_LINUX_SOURCES_ON_WINDOWS} PROPERTIES HEADER_FILE_ONLY ON
        )
    set (_SOURCES ${_SOURCES} ${_LINUX_SOURCES_ON_WINDOWS})
elseif ("${PLATFORM}" STREQUAL linux) # linux
    set (_SOURCES ${_SOURCES}
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_perf.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_sub_devices_linux.cpp
    ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_std.cpp
    ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_os.cpp
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
    )
# platform dependent
if ("${PLATFORM}" STREQUAL Windows) # windows
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
        )
    set (_HEADERS ${_HEADERS} ${_LINUX_HEADERS})
elseif ("${PLATFORM}" STREQUAL linux) # linux
    file (GLOB_RECURSE _LINUX_HEADERS
        ${BS_DIR_INSTRUMENTATION}/utils/linux/inc/*.h
        ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/*.h
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
source_group ("Header Files\\api"                   "${BS_DIR_INC}/common/instrumentation/api/.*_api.h")
source_group ("Header Files\\api\\performance_api"  "${BS_DIR_INC}/common/instrumentation/api/.*performance_api.h")

source_group ("Source Files\\codegen"               "${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/.*.cpp")

# common & platform dependent
if ("${PLATFORM}" STREQUAL Windows) # windows
    source_group ("Header Files"                    "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc/.*.h)")
    source_group ("Header Files\\iu"                "(${BS_DIR_INSTRUMENTATION}/utils/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/utils/windows/inc/.*.h)")
    source_group ("Header Files\\performance_api"   FILES              "${BS_DIR_D3D12}/PCH/D3D12PerformanceAPI.H"
                                                                       "${BS_DIR_VULKAN}/Core/PCH/vulkan/vk_intel_performance_query.h"
                                                    REGULAR_EXPRESSION "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/inc/.*performance.*.h)")

    source_group ("Source Files"                    "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/.*.cpp)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/.*.rc)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/.*.cpp)")
    source_group ("Source Files\\iu"                "(${BS_DIR_INSTRUMENTATION}/utils/common/.*.c)|(${BS_DIR_INSTRUMENTATION}/utils/windows/umd/.*.cpp)")
    source_group ("Source Files\\performance_api"   "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/windows/.*performance.*.cpp)")

    # linux files in solution explorer
    source_group ("Header Files\\linux"             "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/.*.h)")
    source_group ("Header Files\\linux\\iu"         "(${BS_DIR_INSTRUMENTATION}/utils/linux/inc/.*.h)")

    source_group ("Source Files\\linux"             "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/.*.cpp)")
    source_group ("Source Files\\linux\\iu"         "(${BS_DIR_INSTRUMENTATION}/utils/linux/.*.cpp)")
elseif ("${PLATFORM}" STREQUAL linux) # linux
    source_group ("Header Files"                    "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc/.*.h)")
    source_group ("Header Files\\iu"                "(${BS_DIR_INSTRUMENTATION}/utils/common/inc/.*.h)|(${BS_DIR_INSTRUMENTATION}/utils/linux/inc/.*.h)")

    source_group ("Source Files"                    "(${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/.*.cpp)|(${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/.*.cpp)")
    source_group ("Source Files\\iu"                "(${BS_DIR_INSTRUMENTATION}/utils/common/.*.c)|(${BS_DIR_INSTRUMENTATION}/utils/linux/.*.cpp)")
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# LINK LIBS
#################################################################################
if ("${PLATFORM}" STREQUAL Windows) # windows
    add_library (${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

    # project specific target settings
    instr_target_settings (${PROJECT_NAME})
    set (PUBLIC_EXPORTS
        /EXPORT:OpenAdapterGroup
        /EXPORT:OpenMetricsDevice
        /EXPORT:CloseMetricsDevice
        /EXPORT:OpenMetricsDeviceFromFile
        /EXPORT:OpenPerformanceInterface
        /EXPORT:ClosePerformanceInterface)
    set (INTERNAL_EXPORTS
        /EXPORT:SaveMetricsDeviceToFile)
    instr_set_linker_flags ("RELEASE"         "${PUBLIC_EXPORTS}")
    instr_set_linker_flags ("RELEASEINTERNAL" "${PUBLIC_EXPORTS} ${INTERNAL_EXPORTS}")
    instr_set_linker_flags ("DEBUG"           "${PUBLIC_EXPORTS} ${INTERNAL_EXPORTS}")
    set (CMAKE_CXX_STANDARD_LIBRARIES "")
    set (CMAKE_C_STANDARD_LIBRARIES "")
    set_target_properties(${PROJECT_NAME} PROPERTIES VS_GLOBAL_DriverTargetPlatform Universal)
    set_target_properties(${PROJECT_NAME} PROPERTIES VS_PLATFORM_TOOLSET "WindowsApplicationForDrivers10.0")
    set_property (TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${LIB}${ARCH})
    target_link_libraries (${PROJECT_NAME}
        dxgi.lib    # used in performance_api_dx12.cpp
        gdi32.lib
        )
    windows_apps_props_universal(${PROJECT_NAME})
elseif ("${PLATFORM}" STREQUAL linux) # linux
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,noexecstack")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,relro")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,now")
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
    target_link_libraries(
        ${PROJECT_NAME}                 # metrics_discovery
        ${DRM_LIB_PATH}                 # drm
        rt
        pthread
        stdc++
    )
    set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
    set_metrics_discovery_version()
    set_property(TARGET ${PROJECT_NAME} PROPERTY VERSION ${MD_VERSION})
    set_property(TARGET ${PROJECT_NAME} PROPERTY SOVERSION ${MD_VERSION_MAJOR})
    set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME ${LIB})
endif ()


#################################################################################
# INCLUDES
#################################################################################
set (COMMON_TARGET_INCLUDE_DIRECTORIES
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc/internal/concurrent_groups
    )

if ("${PLATFORM}" STREQUAL Windows) # windows
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
elseif ("${PLATFORM}" STREQUAL linux)
    # generic
    include_directories (
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

    # drm
    if (NOT "${LIBDRM_SRC}" STREQUAL "")
        message (STATUS "using LIBDRM_SRC = ${LIBDRM_SRC}")
        include_directories (
            ${LIBDRM_SRC}
            ${LIBDRM_SRC}/include/drm
            ${LIBDRM_SRC}/intel
        )
    endif ()
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# FLAGS
#################################################################################
# platform specific
if ("${PLATFORM}" STREQUAL Windows) # windows
    # Excludes metrics for unreleased platforms for non-internal builds.
    # To enable metrics, just remove the flag for a given platform, do not set it to 1
    set (DISABLED_METRICS )

    bs_set_extra_target_properties (${PROJECT_NAME}
        METRICS_DISCOVERY
        ISTDLIB_UMD
        USERMODE_DRIVER
        STD_CALL
        )

    # set DISABLED_METRICS
    set_property (TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS
        $<$<CONFIG:Release>: ${DISABLED_METRICS}>
        )
elseif ("${PLATFORM}" STREQUAL "linux") # linux
    # select ENABLED_METRICS
    # include only ENABLED_METRICS or all metrics if not defined.
    if (DEFINED ENABLED_METRICS)
        message ("Enable MDAPI metrics for platforms: ${ENABLED_METRICS}")
        foreach (hwPlatform ${ENABLED_METRICS})
            add_definitions(-DMD_INCLUDE_${hwPlatform}_METRICS)
        endforeach ()
    else ()
        message ("Enable MDAPI metrics for platforms: ALL")
    endif ()

    # configuration specific defines
    if ("${BUILD_TYPE}" STREQUAL "release")
        add_definitions(-DNDEBUG)
        # security compiler flags
        add_definitions(-O2 -D_FORTIFY_SOURCE=2 -Wformat)
    elseif ("${BUILD_TYPE}" STREQUAL "release-internal" OR
            "${BUILD_TYPE}" STREQUAL "releaseinternal")
            add_definitions(-D_RELEASE_INTERNAL)
            add_definitions(-DNDEBUG)
    elseif ("${BUILD_TYPE}" STREQUAL "debug")
        add_definitions(-D_DEBUG)
    endif ()

    add_definitions(-Wall)
    add_definitions(-fdiagnostics-color=auto) # color=auto only to colorize compiler output
    add_definitions(-fstack-protector)
    add_definitions(-fvisibility=hidden)      # to disable exporting internal symbols (by default gcc exports all symbols)
    add_definitions(-Wno-unused)
    add_definitions(-Wno-strict-aliasing)
    add_definitions(-Wno-unknown-pragmas)
    add_definitions(-Wno-comment)
    add_definitions(-msse)
    if ("${BUILD_TYPE}" STREQUAL "release" OR
        "${BUILD_TYPE}" STREQUAL "release-internal" OR
        "${BUILD_TYPE}" STREQUAL "releaseinternal")
        add_definitions(-Wformat-security)
    elseif ("${BUILD_TYPE}" STREQUAL "debug")
        add_definitions(-g)
    endif ()
    # C++ specific
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-reorder")

    # common
    add_definitions(-DMD_USE_PERF)
    add_definitions(-DMETRICS_DISCOVERY)
    add_definitions(-fno-inline)
    add_definitions(-Wno-extern-c-compat)

    # to enable x86 build on x64 host
    if ("${TARGET_ARCH}" STREQUAL "32")
        # flag is needed for both, compiler and linker
        add_definitions(-m32)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m32")
    # to enable x64 build on x86 host
    elseif("${TARGET_ARCH}" STREQUAL "64" AND ${HOST_ARCH} STREQUAL "32")
        # flag is needed for both, compiler and linker
        add_definitions(-m64)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m64")
    endif ()
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()

#################################################################################
# INSTALLER
#################################################################################

set (API_HEADER_LOCATION "${BS_DIR_INC}/common/instrumentation/api/metrics_discovery_api.h")

if ("${PLATFORM}" STREQUAL Windows) # windows
    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Release/lh64
        CONFIGURATIONS Release
    )

    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Release-Internal/lh64
        CONFIGURATIONS ReleaseInternal
    )

    install (TARGETS ${PROJECT_NAME} RUNTIME
        DESTINATION Debug/lh64
        CONFIGURATIONS Debug
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Release/lh64/pdb
        CONFIGURATIONS Release
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Release-Internal/lh64/pdb
        CONFIGURATIONS ReleaseInternal
    )

    install (FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
        DESTINATION Debug/lh64/pdb
        CONFIGURATIONS Debug
    )
elseif (${PLATFORM} STREQUAL linux) # linux
    include(GNUInstallDirs)

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
if ("${PLATFORM}" STREQUAL Windows)
    instr_debug (${PROJECT_NAME})
elseif ("${PLATFORM}" STREQUAL linux)
    message ("INFO: PROJECT_NAME           = ${PROJECT_NAME}")
    message ("INFO: VERSION                = ${MD_VERSION}")
    message ("INFO: BUILD_TYPE             = ${BUILD_TYPE}")
    message ("INFO: PLATFORM               = ${PLATFORM}")
    message ("INFO: HOST_ARCH              = ${HOST_ARCH}")
    message ("INFO: TARGET_ARCH            = ${TARGET_ARCH}")
    message ("INFO: LINUX_DISTRO           = ${LINUX_DISTRO}")
    message ("INFO: DUMP_DIR               = ${DUMP_DIR}")
    message ("INFO: LIB_INSTALL_DIR        = ${CMAKE_INSTALL_FULL_LIBDIR}")
    message ("INFO: LIBDRM_SRC             = ${LIBDRM_SRC}")
    message ("INFO: DRM_LIB_PATH           = ${DRM_LIB_PATH}")
    message ("INFO: BS_DIR_INSTRUMENTATION = ${BS_DIR_INSTRUMENTATION}")
    message ("INFO: BS_DIR_INC             = ${BS_DIR_INC}")
    message ("INFO: BS_DIR_EXTERNAL        = ${BS_DIR_EXTERNAL}")
    message ("INFO: CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
    message ("INFO: CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
else ()
    message ("-- Using platform is ${PLATFORM}")
endif ()
