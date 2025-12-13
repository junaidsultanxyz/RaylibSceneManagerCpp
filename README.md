# Raylib C++ Scene Manager

A modular and easy to manage game template along with Scene Manager for [Raylib](https://www.raylib.com/) using C++ and CMake.
Here is youtube video for complete explanation: [Click Here](https://www.youtube.com/@junaidsultanxyz)

![raylib-scene-manager-video-24fps](https://github.com/user-attachments/assets/e141e3cc-61d9-43c0-80fa-c308ae55be98)

## Features

* **Scene Management:** Easy scene switching
* **Template:** Ready to use game template to get started easily.
* **Modular Architecture:** Every scene logic is written in its respective file, promising clean and easy to 
* **Automated Build:** Uses CMake `FetchContent` to automatically download and compile Raylib (no manual installation required).
* **Cross-Platform:** Works on Windows, macOS, and Linux.

---

## Instructions
### Prerequisites
- Install [Cmake](https://cmake.org/download/)
- Install C++
### Setup
1. **Clone repository**
    ``` Bash
    git clone https://github.com/junaidsultanxyz/RaylibSceneManagerCpp.git
    cd RaylibSceneManagerCpp
    ```
2. **Generate project files**
   ``` Bash
    mkdir build
    cd build
    cmake ..
    ```
3. **Build project**
   ``` Bash
   cmake --build .
   ```
4. **Run the game**
  - Windows: .\src\Game\Debug\Game.exe
  - Linux/Mac: ./src/Game/Game

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
