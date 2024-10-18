/*
 * LogicGates.h
 *
 *  Created on: Jun 14, 2020
 *      Author: brad
 */

#ifndef LOGICGATES_H
#define LOGICGATES_H

#include <string>
#include "../../FourBitAdder/intern/AbstractGate.h"

class AND: public AbstractGate
{
public:
    /**
     * Constructor for concrete class AND.
     */
    AND(const unsigned short int);
    virtual ~AND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class NAND: public AbstractGate
{
public:
    friend class NOT;
    NAND(const unsigned short int);
    virtual ~NAND();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class OR: public AbstractGate
{
public:
    OR(const unsigned short int);
    virtual ~OR();

protected:
    std::string m_strID;

    virtual void update();
    virtual std::string repr();
};

class NOT: public AbstractGate {
public:
    NOT(const unsigned short int);
    virtual ~NOT();

protected:
    std::string m_strID;
    NAND m_nandGate;

    virtual void update();
    virtual std::string repr();
};
#endif /* LOGICGATES_H */