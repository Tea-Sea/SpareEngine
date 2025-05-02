#include "headers/Material.hpp"

Material::Material()
{
    shader = new Shader("vertex.glsl", "orange.glsl");
    // texture = new Texture("container.jpg");
    // std::unordered_map<std::string, UniformValue> uniforms;
}

Material::~Material()
{
}

Shader* Material::getShader()
{
    return shader;
}

Texture* Material::getTexture()
{
    return texture;
}