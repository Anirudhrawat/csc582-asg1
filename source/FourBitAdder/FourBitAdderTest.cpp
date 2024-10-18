#include <iostream>
#include "FourBitAdder.h"

int main()
{
    FourBitAdder fa(1); // Create a Four-Bit Adder object

    unsigned short int A[4] = {1, 0, 1, 1}; // Example 4-bit number: 1101 (13 in decimal)
    unsigned short int B[4] = {0, 1, 1, 0}; // Example 4-bit number: 0110 (6 in decimal)
    unsigned short int CarryIn = 0;

    fa.set_inputs(A, B, CarryIn);
    fa.update();

    std::cout << "Sum: ";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << fa.get_sum(i);
    }
    std::cout << ", CarryOut: " << fa.get_carry_out() << std::endl;

    return 0;
}