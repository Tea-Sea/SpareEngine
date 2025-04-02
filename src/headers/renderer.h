#include <cstdint>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
class renderer
{
	private:

		// COMPONENTS
	
        bool initialise(); //Return curent display info to be rendered
		void framebuffer_size_callback(SDL_Window* gWindow, int width, int height);

	public:
	renderer();
	int open_window();
	void close();
};