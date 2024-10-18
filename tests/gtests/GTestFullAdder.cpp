#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/FullAdder.h"

// Test case for Full-Adder
TEST(FullAdderTest, TruthTable) {
    FullAdder fa(1);

    // Test case 1: 0 + 0 + 0
    fa.set_in1(0);
    fa.set_in2(0);
    fa.carryOut();  // Assume a method set_carry_in exists
    fa.update();
    EXPECT_EQ(fa.sum(), 0);
    EXPECT_EQ(fa.carryOut(), 0);

    // Test case 2: 0 + 1 + 1
    fa.set_in1(0);
    fa.set_in2(1);
    fa.carryOut();
    fa.update();
    EXPECT_EQ(fa.sum(), 0);
    EXPECT_EQ(fa.carryOut(), 1);

    // Test case 3: 1 + 1 + 0
    fa.set_in1(1);
    fa.set_in2(1);
    fa.carryOut();
    fa.update();
    EXPECT_EQ(fa.sum(), 0);
    EXPECT_EQ(fa.carryOut(), 1);

    // Test case 4: 1 + 1 + 1
    fa.set_in1(1);
    fa.set_in2(1);
    fa.carryOut();
    fa.update();
    EXPECT_EQ(fa.sum(), 1);
    EXPECT_EQ(fa.carryOut(), 1);
}
