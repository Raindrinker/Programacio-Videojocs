#include "ScriptManager.h"

ScriptManager::ScriptManager() {

}

void ScriptManager::tick(float deltaTime)
{
    
    for (Script* script : scripts) {
        cout << "run script" << endl;

        script->tickScript(deltaTime);
    }
}

void ScriptManager::AddScript(Script* script) {

    scripts.push_back(script);
}
