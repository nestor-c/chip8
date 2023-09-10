#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"
#include "Speaker.h"
#include "keyboard.h"
#include "cpu.h"


class Chip8{
        private:
		Renderer myRenderer;
		Keyboard myKeyboard;
		Speaker mySpeaker;
        SDL_Event event;
        SDL_Window* window;
        int fps, fpsInterval;
        unsigned int startTime, now, then, elapsed;
        
    public:
        void init();
        Chip8();
        ~Chip8();
        void eventLoop();
        bool quit;
		CPU myCPU;
};
#endif
