#pragma once

#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdint>

class Window
{
private:
    GLFWwindow *m_Window;
    uint32_t m_Width;
    uint32_t m_Height;
    std::string m_Title;

public:
    Window(uint32_t width, uint32_t height, std::string title)
        : m_Width(width), m_Height(height), m_Title(title)
    {
        if (!glfwInit())
        {
            std::cout << "GLFW failed to init!" << std::endl;
        }

        m_Window = glfwCreateWindow(width, height, m_Title.c_str(), NULL, NULL);
    }

    GLFWwindow *GetWindow() { return m_Window; }
    uint32_t GetWidth() { return m_Width; }
    uint32_t GetHeight() { return m_Height; }
    std::string GetTitle() { return m_Title; }
};