#include "KGEngine.h"



	HelloTriangleApp::HelloTriangleApp()
	{
		GLFWwindow* window = nullptr;
		VkInstance instance = nullptr;
	}

	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

#ifdef NDEBUG
	const bool enableValidaitonLayers = false;
#else
	const bool enableValidaitonLayers = true;
#endif // NDEBUG




	//The overhead that is used to execute through program
	void HelloTriangleApp::run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();

	}



	/*Creates an instance that makes the connection between the library, gpu driver and specifies details
	about the engine/app.*/
	void HelloTriangleApp::createInstance()
	{

		if (enableValidaitonLayers && !checkValidaitonSupport())
		{
			throw std::runtime_error(" Validation Layers requested but are not available");

		}

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

		if (enableValidaitonLayers)
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else {
			createInfo.enabledLayerCount = 0;
		}

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


	//checks to see how many validaiton layers there are
	bool HelloTriangleApp::checkValidaitonSupport()
	{

		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector <VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers)
		{
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers)
			{

				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}

			}
			if (!layerFound)
			{

				return false;
			}

		}

		return true;

	}

	
	
	//Destroys objects for memory allocation
	void HelloTriangleApp::cleanup()
	{
		vkDestroyInstance(instance, nullptr);

		glfwDestroyWindow(window);

		glfwTerminate();

	}

