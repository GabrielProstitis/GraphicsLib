#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "Mesh.hpp"

#include <cstdint>

class Object
{
protected:
    uint32_t m_ID;
    Mesh m_Mesh;

public:
    virtual uint32_t GetID() = 0;
};
