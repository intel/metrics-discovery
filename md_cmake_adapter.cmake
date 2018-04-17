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

#################################################################################
# HELPER FUNCTIONS
#################################################################################

#################################################################################
# clearInputVariables
#   Clears cached MDAPI input cmake variables. Needed for e.g. the below command scenario:
#   1. cmake -DMD_PLATFORM=linux -DMD_BUILD_TYPE=release -DMD_ARCH=32 -> MD_ARCH specified to 32
#   2. cmake -DMD_PLATFORM=linux -DMD_BUILD_TYPE=release              -> default MD_ARCH value should be used,
#                                                                        but without clearing, it will be still MD_ARCH=32
#################################################################################
function(clearInputVariables)
    unset(MD_PLATFORM CACHE)
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
    message("INFO: Input MD_PLATFORM      = ${MD_PLATFORM}")
    message("INFO: Input MD_BUILD_TYPE    = ${MD_BUILD_TYPE}")
    message("INFO: Input MD_ARCH          = ${MD_ARCH}")
    message("INFO: Input MD_LIBDRM_SRC    = ${MD_LIBDRM_SRC}")
    message("INFO: Input MD_LINUX_DISTRO  = ${MD_LINUX_DISTRO}")
endif()

# PLATFORM
if (NOT (MD_PLATFORM AND
         MD_PLATFORM STREQUAL "linux"))
    errorExit("ERROR: Specify correct MD_PLATFORM (-DMD_PLATFORM=linux)")
endif()
set(PLATFORM ${MD_PLATFORM})

# BUILD_TYPE
if (NOT (MD_BUILD_TYPE AND
         MD_BUILD_TYPE STREQUAL "release" OR
         MD_BUILD_TYPE STREQUAL "release-internal" OR
         MD_BUILD_TYPE STREQUAL "debug"))
    errorExit("ERROR: Specify correct MD_BUILD_TYPE (-DMD_BUILD_TYPE=release|release-internal|debug)")
endif()
set(BUILD_TYPE ${MD_BUILD_TYPE})

# ARCH
if (NOT (MD_ARCH))
    set(ARCH "64")
    message("-- using ARCH = ${ARCH}")
elseif (MD_ARCH STREQUAL "64" OR
        MD_ARCH STREQUAL "32")
    set(ARCH ${MD_ARCH})
else()
    errorExit("ERROR: Specify correct MD_ARCH (-DMD_ARCH=64|32)")
endif()

if (ARCH STREQUAL "32")
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
set(DUMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dump/${PLATFORM}${ARCH}/${BUILD_TYPE}/${PROJECT_NAME})

# OUTPUT
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DUMP_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DUMP_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DUMP_DIR})

# Clear input variables to have a 'fresh', non-cached values during next cmake execution
clearInputVariables()
