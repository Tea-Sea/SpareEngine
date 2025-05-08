#pragma once

#include "GameObject.hpp"

#include <glm/glm.hpp>

class Camera : public GameObject
{
	public:

	
		Camera();

		~Camera();

		glm::mat4 getViewMatrix() const;

		glm::mat4 getProjectionMatrix() const;

		glm::mat4 getViewProjectionMatrix() const;

		glm::mat4 calculateViewMatrix();
		
		glm::mat4 calculateProjectionMatrix();

		glm::mat4 calculateViewProjectionMatrix();

		void setAspectRatio(float x, float y);
		void update(float dealtaTime);
		
	private:

		GameObject* attachedTo = nullptr;

		glm::mat4 view = glm::mat4{0.0f};
		
		glm::mat4 projection = glm::mat4{0.0f};

		float pitch = 0.0f;
		float fov = 60.0f;
		float aspect = (800.0f / 600.0f);
		float nearClip = 0.1f;
		float farClip = 100.0f;


};
