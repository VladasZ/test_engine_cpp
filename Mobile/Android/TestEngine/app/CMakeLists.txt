cmake_minimum_required(VERSION 3.4.1)

function(add_catalog_recursive catalog group_catalog source_files)
    message(${catalog})
    message(${source_files})
    file(GLOB children RELATIVE ${catalog} ${catalog}/*)
    foreach(child ${children})
        if(IS_DIRECTORY ${catalog}/${child})
            add_catalog_recursive(${catalog}/${child} ${group_catalog}/${child} ${source_files})
        else()
            get_filename_component(extension ${child} EXT)
            if (NOT extension STREQUAL "")
                if(APPLE)
                    string(REGEX MATCHALL "^.*.[h|cpp|m|c]" out ${extension})
                else()
                    string(REGEX MATCHALL "^.*.[h|cpp]" out ${extension})
                endif()
                if (NOT out STREQUAL "")
                    if(MSVC)
                        string(REPLACE "/" "\\" group_catalog_name ${group_catalog})
                    else()
                        set(group_catalog_name ${group_catalog})
                    endif()
                    set(filename ${catalog}/${child})
                    source_group(${group_catalog_name} FILES ${filename})
                    message(${group_catalog_name} " group_catalog_name")
                    message(${filename} " filename")
                    include_directories(${catalog})
                    set(${source_files} ${${source_files}} ${filename})
                endif()
            endif()
        endif()
    endforeach()
    set(${source_files} ${${source_files}} PARENT_SCOPE)
endfunction(add_catalog_recursive)

project(Tools CXX)

add_catalog_recursive(../../../../../../source/Tools / TOOLS_SOURCE)
add_catalog_recursive(../../../../../source/Tools / TOOLS_SOURCE)
add_catalog_recursive(../../../../source/Tools / TOOLS_SOURCE)
add_catalog_recursive(../../../source/Tools / TOOLS_SOURCE)
add_catalog_recursive(../../source/Tools / TOOLS_SOURCE)

message("HEEELOOOOO")

message(${TOOLS_SOURCE})
message("HEEELOOOOO2")

add_library( Tools
             SHARED
            ${TOOLS_SOURCE}
            )


target_compile_options( Tools PUBLIC -std=c++17 -fpermissive -w -Wall )

add_library(
             native-lib
             SHARED
             src/main/cpp/native-lib.cpp
             )

find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib

                       ${log-lib}
                       GLESv2
                       Tools
                       )