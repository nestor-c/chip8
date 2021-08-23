#ifndef CHIP8_H
#define CHIP8_H
#include "Renderer.h"
#include <time.h>

class Chip8{
    private:
        void init();
        int fps = 60, fpsInterval;
        time_t startTime, now, then, elapsed;
        void step();
        Renderer myRenderer;
    public:
        Chip8();
        ~Chip8();
};
#endif