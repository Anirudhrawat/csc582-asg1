#include <iostream>
#include "HalfAdder.h" // Include the appropriate header file for HalfAdder

int main() {
    HalfAdder ha(1); 
    ha.set_in1(0); 
    ha.set_in2(0);  
    ha.update();      

    std::cout << "Sum: " << ha.sum() << ", Carry: " << ha.carry() << std::endl;
    return 0;
}
