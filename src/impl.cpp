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
