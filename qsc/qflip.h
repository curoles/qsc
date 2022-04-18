/**@file
 * @brief     Flip qubit, |0⟩ -> |1⟩, |1⟩ -> |0⟩.
 * @authors   Igor Lesik 2022-2022
 * @copyright Igor Lesik  2022-2022
 *
 *
 */
#pragma once

#include "qsc/defines.h"

namespace qsc {

class QFlip : public Module
{
    typedef QFlip SC_CURRENT_USER_MODULE;

    In<Qubits> in;
    Out<Qubits> out;

public:
    QFlip(const sc_core::sc_module_name& name):
        Module(name), in(), out()
    {
        SC_METHOD(qflip);
        sensitive << in;
    }

    void qflip()
    {
        out = qpp::gt.X * in.read();
    }
};


} // namespace qsc