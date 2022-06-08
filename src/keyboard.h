#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
#include <map>
#include "SDL.h"

class Keyboard{
	public:
    Keyboard();
    std::map<int,int> KEYMAP;
	int* keysPressed;
	int onNextKeypress;
	bool isKeyPressed(int);
	void onKeyDown(SDL_Event event);
};
#endif
