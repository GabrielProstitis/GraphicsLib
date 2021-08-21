#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>
#include <vector>

#include <cstdint>

struct Mesh
{
    std::vector<float> m_BufferData;
    std::vector<uint32_t> m_Indices;
    uint32_t m_Vao;
    uint32_t m_Vbo;
    uint32_t m_Ibo;

    Mesh()
        : m_Vao(0), m_Vbo(0), m_Ibo(0) {}

    Mesh(const std::vector<float> &bufferData, const std::vector<uint32_t> &indices, uint32_t vao, uint32_t vbo, uint32_t ibo)
        : m_BufferData(bufferData), m_Indices(indices), m_Vao(vao), m_Vbo(vbo), m_Ibo(ibo) {}
};