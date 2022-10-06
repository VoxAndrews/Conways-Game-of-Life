#include <iostream>

#include "window/window.h"

int main()
{
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "// CONWAY'S GAME OF LIFE" << std::endl;
    std::cout << "//" << std::endl;
    std::cout << "// Programmed by: Darcy L. C. Wilson - 2022" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl << std::endl;
    
    Window userWindow("Conway's Game of Life"); //Creates a GLFW window with specific user parameters

    return 0;
}