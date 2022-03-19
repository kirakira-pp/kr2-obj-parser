#include "OpenGLApplication.h"
#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void GLAPIENTRY MessageCallback( GLenum source,
                                 GLenum type,
                                 GLuint id,
                                 GLenum severity,
                                 GLsizei length,
                                 const GLchar* message,
                                 const void* userParam )
{
    LOG_ERROR("GL CALLBACK: {} type = {:x}, severity = {:x}, message = {}",
              ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
              type, severity, message );
}

OpenGLApplication::OpenGLApplication(int argc, char* argv[])
    : Application(argc, argv)
{
}

OpenGLApplication::~OpenGLApplication()
{
}

bool OpenGLApplication::InitInternal()
{
    Application::InitInternal();
    //
    if(glfwInit() == GLFW_FALSE)
    {
        LOG_ERROR("Failed to initialize GLFW");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    m_Window = glfwCreateWindow(800, 600, "krkr", nullptr, nullptr);
    if(m_Window == nullptr)
    {
        LOG_ERROR("Failed to create GLFW window");
        return false;
    }

    glfwMakeContextCurrent(m_Window);
    if(!gladLoadGL())
    {
        LOG_ERROR("Failed to load OpenGL using GLAD");
        return false;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    glViewport(0, 0, 800, 600);
    glClearColor(.75f, .49f, .28f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Underlying Application Initialize
    Init();

    return true;
}

void OpenGLApplication::ShutdownInternal()
{
    Shutdown();
    //
    if(m_Window)
        glfwDestroyWindow(m_Window);
    glfwTerminate();
    //
    Application::ShutdownInternal();
}

void OpenGLApplication::ProcessInputInternal()
{
    glfwPollEvents();
    ProcessInput();
}

void OpenGLApplication::UpdateInternal(float dt)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Update(dt);
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

float OpenGLApplication::GetCurrentTime()
{
    return (float)glfwGetTime();
}
