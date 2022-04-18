/**@file
 * @brief     Test X gate (Quantum Flip).
 * @author    Igor Lesik 2022-2022
 * @copyright Igor Lesik 2022-2022
 */
#include "qsc/qsystemc.h"

using namespace qpp;
using namespace qsc;

SC_MODULE(QFlipDriver)
{
    Out<Qubits> out{"out"};

    SC_CTOR(QFlipDriver)
    {
        SC_THREAD(drive);
    }

    void drive()
    {
        while (true) {
            out.write(0_ket);
            wait(1, sc_core::SC_NS);
            out.write(1_ket);
            wait(1, sc_core::SC_NS);
        }
    }
};

SC_MODULE(QFlipMonitor)
{
    In<qsc::Qubits> in{"in"}, out{"out"};

    SC_CTOR(QFlipMonitor)
    {
        SC_METHOD(monitor);
        sensitive << in << out;
        dont_initialize();
    }

    void monitor()
    {
        std::cout << "@ " << sc_core::sc_time_stamp() << "\n"
        << "input:\n" << in.read() << "\n"
        << "output:\n" << out.read()
        << std::endl;
    }
};

int sc_main(int /*argc*/, char* /*argv*/[])
{
    using namespace qsc;

    QSignal in{"in", Eigen::VectorXcd {2}};
    QSignal out{"out", Eigen::VectorXcd {2}};

    QFlip qflip("qflip");
    qflip(in, out);

    QFlipDriver driver("driver");
    driver(in);

    QFlipMonitor monitor("monitor");
    monitor(in, out);

    sc_core::sc_start(3, sc_core::SC_NS);

    return 0;
}
