#include <cstdint>

class renderer
{
	private:

		// COMPONENTS
	
        bool init(); //Return curent display info to be rendered

	public:
	renderer();
	bool open_window();
};