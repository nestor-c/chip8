#ifndef RENDERER_H
#define RENDERER_H
#include "stdio.h"
#include <SDL2/SDL.h>

class Renderer{
    public:
        Renderer(int);
        bool setPixel(int x,int y);
        void clear();
        void render();
        void testRender();
        void displayDisplay();
    private:
        int cols;
        int rows;
        int width;
        int height;
        int scale;
        int* display;
        int x;
        int y;
        SDL_Window* screen;
        SDL_Renderer* renderer;
};
#endif
