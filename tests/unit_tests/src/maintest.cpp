#include "maintest.h"
#include "impl.h"





TEST(Lab1,Simple)
{
   int source = 0x5;
   char* expected = "00000000000000000000000000000101";
                  //"1010000000000000000000000000000
   char buffer[80];

   char *actual = IntToBinaryRepresentation(buffer,source);


   ASSERT_STREQ(expected,actual);
}

