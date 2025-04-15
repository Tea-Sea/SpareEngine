#include "headers/Scene.hpp"

#include <stdexcept>

Scene::Scene(int id)
{
    ID = id;

    // Test purposes
    GameObject testObject0(glm::vec3(0, 0, 0), 0);
    TestObject testObject1(glm::vec3(1, 1, 1), 1);

    addObjectToList(testObject0);
    addObjectToList(testObject1);
}

Scene::Scene(std::string src)
{
    // TODO: LOAD SCENE DATA FROM SOURCE
}

Scene::~Scene()
{
}

bool Scene::addObjectToList(GameObject obj)
{
    objectList.push_back(std::make_unique<GameObject>(obj));
    return 1;
}

bool Scene::removeObjectFromList(GameObject* objectToRemove)
{

    return 1;
}

GameObject& Scene::searchObjectByID(int ID)
{
    if (ID < objectList.size())
    {
        return *objectList[ID];
    }
    throw std::out_of_range("GameObject does not exist");
}

std::vector<std::unique_ptr<GameObject>>& Scene::getObjectList()
{
    return objectList;
}

const int& Scene::getSceneID() const
{
    return ID;
}

const std::string& Scene::getSceneName() const
{
    return name;
}

void Scene::setSceneName(std::string newName)
{
   name = newName;
}