#ifndef HALFADDER_H
#define HALFADDER_H

#include <string>
#include "AbstractGate.h" 
#include "LogicGates.h"

class HalfAdder : public AbstractGate {
public:
    HalfAdder(const unsigned short int id);
    virtual ~HalfAdder();

    unsigned short int sum() const;    
    unsigned short int carry() const;  
    virtual void update() override;
protected:
    std::string m_strID;
    AND m_andGate; 
    OR m_orGate;   
    NAND m_nandGate; 

    
    virtual std::string repr() override;
};

#endif /* HALFADDER_H */