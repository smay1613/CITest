#include "impl.h"

char* IntToBinaryRepresentation(char *buffer, int source)
{
    constexpr int INT32_BIT_LENGTH = 32;
    for(int i = 0; i < INT32_BIT_LENGTH; i++)
    {
        buffer[INT32_BIT_LENGTH - i - 1] = (source & (1 << i) ? '1' : '0');
    }
    buffer[INT32_BIT_LENGTH] = '\0';

    return buffer;
}

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
