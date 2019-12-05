#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>

//void ToBase64(char *strIn,char *strOut);

//TEST(Lab4,Simple)
//{
//  char *source = "BaSe64";
//  char actual[30];

//  ToBase64(source,actual);

//  ASSERT_STREQ(actual,"QmFTZTY0");
//}


TEST(Lab4,SaltanSimple)
{
  const char key[] = "ccaddfbbcacabaa";
  const char expected[] = "DEBAC";
  char actual[20];
  Decoder(key,actual);
  ASSERT_STREQ(expected,actual);
}

