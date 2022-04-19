/**@file
 * @brief     CNOT gate, |10⟩ -> |11⟩, |11⟩ -> |10⟩.
 * @authors   Igor Lesik 2022-2022
 * @copyright Igor Lesik  2022-2022
 *
 *
 */
#pragma once

#include "qsc/defines.h"

namespace qsc {

class QCNot : public Module
{
    typedef QCNot SC_CURRENT_USER_MODULE;

    In<Qubits> in{"in"};
    Out<Qubits> out{"out"};

public:
    QCNot(const sc_core::sc_module_name& name):
        Module(name)
    {
        SC_METHOD(cnot);
        sensitive << in;
    }

    void cnot()
    {
        out = qpp::gt.CNOT * in.read();
        //std::cout << "in:\n" << in.read() << "\nout:\n" << out.read() << std::endl;
    }
};


} // namespace qsc