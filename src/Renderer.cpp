#include "Renderer.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include "keyboard.h"
#include <cmath>

#define CHECK_ERROR(test, message) \
    do { \
        if((test))\
        { \
            fprintf(stderr, "%s\n", (message)); \
            exit(1); \
        } \
    } while(0)
    
Renderer::Renderer(int myScale):cols(64*myScale),rows(32*myScale),scale(myScale){
    display = new Uint32[rows*cols]();
    memset(display, 255, rows * cols * sizeof(Uint32));
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());
    
    CHECK_ERROR(
        (screen = SDL_CreateWindow
            (
                "My Window",
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                cols, 
                rows,
                0
            )
        )
             == NULL, 
             SDL_GetError()
    );

    CHECK_ERROR(
        (renderer = SDL_CreateRenderer(
                        screen, 
                        -1, 
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                    )
        ) == NULL, 
        SDL_GetError()
    );

	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC,cols,rows);
};

bool Renderer::setPixel(int x,int y){
    if (x > cols){
        x -= cols;
    } else if (x < 0){
        x += cols;
    }
    if(y > rows){
        y -= rows;
    } else if (y < 0){
        y += rows;
    }
    int pixelLoc = x + (y*cols);
	
	// 4294967295 -> in Binary (11111111 11111111 11111111 11111111)
    display[pixelLoc] ^= (Uint32)4294967295;

    return !display[pixelLoc];
}

void Renderer::clear(){
    display = new Uint32[cols*rows];
}

void Renderer::render(){
	//SDL_RenderClear(renderer);
    //SDL_GetError();
	SDL_Event event;
	//SDL_SetRenderDrawColor(renderer,255,0,255,255);
	//SDL_RenderClear(renderer);
	//bool leftMouseButtonDown = false;
	bool quit = false;
	//double beforeTime = SDL_GetPerformanceCounter()/SDL_GetPerformanceFrequency();

	while(!quit){
		while(SDL_PollEvent(&event)){
			//if (event.type == SDL_QUIT) break;
			switch(event.type){
				case SDL_KEYDOWN:
					std::cout << "Key pressed Down" << std::endl;
					if (event.key.keysym.scancode == SDL_SCANCODE_G)
						std::cout << "Pressed G" << std::endl;
					break;	
				case SDL_KEYUP:
					std::cout << "Key lifted" << std::endl;
					break;
				case SDL_QUIT:
					quit=true;
		}
	}
		
	//SDL_RenderClear(renderer);
	SDL_UpdateTexture(texture,NULL,display,cols*sizeof(Uint32));
	SDL_RenderCopy(renderer,texture,NULL,NULL);
	SDL_RenderPresent(renderer);
	//SDL_RenderClear(renderer);
	//double currentTime = (double)SDL_GetPerformanceCounter()/SDL_GetPerformanceFrequency();
	//double deltaTime = static_cast<double>(currentTime - beforeTime);
	// beforeTime = currentTime;
	// std::cout << "Time between each frame in seconds: " << deltaTime << std::endl;
	// float fps = 1.0/deltaTime;
	// std::cout << "Fps: " << fps << std::endl;
	}

	delete[] display;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	SDL_Quit();	
}

void Renderer::testRender(){
    setPixel(320,160);
	setPixel(321,160);
	setPixel(322,160);
}