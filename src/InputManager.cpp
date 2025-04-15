#include "headers/InputManager.hpp"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::update(SDL_Event event)
{
    
    switch (event.type)
    {
        case SDL_QUIT:
        {
            //End the main loop
            quitRequest = true;
        }
        case SDL_MOUSEMOTION:
        {
            // Check relative mouse states
            int deltax = 0, deltay = 0;
            auto r = SDL_GetRelativeMouseState(&deltax, &deltay);
            // SDL_Log("MOUSE\n");
            // SDL_Log("%i, %i \n", deltax, deltay);
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
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
        case SDL_KEYDOWN:
            /* Check the SDLKey values */
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                case SDLK_w:
                {
                    SDL_Log("UP PRESSED\n");
                }
                break;
                case SDLK_LEFT:
                case SDLK_a:
                {
                    SDL_Log("LEFT PRESSED\n");
                }
                break;
                case SDLK_DOWN:
                case SDLK_s:
                {
                    SDL_Log("DOWN PRESSED\n");
                }
                break;
                case SDLK_RIGHT:
                case SDLK_d:
                {
                    SDL_Log("RIGHT PRESSED\n");
                }
                break;
                case SDLK_ESCAPE:
                {
                    //End the main loop
                    quitRequest = true;
                }
                default:
                break;
            }
            break;
        // KEY RELEASES
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                case SDLK_w:
                SDL_Log("UP RELEASED\n");
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                SDL_Log("LEFT RELEASED\n");
                    break;
                    case SDLK_DOWN:
                    case SDLK_s:
                SDL_Log("DOWN RELEASED\n");
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
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

bool InputManager::getQuitRequested() const
{
    return quitRequest;
}