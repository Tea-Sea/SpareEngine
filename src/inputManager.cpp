#include "headers/inputManager.hpp"

#include <iostream>



InputManager InputManager::instance;

InputManager& InputManager::GetInstance() {
    return instance;
}


InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
    //The main loop
    
    //The event data
    SDL_Event e;
    
    //Get event data
    while( SDL_PollEvent( &e ) )
    {
        switch (e.type)
        {
            case SDL_EVENT_QUIT:
            {
                //End the main loop
                quitRequest = true;
            }
            case SDL_EVENT_MOUSE_MOTION:
            {
                // Check relative mouse states
                float deltax = 0, deltay =0;
                SDL_Log("MOUSE\n");
                auto r = SDL_GetRelativeMouseState(&deltax, &deltay);
                SDL_Log("%F, %F \n", deltax, deltay);
            }
            break;
            /* Look for a keypress */
            case SDL_EVENT_KEY_DOWN:
                /* Check the SDLKey values and move change the coords */
                switch( e.key.key )
                {
                    case SDLK_UP:
                    case SDLK_W:
                    {
                        SDL_Log("UP PRESSED\n");
                    }
                    break;
                    case SDLK_LEFT:
                    case SDLK_A:
                    {
                        SDL_Log("LEFT PRESSED\n");
                    }
                    break;
                    case SDLK_DOWN:
                    case SDLK_S:
                    {
                        SDL_Log("DOWN PRESSED\n");
                    }
                    break;
                    case SDLK_RIGHT:
                    case SDLK_D:
                    {
                        SDL_Log("RIGHT PRESSED\n");
                    }
                    break;
                    default:
                    break;
                }
                break;
            /* We must also use the SDL_KEYUP events to zero the x */
            /* and y velocity variables. But we must also be       */
            /* careful not to zero the velocities when we shouldn't*/
            case SDL_EVENT_KEY_UP:
                switch( e.key.key )
                {
                    case SDLK_UP:
                    case SDLK_W:
                    SDL_Log("UP RELEASED\n");
                        break;
                    case SDLK_LEFT:
                    case SDLK_A:
                    SDL_Log("LEFT RELEASED\n");
                        break;
                        case SDLK_DOWN:
                        case SDLK_S:
                    SDL_Log("DOWN RELEASED\n");
                        break;
                    case SDLK_RIGHT:
                    case SDLK_D:
                    SDL_Log("RIGHT RELEASED\n");
                        break;
                    default:
                        break;
                }
                break;
            default:
            break;
        }
    }
}

bool InputManager::WasQuitRequested() const
{
    return quitRequest;
}