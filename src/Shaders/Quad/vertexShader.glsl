#version 330 core
layout (location = 0) in vec2 VerPos;

uniform mat4 u_MVP;
uniform vec4 Color;

out vec4 frag_color;

void main()
{
    gl_Position = u_MVP*vec4(VerPos, 0.0, 1.0);
    frag_color = Color; 
}