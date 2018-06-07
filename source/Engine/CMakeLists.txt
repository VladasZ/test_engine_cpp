cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../ThirdParty/soil/inc/SOIL)

conan_basic_setup()

add_definitions(-DGLFW=1)

add_catalog_recursive(${PROJECT_SOURCE_DIR} /Source SOURCE)
add_catalog_recursive(${PROJECT_SOURCE_DIR}/../Tools/source /Source/Tools SOURCE)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} soil)

foreach(debug_lib ${CONAN_LIBS_DEBUG})
    target_link_libraries(${PROJECT_NAME} debug ${debug_lib})
endforeach()

foreach(release_lib ${CONAN_LIBS_RELEASE})
    target_link_libraries(${PROJECT_NAME} optimized ${release_lib})
endforeach()
