#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>
#include "saltan.h"

TEST(Lab4,SaltanSimple)
{
  const char key[] = "ccaddfbbcacabaa";
  const char expected[] = "DEBAC";
  char actual[20];
  Decoder(key,actual);
  ASSERT_STREQ(expected,actual);
}

