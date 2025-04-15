#pragma once

#include "../utils/Geometry.hpp"
#include "GameObject.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>
#include <vector>
#include <memory>


class Renderer
{
	public:
		Renderer();

		Renderer(SDL_Window* window);

		~Renderer();

		bool renderLoop(SDL_Window* window, std::vector<std::unique_ptr<GameObject>>& objects);

		// 2D
		bool drawPixel(Vector2 &pos, int colour);
		bool drawTriangle(Vector2 &p1, Vector2 &p2, Vector2 &p3, int colour);

		// 3D
		bool drawPoint(Vector3 &pos, int colour);
		bool drawTriangle(Vector3 &p1, Vector3 &p2, Vector3 &p3, int colour);


	private:

	SDL_Renderer* renderer;

	unsigned int shaderProgram;

	GLuint VAO, VBO, vertexShader;

	std::vector<float>* vertices;

	void beginFrame();

	void endFrame(SDL_Window* window);

};
