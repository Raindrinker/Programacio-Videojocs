#include "BlockScript.h"
#include "AudioPlayer.h"

void BlockScript::tickScript(float deltaTime) {

	if (destroyed) return;

	ComponentHandle<BoxCollider> collider = entity->get<BoxCollider>();

	if (collider->collidedWith) {
		hp--;
		collider->collidedWith = false;

		if (hp <= 0) {
			destroyed = true;
			world->destroy(entity);

			AudioPlayer::PlayAudio("./Audio/hit.wav", false);
		}
	}

}