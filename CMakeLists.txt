cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

set(BUILD_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

include(${BUILD_DIRECTORY}/build_info.cmake)
include(${BUILD_DIRECTORY}/${BUILD_INFO})
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(test_engine)

conan_basic_setup()

add_subdirectory(source/test_engine_lib)
if(NOT ${CONSOLE_BUILD})
	add_subdirectory(source/test_engine_test)
endif()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  foreach(var ${GIT_DEPENDENCIES})
	add_subdirectory(${var} "${var}/dep_build")
  endforeach()
endif()

