#include "GraphicsLib.hpp"
#include "Graphics/Renderer.hpp"
int main(void)
{

    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    std::vector<float> data =
        {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.0f, 0.5f};

    uint32_t vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, 2 * 3 * sizeof(float), &data[0], GL_STATIC_DRAW);

    uint32_t va = 0;
    glBindVertexArray(va);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    std::vector<uint32_t> indices =
        {0, 1, 2};

    uint32_t ib;
    glGenBuffers(1, &ib);
    std::cout << (ib);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

    Mesh Triangle(data, indices, va, vb, ib);

    Renderer MainRenderer;
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        MainRenderer.render(Triangle);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}