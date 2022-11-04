#include "systemc.h"
#include <iostream>
#include "utils.h"
#include <unistd.h>
#include <string>
#include <ctime>
using std::cout;
using std::endl;
using std::cerr;
using std::string;

SC_MODULE(Printer), virtual public light_if {
    std::time_t start_time = std::time(nullptr);
    SC_CTOR(Printer){ }
    virtual void set(color c){
        std::time_t actual_time = std::time(nullptr);
        std::asctime(std::localtime(&actual_time));
        cout << actual_time-start_time << " s - " << name() << ": " << colors[c] << endl;
    }
    virtual void reset(){
        std::asctime(std::localtime(&start_time));
    }
};

SC_MODULE(OS_Drivers), public timer_if, public car_if {
    sc_export<light_if> main_exp, secondary_exp;
    Printer main_chan, secondary_chan;
    SC_CTOR(OS_Drivers): main_chan("main_chan"), secondary_chan("secondary_chan"){
        main_exp(main_chan);
        secondary_exp(secondary_chan);
    }
    virtual void wait_for_sec(unsigned int secs) {
        sleep(secs);
    }

    virtual void wait_for_car() {
        cerr << "Press key+enter when car arrives";
        string s;
        cin >> s;
    }

    virtual void reset() {
        secondary_chan.set(RED);
        main_chan.set(GREEN);
    }
};