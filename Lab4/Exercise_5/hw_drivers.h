#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

// This is the same as in exercise 4, but without implementing the timer
// interface

#include "systemc.h"
#include "interfaces.h"
#include "utils.h"

SC_MODULE(HW_DRIVERS), virtual light_if, virtual car_if
{
    sc_in<bool> car;
    sc_out<color> M;
    sc_out<color> S;

    SC_CTOR(HW_DRIVERS) : car("car"), M("M"), S("S") {}

    virtual void wait_for_car()
    {
        if (!car)
        {
            wait(car.posedge_event());
        }
    }

    virtual void set_main(color c)
    {
        M.write(c);
    }

    virtual void set_sec(color c)
    {
        S.write(c);
    }
};

#endif
