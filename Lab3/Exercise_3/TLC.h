#include "systemc.h"
#include <iostream>
#include <utils.h>
using std::cout;
using std::endl;

SC_MODULE(TLC)
{
public:
    sc_in<bool> car;
    sc_out<color> main_light;
    sc_out<color> sec_light;

public:
    SC_CTOR(TLC) : car("car"), main_light("main_light"), sec_light("sec_light")
    {
        SC_THREAD(ManageTraffic);
    };

    void ManageTraffic(void);
};