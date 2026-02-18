#include "shader_handler.hpp"

void shader_handler::checkCompileErrors(unsigned int shader, std::string type)
{

    int success;
    char infolog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {

            glGetShaderInfoLog(shader, 1024, NULL, infolog);
            std::cout << "Shader Compilation Error! Type Error:\n" << type << "\n" << infolog << "\n------------------------------------------"<<"\n";
        
        }
        else
        {
            glGetShaderiv(shader, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infolog);
                std::cout << "Linking Compilation Error! Type Error:\n" << type << "\n" << infolog << "\n------------------------------------------"<<"\n";
            }
        }
    }
    
}

shader_handler::shader_handler(const char* vertexPath, const char* fragmentPath)
{

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);

        std::stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexCode   = vertexShaderStream.str();
        fragmentCode = fragmentShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "Shader_Not_Successfully_Read :\n" << e.what() <<"\n";
    }

    const char* vertexShaderCode = vertexCode.c_str();
    const char* fragmentShaderCode = fragmentCode.c_str();

    unsigned int vertex {0}, fragment{0};
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1 , &vertexShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1 , &fragmentShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    iD = glCreateProgram();
    glAttachShader(iD, vertex);
    glAttachShader(iD, fragment);
    glLinkProgram(iD);
    checkCompileErrors(iD,"Program");
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    
}

void shader_handler::use()
{
 glUseProgram(iD);   
}


void shader_handler::setBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(iD, name.c_str()), (int)value);
}

void shader_handler::setFloat(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(iD, name.c_str()),value); 
}

void shader_handler::setInt(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(iD, name.c_str()), value);
    
}