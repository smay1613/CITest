#include "maintest.h"
#include "impl.h"

#include <gtest/gtest.h>

TEST(Lab5,Add)
{
    Complex a(1,2),b(3,4);

    Complex expected(4,6);

    Complex actual = a + b;


    ASSERT_EQ(expected,actual);
    ASSERT_EQ(a,Complex(1,2));
    ASSERT_EQ(b,Complex(3,4));

    a += b;
    Complex expected2(4,6);
    ASSERT_EQ(a,expected2);

    std::cout << "Complex A is as follows: " << std::endl << a << std::endl;
}

TEST(Lab5,Sub)
{
//    Complex a(1,2),b(3,4);

//    Complex expected(-2,-2);

//    Complex actual = a - b;


//    ASSERT_EQ(expected,actual);
//    ASSERT_EQ(a,Complex(1,2));
//    ASSERT_EQ(b,Complex(3,4));

}
