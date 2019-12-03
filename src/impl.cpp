#include "impl.h"
#include <cstring>
#include <bitset>

char* IntToBinaryRepresentation(char *buffer, int source)
{
    strcpy(buffer, std::bitset<(sizeof(source)*8)>(source).to_string().c_str());
    return buffer;
}
