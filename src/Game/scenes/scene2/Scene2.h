//
// Created by JUNAID SULTAN on 12/10/2025.
//

#ifndef MYRAYLIBPROJECT_SCENE2_H
#define MYRAYLIBPROJECT_SCENE2_H
#include "Scene.h"


class Scene2 final : public virtual Scene {
public:
    ~Scene2() override = default;

    void draw() override;
    void update() override;
};


#endif //MYRAYLIBPROJECT_SCENE2_H