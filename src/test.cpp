#include "Speaker.h"
#include <iomanip>
#include <iostream>

int main(int argc, char** argv){
	Speaker mySpeaker;
	mySpeaker.setup("test.wav");
	mySpeaker.play();
}
