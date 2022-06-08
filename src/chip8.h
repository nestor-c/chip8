#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"

class Chip8{
    private:
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
