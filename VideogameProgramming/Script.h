#pragma once

#include<iostream>
#include <glm/glm.hpp>

#include "ECS.h"
#include "Components.h"

using namespace std;
using namespace ECS;

class Script
{
public:

    Script(Entity* entity);

    virtual void startScript();
    
    virtual void tickScript(float deltaTime);

protected:
    Entity* entity;

};