cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../ThirdParty/soil/inc/SOIL)
include_directories(${PROJECT_SOURCE_DIR})
include(../../build/EngineInclude.cmake)
conan_basic_setup()

add_definitions(-DWINDOWS=1)
add_definitions(-DDEBUG=1)
add_definitions(-DGLFW=1)
add_definitions(-DDEBUG_VIEW=1)

add_catalog_recursive(${PROJECT_SOURCE_DIR} / SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} soil)

foreach(debug_lib ${CONAN_LIBS_DEBUG})
    target_link_libraries(${PROJECT_NAME} debug ${debug_lib})
endforeach()

foreach(release_lib ${CONAN_LIBS_RELEASE})
    target_link_libraries(${PROJECT_NAME} optimized ${release_lib})
endforeach()
