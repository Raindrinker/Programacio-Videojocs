#include "AudioPlayer.h"


void AudioPlayer::PlayAudio(string path, bool loop = false)
{
	LPCSTR sw = path.c_str();
	
	if (loop) {
		PlaySound(sw, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else {
		PlaySound(sw, NULL, SND_FILENAME | SND_ASYNC);
	}
}
