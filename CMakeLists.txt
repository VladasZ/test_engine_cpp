cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_SOURCE_DIR}/utils/utils.cmake)

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

add_subdirectory(source/Engine)
add_subdirectory(source/Geometry)
add_subdirectory(source/Tools)
add_subdirectory(source/Test)
add_subdirectory(source/soil)
