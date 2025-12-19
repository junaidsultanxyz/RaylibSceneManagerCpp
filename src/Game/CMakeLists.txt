# Define the Executable
add_executable(Game
        main.cpp
        settings.h
        scenes/scene1/Scene1.cpp
        scenes/scene1/Scene1.h
        scenes/scene2/Scene2.cpp
        scenes/scene2/Scene2.h
        game/Game.cpp
        game/Game.h
)

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