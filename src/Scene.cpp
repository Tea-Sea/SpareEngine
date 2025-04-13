#include "headers/Scene.hpp"


Scene::Scene()
{
    GameObject* testObject0 = new GameObject(glm::vec3(0, 0, 0), 0);
    GameObject* testObject1 = new GameObject(glm::vec3(1, 1, 1), 1);
    addObjectToList(testObject0);
    addObjectToList(testObject1);
    getObjectList();
    // objectList.push_back(testObject);
    searchObjectByID(1);
}

Scene::Scene(std::string src)
{
    // TODO: LOAD SCENE DATA FROM SOURCE
}

Scene::~Scene()
{
}

bool Scene::addObjectToList(GameObject* objectToAdd)
{
    objectList.push_back(objectToAdd);
    return 1;
}

bool Scene::removeObjectFromList(GameObject* objectToRemove)
{

    return 1;
}

GameObject* Scene::searchObjectByID(int ID)
{
    for(int i = 0; i < objectList.size(); i++)
    {
        if (objectList[i]->getID() == ID)
        {
            return objectList[i];
        }
    }
    return nullptr;
}

const std::vector<GameObject*>& Scene::getObjectList() const
{
    return objectList;
}
