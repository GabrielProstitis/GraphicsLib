#version 330 core
layout (location = 0) in vec2 VerPos;

uniform mat4 u_MVP;
uniform vec4 Color;

out vec4 frag_color;
out vec2 TexCoords;
void main()
{
    gl_Position = u_MVP*vec4(VerPos, 0.0, 1.0);
    TexCoords = VerPos;

    frag_color = Color; 
}