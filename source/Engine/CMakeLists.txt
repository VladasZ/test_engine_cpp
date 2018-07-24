cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(Engine)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include_directories(${PROJECT_SOURCE_DIR}/../ThirdParty/soil/inc/SOIL)
include_directories(/home/vladas/.conan/data/glm/0.9.8.5/bincrafters/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include)
include_directories(/home/vladas/.conan/data/glew/2.1.0/bincrafters/stable/package/0a813c597d519ec14c71192b99d7de0a92bbc1c3/include)
include_directories(/home/vladas/.conan/data/glfw/3.2.1.20180327/bincrafters/stable/package/0a813c597d519ec14c71192b99d7de0a92bbc1c3/include)
include_directories(/home/vladas/.conan/data/freetype/2.9.0/bincrafters/stable/package/1e25f8fc336196e0898e984c1f0498b55571827c/include/freetype2)

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
