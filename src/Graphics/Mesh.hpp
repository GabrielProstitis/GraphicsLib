#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include <cstdint>

struct Mesh
{
    float *m_BufferData;
    uint32_t *m_Indices;
    uint32_t m_Count;
    uint32_t m_Vao;
    uint32_t m_Vbo;
    uint32_t m_Ibo;

    Mesh()
        : m_Count(0), m_Vao(0), m_Vbo(0), m_Ibo(0) {}

    Mesh(float bufferData[], uint32_t indicies[], uint32_t count, uint32_t vao, uint32_t vbo, uint32_t ibo)
        : m_BufferData(bufferData), m_Indices(indicies), m_Count(count), m_Vao(vao), m_Vbo(vbo), m_Ibo(ibo) {}
};