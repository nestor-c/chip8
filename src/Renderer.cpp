#include "Renderer.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

#define CHECK_ERROR(test, message) \
    do { \
        if((test)) { \
            fprintf(stderr, "%s\n", (message)); \
            exit(1); \
        } \
    } while(0)

Renderer::Renderer(int myScale):cols(64),rows(32),scale(myScale){
    display = new int[cols*rows];
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());
    screen= SDL_CreateWindow("Nestor\'s fancy window check",
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            cols*scale, 
            rows*scale,
            0);

    SDL_Surface* window_surface=SDL_GetWindowSurface(screen);
    SDL_UpdateWindowSurface(screen);
    SDL_Delay(10000);
    // renderer = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
        

    // SDL_GetError();
};
 
bool Renderer::setPixel(int x,int y){
    if (x > cols){
        x-=cols;
    } else if (x<0){
        x+=cols;
    }
    if(y>rows){
        y-=rows;
    } else if (y<0){
        y+=rows;
    }
    int pixelLoc = x + (y * cols);

    display[pixelLoc] ^=1;

    return !display[pixelLoc];
}

void Renderer::clear(){
    display = new int[cols*rows];
}

void Renderer::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0 , 0, 0, 255);
    SDL_GetError();

    for (int i=0; i < cols * rows; i++){
        int x = (i % cols) * scale;
        int y = floor(i/cols) * scale;
        if (display[i]){
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
            SDL_RenderDrawPoint(renderer,x*scale,y*scale);
        }
    };
}

void Renderer::testRender(){
    setPixel(0,0);
    setPixel(5,2);
}

void Renderer::displayDisplay(){
    
}

// 