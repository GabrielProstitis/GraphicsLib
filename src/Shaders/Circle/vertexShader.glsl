#version 330 core

layout (location = 0) in vec3 VerPos;
out vec4 frag_color;

void main()
{//Must render circle here
    gl_Position = vec4(VerPos, 1.0);
	frag_color = vec4(0.0, 0.0, 1.0, 1.0); 
}