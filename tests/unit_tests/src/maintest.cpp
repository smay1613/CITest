#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>

int BinaryInvert(int x,int p,int n);

TEST(Lab2,Simple)
{
    int x = 0xFF0;
    int n = 3;
    int p = 7;  // old value 8 is incorrect. We must count bits from 0 to 31, not from 1 to 32
    int expected = 0xF10;

    int actual = BinaryInvert(x,p,n);

    ASSERT_EQ(expected,actual);
}

TEST(Lab2,LeftRange)
{
    int x = 0xFF0;
    int n = 1;
    int p = 31;
    int expected = 0x80000FF0;

    int actual = BinaryInvert(x,p,n);

    ASSERT_EQ(expected,actual);
}

TEST(Lab2,RightRange)
{
    int x = 0xFF0;
    int n = 1;
    int p = 0;
    int expected = 0xFF1;

    int actual = BinaryInvert(x,p,n);

    ASSERT_EQ(expected,actual);
}





