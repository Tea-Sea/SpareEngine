#pragma once

#include "Scene.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class SceneManager
{
	public:
	
		void update();
		
		bool getQuitRequested() const;

		static SceneManager& getSceneManager();

		Scene currentScene;
	
	private:
	
		SceneManager();

		~SceneManager();

		static SceneManager* instance;

		bool quitRequest;
};