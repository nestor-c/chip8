#include <SDL.h>
#include "../Speaker.cpp"

void eventLoop(){
    bool quit = false;
    while(!quit){
        SDL_Event gameEvent;
        while(SDL_PollEvent(&gameEvent)){
            if (gameEvent.type == SDL_QUIT) quit = true;
        }
    }
}

int main(){
    Speaker mySpeaker;
    mySpeaker.play();
    eventLoop();
}