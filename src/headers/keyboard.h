#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <iostream>
#include <SDL2/SDL.h>
#include <functional>
#include <map>

class Keyboard{
	public:
    Keyboard();
	std::function<void(int)> onNextKeyPress;
	bool isKeyPressed(uint8_t m_Key);
    std::map<SDL_Scancode, int> KEYMAP;
	std::map<int,bool> keysPressed;
	void onKeyDown(SDL_Event event);
	void onKeyUp(SDL_Event event);
};
#endif
