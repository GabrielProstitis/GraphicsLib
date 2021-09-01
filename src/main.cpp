#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-window.GetWidth() / 2, window.GetWidth() / 2, -window.GetHeight() / 2, window.GetHeight() / 2);

    Quad quad1(glm::vec2(0, 0), glm::vec2(100, 100));
    quad1.AddComponent<Texture>()->SetTexture("cubemix.png");

    Quad quad2(glm::vec2(-150, 0), glm::vec2(100, 100));
    quad2.AddComponent<Texture>()->SetTexture("cubeblue.png");

    Quad quad3(glm::vec2( 150, 0), glm::vec2(100, 100));
    quad3.AddComponent<Texture>()->SetTexture("amogus.png");



    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        MainRenderer.clear();

        MainRenderer.render(quad1);

        MainRenderer.render(quad2);

        MainRenderer.render(quad3);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
