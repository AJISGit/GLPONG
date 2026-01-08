#include <glpong/ball.hpp>


glpong::ball::ball(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix) : glpong::player::player(width, height, window, projectionMatrix) {

	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	position.x = static_cast<float>(windowWidth / 2.0f);
	position.y = static_cast<float>(windowHeight / 2.0f);
	speed = 100.0f;

}


void glpong::ball::update(float deltaTime) {

	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	position.x += speed * direction.x * deltaTime;
	position.y += speed * direction.y * deltaTime;


	if (position.x < 0.0f) {
		position.x = 0.0f;
	} else if (position.x > windowWidth - getWidth()) {
		position.x = windowWidth - getWidth();
	}

	if (position.y < 0.0f) {
		position.y = 0.0f;
	} else if (position.y > windowHeight - getHeight()) {
		position.y = windowHeight - getHeight();
	}

}
