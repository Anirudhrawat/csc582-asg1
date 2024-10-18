#include <gtest/gtest.h>
#include "../../source/FourBitAdder/intern/HalfAdder.h"

// Test case for Half-Adder
TEST(HalfAdderTest, TruthTable) {
    HalfAdder ha(1);

    // Test case 1: 0 + 0
    ha.set_in1(0);
    ha.set_in2(0);
    ha.update();
    EXPECT_EQ(ha.sum(), 0);
    EXPECT_EQ(ha.carry(), 0);

    // Test case 2: 0 + 1
    ha.set_in1(0);
    ha.set_in2(1);
    ha.update();
    EXPECT_EQ(ha.sum(), 1);
    EXPECT_EQ(ha.carry(), 0);

    // Test case 3: 1 + 0
    ha.set_in1(1);
    ha.set_in2(0);
    ha.update();
    EXPECT_EQ(ha.sum(), 1);
    EXPECT_EQ(ha.carry(), 0);

    // Test case 4: 1 + 1
    ha.set_in1(1);
    ha.set_in2(1);
    ha.update();
    EXPECT_EQ(ha.sum(), 0);
    EXPECT_EQ(ha.carry(), 1);
}
