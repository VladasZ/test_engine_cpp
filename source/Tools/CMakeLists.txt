cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Tools)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_library(${PROJECT_NAME} ${SOURCE})

link_project(cpp_utils)
