#include <TLC.h>

void TLC::ManageTraffic(void)
{
    // initialization
    sec_light.write(RED);
    main_light.write(GREEN);

    while (1)
    {

        wait(10, SC_SEC);

        if (!car.read())
        {
            wait(car.posedge_event());
        }

        main_light.write(YELLOW);
        wait(5, SC_SEC);
        main_light.write(RED);
        sec_light.write(GREEN);
        wait(10, SC_SEC);
        sec_light.write(YELLOW);
        wait(5, SC_SEC);
        sec_light.write(RED);
        main_light.write(GREEN);
    }
}