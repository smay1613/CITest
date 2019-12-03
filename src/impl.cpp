#include "impl.h"

int BinaryInvert(int x,int p,int n)
{
    unsigned int mask {x}, mask2 {~x};
    int out {0};
    constexpr unsigned int int_size {sizeof(int) * 8};
    mask <<= (int_size - p);
    mask2 <<= (int_size - p);

    mask >>= (int_size - n);
    mask2 >>= (int_size - n);

    mask <<= p - n;
    mask2 <<= p - n;

    out = mask^x;
    out |= mask2;
    return out;
}
