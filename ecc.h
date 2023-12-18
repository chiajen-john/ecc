#ifndef TYPES_H
#define TYPES_H

typedef bool BOOL;
typedef unsigned int UINT;

struct BIN {
    UINT value;
    BOOL hamming;
    BIN () {};
    BIN (UINT value) {
        this -> value = value;
        this -> hamming = 0;
    }
};

UINT hamming (struct BIN message);
UINT pow (UINT exp, UINT base);

#endif