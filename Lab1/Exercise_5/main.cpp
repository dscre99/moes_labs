#include "systemc.h"
#include "TicToc.h"

int sc_main(int argc, char *argv[]) {
    TicToc TT_instance("TT_instance");

    sc_start(100, SC_NS);

    return 0;
}