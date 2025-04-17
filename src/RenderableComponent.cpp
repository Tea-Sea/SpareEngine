#include "headers/RenderableComponent.hpp"


RenderableComponent::RenderableComponent()
{
    mesh = new Mesh();
    material = new Material();
    
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
