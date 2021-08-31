#include "GraphicsLib.hpp"

int main(void)
{
    Window window(1080, 720, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(0, window.GetWidth(), 0, window.GetHeight());

    Quad paddle1(glm::vec2(50.0f, window.GetHeight() / 2), glm::vec2(20.0f, 200.0f));
    paddle1.AddComponent<Rigidbody>();
    paddle1.GetComponent<Rigidbody>()->SetGravity(0.0f, false);

    Quad paddle2(glm::vec2(window.GetWidth() - 50.0f, window.GetHeight() / 2), glm::vec2(20.0f, 200.0f));
    paddle2.AddComponent<Rigidbody>();
    paddle2.GetComponent<Rigidbody>()->SetGravity(0.0f, false);

    Circle ball(glm::vec2(window.GetWidth() / 2, window.GetHeight() / 2), 15.0f);
    ball.AddComponent<Rigidbody>();
    ball.GetComponent<Rigidbody>()->SetGravity(0.0f, false);

    while (!glfwWindowShouldClose(window.GetWindow()))
    {

        MainRenderer.clear();

        ball.GetComponent<Rigidbody>()->AddConstantForce(glm::vec3(0.5f, 0.7f, 0.0f));
        MainRenderer.render(paddle1);
        MainRenderer.render(paddle2);
        MainRenderer.render(ball);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
