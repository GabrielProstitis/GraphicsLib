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
        const char *src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == 0)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char *message = (char *)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << (std::string) "\n" + (std::string) "Failed to compile " + (std::string)(type == GL_VERTEX_SHADER ? "vertex" : "fragment" + (std::string) " shader");
            std::cout << (std::string) "\n" + (std::string) "error:" + (std::string)message;
            glDeleteShader(id);
            __debugbreak();
            return 0;
        }
        return id;
    }
    static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
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
    static unsigned int GetShaderFromFile(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
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
    //WARNING DO NOT EVER CHANGE THE PATH OF Shader.hpp and Shaders File
    //Getting shaders from src/Shaders
    Shader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
    {
        std::string rawPath = (std::string)__FILE__;         
        std::string currpath;
        if (*rawPath.substr((int)rawPath.size() - 11, 1).c_str() == '\\')
        {
            currpath =
                ((std::string)__FILE__).substr(0, ((std::string)__FILE__).find_last_of('\\') - 9) +
                "\\Shaders\\";
        }
        else
        {
            currpath =
                ((std::string)__FILE__).substr(0, ((std::string)__FILE__).find_last_of('/') - 9) +
                "/Shaders/";
        }

        
        std::cout << currpath << std::endl;
        

        shader = GetShaderFromFile(currpath + vertexShaderPath, currpath + fragmentShaderPath);
    };
    ~Shader()
    {
        glDeleteProgram(shader);
    }
    void SetMat4(glm::mat4 matrix, const std::string &refName)
    {
        glUniformMatrix4fv(glGetUniformLocation(shader, refName.c_str()), 1, false, &matrix[0][0]);
    }
    void UseShader()
    {
        glUseProgram(shader);
    }
    operator unsigned int() const noexcept
    {
        return shader;
    }
};
