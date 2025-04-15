#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
class InputManager
{
	public:
	
		InputManager();

		~InputManager();
		
		void update(SDL_Event event);

		bool getQuitRequested() const;
		
	private:

		bool quitRequest;
};