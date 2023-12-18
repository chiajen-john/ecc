#ifndef TYPES_H
#define TYPES_H

#include <cstdio>

#if 1
    #define M 4 
    #define K 3 
    #define N 7
#else
#endif

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
    void BINprint () {
        UINT value = this -> value;
        if (this -> hamming) {
            printf("decoded: ");
        } else {
            printf("encoded: ");
        }
        for (int i = N-1; i >= 0; i--) {
            if (value & (1 << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    };
};

void Hamming (struct BIN *message);
UINT BitExtract(UINT num, UINT ind);
void RandomFlip (struct BIN *message);

#endif