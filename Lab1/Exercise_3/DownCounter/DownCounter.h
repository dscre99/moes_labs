#include "systemc.h"

SC_MODULE(DownCounter){

    // constructor
    SC_CTOR(DownCounter){
        SC_THREAD(count_down_behav);
    }

    void count_down_behav(void);
};