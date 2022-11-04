#include "adder.h"
#include "adder_tb.h"

int sc_main(int argc, char *argv[]) {
    // channels definitions
    sc_signal<sc_logic> channel_A;
    sc_signal<sc_logic> channel_B;
    sc_signal<sc_logic> channel_Cin;
    sc_signal<sc_logic> channel_Sum;
    sc_signal<sc_logic> channel_Cout;

    // adder and tb instances
    Adder_1bit add_1b_instance("add_1b_instance");
    Adder_1bit_TB add_1b_TB_instance("add_1b_TB_instance");

    // instances connections through channels
    add_1b_instance.A(channel_A);
    add_1b_instance.B(channel_B);
    add_1b_instance.Cin(channel_Cin);
    add_1b_instance.Sum(channel_Sum);
    add_1b_instance.Cout(channel_Cout);

    add_1b_TB_instance.A(channel_A);
    add_1b_TB_instance.B(channel_B);
    add_1b_TB_instance.Cin(channel_Cin);
    add_1b_TB_instance.Sum(channel_Sum);
    add_1b_TB_instance.Cout(channel_Cout);

    sc_start();

    return 0;
}