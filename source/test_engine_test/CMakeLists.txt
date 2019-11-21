
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(test_engine_test)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)

if(${IOS_BUILD})
  file(GLOB ASSETS "/Users/vladas/.deps/test_engine/Assets")
endif()

add_executable(${PROJECT_NAME} ${SOURCE} ${ASSETS})

link_conan_if_needed()
link_deps()

link_project_at_path(test_engine ${test_engine_path})

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
  MACOSX_BUNDLE_BUNDLE_VERSION 1
  MACOSX_BUNDLE_SHORT_VERSION_STRING 1
  RESOURCE "${ASSETS}"
)

endif()

if(${ANDROID_BUILD})
target_link_libraries(${PROJECT_NAME} GLESv3)
endif()

