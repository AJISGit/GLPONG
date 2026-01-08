#pragma once
#include <glpong/player.hpp>


namespace glpong {

	class ball : public player {

		public:

		glm::vec2 direction = { -1.0f, 1.0f };

		ball(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix);

		virtual void update(float deltaTime) override;

	};

}