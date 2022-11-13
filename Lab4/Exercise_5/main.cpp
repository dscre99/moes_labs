#include <systemc.h>
#include "interfaces.h"
#include "../Exercise_3/tlm_tlc.cpp"
#include "timer_driver.h"
#include "hw_drivers.h"
#include "bus.h"
#include "timer_peripheral.h"
#include "../Exercise_1/testbench.h"
#include "pio_peripheral.h"

int sc_main(int argc, char *argv[])
{
	sc_clock clk("clk", sc_time(1, SC_US));
	sc_signal<bool> car("car");
	sc_signal<color> M("Main"), S("Secondary");

	TLC_SW TLC("Controller");
	BUS bus("Bus");
	HW_DRIVERS hw_drivers("Car_and_light_driver");
	TIMER_DRIVER timer_driver("Timer_driver");
	TIMER_PERIPHERAL timer("Timer");
	PIO_PERIPHERAL pio("pio");
	Testbench TB("Testbench");

	timer_driver.bus(bus);

	bus.timer(timer);
	bus.PIO(pio);

	timer.clk(clk);

	hw_drivers.car(car);
	hw_drivers.M(M);
	hw_drivers.S(S);

	TLC.car(hw_drivers);
	TLC.light(hw_drivers);
	TLC.timer(timer_driver);

	TB.Main_road(M);
	TB.Secondary_road(S);
	TB.car(car);

	sc_start();
	return 0;
}
