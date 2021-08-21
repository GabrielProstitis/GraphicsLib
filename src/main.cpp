#include "Graphics/Mesh.hpp"
#include "Graphics/Object.hpp"
#include "Graphics/Renderer.hpp"
#include <iostream>
using namespace Vortex::Graphics;
#define print(x) std::cout << x;
int main(void)
{
    GLFWwindow *window;
    
    uint32_t s[] = {
        1
    };
    print(sizeof(s));
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!LoadOpenGLFunctions())
    {
        std::cout << "OpenGL functions not loaded" << std::endl;
        return -1;
    }

    std::vector<float> data =
    {
       -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f,  0.5f
    };

    GLuint vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, 2 * 3 * sizeof(GLfloat), data, GL_STATIC_DRAW);

    GLuint va = 0;
    glBindVertexArray(va);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

    GLuint indicies[] =
        {
            0, 1, 2};

    GLuint ib;
    glGenBuffers(1, &ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLuint), indicies, GL_STATIC_DRAW);

    Mesh triangle(data, indicies, 3, vb, va, ib);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, triangle.m_Count, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
