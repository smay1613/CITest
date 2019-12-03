#include <climits>
#include <iostream>

#include "impl.h"


int BinaryInvert(int x,int p,int n) {
    const int max_bits_sz = sizeof(x) * 8;

    int mask = (UINT_MAX << (max_bits_sz - n)) >> (max_bits_sz - n) << (p - n);
    return x ^ mask;
}
