#include <Abstract_TCL.h>

void Abstract_TLC::controller()
{
    main_light->reset();
    secondary_light->reset();
    car->reset();
    timer->reset();

    while (1)
    {
        secondary_light->set(RED);
        main_light->set(GREEN);
        timer->wait_for_sec(10);
        car->wait_for_car();
        main_light->set(YELLOW);
        timer->wait_for_sec(5);
        main_light->set(RED);
        secondary_light->set(GREEN);
        timer->wait_for_sec(10);
        secondary_light->set(YELLOW);
        timer->wait_for_sec(5);
    }
}