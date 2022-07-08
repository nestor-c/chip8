#include "Speaker.h"
#include <iomanip>

int main(int argc, char** argv){
	Speaker mySpeaker;
	mySpeaker.setup("test.wav");
	//mySpeaker.play();
	SDL_Delay(2000);
}
