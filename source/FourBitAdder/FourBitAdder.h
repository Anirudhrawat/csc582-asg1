/* add your code */

// Note that you will need intermediate classes as well
// for the half-adder and full-adder circuits.
#ifndef _FOURBITADDER_H_
#define _FOURBITADDER_H_

#include "FullAdder.h"
#include <string>

class FourBitAdder {
public:
    FourBitAdder(const unsigned short int id);
    virtual ~FourBitAdder();

    void set_inputs(unsigned short int A[4], unsigned short int B[4], unsigned short int CarryIn);
    void update();

    unsigned short int get_sum(int index) const; // Get specific Sum bit
    unsigned short int get_carry_out() const;    // Get the final CarryOut

private:
    std::string m_strID;
    FullAdder m_fullAdder1;
    FullAdder m_fullAdder2;
    FullAdder m_fullAdder3;
    FullAdder m_fullAdder4;

    unsigned short int m_sum[4];
    unsigned short int m_carryOut;
};

#endif /* _FOURBITADDER_H_ */
