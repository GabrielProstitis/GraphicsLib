#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <cstdint>
#include "Objects/Object.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

using namespace Vortex::Graphics;

class Renderer
{
private:
	glm::mat4 m_Proj;
	Shader m_Shader;
public:
	Renderer(const std::string& VertexShader, const std::string& FragmentShader) 
		: m_Shader(VertexShader, FragmentShader) {
		m_Shader.UseShader();
	}
	void clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void setSpace(float x_min, float x_max, float y_min, float y_max)
	{
		m_Proj = glm::ortho(x_min, x_max, y_min, y_max, -1.0f, 1.0f);
	}
	void render(const Mesh& mesh) const
	{
		glBindVertexArray(mesh.m_Vao);
		glBindBuffer(GL_ARRAY_BUFFER, mesh.m_Vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.m_Ibo);
		glDrawElements(GL_TRIANGLES, mesh.m_Indices.size() * sizeof(uint32_t), GL_UNSIGNED_INT, 0);
	}
	void render(Object& object) 
	{
		m_Shader.SetMat4(m_Proj * object.GetModel(), "u_MVP");

		std::vector<Mesh> mesh = object.GetMesh();
		for (auto it = mesh.begin(); it != mesh.end(); it++)
			render(*it);
	}
};
