#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

using namespace std;

class SpriteRenderer
{
public:
    SpriteRenderer();

    void Init();

    void DrawSprite(Texture& texture, glm::mat4 proj, glm::vec2 position,
        glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
        glm::vec3 color = glm::vec3(1.0f), string shaderName = "default");

    void Delete();
private:
    std::shared_ptr<Shader> shaderDefault;
    std::shared_ptr<Shader> shaderInverted;
    std::shared_ptr<Shader> shaderRepeating;
    std::shared_ptr<VAO> vao;
    std::shared_ptr<VBO> vbo;
    std::shared_ptr<EBO> ebo;
};