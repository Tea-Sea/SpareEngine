#pragma once

#include "RenderableComponent.hpp"
#include "../utils/Geometry.hpp"

#include <glm/glm.hpp> 
#include <algorithm>

class GameObject {

public:

    GameObject();

    GameObject(int ID);

    // Constructor to initialize the position
    GameObject(glm::vec3 position, int ID);

    // Virtual destructor to allow proper cleanup of derived classes
    virtual ~GameObject();

    void addChild(GameObject* child);

    void removeChild(GameObject* child);

    glm::vec3 getPosition() const;

    glm::quat getRotation() const;

    glm::vec3 getScale() const;

    Transform getTransform() const;

    int getID();

    const std::string& getName() const;

    void setPosition(const glm::vec3& newPosition);

    void setRotation(const glm::quat& rot);

    void setScale(const float x, const float y, const float z);

    void setID(int id);

    void setName(std::string name);
    
    bool hasRenderable() const;

    RenderableComponent* getRenderable();

    GameObject* parent = nullptr;

    std::vector<GameObject*> children;

    glm::mat4 getModelMatrix();

    virtual void update(float deltaTime);

protected:

    glm::vec3 velocity;

    Transform transform;
    
    int ID;

    std::string name = "";

    RenderableComponent* renderable = nullptr;

    // virtual PhysicsComponent* physics;

    // virtual AIComponent ai;
};