#include <cstdint>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Renderer
{
	public:
		
	Renderer();
	int open_window();
	void close();
	void process_input(SDL_Window* gwindow);

	private:

		// COMPONENTS
	
        bool initialise(); //Return curent display info to be rendered
		void framebuffer_size_callback(SDL_Window* gWindow, int width, int height);
};