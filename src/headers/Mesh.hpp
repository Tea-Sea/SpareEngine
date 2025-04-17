#pragma once

#include "Shader.hpp"
#include "../utils/Geometry.hpp"

#include <vector>
#include <glad/glad.h>
#include <string>

#include <iostream>

class Mesh
{
	public:
	
		Mesh();

		Mesh(std::string src);

        Mesh(const std::vector<Vertex>& verts, const std::vector<int>& inds);

		~Mesh();

        std::vector<Vertex>* getVertices();

        std::vector<int>* getIndices();

        void draw(Shader* shader) const;

	private:

        bool uploaded;

        std::vector<Vertex> vertices;

        std::vector<int> indices;

        GLuint vao = 0;
        GLuint vbo = 0;
        GLuint ebo = 0;

        void uploadToGPU();

};
