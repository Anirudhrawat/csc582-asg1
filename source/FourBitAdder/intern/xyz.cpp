#include "HalfAdder.h"
#include <iostream>

int main() {
    HalfAdder ha(1);
    ha.set_in1(1);
    ha.set_in2(0);
    ha.update();
    std::cout << "Sum: " << ha.sum() << ", Carry: " << ha.carry() << std::endl;
    return 0;
}