
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(sand)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(cpp_utils)
link_project(sand_lib)

link_project_at_path(geometry ${PROJECT_SOURCE_DIR}/../ui/source/geometry)

conan_target_link_libraries(${PROJECT_NAME})
