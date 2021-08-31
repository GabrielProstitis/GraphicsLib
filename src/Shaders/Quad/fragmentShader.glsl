#version 330 core
out vec4 Color;
  
in vec4 frag_color; // the input variable from the vertex shader (same name and same type)  



in vec2 TexCoords;
uniform sampler2D Texture;

void main()
{
    if(true)
        Color = frag_color;
    else
        Color = texture(Texture, TexCoords);
} 