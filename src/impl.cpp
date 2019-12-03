#include "impl.h"
#define BITES_IN_BYTE 8
char* IntToBinaryRepresentation(char *buffer, int source)
{
	int ii {};
	char even ='0', odd = '1';
	
	ii = BITES_IN_BYTE*sizeof(int);
	*(buffer+ii) = '\0';
	do
	{
		ii--;
		if (0 == source%2)
		{
			*(buffer+ii) = even;
		}
		else
		{
			*(buffer+ii) = odd;
		}
		source/=2;
	}
	while(ii>0)
		
	return buffer;
}
