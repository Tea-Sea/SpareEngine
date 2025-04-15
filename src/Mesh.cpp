#include "headers/Mesh.hpp"

Mesh::Mesh() : uploaded(false)
{    
    // TEST CUBE
    vertices = {
        -1, -1,  0.5, //0
         1, -1,  0.5, //1
        -1,  1,  0.5, //2
         1,  1,  0.5, //3
        -1, -1, -0.5, //4
         1, -1, -0.5, //5
        -1,  1, -0.5, //6
         1,  1, -0.5  //7
    };

    indices = {
        //Top
        2, 6, 7,
        2, 3, 7,

        //Bottom
        0, 4, 5,
        0, 1, 5,

        //Left
        0, 2, 6,
        0, 4, 6,

        //Right
        1, 3, 7,
        1, 5, 7,

        //Front
        0, 2, 3,
        0, 1, 3,

        //Back
        4, 6, 7,
        4, 5, 7
    };
    uploadToGPU();
}

Mesh::Mesh(std::string src) : uploaded(false)
{

}

Mesh::Mesh(const std::vector<float>& verts, const std::vector<int>& inds)
        : vertices(verts), indices(inds), uploaded(false)
{

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

void Mesh::uploadToGPU() {
    if (uploaded) return;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // EBO
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex attribute: positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // Done
    glBindVertexArray(0);
    uploaded = true;
}

void Mesh::draw(Shader* shader) const {
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}