#pragma once

#include "Scene.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class SceneManager
{
	public:
	
		SceneManager();

		~SceneManager();

		Scene* currentScene;
	
	private:
	
};