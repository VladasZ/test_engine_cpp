cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${CMAKE_BINARY_DIR}/${BUILD_INFO})
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(TestEngine)

if (WIN32)
	add_definitions(-DWINDOWS=1)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS=1)
endif ()

if (APPLE)
	add_definitions(-DAPPLE=1)
	add_definitions(-DMAC_OS=1)
endif ()

add_definitions(-DGLFW=1)
add_definitions(-DDEBUG=1)

conan_basic_setup()

add_subdirectory(source/sand)
add_subdirectory(source/testengine)
add_subdirectory(source/geometry)
add_subdirectory(source/cpp_utils)
add_subdirectory(source/soil)
