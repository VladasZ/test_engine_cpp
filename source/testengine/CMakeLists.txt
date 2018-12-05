cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(testengine)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

include_recursive(${PROJECT_SOURCE_DIR}/../ui/source/ui_lib)
target_link_libraries(${PROJECT_NAME} ui_lib)

include_recursive(${PROJECT_SOURCE_DIR}/../ui/source/geometry)
target_link_libraries(${PROJECT_NAME} geometry)

link_project(cpp_utils)
link_project(soil)

conan_target_link_libraries(${PROJECT_NAME})
