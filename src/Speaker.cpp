#include "Speaker.h"

Speaker::Speaker(){
	if (SDL_Init(SDL_INIT_AUDIO) < 0){
		std::cout << "Failed to initialize audio" << std::endl;
	};
};

void Speaker::setup(char* myAudio){
	if(SDL_LoadWAV(myAudio,&specs,&wavBuffer,&wavLength) == NULL ){
		printf("SDL_LoadWav Failed: %s\n",SDL_GetError());
	}

	SDL_AudioDeviceID deviceID;
	
	if((deviceID = SDL_OpenAudioDevice(NULL,0,&specs,NULL,0)) == 0){
		printf("SDL_OpenAudioDevice Failed: %s\n",SDL_GetError());
	}
	
// play audio
	int success = SDL_QueueAudio(deviceID, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceID, 0);
};

Speaker::~Speaker(){

};

void Speaker::play(){
	SDL_PauseAudio(0);
};

void Speaker::pause(){
	SDL_PauseAudio(1);
};