#include "headers/renderer.h"

#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

/* Constants */
//Screen dimension constants
constexpr int kScreenWidth{ 800 };
constexpr int kScreenHeight{ 600 };

/* Global Variables */
//The window we'll be rendering to
SDL_Window* gWindow{ nullptr };
    
//The surface contained by the window
SDL_Surface* gScreenSurface{ nullptr };

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{ nullptr };

renderer::renderer()
{

}

// // TODO: call this when window is resized
// void framebuffer_size_callback(SDL_Window* gWindow, int width, int height)
// {
//     glViewport(0, 0, width, height);
// }  

bool frame_resize_event(void *userdata, SDL_Event *event) {
    if (event->type == SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED) {
        int h;
        int w;
        SDL_GetWindowSize(gWindow, &w, &h);
        glViewport(0, 0, w, h); // will be executed when SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED event occures
    }
    return true;
}

/* Function Implementations */
bool renderer::initialise()
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
        if( gWindow = SDL_CreateWindow( "Hello Window", kScreenWidth, kScreenHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL); gWindow == nullptr )
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
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
        {
            SDL_Log("Failed to initialize GLAD\n"); 
            success = false;
        }
        SDL_AddEventWatch(frame_resize_event, NULL);
        glViewport(0, 0, 800, 600);

    return success;
}

void process_input(SDL_Window* gwindow)
{
    
}

void renderer::close()
{
    //Clean up surface
    SDL_DestroySurface( gHelloWorld );
    gHelloWorld = nullptr;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gScreenSurface = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}

int renderer::open_window(){
        //Final exit code
        int exitCode{ 0 };

        //Initialize
        if( !initialise() )
        {
            SDL_Log( "Unable to initialize program!\n" );
            exitCode = 1;
        }
        else
        {
            //The quit flag
            bool quit{ false };
    
            //The event data
            SDL_Event e;
            SDL_zero( e );
            
            //The main loop
            while( quit == false )
            {
                //Get event data
                while( SDL_PollEvent( &e ) )
                {
                    switch (e.type) {
                        case SDL_EVENT_QUIT:
                        {
                            //End the main loop
                            quit = true;
                        }
                    /* Look for a keypress */
                case SDL_EVENT_KEY_DOWN:
                    /* Check the SDLKey values and move change the coords */
                    switch( e.key.key ){
                        case SDLK_LEFT:
                            SDL_Log("LEFT PRESSED\n");
                            break;
                        case SDLK_RIGHT:
                        SDL_Log("RIGHT PRESSED\n");
                            break;
                        case SDLK_UP:
                        SDL_Log("UP PRESSED\n");
                            break;
                        case SDLK_DOWN:
                        SDL_Log("DOWN PRESSED\n");
                            break;
                        default:
                            break;
                    }
                    break;
                /* We must also use the SDL_KEYUP events to zero the x */
                /* and y velocity variables. But we must also be       */
                /* careful not to zero the velocities when we shouldn't*/
                case SDL_EVENT_KEY_UP:
                    switch( e.key.key ){
                        case SDLK_LEFT:
                        SDL_Log("LEFT RELEASED\n");
                            break;
                        case SDLK_RIGHT:
                        SDL_Log("RIGHT RELEASED\n");
                            break;
                        case SDLK_UP:
                        SDL_Log("UP RELEASED\n");
                            break;
                        case SDLK_DOWN:
                        SDL_Log("DOWN RELEASED\n");
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                break;
                    }
                }
    
                //Fill the surface white
                SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, 0xFF, 0xFF, 0xFF ) );
            
                //Render image on screen
                SDL_BlitSurface( gHelloWorld, nullptr, gScreenSurface, nullptr );
    
                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            } 
        }
        //Clean up
        close();
        return exitCode;
}




