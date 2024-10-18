#include "FourBitAdder.h"

/** Four-Bit Adder **/

/**
 * Constructor for the Four-Bit Adder.
 */
FourBitAdder::FourBitAdder(const unsigned short int id)
    : AbstractDevice(8, 5), // 8 inputs (4 from A, 4 from B), 5 outputs (4 Sum, 1 CarryOut)
      m_fullAdder1(id), m_fullAdder2(id + 1), m_fullAdder3(id + 2), m_fullAdder4(id + 3) {}

/**
 * Destructor for Four-Bit Adder.
 */
FourBitAdder::~FourBitAdder() {}

/**
 * Update method to calculate the final Sum and CarryOut.
 */
void FourBitAdder::update() {
    unsigned short int A[4] = {m_inputs[0], m_inputs[1], m_inputs[2], m_inputs[3]};
    unsigned short int B[4] = {m_inputs[4], m_inputs[5], m_inputs[6], m_inputs[7]};

    // Full-Adder 1
    m_fullAdder1.set_in1(A[0]);
    m_fullAdder1.set_in2(B[0]);
    m_fullAdder1.m_usiOut = 0; // CarryIn = 0 (Assuming m_usiOut holds the CarryIn value)
    m_fullAdder1.update();
    m_outputs[0] = m_fullAdder1.sum(); // Sum
    unsigned short int carry1 = m_fullAdder1.carryOut();

    // Full-Adder 2
    m_fullAdder2.set_in1(A[1]);
    m_fullAdder2.set_in2(B[1]);
    m_fullAdder2.m_usiOut = carry1; // CarryIn from previous Full-Adder
    m_fullAdder2.update();
    m_outputs[1] = m_fullAdder2.sum();
    unsigned short int carry2 = m_fullAdder2.carryOut();

    // Full-Adder 3
    m_fullAdder3.set_in1(A[2]);
    m_fullAdder3.set_in2(B[2]);
    m_fullAdder3.m_usiOut = carry2; // CarryIn from previous Full-Adder
    m_fullAdder3.update();
    m_outputs[2] = m_fullAdder3.sum();
    unsigned short int carry3 = m_fullAdder3.carryOut();

    // Full-Adder 4
    m_fullAdder4.set_in1(A[3]);
    m_fullAdder4.set_in2(B[3]);
    m_fullAdder4.m_usiOut = carry3; // CarryIn from previous Full-Adder
    m_fullAdder4.update();
    m_outputs[3] = m_fullAdder4.sum();
    m_outputs[4] = m_fullAdder4.carryOut(); // Final CarryOut
}
