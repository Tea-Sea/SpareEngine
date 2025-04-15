#pragma once

#include "Mesh.hpp"
#include "Shader.hpp"

class RenderableComponent
{
	public:
	
		RenderableComponent();

		~RenderableComponent();

        Mesh* getMesh();

        Shader* getShader();
		
	private:

    Mesh* mesh;
	// Material* material;
	Shader* shader;

};