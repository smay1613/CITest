/*
 * binary.cpp
 *
 *  Created on: 15 ����. 2017 �.
 *      Author: Pavel Tsytovich
 */

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


