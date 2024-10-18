#ifndef FULLADDER_H
#define FULLADDER_H

#include <string>
#include "AbstractGate.h"
#include "HalfAdder.h"

class FullAdder : public AbstractGate {
public:
    FullAdder(const unsigned short int id);
    virtual ~FullAdder();

    unsigned short int sum() const;    // Accessor for the Sum output
    unsigned short int carryOut() const;  // Accessor for the CarryOut output
    virtual void update() override;
protected:
    std::string m_strID;
    HalfAdder m_halfAdder1; // First Half-Adder
    HalfAdder m_halfAdder2; // Second Half-Adder
    OR m_orGate;            // OR Gate to determine final CarryOut

    
    virtual std::string repr() override;
};

#endif /* FULLADDER_H */