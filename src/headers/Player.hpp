#pragma once

#include "GameObject.hpp"

class Player : public GameObject
{
	public:
	
        Player();
		
		Player(glm::vec3 pos, int id);

		~Player();

		void update(float deltaTime);
		
	private:

};
