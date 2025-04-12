#include "headers/GameObject.hpp"

GameObject::GameObject() : position(position)
{

}

GameObject::GameObject(glm::vec3 position) : position(position)
{

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