#version 330 core
layout (location = 0) in vec2 VerPos;

uniform mat4 u_MVP;
uniform vec4 Color;
uniform vec2 texScale;


out vec4 frag_color;
out vec2 TexCoords;

vec2 TexCoordsVer[6] = vec2[6]
( 
vec2(0.5f, -0.5f), vec2(-0.5f, -0.5f), vec2(-0.5f, 0.5f),
vec2(0.5f, 0.5f), vec2(-0.5f, -0.5f), vec2(-0.5f, 0.5f)
);
void main()
{
    gl_Position = u_MVP*vec4(VerPos, 0.0, 1.0);

    int vertexID = gl_VertexID;//Draft for 

    TexCoords = (TexCoordsVer[vertexID]/vec2(-texScale.x, texScale.y)) + vec2(0.5f, 0.5f);

    frag_color = Color; 
}