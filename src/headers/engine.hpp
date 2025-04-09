#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>
#include <stack>
#include <memory>

class Engine {
    public:
        ~Engine();

        void Run();

        SDL_Renderer* GetRenderer();

        static Engine& GetInstance();   
        
        //bool Engine::frame_resize_event(void *userdata, SDL_Event *event);

        float GetDeltaTime() const;

        int GetWidth() const;

        int GetHeight() const;

    private:
        Engine(const std::string& title, int width, int height);

        void CalculateDeltaTime();

        static Engine* instance;

        SDL_Window* window;

        SDL_Renderer* renderer;

        int frameStart;

        float dt;

        int width;

        int height;
};

#endif