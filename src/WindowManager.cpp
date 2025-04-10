#include "headers/WindowManager.hpp"

#include <glad/glad.h>
#include <stdexcept>


WindowManager::WindowManager(const std::string& title, int width, int height)
{
    WindowManager::width = width;
    WindowManager::height = height;
    window = SDL_CreateWindow( title.c_str(), width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 
    if (window == nullptr)
    {
        throw std::logic_error("Failed to create window.");
    }
}


WindowManager::~WindowManager()
{
    SDL_DestroyWindow(window);
}

SDL_Window* WindowManager::getWindow()
{
    return window;
}

int WindowManager::getWidth() const
{
    return width;
}

int WindowManager::getHeight() const
{
    return height;
}