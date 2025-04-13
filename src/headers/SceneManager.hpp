#pragma once

#include "Scene.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
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