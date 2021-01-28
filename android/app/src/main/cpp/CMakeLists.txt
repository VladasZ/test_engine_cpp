cmake_minimum_required(VERSION 3.9.2 FATAL_ERROR)

project("test_engine")
include(build_tools_generated.cmake)

set(PROJECT_NAME native-lib)

#conan_basic_setup()

add_library(native-lib SHARED native-lib.cpp)

#conan_target_link_libraries(native-lib)

link_and_include_deps(native-lib)

add_subdirectory(${test_engine_PATH} "${test_engine_PATH}/dep_build")
link_project_at_path(test_engine ${test_engine_PATH})
link_from(test_engine)

find_library(log-lib log)
target_link_libraries(native-lib ${log-lib})

find_library(android-lib android)
target_link_libraries(native-lib ${android-lib})

find_library(EGL GLESv2 GLESv3)

#target_link_libraries(${PROJECT_NAME} GLESv2)

target_link_libraries(native-lib EGL GLESv2 GLESv3)

