#pragma once
#include "Graphics/Objects/Object.hpp"
#include <iostream>

class Rigidbody : public Component
{
    Object *m_Object;
    bool m_Gravity;

    float m_GravitySpeed;

    bool m_AirDrag;
    glm::vec3 m_Yspeed;

public:
    void Initialize(Object &obj)
    {
        m_Object = &obj;
        m_Gravity = true;
        m_GravitySpeed = 1.01f;
        m_AirDrag = 0.01f;
        m_Yspeed = glm::vec3(0.0f, -0.01f, 0.0f);
    }

    void SetGravity(float gravity, bool tf)
    {
        m_GravitySpeed = gravity;
        m_Gravity = tf;
    }

    void SetAirDrag(float drag)
    {
        m_AirDrag = drag;
    }

    void AddForce(glm::vec3 force)
    {
        m_Object->SetPosition(m_Object->GetPosition() + force);
    }

    void OnUpdate(float deltaTime)
    {
        if (m_Object->GetPosition().y >= -200.0f && m_Gravity) // Substitute this with collision stuff
        {
            m_Object->SetPosition(m_Object->GetPosition() + m_Yspeed * deltaTime);
            m_Yspeed *= m_GravitySpeed * m_AirDrag;
        }
        else
        {
            m_Yspeed = glm::vec3(0.0f, 0.0f, 0.0f);
        }
    }
};
