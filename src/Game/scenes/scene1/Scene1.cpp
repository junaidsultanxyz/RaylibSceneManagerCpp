//
// Created by JUNAID SULTAN on 12/10/2025.
//

#include "Scene1.h"

#include "raylib.h"
#include "SceneManager.h"
#include "../../settings.h"

void Scene1::draw() {
    const int font = 50;

    ClearBackground(RAYWHITE);
    DrawText("Scene 1", DISPLAY_WIDTH/2 - font*2, DISPLAY_HEIGHT/2 - font, font, LIGHTGRAY );
    if (IsKeyDown(KEY_F2)) SceneManager::setCurrentScene("scene2");
}

void Scene1::update() {
}
