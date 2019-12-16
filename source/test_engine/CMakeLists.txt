cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

setup_lib(test_engine)

if(IOS_BUILD)
    set(CMAKE_LINKER_FLAGS "-Wl,--export-all-symbols")
endif()

if(${ANDROID_BUILD})
    target_link_libraries(${PROJECT_NAME} GLESv2)
    target_link_libraries(${PROJECT_NAME} GLESv3)
endif()
