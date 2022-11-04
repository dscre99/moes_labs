#include "systemc.h"
#include <iostream>
#include <TLC.h>
#include <TLC_tb.h>
#include <utils.h>
#define SIM_NAME "TLC"

unsigned errors = 0;

int sc_main(int argc, char* argv[]){
    cout << "INFO: Elaborating " << SIM_NAME << endl;

    // modules and channels definitions
    sc_signal<color> channel_main_light;
    sc_signal<color> channel_sec_light;
    sc_signal<bool> channel_car;
    TLC TLC_instance("TLC_instance");
    TLC_tb TLC_tb_instance("TLC_tb_instance");

    // modules connections
    TLC_instance.main_light(channel_main_light);
    TLC_instance.sec_light(channel_sec_light);
    TLC_instance.car(channel_car);
    TLC_tb_instance.main_light(channel_main_light);
    TLC_tb_instance.sec_light(channel_sec_light);
    TLC_tb_instance.car(channel_car);
    
    // simulation
	cout << "INFO: Simulating " << SIM_NAME << endl;
	sc_start();

    // stats
    cout << "INFO: Post-processing " << SIM_NAME << endl;
	cout << "INFO: Simulation " << SIM_NAME
		 << " " << (errors? "FAILED":"PASSED")
		 << " with " << errors << " errors"
		 << endl;

	return 0;
}