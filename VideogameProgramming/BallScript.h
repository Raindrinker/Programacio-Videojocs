#pragma once

#include "Script.h"
#include "BlockScript.h"

using namespace std;

class BallScript : public Script
{

    using Script::Script;

public:

    void startScript() override;

    void tickScript(float deltaTime) override;

private:
    void CheckCollisions();

    glm::vec2 currDir = glm::vec2(0., 1.);
    glm::vec2 limits = glm::vec2(800., 800.);

};