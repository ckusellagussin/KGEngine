#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

class renderer
{
public:
    int VBO, VAO, EBA;
    GLFWwindow* Window;
    
    void windowInitialization();
    

    
};

#endif
