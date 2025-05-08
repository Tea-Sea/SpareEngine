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
    glm::vec3 position = {0.0f,0.0f,0.0f};
    glm::vec3 normal = {0.0f,0.0f,0.0f};
    glm::vec2 uv = {0.0f,0.0f};
};

struct Transform 
{
    glm::vec3 position = glm::vec3{0.0f};
    glm::quat rotation = glm::quat{1.0f,0.0f,0.0f,0.0f};
    glm::vec3 scale = glm::vec3{1.0f};
    
    glm::vec3 eulerRotation = glm::vec3{0.0f}; //optional

    glm::mat4 getModelMatrix()
    {
        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, position);
        model *= glm::mat4_cast(rotation);
        model = glm::scale(model, scale);

        return model;
    }

    Transform operator*(const Transform& other)
    {
        Transform result;
        result.position = position + (rotation * other.position);
        result.rotation = rotation * other.rotation;
        result.scale = scale * other.scale;
        return result;
    }
};