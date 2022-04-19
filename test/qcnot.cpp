/**@file
 * @brief     Test CNOT gate.
 * @author    Igor Lesik 2022-2022
 * @copyright Igor Lesik 2022-2022
 */
#include "qsc/qsystemc.h"

using namespace qpp;
using namespace qsc;

SC_MODULE(QCNotDriver)
{
    Out<Qubits> out{"out"};

    SC_CTOR(QCNotDriver)
    {
        SC_THREAD(drive);
    }

    void drive()
    {
        while (true) {
            out.write(00_ket);
            wait(1, sc_core::SC_NS);
            out.write(01_ket);
            wait(1, sc_core::SC_NS);
            out.write(10_ket);
            wait(1, sc_core::SC_NS);
            out.write(11_ket);
            wait(1, sc_core::SC_NS);
        }
    }
};

SC_MODULE(QCNotMonitor)
{
    In<qsc::Qubits> in{"in"}, out{"out"};

    SC_CTOR(QCNotMonitor)
    {
        SC_METHOD(monitor);
        sensitive << out;
        dont_initialize();
    }

    void monitor()
    {
        std::cout << "@ " << sc_core::sc_time_stamp() << "\n"
        << "input:\n" << in.read() << "\n"
        << "output:\n" << out.read()
        << std::endl;

        auto in_quibits = in.read();
        auto out_quibits = out.read();
        if (in_quibits == 00_ket) {
            assert(out_quibits == 00_ket);
            std::cout << "|00⟩ -> |00⟩" << std::endl;
        }
        else if (in_quibits == 01_ket) {
            assert(out_quibits == 01_ket);
            std::cout << "|01⟩ -> |01⟩" << std::endl;
        }
        else if (in_quibits == 10_ket) {
            assert(out_quibits == 11_ket);
            std::cout << "|10⟩ -> |11⟩" << std::endl;
        }
        else if (in_quibits == 11_ket) {
            assert(out_quibits == 10_ket);
            std::cout << "|11⟩ -> |10⟩" << std::endl;
        }
        else {assert(0);}
    }
};

int sc_main(int /*argc*/, char* /*argv*/[])
{
    using namespace qsc;

    QSignal in{"in", 00_ket/*Eigen::VectorXcd{4}*/};
    QSignal out{"out", 00_ket/*Eigen::VectorXcd{4}*/};

    QCNot cnot("cnot");
    cnot(in, out);

    QCNotDriver driver("driver");
    driver(in);

    QCNotMonitor monitor("monitor");
    monitor(in, out);

    sc_core::sc_start(5, sc_core::SC_NS);

    return 0;
}
