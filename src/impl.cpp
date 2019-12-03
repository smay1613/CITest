#include "impl.h"

int BinaryInvert(int x,int p,int n)
{
    int tmp = 0;

    for(int i = 0; i < n; i++)
    {
        tmp |= 1 << i;
    }
    tmp = tmp << (p - n);
    x ^= tmp;

    return x;
}
