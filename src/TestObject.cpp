#include "headers/TestObject.hpp"


    TestObject::TestObject(glm::vec3 position, int ID)
    {
        setID(ID);
        setPosition(position);
        renderable = new RenderableComponent();
    }

    TestObject::~TestObject()
    {

    }
