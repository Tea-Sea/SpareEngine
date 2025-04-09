#include <cstdint>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
class InputManager
{
	public:
	
	static InputManager& GetInstance();

	void Update();

	bool WasQuitRequested() const;
	
	private:

	InputManager();

	~InputManager();

	static InputManager instance;
	
	bool quitRequest;
};