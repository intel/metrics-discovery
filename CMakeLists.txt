# Copyright © 2018, Intel Corporation
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
cmake_minimum_required (VERSION 2.6)

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

set (PROJECT_NAME md)
project (${PROJECT_NAME})

include(md_cmake_adapter.cmake)

#################################################################################
# INCLUDES
#################################################################################

# generic
include_directories (
    # external
    ${BS_DIR_EXTERNAL}/mesa/include
    ${BS_DIR_EXTERNAL}/mesa/src
    ${BS_DIR_EXTERNAL}/mesa/src/intel/common
    ${BS_DIR_EXTERNAL}/drm
    # mdapi core
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/inc
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/inc
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

#################################################################################
# SOURCES
#################################################################################

# generic
set (LOCAL_SRC_FILES ${LOCAL_SRC_FILES}
    # mdapi metrics definitions
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_BXT.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_SKL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_SKL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_SKL_GT4.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_KBL_GT2.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main_KBL_GT3.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/codegen/md_main.cpp
    # mdapi core
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_utils.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_internal.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/common/md_calculation.cpp
    ${BS_DIR_INSTRUMENTATION}/metrics_discovery/linux/md_driver_ifc_linux_perf.cpp
    # utils
    ${BS_DIR_INSTRUMENTATION}/utils/common/iu_debug.c
    ${BS_DIR_INSTRUMENTATION}/utils/linux/iu_std_linux.cpp
    # external
    ${BS_DIR_EXTERNAL}/mesa/src/intel/common/gen_device_info.c
)

# mdapi internal files
if (("${BUILD_TYPE}" STREQUAL "release-internal") OR
    ("${BUILD_TYPE}" STREQUAL "debug"))
    set(MD_INTERNAL_BUILD TRUE)
endif ()

# mdapi internal metrics definitions
if (MD_INTERNAL_BUILD)
        set(LOCAL_SRC_FILES ${LOCAL_SRC_FILES}
#            currently none
        )
endif ()

#################################################################################
# FLAGS
#################################################################################

# select ENABLED_METRICS
# include only ENABLED_METRICS or all metrics if not defined.
if (DEFINED ENABLED_METRICS)
    message("Enable MDAPI metrics for platforms: ${ENABLED_METRICS}")
    foreach (hwPlatform ${ENABLED_METRICS})
        add_definitions(-DMD_INCLUDE_${hwPlatform}_METRICS)
    endforeach ()
else ()
    message("Enable MDAPI metrics for platforms: ALL")
endif ()

# configuration specific defines
if ("${BUILD_TYPE}" STREQUAL "release")
    add_definitions(-DNDEBUG)
    # security compiler flags
    add_definitions(-O2 -D_FORTIFY_SOURCE=2 -Wformat)
elseif ("${BUILD_TYPE}" STREQUAL "release-internal")
    add_definitions(-D_RELEASE_INTERNAL)
    add_definitions(-DNDEBUG)
elseif ("${BUILD_TYPE}" STREQUAL "debug")
    add_definitions(-D_DEBUG)
endif ()

# platform specific
if ("${PLATFORM}" STREQUAL "linux")
    # linux
    add_definitions(-fdiagnostics-color=auto) # color=auto only to colorize compiler output
    add_definitions(-fstack-protector)
    add_definitions(-Wno-unused)
    add_definitions(-Wno-strict-aliasing)
    add_definitions(-Wno-unknown-pragmas)
    add_definitions(-Wno-comment)
    add_definitions(-msse)
    if ("${BUILD_TYPE}" STREQUAL "release")
        add_definitions(-Wformat-security)
    endif ()
    # C++ specific
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-reorder")
    # support for cpp11
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

# common
add_definitions(-DMD_USE_PERF)
add_definitions(-DMETRICS_DISCOVERY)
add_definitions(-fno-inline)
add_definitions(-Wall)
# to enable x86 build on x64 host
if ("${ARCH}" STREQUAL "32")
    add_definitions(-m32)
endif ()

#################################################################################
# LINK LIBS
#################################################################################

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,noexecstack")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,relro")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,now")

if ("${PLATFORM}" STREQUAL "linux")
    # linux
    add_library(${PROJECT_NAME} SHARED ${LOCAL_SRC_FILES})
endif ()

if ("${PLATFORM}" STREQUAL "linux")
    # linux
    target_link_libraries(
        ${PROJECT_NAME}                 # md
        ${DRM_LIB_PATH}                 # drm
        rt
        pthread
        stdc++
    )
endif ()

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

#################################################################################
# DEBUG
#################################################################################

message ("INFO: PROJECT_NAME           = ${PROJECT_NAME}")
message ("INFO: BUILD_TYPE             = ${BUILD_TYPE}")
message ("INFO: PLATFORM               = ${PLATFORM}")
message ("INFO: ARCH                   = ${ARCH}")
message ("INFO: LINUX_DISTRO           = ${LINUX_DISTRO}")
message ("INFO: DUMP_DIR               = ${DUMP_DIR}")
message ("INFO: LIBDRM_SRC             = ${LIBDRM_SRC}")
message ("INFO: DRM_LIB_PATH           = ${DRM_LIB_PATH}")
message ("INFO: BS_DIR_INSTRUMENTATION = ${BS_DIR_INSTRUMENTATION}")
message ("INFO: BS_DIR_INC             = ${BS_DIR_INC}")
message ("INFO: BS_DIR_EXTERNAL        = ${BS_DIR_EXTERNAL}")
message ("INFO: CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
message ("INFO: CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
