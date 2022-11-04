#include "adder.h"
#define EVER ;;

void Adder_1bit::adder_behav(void) {

        Sum->write(A ^ B ^ Cin);
        Cout->write((A & B) ^ (Cin & (A ^ B)));

}