#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include "Mesh.hpp"

class MeshComponent
{
	public:
	
		MeshComponent();

		~MeshComponent();

        MeshComponent getMeshComponent();
		
	private:

    Mesh* mesh;

};

#endif