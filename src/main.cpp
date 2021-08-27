#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer;
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    Circle circ1(glm::vec2(0, 0), 100);
    Circle circ2(glm::vec2(0, 0), 50);
    circ1.AddComponent<CircleCollision2D>();
    circ2.AddComponent<CircleCollision2D>();

    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        MainRenderer.clear();

        if(circ2.GetComponent<CircleCollision2D>()->isColliding(*circ1.GetComponent<CircleCollision2D>()))
            std::cout << "\n" << "colliding";
        
        if(window.IsButtonDown(GLFW_KEY_W))
            circ2.SetPosition(circ2.GetPosition() + glm::vec3(0.00f, +0.5f, 0));
        if (window.IsButtonDown(GLFW_KEY_S))
            circ2.SetPosition(circ2.GetPosition() + glm::vec3(0.00f, -0.5f, 0));
        if (window.IsButtonDown(GLFW_KEY_A))
            circ2.SetPosition(circ2.GetPosition() + glm::vec3(-0.5f, 0, 0));
        if (window.IsButtonDown(GLFW_KEY_D))
            circ2.SetPosition(circ2.GetPosition() + glm::vec3(+0.5f, 0, 0));


        MainRenderer.render(circ1);
        MainRenderer.render(circ2);


        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
