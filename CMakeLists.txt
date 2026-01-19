cmake_minimum_required(VERSION 3.20)

project(KGEngine
    VERSION 0.1.0
    LANGUAGES CXX
)

# ============================
# Global C++ Settings
# ============================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4 /permissive-)
endif()

# ============================
# Engine Target
# ============================
add_executable(KGEngine
    src/main.cpp
)

if (WIN32)
    set_target_properties(KGEngine PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()


target_include_directories(KGEngine
    PRIVATE
        src
        external/entt/src       # EnTT (header-only)
)

# ============================
# Windows / DX11
# ============================
if (WIN32)
    target_compile_definitions(KGEngine PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

    target_link_libraries(KGEngine
        PRIVATE
            d3d11
            dxgi
            d3dcompiler
    )
endif()

# ============================
# Bullet Physics (Prebuilt)
# ============================
find_package(Bullet CONFIG REQUIRED)

target_link_libraries(KGEngine
    PRIVATE
        BulletDynamics
        BulletCollision
        BulletSoftBody
)

# ============================
# Assimp (Prebuilt)
# ============================
find_package(assimp CONFIG REQUIRED)

target_link_libraries(KGEngine
    PRIVATE
        assimp::assimp
)

# ============================
# RenderDoc (Runtime Only)
# ============================

target_compile_definitions(KGEngine
    PRIVATE
        KGENGINE_ENABLE_RENDERDOC
)

# ============================
# Output Directories
# ============================
set_target_properties(KGEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ============================
# Warnings / Clean Build
# ============================
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT KGEngine)
