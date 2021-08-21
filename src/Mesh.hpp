#include <OpenGL.hpp>
#include <GLFW/glfw3.h>

struct Mesh
{
    float *m_BufferData;
    unsigned int *m_Indices;
    unsigned int m_Count;
    unsigned int m_Vao;
    unsigned int m_Vbo;
    unsigned int m_Ibo;

    Mesh()
        : m_Count(0), m_Vao(0), m_Vbo(0), m_Ibo(0) {}

    Mesh(float bufferData[], unsigned int indicies[], unsigned int count, unsigned int vao, unsigned int vbo, unsigned int ibo)
        : m_BufferData(bufferData), m_Indices(indicies), m_Count(count), m_Vao(vao), m_Vbo(vbo), m_Ibo(ibo) {}
};