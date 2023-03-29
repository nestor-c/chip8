#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"
#include "Speaker.h"
#include "Keyboard.h"
#include "cpu.h"


class Chip8{
    public:
        void init();
        Chip8();
        ~Chip8();

    private:
		Renderer myRenderer;
		Keyboard myKeyboard;
		CPU myCPU;
		Speaker mySpeaker;
        SDL_Window* window;
        void step();
        int fps = 60, fpsInterval;
        unsigned int startTime, now, then, elapsed;

};
#endif
