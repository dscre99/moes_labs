#include "timer.h"
using std::cout;
using std::endl;

void TIMER::TIMER_run()
{
    // reset
    sec_5.write(false);

    while (1)
    {
        wait(start.posedge_event());
        //cout << "TIMER starting" << endl;
        sec_5.write(false);
        wait(5, SC_SEC);
        sec_5.write(true);
        wait(SC_ZERO_TIME);
        //cout << "TIMER ended" << endl;
    }
}