#pragma once
#include "Graphics/Objects/Object.hpp"
#include <iostream>
#include <vector>

class Mesh : public Component
{
private:
	Object *object;

public:
	std::vector<float> m_BufferData;
	std::vector<uint32_t> m_Indices;
	uint32_t m_Vao;
	uint32_t m_Vbo;
	uint32_t m_Ibo;

	void Component::Initialize(Object &obj)
	{
		object = &obj;
	}
	void OnUpdate()
	{
	}
};
