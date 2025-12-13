//
// Created by JUNAID SULTAN on 12/10/2025.
//

#include "Scene2.h"

#include "raylib.h"
#include "SceneManager.h"
#include "../../settings.h"

void Scene2::draw() {
    const int font = 50;

    ClearBackground(RAYWHITE);
    DrawText("Scene 2", DISPLAY_WIDTH/2 - font*2, DISPLAY_HEIGHT/2 - font, font, LIGHTGRAY );

    if (IsKeyDown(KEY_F1)) SceneManager::setCurrentScene("scene1");
}

void Scene2::update() {

}
