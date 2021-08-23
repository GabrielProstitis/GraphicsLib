#pragma once
//this is included in Object.hpp
#include "Graphics/Objects/Object.hpp"

class Collision2D : public Component
{
public: 
	void Component::Initialize(Object& obj)
	{
		std::cout << "initialized  Collision2D";
	}
	bool isColliding(Mesh othermesh)
	{

	}
};

class testcomponent : public Component
{
public:
	void Initialize(Object& obj)
	{

	}
	int isworking = 23;
};


