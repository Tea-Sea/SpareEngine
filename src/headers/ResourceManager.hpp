#pragma once

#include "Shader.hpp"
#include "Texture.hpp"
#include "Mesh.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <vector>
#include <unordered_map>
#include <filesystem>

class ResourceManager
{
	public:

        ResourceManager();

		~ResourceManager();

        void loadShader(std::string name, std::string vertexSrc, std::string fragSrc);

        Shader* getShader(const std::string& name);

        void loadTexture(std::string name, std::string textureSrc);

        Texture* getTexture(const std::string& name);

        void loadMesh(std::string name, std::string meshSrc);

        Mesh* getMesh(const std::string& name);

        void loadAll();


	private:

    std::unordered_map<std::string, Shader> shaders;

    std::unordered_map<std::string, Texture> textures;

    std::unordered_map<std::string, Mesh> meshes;

};