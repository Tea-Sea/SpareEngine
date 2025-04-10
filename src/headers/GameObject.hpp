#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "MeshComponent.hpp"

class GameObject
{
	public:
	
		GameObject();

		~GameObject();

        MeshComponent* getMeshComponent();
		
	private:

    MeshComponent* meshComponent;

};

#endif