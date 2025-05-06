#include "headers/Material.hpp"

Material::Material(Shader* shader, Texture* texture)
: shader(shader), texture(texture)
{

}

Material::~Material()
{
    delete shader;
    delete texture;
}

Shader* Material::getShader()
{
    return shader;
}

Texture* Material::getTexture()
{
    return texture;
}

GLuint Material::getShaderID()
{
    return shader->getShaderProgram();
}

GLuint Material::getTextureID()
{
    return texture->getTextureID();
}

void Material::setShader(Shader* newShader)
{
    shader = newShader;
}

void Material::setTexture(Texture* newTexture)
{
    texture = newTexture;
}