cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	include(build_tools_generated.cmake)
endif()

set(CMAKE_CXX_STANDARD 17)

setup_project(test_engine)
