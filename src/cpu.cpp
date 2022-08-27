#include "cpu.h"

void CPU::loadSpritesIntoMemory(){
	 // Array of hex values for each sprite Each sprite is 5 bytes
    // The technical reference provides us with each one of these values
    const std::vector<uint8_t> SPRITES {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};

    // According to the technical reference, sprites are stored in the interpreter section of memory starting at hex 0x000
    for (int i = 0; i < SPRITESsize(); i++) {
        memory[i] = SPRITES[i];
    }
}

void CPU::loadRomIntoMemory(std::vector<uint8_t> program){
	for(int loc=0;loc< programsize();loc++){
		memory[0x200+loc] = program[loc];
	}
}

void CPU::playSound(){
	   if (soundTimer > 0) {
        s.play();
    } else {
        s.pause();
    }
};

void CPU::updateTimers(){
	 if (delayTimer > 0) {
        delayTimer -= 1;
    }

    if (soundTimer > 0) {
        soundTimer -= 1;
    }
};

void CPU::cycle(){
  for (int i = 0; i < speed; i++) {
        if (!paused) {
            int opcode = (memory[pc] << 8 | memory[pc + 1]);
            executeInstruction(opcode);
        }
    }
	if (!paused) {
        updateTimers();
    }

    playSound();
    r.render();
}

void CPU::executeInstruction(uint8_t opcode){
	pc += 2;

    // We only need the 2nd nibble, so grab the value of the 2nd nibble
    // and shift it right 8 bits to get rid of everything but that 2nd nibble.
    int x = (opcode & 0x0F00) >> 8;

    // We only need the 3rd nibble, so grab the value of the 3rd nibble
    // and shift it right 4 bits to get rid of everything but that 3rd nibble.
    int y = (opcode & 0x00F0) >> 4;


	switch (opcode & 0xF000) {
    case 0x0000:
        switch (opcode) {
            case 0x00E0:
                break;
            case 0x00EE:
                break;
        }

        break;
    case 0x1000:
        break;
    case 0x2000:
        break;
    case 0x3000:
        break;
    case 0x4000:
        break;
    case 0x5000:
        break;
    case 0x6000:
        break;
    case 0x7000:
        break;
    case 0x8000:
        switch (opcode & 0xF) {
            case 0x0:
                break;
            case 0x1:
                break;
            case 0x2:
                break;
            case 0x3:
                break;
            case 0x4:
                break;
            case 0x5:
                break;
            case 0x6:
                break;
            case 0x7:
                break;
            case 0xE:
                break;
        }

        break;
    case 0x9000:
        break;
    case 0xA000:
        break;
    case 0xB000:
        break;
    case 0xC000:
        break;
    case 0xD000:
        break;
    case 0xE000:
        switch (opcode & 0xFF) {
            case 0x9E:
                break;
            case 0xA1:
                break;
        }

        break;
    case 0xF000:
        switch (opcode & 0xFF) {
            case 0x07:
                break;
            case 0x0A:
                break;
            case 0x15:
                break;
            case 0x18:
                break;
            case 0x1E:
                break;
            case 0x29:
                break;
            case 0x33:
                break;
            case 0x55:
                break;
            case 0x65:
                break;
        }

        break;

    default:
        throw new Error('Unknown opcode ' + opcode);
}

}