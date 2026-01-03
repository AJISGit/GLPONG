#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef _DEBUG
#include <iostream>
#endif


const int initialWindowWidth = 800;
const int initialWindowHeight = 600;

const char* vertexShaderSource = R"(
	#version 330 core

	layout (location = 0) in vec3 vertexPosition;
	
	void main() {
		gl_Position = vec4(vertexPosition.xyz, 1.0f);
	}

)";

const char* fragmentShaderSource = R"(
	#version 330 core

	out vec4 FragmentColor;
	
	void main() {
		FragmentColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

)";



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

	//// Shader Stuff ////
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//// Vertex Buffer Stuff ////
	float vertexInput[] = {
		0.0f, 0.5f, 0.0f, // Top
		-0.5f, -0.5f, 0.0f, // Bottom Left
		0.5f, -0.5f, 0.0f // Top Left
	};

	GLuint VAO;
	GLuint VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexInput), vertexInput, GL_STATIC_DRAW);

	//// Vertex Attributes ////
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*) 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//// Render Loop ////
	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

	}

	glfwTerminate();

	return 0;

}