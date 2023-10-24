#version 330 core
out vec4 FragColor;

in vec3 color;

in vec3 normals;
in vec2 uvs;
in vec3 vpos;

uniform sampler2D tex0;

uniform vec3 tint = vec3(1.0, 1.0, 1.0);

float sdCircle( in vec2 p, in float r ) 
{
    return length(p)-r;
}

float sdStar5(in vec2 p, in float r, in float rf)
{
    const vec2 k1 = vec2(0.809016994375, -0.587785252292);
    const vec2 k2 = vec2(-k1.x,k1.y);
    p.x = abs(p.x);
    p -= 2.0*max(dot(k1,p),0.0)*k1;
    p -= 2.0*max(dot(k2,p),0.0)*k2;
    p.x = abs(p.x);
    p.y -= r;
    vec2 ba = rf*vec2(-k1.y,k1.x) - vec2(0,1);
    float h = clamp( dot(p,ba)/dot(ba,ba), 0.0, r );
    return length(p-ba*h) * sign(p.y*ba.x-p.x*ba.y);
}

void main()
{
    //vec2 p = (2.0*vpos-vec2(400., 400.))/400.;
    
    float star = smoothstep(0.01, 0.05, sdStar5(vpos.xy, 0.6, 0.45));

    float circle = smoothstep(0.01, 0.05, sdCircle(vpos.xy + vec2(0.35, 0.45), 0.2));

    FragColor = vec4(circle*star, circle*star, circle*star, 1.0);
}
