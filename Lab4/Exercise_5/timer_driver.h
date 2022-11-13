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
        // cout << "[INFO]: timer_driver writing control @" << sc_time_stamp() << endl;
        // cout << (bus->read(TIMER_CONTROL_ADDR).range(31,2),0,bus->read(TIMER_CONTROL_ADDR)[0]) << endl;
        // NEEDED TO SET ONE-SHOT MODE AND TO RESET OVERFLOW FLAG
        bus->write(TIMER_CONTROL_ADDR, (bus->read(TIMER_CONTROL_ADDR).range(31,3),0,0,bus->read(TIMER_CONTROL_ADDR)[0])); // one-shot timer setup
        bus->write(TIMER_COUNTER_ADDR, 0); // restarts timer
        wait(SC_ZERO_TIME); // NEEDED TO ACTUALLY RESET OVERFLOW FLAG OTHERWISE DEADLOCK OCCURS 
                            //  SINCE NEXT LOOP WOULD ALWAYS BE SKIPPED

        // cout << "[INFO]: start waiting " << s << " seconds" << endl;
        while (!(bus->read(TIMER_CONTROL_ADDR)[2]))
        {
            wait(1, SC_US);
        }
        // cout << "[INFO]: end waiting " << s << " seconds" << endl;
    }
};

#endif
