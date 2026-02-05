#include "Renderer.hpp"


void renderer::windowInitialization()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    Window = glfwCreateWindow(720, 520, "KG Engine", NULL, NULL);
    
    if(!glfwInit())
    {
        std::println("GLFW failed to initialize");
    }
    
    if(!Window)
    {
        std::print("Window failed to initialize");
    }
    
    glfwTerminate();
    
}
