#include "systemc.h"
#include "utils.h"
#include "Abstract_TCL.h"
#include "OS_Drivers.h"

int sc_main(int argc, char *argv[]){
    Abstract_TLC TLC("TLC");
    OS_Drivers TB("TB");

    TLC.car(TB);
    TLC.timer(TB);
    TLC.main_light(TB.main_exp);
    TLC.secondary_light(TB.secondary_exp);

    sc_start(100, SC_SEC);
    return 0;
}