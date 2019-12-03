#include "impl.h"
#include <bitset>
#include <cstring>
#include <limits.h>

int BinaryInvert(int x,int p,int n)
{
    const int mask_lenth = sizeof(x) * 8;

    int mask = (UINT_MAX << (mask_lenth - n)) >> (mask_lenth - n) << (p - n);
    return x ^ mask;
}
