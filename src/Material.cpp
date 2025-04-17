#include "headers/Material.hpp"

Material::Material()
{
    shader = new Shader("orange.glsl");
    // std::unordered_map<std::string, UniformValue> uniforms;
}

Material::~Material()
{
}

Shader* Material::getShader()
{
    return shader;
}