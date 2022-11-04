#include <TLC_tb.h>

void TLC_tb::input_generator(void)
{
    car.write(false);
    wait(5, SC_SEC);
    car.write(true);
    cout << "INFO: car arrived at time " << sc_time_stamp() << endl;
    wait(1, SC_SEC);
    car.write(false); // The car leaves before green…
    cout << "INFO: car left at time " << sc_time_stamp() << endl;
    wait(30, SC_SEC);
    car.write(true);
    cout << "INFO: car arrived at time " << sc_time_stamp() << endl;
    wait(60, SC_SEC);
    car.write(false);
    wait(14, SC_SEC);
    sc_stop(); // No more inputs, end simulation
}

void TLC_tb::output_monitor(void)
{
    cout << "[Time: " << sc_time_stamp()
         << "]\n\tMain: " << COLORS[main_light.read()]
         << "\n\tSecondary: " << COLORS[sec_light.read()]
         << "\n\tCar: " << car.read() << endl;
}
