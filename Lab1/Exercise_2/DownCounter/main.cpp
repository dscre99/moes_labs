#include "systemc.h"
#include "DownCounter.h"

int sc_main(int argc, char *argv[]) {
    // elaboration stage
    DownCounter counterInstance("counterInstance");

    // simulation stage
    sc_start();

    return 0;
}