#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <bitset>

void loadRom(std::string romName){
        std::bitset<8> binaryOutput;
        std::ifstream romFile("../build/roms/"+romName,std::ios_base::binary|std::ios_base::ate);
        if (!romFile.is_open()){
            throw std::runtime_error ("Error opening the given ROM file. Try again or try another ROM");
        }

        size_t fileSize = romFile.tellg();
        romFile.seekg(0,std::ios::beg);
        
        std::vector<uint8_t> program(fileSize);
        
        if(!romFile.read((char*)program.data(),fileSize)){
            throw std::runtime_error("Error reading data from given ROM file. Try again or try another ROM");
        };

        for(auto m_element: program){
            std::cout << m_element <<" ";
        };
    }

int main(){
    loadRom("BLINKY");
}