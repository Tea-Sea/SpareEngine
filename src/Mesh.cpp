#include "headers/Mesh.hpp"

Mesh::Mesh() : uploaded(false)
{    
    // TEST CUBE
    vertices = {
        // FRONT (+Z)
        { {-0.5f, -0.5f,  0.5f}, {0, 0, 1}, {0, 0} },  // bottom-left
        { { 0.5f, -0.5f,  0.5f}, {0, 0, 1}, {1, 0} },  // bottom-right
        { { 0.5f,  0.5f,  0.5f}, {0, 0, 1}, {1, 1} },  // top-right
        { {-0.5f,  0.5f,  0.5f}, {0, 0, 1}, {0, 1} },  // top-left
        
        // BACK (-Z)
        { { 0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 0} },
        { {-0.5f, -0.5f, -0.5f}, {0, 0, -1}, {1, 0} },
        { {-0.5f,  0.5f, -0.5f}, {0, 0, -1}, {1, 1} },
        { { 0.5f,  0.5f, -0.5f}, {0, 0, -1}, {0, 1} },
        
        // LEFT (-X)
        { {-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0} },
        { {-0.5f, -0.5f,  0.5f}, {-1, 0, 0}, {1, 0} },
        { {-0.5f,  0.5f,  0.5f}, {-1, 0, 0}, {1, 1} },
        { {-0.5f,  0.5f, -0.5f}, {-1, 0, 0}, {0, 1} },
        
        // RIGHT (+X)
        { { 0.5f, -0.5f,  0.5f}, {1, 0, 0}, {0, 0} },
        { { 0.5f, -0.5f, -0.5f}, {1, 0, 0}, {1, 0} },
        { { 0.5f,  0.5f, -0.5f}, {1, 0, 0}, {1, 1} },
        { { 0.5f,  0.5f,  0.5f}, {1, 0, 0}, {0, 1} },
        
        // TOP (+Y)
        { {-0.5f,  0.5f,  0.5f}, {0, 1, 0}, {0, 0} },
        { { 0.5f,  0.5f,  0.5f}, {0, 1, 0}, {1, 0} },
        { { 0.5f,  0.5f, -0.5f}, {0, 1, 0}, {1, 1} },
        { {-0.5f,  0.5f, -0.5f}, {0, 1, 0}, {0, 1} },
        
        // BOTTOM (-Y)
        { {-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 0} },
        { { 0.5f, -0.5f, -0.5f}, {0, -1, 0}, {1, 0} },
        { { 0.5f, -0.5f,  0.5f}, {0, -1, 0}, {1, 1} },
        { {-0.5f, -0.5f,  0.5f}, {0, -1, 0}, {0, 1} },
    }; 

    indices = {
       // Front face
        0, 1, 2,  2, 3, 0,
        // Back face
        4, 5, 6,  6, 7, 4,
        // Left face
        8, 9, 10, 10,11,8,
        // Right face
        12,13,14, 14,15,12,
        // Top face
        16,17,18, 18,19,16,
        // Bottom face
        20,21,22, 22,23,20
    };

    uploadToGPU();
}

Mesh::Mesh(std::string src) : uploaded(false)
{

}

Mesh::Mesh(const std::vector<Vertex>& verts, const std::vector<int>& inds)
        : vertices(verts), indices(inds), uploaded(false)
{

}

Mesh::~Mesh()
{
}

std::vector<Vertex>* Mesh::getVertices()
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
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // EBO
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Vertex attribute: positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);      // Position
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(12));   // Normal
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(24));   // UV

    // Done
    glBindVertexArray(0);
    uploaded = true;
}

void Mesh::draw(Shader* shader) const {
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}