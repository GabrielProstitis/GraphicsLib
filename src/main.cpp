#include "GraphicsLib.hpp"

int main(void)
{

    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    float data[] =
        {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.0f, 0.5f};

    uint32_t vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, 2 * 3 * sizeof(float), data, GL_STATIC_DRAW);

    uint32_t va = 0;
    glBindVertexArray(va);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    uint32_t indicies[] =
        {
            0, 1, 2};

    uint32_t ib;
    glGenBuffers(1, &ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(uint32_t), indicies, GL_STATIC_DRAW);

    Mesh triangle(data, indicies, 3, vb, va, ib);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, triangle.m_Count, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}