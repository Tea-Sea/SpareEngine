#pragma once

#include "Scene.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <vector>

class SceneManager
{
	public:
	
		SceneManager(SDL_Window* window);

		~SceneManager();

		Scene* getCurrentScene();

		bool loadScene(Scene* sceneToLoad);

		void updateCurrentScene(float deltaTime);


	private:

	Scene* currentScene;
	// vector<Mesh> 

	
};