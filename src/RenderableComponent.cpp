#include "headers/RenderableComponent.hpp"


RenderableComponent::RenderableComponent()
{
    Mesh* mesh = new Mesh();
    // Material* material  new Material();
}

RenderableComponent::~RenderableComponent()
{

}

Mesh* RenderableComponent::getMesh()
{
    return mesh;
}
