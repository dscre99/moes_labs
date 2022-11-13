#ifndef BUS_H
#define BUS_H

// This must implement the bus interface and have a port of type bus called
// timer.

#include "systemc.h"
#include "interfaces.h"
#include <utils.h>

SC_MODULE(BUS), virtual bus_if
{
    sc_port<bus_if> timer;
    sc_port<bus_if> PIO;

    SC_CTOR(BUS) : timer("timer"), PIO("PIO") {}

    void write(sc_uint<32> addr, sc_uint<32> data)
    {
        switch (addr)
        {
        case TIMER_COUNTER_ADDR:
            timer->write(0, data);
            break;

        case TIMER_MAX_VALUE_ADDR:
            timer->write(1, data);
            break;

        case TIMER_CONTROL_ADDR:
            timer->write(2, data);
            break;

        case PIO_DIR_ADDR:
            PIO->write(0, data);
            break;

        case PIO_DATA_ADDR:
            PIO->write(1, data);
            break;

        default:
            cerr << "ERROR: unknown BUS write address (" << addr << ")" << endl;
            break;
        }
    }

    sc_uint<32> read(sc_uint<32> addr)
    {
        sc_uint<32> result = 0;

        switch (addr)
        {
        case TIMER_COUNTER_ADDR:
            result = timer->read(0);
            break;

        case TIMER_MAX_VALUE_ADDR:
            result = timer->read(1);
            break;

        case TIMER_CONTROL_ADDR:
            result = timer->read(2);
            break;

        case PIO_DIR_ADDR:
            result = PIO->read(0);
            break;

        case PIO_DATA_ADDR:
            result = PIO->read(1);
            break;

        default:
            cerr << "ERROR: unknown BUS read address (" << addr << ")" << endl;
            break;
        }

        return result;
    }
};

#endif
