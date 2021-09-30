#include "Renderer.h"
#include <time.h>
#include <stdlib.h>
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

Renderer::Renderer(int myScale):cols(64),rows(32),scale(myScale),width(cols*scale),height(rows*scale){
    display = new int[cols*rows];
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());
    
    screen = SDL_CreateWindow("Nestor\'s fancy window check",
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            cols*scale, 
            rows*scale,
            0);

    //renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    

    //SDL_Surface* window_surface = SDL_GetWindowSurface(screen);
    // if (window_surface == NULL) {
    //     std::cout << SDL_GetError() << std::endl;
    // }
    //SDL_FillRect(window_surface, NULL,  SDL_MapRGB( window_surface->format, 0xFF, 0xFF, 0xFF ));
    //SDL_UpdateWindowSurface(screen);
    while (true)
    {
      // Get the next event
      SDL_Event event;
      if (SDL_PollEvent(&event))
      {
        if (event.type == SDL_QUIT)
        {
          // Break out of the loop on quit
          break;
        }
      }
    }
    
    // renderer = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);    
    // SDL_GetError();
    //SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);   
    SDL_DestroyWindow(screen);
    SDL_Quit();
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
    int pixelLoc = x + (y*rows);

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

// void Renderer::displayDisplay(){
    
// }
