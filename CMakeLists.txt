cmake_minimum_required(VERSION 3.21)
project(KGEngine LANGUAGES CXX)

# ============================
# C++ Standard
# ============================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================
# Source Files (AUTO)
# ============================
file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
    src/*.hpp
    src/*.h
)

add_executable(KGEngine ${ENGINE_SOURCES})

# ============================
# OpenGL Packages
# ============================
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Bullet CONFIG REQUIRED)

# Optional
# find_package(assimp CONFIG REQUIRED)

# ============================
# Link Libraries
# ============================
target_link_libraries(KGEngine PRIVATE
    glfw
    glad::glad
    glm::glm
    spdlog::spdlog

    BulletDynamics
    BulletCollision
    LinearMath
)

# ============================
# Include Paths
# ============================
target_include_directories(KGEngine PRIVATE
    src
    external/stb
)

# ============================
# Windows Specific
# ============================
if (WIN32)
    target_compile_definitions(KGEngine PRIVATE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()
