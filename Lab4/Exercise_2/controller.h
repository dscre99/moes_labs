#include "systemc.h"
#include "utils.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

SC_MODULE(CONTROLLER)
{
    sc_in<bool> car;
    sc_out<color> M;
    sc_out<color> S;
    sc_out<bool> start;
    sc_in<bool> sec_5;

    SC_CTOR(CONTROLLER) : car("car"), M("M"), S("S"), start("start"), sec_5("sec_5")
    {
        SC_THREAD(CONTROLLER_run);
    }

    void CONTROLLER_run();
};

#endif