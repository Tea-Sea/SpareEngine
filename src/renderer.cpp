#include "headers/renderer.h"

#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

/* Constants */
//Screen dimension constants
constexpr int kScreenWidth{ 640 };
constexpr int kScreenHeight{ 480 };

/* Global Variables */
//The window we'll be rendering to
SDL_Window* gWindow{ nullptr };
    
//The surface contained by the window
SDL_Surface* gScreenSurface{ nullptr };

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{ nullptr };

renderer::renderer() {

}

/* Function Implementations */
bool renderer::open_window()
{
    //Initialization flag
    bool success{ true };

    //Initialize SDL
    if( !SDL_Init( SDL_INIT_VIDEO ) )
    {
        SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        if( gWindow = SDL_CreateWindow( "SDL3 Tutorial: Hello SDL3", kScreenWidth, kScreenHeight, 0 ); gWindow == nullptr )
        {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}


