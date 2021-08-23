#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer("vertexShader.glsl", "fragmentShader.glsl");
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    Quad quad1(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
    quad1.AddComponent<Collision2D>();

    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        /* Render here */
        MainRenderer.clear();

        MainRenderer.render(quad1);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
