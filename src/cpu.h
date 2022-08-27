#ifndef CPU_H
#define CPU_H
#include "Keyboard.h"
#include "Speaker.h"
#include "Renderer.h"
#include <vector>
#include <stdint.h>

class CPU{
	public:
		Renderer r;
		Keyboard k;
		Speaker s;
		CPU(Renderer r,Keyboard k,Speaker s);
		//4K bytes of memory
		//Using short int (2 bytes each )
		u_int8_t memory[2048];
		//16 1-byte registers
		std::vector<u_int8_t> v[8];
		//Will store memory address
		int i=0;
		//Timers
		
		uint delayTimer;
		uint soundTimer;
		// Program counter(pc)
		int pc = 0x200;
		std::vector<int> stack;
		int speed = 10;
		bool paused = false;
		void loadSpritesIntoMemory();
		void loadRomIntoMemory(std::vector<uint8_t> program);
		void cycle();
		void executeInstruction(uint8_t opcode);
		void playSound();
		void updateTimers();
};
#endif  