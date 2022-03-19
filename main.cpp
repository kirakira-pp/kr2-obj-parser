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
        INFO("Update");
    }

    void Render() override
    {
        INFO("Render");
    }
};

int main(int argc, char* argv[]) {
//	objParser *op = new objParser(argv[1]);

#ifdef VERBOSE
	op -> printVertexes();
#endif

    MyApp app(argc, argv);
    app.Run();
}
