#include "Speaker.h"
#include <iomanip>
#include <iostream>

int main(int argc, char** argv){
	Speaker mySpeaker;
	mySpeaker.setup("test.wav");
	mySpeaker.play();
	// std::cout << "Made it past the pause." << std::endl << std::endl;
	// mySpeaker.play();
	// SDL_Delay(5000);

	// mySpeaker.play();
	// SDL_Delay(5000);
	// mySpeaker.play();
	// SDL_Delay(5000);
}
