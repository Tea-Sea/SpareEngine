#include "headers/TestObject.hpp"


    TestObject::TestObject(glm::vec3 position, int ID)
    {
        setID(ID);
        setPosition(position);
        velocity = {0,0,0};

        setName("test");

        renderable = new RenderableComponent();
    }

    TestObject::~TestObject()
    {

    }

    void TestObject::update(float deltaTime)
    {
        transform.position += velocity * deltaTime;

        float rotationSpeed = glm::radians(180.0f); // Rotate 90 degrees/sec

        float angle = rotationSpeed * deltaTime;  // Angle to rotate (in degrees)

        glm::quat rotationQuat = glm::angleAxis(angle, glm::vec3(0.72f, 1.0f, 0.28f));

        transform.rotation = glm::normalize(transform.rotation * rotationQuat);

    }
