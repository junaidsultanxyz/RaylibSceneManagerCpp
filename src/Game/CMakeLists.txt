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

# --- Platform Specific Hook ---
# If on Windows/MacOS, we usually need to copy assets to the build folder
# or ensure the working directory is set correctly.
# Raylib usually handles the OpenGL linking internally via its CMake config.