#include "GraphicsLib.hpp"
#include <chrono>

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    Circle circ1(glm::vec2(0, 0), 20);
    circ1.AddComponent<Rigidbody>();

    std::chrono::high_resolution_clock timer;
    float deltaTime = FLT_MIN;
    auto start = timer.now();
    auto stop = timer.now();

    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        auto start = stop;

        MainRenderer.clear();

        circ1.GetComponent<Rigidbody>()->AddForce(glm::vec3(0.1f, 0.0f, 0.0f) * deltaTime);
        MainRenderer.render(circ1, deltaTime);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();

        stop = timer.now();

        deltaTime = std::chrono::duration<float, std::milli>(stop - start).count();
        std::cout << deltaTime << std::endl;
    }

    glfwTerminate();
    return 0;
}
