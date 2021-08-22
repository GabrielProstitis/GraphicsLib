#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer("vertexShader.glsl", "fragmentShader.glsl");
    MainRenderer.setSpace(window.GetWidth(), window.GetHeight());

    Quad quad1(glm::vec2(200.0f,200.0f), glm::vec2(120.0f, 120.0f));

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
