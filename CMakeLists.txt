cmake_minimum_required(VERSION 4.0)
project(MyRaylibProject VERSION 1.0 LANGUAGES CXX)

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