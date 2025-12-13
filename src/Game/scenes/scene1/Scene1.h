//
// Created by JUNAID SULTAN on 12/10/2025.
//

#ifndef MYRAYLIBPROJECT_SCENE1_H
#define MYRAYLIBPROJECT_SCENE1_H
#include "Scene.h"


class Scene1 final : public virtual Scene {
public:
    virtual ~Scene1() = default;

    void draw() override;
    void update() override;
};


#endif //MYRAYLIBPROJECT_SCENE1_H