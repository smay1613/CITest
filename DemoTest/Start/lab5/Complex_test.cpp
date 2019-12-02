/*
 * Complex_test.cpp
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel Tsytovich
 */

#include <gtest/gtest.h>
#include <lab5/Complex.h>


TEST(Lab5,Add)
{
	Complex a(1,2),b(3,4);

	Complex expected(4,6);

	Complex actual = a + b;


	ASSERT_EQ(expected,actual);
	ASSERT_EQ(a, Complex(1,2));
	ASSERT_EQ(b,Complex(3,4));
}

TEST(Lab5,Sub)
{
	Complex a(1,2),b(3,4);

    Complex expected(-2,-2);

	Complex actual = a - b;


	ASSERT_EQ(expected,actual);
	ASSERT_EQ(a,Complex(1,2));
	ASSERT_EQ(b,Complex(3,4));

}
