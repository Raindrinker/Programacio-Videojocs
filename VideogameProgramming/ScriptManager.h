#pragma once

#include<iostream>
#include<string>
#include<map>
#include "ECS.h"
#include "Components.h"
#include "Script.h"

using namespace std;
using namespace ECS;

class ScriptManager
{
public:

    ScriptManager();

    virtual void AddScript(Script* script);
    virtual void tick(float deltaTime);

private:
    std::list<Script*> scripts;

};