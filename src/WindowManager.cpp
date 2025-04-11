#include "headers/WindowManager.hpp"

#include <stdexcept>
#include <iostream>


WindowManager::WindowManager(const std::string& title, int width, int height)
{
    // Create SDL window
    window = SDL_CreateWindow( title.c_str(), width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 
    if (window == nullptr)
    {
        throw std::logic_error("Failed to create window.");
    }

    // Add frame resize callback
    SDL_AddEventWatch(frame_resize_event, this);

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
    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
}

bool WindowManager::frame_resize_event(void* userdata, SDL_Event* event)
{
    WindowManager* manager = static_cast<WindowManager*>(userdata);
    if (event->type == SDL_EVENT_WINDOW_RESIZED)
    {
        // Update width and height from the window resize event
        SDL_Log("Window Resize");
        manager->width = event->window.data1;
        manager->height = event->window.data2;
        glViewport(0, 0, manager->width, manager->height);
    }
    
    return 1;
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