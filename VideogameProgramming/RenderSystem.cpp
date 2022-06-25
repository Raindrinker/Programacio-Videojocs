#include "RenderSystem.h"

RenderSystem::RenderSystem(int width, int height) {
    projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

    sr.Init();
}

void RenderSystem::tick(World* world, float deltaTime) 
{
    world->each<Sprite>([&](Entity* ent, ComponentHandle<Sprite> sprite) {

        cout << "render" << endl;

        ComponentHandle<Transform> transform = ent->get<Transform>();

        Texture texture = textureManager.GetTexture(sprite->filepath);
            
        sr.DrawSprite(texture, projection, transform->position, texture.GetSize());

    });
}

void RenderSystem::unconfigure(World* world) {

    sr.Delete();

    textureManager.Delete();
}
