
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test_engine_test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)

if(${IOS_BUILD})

  file(GLOB SHADERS "/Users/vladas/.deps/test_engine/Assets")

  # set(SHADERS
  # /Users/vladas/.deps/test_engine/Assets/Shaders/diffuse_colored.frag
  # /Users/vladas/.deps/test_engine/Assets/Shaders/diffuse_colored.vert
  # /Users/vladas/.deps/test_engine/Assets/Shaders/ui.frag
  # /Users/vladas/.deps/test_engine/Assets/Shaders/ui.vert
  #   )
endif()

add_executable(${PROJECT_NAME} ${SOURCE} ${SHADERS})

link_project_at_path(image           ${image_path}      )
link_project_at_path(ui_lib          ${ui_path}         )
link_project_at_path(geometry        ${geometry_path}   )
link_project_at_path(cpp_utils       ${cpp_utils_path}  )
link_project_at_path(scene_lib       ${scene_path}      )
link_project_at_path(gl_wrapper      ${gl_wrapper_path} )
link_project_at_path(test_engine_lib ${test_engine_path})

conan_target_link_libraries(${PROJECT_NAME})

if(${IOS_BUILD})

find_library(UIKIT UIKit)
find_library(GLKIT GLKit)
find_library(OPEN_GLES OpenGLES)
find_library(FOUNDATION Foundation)

target_link_libraries(${PROJECT_NAME} ${UIKIT})
target_link_libraries(${PROJECT_NAME} ${GLKIT})
target_link_libraries(${PROJECT_NAME} ${FOUNDATION})
target_link_libraries(${PROJECT_NAME} ${OPEN_GLES})

set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE TRUE
  MACOSX_BUNDLE_GUI_IDENTIFIER org.cmake.${PROJECT_NAME}d
  RESOURCE "${SHADERS}"
)

endif()



