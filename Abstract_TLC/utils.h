#include "systemc.h"

#if !defined(LIGHT_COLORS)
#define LIGHT_COLORS

enum color
{
    RED = 0,
    YELLOW = 1,
    GREEN = 2
};

inline const char *colors[] = {"RED", "YELLOW", "GREEN"};

class light_if : virtual public sc_interface
{
public:
    virtual void set(color) = 0;
    virtual void reset() = 0;
};

struct timer_if : virtual public sc_interface
{
    virtual void wait_for_sec(unsigned int) = 0;
    virtual void reset() = 0;
};

struct car_if : virtual public sc_interface
{
    virtual void wait_for_car() = 0;
    virtual void reset() = 0;
};

#endif // LIGHT_COLORS
