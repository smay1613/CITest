#include "impl.h"

int BinaryInvert(int x,int p,int n)
{
    constexpr int INT32_BIT_COUNT = sizeof(x)*8;

    if (p < INT32_BIT_COUNT && n <= p)
    {
        for (int i = p; i > p - n; i--)
        {
            x ^= 1 << (i-1);
        }
    }

    return x;
}
