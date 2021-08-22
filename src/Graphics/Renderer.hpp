#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <cstdint>

#include "Mesh.hpp"
#include "glm/glm.hpp"

using namespace Vortex::Graphics;

class Renderer
{

	/* not in use yet
private:
	glm::mat4 view;
	Renderer(glm::mat4 view) : view(view){ }*/

public:
	Renderer() {}

	void render(const std::vector<Mesh> &mesh)
	{
		for (auto it = mesh.begin(); it != mesh.end(); it++)
		{
			glBindVertexArray(it->m_Vao);
			glBindBuffer(GL_ARRAY_BUFFER, it->m_Vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, it->m_Ibo);
			glDrawElements(GL_TRIANGLES, it->m_Indices.size() * sizeof(uint32_t), GL_UNSIGNED_INT, 0);
		}
	}
};