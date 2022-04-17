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
#pragma GCC diagnostic pop

namespace qsc {

using Module = sc_core::sc_module;

template <class T> using In = sc_core::sc_in<T>;
template <class T> using Out = sc_core::sc_out<T>;

template <class T> using Signal = sc_core::sc_signal<T>;

} // namespace qsc
