#pragma once
#include <glpong/drawablerect.hpp>


namespace glpong {

	class player : public drawablerect {
		
		public:

		float speed = 250.0f;

		player(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix);

		void update(float deltaTime);

	};

}