#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Adder_1bit_TB) {
    
    private:
        sc_in<sc_logic> Sum;
        sc_in<sc_logic> Cout;
        sc_out<sc_logic> A;
        sc_out<sc_logic> B;
        sc_out<sc_logic> Cin;
        sc_event input_change;

    public:
        SC_CTOR(Adder_1bit_TB): Sum("Sum"), Cout("Cout"), A("A"), B("B"),
                                Cin("Cin"), input_change("input_change") {

            SC_THREAD(value_generator);

            SC_METHOD(value_monitor);
            sensitive << input_change;

        }

    private:
        void value_generator(void);
        void value_monitor(void);

};