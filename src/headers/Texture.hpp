#pragma once

#include <glad/glad.h>
#include <string>
#include <iostream>

class Texture
{
	public:
	
        Texture();

        Texture(std::string path);

		~Texture();

		GLuint getTextureID();
		
	private:

	GLuint textureID;
};
