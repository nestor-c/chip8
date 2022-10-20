#include "../headers/Speaker.h"
#include <iomanip>
#include <iostream>

int main(int argc, char** argv){
	Speaker	speaker;
	speaker.setup("Assets/test.wav");
	speaker.play();
}
 