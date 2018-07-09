cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_SOURCE_DIR}/config/utils.cmake)

set(CMAKE_CXX_STANDARD 17)

project(TestEngine)

if (WIN32)
	add_definitions(-DWINDOWS=1)
endif ()

if (APPLE)
	add_definitions(-DAPPLE=1)
	add_definitions(-DMAC_OS=1)
endif ()


add_definitions(-DDEBUG=1)

add_subdirectory(source/Engine)
add_subdirectory(source/Tools)
add_subdirectory(source/TestTools)
add_subdirectory(source/ThirdParty/soil)
