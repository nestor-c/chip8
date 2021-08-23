#include <iostream>
#include "Renderer.h"

int main(){
   Renderer myRenderer(20);
   std::cout << myRenderer.setPixel(5,5) << std::endl;
   myRenderer.displayDisplay();
   return 0;
   
}
