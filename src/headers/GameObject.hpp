#pragma once

#include <glm/glm.hpp> 

class GameObject {

public:

    GameObject();

    // Constructor to initialize the position
    GameObject(glm::vec3 position,int ID);

    // Virtual destructor to allow proper cleanup of derived classes
    virtual ~GameObject();
    
    glm::vec3 getPosition();

    void setPosition(const glm::vec3& newPosition);

    int getID();

    void setID(int id);

protected:
    glm::vec3 position;  // Common position for all objects
    
    int ID;
    
};