#include "systemc.h"
#include "interfaces.h"

SC_MODULE(PIO_PERIPHERAL), virtual bus_if
{

    // dummy peripheral implementation for TB binding purposes

    SC_CTOR(PIO_PERIPHERAL) {}

    virtual void write(sc_uint<32> addr, sc_uint<32> data)
    {
        return;
    }

    virtual sc_uint<32> read(sc_uint<32> addr)
    {
        return 0;
    }
};
