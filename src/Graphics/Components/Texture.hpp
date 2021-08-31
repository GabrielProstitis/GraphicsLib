#pragma once
#include "Graphics/Objects/Object.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include <iostream>

class Texture : public Component
{
    Object* m_Object;
public:
    void Initialize(Object& obj)
    {

    }
	unsigned int TBO;
    void SetTexture(std::string textureName)
    {
		stbi_set_flip_vertically_on_load(1);
		int something;
		int width = 222;
		int height = 222;

        std::string Path = (std::string)__FILE__;
		std::string TexturesPath = Path.substr(0, Path.size() - 32) + (std::string)"\\Textures\\";

		
		unsigned char* bytes = stbi_load((TexturesPath + textureName).c_str(), &width, &height, &something, 4);
		
		if (bytes == nullptr)
		{
			LOGBREAK("Couldn't Find Image");
		}

		glGenTextures(1, &TBO);
		Vortex::Graphics::glBindTexture(GL_TEXTURE_2D, TBO);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
		Vortex::Graphics::glBindTexture(GL_TEXTURE_2D, 0);

		if (bytes)
			stbi_image_free(bytes);
    }

    void OnUpdate()
    {
    }
};
