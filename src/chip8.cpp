#include "headers/chip8.h"
#include <iostream>

Chip8::Chip8():quit(false), fps(60), myRenderer(10), myCPU(&myRenderer,&myKeyboard,&mySpeaker){
        
}	

Chip8::~Chip8(){}

void Chip8::init(){
	int MS = 1000;
    fpsInterval = MS / fps;
    then = SDL_GetTicks();
    startTime = then;
    
    std::string MYROM = "BLINKY";
     myCPU.loadSpritesIntoMemory();
    
    myCPU.loadRom(MYROM);

    eventLoop();
}

void Chip8::eventLoop(){
    while(!quit){ 
        now = SDL_GetTicks();
        elapsed = now - then;
        if (elapsed > fpsInterval){
            myCPU.cycle();
        }
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }
}