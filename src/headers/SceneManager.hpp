#pragma once

#include "Scene.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <vector>

class SceneManager
{
	public:
	
		SceneManager();

		~SceneManager();

		Scene* getCurrentScene();

		bool loadScene(Scene* sceneToLoad);

	private:

	Scene* currentScene;
	// vector<Mesh> 

	
};