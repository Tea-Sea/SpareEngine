#pragma once

#include <glm/glm.hpp> 

class GameObject {

public:
    // Constructor to initialize the position
    GameObject(glm::vec3 position);

    glm::vec3 getPosition();

    void setPosition(const glm::vec3& newPosition);
    
    // Virtual destructor to allow proper cleanup of derived classes
    virtual ~GameObject();

protected:
    glm::vec3 position;  // Common position for all objects
};