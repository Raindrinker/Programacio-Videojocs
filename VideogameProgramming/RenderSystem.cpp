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
           
        if (sprite->autoSize) {
            sr.DrawSprite(texture, projection, transform->position, texture.GetSize(), transform->rotation, sprite->color, sprite->shaderName);
        }
        else {
            sr.DrawSprite(texture, projection, transform->position, sprite->size, transform->rotation, sprite->color, sprite->shaderName);
        }

    });
}