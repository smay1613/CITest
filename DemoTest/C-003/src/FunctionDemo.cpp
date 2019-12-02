#include "gtest/gtest.h"

int SumParam(int i,int j = 0,int k =1)
{
	return i+j+k;
}

TEST(Module4,FunctionDefaultParameter)
{
	ASSERT_EQ(SumParam(1,2,3),6);
	ASSERT_EQ(SumParam(1,2),4);
	ASSERT_EQ(SumParam(1),2);
}

auto GetA(int a) -> decltype(a+3.0)
		{
	       return a;
		}

TEST(Module4,FunctionTrailingReturn)
{
	ASSERT_EQ(sizeof(GetA(2)),8);
}
