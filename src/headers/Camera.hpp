#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp>

class Camera : public GameObject
{
	public:
		float pitch = 0.0f;
		float fov = 60.0f;
		float aspect = (800.0f / 600.0f);
		float nearClip = 0.1f;
		float farClip = 100.0f;
	
		Camera();

		~Camera();

		glm::mat4 getViewMatrix() const;
		
		glm::mat4 getProjectionMatrix() const;

		glm::mat4 getViewProjectionMatrix() const;

		
	private:

		GameObject* attachedTo = nullptr;

		glm::mat4 view;
		
		glm::mat4 projection;


};
