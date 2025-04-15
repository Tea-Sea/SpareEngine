#include "headers/GameObject.hpp"

GameObject::GameObject() : position(position)
{  
}

GameObject::GameObject(glm::vec3 position, int ID) : position(position)
{
    setID(ID);
    setPosition(position);
}

GameObject::~GameObject()
{
}

glm::vec3 GameObject::getPosition() 
{
    return position;
}

void GameObject::setPosition(const glm::vec3& newPosition)
{
    position = newPosition;
}

int GameObject::getID() 
{
    return ID;
}

void GameObject::setID(int id) 
{
    ID = id;
}

bool GameObject::hasRenderable() const
{
    return renderable != nullptr;
}

RenderableComponent* GameObject::getRenderable()
{
    return renderable;
}
