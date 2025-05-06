#pragma once

#include "Shader.hpp"
#include "Texture.hpp"

class Material
{
	public:
	
		Material();

        Material(Shader* shader, Texture* texture);

		~Material();

        Shader* getShader();

        Texture* getTexture();

        GLuint getShaderID();

        GLuint getTextureID();

        void setShader(Shader* newShader);

        void setTexture(Texture* newTexture);
		
	private:

    Shader* shader;

    Texture* texture;
};
