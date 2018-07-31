cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../ThirdParty/soil/inc/SOIL)

conan_basic_setup()

add_definitions(-DGLFW=1)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)
add_catalog_recursive(${PROJECT_SOURCE_DIR}/../Tools/source /Source/Tools SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} soil)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
