#pragma once
#ifndef KR2_OBJ_PARSER_APPLICATION_H
#define KR2_OBJ_PARSER_APPLICATION_H

class Application
{
public:
    Application(int argc, char* argv[]);
    ~Application();

    virtual bool Init() = 0;
    virtual void Shutdown() = 0;

    virtual void ProcessInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;

    virtual void ProcessInputInternal() = 0;
    virtual void UpdateInternal(float dt) = 0;
    virtual void RenderInternal() = 0;

    virtual bool IsWindowRunning() = 0;

    void Run();

protected:
    int m_Argc;
    char **m_Argv;

    virtual float GetCurrentTime() = 0;
    float GetElapsedTime();
    float m_LastTime = 0.f;
};

#endif //KR2_OBJ_PARSER_APPLICATION_H
