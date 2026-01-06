#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glpong/drawablerect.hpp>

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
	glpong::drawablerect plr(15, 100, window, projectionMatrix);
	plr.position.x = 0.0f;
	plr.position.y = 0.0f;

	//// Render Loop ////
	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		plr.draw();

		glfwSwapBuffers(window);

	}

	glfwTerminate();

	return 0;

}