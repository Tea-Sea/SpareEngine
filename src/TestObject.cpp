#include "headers/TestObject.hpp"


    TestObject::TestObject(glm::vec3 position, int ID)
    {
        setID(ID);
        setPosition(position);

        setName("test");

        renderable = new RenderableComponent();
    }

    TestObject::~TestObject()
    {

    }
