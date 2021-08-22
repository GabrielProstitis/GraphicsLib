#pragma once
#include <sstream>
#include <fstream>
#include "GLFW/glfw3.h"

using namespace Vortex::Graphics;
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int(*CompileShader)(unsigned int, std::string) = [](unsigned int type, const std::string source) {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == 0)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << ((std::string)"Failed to compile" + (std::string)(type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
            std::cout << (std::string)"error:" + (std::string)message;
            glDeleteShader(id);
            return (unsigned int)0;
        }
        return id;
    };
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}
unsigned int GetShadersFromFile(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
    std::stringstream vertexShader_RAW;
    std::stringstream fragmentShader_RAW;
    std::string line;
    std::ifstream readVertexS(vertexShaderPath);
    while (std::getline(readVertexS, line))
    {
        vertexShader_RAW << line << "\n";
    }
    readVertexS.close();
    std::ifstream readFragmentS(fragmentShaderPath);
    while (std::getline(readFragmentS, line))
    {
        fragmentShader_RAW << line << "\n";
    }
    readFragmentS.close();
    if (vertexShader_RAW.str().size() == 0)
    {
        __debugbreak();
    }
    else if (fragmentShader_RAW.str().size() == 0)
    {
        __debugbreak();
    }
    return CreateShader(vertexShader_RAW.str(), fragmentShader_RAW.str());
}
inline unsigned int UseShader(unsigned int& Shader)
{
    glUseProgram(Shader);
}