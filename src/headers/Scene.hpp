#pragma once

#include "GameObject.hpp"
#include "TestObject.hpp"

#include <glm/glm.hpp> 
#include <vector>
#include <memory>
#include <string>

class Scene
{
	public:
	
		Scene(int id);
		
		Scene(std::string src);

		~Scene();

		std::vector<std::unique_ptr<GameObject>>& getObjectList();

		GameObject& searchObjectByID(int ID);

		const int& getSceneID() const;

		const std::string& getSceneName() const;

		void setSceneName(std::string newName);


	private:
	
		int ID;

		std::string name;

		std::vector<std::unique_ptr<GameObject>> objectList;

		bool addObjectToList(GameObject objectToAdd);

		bool removeObjectFromList(GameObject* objectToRemove);

};