#include "AbstractDevice.h"

AbstractDevice::AbstractDevice(int numInputs, int numOutputs)
    : m_inputs(numInputs, 0), m_outputs(numOutputs, 0) {}

AbstractDevice::~AbstractDevice() {}

void AbstractDevice::set_input(int index, unsigned short int value) {
    if (index >= 0 && index < m_inputs.size()) {
        m_inputs[index] = value;
        update(); // Automatically update outputs when inputs change
    }
}

unsigned short int AbstractDevice::get_input(int index) const {
    if (index >= 0 && index < m_inputs.size()) {
        return m_inputs[index];
    }
    return 0;
}

unsigned short int AbstractDevice::get_output(int index) const {
    if (index >= 0 && index < m_outputs.size()) {
        return m_outputs[index];
    }
    return 0;
}

const std::vector<unsigned short int>& AbstractDevice::get_all_outputs() const {
    return m_outputs;
}
