#include "Script.h"

Script::Script(Entity* entity) {
	this->entity = entity;
}

void Script::startScript()
{
	
	cout << "start" << endl;
	
}

void Script::tickScript(float deltaTime)
{
	cout << "update" << endl;
}
