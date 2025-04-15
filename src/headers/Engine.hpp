#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <string>

#include "WindowManager.hpp"
#include "Renderer.hpp"
#include "InputManager.hpp"
#include "SceneManager.hpp"

class Engine
{
    public:
    
        bool run();
        
        WindowManager* getWindow();
        
        Renderer* getRenderer();
        
        InputManager* getInputManager();
        
        SceneManager* getSceneManager();
        
        static Engine& getInstance();   
        
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

        SceneManager m_sceneManager;

        int frameStart;

        float dt;

        int width;

        int height;
};