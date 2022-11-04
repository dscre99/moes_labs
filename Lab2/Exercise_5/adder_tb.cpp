#include "adder_tb.h"

void Adder_1bit_TB::value_generator(void) {

    // gold vectors definitions
    const sc_logic A_gold[8] = {sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_1};
    const sc_logic B_gold[8] = {sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_1};
    const sc_logic Cin_gold[8] = {sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_1};
    const sc_logic Sum_gold[8] = {sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_1};
    const sc_logic Cout_gold[8] = {sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_0,sc_dt::Log_1,sc_dt::Log_1,sc_dt::Log_1};

    // loops through the whole golden vectors' length
    for (int i = 0; i < 8; i++)
    {
        // provides input stimuli
        A->write(A_gold[i]);
        B->write(B_gold[i]);
        Cin->write(Cin_gold[i]);
        wait(1, SC_NS);
        input_change.notify(SC_ZERO_TIME);  // notifies monitor

        // checks Full Adder's output against golden values
        if(Sum->read() != Sum_gold[i]) {
            cout << "*** ERROR: unexpected Sum value ***" << endl;
        }
        if(Cout->read() != Cout_gold[i]) {
            cout << "*** ERROR: unexpected Cout value ***" << endl;
        }

        wait(9, SC_NS);
    }

}

void Adder_1bit_TB::value_monitor(void) {

    // updates monitor with current simulation values
    cout << "A = " << A->read() << " @ " << sc_time_stamp() << endl;
    cout << "B = " << B->read() << " @ " << sc_time_stamp() << endl;
    cout << "Cin = " << Cin->read() << " @ " << sc_time_stamp() << endl;
    cout << "Sum = " << Sum->read() << " @ " << sc_time_stamp() << endl;
    cout << "Cout =" << Cout->read() << " @ " << sc_time_stamp() << endl;
    cout << "--------------------" << endl;

}
