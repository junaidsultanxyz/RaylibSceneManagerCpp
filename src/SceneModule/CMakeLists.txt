# Define the Engine Library
file(GLOB_RECURSE ENGINE_SOURCES
    "*.cpp"
    "*.h"
)

add_library(Engine STATIC ${ENGINE_SOURCES})

# Setup Include Directories
# "BUILD_INTERFACE" lets the Engine find headers locally
# "INSTALL_INTERFACE" would be for when you distribute the lib (optional here)
target_include_directories(Engine PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Link Raylib
# PUBLIC: The Game will also need to know about Raylib types (like Vector2)
target_link_libraries(Engine PUBLIC raylib)