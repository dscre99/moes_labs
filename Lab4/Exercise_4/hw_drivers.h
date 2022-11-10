#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// Here you must implement a module that implements all three interfaces
// and has 3 I/O signals for car, main and secondary

#include "systemc.h"
#include "utils.h"
#include "interfaces.h"

SC_MODULE(HW_DRIVERS),
    virtual light_if,
    virtual timer_if,
    virtual car_if
{
    sc_in<bool> clk;
    sc_in<bool> car;
    sc_out<color> M;
    sc_out<color> S;

    SC_CTOR(HW_DRIVERS) : clk("clk"), car("car"), M("M"), S("S") {}

    void set_main(color);
    void set_sec(color);
    void wait_for_sec(unsigned int);
    void wait_for_car();
};

#endif
