#include "headers/Scene.hpp"

#include <stdexcept>

Scene::Scene(int id)
{
    ID = id;

    // Test purposes
    Player* testPlayer = new Player(glm::vec3(-1, 1, -1), 0);
    Camera* testCamera = new Camera();
    TestObject* testObject = new TestObject(glm::vec3(0, 0, 0), 2);
    
    camera = testCamera;
    

    testPlayer->addChild(testCamera);

    addObjectToList(testObject);
    addObjectToList(testPlayer);
    addObjectToList(testCamera);
}

Scene::Scene(std::string src)
{
    // TODO: LOAD SCENE DATA FROM SOURCE
}

Scene::~Scene()
{
}

bool Scene::addObjectToList(GameObject* obj)
{
    objectList.push_back(std::unique_ptr<GameObject>(obj));
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
GameObject* Scene::getCamera() const
{
    return camera;
}

RenderData Scene::prepareRenderData() {
    RenderData data;
    data.camera = camera;
    for (auto& obj : getObjectList())
    {
        if (obj->hasRenderable())
        {
            data.objects.push_back(obj.get()); // non-owning raw pointer
        }
    }
    // data.objects = gatherVisibleObjects(); // could do culling here
    // data.lights = activeLights;
    return data;
}

void Scene::update(float deltaTime)
{
    for (int i = 0; i < objectList.size(); ++i) {
        objectList[i]->update(deltaTime);
    }
}
    