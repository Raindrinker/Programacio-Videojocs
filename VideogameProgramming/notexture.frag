#version 330 core
out vec4 FragColor;

in vec3 color;

in vec3 normals;
in vec2 uvs;

uniform sampler2D tex0;

uniform vec3 tint = vec3(1.0, 1.0, 1.0);

uniform vec3 lightDirection = vec3(-0.5, -1, -0.75);
uniform float ambient = 0.2;

void main()
{
    vec3 texColor = tint;
    //FragColor = vec4(texColor.r, texColor.g, texColor.b, texColor.a);

    float dotProduct = 1- dot(lightDirection, normals);

    dotProduct = clamp(dotProduct, 0, 1);

    vec3 directionalLight = vec3(dotProduct, dotProduct, dotProduct);

    FragColor = vec4((texColor * directionalLight).xyz, 1.0);

    //FragColor = vec4((normals.x+1.)/2., (normals.y+1.)/2., (normals.z+1.)/2., 1.0f);
   //FragColor = vec4(uvs, 0.0f, 1.0f);
   //FragColor = vec4(color, 1.0f);
}