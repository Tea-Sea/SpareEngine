#pragma once

#include "Shader.hpp"

#include <unordered_map>

class Material
{
	public:
	
		Material();

		~Material();

        Shader* getShader();
		
	private:

    Shader* shader;

    // std::unordered_map<std::string, UniformValue> uniforms;

};
