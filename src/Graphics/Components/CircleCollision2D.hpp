#pragma once
#include "Graphics/Objects/Object.hpp"
#include "Graphics/Objects/Circle.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
class CircleCollision2D : public Component
{
	Object* object;

	float radius;

public:
	void Component::Initialize(Object& obj)
	{
		object = &obj;
		auto circleObj = dynamic_cast<Circle*>(&obj);
		radius = circleObj->GetRadius();

	}
	glm::vec3 GetPosition()
	{
		return object->GetPosition();
	}
	bool isColliding(CircleCollision2D& other)//Circle&Circle Collision
	{
		glm::vec3 otheredge = other.object->GetPosition();
		otheredge.x += other.radius;
		otheredge.y += other.radius;

		glm::vec3 edge = object->GetPosition();
		edge.x += this->radius;
		edge.y += this->radius;

		std::cout << "\n" << "x1: " << otheredge.x << " x2: " << edge.x << " result: " << other.object->GetPosition().x - this->object->GetPosition().x;
		float distanceX = this->object->GetPosition().x - other.object->GetPosition().x;
		float distanceY = this->object->GetPosition().y - other.object->GetPosition().y;
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		if (distance < other.radius + this->radius)
			return true;

		return false;
	}

	bool isColliding(QuadCollision2D& other)//Circle&Quad Collision
	{

		float distanceX = this->object->GetPosition().x - other.GetPosition().x;
		float distanceY = this->object->GetPosition().y - other.GetPosition().y;
		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);

		float HalfquadSizeY = other.GetPosition().y - other.PointMinList[0].y;
		float HalfquadSizeX = other.GetPosition().x - other.PointMinList[0].x;
		float quadRadius = sqrt(std::clamp(distanceX, -HalfquadSizeX, HalfquadSizeX) * std::clamp(distanceX, -HalfquadSizeX, HalfquadSizeX) + std::clamp(distanceY, -HalfquadSizeY, HalfquadSizeY) * std::clamp(distanceY, -HalfquadSizeY, HalfquadSizeY));

		if (distance <= quadRadius + this->radius)
			return true;
		return false;
	}
	void OnUpdate(float delta)
	{

	}
};
