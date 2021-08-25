#version 330 core
out vec4 Color;
  
in vec4 frag_color; // the input variable from the vertex shader (same name and same type)  

void main()
{
    Color = frag_color;
} 