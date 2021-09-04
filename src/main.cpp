#include "GraphicsLib.hpp"

int main(void)
{
    Window window(1080, 720, "Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(0, window.GetWidth(), 0, window.GetHeight());

    Quad quad1(glm::vec2(50, 100), glm::vec2(50, 50));
    quad1.AddComponent<Texture>()->SetTexture("circle.png");

    Quad quad2(glm::vec2(50, 100), glm::vec2(60, 60));
    quad2.AddComponent<Texture>()->SetColor(glm::vec4(0, 1, 0, 1));

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