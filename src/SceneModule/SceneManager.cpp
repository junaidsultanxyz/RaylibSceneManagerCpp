//
// Created by JUNAID SULTAN on 12/8/2025.
//

#include "SceneManager.h"

#include <iostream>
#include <ostream>

std::map<std::string, Scene*> SceneManager::scenes;
Scene* SceneManager::currentScene = nullptr;

Scene * SceneManager::getCurrentScene() {
    return currentScene;
}

void SceneManager::setCurrentScene(const std::string &title) {
    currentScene = scenes.at(title);
}

void SceneManager::addScene(const std::string& title, Scene *scene) {
    scenes.insert(std::make_pair(title,scene));
}

void SceneManager::removeScene(const std::string &title) {
    scenes.erase(title);
}

void SceneManager::Start() {

    if (currentScene != nullptr) {
        currentScene->draw();

        if (!currentScene->getPaused())
            currentScene->update();
    }
    else {
        std::cout << "No Scenes initialized. Use setCurrentScene(string title)" << std::endl;
    }
}

void SceneManager::CleanUp() {
    for (const auto& pair : scenes) {
        delete pair.second;
    }
    scenes.clear();
}
