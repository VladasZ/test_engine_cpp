cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

link_project(soil)
link_project(Tools)
link_project(Geometry)

conan_target_link_libraries(${PROJECT_NAME})
