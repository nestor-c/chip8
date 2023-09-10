#ifndef SPEAKER_H
#define SPEAKER_H
#include <string>
#include <iostream>
#include </usr/local/opt/sdl2/include/SDL2/SDL.h>

class Speaker{
	public:
	~Speaker();
	Speaker();
	void play(int frequency = FREQUENCY);
	void pause();
	void setup();
	std::string dToB(int n);
	const static int SAMPLE_RATE = 44100;
	const static int AMPLITUDE = 28000;
	const static int FREQUENCY = 440;
	const static int DURATION = 2000;
	const static int SAMPLES_PER_CYCLE = SAMPLE_RATE / FREQUENCY;
	
	private:
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioSpec specs, haveSpecs;
	SDL_AudioDeviceID deviceID;
	SDL_AudioFormat Format;
	uint audioPlayTime();
};
#endif