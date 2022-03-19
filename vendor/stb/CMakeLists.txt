cmake_minimum_required(VERSION 3.10)

project(stb)

add_library(${PROJECT_NAME} stb_image.c)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
