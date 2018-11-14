cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(UI)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

link_project(Tools)

conan_target_link_libraries(${PROJECT_NAME})
