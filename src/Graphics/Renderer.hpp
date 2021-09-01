#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <cstdint>
#include "Objects/Object.hpp"
#include "Components/Rigidbody.hpp"
#include "Shader.hpp"

glm::mat4 m_Proj;
glm::mat4 m_Model;

using namespace Vortex::Graphics;

class Renderer
{
private:
	Shader m_Shader;

public:
	Renderer(const std::string &VertexShader, const std::string &FragmentShader)
		: m_Shader(VertexShader, FragmentShader)
	{
		m_Shader.UseShader();
	}

	Renderer()
		: m_Shader("Quad\\vertexShader.glsl", "Quad\\fragmentShader.glsl")
	{
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
	void render(const Mesh &mesh)
	{
		glBindVertexArray(mesh.m_Vao);
		glBindBuffer(GL_ARRAY_BUFFER, mesh.m_Vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.m_Ibo);
		glDrawElements(GL_TRIANGLES, mesh.m_Indices.size() * sizeof(uint32_t), GL_UNSIGNED_INT, 0);
	}

	void render(Object &object)
	{
		m_Model = glm::translate(glm::mat4(1.0f), glm::vec3(object.GetPosition().x, object.GetPosition().y, 0.0f));
		m_Shader.SetMat4(m_Proj * m_Model, "u_MVP");

		
		m_Shader.SetVec4(glm::vec4(1, 1, 1, 1), "Color");
		std::vector<Component*> ComponentList = object.GetComponents();
		for (auto it = ComponentList.begin(); it != ComponentList.end(); it++)
		{
			(*it)->OnUpdate(m_Shader);
			(*it)->OnUpdate();
		}

		std::vector<Mesh*> meshes = object.GetComponents<Mesh>();
		for (auto it = meshes.begin(); it != meshes.end(); it++)
			render(**it);
	}
};