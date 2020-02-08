#include <iostream>
#include "demo.hpp"

int main(int argc, char* argv[])
{
    std::cout << "Hello from CMake Cross Compile Demo!" << std::endl;
    Demo d;
    int result = d.add( 1, 1);
    std::cout << "Add( 1 , 1) return = " << result << std::endl;
    return 0;
}