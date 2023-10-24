#include "ScriptSystem.h"

ScriptSystem::ScriptSystem() {
}

void ScriptSystem::start(World* world)
{
    world->each<ScriptComponent>([&](Entity* ent, ComponentHandle<ScriptComponent> script) {

        scriptManager.startScript(script->scriptId);

    });
}

void ScriptSystem::tick(World* world, float deltaTime)
{
    world->each<ScriptComponent>([&](Entity* ent, ComponentHandle<ScriptComponent> script) {

        scriptManager.tickScript(script->scriptId, deltaTime);

    });
}

ScriptManager* ScriptSystem::getScriptManager() {

    return &scriptManager;

}