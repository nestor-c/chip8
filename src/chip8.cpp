#include "chip8.h"
#include "Renderer.h"
#include <iostream>
void Chip8::init(){
    fpsInterval = 1000/fps;
    then = time(0);
    startTime = then;
    //loop requires a callback function. Find the callback equivalent in C++
    myRenderer.testRender();
    myRenderer.render();
    // Tells browser you want an animation and to call specified function to update animation
    // before next repaint
    // loop = requestAnimationFrame(step);
}

void Chip8::step(){
    now = std::time(0);
    elapsed = now - then;
    if (elapsed > fpsInterval){

    }
    loop = requestAnimationFrame(step);
}
