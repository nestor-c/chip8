#include "headers/chip8.h"
#include <iostream>

Chip8::Chip8()
:myRenderer(10), 
myCPU(myRenderer,myKeyboard,mySpeaker){
}	

Chip8::~Chip8(){}

void Chip8::init(){
	int MS = 1000;
    fpsInterval = MS / fps;
    then = SDL_GetTicks();
    startTime = then;
	
	// if(SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO)){
	// 	//Some error logging.
    //     SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "SDL could not initialize the video or audio system.");
	// }
	
	// if(!window = SDL_CreateWindow("Chip8",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, myRenderer.windowWidth, myRenderer.WindowHeight,0)){
	// 	//some error logging.
    //     SDL_LogError(SDL_LOG_CATEGORY_RENDER, "SDL could not create the defined window.");
	// }

	// if(renderer = SDL_CreateRenderer(window,-1,0)){
	// 	//some error logging.
    //     SDL_LogError(%s, "SDL could not create the requested renderer.");
	// }

    myCPU.loadSpritesIntoMemory();
    myCPU.loadRom("BLINKY");
    myRenderer.render();
    // ----Animation loop start ----
    // while(!quit){
    // SDL_SetRenderDrawColor(renderer,255,255,255,255);
    // SDL_RenderClear(renderer);
    // displayArr[1056]=0;     
    // for(int i=0;i<rows*cols;i++){
    //     if(!displayArr[i]){
    //         x = (i%cols)*scale;
    //         y = floor(i/cols)*scale;
    //         SDL_Rect pixelFill = {x,y,scale,scale};
    //         SDL_SetRenderDrawColor(renderer,0,255,0,255);
    //         SDL_RenderFillRect(renderer,&pixelFill);
    //     }
    // }
    // SDL_RenderPresent(renderer);

    // SDL_Event event;
    // while(SDL_PollEvent(&event)){
        
    //     switch(event.type){
    //         case SDL_QUIT:
    //             quit=true;
    //             break;
    //         default:
    //             break;
    //     }
    // }
    // }
    // freeResources();
    // ----Animation loop End ----
}

void Chip8::step(){
    now = SDL_GetTicks();
    elapsed = now - then;
    if (elapsed > fpsInterval){
		myCPU.cycle();
    }
    // Javascript specific loop that makes animation possible.
	//loop = requestAnimationFrame(step);
}
