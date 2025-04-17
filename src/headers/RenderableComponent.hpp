#pragma once

#include "Mesh.hpp"
#include "Material.hpp"

class RenderableComponent
{
	public:
	
		RenderableComponent();

		~RenderableComponent();

        Mesh* getMesh();

        Material* getMaterial();
		
	private:

    Mesh* mesh;
	Material* material;

};