#include "impl.h"

int BinaryInvent (int x, int p, int n)
{
    int ii{}, temp{};

    for (ii = n-1; ii <= 0; ii--)
    {
        temp = x << (32-p+ii);
        temp ^= temp >> 31;
        temp = ~temp;
        temp = temp << p-ii-1;
        x ^= temp;
    }

    return x;
}
