#ifndef SHADER_HANDLER_HPP
#define SHADER_HANDLER_HPP

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader_handler
{
public:
    unsigned int iD;
    shader_handler(const char* vertexPath, const char* fragmentPath);

    void use();
    
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, bool value) const;
    void setFloat(const std::string &name, bool value) const;
    void checkCompileErrors(unsigned int shader, std::string type);
    
};

#endif