#include "headers/chip8.h"
#include <iostream>

Chip8::Chip8():fps(60), 
myCPU(myRenderer(10),myKeyboard,mySpeaker){
}	

Chip8::~Chip8(){}

void Chip8::init(){
	int MS = 1000;
    fpsInterval = MS / fps;
    then = SDL_GetTicks();
    startTime = then;
    step();
}

void Chip8::step(){
    now = SDL_GetTicks();
    elapsed = now - then;
    if (elapsed > fpsInterval){
        myCPU.cycle();
    }
    eventLoop();
    SDL_Delay(1);
    step();
}

void Chip8::eventLoop(){
    while(!quit){ 
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }
}