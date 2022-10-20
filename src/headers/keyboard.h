#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
#include <map>
#include "SDL.h"

class Keyboard{
	public:
    Keyboard();
    std::map<SDL_Scancode,int> KEYMAP;
	std::map<int,bool> keysPressed;
	void onNextKeyPress(int); 
	bool isKeyPressed(SDL_Scancode);
	void onKeyDown(SDL_Event event);
	void onKeyUp(SDL_Event event);
};
#endif
