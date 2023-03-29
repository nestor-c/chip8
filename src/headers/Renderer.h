#ifndef RENDERER_H
#define RENDERER_H
#include <stdio.h>
#include "SDL.h"


class Renderer{
    public:
        Renderer(int myScale=1);
        void clear();
        void render();
        void testRender();
        void displayDisplay();
		void print();
    private:
        void freeResources();
        bool setPixel(int x,int y);
		SDL_Texture* texture;
        SDL_Renderer* renderer;
        uint cols, rows, windowWidth,windowHeight, scale;
        Uint32* displayArr;
        int x, y;
        SDL_Window* window;
        bool quit;
};
#endif
