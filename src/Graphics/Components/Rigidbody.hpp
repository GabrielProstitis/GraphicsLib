#pragma once
#include "Graphics/Objects/Object.hpp"
#include <iostream>

class Rigidbody : public Component
{
    Object *m_Object;
    bool m_Gravity;
    float m_GravitySpeed;
    float m_GravityVelocity;
    float m_AirDrag;
    glm::vec3 m_speed;

    u_int m_Count;

public:
    void Initialize(Object &obj)
    {
        m_Object = &obj;

        m_Gravity = true;
        m_GravitySpeed = 1.01f;
        m_GravityVelocity = -0.001f;

        m_AirDrag = 1.006f;
        m_speed = glm::vec3(0.0f, 0.00001f, 0.0f);
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
        if (force.y > 0)
        {
            m_GravityVelocity = -0.001f;
        }
        m_speed += force;
    }
    void AddConstantForce(glm::vec3 force)
    {
        m_speed = force;
    }
    glm::vec3 GetSpeed()
    {
        return m_speed;
    }

    void OnUpdate()
    {
        if (m_Gravity == true)
        {
            m_GravityVelocity *= m_GravitySpeed;
            m_speed.y += m_GravityVelocity;
        }
        m_speed /= m_AirDrag;

        m_Object->SetPosition(m_Object->GetPosition() + m_speed);

        if (m_speed.x <= 0.001 && m_speed.x >= -0.001)
        {
            m_speed.x = 0;
        }
    }

    void OnUpdate(Shader &shader)
    {
    }
};
