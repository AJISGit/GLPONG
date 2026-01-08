#include <glpong/ball.hpp>
#ifdef _DEBUG
#include <iostream>
#endif


glpong::ball::ball(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix, glpong::player& plr, glpong::enemy& enemy) : glpong::player::player(width, height, window, projectionMatrix),
gamePlr(plr), gameEnemy(enemy) {
	
	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	position.x = static_cast<float>(windowWidth / 2.0f);
	position.y = static_cast<float>(windowHeight / 2.0f);
	speed = 100.0f;

}


void glpong::ball::doCollisionsOnPlr() {
	bool collidingOnTheXAxis = false;
	bool collidingOnTheYAxis = false;

	// NOTE: I only check if the ball is to the left of the ball and not inside of the ball.
	// This is because the player will always be touching the wall.
	// That way, if the ball is to the left of the player, either it's hit the wall and needs to be sent to the center, or it's colliding with the player.

	if (position.x < (gamePlr.position.x + gamePlr.getWidth())) {
		collidingOnTheXAxis = true;
	}

	if (position.y < (gamePlr.position.y + gamePlr.getHeight()) && position.y > gamePlr.position.y) {
		collidingOnTheYAxis = true;
	}

	if (collidingOnTheXAxis && collidingOnTheYAxis) {
		position.x = gamePlr.position.x + gamePlr.getWidth();
		direction.x = -direction.x;
		#ifdef _DEBUG
		std::cout << "Player\n";
		#endif
	}
}


void glpong::ball::doCollisionsOnEnemy() {
	bool collidingOnTheXAxis = false;
	bool collidingOnTheYAxis = false;

	// NOTE: I only check if the ball is to the right of the ball and not inside of the ball.
	// This is because the player will always be touching the wall.
	// That way, if the ball is to the left of the player, either it's hit the wall and needs to be sent to the center, or it's colliding with the player.

	if ((position.x + getWidth()) > gameEnemy.position.x) {
		collidingOnTheXAxis = true;
	}

	//                 Bottom                                           Top
	if (position.y <= (gameEnemy.position.y + gameEnemy.getHeight()) && position.y >= gameEnemy.position.y) {
		collidingOnTheYAxis = true;
	}

	if (collidingOnTheXAxis && collidingOnTheYAxis) {
		position.x = gameEnemy.position.x - gameEnemy.getWidth();
		direction.x = -direction.x;
	}
}


void glpong::ball::update(float deltaTime) {

	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	//// Move the ball ////
	position.x += speed * direction.x * deltaTime;
	position.y += speed * direction.y * deltaTime;

	//// Do collisions ////

	// Window
	if (position.x < 0.0f || position.x > windowWidth - getWidth()) {
		position.x = static_cast<float>(windowWidth / 2);
		direction.x = -direction.x;
	}

	if (position.y < 0.0f || position.y > windowHeight - getHeight()) {
		direction.y = -direction.y;
	}
	
}
