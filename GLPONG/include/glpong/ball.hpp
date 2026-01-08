#pragma once
#include <glpong/enemy.hpp>


namespace glpong {

	class ball : public player {

		private:

		player& gamePlr;
		enemy& gameEnemy;

		public:

		glm::vec2 direction = { -1.0f, 1.0f };

		ball(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix, player& plr, enemy& enemy);
		
		void doCollisionsOnPlr();
		void doCollisionsOnEnemy();
		virtual void update(float deltaTime) override;


	};

}