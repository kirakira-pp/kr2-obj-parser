#include "OpenGLApplication.h"
#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

OpenGLApplication::OpenGLApplication(int argc, char* argv[])
    : Application(argc, argv)
{
}

OpenGLApplication::~OpenGLApplication()
{
}

bool OpenGLApplication::Init()
{
    if(glfwInit() == GLFW_FALSE)
    {
        ERROR("Failed to initialize GLFW");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(800, 600, "krkr", nullptr, nullptr);
    if(m_Window == nullptr)
    {
        ERROR("Failed to create GLFW window");
        return false;
    }

    glfwMakeContextCurrent(m_Window);
    if(!gladLoadGL())
    {
        ERROR("Failed to load OpenGL using GLAD");
        return false;
    }

    glViewport(0, 0, 800, 600);
    glClearColor(.75f, .49f, .28f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    return true;
}

void OpenGLApplication::Shutdown()
{
    if(m_Window)
        glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void OpenGLApplication::ProcessInputInternal()
{
    glfwPollEvents();
    ProcessInput();
}

float OpenGLApplication::UpdateInternal()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Update(0.f);
    return 0;
}

void OpenGLApplication::RenderInternal()
{
    Render();
    glfwSwapBuffers(m_Window);
}

bool OpenGLApplication::IsWindowRunning()
{
    return !glfwWindowShouldClose(m_Window);
}
