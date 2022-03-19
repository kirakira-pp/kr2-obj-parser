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
		Graphics/VertexBuffer.cpp

        # Application
		Core/Application.cpp
		Core/OpenGLApplication.cpp
		Core/Log.cpp)

target_include_directories(${PROJECT_NAME}
		PUBLIC .
		PUBLIC Core
		PUBLIC Graphics)

target_link_libraries(${PROJECT_NAME} PUBLIC
        glfw
        glad::glad
        glm::glm
        fmt::fmt)
