cmake_minimum_required(VERSION 3.14)
project(gpu_trace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gpu_trace gpu_trace.cpp)

target_include_directories(gpu_trace PRIVATE
    ${CMAKE_SOURCE_DIR}/../inc/common/instrumentation/api
)

target_link_libraries(gpu_trace PRIVATE dl)
