#include "controller.h"

void CONTROLLER::CONTROLLER_run(){
    // reset configuration
    S.write(RED);
    M.write(GREEN);
    start.write(false);

    while (1)
    {
        // waits 5 seconds
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());        
        // waits 5 more seconds (GREEN is 10 secs at least)
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());
        // if car is not present waits for car
        if(!car){
            //cout << "waiting for car" << endl;
            wait(car.posedge_event());
        }
        M.write(YELLOW);
        // waits 5 seconds for main YELLOW
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());
        M.write(RED);
        S.write(GREEN);
        // waits 5 seconds
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());
        // waits 5 more seconds (secondary GREEN is 10 secs sharp)
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());
        S.write(YELLOW);
        // waits 5 seconds for main YELLOW
        start.write(true);
        wait(SC_ZERO_TIME);
        start.write(false);
        wait(sec_5.posedge_event());
        S.write(RED);
        M.write(GREEN);
    }
    
}