#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Object;

class Component
{
public:
    virtual void Initialize(Object &obj) = 0;
    virtual void OnUpdate() = 0;
    virtual void OnUpdate(Shader &shader) = 0;
};

class Object
{

public:
    virtual uint32_t GetID() = 0;
    virtual void SetPosition(glm::vec3 pos) = 0;
    virtual glm::vec3 GetPosition() = 0;

#pragma region Components
private:
    std::vector<Component *> Components;

public:
    ~Object()
    {
        for (auto i = Components.begin(); i < Components.end(); i++)
        {
            delete[] * i;
            break;
        }
    }

    template <typename T>
    T *AddComponent()
    {
        Components.push_back(new T());
        Components[Components.size() - 1]->Initialize(*this);
        return dynamic_cast<T *>(Components[Components.size() - 1]);
    }

    template <typename T>
    T *GetComponent()
    {
        int ErrorMode = -1;

        if (Components.size() == 0)
        {
            return nullptr;
        }

        for (auto it = Components.begin(); it != Components.end(); it++)
        {
            auto Component = dynamic_cast<T *>(*it);
            if (Component != NULL)
            {
                return Component;
            }
        }

        return nullptr;
    }
    template <typename T>
    std::vector<T *> GetComponents()
    {
        std::vector<T *> result;
        int ErrorMode = -1;

        if (Components.size() == 0)
        {
            return result;
        }

        for (auto it = Components.begin(); it != Components.end(); it++)
        {
            auto Component = dynamic_cast<T *>(*it);
            if (Component != NULL)
            {
                result.push_back(Component);
            }
        }

        return result;
    }

    std::vector<Component *> GetComponents()
    {
        std::vector<Component *> result;
        int ErrorMode = -1;

        if (Components.size() == 0)
            return result;

        for (auto it = Components.begin(); it != Components.end(); it++)
            result.push_back(*it);

        return result;
    }

    template <typename T>
    void RemoveComponent()
    {
        for (auto it = Components.begin(); it != Components.end(); it++)
        {
            auto Component = dynamic_cast<T *>(*it);
            if (Component != NULL)
            {
                delete[] Component;
                Components.erase(it, it + 1);
                break;
            }
        }
    }
#pragma endregion
};
