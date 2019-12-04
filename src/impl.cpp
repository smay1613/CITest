#include "impl.h"

int BinaryInvert(int x,int p,int n)
{
    constexpr int INT32_BIT_COUNT = sizeof(x)*8;

    if (p < INT32_BIT_COUNT)
    {
        if (n > p)
        {
            n = 0;
        }

        unsigned int mask = (1 << p) - (1 << (p - n));
        x ^= mask;
    }

    return x;
}
