#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glpong/enemy.hpp>
#include <glpong/ball.hpp>

#ifdef _DEBUG
#include <iostream>
#endif


const int initialWindowWidth = 800;
const int initialWindowHeight = 600;



int main() {

	//// Initilization Stuff ////
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = glfwCreateWindow(initialWindowWidth, initialWindowHeight, "GLPONG", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
		#ifdef _DEBUG

		std::cerr << "Failed to initilize opengl\n";

		#endif
		return 1;
	}

	glViewport(0, 0, initialWindowWidth, initialWindowHeight);

	glm::mat4 projectionMatrix = glm::ortho(0.0f, static_cast<float>(initialWindowWidth), static_cast<float>(initialWindowHeight), 0.0f, 0.1f, 10.0f);
	glpong::player plr(15, 100, window, projectionMatrix);
	glpong::enemy enemy(15, 100, window, projectionMatrix);
	glpong::ball ball(15, 15, window, projectionMatrix);

	//// Render Loop ////

	float lastFrameTime = static_cast<float>(glfwGetTime());

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		float currentFrameTime = static_cast<float>(glfwGetTime());
		float deltaTime = currentFrameTime - lastFrameTime;
		lastFrameTime = currentFrameTime;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		plr.update(deltaTime);
		plr.draw();
		ball.update(deltaTime);
		enemy.update(deltaTime);
		enemy.draw();
		ball.draw();

		glfwSwapBuffers(window);

	}

	glfwTerminate();

	return 0;

}