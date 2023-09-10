#include "../headers/Renderer.h"
#include <iomanip>
#include <iostream>

void gameLoop(Renderer& myRenderer){
	bool quit = false;
	SDL_Event event;

	while(!quit){
		while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
			myRenderer.render();
		}
	}

	SDL_Quit();
}

int main(int argc, char** argv){
	Renderer myRenderer(10);
	myRenderer.setPixel(4,32);
	gameLoop(myRenderer);
	//myRenderer.debug_printDisplay();
}
