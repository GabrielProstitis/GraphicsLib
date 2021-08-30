#include "GraphicsLib.hpp"
#include <chrono>

int main(void)
{
    Window window(1080, 720, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    Circle circ1(glm::vec2(520, 0), 20);
    circ1.AddComponent<Rigidbody>();
    circ1.AddComponent<CircleCollision2D>();
    //circ1.GetComponent<Rigidbody>()->AddForce(glm::vec3(-5.0f, 0.0f, 0.0f));
    circ1.GetComponent<Rigidbody>()->SetGravity(1.01f, true);

    Quad quad1(glm::vec2(-520, 0), glm::vec2(100, 50));
    quad1.AddComponent<Rigidbody>();
    quad1.AddComponent<QuadCollision2D>();
    //quad1.GetComponent<Rigidbody>()->AddForce(glm::vec3(5.0f, 0.0f, 0.0f));
    quad1.GetComponent<Rigidbody>()->SetGravity(1.01f, true);

    bool PrecPressed = false;
    bool isPressed = window.IsButtonDown(GLFW_KEY_SPACE);

    while (!glfwWindowShouldClose(window.GetWindow()))
    {

        MainRenderer.clear();

        if (circ1.GetComponent<CircleCollision2D>()->isColliding(*quad1.GetComponent<QuadCollision2D>()))
        {
            std::cout << "Circ1 colliding with quad1" << std::endl;
        }

        isPressed = window.IsButtonDown(GLFW_KEY_SPACE);
        if (isPressed == true && PrecPressed == false)
        {
            PrecPressed = true;
            quad1.GetComponent<Rigidbody>()->AddForce(glm::vec3(0.0f, 2.0f, 0.0f));
        }
        else if (isPressed == false)
        {
            PrecPressed = false;
        }

        std::cout << PrecPressed << std::endl;

        MainRenderer.render(circ1);
        MainRenderer.render(quad1);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
