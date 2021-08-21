#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "glm/glm/glm.hpp"

#include <cstdint>
#include "glm/glm.hpp"
using namespace Vortex::Graphics;
class Renderer
{

	/* not in use yet
public:
	glm::mat4 view;
	Renderer(glm::mat4 view) : view(view){ }*/
public:
	Renderer() {}
	void RenderMesh(const Mesh& mesh)
	{
		glBindVertexArray(mesh.m_Vao);
		glBindBuffer(GL_ARRAY_BUFFER, mesh.m_Vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.m_Ibo);

		glDrawElements(GL_TRIANGLES, 222, GL_UNSIGNED_INT, nullptr);
	}

};