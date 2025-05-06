#pragma once

#include "Scene.hpp"
#include "ResourceManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <vector>

class SceneManager
{
	public:
	
		SceneManager(ResourceManager& rm, SDL_Window* window);

		~SceneManager();

		Scene* getCurrentScene();

		bool loadScene(Scene* sceneToLoad);

		bool loadScene(std::string* sceneToLoad);

		void updateCurrentScene(float deltaTime);


	private:

	Scene* currentScene;

	ResourceManager m_resourceManager;
	// vector<Mesh> 

	
};