#include "headers/SceneManager.hpp"


SceneManager::SceneManager()
{
    Scene* currentScene = new Scene();
    currentScene->getObjectList();
}

SceneManager::~SceneManager()
{
}

bool SceneManager::loadScene(Scene* sceneToLoad)
{
    currentScene = sceneToLoad;
    return 1;
}

Scene* SceneManager::getCurrentScene()
{
    return currentScene;
}
