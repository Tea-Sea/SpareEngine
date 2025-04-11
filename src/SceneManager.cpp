#include "headers/SceneManager.hpp"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
    Scene* currentScene = new Scene();
}

SceneManager::~SceneManager()
{
}

SceneManager& SceneManager::getSceneManager()
{   
    if (instance == nullptr) 
    {
        instance = new SceneManager;
    }
    return *instance;
}