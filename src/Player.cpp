#include "headers/Player.hpp"

Player::Player()
{
    setName("Player");
}

Player::Player(glm::vec3 pos, int id)
{
    setName("Player");
    setID(id);
    setPosition(pos);
    velocity = {0,0,0};
}

Player::~Player()
{
}

void Player::update(float deltaTime)
    {
        transform.position += velocity * deltaTime;

        float rotationSpeed = glm::radians(90.0f); // Rotate 90 degrees/sec

        float angle = rotationSpeed * deltaTime;  // Angle to rotate (in degrees)

        glm::quat rotationQuat = glm::angleAxis(angle, glm::vec3(0.0f, 1.0f, 0.0f));

        transform.rotation = glm::normalize(transform.rotation * rotationQuat);

    }