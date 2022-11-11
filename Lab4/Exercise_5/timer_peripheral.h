#ifndef TIMER_PERIPHERAL_H
#define TIMER_PERIPHERAL_H

// This must implement the bus interface for the timer functionality

#include "systemc.h"
#include "interfaces.h"
#include "utils.h"

SC_MODULE(TIMER_PERIPHERAL), virtual bus_if
{
    sc_signal<sc_uint<32>> control;
    sc_signal<sc_uint<32>> max_value;
    sc_signal<sc_uint<32>> counter;
    sc_event start;
    sc_in<bool> clk;

    SC_CTOR(TIMER_PERIPHERAL) : control("control"), max_value("max_value"),
                                counter("counter"), start("start"), clk("clk")
    {
        SC_THREAD(count);
    }

    virtual void write(sc_uint<32> addr, sc_uint<32> data)
    {
        switch (addr)
        {
        case 0:
            counter = data;
            start.notify(SC_ZERO_TIME);
            break;

        case 1:
            max_value = data;
            break;

        case 2:
            control = data;
            break;

        default:
            cerr << "ERROR: unknown TIMER_PERIPHERAL write address (" << addr << ")" << endl;
            break;
        }
    }

    virtual sc_uint<32> read(sc_int<32> addr)
    {
        sc_uint<32> result;

        switch (addr)
        {
        case 0:
            result = counter;
            break;

        case 1:
            result = max_value;
            break;

        case 2:
            result = control;
            break;

        default:
            break;
        }

        return result;
    }

    void count()
    {
        // reset conditions
        counter = 0;
        control = 0;
        max_value = 0;

        wait(start); // wait for initial start
        while (1)
        {
            wait(clk.posedge_event());
            counter.write(counter.read() + 1);
            if (counter.read() + 1 >= max_value.read())
            {
                // notifies overflow
                control.write(control.read().range(31, 3) & 1 & control.read().range(1, 0));
                // resets counter
                counter.write(0);
                if (!control.read()[1])
                {
                    // if not in continuous mode, waits for start event
                    wait(start);
                }
            }
        }
    }
};

#endif
