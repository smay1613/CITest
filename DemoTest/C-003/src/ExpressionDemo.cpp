/*
 * IncrementDecrement.cpp
 *
 *  Created on: 18 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"
#include <limits>
using namespace std;
TEST(Module3, IncrementDecrementDemo)
{
	int a = 2;

	ASSERT_EQ(a++,2);
	ASSERT_EQ(a,3);
	ASSERT_EQ(++a,4);

	ASSERT_EQ(a--,4);
	ASSERT_EQ(a,3);
	ASSERT_EQ(--a,2);
}

TEST(Module3, SizeofDemo)
{
	ASSERT_EQ(sizeof(int),4);
	ASSERT_EQ(sizeof(char),1);
	ASSERT_EQ(sizeof(float),4);
	ASSERT_EQ(sizeof(double),8);

	int SomeArray[10];
	ASSERT_EQ(sizeof(SomeArray)/sizeof(int),10);
}

TEST(Module3, ArithmeticDemo)
{
  int min = -2147483647 - 1;
  int max = 2147483647;

  int result1 = min-1;
  int result2 = max+1;

  ASSERT_EQ(result1,max);
  ASSERT_EQ(result2,min);

}

TEST(Module3, ShiftDemo)
{
	ASSERT_EQ( 2 >> 2, 0);
	ASSERT_EQ(2 << 2, 8);
	ASSERT_EQ (-1 >> 2, -1);
}

TEST(Module3,ConditionDemo)
{
	int a = 2;
	int b = 3;
	ASSERT_EQ(a > b, 0);
	ASSERT_EQ(a < b, 1);
	ASSERT_EQ(a > b && b != 0, 0);
	ASSERT_EQ(a < b && b != 0, 1);
}

constexpr int inc(const int a)
{
	return a+1;
}
TEST(Module3,ContExprDemo)
{
	ASSERT_EQ(inc(3),4);
}

TEST(Module3,ConstExprDemoWithArray)
{
	struct A
	{
		constexpr A(bool b) : n(b?5:10) {};
		size_t n;
	};
	int a[A(true).n];
	int b[A(false).n];
	ASSERT_EQ(sizeof(a)/sizeof(int),5);
	ASSERT_EQ(sizeof(b)/sizeof(int),10);
}
TEST(Module3,FlexybleArray)
{
	int size = 5;
	char fill[10] = "#########";
	char flex[size] = "ABCD";
	ASSERT_STREQ(flex,"ABCD");
	ASSERT_STREQ(fill,"#########");
}
