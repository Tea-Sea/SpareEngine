#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp> 
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

class Shader {

public:
    Shader(std::string path);

    Shader(std::string vertPath, std::string fragPath);

    ~Shader();

    GLuint compileShader(GLenum shaderType, std::string source);

    GLuint createShaderProgram(GLuint vertexSrc, GLuint fragmentSrc);

    GLuint getShaderProgram();

    void setMatrix(GLchar* property, glm::mat4 matrix);

    // void setUniform(const std::string& name, const glm::mat4& matrix);

    void bind();
    
    void unbind();


private:
    GLuint vertexShader;

    GLuint fragShader;

    GLuint shaderProgram;

};