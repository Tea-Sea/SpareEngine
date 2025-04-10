#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include "WindowManager.hpp"
#include "Renderer.hpp"
#include "InputManager.hpp"

class Engine
{
    public:
    
        bool run();
        
        WindowManager* getWindow();
        
        Renderer* getRenderer();
        
        InputManager* getInputManager();
        
        static Engine& getInstance();   
        
        //bool Engine::frame_resize_event(void *userdata, SDL_Event *event);
        
        float getDeltaTime() const;
        
        int getWidth() const;
        
        int getHeight() const;
    
    private:
    
        Engine(const std::string& title, int width, int height);

        ~Engine();

        void calculateDeltaTime();

        static Engine* instance;

        WindowManager m_windowManager;

        Renderer m_renderer;

        InputManager m_inputManager;

        int frameStart;

        float dt;

        int width;

        int height;
};

#endif