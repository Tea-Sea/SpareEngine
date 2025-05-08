#include "headers/Camera.hpp"

Camera::Camera()
{
    setName("Camera");

    
    // TODO: Handle view an projection matrixes

    view = calculateViewMatrix();
    //view = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
    projection = calculateProjectionMatrix();
}

Camera::~Camera()
{

}

glm::mat4 Camera::getViewMatrix() const
{
    return view;
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return projection;
}

glm::mat4 Camera::getViewProjectionMatrix() const
{
    return view * projection;
}


glm::mat4 Camera::calculateViewMatrix()
{
    return  glm::inverse(transform.getModelMatrix());

}

glm::mat4 Camera::calculateProjectionMatrix()
{
    return glm::perspective(glm::radians(fov), aspect, nearClip, farClip);
}

glm::mat4 Camera::calculateViewProjectionMatrix()
{
    return getProjectionMatrix() * getViewMatrix();
}

void Camera::setAspectRatio(float x, float y)
{
    aspect = x / y;
}

 void Camera::update(float deltaTime)
 {
    if (parent)
    {
        transform = parent->getTransform();
    }
    view = calculateViewMatrix();
    projection = calculateProjectionMatrix();
    std::cout << "camera: " << transform.position.x << ", " << transform.position.y << ", " << transform.position.z << ", " << std::endl;
    std::cout << "rotation: " << transform.rotation.w << ", " << transform.rotation.x << ", " << transform.rotation.y << ", " << transform.rotation.z << ", " << std::endl;
    for (int row = 0; row < 4; ++row) {
        std::cout << "[ ";
        for (int col = 0; col < 4; ++col) {
            std::cout << view[col][row] << " ";
        }
        std::cout << "]\n";
    }

 }