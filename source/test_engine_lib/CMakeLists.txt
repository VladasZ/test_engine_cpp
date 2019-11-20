cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

setup_lib(test_engine_lib)

if(IOS_BUILD)
  set(CMAKE_LINKER_FLAGS "-Wl,--export-all-symbols")
endif()

link_project_at_path(image      ${image_path}     )
link_project_at_path(ui_lib     ${ui_path}        )
link_project_at_path(sprites    ${sprites_path}   )
link_project_at_path(geometry   ${geometry_path}  )
link_project_at_path(cpp_utils  ${cpp_utils_path} )
link_project_at_path(scene_lib  ${scene_path}     )
link_project_at_path(gl_wrapper ${gl_wrapper_path})
