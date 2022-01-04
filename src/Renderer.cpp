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
    
Renderer::Renderer(int myScale):cols(64*myScale),rows(32*myScale),scale(myScale){

    bool leftMouseButtonDown = false;
    bool quit = false;
    display = new Uint32[rows*cols]();
    memset(display, 255, rows * cols * sizeof(Uint32));
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());
    
    CHECK_ERROR(
        (screen = SDL_CreateWindow
            (
                "Pixel Drawing",
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

    SDL_Texture* texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC,cols,rows);
    SDL_Event event;
   
    while (!quit)
    {
        SDL_UpdateTexture(texture,NULL, display,cols*sizeof(Uint32));
      // Get the next events
      
      
      if (SDL_PollEvent(&event))
      {
        std::cout << "X: " << event.motion.x << " Y: " << event.motion.y << std::endl;
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    leftMouseButtonDown = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    leftMouseButtonDown = true;
            case SDL_MOUSEMOTION:
                if (leftMouseButtonDown)
                {
                    int mouseX = event.motion.x;
                    int mouseY = event.motion.y;
                    display[(mouseY * cols) + mouseX] = 0;
                }
                break;
        }
      }
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer,texture,NULL,NULL);
      SDL_RenderPresent(renderer);
    }
    
    delete[] display;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
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

    display[pixelLoc] ^= 1;

    return !display[pixelLoc];
}

void Renderer::clear(){
    display = new Uint32[cols*rows];
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
