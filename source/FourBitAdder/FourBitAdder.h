#ifndef _FOURBITADDER_H_
#define _FOURBITADDER_H_

#include "AbstractDevice.h"
#include "intern/FullAdder.h"

class FourBitAdder : public AbstractDevice {
public:
    FourBitAdder(const unsigned short int id);
    virtual ~FourBitAdder();

protected:
    // Overriding the update method from AbstractDevice
    virtual void update() override;

private:
    FullAdder m_fullAdder1;
    FullAdder m_fullAdder2;
    FullAdder m_fullAdder3;
    FullAdder m_fullAdder4;
};

#endif /* _FOURBITADDER_H_ */
