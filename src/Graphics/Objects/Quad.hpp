#include "Object.hpp"

class Quad : public Object
{
private:
    uint32_t m_ID;

    glm::vec2 m_Position;
    glm::vec2 m_Scale;

    glm::vec4 m_Color;

    std::vector<Mesh> m_Mesh;

    glm::mat4 m_Model;
public:
    Quad(glm::vec2 position, glm::vec2 scale)
        : m_ID(0), m_Position(position), m_Scale(scale), m_Color(0)
    {
        m_Model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f));

        std::vector<float> data =
            {
               -scale.x/2.0f, -scale.y/2.0f,
                scale.x/2.0f, -scale.y/2.0f,
                scale.x/2.0f,  scale.y/2.0f,
               -scale.x/2.0f,  scale.y/2.0f};

        uint32_t vb;
        glGenBuffers(1, &vb);
        glBindBuffer(GL_ARRAY_BUFFER, vb);
        glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(float), &data[0], GL_STATIC_DRAW);

        uint32_t va = 0;
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

        std::vector<Mesh> pMesh;
        pMesh.emplace_back(data, indices, va, vb, ib);

        m_Mesh = pMesh;
    }

    uint32_t GetID() { return m_ID; }
    std::vector<Mesh> GetMesh() { return m_Mesh; }
    glm::vec2 GetPosition()
    {
        return m_Position;
    }
    glm::vec2 GetScale()
    {
        return m_Scale;
    }
    glm::mat4 GetModel()
    {
        return m_Model;
    }
};