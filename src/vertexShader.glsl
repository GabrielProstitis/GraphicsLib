#version 330 core

layout(location = 0) out vec2 Position

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

uniform vec4 color;
out vec4 frag_color;

void main()
{
	gl_Position = vec4(Position, 0, 0);
	frag_color = color;
}