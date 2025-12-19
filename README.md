# Raylib C++ Scene Manager

A modular and easy to manage game template along with Scene Manager for [Raylib](https://www.raylib.com/) using C++ and CMake.
Here is youtube video for complete explanation: [Click Here](https://www.youtube.com/@junaidsultanxyz)

![raylib-scene-manager-video-24fps](https://github.com/user-attachments/assets/e141e3cc-61d9-43c0-80fa-c308ae55be98)

## Features

* **Scene Management:** Easy scene switching
* **Template:** Ready to use game template to get started easily.
* **Modular Architecture:** Every scene logic is written in its respective file, promising clean and easy to maintain code
* **Automated Build:** Uses CMake `FetchContent` to automatically download and compile Raylib (no manual installation required).
* **Cross-Platform:** Works on Windows, macOS, and Linux with auto-detected compilers.

---

## Prerequisites

### All Platforms
- CMake 3.15 or higher ([Download Here](https://cmake.org/download/))
- A C++17 compatible compiler
- Git (for fetching Raylib)

### Platform-Specific Requirements

**Windows:**
- MinGW-w64 with g++ OR Visual Studio 2019+ with MSVC

**macOS:**
- Xcode Command Line Tools: `xcode-select --install`

**Linux (Ubuntu/Debian):**
```bash
sudo apt install build-essential cmake git
sudo apt install libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev
```

---

## Setup

1. ### Clone repository
  ```bash
    git clone https://github.com/junaidsultanxyz/RaylibSceneManagerCpp.git
    cd RaylibSceneManagerCpp
  ```
2. ### Build Project
    ### Option 1 (Easiest)

      **Windows:**
      ```cmd
      build.bat
      ```

      **macOS/Linux:**
      ```bash
      chmod +x build.sh
      ./build.sh
      ```

    ### Option 2: Using CMake Presets

    ```bash
    cmake --preset default
    cmake --build build --config Debug
    ```

---

## Running the Game
When you run the build script, it prompts you to run the game iun the end as well.

**Windows:**
```cmd
build\src\Game\Game.exe
```

**macOS/Linux:**
```bash
./build/src/Game/Game
```

---

## Troubleshooting

**CMake can't find compiler:**
- Windows: Ensure MinGW/MSVC is in your PATH. Check with `g++ --version` or open "Developer Command Prompt for VS"
- macOS: Install Xcode Command Line Tools with `xcode-select --install`
- Linux: Install build-essential with `sudo apt install build-essential`

**Build errors:**
- Delete the `build/` directory and try again
- Ensure you have internet connection (for Raylib download)
- Check that all prerequisites are installed

---

## How it works
![raylib-scene-manager-working-24fps](https://github.com/user-attachments/assets/4342484e-0c98-4987-965a-bac791c0882b)

- Scene Manager is built separately and can be used in any project. It is no external dependency.
- To create custom scene, inherit the abstract `Scene` class and override the abstract functions
- Add the scene in scene manager (go to `game.cpp` and use `SceneManager::addScene("title", new CustomScene())`. See [here](https://github.com/junaidsultanxyz/RaylibSceneManagerCpp/blob/a48644a99f47874349ecd68485b83f7b97f17d45/src/Game/game/Game.cpp#L29-L35)
- Now we can switch to custom scene anytime using `SceneManager::switchScene("title")`. Remember, the title for scene is always unique.
- Now code your draw and update logic for your custom scene

#### How to pause the Scene?
Every scene inherits an `isPaused` variable. Everything you write inside the `update()` function can be paused if this variable is true. You can set pause state using `setPaused(bool)` function inherited by Scene class.
See [SceneManager::Start()](https://github.com/junaidsultanxyz/RaylibSceneManagerCpp/blob/a48644a99f47874349ecd68485b83f7b97f17d45/src/SceneModule/SceneManager.cpp#L29-L40).
