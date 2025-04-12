#include "headers/MeshComponent.hpp"


MeshComponent::MeshComponent()
{
    Mesh* mesh = new Mesh();
}

MeshComponent::~MeshComponent()
{

}

MeshComponent* MeshComponent::getMeshComponent()
{
    return this;
}
