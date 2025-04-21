#include "headers/Camera.hpp"

Camera::Camera()
{
    setName("Camera");

    
    // TODO: Handle view an projection matrixes

    view = getViewMatrix();
    projection = getProjectionMatrix();
}

Camera::~Camera()
{

}

glm::mat4 Camera::getViewMatrix() const
{
    // glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-pitch), glm::vec3(1, 0, 0));
    // return rotationMatrix * glm::inverse(this->getTransform().getModelMatrix());

    return glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(glm::radians(fov), aspect, nearClip, farClip);
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
    return getProjectionMatrix() * getViewMatrix();
}

void Camera::setAspectRatio(float x, float y)
{
    aspect = x / y;
}