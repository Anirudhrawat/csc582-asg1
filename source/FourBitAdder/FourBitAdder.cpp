#include "FourBitAdder.h"

/* Four-Bit Adder */

/**
 * Constructor for the Four-Bit Adder.
 */
FourBitAdder::FourBitAdder(const unsigned short int id)
    : m_fullAdder1(id), m_fullAdder2(id + 1), m_fullAdder3(id + 2), m_fullAdder4(id + 3) {
    m_strID = std::to_string(id) + "FourBitAdder";
}

/**
 * Destructor for Four-Bit Adder.
 */
FourBitAdder::~FourBitAdder() {}

/**
 * Set inputs for the Four-Bit Adder.
 */
void FourBitAdder::set_inputs(unsigned short int A[4], unsigned short int B[4], unsigned short int CarryIn) {
    // Set inputs for each Full-Adder
    m_fullAdder1.set_in1(A[0]);
    m_fullAdder1.set_in2(B[0]);
    m_fullAdder1.m_usiOut = CarryIn;  // Set CarryIn for the first Full-Adder

    m_fullAdder2.set_in1(A[1]);
    m_fullAdder2.set_in2(B[1]);

    m_fullAdder3.set_in1(A[2]);
    m_fullAdder3.set_in2(B[2]);

    m_fullAdder4.set_in1(A[3]);
    m_fullAdder4.set_in2(B[3]);
}

/**
 * Update method to calculate the final Sum and CarryOut.
 */
void FourBitAdder::update() {
    // Full-Adder 1
    m_fullAdder1.update();
    m_sum[0] = m_fullAdder1.sum();
    unsigned short int carry1 = m_fullAdder1.carryOut();

    // Full-Adder 2
    m_fullAdder2.m_usiOut = carry1; // Pass carry1 as CarryIn
    m_fullAdder2.update();
    m_sum[1] = m_fullAdder2.sum();
    unsigned short int carry2 = m_fullAdder2.carryOut();

    // Full-Adder 3
    m_fullAdder3.m_usiOut = carry2; // Pass carry2 as CarryIn
    m_fullAdder3.update();
    m_sum[2] = m_fullAdder3.sum();
    unsigned short int carry3 = m_fullAdder3.carryOut();

    // Full-Adder 4
    m_fullAdder4.m_usiOut = carry3; // Pass carry3 as CarryIn
    m_fullAdder4.update();
    m_sum[3] = m_fullAdder4.sum();
    m_carryOut = m_fullAdder4.carryOut(); // Final CarryOut
}

/**
 * Get the sum bit at a specific index.
 */
unsigned short int FourBitAdder::get_sum(int index) const {
    if (index >= 0 && index < 4) {
        return m_sum[index];
    }
    return 0;
}

/**
 * Get the final CarryOut.
 */
unsigned short int FourBitAdder::get_carry_out() const {
    return m_carryOut;
}