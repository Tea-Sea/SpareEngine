#include <cstdint>

class renderer
{
	private:

		// COMPONENTS
	
        bool init(); //Return curent display info to be rendered

	public:
	renderer();
	int open_window();
	void close();
};