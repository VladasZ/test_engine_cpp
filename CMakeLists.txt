cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

set(DEPS_DIR $ENV{HOME}/.deps)
if (NOT EXISTS ${DEPS_DIR}/build_tools)
	execute_process(COMMAND git clone https://github.com/vladasz/build_tools ${DEPS_DIR}/build_tools)
endif()
include(${DEPS_DIR}/build_tools/utils.cmake)


if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	include(build/build_tools_generated.cmake)
endif()

set(CMAKE_CXX_STANDARD 17)

setup_project(test_engine)
