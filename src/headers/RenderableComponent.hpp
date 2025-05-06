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

		void attachMesh(Mesh* newMesh);

		void attachMaterial(Material* newMaterial);
		
	private:

    Mesh* mesh;
	Material* material;

};