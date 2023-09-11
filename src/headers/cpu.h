#ifndef CPU_H
#define CPU_H
#include "keyboard.h"
#include "Speaker.h"
#include "Renderer.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <fstream>

class CPU{
	public:
		int count;
		Renderer* cpu_Renderer;
		Keyboard* cpu_Keyboard;
		Speaker* cpu_Speaker;
		CPU(Renderer*,Keyboard*,Speaker*);
		//4K bytes of memory
		u_int8_t memory[4096];
		//16 1-byte registers
		std::vector<uint8_t> v;
		//Will store memory address. 16 Bits
		std::uint16_t i; 
		//Timers
		uint delayTimer;
		uint soundTimer;
		// Program counter(pc)
		int pc;
		std::vector<uint16_t>* m_stack;
		int speed;
		bool paused;
		void loadSpritesIntoMemory();
		void loadRom(std::string romName);
		void loadProgramIntoMemory(std::vector<uint8_t> program);
		void cycle();
		void executeInstruction(u_int16_t opcode);
		void playSound();
		void updateTimers();
		bool debug;
};
#endif  