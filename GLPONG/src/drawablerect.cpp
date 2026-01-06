#include <glpong/drawablerect.hpp>


void glpong::drawablerect::generateVertices() {

	// Top Left
	vertices[0] = 0.0f; // x
	vertices[1] = 0.0f; // y

	// Top Right
	vertices[2] = width; // x
	vertices[3] = 0.0f; // y

	// Bottom Left
	vertices[4] = 0.0f; // x
	vertices[5] = height; // y

	// Bottom Right
	vertices[6] = width; // x
	vertices[7] = height; // y

}


void glpong::drawablerect::generateBuffers() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);


}


void glpong::drawablerect::generateShaders() {

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	shader = glCreateProgram();
	glAttachShader(shader, vertexShader);
	glAttachShader(shader, fragmentShader);
	glLinkProgram(shader);

	glUseProgram(shader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}


glpong::drawablerect::drawablerect(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix) {

	this->width = width;
	this->height = height;
	this->window = window;

	position.x = 0.0f;
	position.y = 0.0f;
	
	setProjectionMatrix(projectionMatrix);
	generateVertices();
	generateShaders();
	generateBuffers();

}


glpong::drawablerect::~drawablerect() {

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	glDeleteProgram(shader);

}


void glpong::drawablerect::draw() {

	glUseProgram(shader);

	glm::mat4 modelMatrix(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(position.x, position.y, 0.0f));

	glUniformMatrix4fv(glGetUniformLocation(shader, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
	glUniformMatrix4fv(glGetUniformLocation(shader, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

}


void glpong::drawablerect::setProjectionMatrix(const glm::mat4& projectionMatrix) {
	this->projectionMatrix = projectionMatrix;
}
