#include "headers/Camera.hpp"

Camera::Camera()
{
    setName("Camera");
    // TODO: Handle view an projection matrixes
}

Camera::~Camera()
{

}

glm::mat4 Camera::getViewMatrix() const
{
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-pitch), glm::vec3(1, 0, 0));
    return rotationMatrix * glm::inverse(this->getTransform().getModel());
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(glm::radians(fov), aspect, nearClip, farClip);
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
    return getProjectionMatrix() * getViewMatrix();
}