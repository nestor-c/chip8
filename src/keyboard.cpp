#include "keyboard.h"

Keyboard::Keyboard(){
	KEYMAP[49] = 0x1; // 1
	KEYMAP[50] = 0x2; // 2
	KEYMAP[51] = 0x3; // 3
	KEYMAP[52] = 0xc; // 4
	KEYMAP[81] = 0x4; // Q
	KEYMAP[87] = 0x5; // W
	KEYMAP[69] = 0x6; // E
	KEYMAP[82] = 0xD; // R
	KEYMAP[65] = 0x7; // A
	KEYMAP[83] = 0x8; // S
	KEYMAP[68] = 0x9; // D
	KEYMAP[70] = 0xE; // F
	KEYMAP[90] = 0xA; // Z
	KEYMAP[88] = 0x0; // X
	KEYMAP[67] = 0xB; // C
	KEYMAP[86] = 0xF; // V	
}

bool Keyboard::isKeyPressed(int keyCode){
	return keysPressed[keyCode];
}

void Keyboard::onKeyDown(SDL_Event event){
	if (event.type == SDL_KEYDOWN)
	{
		int Key = KEYMAP[event.key.keysym.scancode];
		if (Key == 49) std::cout << "test complete " << std::endl;
	}
}