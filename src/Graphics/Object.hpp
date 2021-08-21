#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "Mesh.hpp"
#include "glm/glm.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Object
{
protected:
    uint32_t m_ID;
    glm::vec2 position;
    glm::vec4 color;
    std::vector<Mesh> m_Mesh;

public:
    virtual uint32_t GetID() = 0;
};
