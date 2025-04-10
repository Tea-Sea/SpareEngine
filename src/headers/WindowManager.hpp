#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

class WindowManager
{
    public:
    
        WindowManager();
        WindowManager(const std::string& title, int width, int height);

        ~WindowManager();

        SDL_Window* getWindow();
        
        //bool Engine::frame_resize_event(void *userdata, SDL_Event *event);

        float getDeltaTime() const;

        int getWidth() const;

        int getHeight() const;

    private:

        void calculateDeltaTime();

        SDL_Window* window;

        int frameStart;

        float dt;

        int width;

        int height;
};

#endif