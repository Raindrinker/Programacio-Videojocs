#version 330 core
out vec4 FragColor;

in vec3 color;

in vec2 uvs;

uniform sampler2D tex0;

uniform vec3 tint = vec3(1.0, 1.0, 1.0);

void main()
{
   FragColor = texture(tex0, uvs);
}