cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project(Tools)
link_project(Geometry)
link_project(cpp_utils)

conan_target_link_libraries(${PROJECT_NAME})
