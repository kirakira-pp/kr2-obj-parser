cmake_minimum_required(VERSION 3.10)

project(kr2-obj-parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME}
        main.cpp
        parser.cpp
)
