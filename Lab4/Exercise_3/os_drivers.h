#ifndef OS_DRIVERS_H
#define OS_DRIVERS_H

#include "systemc.h"
#include "interfaces.h"
#include <ctime>

SC_MODULE(OS_DRIVERS),
    virtual light_if,
    virtual timer_if,
    virtual car_if
{

    std::time_t start_time = std::time(nullptr);
    SC_CTOR(OS_DRIVERS) {}

    void set_main(color);
    void set_sec(color);
    void wait_for_sec(unsigned int);
    void wait_for_car();
};

#endif
