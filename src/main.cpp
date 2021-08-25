#include "GraphicsLib.hpp"

int main(void)
{
    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Renderer MainRenderer("Quad/vertexShader.glsl", "Quad/fragmentShader.glsl");
    MainRenderer.setSpace(-(float)(window.GetWidth() / 2), window.GetWidth() / 2, -(float)(window.GetHeight() / 2), window.GetHeight() / 2);

    //Quad cube(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f));
    //cube.AddComponent<Collision2D>();
    //Quad quad1(glm::vec2(0.0f, 90.0f), glm::vec2(100.0f, 100.0f));
    //quad1.AddComponent<Collision2D>();
    
    
    Quad objecta(glm::vec2(-100, 0), glm::vec2(100, 200));
    std::cout << "\n 1st quad: " << " get mesh: " << &objecta.GetMesh()[0];

    Circle objectb(glm::vec2(0, 0), 100, glm::vec3(0.0f, 0.0f, 1.0f));
    std::cout << "\n 1st quad: "  << " get mesh: " << &objecta.GetMesh()[0];

    //std::cout << "\n 1st quad: " << rectb.GetMesh()[0].m_BufferData[0];


    glfwSwapInterval(0);



    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        MainRenderer.clear();


        MainRenderer.render(objecta);
        MainRenderer.render(objectb);

        if(window.IsButtonDown(GLFW_KEY_Z))
            std::cout << "\n z button pressed";

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
