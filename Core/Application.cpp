#include "Application.h"
#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// TODO: Add the game loop pattern: https://gpp.tkchu.me/game-loop.html
// TODO: Add support for parse arguements

Application::Application(int argc, char **argv)
{
    m_Argc = argc;
    m_Argv = argv;
}

Application::~Application()
{
}

void Application::Run()
{
    if(!InitInternal())
    {
        LOG_ERROR("Failed to Initialize Application");
        ShutdownInternal();
        return;
    }

    while(IsWindowRunning())
    {
        float dt = GetElapsedTime();
        ProcessInputInternal();
        UpdateInternal(dt);
        RenderInternal();
    }

    ShutdownInternal();
}

float Application::GetElapsedTime()
{
    float now = GetCurrentTime();
    float elapsed = now - m_LastTime;
    m_LastTime = now;
    return elapsed;
}

bool Application::InitInternal()
{
    return true;
}

void Application::ShutdownInternal()
{
}
