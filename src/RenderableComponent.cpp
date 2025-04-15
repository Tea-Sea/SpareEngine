#include "headers/RenderableComponent.hpp"


RenderableComponent::RenderableComponent()
{
    mesh = new Mesh();
    // Material* material  new Material();
    shader = new Shader("orange.glsl");
}

RenderableComponent::~RenderableComponent()
{

}

Mesh* RenderableComponent::getMesh()
{
    return mesh;
}
