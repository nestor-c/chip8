#include "chip8.h"

Chip8::Chip8():myRenderer(10){
    
}

void Chip8::init(){
    const int MS = 1000; 
    fpsInterval = MS / fps;
    then = SDL_GetTicks();
    startTime = then;
    //loop requires a callback function. Find the callback equivalent in C++
    myRenderer.testRender();
    myRenderer.render();

	while(true){
		SDL_Event event;
		if(SDL_WaitEvent(&event)){
			if(event.type == SDL_QUIT){
				break;
			}
		}
	}
}

void Chip8::step(){
    now = SDL_GetTicks();
    elapsed = now - then;
    if (elapsed > fpsInterval){
    }
}

Chip8::~Chip8(){}