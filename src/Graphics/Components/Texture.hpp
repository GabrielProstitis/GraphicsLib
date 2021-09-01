#pragma once
#include "Graphics/Objects/Object.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

using namespace Vortex;

class Texture : public Component
{
	Object *m_Object;
	glm::vec4 m_Color;
	bool m_IsTexture;

public:
	unsigned int TBO;

	void Initialize(Object &obj)
	{
	}

	void SetIfTexture(bool tf)
	{
		m_IsTexture = tf;
	}

	void SetColor(glm::vec4 color)
	{
		m_Color = color;
		m_IsTexture = false;
	}

	void SetTexture(std::string textureName)
	{
		stbi_set_flip_vertically_on_load(1);
		int width;
		int height;
		std::string Path = (std::string)__FILE__;
		std::string TexturesPath = Path.substr(0, Path.size() - 32) + (std::string) "\\Textures\\";

		unsigned char *image = stbi_load((TexturesPath + textureName).c_str(), &width, &height, 0, 4);

		std::cout << std::endl
				  << width;

		if (image == nullptr)
		{
			LOGBREAK("Couldn't Find Image");
		}

		glGenTextures(1, &TBO);
		glActiveTexture(GL_TEXTURE0+TBO);
		Graphics::glBindTexture(GL_TEXTURE_2D, TBO);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		Graphics::glBindTexture(GL_TEXTURE_2D, 0);

		if (image)
		{
			stbi_image_free(image);
		}

		m_IsTexture = true;
	}

	void OnUpdate()
	{
	}

	void OnUpdate(Shader &shader)
	{
		if (m_IsTexture)
		{
			glActiveTexture(GL_TEXTURE0 + TBO);
			Graphics::glBindTexture(GL_TEXTURE_2D, TBO);
			shader.Set1i(TBO, "Texture");
			shader.SetVec4(glm::vec4(-1, 0, 0, 1), "Color"); //if x is -1 frag shader switch to render texture
		}
		else
			shader.SetVec4(m_Color, "Color");
	}
};
