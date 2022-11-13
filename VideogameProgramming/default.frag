#version 330 core
out vec4 FragColor;

in vec3 color;

in vec3 normals;
in vec2 uvs;

uniform sampler2D tex0;

uniform vec3 tint = vec3(1.0, 1.0, 1.0);

void main()
{
    vec4 texColor = texture(tex0, uvs);
    //FragColor = vec4(texColor.r, texColor.g, texColor.b, texColor.a);

   FragColor = vec4((normals.x+1.)/2., (normals.y+1.)/2., 0, 1.0f);
   //FragColor = vec4(uvs, 0.0f, 1.0f);
   //FragColor = vec4(color, 1.0f);
}