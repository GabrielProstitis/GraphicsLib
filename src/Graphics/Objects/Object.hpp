#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "../Mesh.hpp"
#include "glm/glm.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Object
{
public:
    virtual uint32_t GetID() = 0;
    virtual std::vector<Mesh> GetMesh() = 0;
};
