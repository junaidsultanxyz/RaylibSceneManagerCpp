//
// Created by JUNAID SULTAN on 12/10/2025.
//

#include "Game.h"

#include "raylib.h"
#include "SceneManager.h"
#include "../settings.h"
#include "../scenes/scene1/Scene1.h"
#include "../scenes/scene2/Scene2.h"

Scene* scene1 = new Scene1();
Scene* scene2 = new Scene2();

void Game::StartGame() {
    setScenes();

    InitWindow(DISPLAY_WIDTH, DISPLAY_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    while (!WindowShouldClose()) {
        BeginDrawing();
        SceneManager::Start();
        EndDrawing();
    }
    SceneManager::CleanUp(); // deletes the Scene* from the map
    CloseWindow();
}

void Game::setScenes() {
    SceneManager::addScene("scene1", new Scene1());
    SceneManager::addScene("scene2", new Scene2());

    // calling this here to set first scene
    SceneManager::setCurrentScene("scene1");
}
