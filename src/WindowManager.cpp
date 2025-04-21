#include "headers/WindowManager.hpp"

#include <stdexcept>
#include <iostream>


WindowManager::WindowManager(const std::string& title, int width, int height)
{
    // Initialise SDL
    if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        throw std::logic_error("Failed to initialise SDL library.");
    }
    
    // Create SDL window
    window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 
    if (window == nullptr)
    {
        throw std::logic_error("Failed to create window.");
    }

    // Create GL Context and attach to the window. Make it current
    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) 
    {
        throw std::runtime_error("Failed to attach glcontext to the window.");
        SDL_DestroyWindow(window);
    }
    SDL_GL_MakeCurrent(window, glContext);
    
    // Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //Initialise GLAD and set viewport
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            throw std::runtime_error("Failed to initialise GLAD.");
        }
    glViewport(0, 0, 800, 600);
}

WindowManager::~WindowManager()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}

void WindowManager::update(SDL_Event event)
{
    switch (event.type)
    {
    case SDL_WINDOWEVENT:
        {
            if (event.window.event == SDL_WINDOWEVENT_RESIZED)
            {
                // Update width and height from the window resize event
                SDL_GetWindowSize(window, &width, &height);
                glViewport(0, 0, width, height);

                SDL_Log("Window resized to: %i , %i" , width, height);
                if (resizeCallback) {
                    resizeCallback(width, height);
                }
            }
        }
    }
}

void WindowManager::setResizeCallback(ResizeCallback callback) {
    resizeCallback = callback;
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