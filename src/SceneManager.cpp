#include "headers/SceneManager.hpp"


SceneManager::SceneManager()
{
    currentScene = new Scene(0);
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

Scene* SceneManager::getCurrentScene()
{
    return currentScene;
}
