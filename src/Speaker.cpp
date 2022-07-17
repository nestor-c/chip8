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
	
	if((deviceID = SDL_OpenAudioDevice(NULL,0,&specs,NULL,0)) == 0){
		printf("SDL_OpenAudioDevice Failed: %s\n",SDL_GetError());
	}
};

Speaker::~Speaker(){

};

void Speaker::play(){
	if(SDL_QueueAudio(deviceID,wavBuffer,wavLength) < 0){
		printf("SDL_QueueAudio Failed: %s\n",SDL_GetError());
	}
	SDL_PauseAudioDevice(deviceID, 0);
	
	while(wavLength > 0){
		SDL_Delay(100);
	};
};

void Speaker::pause(){
	SDL_PauseAudioDevice(deviceID, 1);
};