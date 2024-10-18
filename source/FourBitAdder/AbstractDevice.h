#ifndef _ABSTRACTDEVICE_H_
#define _ABSTRACTDEVICE_H_

#include <vector>

class AbstractDevice {
public:
    AbstractDevice(int numInputs, int numOutputs);
    virtual ~AbstractDevice();

    // Methods to set inputs and automatically update outputs
    void set_input(int index, unsigned short int value);
    unsigned short int get_input(int index) const;

    // Get specific output or all outputs
    unsigned short int get_output(int index) const;
    const std::vector<unsigned short int>& get_all_outputs() const;

protected:
    // Pure virtual function to be defined by derived classes
    virtual void update() = 0;

    // Input and output storage
    std::vector<unsigned short int> m_inputs;
    std::vector<unsigned short int> m_outputs;
};

#endif /* _ABSTRACTDEVICE_H_ */
