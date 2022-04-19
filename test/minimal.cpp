#include <iostream>

#include "qsc/qsystemc.h"

int sc_main(int, char**) {
    using namespace qpp;

    std::cout << "This is the |0⟩ state:\n";
    std::cout << disp(0_ket) << '\n';

    cmat U = gt.X;
    ket result = U * 0_ket;

    std::cout << ">> The result of applying the bit-flip gate X on |0⟩ is:\n";
    std::cout << disp(result) << '\n';

    return 0;
}