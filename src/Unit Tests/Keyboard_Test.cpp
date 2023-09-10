#include "../headers/keyboard.h"
#include <iomanip>
#include <iostream>

SDL_Window* window;
SDL_Renderer* renderer;

void initWindow (){
	SDL_Init(SDL_INIT_VIDEO);
	 // Create a window
    window = SDL_CreateWindow("Print Letter Key Pressed", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_HIDDEN);
    // Create a renderer
 	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void freeResources(){
 	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void gameLoop(Keyboard m_Keyboard){
	bool quit = false;
	SDL_Event event;

	initWindow();

	while(!quit){
		while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
			else if (event.type == SDL_KEYDOWN){
            	 m_Keyboard.onKeyDown(event);
			}
		}
	}
	freeResources();
	SDL_Quit();

}



int main(int argc, char** argv){
	//Testing onKeydown method
	Keyboard myKeyboard;
	gameLoop(myKeyboard);
}
