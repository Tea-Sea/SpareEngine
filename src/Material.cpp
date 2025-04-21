#include "headers/Material.hpp"

Material::Material()
{
    shader = new Shader("vertex.glsl", "test.glsl");
    // std::unordered_map<std::string, UniformValue> uniforms;
}

Material::~Material()
{
}

Shader* Material::getShader()
{
    return shader;
}