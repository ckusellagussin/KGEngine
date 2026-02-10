#include "shader.hpp"

const char *vertexShaderSource ="#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColour;\n"
"void main()"
"{\n"
"FragColour = vec4(0.3f, 0.8f, 0.2f, 1.0f);\n"
"}\n\0";




void shader::shaderInit()
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glGenBuffers(1, &VBO);
    glCompileShader(vertexShader);

    int success;
    char infolog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {

        glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
        std::cout << "Vertex Shader Compilation Error\n" << infolog;
        
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {

        glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
        std::cout << "Fragment Shader Compilation Error\n" << infolog;
        
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    

    if(!success)
    {

        glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
        std::cout << "Shader Program Linking Failure\n";
        
    }
    
    
    float vertices[] =
    {
        -0.9f, -0.5f, 0.0f,
        0.0f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        
        0.0f, 0.5f, 0.0f,
        0.9f, -0.5f, 0.0f,
        0.0f, -0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    
}
