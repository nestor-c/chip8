#include "headers/keyboard.h"

Keyboard::Keyboard():onNextKeyPress(NULL){
	KEYMAP = {
	{SDL_SCANCODE_1, 0x1}, // 1
	{SDL_SCANCODE_2, 0x2}, // 2
	{SDL_SCANCODE_3, 0x3}, // 3
	{SDL_SCANCODE_4, 0xc}, // 4
	{SDL_SCANCODE_Q, 0x4}, // Q
	{SDL_SCANCODE_W, 0x5}, // W
	{SDL_SCANCODE_E, 0x6}, // E
	{SDL_SCANCODE_R, 0xD}, // R
	{SDL_SCANCODE_A, 0x7}, // A
	{SDL_SCANCODE_S, 0x8}, // S
	{SDL_SCANCODE_D, 0x9}, // D
	{SDL_SCANCODE_F, 0xE}, // F
	{SDL_SCANCODE_Z, 0xA}, // Z
	{SDL_SCANCODE_X, 0x0}, // X
	{SDL_SCANCODE_C, 0xB}, // C
	{SDL_SCANCODE_V, 0xF} // V
	};
}

bool Keyboard::isKeyPressed(uint8_t m_Key){
	return keysPressed[m_Key];
}

void Keyboard::onKeyDown(SDL_Event event){
	int key = KEYMAP[event.key.keysym.scancode];
	keysPressed[key] = true;

	if (onNextKeyPress != NULL && key){
		onNextKeyPress(key);
		onNextKeyPress = NULL;		
	}
}

void Keyboard::onKeyUp(SDL_Event event){
	int key = KEYMAP[event.key.keysym.scancode];
	keysPressed[key] = false;
}