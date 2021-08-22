#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <cstdint>
#include "Objects/Object.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

using namespace Vortex::Graphics;

class Renderer
{

	/* not in use yet
private:
	glm::mat4 view;
	Renderer(glm::mat4 view) : view(view){ }*/
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
	void setSpace(float x, float y)
	{
		m_Proj = glm::ortho(0.0f, x, 0.0f, y, -1.0f, 1.0f);
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
		auto GetMatrix = [](glm::mat4 matrix) {
			std::string result;
			for (int j = 0; j < 4; j++)
			{
				result += ("|");
				for (int x = 0; x < 4; x++)
					result += std::to_string(matrix[j][x]) + (std::string)" ";
				result += ("|\n");
			}
			return result;
		};

		Object* objeca = &object;
		auto mesh = (*objeca).GetMesh();
		std::cout << GetMatrix((*objeca).GetModel()) << "\n";
		glm::mat4 u_MP = m_Proj * (*objeca).GetModel();
		m_Shader.SetMat4(u_MP, "u_MVP");

		for (auto it = mesh.begin(); it != mesh.end(); it++)
			render(*it);
	}
};
