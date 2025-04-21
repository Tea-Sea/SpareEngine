#include "headers/Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Shader::Shader(std::string fragPath)
{
    fragPath = "assets/shaders/" + fragPath;
    std::string vertexPath = "assets/shaders/vertex.glsl";

    vertexShader = compileShader(GL_VERTEX_SHADER, loadShaderFromSrc(vertexPath));
    fragShader = compileShader(GL_FRAGMENT_SHADER, loadShaderFromSrc(fragPath));

    shaderProgram = createShaderProgram(vertexShader, fragShader);

    // Clean up shaders after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    cacheUniformLocations(shaderProgram);
}

Shader::Shader(std::string vertexPath, std::string fragPath)
{

    fragPath = "assets/shaders/" + fragPath;
    vertexPath = "assets/shaders/" + vertexPath;

    vertexShader = compileShader(GL_VERTEX_SHADER, loadShaderFromSrc(vertexPath));
    fragShader = compileShader(GL_FRAGMENT_SHADER, loadShaderFromSrc(fragPath));

    shaderProgram = createShaderProgram(vertexShader, fragShader);

    // Clean up shaders after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    cacheUniformLocations(shaderProgram);
}

Shader::~Shader()
{

}

std::string Shader::loadShaderFromSrc(std::string src)
{

    std::ifstream shaderSrc(src);

    if (!shaderSrc) {
        std::cerr << "Error reading shader file: " << src << std::endl;
    }

    std::stringstream strBuffer;

    strBuffer << shaderSrc.rdbuf();
    shaderSrc.close();

    return strBuffer.str();
}


GLuint Shader::compileShader(GLenum shaderType, std::string src)
{
    const char *c_str = src.c_str();
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &c_str, nullptr);
    glCompileShader(shader);

    // Check for compile errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    return shader;
}

GLuint Shader::createShaderProgram(GLuint vert, GLuint frag)
{
    GLuint program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    // Check for linking errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Shader Linking Failed:\n" << infoLog << std::endl;
    }

    return program;
}

GLuint Shader::getShaderProgram()
{
    return shaderProgram;
}

// Mat4
void Shader::setUniform(GLchar* name, glm::mat4 matrix)
{
    glUniformMatrix4fv(uniformLocations[hasGenericUniform(name)], 1, GL_FALSE, glm::value_ptr(matrix));

}

// Vec2
void Shader::setUniform(GLchar* name, glm::vec2 vector)
{
    glUniform2f(uniformLocations[hasGenericUniform(name)], vector.x, vector.y);

}

// Bool
void Shader::setUniform(GLchar* name, bool value)
{
    glUniform1i(uniformLocations[hasGenericUniform(name)], (int)value);

}

// Int
void Shader::setUniform(GLchar* name, int value)
{
    glUniform1i(uniformLocations[hasGenericUniform(name)], value);

}

// Float
void Shader::setUniform(GLchar* name, float value)
{
    glUniform1f(uniformLocations[hasGenericUniform(name)], value);
}

void Shader::cacheUniformLocations(const GLuint& shader)
{
    int numUniforms = 0;
    glGetProgramiv(shader, GL_ACTIVE_UNIFORMS, &numUniforms);

    for (int i = 0; i < numUniforms; ++i) {
        char name[256];
        GLsizei length;
        GLint size;
        GLenum type;

        glGetActiveUniform(shader, i, sizeof(name), &length, &size, &type, name);
        std::cout << "Uniform " << i << ": " << name << ": " << length << ": " << size << ": " << type << std::endl;
        GLuint location = glGetUniformLocation(shader, name);
        uniformLocations[name] = location;
    }
}

const GLchar* Shader::hasGenericUniform(GLchar* name) const
{
    for (auto& [uniformName, loc] : uniformLocations)
    {
        std::string lower = toLowerCase(uniformName);
        if (lower.find(name) != std::string::npos)
        {
          return uniformName.c_str();
        }
    }
    std::cerr << "Error: Could not find shader uniform: " << name << std::endl;
    return 0;
}


void Shader::bind()
{
    glUseProgram(shaderProgram);
}

void Shader::unbind()
{
    glUseProgram(0);
}
