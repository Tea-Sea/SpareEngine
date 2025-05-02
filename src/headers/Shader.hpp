#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "../utils/String.hpp"

class Shader {

public:
    Shader(std::string vertexPath);

    Shader(std::string vertexPath, std::string fragPath);

    ~Shader();

    std::string loadShaderFromSrc(std::string src);

    GLuint compileShader(GLenum shaderType, std::string source);

    GLuint createShaderProgram(GLuint vertexSrc, GLuint fragmentSrc);

    GLuint getShaderProgram();

    void setUniform(GLchar* name, glm::mat4 matrix);

    void setUniform(GLchar* name, glm::vec2 vector);

    void setUniform(GLchar* name, bool value);

    void setUniform(GLchar* name, int value);

    void setUniform(GLchar* name, float value);

    void cacheUniformLocations(const GLuint& shader);

    std::vector<std::string> getUniforms();

    const GLchar* genericToUniformName(const GLchar* name);

    void bind();

    void unbind();


private:
    GLuint vertexShader;

    GLuint fragShader;

    GLuint shaderProgram;

    std::vector<std::string> uniforms;

    std::unordered_map<std::string, GLint> uniformLocations;

};