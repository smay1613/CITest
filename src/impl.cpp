#include "impl.h"

char* IntToBinaryRepresentation(char *buffer, int source)
{
	//unsigned int mask = 1 << (sizeof(unsigned int)*8 - 1);

	unsigned int i=0;
	while(i < sizeof(int)*8)
	{
		buffer[i++] = '0'+ (source < 0);
		source = source << 1;
	}
	buffer[i] = '\0';
	return buffer;
}

