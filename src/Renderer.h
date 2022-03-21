#ifndef RENDERER_H
#define RENDERER_H
#include <stdio.h>
#include "SDL.h"

class Renderer{
    public:
        Renderer(int myScale=1);
        bool setPixel(int x,int y);
        void clear();
        void render();
        void testRender();
        void displayDisplay();
    private:
        int cols;
        int rows;
        int scale;
        Uint32* display;
        int x;
        int y;
        SDL_Window* screen;
        SDL_Renderer* renderer;
		SDL_Texture* texture;
};
#endif
