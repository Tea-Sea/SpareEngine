#include "headers/SceneManager.hpp"


SceneManager::SceneManager()
{
    Scene* currentScene = new Scene();
    currentScene->testObject->getPosition();
}

SceneManager::~SceneManager()
{
}
