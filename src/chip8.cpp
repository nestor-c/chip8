#include "chip8.h"
#include "Renderer.h"
#include <iostream>
void Chip8::init(){
    fpsInterval = 1000/fps;
    then = time(0);
    startTime = then;
    //loop requires a callback function. Find the callback equivalent in C++
    myRenderer.testRender();
    myRenderer.render()
    loop = 
}

void Chip8::step(){
    now = Date.now();
    elapsed = now - then;
    if (elapsed > fpsInterval){

    }
    loop = requestAnimationFrame(step);
}
