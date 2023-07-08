#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"
#include "Speaker.h"
#include "keyboard.h"
#include "cpu.h"


class Chip8{
    public:
        void init();
        Chip8();
        ~Chip8();
        void eventLoop();
        bool quit = false;

    private:
		Renderer myRenderer(int);
		Keyboard myKeyboard;
        SDL_Event event;
        
		CPU myCPU;
		Speaker mySpeaker;
        SDL_Window* window;
        void step();
        int fps, fpsInterval;
        unsigned int startTime, now, then, elapsed;

};
#endif
