cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Tools)

include(${CONAN_BUILD_INFO})
conan_basic_setup()

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

conan_target_link_libraries(${PROJECT_NAME})
