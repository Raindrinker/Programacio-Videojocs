#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	
	glfwInit();

	// Tell GLFW we are using OpenGL 3.3 and the CORE profile (only the modern functions)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a GLFWwindow with size 800x800
	GLFWwindow* window = glfwCreateWindow(800, 800, "ProgramacioVideojocs", NULL, NULL);
	if (window == NULL) {

		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make window part of the current context
	glfwMakeContextCurrent(window); 

	//Load GLAD and specify the viewport
	gladLoadGL();
	glViewport(0, 0, 800, 800); 

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //Clear back buffer with blue
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window); //Swap buffers

	//Program core loop
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}