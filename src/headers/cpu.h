#ifndef CPU_H
#define CPU_H
#include "Keyboard.h"
#include "Speaker.h"
#include "Renderer.h"
#include <vector>
//#include <stdint.h>
#include <cstdint>
#include <fstream>

class CPU{
	public:
		Renderer r;
		Keyboard k;
		Speaker s;
		CPU(Renderer r,Keyboard k,Speaker s);
		//4K bytes of memory
		u_int8_t memory[4096];
		//16 1-byte registers
		std::vector<uint8_t> v[16];
		//Will store memory address. 16 Bits
		std::vector<uint8_t> i[2]; 
		//Timers
		uint delayTimer;
		uint soundTimer;
		// Program counter(pc)
		int pc = 0x200;
		std::vector<uint16_t>* m_stack;
		int speed = 10;
		bool paused = false;
		void loadSpritesIntoMemory();
		void loadRom(std::string romName);
		void loadProgramIntoMemory(std::vector<uint8_t> program);
		void cycle();
		void executeInstruction(uint8_t opcode);
		void playSound();
		void updateTimers();
};
#endif  