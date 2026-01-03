#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef _DEBUG
#include <iostream>
#endif


const int initialWindowWidth = 800;
const int initialWindowHeight = 600;


void windowResized(GLFWwindow* window, int width, int height) {
	
	glViewport(0, 0, width, height);

}


int main() {

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

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

	}

	glfwTerminate();

	return 0;

}