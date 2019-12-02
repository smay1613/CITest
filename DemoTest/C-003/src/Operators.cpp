/*
 * Operators.cpp
 *
 *  Created on: 19 сент. 2017 г.
 *      Author: Паша
 */

#include "gtest/gtest.h"

TEST(Module4,SimpleIf)
{
	int a = 2;
	int result;
	if( a > 2)
		result = 5;
	else
		result = 3;
	ASSERT_EQ(result,3);
}
TEST(Module4,IfOperatorTrue)
{
	int a = 2;
	int result;

	if(a)
		result = 5;
	else
		result = 100;
	ASSERT_EQ(result,5);
}

TEST(Module4,IfOperatorFalse)
{
	int a = 0;
		int result;

		if(a)
			result = 5;
		else
			result = 100;
		ASSERT_EQ(result,100);
}

TEST(Module4,SwitchOperator)
{
	int a = 4;
	switch(a)
	{
	case 2:
		   a++;
	case 4:
		   a++;
	case 6:
		  a++;
	case 8:
		  a++;
	default:
		  a++;
	}
	ASSERT_EQ(a,8);
}

TEST(Module4,SwitchOperatorWithoutBreak)
{
	int a = 4;
	switch(a)
	{
	case 2:
		   a++;break;
	case 4:
		   a++;break;
	case 6:
		  a++;break;
	case 8:
		  a++;break;
	default:
		  a++;break;
	}
	ASSERT_EQ(a,5);
}

TEST(Module4,BasedRangeForOperator1)
{
	int sum=0;
	for(int current : {0,1,2,3,4,5,6})
		sum += current;
	ASSERT_EQ(sum,21);
}

TEST(Module4,BasedRangeForOperator2)
{
	char Str[] = "ABAABBA";
	int countA = 0;
	for(char current : Str)
		countA += (current == 'A');
	ASSERT_EQ(countA,4);
}
