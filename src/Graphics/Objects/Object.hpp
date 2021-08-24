#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include "../Mesh.hpp"
#include "glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Object;
class Component
{
public:
    virtual void Initialize(Object& obj) = 0; 
};

class Object
{

public:
    virtual uint32_t GetID() = 0;
    virtual std::vector<Mesh> GetMesh() = 0;
    virtual glm::mat4 GetModel() = 0;



    #pragma region Components
private:
    std::vector<Component*> Components;

public:
    ~Object()
    {
        for (auto i = Components.begin(); i < Components.end(); i++)
        {
            delete[] *i;
            break;
        }
    }
    template<typename T>
    void AddComponent()
    {
        Components.push_back(new T());
        Components[Components.size()-1]->Initialize(*this);
    }

    template<typename T>
    T* GetComponent()
    {
        int ErrorMode = -1;
        if (Components.size() == 0)
        {
            LOGBREAK("No Any Components");
        }
        for (auto it = Components.begin(); it != Components.end(); it++)
        {
            auto Component = dynamic_cast<T*>(*it);
            if (Component != NULL)
                return Component;
        }
        if (ErrorMode == -1)
        {
            LOGBREAK("Couldnt Find The Component");

            return nullptr;
        }
    }

    template<typename T>
    void RemoveComponent()
    {
        for (auto it = Components.begin(); it != Components.end(); it++)
        {
            auto Component = dynamic_cast<T*>(*it);
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
