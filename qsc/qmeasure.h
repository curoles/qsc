/**@file
 * @brief     Quantum measurement.
 * @authors   Igor Lesik 2022-2022
 * @copyright Igor Lesik  2022-2022
 *
 *
 */
#pragma once

#include "qsc/defines.h"

namespace qsc {

class QMeasureBit : public Module
{
    typedef QMeasureBit SC_CURRENT_USER_MODULE;

    In<Qubits> in{"in"};
    In<unsigned int> pos{"pos"};
    Out<unsigned int> result{"result"};
    Out<std::vector<double> > probabilities{"probabilities"};

public:
    QMeasureBit(const sc_core::sc_module_name& name):
        Module(name)
    {
        SC_METHOD(measure);
        sensitive << in;
    }

    void measure()
    {
        auto measured = qpp::measure(in.read(), qpp::gt.H, {(qpp::idx)pos.read()});
        result = std::get<qpp::RES>(measured);
        probabilities = std::get<qpp::PROB>(measured);
        //std::cout << "in:\n" << in.read() << "\nout:\n" << out.read() << std::endl;
    }
};


} // namespace qsc