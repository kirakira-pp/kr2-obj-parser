#pragma once
#ifndef KR2_OBJ_PARSER_OPENGLAPPLICATION_H
#define KR2_OBJ_PARSER_OPENGLAPPLICATION_H

#include "Application.h"

// TODO: Add Window Spec class

class GLFWwindow;

class OpenGLApplication : public Application
{
public:
    OpenGLApplication(int argc, char* argv[]);
    ~OpenGLApplication();

    bool InitInternal() override;
    void ShutdownInternal() override;

    void ProcessInputInternal() override;
    void UpdateInternal(float dt) override;
    void RenderInternal() override;

    bool IsWindowRunning() override;

private:
    GLFWwindow *m_Window;

protected:
    float GetCurrentTime() override;
};

#endif //KR2_OBJ_PARSER_OPENGLAPPLICATION_H