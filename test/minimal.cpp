#include <iostream>

#include "qpp/qpp.h"

int main() {
    using namespace qpp;

    std::cout << "This is the |0> state:\n";
    std::cout << disp(0_ket) << '\n';
}