#pragma once

#include <glm/glm.hpp>
#include "Texture.h"

struct Transform
{
    Transform(glm::vec2 position, float rotation, float scale) {
        this->position = position;
        this->rotation = rotation;
        this->scale = scale;
    }

    glm::vec2 position;
    float rotation;
    float scale;
};

struct Sprite
{
    Sprite(const char* filepath, glm::vec3 color) {
        this->filepath = filepath;
        this->color = color;
    }

    const char* filepath;
    glm::vec3 color;
};