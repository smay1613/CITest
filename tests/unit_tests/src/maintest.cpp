#include "maintest.h"
#include "impl.h"

TEST(Lab9,Five)
{
    Integer v(5);
    char *actual = (char*)v;
    ASSERT_STREQ(actual,"five");
}

TEST(Lab9,Seven)
{
    Integer v(7);
    char *actual = (char*)v;
    ASSERT_STREQ(actual,"seven");
}
