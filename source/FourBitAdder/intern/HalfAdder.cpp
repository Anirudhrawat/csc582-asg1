#include "HalfAdder.h"

/** Half-Adder **/

/**
 * Constructor for concrete class HalfAdder.
 */
HalfAdder::HalfAdder(const unsigned short int id)
    : m_andGate(id), m_nandGate(id), m_orGate(id) {
    m_strID = std::to_string(id) + "HalfAdder";
}

/**
 * Destructor for concrete class HalfAdder.
 */
HalfAdder::~HalfAdder() {}

/**
 * Update method to calculate Sum and Carry.
 */
void HalfAdder::update() {
    // Sum = A XOR B
    // XOR can be implemented as: (A NAND B) AND (A OR B)
    m_nandGate.set_in1(m_usiIn1);
    m_nandGate.set_in2(m_usiIn2);
    m_nandGate.update();

    m_orGate.set_in1(m_usiIn1);
    m_orGate.set_in2(m_usiIn2);
    m_orGate.update();

    // To achieve XOR using NAND and OR
    m_andGate.set_in1(m_nandGate.out());
    m_andGate.set_in2(m_orGate.out());
    m_andGate.update();

    // The Sum is the output of the XOR logic
    m_usiOut = m_andGate.out(); // Sum output

    // Carry = A AND B
    m_andGate.set_in1(m_usiIn1);
    m_andGate.set_in2(m_usiIn2);
    m_andGate.update();
}

/**
 * Accessor for Sum output.
 */
unsigned short int HalfAdder::sum() const {
    return m_usiOut;
}

/**
 * Accessor for Carry output.
 */
unsigned short int HalfAdder::carry() const {
    return m_andGate.out();
}

/**
 * Representation method.
 */
std::string HalfAdder::repr() {
    std::string rp = AbstractGate::repr();
    return "id: " + m_strID + "\n\t" + rp;
}