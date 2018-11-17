
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(sand)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(geometry)
link_project(cpp_utils)

conan_target_link_libraries(${PROJECT_NAME})
