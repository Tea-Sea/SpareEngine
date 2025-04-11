#include "headers/Renderer.hpp"

#include <stdexcept>
#include <iostream>

// THIS IS GROSS AND JUST FOR TESTING
const char *vertexShaderSource = "#version 320 es\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// const char *fragmentShaderSource = "#version 320 es\n"
//     "precision mediump float;\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     "    FragColor = vec4(1.0f, 0.2f, 0.1f, 1.0f);\n"
//     "}\0";
const char *fragmentShaderSource = "#version 320 es\n"
"precision mediump float;\n"
"\n"
"out vec4 fragColor;\n"
"\n"
"uniform vec2 iResolution;\n"
"uniform float iTime;\n"
"\n"
"vec3 palette(float t) {\n"
"    vec3 a = vec3(0.5, 0.5, 0.5);\n"
"    vec3 b = vec3(0.5, 0.5, 0.5);\n"
"    vec3 c = vec3(1.0, 1.0, 1.0);\n"
"    vec3 d = vec3(0.263, 0.416, 0.557);\n"
"\n"
"    return a + b * cos(6.28318 * (c * t + d));\n"
"}\n"
"\n"
"void main() {\n"
"    vec2 fragCoord = gl_FragCoord.xy;\n"
"    vec2 uv = (fragCoord * 2.0 - iResolution) / iResolution.y;\n"
"    vec2 uv0 = uv;\n"
"    vec3 finalColor = vec3(0.0);\n"
"\n"
"    for (float i = 0.0; i < 4.0; i++) {\n"
"        uv = fract(uv * 1.5) - 0.5;\n"
"\n"
"        float d = length(uv) * exp(-length(uv0));\n"
"        vec3 col = palette(length(uv0) + i * 0.4 + iTime * 0.4);\n"
"\n"
"        d = sin(d * 8.0 + iTime) / 8.0;\n"
"        d = abs(d);\n"
"        d = pow(0.01 / d, 1.2);\n"
"\n"
"        finalColor += col * d;\n"
"    }\n"
"\n"
"    fragColor = vec4(finalColor, 1.0);\n"
"}\n";


Renderer::Renderer(SDL_Window* window)
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };  


    unsigned int VBO;
    glGenBuffers(1, &VBO);  
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
}

Renderer::~Renderer()
{
    

}

bool Renderer::renderLoop(SDL_Window* window)
{
    GLint resLoc = glGetUniformLocation(shaderProgram, "iResolution");
    glUniform2f(resLoc, 600, 800);

    GLint timeLoc = glGetUniformLocation(shaderProgram, "iTime");
    glUniform1f(timeLoc, (SDL_GetTicks() / 1000.0f));

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(window);
    return 1;
}

// --- 2D ---
bool Renderer::drawPixel(Vector2 &pos, int colour)
{
    return 1;

}

bool Renderer::drawTriangle(Vector2 &p1, Vector2 &p2, Vector2 &p3, int colour)
{
    
    return 1;
}

// --- 3D ---
bool Renderer::drawPoint(Vector3 &pos, int colour)
{
    return 1;

}

bool Renderer::drawTriangle(Vector3 &p1, Vector3 &p2, Vector3 &p3, int colour)
{
    return 1;
}