#include "headers/SceneManager.hpp"


SceneManager::SceneManager(ResourceManager& rm, SDL_Window* window) : m_resourceManager(rm)
{
    currentScene = new Scene(m_resourceManager, 0);
    
    //currentScene->getObjectList();
}

SceneManager::~SceneManager()
{
}

bool SceneManager::loadScene(Scene* sceneToLoad)
{
    currentScene = sceneToLoad;
    return 1;
}

bool SceneManager::loadScene(std::string* sceneToLoad)
{
    // TODO: add scene loading by name
    //currentScene = sceneToLoad;
    return 1;
}

Scene* SceneManager::getCurrentScene()
{
    return currentScene;
}

void SceneManager::updateCurrentScene(float deltaTime)
{
    if (currentScene)
    {
        currentScene->update(deltaTime);
    }
}
