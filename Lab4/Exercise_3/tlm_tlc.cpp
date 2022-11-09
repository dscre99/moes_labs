#include "tlm_tlc.h"

void TLC_SW::controller()
{
    while (1)
    {
        light->set_sec(RED);
        light->set_main(GREEN);
        timer->wait_for_sec(10);
        car->wait_for_car();
        light->set_main(YELLOW);
        timer->wait_for_sec(5);
        light->set_main(RED);
        light->set_sec(GREEN);
        timer->wait_for_sec(10);
        light->set_sec(YELLOW);
        timer->wait_for_sec(5);
    }
}