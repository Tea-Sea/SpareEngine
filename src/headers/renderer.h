#include <cstdint>

class renderer
{
	private:

		// COMPONENTS
	
        bool initialise(); //Return curent display info to be rendered
		// void framebuffer_size_callback(SDL_Window* gWindow, int width, int height);

	public:
	renderer();
	int open_window();
	void close();
};