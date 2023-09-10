#ifndef KEYBOARD_H
#define KEYBOARD_H
#include </usr/local/opt/sdl2/include/SDL2/SDL.h>
#include <iostream>
#include <functional>
#include <map>

	class Keyboard{
	public:
		Keyboard();
		~Keyboard();
		bool isKeyPressed(uint8_t m_Key);
		void onKeyDown(SDL_Event event);
		void onKeyUp(SDL_Event event);
		void printKeysPressed();
		std::function<void(int)> onNextKeyPress;
		std::map<SDL_Scancode, int> KEYMAP;
		
	private:
		std::map<int,bool> keysPressed;
};
#endif
