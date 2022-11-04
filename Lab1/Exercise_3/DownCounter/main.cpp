#include "systemc.h"
#include "DownCounter.h"

int sc_main(int argc, char *argv[]) {
    // elaboration stage
    sc_set_time_resolution(1,SC_NS);
    DownCounter counterInstance("counterInstance");

    cout << "Time resolution is " << sc_get_time_resolution() << endl;

    // simulation stage
    cout << "Starting DownCounter simulation with delay" << endl;
    sc_start();
    cout << "Exiting DownCounter simulation with delay." << endl;
    cout << "Simulator finished at " << sc_time_stamp() << endl;

    return 0;
}