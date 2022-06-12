# CMakeList.txt : CMake project for KGEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)


project (KGEngine)


set(ENGINE_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/src/KGEngine.h
    ${CMAKE_CURRENT_LIST_DIR}/src/KGEngine.cpp
)


add_library(engine STATIC ${ENGINE_SOURCE})

set(TESTING_SOURCE
${CMAKE_CURRENT_LIST_DIR}/src/testing.cpp
)

add_executable(program ${TESTING_SOURCE})


# TODO: Add tests and install targets if needed.
target_link_libraries(program engine)
target_link_libraries(engine Vulkan::Vulkan)
target_link_libraries(engine glm::glm)
include_directories(C:/VulkanSDK/1.3.211.0/Include)
add_subdirectory(C:/GameEngine/KGEngine/include/glfw-3.3.7)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET engine PROPERTY CXX_STANDARD 20)
endif()
