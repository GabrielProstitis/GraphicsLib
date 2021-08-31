#pragma once
#include "Object.hpp"
#include <string>

class Circle : public Object
{
private:
    uint32_t m_ID;

    glm::vec3 m_Position;

    glm::vec4 m_Color;

    float m_Radius;

public:
    Circle(glm::vec2 position, float radius, glm::vec4 color)
        : m_ID(0), m_Position(glm::vec3(position.x, position.y, 0)), m_Radius(radius)
    {

        std::vector<float> data;
        std::vector<uint32_t> indices;

#pragma region Creating Triangles and Pushing into data(variable)
        int steps = 30;
        float angle = 3.14159 * 2.0f / steps;

        float xPos = 0;
        float yPos = 0;
        float prevX = xPos;
        float prevY = yPos - radius;

        for (int i = 0; i <= steps; i++)
        {
            float newX = radius * sin(angle * i);
            float newY = -radius * cos(angle * i);

            data.push_back(0.0f);
            data.push_back(0.0f);
            data.push_back(prevX);
            data.push_back(prevY);
            data.push_back(newX);
            data.push_back(newY);

            prevX = newX;
            prevY = newY;
        }
#pragma endregion

        for (int j = 0; j < data.size(); j++)
            indices.push_back(j);

        uint32_t vb;
        glGenBuffers(1, &vb);
        glBindBuffer(GL_ARRAY_BUFFER, vb);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

        uint32_t va = 0;
        glGenVertexArrays(1, &va);
        glBindVertexArray(va);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

        uint32_t ib;
        glGenBuffers(1, &ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

        this->AddComponent<Mesh>();
        Mesh *result = (this->GetComponent<Mesh>());
        result->m_BufferData = data;
        result->m_Indices = indices;
        result->m_Vao = va;
        result->m_Vbo = vb;
        result->m_Ibo = ib;
    }

    Circle(glm::vec2 position, float radius, glm::vec3 color)
        : Circle(position, radius, glm::vec4(color, 1.f)) {}

    Circle(glm::vec2 position, float radius)
        : Circle(position, radius, glm::vec4(1.f, 1.f, 1.f, 1.f)) {}

    uint32_t GetID() { return m_ID; }

    glm::vec3 GetPosition()
    {
        return m_Position;
    }

    void SetPosition(glm::vec3 pos)
    {
        m_Position = pos;
    }

    float GetRadius()
    {
        return m_Radius;
    }
};