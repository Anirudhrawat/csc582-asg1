#include <iostream>
#include "FullAdder.h"

int main()
{
    FullAdder fa(1); // Create a FullAdder object with ID 1
    fa.set_in1(0);   // Set the first input (A)
    fa.set_in2(0);   // Set the second input (B)
    fa.update();     // Update to calculate Sum and CarryOut

    std::cout << "Sum: " << fa.sum() << ", CarryOut: " << fa.carryOut() << std::endl;
    return 0;
}
