#include <glpong/enemy.hpp>


glpong::enemy::enemy(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix) : glpong::player::player(width, height, window, projectionMatrix) {

	int windowWidth = 0;
	int windowHeight = 0;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	position.x = windowWidth - getWidth();

}

void glpong::enemy::update(float deltaTime) {

	

}
