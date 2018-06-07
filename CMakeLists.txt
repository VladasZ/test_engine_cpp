cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(${CMAKE_SOURCE_DIR}/config/utils.cmake)

set(CMAKE_CXX_STANDARD 17)

project(TestEngine)

add_definitions(-DWINDOWS=1)
add_definitions(-DDEBUG=1)

add_subdirectory(source/Engine)
add_subdirectory(source/Tools)
add_subdirectory(source/ThirdParty/soil)
