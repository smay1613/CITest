/*
 * base64Test.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel Tsytovich
 */

#include <gtest/gtest.h>

void ToBase64(char *strIn,char *strOut);

TEST(Lab4,Simple)
{
  char *source = "BaSe64";
  char actual[30];

  ToBase64(source,actual);

  ASSERT_STREQ(actual,"QmFTZTY0");
}


