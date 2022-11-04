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

void TLC_tb::red_on_green_monitor(void)
{
    extern int errors;
    if ((main_light.read() == GREEN) && ((sec_light.read() != RED)))
    {
        errors++;
        cout << "ERROR: secondary light is " << sec_light.read()
             << " while main light is GREEN" << endl;
    }
    else if ((main_light.read() != RED) && ((sec_light.read() == GREEN)))
    {
        errors++;
        cout << "ERROR: main light is " << main_light.read()
             << " while secondary light is GREEN" << endl;
    }
}

void TLC_tb::minimum_green_main_monitor(void)
{
    extern int errors;

    while (1)
    {
        wait(main_light->value_changed_event());
        if (main_light.read() == GREEN)
        {
            wait(10, SC_SEC);
            if (main_light.read() != GREEN)
            {
                errors++;
                cout << "ERROR: main light does not remain GREEN for 10 seconds" << endl;
            }
        }
    }
}

void TLC_tb::minimum_green_sec_monitor(void)
{
    extern int errors;

    while (1)
    {
        wait(sec_light->value_changed_event());
        if (sec_light.read() == GREEN)
        {
            wait(10, SC_SEC);
            if (sec_light.read() != GREEN)
            {
                errors++;
                cout << "ERROR: secondary light does not remain GREEN for 10 seconds" << endl;
            }
        }
    }
}