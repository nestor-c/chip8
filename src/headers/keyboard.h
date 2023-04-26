#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
#include <map>
#include "SDL.h"
#include <functional>

class Keyboard{
	public:
    Keyboard();
    std::map<SDL_Scancode,int> KEYMAP;
	std::map<int,bool> keysPressed;
	std::function<void()> onNextKeyPress;
	bool isKeyPressed(uint8_t m_Key);
	void onKeyDown(SDL_Event event);
	void onKeyUp(SDL_Event event);
};
#endif
