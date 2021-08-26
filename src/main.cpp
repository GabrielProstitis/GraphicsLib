#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    Quad quad1(glm::vec2(100, 0), glm::vec2(100, 200), glm::vec3(1.0f, 0.0f, 1.0f));
    Quad quad2(glm::vec2(-100, 0), glm::vec2(50, 100), glm::vec3(1.0f, 0.0f, 0.0f));

    quad1.AddComponent<Collision2D>();
    quad2.AddComponent<Collision2D>();

    if (quad1.GetComponent<Collision2D>()->isColliding(*quad2.GetComponent<Collision2D>()))
    {
        std::cout << "yay" << std::endl;
    }

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
