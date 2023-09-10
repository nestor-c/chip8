#ifndef RENDERER_H
#define RENDERER_H
#include <stdio.h>
#include <iomanip>
#include </usr/local/opt/sdl2/include/SDL2/SDL.h>


class Renderer{
    public:
        Renderer(int myScale=1);
        ~Renderer();
        void clear();
        void render();
        void displayDisplay();
		void print();
        bool setPixel(int x,int y);
        void debug_printDisplay();
    private:
        void freeResources();
		SDL_Texture* texture;
        SDL_Renderer* renderer;
        uint cols, rows, windowWidth,windowHeight, scale;
        bool* displayArr;
        int x, y;
        SDL_Window* window;
        bool quit;
};
#endif
