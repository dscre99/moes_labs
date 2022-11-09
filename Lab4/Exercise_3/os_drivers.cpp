#include "os_drivers.h"
#include "utils.h"
#include <thread>
#include <chrono>
#include <string>

void OS_DRIVERS::set_main(color c)
{
    std::time_t actual_time = std::time(nullptr);
    std::asctime(std::localtime(&actual_time));
    cout << "@" << actual_time - start_time << "s main " << COLORS[c] << endl;
}

void OS_DRIVERS::set_sec(color c)
{
    std::time_t actual_time = std::time(nullptr);
    std::asctime(std::localtime(&actual_time));
    cout << "@" << actual_time - start_time << "s sec " << COLORS[c] << endl;
}

void OS_DRIVERS::wait_for_sec(unsigned int secs)
{
    std::this_thread::sleep_for(std::chrono::seconds(secs));
}

void OS_DRIVERS::wait_for_car()
{
    cerr << "Press a key and enter when a car arrives ";
    std::string s;
    cin >> s;
}