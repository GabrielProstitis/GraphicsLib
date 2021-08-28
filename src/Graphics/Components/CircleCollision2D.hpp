#pragma once
#include "Graphics/Objects/Object.hpp"
#include "Graphics/Objects/Circle.hpp"
#include <iostream>
#include <vector>

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

	bool isColliding(CircleCollision2D &other)
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
		else
			return false;
	}

	bool isColliding(Object &other)
	{
		return false;
	}
	void OnUpdate(float deltaTime)
	{
	}
};
