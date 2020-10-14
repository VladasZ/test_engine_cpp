cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

project(native-lib)
include(build_tools_generated.cmake)

add_library(${PROJECT_NAME} SHARED native-lib.cpp)

link_and_include_deps(${PROJECT_NAME})

add_subdirectory(${test_engine_PATH} "${test_engine_PATH}/dep_build")
link_project_at_path(test_engine ${test_engine_PATH})
link_from(test_engine)

find_library(log-lib log)
target_link_libraries(${PROJECT_NAME} ${log-lib})

find_library(android-lib android)
target_link_libraries(${PROJECT_NAME} ${android-lib})
