#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(TicToc) {

    sc_event evt_wakeup_tic, evt_wakeup_toc;
    
    SC_CTOR(TicToc) {
        SC_THREAD(node1);
        SC_THREAD(node2);
    }

    void node1(void);
    void node2(void);

};