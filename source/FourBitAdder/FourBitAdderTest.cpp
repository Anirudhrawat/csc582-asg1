#include <iostream>
#include "FourBitAdder.h"

// Function to print the sum and carry-out results
void print_result(unsigned short int sum[4], unsigned short int carryOut) {
    std::cout << "Sum: ";
    for (int i = 3; i >= 0; --i) { // Print from most significant to least significant bit
        std::cout << sum[i];
    }
    std::cout << ", CarryOut: " << carryOut << std::endl;
}

int main() {
    // Create a Four-Bit Adder object
    FourBitAdder adder(1);

    // Test Case 1
    unsigned short int A1[4] = {1, 1, 1, 1}; // 1101 (13 in decimal)
    unsigned short int B1[4] = {0, 0, 0, 0}; // 0110 (6 in decimal)
    unsigned short int carryIn1 = 0;
    adder.set_input(0, A1[0]); // Set A0
    adder.set_input(1, A1[1]); // Set A1
    adder.set_input(2, A1[2]); // Set A2
    adder.set_input(3, A1[3]); // Set A3
    adder.set_input(4, B1[0]); // Set B0
    adder.set_input(5, B1[1]); // Set B1
    adder.set_input(6, B1[2]); // Set B2
    adder.set_input(7, B1[3]); // Set B3
    // Outputs are automatically updated through AbstractDevice's set_input method

    // Retrieve and print the results
    unsigned short int sum1[4] = {adder.get_output(0), adder.get_output(1), adder.get_output(2), adder.get_output(3)};
    unsigned short int carryOut1 = adder.get_output(4);

    std::cout << "Test Case 1 - A: 1101, B: 0110, CarryIn: 0" << std::endl;
    print_result(sum1, carryOut1);

    // Add more test cases as needed...

    return 0;
}

