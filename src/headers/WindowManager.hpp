#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <glad/glad.h>
#include <string>
#include <functional>

class WindowManager
{
    public:
    
        WindowManager();

        WindowManager(const std::string& title, int width, int height);

        ~WindowManager();

        SDL_Window* getWindow();

        using ResizeCallback = std::function<void(int width, int height)>;

        void setResizeCallback(ResizeCallback callback);
        
        static int frameResizeEvent(void *userdata, SDL_Event *event);

        void update(SDL_Event event);

        float getDeltaTime() const;

        int getWidth() const;

        int getHeight() const;

    private:

        void calculateDeltaTime();

        SDL_Window* window;

        SDL_GLContext glContext;

        ResizeCallback resizeCallback;

        int frameStart;

        float dt;

        int width;

        int height;
};