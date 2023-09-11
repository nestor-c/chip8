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
    
Renderer::Renderer(int myScale):cols(64),rows(32),scale(myScale),windowWidth(cols*myScale),windowHeight(rows*myScale),quit(false){
    displayArr = new bool[rows*cols]();
    //Set display to all white by filling every value to 255
    memset(displayArr, 0, rows * cols * sizeof(bool));

    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

    {CHECK_ERROR(
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
    );}

    {CHECK_ERROR(
        (renderer = SDL_CreateRenderer(
                        window, 
                        -1, 
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                    )
        ) == NULL, 
        SDL_GetError()
    );}

	texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,windowWidth,windowHeight);
};

Renderer::~Renderer(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    delete[] displayArr;
}

void Renderer::freeResources(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    delete[] displayArr;
}

bool Renderer::setPixel(int x,int y){
    // if (x > (cols-1)){
    //     x %= cols;
    // } else if (x < 0){
    //     x = cols + (x % cols);
    // }
    // if(y > (rows-1)){
    //     y %= (rows);
    // } else if (y < 0){
    //     y = rows + (y % rows);
    // }
    
    if (x > (cols)){
        x -= cols;
    } else if (x < 0){
        x += cols;
    }
    if(y > (rows)){
        y -= rows;
    } else if (y < 0){
        y += cols;
    }

    int pixelLoc=x + (y*cols);
    displayArr[pixelLoc] ^= 1;
    return !displayArr[pixelLoc];    
}

void Renderer::clear(){
    memset(displayArr, 0, rows * cols * sizeof(bool));
}

void Renderer::render(){
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderClear(renderer);
        for(int i=0;i<rows*cols;i++){
            if(!displayArr[i]){
                x = (i%cols)*scale;
                y = floor(i/cols)*scale;
                int intScale = (int) scale;
                SDL_Rect pixelFill = {x,y,intScale,intScale};
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                SDL_RenderFillRect(renderer,&pixelFill);
            }
        }
        SDL_RenderPresent(renderer);
};

void Renderer::debug_printDisplay(){
    for (int i = 0; i< rows;i++){
        std::cout << std::left << std::setw(5) << i;
        for (int j=0;j<cols;j++){
            std::cout<< displayArr[j + (i*cols)];
        }
        std::cout << std::endl;
    }
};