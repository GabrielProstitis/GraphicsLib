#pragma once
#include "Graphics/Objects/Object.hpp"
#include <iostream>
#include <vector>

class QuadCollision2D : public Component
{
	Object *object;

	std::vector<glm::vec2> PointMaxList; //Per Mesh point
	std::vector<glm::vec2> PointMinList; //Per Mesh point

public:
	void Component::Initialize(Object &obj)
	{
		//std::cout << "\ninitialized  Collision2D";

		object = &obj;

		glm::vec2 PointMax(0, 0);
		glm::vec2 PointMin(0, 0);

		Mesh *mesh = obj.GetComponent<Mesh>();

		for (int j = 0; j < mesh->m_BufferData.size(); j += 2)
		{
			if (PointMax.x < mesh->m_BufferData[j])
				PointMax.x = mesh->m_BufferData[j];
			if (PointMax.y < mesh->m_BufferData[j + 1])
				PointMax.y = mesh->m_BufferData[j + 1];

			if (PointMin.x > mesh->m_BufferData[j])
				PointMin.x = mesh->m_BufferData[j];
			if (PointMin.y > mesh->m_BufferData[j + 1])
				PointMin.y = mesh->m_BufferData[j + 1];
			/*
			std::cout << "  \n"
					  << "x: " << mesh->m_BufferData[j] << " y: " << mesh->m_BufferData[j + 1];
			*/
		}
		/*object->GetModel()[3][0];
		object->GetModel()[3][1];
		object->GetModel()[3][0];
		object->GetModel()[3][1];*/

		PointMax.x += object->GetPosition().x;
		PointMax.y += object->GetPosition().y;
		PointMin.x += object->GetPosition().x;
		PointMin.y += object->GetPosition().y;

		/*
		std::cout << "\n"
				  << "PointMax: " << PointMax.x << " PointMin: " << PointMax.y;
		std::cout << "\n"
				  << "PointMin: " << PointMin.x << " PointMin: " << PointMin.y;
		*/

		PointMaxList.push_back(PointMax);
		PointMinList.push_back(PointMin);
	}
	//For now working with only quad Collision Detection
	bool isColliding(QuadCollision2D &other)
	{
		auto Vertices = other.object->GetComponent<Mesh>()->m_BufferData;
		for (int j = 0; j < Vertices.size(); j += 2)
		{
			Vertices[j] += other.object->GetPosition().x;
			Vertices[j + 1] += other.object->GetPosition().y;
			if ((Vertices[j] <= PointMaxList[0].x && Vertices[j + 1] <= PointMaxList[0].y) &&
				(Vertices[j] >= PointMinList[0].x && Vertices[j + 1] >= PointMinList[0].y))
			{
				return true;
			}
		}

		return false;
	}

	bool isColliding(Object &other)
	{
		if (other.GetComponent<QuadCollision2D>() != nullptr)
		{
			LOGWARNING("No Collision2D found");
			return false;
		}

		auto Vertices = other.GetComponent<Mesh>()->m_BufferData;
		for (int j = 0; j < Vertices.size(); j += 2)
		{
			Vertices[j] += other.GetPosition().x;
			Vertices[j + 1] += other.GetPosition().y;
			if ((Vertices[j] <= PointMaxList[0].x && Vertices[j + 1] <= PointMaxList[0].y) &&
				(Vertices[j] >= PointMinList[0].x && Vertices[j + 1] >= PointMinList[0].y))
			{
				return true;
			}
		}

		return false;
	}
	void OnUpdate(float deltaTime)
	{
	}
};
