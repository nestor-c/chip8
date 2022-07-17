#ifndef SPEAKER_H
#define SPEAKER_H
#include <string>
#include <iostream>
#include "SDL.h"

class Speaker{
	public:
	~Speaker();
	Speaker();
	void play();
	void pause();
	void setup(char* myAudio);
	
	
	private:
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioSpec specs;
	SDL_AudioDeviceID deviceID;
};
#endif