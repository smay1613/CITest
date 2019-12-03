#include "impl.h"
#include <bitset>
#include <cstring>

char* IntToBinaryRepresentation(char *buffer,int number)
{
	std::bitset<32> y(number);
    std::string string = y.to_string();
    strcpy(buffer, string.c_str());

	return (buffer);
}
