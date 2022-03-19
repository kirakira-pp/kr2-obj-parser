#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "parser.h"

int main(int argc, char* argv[]) {
	objParser *op = new objParser(argv[1]);

#ifdef VERBOSE
	op -> printVertexes();
#endif

    glfwInit();
    // Specify OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "krkr", nullptr, nullptr);
    if(window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        return 1;
    }
    // Load OpenGL Context
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, 800, 600);
    glClearColor(.75f, .49f, .28f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
