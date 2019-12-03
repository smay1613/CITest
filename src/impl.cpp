#include "impl.h"
#include <bitset>
#include <cstring>

char* IntToBinaryRepresentation(char *buffer,int number)
{
	std::bitset<32> y(number);
	std::string str = y.to_string();
	strcpy(buffer, str.c_str());

	return (buffer);
}
