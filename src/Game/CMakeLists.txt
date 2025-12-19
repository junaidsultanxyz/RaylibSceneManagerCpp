# Define the Executable
file(GLOB_RECURSE GAME_SOURCES
    "*.cpp"
    "*.h"
)
add_executable(Game ${GAME_SOURCES})
# Link the Engine
target_link_libraries(Game PRIVATE Engine)

# --- Platform Specific Settings ---
if(WIN32)
    # Windows: Add console for debug output, or remove console for release
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set_target_properties(Game PROPERTIES WIN32_EXECUTABLE TRUE)
    endif()
elseif(APPLE)
    # macOS: Set bundle properties if needed
    set_target_properties(Game PROPERTIES
        MACOSX_BUNDLE FALSE
    )
elseif(UNIX)
    # Linux: Link additional required libraries
    target_link_libraries(Game PRIVATE Threads::Threads)
endif()

# Copy assets or set working directory as needed
# Raylib handles OpenGL linking internally via its CMake config