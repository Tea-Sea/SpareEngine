#include "headers/TestObject.hpp"


    TestObject::TestObject(glm::vec3 position, int ID)
    {
        setID(ID);
        setPosition(position);
        velocity = {0,0,0};
        setScale(0.5f, 1.0f, 1.0f);

        setName("test");

        renderable = new RenderableComponent();
    }

    TestObject::~TestObject()
    {

    }

    void TestObject::update(float deltaTime)
    {
        // transform.position += velocity * deltaTime;
        transform.position += velocity * deltaTime;
        
        float rotationSpeed = glm::radians(90.0f);  // Rotate 45 degrees per second

        float angle = rotationSpeed * deltaTime;  // Angle to rotate (in degrees)

        glm::quat rotationQuat = glm::angleAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f));

        transform.rotation = glm::normalize(transform.rotation * rotationQuat);
    }
