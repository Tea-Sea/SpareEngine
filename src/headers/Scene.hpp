#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp> 
#include <vector>
#include <string>

class Scene
{
	public:
	
        Scene();
		
		Scene(std::string src);

		~Scene();

		const std::vector<GameObject*>& getObjectList() const;

		GameObject* searchObjectByID(int ID);


	private:
		
		std::vector<GameObject*> objectList;

		bool addObjectToList(GameObject* objectToAdd);

		bool removeObjectFromList(GameObject* objectToRemove);

};