#include "headers/InputManager.hpp"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::update()
{
    //The event data
    SDL_Event e;
    
    //Get event data
    while(SDL_PollEvent(&e) )
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
                auto r = SDL_GetRelativeMouseState(&deltax, &deltay);
                // SDL_Log("MOUSE\n");
                // SDL_Log("%F, %F \n", deltax, deltay);
            }
            break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            {
                switch(e.button.button)
                {
                    case 1:
                    {
                        SDL_Log("Left Click\n");
                    }
                    break;
                    case 2:
                    {
                        SDL_Log("Middle Click\n");
                    }
                    break;
                    case 3:
                    {
                        SDL_Log("Right Click\n");
                    }
                    break;
                    default:
                    break;
                }
                
            }
            break;
            /* Look for a keypress */
            case SDL_EVENT_KEY_DOWN:
                /* Check the SDLKey values */
                switch(e.key.key)
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
            // KEY RELEASES
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

bool InputManager::getQuitRequested() const
{
    return quitRequest;
}