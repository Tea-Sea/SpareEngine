#include "headers/Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Shader::Shader(std::string fragPath)
{
    fragPath = "assets/shaders/" + fragPath;
    std::string vertexPath = "assets/shaders/default.vert";

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
void Shader::setUniform(const GLchar* name, glm::mat4 matrix)
{
    const GLchar* uniform = genericToUniformName(name);
    if (uniform)
    {
        glUniformMatrix4fv(uniformLocations[uniform], 1, GL_FALSE, glm::value_ptr(matrix));
    }

}

// Vec2
void Shader::setUniform(const GLchar* name, glm::vec2 vector)
{
    const GLchar* uniform = genericToUniformName(name);
    if (uniform)
    {
        glUniform2f(uniformLocations[uniform], vector.x, vector.y);
    }
}

// Bool
void Shader::setUniform(const GLchar* name, bool value)
{
    const GLchar* uniform = genericToUniformName(name);
    if (uniform)
    {
        glUniform1i(uniformLocations[uniform], (int)value);
    }
}

// Int
void Shader::setUniform(const GLchar* name, int value)
{
    const GLchar* uniform = genericToUniformName(name);
    if (uniform)
    {
        glUniform1i(uniformLocations[uniform], value);
    }
}

// Float
void Shader::setUniform(const GLchar* name, float value)
{
    const GLchar* uniform = genericToUniformName(name);
    if(uniform)
    {
        glUniform1f(uniformLocations[uniform], value);
    }
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
        // std::cout << "Uniform " << i << ": " << name << ": " << length << ": " << size << ": " << type << std::endl;
        GLuint location = glGetUniformLocation(shader, name);
        uniforms.push_back(name);
        uniformLocations[name] = location;
    }
}

std::vector<std::string> Shader::getUniforms()
{
    return uniforms;
}


const GLchar* Shader::genericToUniformName(const GLchar* name)
{
    for (auto& [uniformName, loc] : uniformLocations)
    {
        std::string lower = toLowerCase(uniformName);
        if (lower.find(name) != std::string::npos)
        {
            return uniformName.c_str();
        }
    }
    // std::cerr << "Error: Could not find shader uniform: " << name << std::endl;
    return nullptr;
}

void Shader::bind()
{
    glUseProgram(shaderProgram);
}

void Shader::unbind()
{
    glUseProgram(0);
}
