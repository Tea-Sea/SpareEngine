#pragma once

#include "Scene.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <vector>

class ResourceManager
{
	public:
	
        ResourceManager();

		~ResourceManager();

        void LoadShader(std::string* name, std::string* vertexSrc, std::string* fragSrc);

        Shader* getShader(std::string* name);

        void LoadTexture(std::string* name, std::string* textureSrc);

        Texture* getTexture(std::string* name);

        void LoadMesh(std::string* name, std::string* meshSrc);

        Mesh* getMesh(std::string* name);


	private:
	
};