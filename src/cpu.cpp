#include "headers/cpu.h"

CPU::CPU(Renderer r,Keyboard k,Speaker s){
    m_stack = new std::vector<uint16_t>();
};

void CPU::loadSpritesIntoMemory(){
	/* Array of hex values for each sprite Each sprite is 5 bytes
     The technical reference provides us with each one of these values
     */
    uint8_t SPRITES[] = {
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
    //Doesn't fill the full 512 bytes and only occupies 80 spaces.
    for (int i = 0; i < sizeof(SPRITES)/sizeof(SPRITES[0]); i++) {
        memory[i] = SPRITES[i];
    }
}

void CPU::loadProgramIntoMemory(std::vector<uint8_t> program){
	for(int loc=0;loc< program.size();loc++){
		memory[0x200+loc] = program[loc];
	}
}

void CPU::loadRom(std::string romName){
        std::ifstream romFile("build/roms/"+romName,std::ios_base::binary|std::ios_base::ate);
        if (!romFile.is_open()){
            throw std::runtime_error ("Error opening the given ROM file. Try again or try another ROM");
        }

        size_t fileSize = romFile.tellg();
        romFile.seekg(0,std::ios::beg);
        
        std::vector<uint8_t> program(fileSize);
        
        if(!romFile.read((char*)program.data(),fileSize)){
            throw std::runtime_error("Error reading data from given ROM file. Try again or try another ROM");
        }

        loadProgramIntoMemory(program);
        romFile.close();
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
    //Loop that handles execution
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

    //Each opcode is 2 bytes long so increment by 2 to get it ready for 
    // the next instruction
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
            //clear display 
            r.clear(); 
                break;
            case 0x00EE:
             // return from subroutine      
                if (!m_stack->empty()){
                    pc =  m_stack->back();
                    m_stack->pop_back();
                }
                break;
        }
        break;
    case 0x1000:
        pc = (opcode & 0xFFF);
        break;
    case 0x2000:
        m_stack->push_back(pc);
        pc = (opcode & 0xFFF);
        break;
    case 0x3000:
        if (v[x] == static_cast<uint8_t>(opcode & 0x00FF)){
            pc += 2;
        }
        break;
    case 0x4000:
        if (v[x]!= (uint8_t)(opcode & 0xFF)){
            pc += 2;
        }
        break;
    case 0x5000:
        if (v[x]==v[y]){
            pc += 2;
        }
        break;
    case 0x6000:
        v[x]= (opcode & 0xFF);
        break;
    case 0x7000:
        v[x]+=(opcode & 0xFF);
        break;
    case 0x8000:
        switch (opcode & 0xF) {
            case 0x0:
                v[x] = v[y];
                break;
            case 0x1:
                v[x] |= v[y];
                break;
            case 0x2:
                v[x] &= v[y];
                break;
            case 0x3:
                v[x] ^= v[y];
                break;
            case 0x4:
                int sum = (v[x] += v[y]);
                v[0xF] = 0;
                if (sum > 0xFF){
                    v[0xF] = 1;
                }
                v[x] = sum;
                break;
            case 0x5:
                v[0xF] = 0;
                if (v[x]>v[y]){
                    v[0xF]=1;
                }
                v[x] -= v[y];
                break;
            case 0x6:
                v[0xF] = (v[x] & 0x1);
                v[x] >>= 1;
                break;
            case 0x7:
                v[0xF] = 0;
                if (v[y] > v[x]){
                    v[0xF] = 1;
                }
                v[x] = v[y]-v[x];
                break;
            case 0xE:
                v[0xF]=(v[x] & 0x80);
                v[x] <<=1;
                break;
        }
        break;
    case 0x9000:
        if (v[x] != v[y]){
            pc+=2;
        }
        break;
    case 0xA000:
        i = (opcode & 0xFFF);
        break;
    case 0xB000:
        pc = (opcode & 0xFFF) + v[0];
        break;
    case 0xC000:
        int rand = Math.floor(Math.random()*0xFF);
        v[x]= rand & (opcode & 0xFF);
        break;
    case 0xD000:
        const int width = 8;
    
        int height = (opcode & 0xF);

        this.v[0xF] = 0;

        for (int row = 0; row < height; row++) {
            int sprite = memory[i + row];

            for (int col = 0; col < width; col++) {
                // If the bit (sprite) is not 0, render/erase the pixel
                if ((sprite & 0x80) > 0) {
                    // If setPixel returns 1, which means a pixel was erased, set VF to 1
                    if (renderer.setPixel(v[x] + col, v[y] + row)) {
                        v[0xF] = 1;
                    }
                }

                // Shift the sprite left 1. This will move the next next col/bit of the sprite into the first position.
                // Ex. 10010000 << 1 will become 0010000
                sprite <<= 1;
            }
        }
        break;
    case 0xE000:
        switch (opcode & 0xFF) {
            case 0x9E:
                if (k.isKeyPressed(v[x])):
                    pc+=2;
                break;
            case 0xA1:
                if (!k.isKeyPressed(v[x])):
                    pc+=2;
                break;
        }

        break;
    case 0xF000:
        switch (opcode & 0xFF) {
            case 0x07:
                v[x] = delayTimer;
                break;
            case 0x0A:
                paused= true;
                k.onNextKeyPress = (SDL_Scancode Key)=>{
                    v[x] = key;
                    paused = false;
                }
                break;
            case 0x15:
                delayTimer = v[x];
                break;
            case 0x18:
                soundTimer = v[x];
                break;
            case 0x1E:
                i += v[x];
                break;
            case 0x29:
                i = v[x]*5;
                break;
            case 0x33:
                memory[i]=v[x]/100;

                memory[i+1] = (v[x]%100)/10;

                memory[i+2] = (v[x]%10);
                break;
            case 0x55:
                for(int registerIndex=0; registerIndex < x; registerIndex++){
                    memory[i+registerIndex] = v[registerIndex];
                }
                break;
            case 0x65:
                for(int registerIndex=0; registerIndex < x; registerIndex++){
                    v[registerIndex] = memory[i+registerIndex];
                }
                break;
        }

        break;

   // default:
   //     throw std::invalid_argument('Unknown opcode ');
}

}