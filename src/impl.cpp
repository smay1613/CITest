#include "impl.h"

char* IntToBinaryRepresentation(char *buff,int value)
{
   constexpr unsigned int int_size = sizeof(int) * 8;
   for (unsigned int i = 0; i < int_size; i++)
   {
       buff[i] = '0' + static_cast<char>((value >> (int_size - 1 - i)) & 0x1);
   }
   buff[int_size] = '\0';

   return buff;
}
