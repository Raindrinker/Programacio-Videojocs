#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Texture.h"
#include "SpriteRenderer.h"
#include "RenderSystem.h"
#include "ScriptManager.h"
#include "BallScript.h"
#include "Script.h"

#include "ECS.h"

using std::cout; 
using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
using namespace ECS;

GLFWwindow* window; // Game window
const unsigned int width = 800;
const unsigned int height = 800;

float t = 0;
time_t current_time;

World* world;
ScriptManager scriptManager;


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
	glViewport(0, 0, width, height);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

Entity* CreateEntity(glm::vec2 position, float rotation, float scale, const char* filepath, glm::vec3 color) {
	Entity* ent = world->create();
	ent->assign<Transform>(position, rotation, scale);
	ent->assign<Sprite>(filepath, color);

	return ent;
}

void SetupWorld() {

	world = World::createWorld();
	world->registerSystem(new RenderSystem(width, height));

	Entity* paddle_ent = CreateEntity(glm::vec2(400.f, 700.f), 0.f, 1.f, "Textures/button_yellow.png", glm::vec3(1., 1., 1.));

	Entity* ball_ent = CreateEntity(glm::vec2(400.f, 400.f), 0.f, 1.f, "Textures/ball_blue_small.png", glm::vec3(1., 1., 1.));

	BallScript* script = new BallScript(ball_ent);
	scriptManager.AddScript(script);
}

int main() {
	
	SetupGLFW();

	if (!SetupWindow()) {
		return -1;
	}

	SetupWorld();

	float dt = 0;
	float time = clock();

	//Program core loop
	while (!glfwWindowShouldClose(window)) {

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);

		//sr.DrawSprite(tex, projection, glm::vec2(300.0f, 0.0f), glm::vec2(512, 512));
		//sr.DrawSprite(texBall, projection, glm::vec2(400.0f, 400.0f), texBall.GetSize());

		dt = clock() - time;
		time = clock();
		if (dt < 50) {
			world->tick(dt);
			scriptManager.tick(dt);
		}

		std::cout << "tick" << std::endl;
		std::cout << dt << std::endl;

		glfwSwapBuffers(window); //Swap buffers

		// Take care of GLFW events
		glfwPollEvents();
	}

	// Cleanup

	glfwDestroyWindow(window);
	glfwTerminate();

	world->destroyWorld();

	return 0;
}