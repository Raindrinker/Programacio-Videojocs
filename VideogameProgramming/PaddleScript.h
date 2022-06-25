#pragma once

#include<iostream>

#include "Script.h"

using namespace std;

class PaddleScript : public Script
{

    using Script::Script;

public:

    void startScript() override;

    void tickScript(float deltaTime) override;

};