#include "keyboard.h"

Keyboard::Keyboard(){
	KEYMAP[SDL_SCANCODE_1]= 0x1; // 1
	KEYMAP[SDL_SCANCODE_2]= 0x2; // 2
	KEYMAP[SDL_SCANCODE_3]= 0x3; // 3
	KEYMAP[SDL_SCANCODE_4]= 0xc; // 4
	KEYMAP[SDL_SCANCODE_Q]= 0x4; // Q
	KEYMAP[SDL_SCANCODE_W]= 0x5; // W
	KEYMAP[SDL_SCANCODE_E]= 0x6; // E
	KEYMAP[SDL_SCANCODE_R]= 0xD; // R
	KEYMAP[SDL_SCANCODE_A]= 0x7; // A
	KEYMAP[SDL_SCANCODE_S]= 0x8; // S
	KEYMAP[SDL_SCANCODE_D]= 0x9; // D
	KEYMAP[SDL_SCANCODE_F]= 0xE; // F
	KEYMAP[SDL_SCANCODE_Z]= 0xA; // Z
	KEYMAP[SDL_SCANCODE_X]= 0x0; // X
	KEYMAP[SDL_SCANCODE_C]= 0xB; // C
	KEYMAP[SDL_SCANCODE_V]= 0xF; // V
}

bool Keyboard::isKeyPressed(SDL_Scancode keyCode){
	return keysPressed[keyCode];
}

void Keyboard::onKeyDown(SDL_Event event){
	int key = KEYMAP[event.key.keysym.scancode];
	keysPressed[key] = true;

	if (onNextKeyPress != NULL && key){
		onNextKeyPress(key);
	}
}

void Keyboard::onKeyUp(SDL_Event event){
	int key = KEYMAP[event.key.keysym.scancode];
	keysPressed[key] = false;
}