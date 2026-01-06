#include <glpong/player.hpp>


glpong::player::player(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix) : glpong::drawablerect::drawablerect(width, height, window, projectionMatrix) {



}


void glpong::player::update(float deltaTime) {

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position.y -= speed * deltaTime;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position.y += speed * deltaTime;
	}

	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	if (position.y < 0.0f) {
		position.y = 0.0f;
	} else if (position.y > windowHeight - getHeight()) {
		position.y = windowHeight - getHeight();
	}


}
