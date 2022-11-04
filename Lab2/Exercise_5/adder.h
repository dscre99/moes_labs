#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Adder_1bit) {
    
    private:
        sc_in<sc_logic> A;
        sc_in<sc_logic> B;
        sc_in<sc_logic> Cin;
        sc_out<sc_logic> Sum;
        sc_out<sc_logic> Cout;

    public:
        SC_CTOR(Adder_1bit): A("A"), B("B"), Cin("Cin"), Sum("Sum"), Cout("Cout") {

            SC_METHOD(adder_behav);
            sensitive << A << B << Cin;

        }

    private:
        void adder_behav(void);
};