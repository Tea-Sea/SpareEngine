#pragma once

#include "Mesh.hpp"

class MeshComponent
{
	public:
	
		MeshComponent();

		~MeshComponent();

        MeshComponent* getMeshComponent();
		
	private:

    Mesh* mesh;

};