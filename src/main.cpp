#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-window.GetWidth() / 2, window.GetWidth() / 2, -window.GetHeight() / 2, window.GetHeight() / 2);

    Quad quad1(glm::vec2(50, 50), glm::vec2(120, 120));
    Quad quad2(glm::vec2(-50, -100), glm::vec2(140, 140));

    quad1.AddComponent<Texture>();
    quad1.GetComponent<Texture>()->SetTexture("amogus.png");

    quad2.AddComponent<Texture>();
    quad2.GetComponent<Texture>()->SetColor(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f));

    while (!glfwWindowShouldClose(window.GetWindow()))
    {

        MainRenderer.clear();

        MainRenderer.render(quad1);
        MainRenderer.render(quad2);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
