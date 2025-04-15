#include "headers/Renderer.hpp"

#include <stdexcept>
#include <iostream>

Renderer::Renderer(SDL_Window* window)
{
    
}

Renderer::~Renderer()
{
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
}

void Renderer::beginFrame()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
}

void Renderer::endFrame(SDL_Window* window)
{
    SDL_GL_SwapWindow(window);
}

bool Renderer::renderLoop(SDL_Window* window, std::vector<std::unique_ptr<GameObject>>& objects)
{

    beginFrame();
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    // DEBUGGING
    for (const auto& obj : objects)
    {
        if (obj->hasRenderable())
        {
            glUniform3f(glGetUniformLocation(obj->getRenderable()->getShader()->getShaderProgram(), "colour"), 5.0f, 0.2f, 0.0f);  // Set wireframe colour
            obj->getRenderable()->getShader()->use();
            obj->getRenderable()->getMesh()->draw(obj->getRenderable()->getShader());
        }
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Switch to wireframe mode
    glLineWidth(2.0f);  // Optional: Change line width for better visibility

    for (const auto& obj : objects)
    {
        if (obj->hasRenderable())
        {
            // Use a different colour for wireframe
            glUniform3f(glGetUniformLocation(obj->getRenderable()->getShader()->getShaderProgram(), "colour"), 1.0f, 1.0f, 1.0f);  // Set wireframe colour
            obj->getRenderable()->getShader()->use();
            obj->getRenderable()->getMesh()->draw(obj->getRenderable()->getShader());
        }
    }

    // GLint resLoc = glGetUniformLocation(shaderProgram, "iResolution");
    // glUniform2f(resLoc, 600, 800);

    // GLint timeLoc = glGetUniformLocation(shaderProgram, "iTime");
    // glUniform1f(timeLoc, (SDL_GetTicks() / 1000.0f));

    glBindVertexArray(0);

    endFrame(window);
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