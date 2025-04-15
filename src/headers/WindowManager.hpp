#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <glad/glad.h>
#include <string>

class WindowManager
{
    public:
    
        WindowManager();
        WindowManager(const std::string& title, int width, int height);

        ~WindowManager();

        SDL_Window* getWindow();
        
        static int frame_resize_event(void *userdata, SDL_Event *event);

        void update(SDL_Event event);

        float getDeltaTime() const;

        int getWidth() const;

        int getHeight() const;

    private:

        void calculateDeltaTime();

        SDL_Window* window;

        SDL_GLContext glContext;

        int frameStart;

        float dt;

        int width;

        int height;
};