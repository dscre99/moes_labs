#include "hw_drivers.h"
#define CLK_PER_SEC 1000000 // 1MHz

void HW_DRIVERS::set_main(color c)
{
    M.write(c);
}

void HW_DRIVERS::set_sec(color c)
{
    S.write(c);
}

void HW_DRIVERS::wait_for_sec(unsigned int s)
{
    for (unsigned int i = 0; i < CLK_PER_SEC * s; i++)
    {
        wait(clk.posedge_event());
    }
}

void HW_DRIVERS::wait_for_car()
{
    while (car.read() == false)
    {
        wait(car.posedge_event());
    }
}
