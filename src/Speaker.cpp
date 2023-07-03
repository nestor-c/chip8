#include "headers/Speaker.h"

void audioCallback(void* userdata, Uint8* stream, int len){
    int samples = len / 2;
    Sint16* audioBuffer = reinterpret_cast<Sint16*>(stream);
    
    for (int i = 0; i < samples; ++i) {
        // Generate a square wave by toggling between maximum and minimum amplitude
		//Comparison checks what half of the cycle the sample falls in.
        if (i % (Speaker::SAMPLES_PER_CYCLE) < (Speaker::SAMPLES_PER_CYCLE) / 2) {
            audioBuffer[i] = Speaker::AMPLITUDE;
        } else {
            audioBuffer[i] = -(Speaker::AMPLITUDE);
        }
    }
}

Speaker::Speaker(){
	if (SDL_Init(SDL_INIT_AUDIO) < 0){
		std::cout << "Failed to initialize audio" << std::endl;
	};
	SDL_memset(&specs,0,sizeof(specs));
	specs.freq= SAMPLE_RATE;
	specs.format = AUDIO_S16SYS;
	specs.channels = 1;
	specs.samples=4096;
	specs.callback=audioCallback;

	setup();
};

void Speaker::setup(){
	// if(SDL_LoadWAV(myAudio.c_str(),&specs,&wavBuffer,&wavLength) == NULL ){
	// 	printf("SDL_LoadWav Failed: %s\n",SDL_GetError());
	// }
	
	if((deviceID = SDL_OpenAudioDevice(NULL,0,&specs,&haveSpecs,SDL_AUDIO_ALLOW_FORMAT_CHANGE)) == 0){
		printf("SDL_OpenAudioDevice Failed: %s\n",SDL_GetError());
	}
};

Speaker::~Speaker(){
};

void Speaker::play(int frequency){
	// if(SDL_QueueAudio(deviceID,wavBuffer,wavLength) < 0){
	// 	printf("SDL_QueueAudio Failed: %s\n",SDL_GetError());
	// }
	SDL_PauseAudioDevice(deviceID, 0);
	// SDL_FreeWAV(wavBuffer);
	// std::cout << audioPlayTime()<< std::endl;  
	// SDL_Delay(audioPlayTime());
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

