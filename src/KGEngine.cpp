#include "KGEngine.h"



	HelloTriangleApp::HelloTriangleApp()
	{
		GLFWwindow* window = nullptr;
		VkInstance instance = nullptr;
	}



	//The overhead that is used to execute through program
	void HelloTriangleApp::run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();

	}



	/*Creates an instance that makes the connection between the libraryand the gpu driverand specifies details
	about the engine/app.*/
	void HelloTriangleApp::createInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "KG Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtentionCount = 0;
		
		vkEnumerateInstanceExtensionProperties(nullptr, &glfwExtentionCount, nullptr);

		std::vector<VkExtensionProperties> extentions(glfwExtentionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &glfwExtentionCount, extentions.data());
		
		const char** glfwExtentions;

		glfwExtentions =
			glfwGetRequiredInstanceExtensions(&glfwExtentionCount);

		createInfo.enabledExtensionCount = glfwExtentionCount;
		createInfo.ppEnabledExtensionNames = glfwExtentions;
		
		createInfo.enabledLayerCount = 0;

		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

		if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create Instance");

		}
		else
		{

			std::cout << "Instance Created!" << std::endl;
		}

		glfwExtentions = glfwGetRequiredInstanceExtensions(&glfwExtentionCount);
		std::cout << "glfw required extentions:" << std::endl;
		
		for (int i = 0; i < glfwExtentionCount; ++i)
		{

			std::cout << "\t" << glfwExtentions[i] << std::endl;

		}

		std::cout << "Available Extentions:\n" << std::endl;

		for (const auto& extention : extentions)
		{

			std::cout << '\t' << extention.extensionName << '\n';

		}



	}


	
	//Creates the window through glfw
	void HelloTriangleApp::initWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

	}

	
	
	void HelloTriangleApp::initVulkan()
	{
		createInstance();


	}

	
	
	//Main loop keeps the application working until it's closed
	void HelloTriangleApp::mainLoop()
	{
		while (!glfwWindowShouldClose(window))
		{

			glfwPollEvents();

		}
	}

	
	
	//Destroys objects for memory allocation
	void HelloTriangleApp::cleanup()
	{
		vkDestroyInstance(instance, nullptr);

		glfwDestroyWindow(window);

		glfwTerminate();

	}

