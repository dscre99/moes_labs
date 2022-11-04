#include "DownCounter.h"
using std::cout;
using std::endl;

void DownCounter::count_down_behav(void) {
    const sc_time t_1NS(1,SC_NS);
    sc_time t_DELAY(20*t_1NS);

    cout << "INFO: time is " << sc_time_stamp() << endl;


    for (int i = 3; i >= 0; i--)
    {
        cout << "Count:: " << i << "  ";
        cout << "INFO: delaying " << t_DELAY << endl;
        wait(t_DELAY);
        cout << "INFO: time is " << sc_time_stamp() << endl;
    }
    
}