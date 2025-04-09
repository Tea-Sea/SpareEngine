#include "headers/renderer.hpp"
#include "headers/inputManager.hpp"
#include "headers/engine.hpp"

#include <glad/glad.h>
#include <stdexcept>

Engine* Engine::instance = nullptr;

Engine::Engine(const std::string& title, int width, int height)
{
    // Check if engine instance already exists
    if (instance == nullptr) {
        instance = this;
    } else {
        throw std::logic_error("Engine constructor called when an instance is already created.");
    }

    // Initialise SDL
    if( !SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) )
    {
        throw std::logic_error("Failed to initialise SDL library.");
    }

    // TODO: Check MIX_Init

    // Create window
    window = SDL_CreateWindow( title.c_str(), width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); 
    if (window == nullptr)
    {
        throw std::logic_error("Failed to create window.");
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        throw std::runtime_error("Failed to create a renderer for the window.");
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            throw std::runtime_error("Failed to initialise GLAD."); 
        }

        
        glViewport(0, 0, 800, 600);
        // TODO: Add event to watch for window resize
        //SDL_AddEventWatch(frame_resize_event, NULL);

    Renderer renderer;
}

Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

Engine& Engine::GetInstance() {
    if (instance == nullptr) {
        instance = new Engine("Hello Window", 800, 600);
    }
    return *instance;
}

// bool frame_resize_event(void *userdata, SDL_Event *event) {
//     if (event->type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
//         int h;
//         int w;
//         SDL_GetWindowSize(window, &w, &h);
//         glViewport(0, 0, w, h); // will be executed when SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED event occures
//     }
//     return true;
// }

void Engine::Run()
{
    //TODO: Add main loop
    while (!InputManager::GetInstance().WasQuitRequested())
    {
        InputManager::GetInstance().Update();
        SDL_Delay(0.5);
    }
}