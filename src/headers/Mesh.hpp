#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh
{
	public:
	
		Mesh();

		~Mesh();

        std::vector<float>* getVertices();
        std::vector<int>* getIndices();
		
	private:

    std::vector<float> vertices;
    std::vector<int> indices;

};

#endif
