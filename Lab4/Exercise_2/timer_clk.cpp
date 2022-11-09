#include "timer_clk.h"

void TIMER_CLK::TIMER_CLK_run(){
    int count = 0;
    sec_5.write(false);

    while (1)
    {
        wait();
        if(count == 0){
            sec_5.write(false);
        }
        count++;
        if(count >= N_SECS*TICS_PER_SEC){
            sec_5.write(true);
            count = 0;
        }
    }
    
}