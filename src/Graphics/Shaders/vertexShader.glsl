#version 330 core
layout (location = 0) in vec2 VerPos;
  
out vec4 frag_color;

void main()
{
    gl_Position = vec4(VerPos, 0.0, 1.0);
    frag_color = vec4(0.0, 0.0, 1.0, 1.0); 
}