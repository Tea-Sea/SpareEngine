#include "headers/Renderer.hpp"

#include <stdexcept>

Renderer::Renderer(SDL_Window* window)
{
    // Create renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        throw std::runtime_error("Failed to create a renderer for the window.");
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
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