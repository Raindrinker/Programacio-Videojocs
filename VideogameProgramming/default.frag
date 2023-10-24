#version 330 core
out vec4 FragColor;

in vec3 color;

in vec3 normals;
in vec2 uvs;
in vec3 vpos;

uniform sampler2D tex0;

uniform vec3 tint = vec3(1.0, 1.0, 1.0);

uniform vec3 lightDirection = vec3(-0.5, -1, -0.75);
uniform float ambient = 0.2;

void main()
{
    vec4 texColor = texture(tex0, uvs);
    //FragColor = vec4(texColor.r, texColor.g, texColor.b, texColor.a);

    float dotProduct = 1- dot(lightDirection, normals);

    dotProduct = clamp(dotProduct, 0, 1);

    vec4 directionalLight = vec4(dotProduct, dotProduct, dotProduct, 1);

    FragColor = texColor;

    FragColor = texColor * directionalLight;

    //FragColor = vec4((normals.x+1.)/2., (normals.y+1.)/2., (normals.z+1.)/2., 1.0f);
    //FragColor = vec4(uvs, 0.0f, 1.0f);

    if (vpos.y*10 - round(vpos.y*10) > 0.1) {
        FragColor = vec4(1, 1, 1, 1.0);
    }
    //FragColor = vec4(color, 1.0f);
}