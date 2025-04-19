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

void Renderer::drawObjects(RenderData data)
{
    Shader* currentShader = nullptr;
    for (const auto& obj : data.objects)
    {
        Shader* shader = obj->getRenderable()->getMaterial()->getShader();

        if (shader != currentShader)
        {
            glUniform3f(glGetUniformLocation(obj->getRenderable()->getMaterial()->getShader()->getShaderProgram(), "colour"), 5.0f, 0.2f, 0.0f);
            if (debugging)
            {
            glUniform3f(glGetUniformLocation(obj->getRenderable()->getMaterial()->getShader()->getShaderProgram(), "colour"), 1.0f, 1.0f, 1.0f);
            }
            obj->getRenderable()->getMaterial()->getShader()->bind();
            currentShader = shader;

            shader->setMatrix("view", data.camera->getViewMatrix());
            shader->setMatrix("projection", data.camera->getProjectionMatrix());
        }
        shader->setMatrix("model", obj->getModelMatrix());

        // TODO: Move these to the scene
        // obj->getRenderable()->getMaterial()->getShader()->setMatrix("view", data.camera->getViewMatrix());
        // obj->getRenderable()->getMaterial()->getShader()->setMatrix("projection", data.camera->getProjectionMatrix());

        obj->getRenderable()->getMesh()->draw(obj->getRenderable()->getMaterial()->getShader());

        // TODO: Refactor this because its gross as
        
    }
}

bool Renderer::renderLoop(SDL_Window* window, RenderData data)
{
    // data.camera->getViewMatrix();
    beginFrame();
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    drawObjects(data);

    // DEBUGGING
    if (debugging)
    {
        // Draw objects in wireframe mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Switch to wireframe mode

        drawObjects(data);
    }

    // Move these to uniform construction code in shader
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