cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(soil)

include_directories(inc)

add_library(${PROJECT_NAME} STATIC 
	src/image_helper.c
    src/stb_image_aug.c
    src/image_DXT.c
    src/SOIL.c
)
