#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

// Vertices coordinates
GLfloat equilateral_triangle[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
};

GLfloat right_triangle[] =
{
	-0.5f, -0.5f, 0.0f, // Lower left corner
	0.5f, -0.5f, 0.0f, // Lower right corner
	0.5f, 0.5f, 0.0f // Upper corner
};

GLFWwindow* window; // Game window
GLuint shaderProgram; // Shader program
GLuint VAO; //Array of VBOs that store the information of a complete rendered object
GLuint VBO; //Memory buffer tha tholds informationa bout vertices

void SetupGLFW() {

	glfwInit();

	// Tell GLFW we are using OpenGL 3.3 and the CORE profile (only the modern functions)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

bool SetupWindow() {
	//Create a GLFWwindow with size 800x800
	window = glfwCreateWindow(800, 800, "ProgramacioVideojocs", NULL, NULL);
	if (window == NULL) {

		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Make window part of the current context
	glfwMakeContextCurrent(window);

	//Load GLAD and specify the viewport
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	return true;
}

void SetupShaders() {

	// Create vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// Create fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Create shader program and attach shaders to it
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	// Delete non-program references to the shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void SetupVertexData(GLfloat data[], int len) {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * len, data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

int main() {
	
	SetupGLFW();

	if (!SetupWindow()) {
		return -1;
	}

	SetupShaders();

	SetupVertexData(equilateral_triangle, 9);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //Clear back buffer with blue
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window); //Swap buffers

	//Program core loop
	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //Clear back buffer with blue
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram); //Select shader program
		glBindVertexArray(VAO); // Bind VAO to use

		glDrawArrays(GL_TRIANGLES, 0, 3); //Interpret the information in the VAO as triangles, starting at index 0, and drawing 3 vertices.

		glfwSwapBuffers(window); //Swap buffers

		// Take care of GLFW events
		glfwPollEvents();
	}

	// Cleanup
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}