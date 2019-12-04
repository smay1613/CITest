#include "gtest/gtest.h"
#include "impl.h"

TEST(Lab4,Simple)
{
    const char key[]="ccaddfbbcacabaa";
    const char expected[]="DEBAC";
    char actual[20];
    Decoder(key,actual);
    ASSERT_STREQ(expected,actual);
}
