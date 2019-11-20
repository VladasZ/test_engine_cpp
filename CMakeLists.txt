cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	include(build/build_tools_generated.cmake)
endif()

project(test_engine)

setup_conan_if_needed()
setup_deps()

add_subdirectory(source/test_engine_lib)

if(NOT ${NEEDS_SIGNING})
	add_subdirectory(source/test_engine_test)
endif()
