#version 330 core
out vec4 FragColor;

in vec3 color;

uniform vec3 tint;

void main()
{
   FragColor = vec4(color * tint, 1.0f);
}