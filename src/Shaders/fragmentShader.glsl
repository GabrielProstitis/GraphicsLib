#version 330 core

layout(location = 0) in vec4 gl_Color
in vec4 frag_color;

void main()
{
	gl_Color = frag_color;
}