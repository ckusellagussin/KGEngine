#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

class shader
{
public:
    unsigned int VBO, VAO, EBO, vertexShader, fragmentShader, shaderProgram;
    
    void shaderInit();
    
};

#endif