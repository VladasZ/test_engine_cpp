cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${CMAKE_BINARY_DIR}/${BUILD_INFO})
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(TestEngine)

add_definitions(-DGLFW=1)
add_definitions(-DDEBUG=1)
add_definitions(-DUI_DESKTOP=1)

conan_basic_setup()

add_subdirectory(source/ui)
add_subdirectory(source/sand)
add_subdirectory(source/scene)
add_subdirectory(source/cpp_utils)
add_subdirectory(source/testengine)
