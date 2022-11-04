#include "systemc.h"
#include <iostream>
#include <utils.h>
using std::cout;
using std::endl;

SC_MODULE(Abstract_TLC){
    public:
        sc_port<car_if> car;
        sc_port<timer_if> timer;
        sc_port<light_if> main_light, secondary_light;

        SC_CTOR(Abstract_TLC){
            SC_THREAD(controller);
        }

    void controller();
};
