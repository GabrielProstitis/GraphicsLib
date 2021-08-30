#pragma once
#include "Graphics/Objects/Object.hpp"
#include "Graphics/Objects/Circle.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
class CircleCollision2D : public Component
{
	Object *object;

	float radius;

public:
	void Component::Initialize(Object &obj)
	{
		object = &obj;
		auto circleObj = dynamic_cast<Circle *>(&obj);
		radius = circleObj->GetRadius();
	}
	glm::vec3 GetPosition()
	{
		return object->GetPosition();
	}
	bool isColliding(CircleCollision2D &other) //Circle&Circle Collision
	{
		glm::vec3 otheredge = other.object->GetPosition();
		otheredge.x += other.radius;
		otheredge.y += other.radius;

		glm::vec3 edge = object->GetPosition();
		edge.x += this->radius;
		edge.y += this->radius;

		std::cout << "\n"
				  << "x1: " << otheredge.x << " x2: " << edge.x << " result: " << other.object->GetPosition().x - this->object->GetPosition().x;
		float distanceX = this->object->GetPosition().x - other.object->GetPosition().x;
		float distanceY = this->object->GetPosition().y - other.object->GetPosition().y;
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		if (distance < other.radius + this->radius)
			return true;

		return false;
	}

	bool isColliding(Circle &other)
	{
		if (other.GetComponent<CircleCollision2D>() != nullptr)
		{
			glm::vec3 otheredge = other.GetPosition();
			otheredge.x += other.GetComponent<CircleCollision2D>()->radius;
			otheredge.y += other.GetComponent<CircleCollision2D>()->radius;

			glm::vec3 edge = object->GetPosition();
			edge.x += this->radius;
			edge.y += this->radius;

			std::cout << "\n"
					  << "x1: " << otheredge.x << " x2: " << edge.x << " result: " << object->GetPosition().x - this->object->GetPosition().x;
			float distanceX = this->object->GetPosition().x - other.GetPosition().x;
			float distanceY = this->object->GetPosition().y - other.GetPosition().y;
			float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

			if (distance < other.GetComponent<CircleCollision2D>()->radius + this->radius)
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}

	bool isColliding(QuadCollision2D &other) //Circle&Quad Collision
	{

		float distanceX = this->object->GetPosition().x - other.GetPosition().x;
		float distanceY = this->object->GetPosition().y - other.GetPosition().y;
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		float HalfquadSizeX = other.GetSize().x / 2;
		float HalfquadSizeY = other.GetSize().y / 2;
		float quadRadius = sqrt(std::clamp(distanceX, -HalfquadSizeX, HalfquadSizeX) * std::clamp(distanceX, -HalfquadSizeX, HalfquadSizeX) + std::clamp(distanceY, -HalfquadSizeY, HalfquadSizeY) * std::clamp(distanceY, -HalfquadSizeY, HalfquadSizeY));

		std::cout << "Quad radius        " << quadRadius << std::endl;
		std::cout << "Circle radius        " << this->radius << std::endl;

		if (distance <= quadRadius + this->radius)
			return true;

		return false;
	}

	void OnUpdate()
	{
	}
};
