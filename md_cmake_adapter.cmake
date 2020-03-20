# Copyright © 2019, Intel Corporation
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
# HELPER FUNCTIONS
#################################################################################

##################################################################################
# set_metrics_discovery_version
#   Finds version string based on the API version enums in metrics_discovery_api.h
#   and sets variables MD_VERSION_MAJOR and MD_VERSION in parent context
##################################################################################
function(set_metrics_discovery_version)
    # Parse the full version number from metrics_discovery_api.h and set MD_VERSION
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/inc/common/instrumentation/api/metrics_discovery_api.h _md_h_contents)

    foreach(VERSION MAJOR MINOR BUILD)
        string(REGEX MATCH "MD_API_${VERSION}_NUMBER_CURRENT[ \t]*=*[\ t]*[A-Z_]*[0-9]*" _ENUM_LINE ${_md_h_contents})
        string(REGEX MATCH "[0-9].*" VERSION_NUMBER ${_ENUM_LINE})
        set(VERSION_${VERSION} ${VERSION_NUMBER})
    endforeach(VERSION)

    set(MD_VERSION_MAJOR ${VERSION_MAJOR} PARENT_SCOPE)
    set(MD_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUILD} PARENT_SCOPE)
endfunction(set_metrics_discovery_version)

#################################################################################
# clearInputVariables
#   Clears cached MDAPI input cmake variables. Needed for e.g. the below command scenario:
#   1. cmake -DMD_PLATFORM=linux -DMD_BUILD_TYPE=release -DMD_ARCH=32 -> MD_ARCH specified to 32
#   2. cmake -DMD_PLATFORM=linux -DMD_BUILD_TYPE=release              -> default MD_ARCH value should be used,
#                                                                        but without clearing, it will be still MD_ARCH=32
#################################################################################
function(clearInputVariables)
    unset(CMAKE_SYSTEM_NAME CACHE)
    unset(MD_PLATFORM CACHE)
    unset(CMAKE_BUILD_TYPE CACHE)
    unset(MD_BUILD_TYPE CACHE)
    unset(MD_ARCH CACHE)
    unset(MD_LIBDRM_SRC CACHE)
    unset(MD_LINUX_DISTRO CACHE)
endfunction()

#################################################################################
# errorExit
#   Clears cached input variables and displays the given error message.
#################################################################################
function(errorExit message)
    clearInputVariables()
    message(FATAL_ERROR ${message})
endfunction()

#################################################################################
# ADAPTER
#################################################################################

if (${CMAKE_VERBOSE_MAKEFILE} STREQUAL ON)
    message("INFO: Input CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
    message("INFO: Input MD_PLATFORM       = ${MD_PLATFORM}")
    message("INFO: Input CMAKE_BUILD_TYPE  = ${CMAKE_BUILD_TYPE}")
    message("INFO: Input MD_BUILD_TYPE     = ${MD_BUILD_TYPE}")
    message("INFO: Input MD_ARCH           = ${MD_ARCH}")
    message("INFO: Input MD_LIBDRM_SRC     = ${MD_LIBDRM_SRC}")
    message("INFO: Input MD_LINUX_DISTRO   = ${MD_LINUX_DISTRO}")
endif()

# PLATFORM
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    if ((NOT (MD_PLATFORM)) OR (MD_PLATFORM STREQUAL "linux") OR (MD_PLATFORM STREQUAL "Linux"))
        set(PLATFORM "linux")
        message("-- using PLATFORM = ${PLATFORM}")
    else ()
        errorExit("ERROR: Current platform ${CMAKE_SYSTEM_NAME} contradicts to requested ${MD_PLATFORM}")
    endif()
else()
    errorExit("ERROR: Project isn't targeted for ${CMAKE_SYSTEM_NAME}. Please run CMake on Linux.")
endif()

# BUILD_TYPE
if (CMAKE_BUILD_TYPE)
    string (TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
endif ()

if(NOT (MD_BUILD_TYPE))
    if (NOT (CMAKE_BUILD_TYPE))
        set(BUILD_TYPE "release")
    else()
        set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
    endif()
else()
    if (NOT (CMAKE_BUILD_TYPE))
        set(BUILD_TYPE ${MD_BUILD_TYPE})
    elseif (${MD_BUILD_TYPE} STREQUAL ${CMAKE_BUILD_TYPE})
        set(BUILD_TYPE ${MD_BUILD_TYPE})
    else()
        errorExit("ERROR: -DMD_BUILD_TYPE contradicts to -DCMAKE_BUILD_TYPE.")
    endif()
endif()

if (NOT (BUILD_TYPE STREQUAL "release" OR
         BUILD_TYPE STREQUAL "release-internal" OR
         BUILD_TYPE STREQUAL "debug"))
    errorExit("ERROR: Specify correct BUILD_TYPE 'release|release-internal|debug' through -DCMAKE_BUILD_TYPE or -DMD_BUILD_TYPE")
else()
    message("-- using BUILD_TYPE = ${BUILD_TYPE}")
endif()

# HOST ARCH
if (CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64") # 64 bits Linux
    set (HOST_ARCH "64")
else() # 32 bits Linux
    set (HOST_ARCH "32")
endif ()

# TARGET ARCH
if (MD_ARCH)
# User defines ARCH through custom variable
    if (MD_ARCH STREQUAL "32" OR MD_ARCH STREQUAL "64")
        set(TARGET_ARCH ${MD_ARCH})
    else()
        errorExit("ERROR: Specify correct MD_ARCH (-DMD_ARCH=64|32).")
    endif()
else()
# User defines ARCH through compiler flags
    set(TARGET_ARCH "64") # 64 bits by default
    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(TARGET_ARCH "32")
    endif()
endif()

message("-- using TARGET_ARCH = ${TARGET_ARCH}")

if(TARGET_ARCH STREQUAL "32")
    message("-- !! Compiling 32bit on 64bit host requires gcc (g++) in multilib version !!")
    message("   e.g. sudo apt-get install gcc-4.8-multilib g++-4.8-multilib")
endif()

# LINUX_DISTRO
if (MD_LINUX_DISTRO)
    set(LINUX_DISTRO ${MD_LINUX_DISTRO})
endif()

# LIBDRM
if (NOT (MD_LIBDRM_SRC))
    if ("${PLATFORM}" STREQUAL "linux")
        set(LIBDRM_SRC /usr/include/libdrm)
    else()
        message(WARNING "WARNING: MD_LIBDRM_SRC not specified (-DMD_LIBDRM_SRC=...)")
    endif()
else()
    set(LIBDRM_SRC ${MD_LIBDRM_SRC})
endif()

set(DRM_LIB_PATH drm)

# PATHS
set(BS_DIR_INSTRUMENTATION ${CMAKE_CURRENT_SOURCE_DIR}/instrumentation)
set(BS_DIR_INC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(BS_DIR_EXTERNAL ${CMAKE_CURRENT_SOURCE_DIR}/external)
set(DUMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dump/${PLATFORM}${TARGET_ARCH}/${BUILD_TYPE}/${PROJECT_NAME})
if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set (CMAKE_INSTALL_PREFIX /usr)
endif ()

# OUTPUT
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DUMP_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DUMP_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DUMP_DIR})

# Clear input variables to have a 'fresh', non-cached values during next cmake execution
clearInputVariables()
