#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"
#include "Speaker.h"
#include "Keyboard.h"
#include "CPU.h"


class Chip8{
    private:
		CONST RENDERER = new Renderer(10);
		CONST KEYBOARD = new Keyboard();
		CONST SPEAKER = new Speaker();
		CONST CPU = new CPU(RENDERER, KEYBOARD, SPEAKER);
        void step();
        int fps = 60, fpsInterval;
        unsigned int startTime, now, then, elapsed;
    public:
        Renderer myRenderer;
        void init();
        Chip8();
        ~Chip8();
};
#endif
