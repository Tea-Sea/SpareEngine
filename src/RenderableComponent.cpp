#include "headers/RenderableComponent.hpp"


RenderableComponent::RenderableComponent()
{
    mesh = new Mesh();
    material = new Material(new Shader("orange"), new Texture());
    
}

RenderableComponent::~RenderableComponent()
{

}

Mesh* RenderableComponent::getMesh()
{
    return mesh;
}

Material* RenderableComponent::getMaterial()
{
    return material;
}

void RenderableComponent::attachMesh(Mesh* newMesh)
{
    mesh = newMesh;
}

void RenderableComponent::attachMaterial(Material* newMaterial)
{
    material = newMaterial;
}

