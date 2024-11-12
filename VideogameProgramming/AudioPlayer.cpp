#include "AudioPlayer.h"

void AudioPlayer::Init() {

	BASS_Init(-1, 44100, 0, 0, NULL);
	BASS_SetVolume(0.5f);
}

void AudioPlayer::PlayAudio(string path, bool loop = false)
{
	LPCSTR sw = path.c_str();
	
	if (loop) {
		HSAMPLE sample = BASS_SampleLoad(false, sw, 0, 0, 1, BASS_SAMPLE_MONO | BASS_SAMPLE_LOOP);
		HCHANNEL channel = BASS_SampleGetChannel(sample, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
	else {
		HSAMPLE sample = BASS_SampleLoad(false, sw, 0, 0, 1, BASS_SAMPLE_MONO);
		HCHANNEL channel = BASS_SampleGetChannel(sample, FALSE);
		BASS_ChannelPlay(channel, FALSE);
	}
}
