#pragma once

#include "GameObject.hpp"
#include "TestObject.hpp"
#include "Player.hpp"
#include "Camera.hpp"
#include "ResourceManager.hpp"
#include "../utils/RenderData.hpp"

#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <string>

class Scene
{
	public:

		Scene(ResourceManager resources, int id);

		Scene(std::string src);

		~Scene();

		std::vector<std::unique_ptr<GameObject>>& getObjectList();

		GameObject& searchObjectByID(int ID);

		const int& getSceneID() const;

		Camera* getCamera() const;

		const std::string& getSceneName() const;

		void setSceneName(std::string newName);

		RenderData prepareRenderData();

		virtual void update(float deltaTime);


	private:

		int ID;

		std::string name;

		std::vector<std::unique_ptr<GameObject>> objectList;

		Camera* camera;

		bool addObjectToList(GameObject* objectToAdd);

		bool removeObjectFromList(GameObject* objectToRemove);

};