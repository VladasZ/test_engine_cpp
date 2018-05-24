cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(configuration/sources_parsing.cmake)

project(TestEngine)

add_subdirectory(source/Engine)
add_subdirectory(source/ThirdParty/soil)
