cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

include(build_tools_generated.cmake)

project(native-lib)

add_library(${PROJECT_NAME} SHARED native-lib.cpp)

setup_deps()
link_deps()

add_subdirectory(${test_engine_path} "${test_engine_path}/dep_build")
link_project_at_path(test_engine ${test_engine_path})

find_library(log-lib log)
target_link_libraries(${PROJECT_NAME} ${log-lib})

find_library(android-lib android)
target_link_libraries(${PROJECT_NAME} ${android-lib})
