#pragma once
#include "Object.hpp"
#include <string>

class Quad : public Object
{
private:
    uint32_t m_ID;

    glm::vec3 m_Position;

    glm::vec2 m_Size;

    glm::vec4 m_Color;

public:
    Quad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
        : m_ID(0), m_Position(glm::vec3(position.x, position.y, 0)), m_Size(size), m_Color(color)
    {

        std::vector<float> data =
            {
                -size.x / 2.0f, -size.y / 2.0f,
                size.x / 2.0f, -size.y / 2.0f,
                size.x / 2.0f, size.y / 2.0f,
                -size.x / 2.0f, size.y / 2.0f};

        uint32_t vb;
        glGenBuffers(1, &vb);
        glBindBuffer(GL_ARRAY_BUFFER, vb);
        glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(float), &data[0], GL_STATIC_DRAW);

        uint32_t va = 0;
        glGenVertexArrays(1, &va);
        glBindVertexArray(va);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

        std::vector<uint32_t> indices =
            {
                0, 1, 2,
                2, 3, 0};

        uint32_t ib;
        glGenBuffers(1, &ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

        this->AddComponent<Mesh>();
        Mesh* result = (this->GetComponent<Mesh>());
        result->m_BufferData = data;
        result->m_Indices = indices;
        result->m_Vao = va;
        result->m_Vbo = vb;
        result->m_Ibo = ib;

    }

    Quad(glm::vec2 position, glm::vec2 size, glm::vec3 color)
        : Quad(position, size, glm::vec4(color.x, color.y, color.z, 1.0f)) {}
    Quad(glm::vec2 position, glm::vec2 size)
        : Quad(position, size, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)) {}

    uint32_t GetID() { return m_ID; }
    glm::vec3 GetPosition() { return m_Position; }
    void SetPosition(glm::vec3 pos) { m_Position = pos; }
    glm::vec2 GetSize() { return m_Size; }
    glm::vec4 GetColor() { return m_Color; }
    void SetColor(glm::vec4 color) { m_Color = color; }
};