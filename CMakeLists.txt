cmake_minimum_required(VERSION 3.10)

project(kr2-obj-parser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
# add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/fmt)

add_executable(${PROJECT_NAME}
        main.cpp
        obj_parser.cpp
	vertex_parser.cpp
        Log.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        glfw
        glad::glad
        glm::glm
        fmt::fmt)
