#include "chip8.h"
#include <iostream>

Chip8::Chip8():myRenderer(10){
}

Chip8::~Chip8(){}

void Chip8::init(){
	myRenderer.render();
    // const int MS = 1000; 
    // fpsInterval = MS / fps;
    // then = SDL_GetTicks();
    // startTime = then;
    // //loop requires a callback function. Find the callback equivalent in C++
	// SDL_Event event;
	
	// while(true){
	// 	SDL_SetRenderDrawColor(myRenderer.renderer,255,255,255,255);
	// 	SDL_RenderClear(myRenderer.renderer);
	// 	SDL_UpdateTexture(myRenderer.texture,NULL, myRenderer.display,myRenderer.cols*sizeof(Uint32));
	// 	SDL_RenderCopy(myRenderer.renderer,myRenderer.texture,NULL,NULL);
	// 	if(SDL_WaitEvent(&event)){
	// 		if(event.type == SDL_QUIT){
	// 			break;
	// 		}
	// 	}
	// }
}

void Chip8::step(){
    now = SDL_GetTicks();
    elapsed = now - then;
    if (elapsed > fpsInterval){
    }
}
