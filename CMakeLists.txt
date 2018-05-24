#include(PrecompiledHeader.cmake)

function(add_recursive current_dir sources_files)
    file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${current_dir} ${PROJECT_SOURCE_DIR}/${current_dir}/*)
    foreach(child ${children})
        if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${current_dir}/${child})
            add_recursive(${current_dir}/${child} ${sources_files})
        else()
            get_filename_component(extension ${child} EXT)
            if (NOT extension STREQUAL "")
                string(REGEX MATCHALL "^.*.[h|hpp|c|cpp|cxx]" out ${extension})
                if (NOT out STREQUAL "")
                    if(MSVC)
                        string(REPLACE "/" "\\" groupname ${current_dir})
                    endif()
                    set(filename ${PROJECT_SOURCE_DIR}/${current_dir}/${child})
                    source_group(${groupname} FILES ${filename})
                    set(${sources_files} ${${sources_files}} ${filename})
                endif()    
            endif()
        endif()        
    endforeach()
    set(${sources_files} ${${sources_files}} PARENT_SCOPE)
endfunction(add_recursive)
#_________________________________________________________________________________________
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
get_filename_component(SolutionName ${CMAKE_CURRENT_LIST_DIR} NAME)

add_subdirectory(lib_temp/soil)

project(${SolutionName})

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include_directories(source)
include_directories(${PROJECT_SOURCE_DIR}/lib_temp/soil/inc/SOIL)
include(build/Include.cmake)
conan_basic_setup()

add_definitions(-DWINDOWS=1)
add_definitions(-DDEBUG=1)
add_definitions(-DGLFW=1)
add_definitions(-DDEBUG_VIEW=1)

add_recursive(source PARSED_SOURCE)
add_executable(${PROJECT_NAME} ${PARSED_SOURCE})


target_link_libraries(${PROJECT_NAME} soil)

foreach(debug_lib ${CONAN_LIBS_DEBUG})
    target_link_libraries(${PROJECT_NAME} debug ${debug_lib})
endforeach()

foreach(release_lib ${CONAN_LIBS_RELEASE})
    target_link_libraries(${PROJECT_NAME} optimized ${release_lib})
endforeach()