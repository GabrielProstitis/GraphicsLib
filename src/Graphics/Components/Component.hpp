#pragma once
//this is included in Object.hpp
#include "Graphics/Objects/Object.hpp"

class Collision2D : public Component
{
public: 
	void Component::Initialize(Object& obj)
	{
		std::cout << "\ninitialized  Collision2D";
	}
};