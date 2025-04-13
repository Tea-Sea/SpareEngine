#pragma once

#include "Mesh.hpp"

class RenderableComponent
{
	public:
	
		RenderableComponent();

		~RenderableComponent();

        Mesh* getMesh();
		
	private:

    Mesh* mesh;
	// Material* material;

};