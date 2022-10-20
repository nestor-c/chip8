#include "headers/Speaker.h"

Speaker::Speaker(){
	if (SDL_Init(SDL_INIT_AUDIO) < 0){
		std::cout << "Failed to initialize audio" << std::endl;
	};
};

void Speaker::setup(std::string myAudio){
	if(SDL_LoadWAV(myAudio.c_str(),&specs,&wavBuffer,&wavLength) == NULL ){
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
	SDL_FreeWAV(wavBuffer);
	std::cout << audioPlayTime()<< std::endl;  
	SDL_Delay(audioPlayTime());
};

void Speaker::pause(){
	SDL_PauseAudioDevice(deviceID, 1);
};

uint Speaker::audioPlayTime(){
	int bytesPerSample = SDL_AUDIO_BITSIZE(specs.format)/8;
	int freq = specs.freq;
	int wavLengthMono = wavLength/2;
	int second = 1000;
	
	try {
		return 	(wavLengthMono/bytesPerSample/freq)*second;
	} catch (std::runtime_error& e){
			std::cout << "Exception occurred"<< std::endl;
			return -1;
	}

	}; 