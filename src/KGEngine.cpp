#include "KGEngine.h"

void Initialise() 
{
    std::cout << "ENGINE INITIALISED!" << std::endl;


    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);

    uint32_t extentionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extentionCount, nullptr);

    std::cout << extentionCount << "extentions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window))
    {

        glfwPollEvents();

    }

    glfwDestroyWindow(window);

    glfwTerminate;


}

