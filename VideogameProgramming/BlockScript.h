#pragma once

#include "Script.h"

using namespace std;

class BlockScript : public Script
{

    using Script::Script;

public:

    void tickScript(float deltaTime) override;

private:
    int hp = 1;
    bool destroyed = false;

};