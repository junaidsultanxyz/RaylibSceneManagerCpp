//
// Created by JUNAID SULTAN on 12/8/2025.
//

#ifndef MYRAYLIBPROJECT_SCENEMANAGER_H
#define MYRAYLIBPROJECT_SCENEMANAGER_H

#include <map>
#include <string>

#include "Scene.h"


class SceneManager {
    static std::map<std::string, Scene*> scenes;
    static Scene* currentScene;

public:
    static Scene* getCurrentScene();
    static void setCurrentScene(const std::string &title);
    static void addScene(const std::string& title, Scene* scene);
    static void removeScene(const std::string &title);

    static void Start();
};


#endif //MYRAYLIBPROJECT_SCENEMANAGER_H