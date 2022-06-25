#include "BallScript.h"

void BallScript::startScript() {

}

void BallScript::tickScript(float deltaTime) {

	cout << "tick ball" << endl;

	ComponentHandle<Transform> transform = entity->get<Transform>();

	transform->position += currDir * deltaTime / 2.f;

	if (transform->position.x < 0) currDir.x = 1;
	if (transform->position.x > limits.x) currDir.x = -1;
	if (transform->position.y < 0) currDir.y = 1;

	if (transform->position.y > limits.x) {

		transform->position = limits / 2.f;
		currDir = glm::vec2(0.f, 1.0f);

	}

}