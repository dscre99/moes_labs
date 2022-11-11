#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H

// Here you must implement the timer_driver, withhave a port of type bus.

#include "systemc.h"
#include "interfaces.h"
#include <utils.h>

SC_MODULE(TIMER_DRIVER), virtual timer_if
{
    sc_port<bus_if> bus;

    SC_CTOR(TIMER_DRIVER) : bus("bus") {}

    virtual void wait_for_sec(unsigned int s)
    {
        bus->write(TIMER_MAX_VALUE_ADDR, s * CLK_PER_SEC);
        bus->write(TIMER_CONTROL_ADDR, 0); // one-shot timer setup
        bus->write(TIMER_COUNTER_ADDR, 0); // restarts timer

        while (!(bus->read(TIMER_CONTROL_ADDR)[2]))
        {
            wait(1, SC_US);
        }
    }
};

#endif
