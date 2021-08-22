#pragma once
#include <sstream>
#include <fstream>
#include "GLFW/glfw3.h"

using namespace Vortex::Graphics;
class Shader
{
private: 
    unsigned int shader;
    static unsigned int CompileShader(unsigned int type, const std::string source)
    {
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
            std::cout << (std::string)"Failed to compile" + (std::string)(type == GL_VERTEX_SHADER ? "vertex" : "fragment");
            std::cout << (std::string)"error:" + (std::string)message;
            glDeleteShader(id);
            return 0;
        }
        return id;
    }
    static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {

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
    static unsigned int GetShaderFromFile(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
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
public:
    
    Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
        shader = GetShaderFromFile(vertexShaderPath, fragmentShaderPath);
    };
    ~Shader()
    {
        glDeleteProgram(shader);
    }
    void UseShader()
    {
        glUseProgram(shader);
    }
    unsigned int GetShader() const
    {
        return shader;
    }
};