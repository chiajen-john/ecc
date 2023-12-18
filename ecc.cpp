#include "ecc.h"

UINT BitExtract(UINT num, UINT ind) {
    if (num & (1 << ind)) {
        return 1;
    }
    return 0;
}

void Hamming (struct BIN *message) {
    if (message -> hamming) {
        // decode
        UINT value = message -> value;
        message -> value = BitExtract(value, 0) ^ 
                        (BitExtract(value, 3) << 1) ^
                        (BitExtract(value, 5) << 2) ^
                        (BitExtract(value, 6) << 3) ^
                        (BitExtract(value, 7) << 4);
    } else {
        // encode
        UINT value = 0;
        value ^= (message -> value & (1 << 1)) << 2;
        value ^= (message -> value & (1 << 2)) << 3;
        value ^= (message -> value & (1 << 3)) << 3;
        value ^= (message -> value & (1 << 0)) << 0;
        value ^= (BitExtract(value, 3) ^ 
                BitExtract(value, 5) ^ 
                BitExtract(value, 7)) ? 1 << 1: 0;
        value ^= (BitExtract(value, 3) ^ 
                BitExtract(value, 6) ^
                BitExtract(value, 7)) ? 1 << 2: 0;
        value ^= (BitExtract(value, 5) ^ 
                BitExtract(value, 6) ^
                BitExtract(value, 7)) ? 1 << 4: 0;
        message -> value = value;
        message -> hamming = true;
    }

    return;
}

void RandomFlip(struct BIN *message) {
    UINT r = 42 % N;
    message -> value ^= 1 << r;
    return;
}