#include "renderer.hpp"
#include "shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void windowEscape(GLFWwindow *window);

void renderer::windowInitialization()
{
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(720, 520, "KG Engine", NULL, NULL);
    
    if(window == NULL)
    {
        std::println("Failed to create window");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {

        std::println("Failed to initialize GLAD");
        
    }

    shader shader;
    while(!glfwWindowShouldClose(window))
    {
        windowEscape(window);
        glClearColor(0.3f,0.3f,0.3f,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.shaderInit();
        glUseProgram(shader.shaderProgram);
        glBindVertexArray(shader.VAO);
        glDrawArrays(GL_TRIANGLES, 0 , 6);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    glfwTerminate();
    
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

    glViewport(0,0,width,height);
    
}

void windowEscape(GLFWwindow *window)
{

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {

        glfwSetWindowShouldClose(window, true);
        
    }
    
}

