#ifndef RENDERER_H
#define RENDERER_H
#include <stdio.h>
#include <SDL2/SDL.h>


class Renderer{
    public:
        Renderer(int myScale=1);
        void clear();
        void render();
        void testRender();
        void displayDisplay();
		void print();
        bool setPixel(int x,int y);
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
