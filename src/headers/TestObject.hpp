#pragma once

#include "GameObject.hpp"
#include "RenderableComponent.hpp"

#include <glm/glm.hpp> 

class TestObject : public GameObject {

public:
    // Constructor to initialize the position
    TestObject();

    glm::vec3 getPosition();

    void setPosition(const glm::vec3& newPosition);

    // Virtual destructor to allow proper cleanup of derived classes
    ~TestObject();

    RenderableComponent meshComponent;

};