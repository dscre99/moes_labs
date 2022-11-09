#include "systemc.h"

#ifndef TIMER_CLK_H
#define TIMER_CLK_H

#define TICS_PER_SEC 1000000    // 1 Mhz clk
#define N_SECS 5

SC_MODULE(TIMER_CLK){
    sc_in<bool> clk;
    sc_in<bool> start;
    sc_out<bool> sec_5;

    SC_CTOR(TIMER_CLK){
        SC_THREAD(TIMER_CLK_run);
        sensitive << clk.pos();
    }

    void TIMER_CLK_run();
};

#endif