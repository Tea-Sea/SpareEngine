#include "headers/Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Shader::Shader(std::string path)
{
    std::stringstream strBuffer;
    std::string vertSrc = "assets/shaders/vertex.glsl";
    path = "assets/shaders/" + path;
    
    //Load and compile shaders
    std::ifstream vert(vertSrc);
    std::ifstream frag(path);

    if (!frag) {
        std::cerr << "Error reading shader file." << std::endl;
    }
    strBuffer << vert.rdbuf();
    vertexShader = compileShader(GL_VERTEX_SHADER, strBuffer.str());
    strBuffer.str(std::string());
    strBuffer << frag.rdbuf();
    fragShader = compileShader(GL_FRAGMENT_SHADER, strBuffer.str());

    shaderProgram = createShaderProgram(vertexShader, fragShader);
    glUseProgram(shaderProgram);
    // FOR TESTING PURPOSES -----------------
   
    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc  = glGetUniformLocation(shaderProgram, "view");
    GLint projLoc  = glGetUniformLocation(shaderProgram, "projection");

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::lookAt(
        glm::vec3(3.0f, 3.0f, 3.0f), // camera position
        glm::vec3(0.0f, 0.0f, 0.0f), // look at
        glm::vec3(0.0f, 1.0f, 0.0f)  // up vector
    );
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (float)600 / (float)800,
        0.1f,
        100.0f
    );

    // Upload matrices to shader
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    // -----------------------
    
    vert.close();
    frag.close();
}

Shader::Shader(std::string vertPath, std::string fragPath)
{
    std::stringstream strBuffer;

    vertPath = "assets/shaders/" + vertPath;
    fragPath = "assets/shaders/" + fragPath;
    //Load and compile shaders
    std::ifstream vert(vertPath);
    std::ifstream frag(fragPath);

    if (!vert) {
        std::cerr << "Error reading vertex shader file." << std::endl;
    }
    if (!frag) {
        std::cerr << "Error reading fragment shader file." << std::endl;
    }

    strBuffer << vert.rdbuf();
    vertexShader = compileShader(GL_VERTEX_SHADER, strBuffer.str());
    strBuffer.str(std::string());
    strBuffer << frag.rdbuf();
    fragShader = compileShader(GL_FRAGMENT_SHADER, strBuffer.str());

    createShaderProgram(vertexShader, fragShader);

    vert.close();
    frag.close();
}

Shader::~Shader()
{

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
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vert);
    glAttachShader(shaderProgram, frag);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader Linking Failed:\n" << infoLog << std::endl;
    }

    // Clean up shaders after linking
    glDeleteShader(vert);
    glDeleteShader(frag);

    return shaderProgram;
}

GLuint Shader::getShaderProgram()
{
    return shaderProgram;
}

void Shader::setMat4(GLchar* property, glm::mat4 matrix)
{
    GLint modelLoc = glGetUniformLocation(shaderProgram, property);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

// void Shader::setUniform(const std::string& name, const glm::mat4& matrix) 
// {
//     GLint location = getUniformLocation(name);
//     glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
// }

void Shader::bind()
{
    glUseProgram(shaderProgram);
}

void Shader::unbind()
{
    glUseProgram(0);
}
