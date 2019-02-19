cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_BINARY_DIR}/build_info.cmake)
include(${CMAKE_BINARY_DIR}/${BUILD_INFO})
include(${BUILD_SCRIPT_PATH})

set(CMAKE_CXX_STANDARD 17)

project(test_engine)

add_definitions(-DGLFW=1)
add_definitions(-DDEBUG=1)
add_definitions(-DUI_DESKTOP=1)

conan_basic_setup()

add_subdirectory(source/test_engine_lib)
add_subdirectory(source/test_engine_test)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  foreach(var ${GIT_DEPENDENCIES})
	add_subdirectory(${var} "${var}/dep_build")
  endforeach()
endif()

