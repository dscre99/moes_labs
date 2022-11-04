#include "TicToc.h"

void TicToc::node1(void) {
    const sc_time t_1NS(1, SC_NS);
    sc_time t_DELAY(10*t_1NS);

    for(;;){
        cout << "Node1 UP @ " << sc_time_stamp() << endl;
        wait(t_DELAY);
        cout << "Node1 DOWN @ " << sc_time_stamp() << endl;
        evt_wakeup_tic.notify(SC_ZERO_TIME);
        wait(evt_wakeup_toc);
    }
}

void TicToc::node2(void) {
    const sc_time t_1NS(1, SC_NS);
    sc_time t_DELAY(10*t_1NS);

    for(;;) {
        wait(evt_wakeup_tic);
        cout << "Node2 UP @ " << sc_time_stamp() << endl;
        wait(t_DELAY);
        cout << "Node2 DOWN @ " << sc_time_stamp() << endl;
        evt_wakeup_toc.notify(SC_ZERO_TIME);
    }

}