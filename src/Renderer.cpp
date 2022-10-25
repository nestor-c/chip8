#include "headers/Renderer.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cmath>

#define CHECK_ERROR(test, message) \
    do { \
        if((test))\
        { \
            fprintf(stderr, "%s\n", (message)); \
            exit(1); \
        } \
    } while(0)
    
Renderer::Renderer(int myScale):cols(64),rows(32),scale(myScale),windowWidth(cols*myScale),windowHeight(rows*myScale){
    display = new Uint32[rows*cols]();
    //Set display to all white by filling every value to 255
    memset(display, 255, rows * cols * sizeof(Uint32));

    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

    CHECK_ERROR(
        (window = SDL_CreateWindow
            (
                "My Window",
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                windowWidth, 
                windowHeight,
                0
            )
        )
             == NULL, 
             SDL_GetError()
    );

    CHECK_ERROR(
        (renderer = SDL_CreateRenderer(
                        window, 
                        -1, 
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                    )
        ) == NULL, 
        SDL_GetError()
    );

	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,windowWidth,windowHeight);
};

void Renderer::freeResources(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
}

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
    while(!quit){
        // CHECK_ERROR(
        //     SDL_SetRenderDrawColor(renderer,255,255,255,255) < 0,
        //     SDL_GetError()
        //     );
        
        // CHECK_ERROR (
        //     SDL_RenderClear(renderer)< 0, 
        //      SDL_GetError()
        // );
        testRender();
        SDL_UpdateTexture(texture,NULL,display,windowWidth*sizeof(Uint32));
        //SDL_RenderCopy(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
        SDL_Event event;
        
        while(SDL_PollEvent(&event)){
            
            switch(event.type){
                case SDL_QUIT:
                    quit=true;
                    break;
                default:
                    break;
            }
        }
    }
    freeResources();
}

void Renderer::testRender(){
    setPixel(320,160);
	setPixel(321,160);
	setPixel(322,160);
}