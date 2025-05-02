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

void Renderer::drawObjects(RenderData data, float deltaTime, bool debugging)
{
    // data.camera->updateAspectRatio()
    Shader* currentShader = nullptr;
    for (const auto& obj : data.objects)
    {
        Shader* shader = obj->getRenderable()->getMaterial()->getShader();

        if (shader != currentShader)
        {
            if (debugging)
            {
                glUniform3f(glGetUniformLocation(obj->getRenderable()->getMaterial()->getShader()->getShaderProgram(), "colour"), 1.0f, 1.0f, 1.0f);
            } else {
                glUniform3f(glGetUniformLocation(obj->getRenderable()->getMaterial()->getShader()->getShaderProgram(), "colour"), 5.0f, 0.2f, 0.0f);
            }
            obj->getRenderable()->getMaterial()->getShader()->bind();
            currentShader = shader;
            // if (shader->uniformExists("test"))
            // {
            //     shader->setUniform("test", test data)
            // }
            // //repeat
            //     if (test == "view")
            //     {

            //     }
            // }
            shader->setUniform("view", data.camera->getViewMatrix());
            shader->setUniform("projection", data.camera->getProjectionMatrix());
            shader-> setUniform("time", deltaTime);
            // std::cout << deltaTime << std::endl;
            shader-> setUniform("resolution", glm::vec2(800.0f, 600.0f));
        }
        shader->setUniform("model", obj->getModelMatrix());

        // TODO: Move these to the scene
        // obj->getRenderable()->getMaterial()->getShader()->setMatrix("view", data.camera->getViewMatrix());
        // obj->getRenderable()->getMaterial()->getShader()->setMatrix("projection", data.camera->getProjectionMatrix());

        obj->getRenderable()->getMesh()->draw(obj->getRenderable()->getMaterial()->getShader());


    //     GLint location = glGetUniformLocation(shader->getShaderProgram(), "iTime");
    // if (location == -1) {
    //     std::cout << "Uniform not found in the shader." << std::endl;
    // } else {
    //     GLfloat value;
    //     glGetUniformfv(shader-> getShaderProgram(), location, &value);
    //     std::cout << "Uniform WAS found at location: " << location << std::endl;
    //     std::cout << "Current value: " << value << std::endl;
    // }
        // TODO: Refactor this because its gross as
        
    }
}

bool Renderer::renderLoop(SDL_Window* window, float deltaTime, RenderData data)
{
    // data.camera->getViewMatrix();
    beginFrame();
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    drawObjects(data, deltaTime, 0);

    // DEBUGGING
    if (debugging)
    {
        // Draw objects in wireframe mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Switch to wireframe mode
        glDepthMask(GL_FALSE);

        drawObjects(data, deltaTime, 1);
    }

    // Move these to uniform construction code in shader
    // GLint resLoc = glGetUniformLocation(shaderProgram, "iResolution");
    // glUniform2f(resLoc, 600, 800);

    // GLint timeLoc = glGetUniformLocation(shaderProgram, "iTime");
    // glUniform1f(timeLoc, (SDL_GetTicks() / 1000.0f));

    glBindVertexArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDepthMask(GL_TRUE);
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