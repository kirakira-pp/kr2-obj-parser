#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "parser.h"
#include "Log.h"

struct Test
{
    int a;

    friend std::ostream& operator<<(std::ostream& out, const Test &test)
    {
        out << test.a;
        return out;
    }
};

template <>
struct fmt::formatter<Test>: formatter<std::string> {
    template <typename FormatContext>
    auto format(Test t, FormatContext& ctx) {
        auto ans = fmt::format("Fuck = {}", t.a);
        return formatter<std::string>::format(ans, ctx);
    }
};

int main(int argc, char* argv[]) {
	objParser *op = new objParser(argv[1]);

#ifdef VERBOSE
	op -> printVertexes();
#endif

    INFO("test");
    TRACE("123123");
    Test t;
    DEBUG("{} {} {} {} {}", 1, "2", 3.f, 4.0, t);

    glfwInit();
    // Specify OpenGL version
#if __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
#else
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    
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
