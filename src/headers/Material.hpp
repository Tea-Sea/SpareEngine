#pragma once

#include "Shader.hpp"
#include "Texture.hpp"

class Material
{
	public:
	
		Material();

		~Material();

        Shader* getShader();

        Texture* getTexture();
		
	private:

    Shader* shader;

    Texture* texture;
};
