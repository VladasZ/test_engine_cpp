cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

link_project(soil)
link_project(Tools)
link_project(Geometry)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
