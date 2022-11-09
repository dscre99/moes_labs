#ifndef TLM_TLC_H
#define TLM_TLC_H

#include "systemc.h"
#include "utils.h"
#include "interfaces.h"

SC_MODULE(TLC_SW)
{
    sc_port<car_if> car;
    sc_port<timer_if> timer;
    sc_port<light_if> light;

    SC_CTOR(TLC_SW) : car("car"), timer("timer"), light("light")
    {
        SC_THREAD(controller);
    }

    void controller();
};

#endif
