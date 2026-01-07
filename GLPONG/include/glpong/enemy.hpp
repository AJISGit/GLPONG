#pragma once
#include <glpong/player.hpp>


namespace glpong {

	class enemy : public player {

		public:

		enemy(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix);

		virtual void update(float deltaTime) override;

	};

}