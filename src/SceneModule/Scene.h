//
// Created by JUNAID SULTAN on 12/8/2025.
//

#ifndef MYRAYLIBPROJECT_SCENE_H
#define MYRAYLIBPROJECT_SCENE_H

class Scene {
protected:
    bool isPaused = false;

public:
    virtual ~Scene() = default;

    void setPaused(const bool paused) { this->isPaused = paused; }
    bool getPaused() const { return this->isPaused; }

    virtual void draw() = 0;
    virtual void update() = 0;
};

#endif //MYRAYLIBPROJECT_SCENE_H