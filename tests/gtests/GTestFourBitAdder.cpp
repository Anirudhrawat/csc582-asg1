#include <gtest/gtest.h>
#include "../../source/FourBitAdder/FourBitAdder.h"

// Test case for Four-Bit Adder
TEST(FourBitAdderTest, BasicAddition) {
    FourBitAdder adder(1);

    // Test case: 1101 (13) + 0110 (6)
    unsigned short int A[4] = {1, 0, 1, 1}; // 1101
    unsigned short int B[4] = {0, 1, 1, 0}; // 0110
    unsigned short int carryIn = 0;

    // Set inputs
    adder.set_input(0, A[0]);
    adder.set_input(1, A[1]);
    adder.set_input(2, A[2]);
    adder.set_input(3, A[3]);
    adder.set_input(4, B[0]);
    adder.set_input(5, B[1]);
    adder.set_input(6, B[2]);
    adder.set_input(7, B[3]);

    // Verify output
    unsigned short int expectedSum[4] = {1, 1, 1, 0}; // Expected sum: 0011 (decimal 3)
    unsigned short int expectedCarryOut = 0;

    EXPECT_EQ(adder.get_output(0), expectedSum[0]);
    EXPECT_EQ(adder.get_output(1), expectedSum[1]);
    EXPECT_EQ(adder.get_output(2), expectedSum[2]);
    EXPECT_EQ(adder.get_output(3), expectedSum[3]);
    EXPECT_EQ(adder.get_output(4), expectedCarryOut);
}
