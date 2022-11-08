#include "systemc.h"

#ifndef TIMER_H
#define TIMER_H

SC_MODULE(TIMER)
{
    sc_in<bool> start;
    sc_out<bool> sec_5;

    SC_CTOR(TIMER) : start("start"), sec_5("sec_5")
    {
        SC_THREAD(TIMER_run);
    }

    void TIMER_run();
};

#endif