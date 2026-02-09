#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

class renderer
{
public:
    GLFWwindow* window;
    void windowInitialization();
};

#endif
