#pragma once

#include "Window.hpp"

using namespace Vortex::Graphics;

int InitGraphics(Window window)
{
    if (!window.GetWindow())
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window.GetWindow());
    glfwSwapInterval(0);
    if (!LoadOpenGLFunctions())
    {
        std::cout << "OpenGL functions not loaded" << std::endl;
        return -1;
    }
}