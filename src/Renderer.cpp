#include "Renderer.h"
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
    
Renderer::Renderer(int myScale):cols(64),rows(32),scale(myScale),windowWidth(cols*myScale),windowHeight(rows*myScale),quit(false){
    displayArr = new Uint32[rows*cols]();
    //Set display to all white by filling every value to 255
    memset(displayArr, 255, rows * cols * sizeof(Uint32));
    
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

    CHECK_ERROR(
        (window = SDL_CreateWindow
            (
                "My Window",
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
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

	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,windowWidth,windowHeight);
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
	//0xFFFFFFFF -> Binary(11111111 11111111 11111111 11111111)    
    displayArr[pixelLoc] ^= (Uint32)0xFFFFFFFF;
    return !displayArr[pixelLoc];
}

void Renderer::clear(){
    displayArr = new Uint32[cols*rows];
}

void Renderer::render(){
    while(!quit){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
        display[1056]=0;     
        for(int i=0;i<rows*cols;i++){
            if(!display[i]){
                x = (i%cols)*scale;
                y = floor(i/cols)*scale;
                SDL_Rect pixelFill = {x,y,scale,scale};
                SDL_SetRenderDrawColor(renderer,0,255,0,255);
                SDL_RenderFillRect(renderer,&pixelFill);
            }
        }
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