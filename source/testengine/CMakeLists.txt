cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(testengine)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

link_project_at_path(ui_lib    ${PROJECT_SOURCE_DIR}/../ui/source/ui_lib)
link_project_at_path(scene_lib ${PROJECT_SOURCE_DIR}/../scene/source/scene_lib)
link_project_at_path(geometry  ${PROJECT_SOURCE_DIR}/../ui/source/geometry)
link_project_at_path(soil      ${PROJECT_SOURCE_DIR}/../ui/source/soil)

link_project(cpp_utils)

conan_target_link_libraries(${PROJECT_NAME})
