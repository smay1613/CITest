#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>

TEST(Lab5,Add)
{
    constexpr Complex a(1,2),b(3,4);

    constexpr Complex expected(4,6);

    constexpr Complex actual = a + b;


    ASSERT_EQ(expected,actual);
    ASSERT_EQ(a, Complex(1,2));
    ASSERT_EQ(b,Complex(3,4));

}

TEST(Lab5,Sub)
{
    constexpr Complex a(1,2),b(3,4);

    constexpr Complex expected(-2,-2);

    constexpr Complex actual = a - b;


    ASSERT_EQ(expected,actual);
    ASSERT_EQ(a,Complex(1,2));
    ASSERT_EQ(b,Complex(3,4));

}

TEST(Lab5,Operators)
{
    constexpr Complex a(1,2);

//    Complex b(3,4);
    Complex b = "3+4"_i;

    constexpr Complex expected(4,6);

    b += a;

    ASSERT_EQ(expected,b);
    ASSERT_EQ(a,Complex(1,2));
    ASSERT_EQ(b,Complex(4,6));

}
