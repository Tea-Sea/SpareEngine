#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
class InputManager
{
	public:
	
		InputManager();

		~InputManager();
		
		void update();

		bool getQuitRequested() const;
		
	private:

		bool quitRequest;
};

#endif