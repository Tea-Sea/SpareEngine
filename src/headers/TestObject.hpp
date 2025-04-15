#pragma once

#include "GameObject.hpp"
#include "RenderableComponent.hpp"

#include <glm/glm.hpp> 

class TestObject : public GameObject {

public:
    TestObject(glm::vec3 position, int ID);

    ~TestObject();

};