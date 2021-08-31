#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-window.GetWidth() / 2, window.GetWidth() / 2, -window.GetHeight() / 2, window.GetHeight() / 2);

    Quad quad1(glm::vec2(0, 0), glm::vec2(120, 120), glm::vec3(1, 0, 0));
    Quad quad2(glm::vec2(0, 0), glm::vec2(140, 140), glm::vec3(1, 0, 0));
    quad1.AddComponent<Texture>();
    quad1.GetComponent<Texture>()->SetTexture("circle.png");

    while (!glfwWindowShouldClose(window.GetWindow()))
    {

        MainRenderer.clear();

        MainRenderer.render(quad2);
        MainRenderer.render(quad1);
        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
