#include "ScriptRotate.h"



ScriptRotate::ScriptRotate(GLFWwindow* window, World* world, Entity* entity, Entity* camera)
{
	this->window = window;
	this->entity = entity;
	this->world = world;
	this->camera = camera;
}

void ScriptRotate::startScript() {

}

void ScriptRotate::tickScript(float deltaTime) {

	ComponentHandle<Transform3D> myTransform = entity->get<Transform3D>();

	myTransform->rotation.y += deltaTime/1000.0f;
	myTransform->rotation.x += deltaTime/2000.0f;

}