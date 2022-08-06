#pragma once
#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE


class HelloTriangleApp
{
public: 
	GLFWwindow* window;
	VkInstance instance;
	const uint32_t HEIGHT = 600;
	const uint32_t WIDTH = 800;
	
	HelloTriangleApp();
	void run();

private:
	void initWindow();
	void createInstance();
	void initVulkan();
	void mainLoop();
	void cleanup();
	
	bool checkValidaitonSupport();
};
