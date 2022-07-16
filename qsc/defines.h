/**@file
 * @brief     Quantum System common definitions.
 * @authors   Igor Lesik 2022-2022
 * @copyright Igor Lesik  2022-2022
 *
 *
 */
#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#include "systemc"
#include "qpp/qpp.h"
#pragma GCC diagnostic pop

namespace qsc {

using Module = sc_core::sc_module;

template <class T> using In = sc_core::sc_in<T>;
template <class T> using Out = sc_core::sc_out<T>;

template <class T> using Signal = sc_core::sc_signal<T>;

using Qubits = Eigen::VectorXcd;//qpp::ket;

using QSignal = Signal<Qubits>;

} // namespace qsc

inline std::ostream& operator << (std::ostream& os, const qsc::Qubits& qubits) {
    os << qpp::disp(qubits);
    return os;
}

namespace sc_core {

inline void sc_trace(sc_core::sc_trace_file* tf, const qsc::Qubits& /*qubits*/, const std::string& name) {
    sc_core::sc_trace(tf, "FIXME"/*qubits.to_string()*/, name);
}

inline void sc_trace(sc_core::sc_trace_file* /*tf*/, const std::vector<double>&, const std::string& /*name*/) {
    //FIXME
}

}

