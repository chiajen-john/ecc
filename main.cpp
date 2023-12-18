#include "ecc.h"

UINT vector = 0b1110;
struct BIN test = BIN(vector);

int main (int argc, char *argv[]) {
    test.BINprint();
    hamming(&test);
    test.BINprint();
    hamming(&test);
    test.BINprint();
    return 0;
}