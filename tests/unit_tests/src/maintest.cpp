#include "maintest.h"
#include "impl.h"
#include <gtest/gtest.h>

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

