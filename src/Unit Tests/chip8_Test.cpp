#include "../headers/chip8.h"
#include <string>

int main(){
     std::string BLINKY = "build/roms/BLINKY";
    Chip8 myVirtualMachine;
    myVirtualMachine.myCPU.loadRom(BLINKY);
    }