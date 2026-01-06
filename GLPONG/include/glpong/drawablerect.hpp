#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace glpong {

	class drawablerect {

		private:


		const char* vertexShaderSource = R"(

			#version 330 core

			layout (location = 0) in vec2 vertexPosition;

			uniform mat4 modelMatrix;
			uniform mat4 projectionMatrix;
	
			void main() {
				gl_Position = projectionMatrix * modelMatrix * vec4(vertexPosition.xy, 0.0f, 1.0f);
				gl_Position.z = 0.0f;
			}

		)";

		const char* fragmentShaderSource = R"(

			#version 330 core

			out vec4 FragmentColor;
	
			void main() {
				FragmentColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
			}

		)";


		glm::mat4 projectionMatrix;
		float vertices[8] = {};

		unsigned int indices[6] = {
			2, 3, 1,
			1, 0, 2
		};

		float width = 0.0f;
		float height = 0.0f;

		GLuint VAO;
		GLuint VBO;
		GLuint EBO;
		GLuint shader;

		// Just so I remember, call generateVertices(), then generateShaders(), then generateBuffers().

		protected:

		GLFWwindow* window = nullptr;

		void generateVertices();
		void generateBuffers();
		void generateShaders();

		public:

		glm::vec2 position = { 0.0f, 0.0f };

		drawablerect(float width, float height, GLFWwindow* window, const glm::mat4& projectionMatrix);
		~drawablerect();

		void draw();

		void setProjectionMatrix(const glm::mat4& projectionMatrix);

		float getWidth();
		float getHeight();


	};

}