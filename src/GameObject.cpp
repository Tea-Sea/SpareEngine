#include "headers/GameObject.hpp"

GameObject::GameObject()
{  
}

GameObject::GameObject(int ID)
{
    setID(ID);
}

GameObject::GameObject(glm::vec3 position, int ID)
{
    setID(ID);
    setPosition(position);
    velocity = {0,0,0};
}

GameObject::~GameObject()
{
}

void GameObject::addChild(GameObject* child)
{
    if (child == nullptr || child == this)
    {
        std::cout << "Error adding child" << child->getID() << " to gameObject id:" << ID << std::endl;
    }

    if (child->parent)
    {
        child->parent->removeChild(child);
    }

        child->parent = this;
        children.push_back(child);
}

void GameObject::removeChild(GameObject* child)
{
    if (child == nullptr || child == this)
    {
        std::cout << "Error removing child" << child->getID() << " from gameObject id:" << ID << std::endl;
    }

    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end())
    {
        children.erase(it);
    }
}

glm::vec3 GameObject::getPosition() const
{
    return transform.position;
}

glm::quat GameObject::getRotation() const
{
    return transform.rotation;
}

glm::vec3 GameObject::getScale() const
{
    return transform.scale;
}

Transform GameObject::getTransform() const
{
    if (parent) {
        return parent->getTransform() * transform;
    } else {
        return transform;
    }
}

int GameObject::getID() 
{
    return ID;
}

const std::string& GameObject::getName() const
{
    return name;
}


void GameObject::setPosition(const glm::vec3& newPosition)
{
    transform.position = newPosition;
}

void GameObject::setRotation(const glm::quat& rot) 
{
    transform.rotation = rot;
}

void GameObject::setScale(const float x, const float y, const float z) 
{
    transform.scale.x = x;
    transform.scale.y = y;
    transform.scale.z = z;
}

void GameObject::setID(int id) 
{
    ID = id;
}
void GameObject::setName(std::string newName)
{
   name = newName;
}


bool GameObject::hasRenderable() const
{
    return renderable != nullptr;
}

RenderableComponent* GameObject::getRenderable()
{
    return renderable;
}

glm::mat4 GameObject::getModelMatrix()
{
    return transform.getModelMatrix();
}


void GameObject::update(float deltaTime)
{
    // transform.position += velocity * deltaTime;
}