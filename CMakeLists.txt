cmake_minimum_required(VERSION 3.15)
project(RaylibSceneManagement VERSION 1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Platform-specific settings ---
if(WIN32)
    # Windows specific settings
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(APPLE)
    # macOS specific settings
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum macOS deployment version")
elseif(UNIX)
    # Linux specific settings
    # Find required packages for Linux
    find_package(Threads REQUIRED)
endif()

# --- 1. Setup Dependencies (Raylib) ---
include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master  # Or a specific tag like 'v5.0' for stability
)

# Configuration options to speed up the build (we don't need Raylib examples)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

# --- 2. Add Subdirectories ---
# Order matters: Engine must be defined before Game links to it.
add_subdirectory(src/SceneModule)
add_subdirectory(src/Game)