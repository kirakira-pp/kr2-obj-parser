#include <iostream>

#include "parser.h"
#include "Log.h"

#include "Core/OpenGLApplication.h"

class MyApp : public OpenGLApplication
{
public:
    MyApp(int argc, char* argv[])
        : OpenGLApplication(argc, argv)
    {
    }
    ~MyApp() = default;

    void ProcessInput() override
    {
        INFO("ProcessInput");
    }

    void Update(float dt) override
    {
        INFO("Update {}", dt);
    }

    void Render() override
    {
        INFO("Render");
    }
};

int main(int argc, char* argv[])
{
    MyApp app(argc, argv);
    app.Run();
}
