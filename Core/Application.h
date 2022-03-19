#pragma once
#ifndef KR2_OBJ_PARSER_APPLICATION_H
#define KR2_OBJ_PARSER_APPLICATION_H

class Application
{
public:
    Application(int argc, char* argv[]);
    ~Application();

    /**
     * Init
     * @return
     */
    virtual bool Init() = 0;
    virtual void Shutdown() = 0;

    virtual void ProcessInput() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;

    virtual void ProcessInputInternal() = 0;
    virtual float UpdateInternal() = 0;
    virtual void RenderInternal() = 0;

    virtual bool IsWindowRunning() = 0;

    void Run();

protected:
    int m_Argc;
    char **m_Argv;
};

#endif //KR2_OBJ_PARSER_APPLICATION_H
