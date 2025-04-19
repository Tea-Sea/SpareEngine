#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

struct Vector2
{
    float x, y;

    Vector2() : x(0), y(0) {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
};

struct Vector3
{
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

};

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

struct Transform 
{
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
    
    glm::vec3 eulerRotation;

    glm::mat4 getModelMatrix() const
    {
        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, position);
        // model *= glm::toMat4(rotation);
        // model = glm::rotate(model, rotation);
        model *= glm::mat4_cast(rotation);
        model = glm::scale(model, scale);

        return model;
    }

    Transform operator*(const Transform& other) const 
    {
        return Transform
        {
            position * other.position,
            rotation * other.rotation,
            scale * other.scale};
        }
};