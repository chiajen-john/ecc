#include "ecc.h"

UINT hamming (struct BIN message) {
    if (message.hamming) {
        // decode

    } else {
        // encode

    }

    return 0;
}

UINT pow (UINT exp, UINT base) {
    UINT num = 1;
    for (int i = 0; i < base; i++) {
        num *= exp;
    }
    return num;
}