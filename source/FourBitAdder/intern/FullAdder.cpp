#include "FullAdder.h"

/** Full-Adder **/

/**
 * Constructor for concrete class FullAdder.
 */
FullAdder::FullAdder(const unsigned short int id)
    : m_halfAdder1(id), m_halfAdder2(id + 1), m_orGate(id + 2) {
    m_strID = std::to_string(id) + "FullAdder";
}

/**
 * Destructor for concrete class FullAdder.
 */
FullAdder::~FullAdder() {}

/**
 * Update method to calculate Sum and CarryOut.
 */
void FullAdder::update() {
    // First Half-Adder to add A and B
    m_halfAdder1.set_in1(m_usiIn1);
    m_halfAdder1.set_in2(m_usiIn2);
    m_halfAdder1.update();

    unsigned short int sum1 = m_halfAdder1.sum();    // Partial Sum from the first half-adder
    unsigned short int carry1 = m_halfAdder1.carry(); // Carry from the first half-adder

    // Second Half-Adder to add sum1 and CarryIn
    m_halfAdder2.set_in1(sum1);
    m_halfAdder2.set_in2(m_usiOut); // Assume this represents CarryIn
    m_halfAdder2.update();

    unsigned short int sum2 = m_halfAdder2.sum();    // Final Sum
    unsigned short int carry2 = m_halfAdder2.carry(); // Second Carry

    // OR Gate to determine the final CarryOut
    m_orGate.set_in1(carry1);
    m_orGate.set_in2(carry2);
    m_orGate.update();

    // Set the final Sum and CarryOut
    m_usiOut = sum2; // Sum result
}