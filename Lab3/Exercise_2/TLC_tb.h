#include "systemc.h"
#include <iostream>
#include <utils.h>
using std::cout;
using std::endl;

SC_MODULE(TLC_tb)
{
public:
    sc_in<color> main_light;
    sc_in<color> sec_light;
    sc_out<bool> car;

public:
    SC_CTOR(TLC_tb) : main_light("main_light"), sec_light("sec_light"), car("car")
    {
        SC_THREAD(input_generator);
        SC_METHOD(output_monitor);
        sensitive << main_light << sec_light;
    }

    void input_generator(void);
    void output_monitor(void);
};