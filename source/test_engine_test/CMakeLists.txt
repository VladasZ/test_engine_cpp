
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test_engine_test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

link_project_at_path(ui_lib          ${ui_path}         )
link_project_at_path(geometry        ${geometry_path}   )
link_project_at_path(cpp_utils       ${cpp_utils_path}  )
link_project_at_path(scene_lib       ${scene_path}      )
link_project_at_path(test_engine_lib ${test_engine_path})

conan_target_link_libraries(${PROJECT_NAME})
