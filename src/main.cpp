#include "GraphicsLib.hpp"

int main(void)
{

    Window window(640, 480, "Graphics Lib Test");
    InitGraphics(window);

    Quad quad1(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f, 0.5f));
    
    unsigned int shader = GetShaderFromFile("githubfiles/src/Graphics/Shaders/vertexShader.glsl", "githubfiles/src/Graphics/Shaders/fragmentShader.glsl");
    glUseProgram(shader);
    Renderer MainRenderer;
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        MainRenderer.render(quad1.GetMesh());

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}