#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>

char* IntToBinaryRepresentation(char *,int);

TEST(Lab1,Simple)
{
   int source = 0x5;
   char* expected = "00000000000000000000000000000101";
   char buffer[80];

   char *actual = IntToBinaryRepresentation(buffer,source);


   ASSERT_STREQ(expected,actual);
}

int BinaryInvert(int x,int p,int n);

TEST(Lab2,Simple)
{
    int x = 0xFF0;
    int n = 3;
    int p = 8;
    int expected = 0xF10;

    int actual = BinaryInvert(x,p,n);

    ASSERT_EQ(expected,actual);
}
