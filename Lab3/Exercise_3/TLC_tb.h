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
        SC_METHOD(red_on_green_monitor);
        sensitive << main_light << sec_light;
        SC_THREAD(minimum_green_main_monitor);
        SC_THREAD(minimum_green_sec_monitor);
    }

    void input_generator(void);
    void output_monitor(void);
    void red_on_green_monitor(void);
    void minimum_green_main_monitor(void);
    void minimum_green_sec_monitor(void);
};