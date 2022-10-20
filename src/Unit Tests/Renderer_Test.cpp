#include "../headers/Renderer.h"
#include <iomanip>
#include <iostream>

int main(int argc, char** argv){
	Renderer myRenderer(10);
	myRenderer.render();
	myRenderer.freeResources();
}
