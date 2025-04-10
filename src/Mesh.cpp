#include "headers/Mesh.hpp"

Mesh::Mesh()
{

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };  

    
    // // TEST CUBE
    // std::vector<float> vertices {
    //     -1, -1,  0.5, //0
    //      1, -1,  0.5, //1
    //     -1,  1,  0.5, //2
    //      1,  1,  0.5, //3
    //     -1, -1, -0.5, //4
    //      1, -1, -0.5, //5
    //     -1,  1, -0.5, //6
    //      1,  1, -0.5  //7
    // };

    // std::vector<float> indices {
    //     //Top
    //     2, 6, 7,
    //     2, 3, 7,

    //     //Bottom
    //     0, 4, 5,
    //     0, 1, 5,

    //     //Left
    //     0, 2, 6,
    //     0, 4, 6,

    //     //Right
    //     1, 3, 7,
    //     1, 5, 7,

    //     //Front
    //     0, 2, 3,
    //     0, 1, 3,

    //     //Back
    //     4, 6, 7,
    //     4, 5, 7
    // };
}

Mesh::~Mesh()
{
}

std::vector<float>* Mesh::getVertices()
{
    return &vertices;
}

std::vector<int>* Mesh::getIndices()
{
    return &indices;
}